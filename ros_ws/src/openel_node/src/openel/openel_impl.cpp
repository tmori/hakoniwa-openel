#include "openel_impl.hpp"
#include "openel_impl_private.hpp"

std::string * openel_pub_topic_name = nullptr;
std::string* openel_sub_topic_name = nullptr;
std::shared_ptr<rclcpp::Node> openel_node = nullptr;
const char *openel_node_name;
using namespace std::chrono_literals;
static rclcpp::WallRate rate(100ms);

void openel_init(int argc, const char* argv)
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
    std::cout << "START:" << openel_node_name << std::endl;

    rclcpp::init(0, nullptr);
    openel_node = rclcpp::Node::make_shared(openel_node_name);
    return;
}

void openel_sync()
{
    rclcpp::spin_some(openel_node);
    rate.sleep();
}