#ifndef _OPENEL_ACTUATOR_HAKO_HPP_
#define _OPENEL_ACTUATOR_HAKO_HPP_

#include "Actuator.hpp"

#define MOTOR_ADDRESS    0x3A
#define MOTOR_SPEED_L    0x00
#define MOTOR_SPEED_R    0x02
#define MOTOR_ENCODER_L  0x10
#define MOTOR_ENCODER_R  0x14

#define MOTOR_LENGTH_SPEED   (2)
#define MOTOR_LENGTH_ENCODER (4)


class ActuatorHako : public Actuator
{
private:
    static std::string strDevName;
    static std::vector<std::string> strFncLst;

public:
    static Property ActuatorHako_property;

    static ReturnCode fncInit(HALComponent *pHALComponent);
    static ReturnCode fncReInit(HALComponent *pHALComponent);
    static ReturnCode fncFinalize(HALComponent *pHALComponent);
    static ReturnCode fncAddObserver(HALComponent *pHALComponent, HALObserver **halObserver);
    static ReturnCode fncRemoveObserver(HALComponent *pHALComponent, HALObserver **halObserver);
    static ReturnCode fncGetProperty(HALComponent *pHALComponent, Property **property);
    static ReturnCode fncGetTime(HALComponent *pHALComponent, unsigned int **timeValue);
    static ReturnCode fncGetValLst(HALComponent *pHALComponent, float **valueList, int **num);
    static ReturnCode fncGetTimedValLst(HALComponent *pHALComponent, float **valueList, unsigned int **time, int **num);
    static ReturnCode fncSetValue(HALComponent *pHALComponent, int request, float value);
    static ReturnCode fncGetValue(HALComponent *pHALComponent, int request, float **value);
    static ReturnCode fncNop(HALComponent *pHALComponent, HAL_ARGUMENT_T *pCmd);
    static ReturnCode fncDeviceVendorSpec(HALComponent* pHALComponent, HAL_ARGUMENT_T *pCmd, HAL_ARGUMENT_DEVICE_T *pCmdDev);

    static ReturnCode fncHakoPublish(HALComponent *pHALComponent);

};

extern HAL_FNCTBL_T HalActuatorHakoTbl;

#endif /* _OPENEL_ACTUATOR_HAKO_HPP_ */