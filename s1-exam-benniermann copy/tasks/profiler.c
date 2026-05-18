#include "profiler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

function_profiler create_profiler(unsigned int capacity) {
    function_profiler prof = {0};

    prof.entries = malloc(capacity * sizeof(function_entry));
    if (prof.entries == NULL)
        return prof;
    prof.capacity = capacity;
    prof.count    = 0;
    return prof;
}

void add_function_call(function_profiler *profiler, const char *func_name, unsigned int cpu_time) {}

void sort_entries(function_profiler *profiler) {}

void destroy_profiler(function_profiler *profiler) {}

// helpers provided by us

void print_function_entry(const char *description, function_entry e) {
    printf("%s{ .func_name = %18s, .call_count = %2u, .total_cpu_time = %3u }\n",
           description,
           e.func_name,
           e.call_count,
           e.total_cpu_time);
}

void print_function_profiler(const char *description, function_profiler profiler) {
    for (unsigned int i = 0; i < profiler.count; ++i) {
        print_function_entry(description, profiler.entries[i]);
    }
}
