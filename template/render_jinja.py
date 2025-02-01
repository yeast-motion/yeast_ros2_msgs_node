import jinja2
import json
import pathlib
import argparse
import glob
import os
import re

parser = argparse.ArgumentParser(description='Render script')
parser.add_argument('--src-dir', action='store', dest='src_dir', default='')
parser.add_argument('--dst-dir', action='store', dest='dst_dir', default='')
parser.add_argument('--template', action='store', dest='template', default='')
args = parser.parse_args()

SCRIPT_DIRECTORY = os.path.dirname(os.path.realpath(__file__))
ROOT_DIRECTORY = os.path.dirname(SCRIPT_DIRECTORY)

print(SCRIPT_DIRECTORY)
print(ROOT_DIRECTORY)

template_file = os.path.realpath(args.template)

schema_dir = os.path.realpath(args.src_dir)
schema_files = glob.glob(f'{schema_dir}/*.json')

header_dir = os.path.realpath(args.dst_dir)

header_names = []
type_members = {}
# 'name' : (prim[], ref[])

for schema_file in schema_files:
    if os.stat(schema_file).st_size == 0:
        continue

    msg_name = ''

    with open(schema_file, 'r') as stream:
        json_data = json.load(stream)

        title = json_data['title']
        hname = re.sub(r"(?!^.{0,1})[A-Z]", '_\\g<0>', title).lower()
        header_names.append(hname)

        prims = []
        refs = []

        for struct in json_data['properties']:
            if 'type' in json_data['properties'][struct]:
                prims.append(struct)
            elif '$ref' in json_data['properties'][struct]:
                refs.append(struct)

        type_members[title] = (prims, refs)

    schema_basename = os.path.basename(schema_file)

env = jinja2.Environment(loader=jinja2.FileSystemLoader('/'), trim_blocks=True)
msg_template = env.get_template(template_file)
msg_result = msg_template.render(header_names=header_names, type_members=type_members)
f = open(f'{header_dir}/yeast_msg_helper_gen.hpp', 'w')
f.write(msg_result)
f.close()

# python3 template/render_jinja.py --template template/msg.j2 --src-dir yeast-schema/data_definitions/ --dst-dir msg/

