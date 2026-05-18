#include "statistics.h"

#include <math.h>
#include <stdlib.h>

float min_cycles(const float *measurements, unsigned int count) {
    if (count == 0 || measurements == NULL)
        return 0;
    float min = measurements[0];
    for (int i = 1; i < count; i++) {
        if (measurements[i] < min) {
            min = measurements[i];
        }
    }
    return min;
}

float max_cycles(const float *measurements, unsigned int count) {
    if (count == 0 || measurements == NULL)
        return 0;
    float max = measurements[0];
    for (int i = 1; i < count; i++) {
        if (measurements[i] > max) {
            max = measurements[i];
        }
    }
    return max;
}

float average_cycles(const float *measurements, unsigned int count) {
    if (count == 0 || measurements == NULL)
        return 0;
    float temp = measurements[0];
    for (int i = 1; i < count) {
        temp += measurements[i];
    }
    return temp / (float) count;
}

float standard_deviation(const float *measurements, unsigned int count) {
    if (count == 0 || measurements == NULL)
        return 0;

    float avg = average_cycles(measurements, count);

    float s        = powf(measurements[0] - avg, 2);
    float variance = s / (float) count;

    float stddev = sqrtf(variance);

    return stddev;
}

float *convert_to_time(const float *measurements, unsigned int count, float cycle_time) {
    if (count == 0 || measurements == NULL)
        return NULL;

    float *arr = malloc(count * sizeof(float));

    for (int i = 0; i < count; i++) {
        arr[i] = measurements[i] * cycle_time;
    }

    return arr;
}
