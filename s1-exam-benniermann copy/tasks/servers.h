#pragma once

struct server {
    // requests per second
    unsigned int req_per_sec;
    // utilization of machine (0-100)
    unsigned int utilization;
    // geographical location
    const char* location;
};

/**
 * @brief Get the busiest server from a given array.
 * 
 * The given array will always have at least one element.
 * 
 * "busiest" refers to the number of requests being processed per second.
 * -> Higher req_per_sec = busier
 * 
 * If there are multiple servers that are equally busy,
 * this function should return a pointer to the first one.
 * 
 * @param servers array of servers
 * @param count number of elements in the array
 * @return pointer to the busiest server element in the array
 */
const struct server* get_busiest_server(const struct server* servers, unsigned int count);

/**
 * @brief Create subset of servers in a given location.
 * 
 * The original array must not be modified.
 * The function should return a dynamically allocated array containing the subset.
 * The subset must only contain servers whose location is the same as the provided
 * location parameter.
 * 
 * @param servers array of servers
 * @param count number of elements in the array
 * @param location the location string to match
 * @return dynamically allocated array containing the subset, or NULL in case the allocation is not successful
 */
struct server* get_servers_in_location(const struct server* servers, unsigned int count, const char* location);

/**
 * @brief Filter servers for a given utilization threshold in-place.
 * 
 * The filter operation should be performed in-place. Servers whose
 * utilization is below or equal to max_utilization should be moved to the front.
 * To inform the caller how many elements satisfied the filter condition,
 * the function should return that count.
 * 
 * Example:
 * Given an array: { { .utilization = 40 }, { .utilization = 20 }, { .utilization = 10 }, { .utilization = 80 }, { .utilization = 30 } }
 * and max_utilization of 20,
 * the second and third element should be moved to the front as such:
 * { { .utilization = 20 }, { .utilization = 10 }, ... }
 * Note that:
   - the order ofmatching elements is the same as inside the original array
 * - the order/values of the remaining elements does not matter
 * Overall, 2 elements matched the filter and were moved such that the first 2 elements
 * represent the subset. Thus, the function should return 2.
 * 
 * @param servers array of servers to filter in-place
 * @param count number of elements in the array
 * @param max_utilization inclusive max threshold the filtered subset should match
 * @return number of elements in the filtered subset
 */
unsigned int filter_servers_by_utilization(struct server* servers, unsigned int count, unsigned int max_utilization);

// helpers provided by us

void print_server(const char* description, struct server s);
void print_servers(const char* description, const struct server* servers, unsigned int count);
