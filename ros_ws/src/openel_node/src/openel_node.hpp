#ifndef _OPENEL_NODE_HPP_
#define _OPENEL_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
extern std::shared_ptr<rclcpp::Node> openel_node;
extern std::string* openel_pub_topic_name;
extern std::string* openel_sub_topic_name;

#endif /* _OPENEL_NODE_HPP_ */