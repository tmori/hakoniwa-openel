#include <stdio.h>
#include <iostream>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include <Actuator.hpp>
#include <openEL.hpp>

using namespace std::chrono_literals;


int main(int argc, char **argv) 
{
    const char *node_name = "openel_node";
    std::cout << "START:" << node_name << std::endl;

    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(node_name);

    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
        rclcpp::spin_some(node);
        rate.sleep();
    }
    std::cout << "EXIT" << std::endl;

    rclcpp::shutdown();
    return 0;
}

