#pragma once

/**
 * Print an integer with a description to the standard output.
 * 
 * Example usage:
 *  dhbw_print_integer("my integer", 25);
 * 
 * @param description a formal description of the number to be printed
 * @param v the actual integer value
 */
void dhbw_print_integer(const char* description, long long v);

/**
 * Print a single line of text to the standard output.
 * 
 * Example usage:
 *  dhbw_print_line("this is very important!");
 * 
 * @param text the line of text to print
 */
void dhbw_print_line(const char* text);

/**
 * Print a floating point number with a description to the standard output.
 * 
 * Example usage:
 *  dhbw_print_float("my bmi is", 6.9);
 * 
 * @param description a formal description of the number to be printed
 * @param v the actual float value
 */
void dhbw_print_float(const char* description, double v);

/**
 * Print the bitwise representation of an unsigned integer starting from the MSB.
 * 
 * Example usage:
 *  dhbw_print_bitwise_int("large number", 65000);
 * The above would result in the following being printed into the console:
 *  00000000000000001111110111101000: large number
 * 
 * @param description a formal description of the value to be printed
 * @param v the actual unsigned integer value to print
 */
void dhbw_print_bitwise_uint(const char *description, unsigned int v);

/**
 * Print the bitwise representation of an integer starting from the MSB.
 * 
 * Example usage:
 *  dhbw_print_bitwise_int("negative number", -4);
 * The above would result in the following being printed into the console:
 *  11111111111111111111111111111100: negative number
 * 
 * @param description a formal description of the value to be printed
 * @param v the actual integer value to print
 */
void dhbw_print_bitwise_int(const char *description, int v);

/**
 * @brief Print string with a formal description.
 * 
 * Example usage:
 *  const char *test = "Test";
 *  dhbw_print_string("test value", test);
 * 
 * @param description a formal description of the value to be printed
 * @param v string to print
 */
void dhbw_print_string(const char *description, const char *v);

/**
 * @brief Print address stored in a pointer.
 * 
 * Example usage:
 *  int i = 5;
 *  dhbw_print_address("address of i", &i);
 * 
 * @param description a formal description of the value to be printed
 * @param v pointer to print
 */
void dhbw_print_address(const char *description, const void *v);

/**
 * Print an array of float with a description to the standard output.
 * 
 * Example usage:
 *  dhbw_print_arr("last years sales", arr, 5);
 * 
 * @param description a formal description of the array to be printed
 * @param arr pointer to the data of the array
 * @param size the number of elements in the array
 */
void dhbw_print_arr(const char *description, const float *arr, unsigned int size);
