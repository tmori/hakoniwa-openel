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

#ifndef OPENEL_SENSOR_HAKO_HPP
#define OPENEL_SENSOR_HAKO_HPP

#include "Sensor.hpp"
#include "openel_node.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"

#define SENSOR_HAKO_DATA_NUM 360

class SensorHako : public Sensor
{
private:
    static std::string strDevName;
    static std::vector<std::string> strFncLst;
    static std::shared_ptr<rclcpp::Subscription<sensor_msgs::msg::LaserScan>> subscriber;
    static void scanCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg);
    static double ranges[SENSOR_HAKO_DATA_NUM];

public:
    static Property SensorHako_property;

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

};

extern HAL_FNCTBL_T HalSensorHakoTbl;

#endif // OPENEL_SENSOR_HAKO_HPP
