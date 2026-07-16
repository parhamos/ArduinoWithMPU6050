
bool Application::begin()
{
    Serial.begin(115200);

    Serial.println("Model");
    if (!model.begin())
        return false;

    Serial.println("Sensor");
    if (!sensor.begin())
        return false;

    Serial.println("Calibration");
    if (!calibration.begin())
        return false;

    Serial.println("Filter");
    if (!filter.begin())
        return false;

    Serial.println("Statistics");
    if (!statistics.begin())
        return false;

    Serial.println("Display");
    if (!display.begin())
        return false;

    Serial.println("Protocol");
    if (!protocol.begin())
        return false;

    Serial.println("Scheduler");
    if (!scheduler.begin())
        return false;

    model.status().firmware = FirmwareState::Ready;

    Serial.println("Application OK");

    return true;
}