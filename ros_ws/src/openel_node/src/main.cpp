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

    //OPENEL CODES
    Actuator* hako_actuator;
    {
        HALId halid;
        halid.deviceKindId = 0x0001;
        halid.productId = 0x00000001;
        halid.vendorId = 0x0000000E;
        halid.instanceId = 0x00000001;
        Actuator* hako_actuator = new Actuator(halid);
        ReturnCode ret = hako_actuator->Init();
        if (ret != HAL_OK) {
            std::cout << "ERROR: init()" << std::endl;
            return 1;
        }
    }

    //ROS CODES
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(node_name);

    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
        //OPENEL CODE
        {
            //publish topic
            hako_actuator->SetValue(HAL_REQUEST_VELOCITY_CONTROL, 0.1);
        }
        rclcpp::spin_some(node);
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

