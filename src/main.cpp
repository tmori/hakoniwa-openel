#include <stdio.h>
#include <Actuator.hpp>
#include <openEL.hpp>
#include <iostream>

int
main(int argc, const char* argv[])
{
    HALId halid;
    halid.deviceKindId = 0x0001;
    halid.productId = 0x00000001;
    halid.vendorId = 0x0000000A;
    halid.instanceId = 0x00000001;

    Actuator* hako_actuator = new Actuator(halid);

    //ros init
    ReturnCode ret = hako_actuator->Init();
    if (ret != HAL_OK) {
        std::cout << "ERROR: init()" << std::endl;
        return 1;
    }

    //publish topic
    hako_actuator->SetValue(0, 0.1);

    hako_actuator->Finalize();

    delete hako_actuator;
    return 0;
}