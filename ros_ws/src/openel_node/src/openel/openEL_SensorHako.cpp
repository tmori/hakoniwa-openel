/*
 * MIT License
 *
 * Copyright (c) 2017 M5Stack
 * Copyright (c) 2021 JASA(Japan Embedded Systems Technology Association)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "openEL_SensorHako.hpp"

std::string SensorHako::strDevName = "HakoSensor";
double SensorHako::ranges[SENSOR_HAKO_DATA_NUM];
std::shared_ptr<rclcpp::Subscription<sensor_msgs::msg::LaserScan>> SensorHako::subscriber;
std::string* openel_sub_topic_name = nullptr;

std::vector<std::string> SensorHako::strFncLst =
{
    "Init",
    "ReInit",
    "Finalize",
    "AddObserver",
    "RemoveObserver",
    "GetProperty",
    "GetTime",
    "GetValueList",
    "GetTimedValueList"
};


Property SensorHako::SensorHako_property;
void SensorHako::scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    int i;
    for (i = 0; i < SENSOR_HAKO_DATA_NUM; i++) {
        ranges[i] = msg->ranges[i];
    }
    //std::cout<< "SensorHako::scanCallback()" << std::endl;
}

ReturnCode SensorHako::fncInit(HALComponent *pHALComponent)
{
    std::cout<< "SensorHako::openel_sub_topic_name = " << *openel_sub_topic_name << std::endl;
    subscriber = openel_node->create_subscription<sensor_msgs::msg::LaserScan>(
      *openel_sub_topic_name, 1, SensorHako::scanCallback);
    std::cout<< "SensorHako::fncInit()" << std::endl;
    return HAL_OK;
}

ReturnCode SensorHako::fncReInit(HALComponent *pHALComponent)
{
    return HAL_OK;
}

ReturnCode SensorHako::fncFinalize(HALComponent *pHALComponent)
{
    return HAL_OK;
}

ReturnCode SensorHako::fncAddObserver(HALComponent *pHALComponent, HALObserver **halObserver)
{
    return HAL_OK;
}

ReturnCode SensorHako::fncRemoveObserver(HALComponent *pHALComponent, HALObserver **halObserver)
{
    return HAL_OK;
}

ReturnCode SensorHako::fncGetProperty(HALComponent *pHALComponent, Property **property)
{
    SensorHako_property.deviceName = strDevName;
    SensorHako_property.functionList = strFncLst;
    (**property).functionList.resize(strFncLst.size());
    **property = SensorHako_property;

    return HAL_OK;
}

ReturnCode SensorHako::fncGetTime(HALComponent *pHALComponent, unsigned int **timeValue)
{

    return HAL_OK;
}

ReturnCode SensorHako::fncGetValLst(HALComponent *pHALComponent, float **valueList, int **num)
{
    //std::cout<< "SensorHako::fncGetValLst():start" << std::endl;
    int i;
    float *ptr = *valueList;
    for (i = 0; i < SENSOR_HAKO_DATA_NUM; i++) {
        ptr[i] = (float)ranges[i];
    }
    //std::cout<< "SensorHako::fncGetValLst():end1" << std::endl;

    **num = SENSOR_HAKO_DATA_NUM;
    //std::cout<< "SensorHako::fncGetValLst():end2" << std::endl;
    return HAL_OK;
}

ReturnCode SensorHako::fncGetTimedValLst(HALComponent *pHALComponent, float **valueList, unsigned int **timeValue, int **num)
{

    return HAL_OK;
}

ReturnCode SensorHako::fncSetValue(HALComponent *pHALComponent, int request, float value)
{
    return HAL_ERROR;
}

ReturnCode SensorHako::fncGetValue(HALComponent *pHALComponent, int request, float **value)
{
    return HAL_ERROR;
}

ReturnCode SensorHako::fncNop(HALComponent *pHALComponent, HAL_ARGUMENT_T *pCmd)
{
    return HAL_ERROR;
}

ReturnCode SensorHako::fncDeviceVendorSpec(HALComponent *pHALComponent, HAL_ARGUMENT_T *pCmd, HAL_ARGUMENT_DEVICE_T *pCmdDev)
{
    return HAL_ERROR;
}

HAL_FNCTBL_T HalSensorHakoTbl =
{
    SensorHako::fncInit,			/* 0x00 */
    SensorHako::fncReInit,			/* 0x01 */
    SensorHako::fncFinalize,		/* 0x02 */
    SensorHako::fncAddObserver,		/* 0x03 */
    SensorHako::fncRemoveObserver,		/* 0x04 */
    SensorHako::fncGetProperty,		/* 0x05 */
    SensorHako::fncGetTime,		/* 0x06 */
    SensorHako::fncNop,			/* 0x07 */
    SensorHako::fncNop,			/* 0x08 */
    SensorHako::fncNop,			/* 0x09 */
    SensorHako::fncNop,			/* 0x0A */
    SensorHako::fncNop,			/* 0x0B */
    SensorHako::fncNop,			/* 0x0C */
    SensorHako::fncNop,			/* 0x0D */
    SensorHako::fncNop,			/* 0x0E */
    SensorHako::fncNop,			/* 0x0F */
    SensorHako::fncNop,			/* 0x10 */
    SensorHako::fncNop,			/* 0x11 */
    SensorHako::fncNop,			/* 0x12 */
    SensorHako::fncNop,			/* 0x13 */
    SensorHako::fncNop,			/* 0x14 */
    SensorHako::fncNop,			/* 0x15 */
    SensorHako::fncNop,			/* 0x16 */
    SensorHako::fncNop,			/* 0x17 */
    SensorHako::fncSetValue,		/* 0x18 */
    SensorHako::fncGetValue,		/* 0x19 */
    SensorHako::fncGetValLst,		/* 0x1A */
    SensorHako::fncGetTimedValLst,		/* 0x1B */
    SensorHako::fncDeviceVendorSpec,	/* 0x1C */
    SensorHako::fncDeviceVendorSpec,	/* 0x1D */
    SensorHako::fncDeviceVendorSpec,	/* 0x1E */
    SensorHako::fncDeviceVendorSpec,	/* 0x1F */
};
