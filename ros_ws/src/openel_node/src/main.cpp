#include <stdio.h>
#include <iostream>
#include <string.h>
#include "openel_node.hpp"
#include <Actuator.hpp>
#include <Sensor.hpp>
#include <openEL.hpp>
#include "openel/openEL_ActuatorHako.hpp"

using namespace std::chrono_literals;
std::string * openel_pub_topic_name = nullptr;
std::string* openel_sub_topic_name = nullptr;
std::shared_ptr<rclcpp::Node> openel_node = nullptr;
static Actuator* hako_motor_l;
static Actuator* hako_motor_r;
static Sensor* hako_sensor;

static void hako_motor_init()
{
    HALId halid;
    halid.deviceKindId = 0x0001;
    halid.productId = 0x00000001;
    halid.vendorId = 0x0000000E;
    
    halid.instanceId = MOTOR_LEFT;
    hako_motor_l = new Actuator(halid);
    ReturnCode ret = hako_motor_l->Init();
    if (ret != HAL_OK) {
        std::cout << "ERROR: motor left init()" << std::endl;
        exit(1);
    }
    std::cout << "OpenEL Motor L init OK" << std::endl;

    halid.instanceId = MOTOR_RIGHT;
    hako_motor_r = new Actuator(halid);
    ret = hako_motor_r->Init();
    if (ret != HAL_OK) {
        std::cout << "ERROR: motor right init()" << std::endl;
        exit(1);
    }
    std::cout << "OpenEL Motor R init OK" << std::endl;
}
static void hako_sensor_init()
{
    HALId halid;
    halid.deviceKindId = 0x0002;
    halid.productId = 0x00000001;
    halid.vendorId = 0x0000000E;
    
    halid.instanceId = 0x1;
    hako_sensor = new Sensor(halid);
    ReturnCode ret = hako_sensor->Init();
    if (ret != HAL_OK) {
        std::cout << "ERROR: sensor init()" << std::endl;
        exit(1);
    }
    std::cout << "OpenEL Sensor init OK" << std::endl;
}

int main(int argc, char **argv) 
{
    char buffer[3][4096];

    if (argc > 1) {
        sprintf(buffer[0], "%s_tb3_node", argv[1]);
        sprintf(buffer[1], "%s_cmd_vel", argv[1]);
        sprintf(buffer[2], "%s_scan", argv[1]);
        printf("START: %s\n", argv[1]);
    }
    else {
        sprintf(buffer[0], "tb3_node");
        sprintf(buffer[1], "cmd_vel");
        sprintf(buffer[2], "scan");
        printf("START\n");
    }    
    const char *node_name = buffer[0];
    openel_pub_topic_name = new std::string(buffer[1]);
    openel_sub_topic_name = new std::string(buffer[2]);
    std::cout << "START:" << node_name << std::endl;
    //ROS CODES
    rclcpp::init(argc, argv);
    openel_node = rclcpp::Node::make_shared(node_name);

    //OPENEL CODES
    {
        hako_motor_init();
        hako_sensor_init();
    }

    rclcpp::WallRate rate(100ms);
    while (rclcpp::ok()) {
        //OPENEL CODE
        {
            //publish topic
            hako_motor_l->SetValue(HAL_REQUEST_VELOCITY_CONTROL, 0.5f);
            hako_motor_r->SetValue(HAL_REQUEST_VELOCITY_CONTROL, 0.5f);
        }
        rclcpp::spin_some(openel_node);
        rate.sleep();
    }
    std::cout << "EXIT" << std::endl;

    //OPENEL CODES
    {
        hako_motor_l->Finalize();
        hako_motor_r->Finalize();
        hako_sensor->Finalize();
        delete hako_motor_l;
        delete hako_motor_r;
        delete hako_sensor;
    }

    rclcpp::shutdown();
    return 0;
}

