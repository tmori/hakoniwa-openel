
#include "openEL_ActuatorHako.hpp"
#include <iostream>

std::string ActuatorHako::strDevName = "ActuatorHako";

std::vector<std::string> ActuatorHako::strFncLst =
{
    "Init",
    "ReInit",
    "Finalize",
    "AddObserver",
    "RemoveObserver",
    "SetValue",
    "GetValue"
};

Property ActuatorHako::ActuatorHako_property;

ReturnCode ActuatorHako::fncInit(HALComponent *pHALComponent)
{
    //TODO
    std::cout<< "ActuatorHako::fncInit()" << std::endl;
    return HAL_OK;
}

ReturnCode ActuatorHako::fncReInit(HALComponent *pHALComponent)
{
    //TODO
    return HAL_OK;
}

ReturnCode ActuatorHako::fncFinalize(HALComponent *pHALComponent)
{
    //TODO
    std::cout<< "ActuatorHako::fncFinalize()" << std::endl;
    return HAL_OK;
}

ReturnCode ActuatorHako::fncAddObserver(HALComponent *pHALComponent, HALObserver **halObserver)
{
    //TODO
    return HAL_OK;
}

ReturnCode ActuatorHako::fncRemoveObserver(HALComponent *pHALComponent, HALObserver **halObserver)
{
    //TODO
    return HAL_OK;
}

ReturnCode ActuatorHako::fncGetProperty(HALComponent *pHALComponent, Property **property)
{
    ActuatorHako_property.deviceName = strDevName;
    ActuatorHako_property.functionList = strFncLst;
    (**property).functionList.resize(strFncLst.size());
    **property = ActuatorHako_property;

    return HAL_OK;
}

ReturnCode ActuatorHako::fncGetTime(HALComponent *pHALComponent, unsigned int **timeValue)
{
    //TODO

    //**timeValue = (unsigned int)millis();

    return HAL_OK;
}

ReturnCode ActuatorHako::fncGetValLst(HALComponent *pHALComponent, float **valueList, int **num)
{
    //TODO
    return HAL_ERROR;
}

ReturnCode ActuatorHako::fncGetTimedValLst(HALComponent *pHALComponent, float **valueList, unsigned int **timeValue, int **num)
{
    //TODO
    return HAL_ERROR;
}

ReturnCode ActuatorHako::fncSetValue(HALComponent *pHALComponent, int request, float value)
{
    ReturnCode retCode = HAL_OK;
    std::cout<< "ActuatorHako::fncSetValue()" << std::endl;

    if (pHALComponent->hALId.instanceId >= InstanceNum)
    {
        return HAL_ERROR;
    }

    switch (request)
    {
    case HAL_REQUEST_POSITION_CONTROL:
        //TODO
        //setEncoder((int32_t)value, pHALComponent->hALId.instanceId);
        break;
    case HAL_REQUEST_VELOCITY_CONTROL:
        //TODO
        //setSpeed((int16_t)value, pHALComponent->hALId.instanceId);
        break;
    case HAL_REQUEST_TORQUE_CONTROL:
        break;
    default:
        retCode = HAL_ERROR;
        break;
    }

    return retCode;
}

ReturnCode ActuatorHako::fncGetValue(HALComponent *pHALComponent, int request, float **value)
{
    int32_t wheel;
    int16_t sp;
    ReturnCode retCode = HAL_OK;

    if (pHALComponent->hALId.instanceId >= InstanceNum)
    {
        return HAL_ERROR;
    }

    switch (request)
    {
    case HAL_REQUEST_POSITION_CONTROL:
        //getEncoder(&wheel, pHALComponent->hALId.instanceId);
        //**value = (float)wheel;
        break;
    case HAL_REQUEST_VELOCITY_CONTROL:
        //getSpeed(&sp, pHALComponent->hALId.instanceId);
        //**value = (float)sp;
        break;
    case HAL_REQUEST_TORQUE_CONTROL:
        break;
    default:
        retCode = HAL_ERROR;
        break;
    }

    return retCode;
}

ReturnCode ActuatorHako::fncNop(HALComponent *pHALComponent, HAL_ARGUMENT_T *pCmd)
{
    return HAL_ERROR;
}

ReturnCode ActuatorHako::fncDeviceVendorSpec(HALComponent *pHALComponent, HAL_ARGUMENT_T *pCmd, HAL_ARGUMENT_DEVICE_T *pCmdDev)
{
    return HAL_ERROR;
}

HAL_FNCTBL_T HalActuatorHakoTbl =
{
    ActuatorHako::fncInit,			/* 0x00 */
    ActuatorHako::fncReInit,			/* 0x01 */
    ActuatorHako::fncFinalize,		/* 0x02 */
    ActuatorHako::fncAddObserver,		/* 0x03 */
    ActuatorHako::fncRemoveObserver,		/* 0x04 */
    ActuatorHako::fncGetProperty,		/* 0x05 */
    ActuatorHako::fncGetTime,		/* 0x06 */
    ActuatorHako::fncNop,			/* 0x07 */
    ActuatorHako::fncNop,			/* 0x08 */
    ActuatorHako::fncNop,			/* 0x09 */
    ActuatorHako::fncNop,			/* 0x0A */
    ActuatorHako::fncNop,			/* 0x0B */
    ActuatorHako::fncNop,			/* 0x0C */
    ActuatorHako::fncNop,			/* 0x0D */
    ActuatorHako::fncNop,			/* 0x0E */
    ActuatorHako::fncNop,			/* 0x0F */
    ActuatorHako::fncNop,			/* 0x10 */
    ActuatorHako::fncNop,			/* 0x11 */
    ActuatorHako::fncNop,			/* 0x12 */
    ActuatorHako::fncNop,			/* 0x13 */
    ActuatorHako::fncNop,			/* 0x14 */
    ActuatorHako::fncNop,			/* 0x15 */
    ActuatorHako::fncNop,			/* 0x16 */
    ActuatorHako::fncNop,			/* 0x17 */
    ActuatorHako::fncSetValue,		/* 0x18 */
    ActuatorHako::fncGetValue,		/* 0x19 */
    ActuatorHako::fncGetValLst,	/* 0x1A */
    ActuatorHako::fncGetTimedValLst,	/* 0x1B */
    ActuatorHako::fncDeviceVendorSpec,	/* 0x1C */
    ActuatorHako::fncDeviceVendorSpec,	/* 0x1D */
    ActuatorHako::fncDeviceVendorSpec,	/* 0x1E */
    ActuatorHako::fncDeviceVendorSpec,	/* 0x1F */
};
