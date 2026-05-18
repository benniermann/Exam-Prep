#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include ".assignment/dhbw.h"
#include "tasks/encryption.h"
#include "tasks/profiler.h"
#include "tasks/servers.h"
#include "tasks/statistics.h"

#define RUN_STATISTICS_TESTS 1
#define RUN_SERVERS_TESTS    0
#define RUN_PROFILER_TESTS   0
#define RUN_ENCRYPTION_TESTS 1

int float_compare(float f1, float f2);

int main(int argc, const char *argv[]) {
    int failed_tests = 0;
#if RUN_STATISTICS_TESTS
    {
        dhbw_print_line("\nRunning statistics test");
        float arr[] = {
            6.20f,
            7.30f,
            8.40f,
            4.50f,
            7.70f,
            6.80f,
            6.80f,
            7.30f,
            6.90f,
            4.30f,
        };
        unsigned int size = sizeof(arr) / sizeof(arr[0]);
        dhbw_print_arr("  Using measurements", arr, size);
        {
            dhbw_print_line("\n  Running min_cycles test");
            float expected = 4.3f;
            dhbw_print_float("  Expected", expected);
            float actual = min_cycles(arr, size);
            dhbw_print_float("    Actual", actual);
            if (float_compare(expected, actual) != 0) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running max_cycles test");
            float expected = 8.4f;
            dhbw_print_float("  Expected", expected);
            float actual = max_cycles(arr, size);
            dhbw_print_float("    Actual", actual);
            if (float_compare(expected, actual) != 0) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running average_cycles test");
            float expected = 6.62f;
            dhbw_print_float("  Expected", expected);
            float actual = average_cycles(arr, size);
            dhbw_print_float("    Actual", actual);
            if (float_compare(expected, actual) != 0) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running standard_deviation test");
            float expected = 1.24f;
            dhbw_print_float("  Expected", expected);
            float actual = standard_deviation(arr, size);
            dhbw_print_float("    Actual", actual);
            if (float_compare(expected, actual) != 0) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running convert_to_time test");
            float cycle_time = 3.14f;
            dhbw_print_float("  Using cycle_time", cycle_time);
            float expected[] = {
                19.47f,
                22.92f,
                26.38f,
                14.13f,
                24.18f,
                21.35f,
                21.35f,
                22.92f,
                21.67f,
                13.50f,
            };
            static_assert(sizeof(expected) == sizeof(arr), "expected result size must match input array size");
            dhbw_print_arr("  Expected", expected, size);
            float *actual = convert_to_time(arr, size, cycle_time);
            if (actual) {
                dhbw_print_arr("    Actual", actual, size);
                for (unsigned int i = 0; i < size; ++i) {
                    if (float_compare(expected[i], actual[i]) != 0) {
                        ++failed_tests;
                        dhbw_print_line("  -> Mismatch detected");
                        break;
                    }
                }
                free(actual);
            } else {
                ++failed_tests;
                dhbw_print_line("    Actual: NULL  -> Mismatch detected");
            }
        }
    }
#endif
#if RUN_SERVERS_TESTS
    {
        dhbw_print_line("\nRunning servers tests");
        struct server servers[] = {
            { .req_per_sec = 30,  .utilization = 60, .location = "USA-EAST"},
            { .req_per_sec = 25,  .utilization = 40, .location = "USA-EAST"},
            {  .req_per_sec = 5,  .utilization = 10, .location = "USA-WEST"},
            { .req_per_sec = 60, .utilization = 100, .location = "USA-WEST"},
            {.req_per_sec = 130,  .utilization = 30, .location = "USA-WEST"},
            {  .req_per_sec = 1,   .utilization = 0, .location = "EUROPE-C"},
        };
        unsigned int size = sizeof(servers) / sizeof(servers[0]);
        dhbw_print_line("  Using servers:");
        print_servers("    ", servers, size);
        {
            dhbw_print_line("\n  Running get_busiest_server test");
            const struct server *expected = &servers[4];
            dhbw_print_address("    Expected", expected);
            print_server("    Expected: ", *expected);
            const struct server *actual = get_busiest_server(servers, size);
            if (actual) {
                dhbw_print_address("      Actual", actual);
                print_server("      Actual: ", *actual);
                if (expected != actual) {
                    ++failed_tests;
                    dhbw_print_line("  -> Mismatch detected");
                }
            } else {
                ++failed_tests;
                dhbw_print_line("      Actual: NULL  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running get_servers_in_location test");
            const char *location = "USA-WEST";
            dhbw_print_string("  Looking for location", location);
            struct server expected[] = {servers[2], servers[3], servers[4]};
            unsigned int  exp_size   = sizeof(expected) / sizeof(expected[0]);
            dhbw_print_line("    Expected:");
            print_servers("      ", expected, exp_size);
            struct server *actual = get_servers_in_location(servers, size, location);
            if (actual) {
                dhbw_print_line("      Actual:");
                print_servers("      ", actual, exp_size);
                if (memcmp(expected, actual, sizeof(expected)) != 0) {
                    ++failed_tests;
                    dhbw_print_line("  -> Mismatch detected");
                }
                free(actual);
            } else {
                ++failed_tests;
                dhbw_print_line("      Actual: NULL  -> Mismatch detected");
            }
        }
        {
            dhbw_print_line("\n  Running filter_servers_by_utilization test");
            unsigned int threshold = 20;
            dhbw_print_integer("    Filtering for threshold", threshold);
            struct server expected[] = {servers[2], servers[5]};
            unsigned int  exp_size   = sizeof(expected) / sizeof(expected[0]);
            dhbw_print_integer("    Expected new size", exp_size);
            printf("    Expected elements at indexes [0,%u):\n", exp_size);
            print_servers("      ", expected, exp_size);
            unsigned int act_size = filter_servers_by_utilization(servers, size, threshold);
            dhbw_print_integer("      Actual new size", act_size);
            if (exp_size != act_size) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
            printf("      Actual elements at indexes [0,%u):\n", act_size);
            print_servers("      ", servers, act_size);
            if (memcmp(expected, servers, sizeof(expected)) != 0) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
        }
    }
#endif
#if RUN_PROFILER_TESTS
    {
        dhbw_print_line("\nRunning profiler tests");
        unsigned int capa = 8;
        dhbw_print_integer("  Creating profiler with capacity", capa);
        function_profiler p = create_profiler(capa);
        if (p.entries) {
            dhbw_print_integer("\n    Expected capacity", capa);
            dhbw_print_integer("      Actual capacity", p.capacity);
            if (capa != p.capacity) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
            dhbw_print_integer("\n  Adding \"process_input\" with cpu time", 100);
            add_function_call(&p, "process_input", 100);
            dhbw_print_integer("  Adding \"calculate_physics\" with cpu time", 480);
            add_function_call(&p, "calculate_physics", 480);
            dhbw_print_integer("  Adding \"render_stuff\" with cpu time", 200);
            add_function_call(&p, "render_stuff", 200);
            dhbw_print_integer("  Adding \"sync_network\" with cpu time", 900);
            add_function_call(&p, "sync_network", 900);
            dhbw_print_integer("  Adding \"process_input\" with cpu time", 110);
            add_function_call(&p, "process_input", 110);
            dhbw_print_integer("  Adding \"calculate_physics\" with cpu time", 530);
            add_function_call(&p, "calculate_physics", 530);
            dhbw_print_integer("  Adding \"render_stuff\" with cpu time", 250);
            add_function_call(&p, "render_stuff", 250);
            dhbw_print_integer("  Adding \"process_input\" with cpu time", 90);
            add_function_call(&p, "process_input", 90);
            dhbw_print_integer("  Adding \"calculate_physics\" with cpu time", 490);
            add_function_call(&p, "calculate_physics", 490);
            dhbw_print_integer("  Adding \"render_stuff\" with cpu time", 180);
            add_function_call(&p, "render_stuff", 180);
            dhbw_print_integer("  Adding \"sync_network\" with cpu time", 950);
            add_function_call(&p, "sync_network", 950);

            function_entry before_sort_entries[] = {
                {    .func_name = "process_input", .call_count = 3,  .total_cpu_time = 300},
                {.func_name = "calculate_physics", .call_count = 3, .total_cpu_time = 1500},
                {     .func_name = "render_stuff", .call_count = 3,  .total_cpu_time = 630},
                {     .func_name = "sync_network", .call_count = 2, .total_cpu_time = 1850},
            };
            function_profiler expected = {
                .capacity = capa,
                .count    = sizeof(before_sort_entries) / sizeof(before_sort_entries[0]),
                .entries  = before_sort_entries,
            };
            dhbw_print_integer("\n    Expected count", expected.count);
            dhbw_print_integer("      Actual count", p.count);
            if (expected.count != p.count) {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected");
            }
            dhbw_print_line("\n    Expected before sort:");
            print_function_profiler("      ", expected);
            dhbw_print_line("    Actual before sort:");
            print_function_profiler("      ", p);
            for (unsigned int i = 0; i < expected.count; ++i) {
                function_entry *e = expected.entries + i;
                function_entry *a = p.entries + i;
                if (a->func_name == NULL || strcmp(e->func_name, a->func_name) != 0 || e->call_count != a->call_count
                    || e->total_cpu_time != a->total_cpu_time) {
                    ++failed_tests;
                    dhbw_print_integer("  -> Mismatch detected at index", i);
                }
            }

            dhbw_print_line("\n  Sorting profiler results");
            sort_entries(&p);
            function_entry after_sort_entries[] = {
                {     .func_name = "sync_network", .call_count = 2, .total_cpu_time = 1850},
                {.func_name = "calculate_physics", .call_count = 3, .total_cpu_time = 1500},
                {     .func_name = "render_stuff", .call_count = 3,  .total_cpu_time = 630},
                {    .func_name = "process_input", .call_count = 3,  .total_cpu_time = 300},
            };
            static_assert(sizeof(before_sort_entries) == sizeof(after_sort_entries),
                          "entry count must not change after sort");
            expected = (function_profiler) {
                .capacity = capa,
                .count    = sizeof(after_sort_entries) / sizeof(after_sort_entries[0]),
                .entries  = after_sort_entries,
            };
            dhbw_print_line("\n    Expected after sort:");
            print_function_profiler("      ", expected);
            dhbw_print_line("    Actual after sort:");
            print_function_profiler("      ", p);
            for (unsigned int i = 0; i < expected.count; ++i) {
                function_entry *e = expected.entries + i;
                function_entry *a = p.entries + i;
                if (a->func_name == NULL || strcmp(e->func_name, a->func_name) != 0 || e->call_count != a->call_count
                    || e->total_cpu_time != a->total_cpu_time) {
                    ++failed_tests;
                    dhbw_print_integer("  -> Mismatch detected at index", i);
                    break;
                }
            }

            dhbw_print_line("\n  Destroying profiler");
            destroy_profiler(&p);
        } else {
            ++failed_tests;
            dhbw_print_line("  No valid profiler created. -> Mismatch detected");
        }
    }
#endif
#if RUN_ENCRYPTION_TESTS
    {
        dhbw_print_line("\nRunning encryption tests");
        {
            char        offset    = 4;
            const char *msg       = "hello";
            const char *file_name = "files/hello-output.enc";
            printf("\n  Encrypting \"%s\" with the offset %d to %s\n", msg, offset, file_name);
            FILE *file = fopen(file_name, "w");
            if (file) {
                encrypt(msg, offset, file);
                fclose(file);
            } else {
                dhbw_print_line("SOMETHING IS WRONG, CONTACT US");
                return -1;
            }
            file = fopen(file_name, "r");
            if (file) {
                char buf[256] = {0};
                fgets(buf, sizeof(buf), file);
                const char *expected = "5;lipps";
                dhbw_print_string("    Expected", expected);
                dhbw_print_string("      Actual", buf);
                if (strcmp(buf, expected)) {
                    ++failed_tests;
                    dhbw_print_line("  -> Mismatch detected");
                }
                fclose(file);
            } else {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected, no file was written");
            }
        }
        {
            char        offset    = 42;
            const char *msg       = "now this is the story all about how";
            const char *file_name = "files/bel-output.enc";
            printf("\n  Encrypting \"%s\" with the offset %d to %s\n", msg, offset, file_name);
            FILE *file = fopen(file_name, "w");
            if (file) {
                encrypt(msg, offset, file);
                fclose(file);
            } else {
                dhbw_print_line("SOMETHING IS WRONG, CONTACT US");
                return -1;
            }
            file = fopen(file_name, "r");
            if (file) {
                char buf[256] = {0};
                fgets(buf, sizeof(buf), file);
                const char *expected = "35;dem jxyi yi jxu ijeho qbb qrekj xem";
                dhbw_print_string("    Expected", expected);
                dhbw_print_string("      Actual", buf);
                if (strcmp(buf, expected)) {
                    ++failed_tests;
                    dhbw_print_line("  -> Mismatch detected");
                }
                fclose(file);
            } else {
                ++failed_tests;
                dhbw_print_line("  -> Mismatch detected, no file was written");
            }
        }
        {
            char        offset     = 4;
            const char  expected[] = "hello";
            const char *file_name  = "files/hello-input.enc";
            printf("\n  Decrypting %s with the offset %d\n", file_name, offset);
            FILE *file = fopen(file_name, "r");
            if (file) {
                dhbw_print_string("    Expected", expected);
                char *actual = decrypt(offset, file);
                if (actual) {
                    dhbw_print_string("      Actual", actual);
                    if (actual[sizeof(expected) - 1] != '\0') {
                        ++failed_tests;
                        dhbw_print_line("  -> Mismatch detected, result string is not properly null-terminated");
                    } else if (strcmp(actual, expected)) {
                        ++failed_tests;
                        dhbw_print_line("  -> Mismatch detected");
                    }
                    free(actual);
                } else {
                    ++failed_tests;
                    dhbw_print_line("      Actual: NULL");
                    dhbw_print_line("  -> Mismatch detected");
                }
                fclose(file);
            } else {
                dhbw_print_line("SOMETHING IS WRONG, CONTACT US");
                return -1;
            }
        }
        {
            char        offset     = 42;
            const char  expected[] = "my life got flipped turned upside down";
            const char *file_name  = "files/air-input.enc";
            printf("\n  Decrypting %s with the offset %d\n", file_name, offset);
            FILE *file = fopen(file_name, "r");
            if (file) {
                dhbw_print_string("    Expected", expected);
                char *actual = decrypt(offset, file);
                if (actual) {
                    dhbw_print_string("      Actual", actual);
                    if (actual[sizeof(expected) - 1] != '\0') {
                        ++failed_tests;
                        dhbw_print_line("  -> Mismatch detected, result string is not properly null-terminated");
                    } else if (strcmp(actual, expected)) {
                        ++failed_tests;
                        dhbw_print_line("  -> Mismatch detected");
                    }
                    free(actual);
                } else {
                    ++failed_tests;
                    dhbw_print_line("      Actual: NULL");
                    dhbw_print_line("  -> Mismatch detected");
                }
                fclose(file);
            } else {
                dhbw_print_line("SOMETHING IS WRONG, CONTACT US");
                return -1;
            }
        }
    }
#endif
    dhbw_print_integer("\nFailed test cases", failed_tests);
    return failed_tests;
}

int float_compare(float f1, float f2) {
    float eps  = 0.005f;
    float diff = f1 - f2;
    if (diff > eps) {
        return 1;
    }
    if (diff < -eps) {
        return -1;
    }
    return 0;
}
