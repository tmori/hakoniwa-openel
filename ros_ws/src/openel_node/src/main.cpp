#include <stdio.h>
#include <iostream>
#include <string.h>
#include "openel_node.hpp"
#include <Actuator.hpp>
#include <openEL.hpp>

using namespace std::chrono_literals;
std::string * openel_pub_topic_name = nullptr;

std::shared_ptr<rclcpp::Node> openel_node = nullptr;
int main(int argc, char **argv) 
{
    const char *node_name = "openel_node";
    openel_pub_topic_name = new std::string("openel_pub_topic");
    std::cout << "START:" << node_name << std::endl;
    //ROS CODES
    rclcpp::init(argc, argv);
    openel_node = rclcpp::Node::make_shared(node_name);

    //OPENEL CODES
    Actuator* hako_actuator;
    {
        HALId halid;
        halid.deviceKindId = 0x0001;
        halid.productId = 0x00000001;
        halid.vendorId = 0x0000000E;
        halid.instanceId = 0x00000001;
        hako_actuator = new Actuator(halid);
        ReturnCode ret = hako_actuator->Init();
        if (ret != HAL_OK) {
            std::cout << "ERROR: init()" << std::endl;
            return 1;
        }
        std::cout << "OpenEL init OK" << std::endl;
    }

    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
        //OPENEL CODE
        {
            //publish topic
            hako_actuator->SetValue(HAL_REQUEST_VELOCITY_CONTROL, 0.5);
        }
        rclcpp::spin_some(openel_node);
        rate.sleep();
    }
    std::cout << "EXIT" << std::endl;

    //OPENEL CODES
    {
        hako_actuator->Finalize();
        delete hako_actuator;
    }

    rclcpp::shutdown();
    return 0;
}

