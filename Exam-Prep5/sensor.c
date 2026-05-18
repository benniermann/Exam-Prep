#include <stdlib.h>
#include "sensor.h"

Sensor *create_sensor_array(int count)
{
    Sensor *new_sensor = calloc(count, sizeof(Sensor));

    return new_sensor;
}

double average_active_temperature(const Sensor *sensors, int count)
{
    if (sensors == NULL || count <= 0)
        return 0;

    double sum = 0;
    int active_count = 0;

    for (int i = 0; i < count; i++)
    {
        if (sensors[i].active)
        {
            sum += sensors[i].temperature;
            active_count++;
        }
    }

    if (active_count == 0)
        return 0;

    return sum / active_count;
}

void deactivate_below_threshold(Sensor *sensors, int count, double threshold)
{
    if (sensors == NULL || count == 0)
        return;

    for (int i = 0; i < count; i++)
    {
        if (sensors[i].temperature < threshold)
        {
            sensors[i].active = 0;
        }
    }
}

int find_hottest_sensor(const Sensor *sensors, int count)
{
    if (sensors == NULL || count <= 0)
        return -1;

    int hottest_index = 0;
    double highest_temp = sensors[0].temperature;

    for (int i = 1; i < count; i++)
    {
        if (sensors[i].temperature > highest_temp)
        {
            highest_temp = sensors[i].temperature;
            hottest_index = i;
        }
    }

    return hottest_index;
}