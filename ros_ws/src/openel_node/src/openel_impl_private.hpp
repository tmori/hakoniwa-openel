#ifndef _OPENEL_IMPL_PRIVATE_HPP_
#define _OPENEL_IMPL_PRIVATE_HPP_

#include "rclcpp/rclcpp.hpp"
extern std::shared_ptr<rclcpp::Node> openel_node;
extern std::string* openel_pub_topic_name;
extern std::string* openel_sub_topic_name;
extern const char *openel_node_name;

#endif /* _OPENEL_IMPL_PRIVATE_HPP_ */