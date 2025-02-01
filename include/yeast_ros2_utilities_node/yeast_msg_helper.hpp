#ifndef YEAST_MSG_HELPER_GEN_H_
#define YEAST_MSG_HELPER_GEN_H_

#include "yeastcpp/yeastcpp.hpp"

#include "yeast_ros2_interfaces/msg/twist2_d.hpp"
#include "yeast_ros2_interfaces/msg/translation2_d.hpp"
#include "yeast_ros2_interfaces/msg/rotation2_d.hpp"
#include "yeast_ros2_interfaces/msg/motion_sample.hpp"
#include "yeast_ros2_interfaces/msg/pose2_d.hpp"
#include "yeast_ros2_interfaces/msg/motion_command.hpp"

namespace yeast_msg_helper
{
    yeast_ros2_interfaces::msg::Twist2D to_msg(yeast_motion::Twist2D yeast_type);
    yeast_motion::Twist2D from_msg(yeast_ros2_interfaces::msg::Twist2D msg);

    yeast_ros2_interfaces::msg::Translation2D to_msg(yeast_motion::Translation2D yeast_type);
    yeast_motion::Translation2D from_msg(yeast_ros2_interfaces::msg::Translation2D msg);

    yeast_ros2_interfaces::msg::Rotation2D to_msg(yeast_motion::Rotation2D yeast_type);
    yeast_motion::Rotation2D from_msg(yeast_ros2_interfaces::msg::Rotation2D msg);

    yeast_ros2_interfaces::msg::MotionSample to_msg(yeast_motion::MotionSample yeast_type);
    yeast_motion::MotionSample from_msg(yeast_ros2_interfaces::msg::MotionSample msg);

    yeast_ros2_interfaces::msg::Pose2D to_msg(yeast_motion::Pose2D yeast_type);
    yeast_motion::Pose2D from_msg(yeast_ros2_interfaces::msg::Pose2D msg);

    yeast_ros2_interfaces::msg::MotionCommand to_msg(yeast_motion::MotionCommand yeast_type);
    yeast_motion::MotionCommand from_msg(yeast_ros2_interfaces::msg::MotionCommand msg);

}

#endif /* YEAST_MSG_HELPER_GEN_H_ */