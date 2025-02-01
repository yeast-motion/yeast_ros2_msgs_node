import jinja2
import json
import pathlib
import argparse
import glob
import os
import re

parser = argparse.ArgumentParser(description='Render script')
parser.add_argument('--src-dir', action='store', dest='src_dir', default='')
parser.add_argument('--header-template', action='store', dest='header_template', default='')
parser.add_argument('--source-template', action='store', dest='source_template', default='')
parser.add_argument('--header-dest', action='store', dest='header_dest', default='')
parser.add_argument('--source-dest', action='store', dest='source_dest', default='')
args = parser.parse_args()

SCRIPT_DIRECTORY = os.path.dirname(os.path.realpath(__file__))
ROOT_DIRECTORY = os.path.dirname(SCRIPT_DIRECTORY)

print(SCRIPT_DIRECTORY)
print(ROOT_DIRECTORY)

header_template_file = os.path.realpath(args.header_template)
source_template_file = os.path.realpath(args.source_template)

schema_dir = os.path.realpath(args.src_dir)
schema_files = glob.glob(f'{schema_dir}/*.json')

header_dest = os.path.realpath(args.header_dest)
source_dest = os.path.realpath(args.source_dest)

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

msg_template = env.get_template(header_template_file)
msg_result = msg_template.render(header_names=header_names, type_members=type_members)
f = open(f'{header_dest}', 'w')
f.write(msg_result)
f.close()

msg_template = env.get_template(source_template_file)
msg_result = msg_template.render(type_members=type_members)
f = open(f'{source_dest}', 'w')
f.write(msg_result)
f.close()

# python3 template/render_jinja.py --template template/msg.j2 --src-dir yeast-schema/data_definitions/ --dst-dir msg/

