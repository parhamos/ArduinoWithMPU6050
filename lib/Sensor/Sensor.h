#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor
{

public:

    bool begin();

    bool update();

    bool connected();

    float ax();

    float ay();

    float az();

    float temperature();

private:

    float m_ax = 0.0f;

    float m_ay = 0.0f;

    float m_az = 0.0f;

    float m_temp = 0.0f;

    bool m_connected = false;

};

extern Sensor sensor;

#endif