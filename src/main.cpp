#include <stdio.h>
#include <Actuator.hpp>
#include <openEL.hpp>

int
main(int argc, const char* argv[])
{
    HALId halid;
    halid.deviceKindId = 0x0001;
    halid.productId = 0x00000001;
    halid.vendorId = 0x0000000A;
    halid.instanceId = 0x00000001;

    Actuator* hako_actuator = new Actuator(halid);

    hako_actuator->SetValue(0, 0.1);

    delete hako_actuator;
    return 0;
}