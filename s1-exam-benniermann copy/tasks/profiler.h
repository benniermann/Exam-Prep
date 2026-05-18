#pragma once

typedef struct {
    // name of the function
    const char* func_name;
    // how many times it was called
    unsigned int call_count;
    // how much time was spent execution all of the calls combined
    unsigned int total_cpu_time;
} function_entry;

typedef struct {
    // array containing an entry for each unique func_name (no duplicates)
    function_entry* entries;
    // number of elements currently stored in entries
    unsigned int count;
    // number of elements the entries array can hold
    unsigned int capacity;
} function_profiler;

/**
 * @brief Create function profiler with a given entry capacity.
 * 
 * This function should dynamically allocate enough memory
 * to hold `capacity` number of function entries.
 * The returned profiler should be zeroed / NULLed in case the
 * dynamic allocation fails.
 * 
 * @param capacity number of function entries the returned profiler should be able to store
 * @return initialized profiler, zeroed / NULLed struct in case of an allocation failure
 */
function_profiler create_profiler(unsigned int capacity);

/**
 * @brief Add function call to the profiler entries.
 * 
 * If the given func_name already exists in the list of entries,
 * this function should increment the call_count of that entry
 * and add the given cpu_time to the total of the entry.
 * 
 * If the given func_name does not exist yet, add a new entry
 * with a call_count of 1, the given func_name and cpu_time.
 * 
 * You can assume, that there is enough capacity. (no resize necessary)
 * 
 * @param profiler profiler to add the function call to
 * @param func_name name of the function
 * @param cpu_time time used by the given function
 */
void add_function_call(function_profiler* profiler, const char* func_name, unsigned int cpu_time);

/**
 * @brief Sort the given profiler's entries by most used cpu time.
 * 
 * The array of entries should be sorted by their total_cpu_time
 * in descending order.
 * 
 * @param profiler profiler to sort
 */
void sort_entries(function_profiler* profiler);

/**
 * @brief Free memory and reset the given profiler.
 * 
 * This function should free the allocated memory
 * and set all members to 0/NULL.
 * 
 * @param profiler the profiler to destroy
 */
void destroy_profiler(function_profiler* profiler);

// helpers provided by us

void print_function_entry(const char *description, function_entry e);
void print_function_profiler(const char *description, function_profiler profiler);
