#pragma once

/**
 * @brief Find minium in array of measurements.
 *
 * This function should always return 0 for an empty array.
 * 
 * @param measurements array of cycle count measurements
 * @param count number of elements in measurements
 * @return value of minimum element
 */
float min_cycles(const float* measurements, unsigned int count);

/**
 * @brief Find maximum in array of measurements.
 *
 * This function should always return 0 for an empty array.
 * 
 * @param measurements array of cycle count measurements
 * @param count number of elements in measurements
 * @return value of maximum element
 */
float max_cycles(const float* measurements, unsigned int count);

/**
 * @brief Calculate average of a given array of measurements.
 *
 * This function should always return 0 for an empty array.
 *
 * @param measurements array of cycle count measurements
 * @param count number of elements in measurements
 * @return average of all elements, or 0 if the array is empty
 */
float average_cycles(const float* measurements, unsigned int count);

/**
 * @brief Calculate standard deviation of a given array of measurements.
 * 
 * This function should always return 0 for an empty array.
 * You may use sqrtf to calculate the root of a float.
 *
 * The standard deviation for a given array `arr` with `count` number of
 * elements is defined as follows:
 * avg = average(arr)
 * s = square(arr[0] - avg) + ... + square(arr[count - 1] - avg)
 * variance = s / count
 * stddev = root(variance)
 * 
 * Example:
 * Given the array { 2, 3, 5, 6 }
 * avg = 16 / 4 = 4
 * s = square(2 - 4) + square(3 - 4) + square(5 - 4) + square(6 - 4)
 *   = square(-2)    + square(-1)    + square(1)     + square(2)
 *   = 4             + 1             + 1             + 4
 *   = 10
 * variance = 10 / 4 = 2.5
 * stddev = root(2.5) = ~1.5811
 *
 * @param measurements array of cycle count measurements
 * @param count number of elements in measurements
 * @return standard deviation of all elements, or 0 if the array is empty
 */
float standard_deviation(const float* measurements, unsigned int count);

/**
 * @brief Convert cycle to time measurements.
 * 
 * The function should return a dynamically allocated array
 * containing all elements of the original converted to actual
 * time using the given cycle_time parameter.
 * 
 * This functions should return NULL if the array is empty.
 * 
 * Example:
 * Given the array { 3, 5, 4 } and a cycle_time of 6
 * the function should return a new array with { 18, 30, 24 }.
 * 
 * @param measurements array of cycle count measurements
 * @param count number of elements in measurements
 * @param cycle_time time interval represented by a single cycle
 * @return dynamically allocated array containing the converted values, or NULL in case the array is empty or the allocation is not successful
 */
float* convert_to_time(const float* measurements, unsigned int count, float cycle_time);
