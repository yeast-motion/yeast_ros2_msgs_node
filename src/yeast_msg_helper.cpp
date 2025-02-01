#include "yeast_ros2_utilities_node/yeast_msg_helper.hpp"

namespace yeast_msg_helper
{
    yeast_ros2_interfaces::msg::Twist2D to_msg(yeast_motion::Twist2D yeast_type)
    {
        yeast_ros2_interfaces::msg::Twist2D msg;

        // Primative Types
        msg.x = yeast_type.x;
        msg.y = yeast_type.y;
        msg.omega = yeast_type.omega;

        // Referenced Types

        return msg;
    }

    yeast_motion::Twist2D from_msg(yeast_ros2_interfaces::msg::Twist2D msg)
    {
        yeast_motion::Twist2D yeast_type;

        // Primative Types
        yeast_type.x = msg.x;
        yeast_type.y = msg.y;
        yeast_type.omega = msg.omega;

        // Referenced Types

        return yeast_type;
    }

    yeast_ros2_interfaces::msg::Translation2D to_msg(yeast_motion::Translation2D yeast_type)
    {
        yeast_ros2_interfaces::msg::Translation2D msg;

        // Primative Types
        msg.x = yeast_type.x;
        msg.y = yeast_type.y;

        // Referenced Types

        return msg;
    }

    yeast_motion::Translation2D from_msg(yeast_ros2_interfaces::msg::Translation2D msg)
    {
        yeast_motion::Translation2D yeast_type;

        // Primative Types
        yeast_type.x = msg.x;
        yeast_type.y = msg.y;

        // Referenced Types

        return yeast_type;
    }

    yeast_ros2_interfaces::msg::Rotation2D to_msg(yeast_motion::Rotation2D yeast_type)
    {
        yeast_ros2_interfaces::msg::Rotation2D msg;

        // Primative Types
        msg.theta = yeast_type.theta;

        // Referenced Types

        return msg;
    }

    yeast_motion::Rotation2D from_msg(yeast_ros2_interfaces::msg::Rotation2D msg)
    {
        yeast_motion::Rotation2D yeast_type;

        // Primative Types
        yeast_type.theta = msg.theta;

        // Referenced Types

        return yeast_type;
    }

    yeast_ros2_interfaces::msg::MotionSample to_msg(yeast_motion::MotionSample yeast_type)
    {
        yeast_ros2_interfaces::msg::MotionSample msg;

        // Primative Types

        // Referenced Types
        msg.pose = to_msg(yeast_type.pose);
        msg.velocity = to_msg(yeast_type.velocity);
        msg.acceleration = to_msg(yeast_type.acceleration);

        return msg;
    }

    yeast_motion::MotionSample from_msg(yeast_ros2_interfaces::msg::MotionSample msg)
    {
        yeast_motion::MotionSample yeast_type;

        // Primative Types

        // Referenced Types
        yeast_type.pose = from_msg(msg.pose);
        yeast_type.velocity = from_msg(msg.velocity);
        yeast_type.acceleration = from_msg(msg.acceleration);

        return yeast_type;
    }

    yeast_ros2_interfaces::msg::Pose2D to_msg(yeast_motion::Pose2D yeast_type)
    {
        yeast_ros2_interfaces::msg::Pose2D msg;

        // Primative Types

        // Referenced Types
        msg.translation = to_msg(yeast_type.translation);
        msg.rotation = to_msg(yeast_type.rotation);

        return msg;
    }

    yeast_motion::Pose2D from_msg(yeast_ros2_interfaces::msg::Pose2D msg)
    {
        yeast_motion::Pose2D yeast_type;

        // Primative Types

        // Referenced Types
        yeast_type.translation = from_msg(msg.translation);
        yeast_type.rotation = from_msg(msg.rotation);

        return yeast_type;
    }

    yeast_ros2_interfaces::msg::MotionCommand to_msg(yeast_motion::MotionCommand yeast_type)
    {
        yeast_ros2_interfaces::msg::MotionCommand msg;

        // Primative Types

        // Referenced Types
        msg.velocity = to_msg(yeast_type.velocity);
        msg.acceleration = to_msg(yeast_type.acceleration);

        return msg;
    }

    yeast_motion::MotionCommand from_msg(yeast_ros2_interfaces::msg::MotionCommand msg)
    {
        yeast_motion::MotionCommand yeast_type;

        // Primative Types

        // Referenced Types
        yeast_type.velocity = from_msg(msg.velocity);
        yeast_type.acceleration = from_msg(msg.acceleration);

        return yeast_type;
    }

}