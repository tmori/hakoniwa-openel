#ifndef _OPENEL_IMPL_HPP_
#define _OPENEL_IMPL_HPP_

#include "rclcpp/rclcpp.hpp"
extern std::shared_ptr<rclcpp::Node> openel_node;
extern std::string* openel_pub_topic_name;
extern std::string* openel_sub_topic_name;
extern const char *openel_node_name;

static inline void openel_init(int argc, const char* argv)
{
    char buffer[3][4096];

    if (argc > 1) {
        sprintf(buffer[0], "%s_tb3_node", argv);
        sprintf(buffer[1], "%s_cmd_vel", argv);
        sprintf(buffer[2], "%s_scan", argv);
        printf("START: %s\n", argv);
    }
    else {
        sprintf(buffer[0], "tb3_node");
        sprintf(buffer[1], "cmd_vel");
        sprintf(buffer[2], "scan");
        printf("START\n");
    }    
    openel_node_name = buffer[0];
    openel_pub_topic_name = new std::string(buffer[1]);
    openel_sub_topic_name = new std::string(buffer[2]);
}

#endif /* _OPENEL_IMPL_HPP_ */