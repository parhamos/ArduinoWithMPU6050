#include "Sensor.h"
#include "SensorPrivate.h"
#include "SensorConfig.h"

Adafruit_MPU6050 mpu;

Sensor sensor;

bool Sensor::begin()
{

    if (!mpu.begin())
    {
        m_connected = false;
        return false;
    }

    mpu.setAccelerometerRange(ACC_RANGE);

    mpu.setGyroRange(GYRO_RANGE);

    mpu.setFilterBandwidth(FILTER_BAND);

    m_connected = true;

    return true;

}

bool Sensor::update()
{

    if (!m_connected)
        return false;

    sensors_event_t a;
    sensors_event_t g;
    sensors_event_t t;

    mpu.getEvent(&a, &g, &t);

    m_ax = a.acceleration.x;

    m_ay = a.acceleration.y;

    m_az = a.acceleration.z;

    m_temp = t.temperature;

    return true;

}

bool Sensor::connected()
{
    return m_connected;
}

float Sensor::ax()
{
    return m_ax;
}

float Sensor::ay()
{
    return m_ay;
}

float Sensor::az()
{
    return m_az;
}

float Sensor::temperature()
{
    return m_temp;
}