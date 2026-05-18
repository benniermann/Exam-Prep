# STG-TES25: C Programming Exam

Welcome to the C programming exam. This exam is designed
to assess your understanding and proficiency in fundamental
and advanced C programming concepts, including memory management,
data structures, algorithms, and file handling.

----------------------------------------------------------

1. ***You are not allowed to use the internet except for accessing the codespace.***
2. ***You are not allowed to communicate with others in any form.***
3. ***You are not allowed to use LLMs in any way, shape or form.***

***Any violation of the above rules will be considered an attempt at cheating and will result in immediate exclusion from the exam.***

----------------------------------------------------------

## Exam Structure

You will be given a set of four independent programming tasks.
These tasks can be solved in any order.

Each task is provided in the `tasks/` folder, as a pair of header and source files.

The header files contain documentation comments describing the functions intended behavior,
hints, additional conditions/restrictions as well as semantics of parameters and return values.

This README also contains task descriptions and examples that differ from those found in the header files. They both communicate the same context, so you can freely choose what you find more helpful.

We have included test cases for each task to help you verify your implementations.
However, be aware that these tests do not cover all possible cases.
You can extend the tests if you want to.

**Read each task carefully and implement exactly what is required.**

## Hand-In

To successfully submit your exam, follow these steps:

0. *(optional but highly appreciated)* Make sure your code is compiling successfully.
1. Commit your changes as you would for your weekly assignments (stage files, create a commit, and provide a commit message).
2. Committing will generate a ZIP file named `submission_<repo name>.zip`
3. Download that ZIP file
4. Rename the ZIP file to `[your matrikelnummer].zip` (e.g. `081507.zip`)
5. Upload the ZIP file on Moodle.
6. Inform us that you have completed the exam.
7. Wait for confirmation that your submission has been successfully uploaded.
8. You're done!

### We wish you much success!

## Table of Contents

- [Task 1 - Statistics](#task-1---statistics)
   * [Task 1.1 Cycle Analysis](#task-11-cycle-analysis)
   * [Task 1.2 Standard Deviation](#task-12-standard-deviation)
   * [Task 1.3 Time Conversion](#task-13-time-conversion)
- [Task 2 - Servers](#task-2---servers)
   * [Task 2.1 Get Busiest Server](#task-21-get-busiest-server)
   * [Task 2.2 Get Servers in Location](#task-22-get-servers-in-location)
   * [Task 2.3 Filter Servers by Utilization](#task-23-filter-servers-by-utilization)
- [Task 3 - Profiler](#task-3---profiler)
   * [Task 3.1 Create Profiler](#task-31-create-profiler)
   * [Task 3.2 Add Function Call](#task-32-add-function-call)
   * [Task 3.3 Sort Entries](#task-33-sort-entries)
   * [Task 3.4 Destroy](#task-34-destroy)
   * [Task 3.5 BONUS: Resizing](#task-35-bonus-resizing)
- [Task 4 - Encryption](#task-4---encryption)
   * [Task 4.1 Encrypt](#task-41-encrypt)
   * [Task 4.2 BONUS: Decrypt](#task-42-bonus-decrypt)

---

## Task 1 - Statistics

Statistical analysis is fundamental in evaluating benchmarks.
This task involves implementing functions for analyzing measurement data including minimum, maximum, average, standard deviation, and time conversion.

**Header File:** `tasks/statistics.h`

### Task 1.1 Cycle Analysis

Implement functions to find minimum and maximum cycle counts in benchmark measurements:

```c
float min_cycles(const float* measurements, unsigned int count)
float max_cycles(const float* measurements, unsigned int count)
```

**Requirements:**
- `min_cycles`: Return the smallest value in the measurements array
- `max_cycles`: Return the largest value in the measurements array
- Both functions should return 0 if the array is empty

**Example:**
```c
float data[] = { 10.5, 5.2, 8.7, 3.1 };
float minimum = min_cycles(data, 4);  // Returns 3.1
float maximum = max_cycles(data, 4);  // Returns 10.5
```

### Task 1.2 Standard Deviation

Implement functions for statistical analysis:

```c
float average_cycles(const float* measurements, unsigned int count)
float standard_deviation(const float* measurements, unsigned int count)
```

**Requirements:**
- `average_cycles`: Calculate and return the mean of the measurements
- `standard_deviation`: Calculate and return the standard deviation
- Return 0 if the array is empty

**Formula for standard deviation:**
$$\sigma = \sqrt{\frac{\sum_{i=0}^{n-1}(x_i - \mu)^2}{n}}$$

where $\mu$ is the average.

**Hint:**

You may use `math.h`'s `sqrtf` to calculate the root of a float.

**Example:**
```c
float data[] = { 10.5, 5.2, 8.7, 3.1 };
float avg = average_cycles(data, 4);        // Returns  6.875
float stddev = standard_deviation(data, 4); // Returns ~2.895
```

### Task 1.3 Time Conversion

Implement a function to convert cycle measurements to time values:

```c
float* convert_to_time(const float* measurements, unsigned int count, float cycle_time)
```

**Requirements:**
- Convert each cycle measurement to time by multiplying with `cycle_time`
- Allocate and return a new array with converted values
- The caller is responsible for freeing the returned array
- Return `NULL` if the given array is empty, or the allocation fails

**Example:**
```c
float cycles[] = { 100.0, 200.0, 300.0 };
float* times = convert_to_time(cycles, 3, 0.01);
// times[0] = 1.0, times[1] = 2.0, times[2] = 3.0
free(times);
```

---

## Task 2 - Servers

Server management is critical for distributed system operations. This task involves implementing functions to analyze and filter servers based on various criteria.

**Header File:** `tasks/servers.h`

### Data Structure

#### `server`
```c
struct server {
    unsigned int req_per_sec;
    unsigned int utilization;
    const char* location;
};
```

Represents a server with its request rate, current utilization, and geographic location.

### Task 2.1 Get Busiest Server

Implement a function that identifies the server handling the most requests:

```c
const struct server* get_busiest_server(const struct server* servers, unsigned int count)
```

**Requirements:**
- Find the server with the highest `req_per_sec` value
- Return a pointer to that server
- The array is guaranteed to have at least one element

**Example:**
```c
struct server servers[] = {
    { 100, 50, "US-East" },
    { 150, 75, "US-West" },
    { 120, 60, "EU-West" }
};
const struct server* busiest = get_busiest_server(servers, 3);
// Returns pointer to server with req_per_sec = 150 (US-West)
```

### Task 2.2 Get Servers in Location

Implement a function that filters servers by geographic location:

```c
struct server* get_servers_in_location(const struct server* servers, unsigned int count, const char* location)
```

**Requirements:**
- Filter servers that match the specified location
- Allocate and return a new array containing matching servers
- The caller is responsible for freeing the returned array
- The returned array may be empty if no matches are found

**Example:**
```c
struct server* us_e_servers = get_servers_in_location(servers, 3, "US-East");
// Returns newly allocated array with matching servers
free(us_e_servers);
```

### Task 2.3 Filter Servers by Utilization

Implement a function that filters servers by a utilization threshold:

```c
unsigned int filter_servers_by_utilization(struct server* servers, unsigned int count, unsigned int max_utilization)
```

**Requirements:**
- Filter servers with `utilization` at or below the specified threshold
- Modify the array in-place, moving matching servers to the front
- Retain the order of matching elements
- Return the new count of filtered servers
- Non-matching servers can be moved or discarded (their order or existence doesn't matter)

**Example:**
```c
struct server servers[] = {
    { 100, 50, "US-East" },
    { 150, 75, "US-West" },
    { 120, 60, "EU-West" }
};
unsigned int count = filter_servers_by_utilization(servers, 3, 60);
// count = 2, front of array contains { 100, 50, "US-East" } and { 120, 60, "EU-West" }
```

---

## Task 3 - Profiler

A profiler is a tool that measures how a program executes - tracking things like function call frequency, execution time, memory usage, and CPU consumption. Profiling is the process of using such a tool to identify performance bottlenecks and optimize code efficiency.
In this task, you will create a function profiler's ability to track function calls and their CPU time consumption. You will implement a data structure that can store information about function execution/calls.

**Header File:** `tasks/profiler.h`

### Data Structures

#### `function_entry`
```c
typedef struct {
    const char* func_name;
    unsigned int call_count;
    unsigned int total_cpu_time;
} function_entry;
```

Stores information about a profiled function including its name, call count, and accumulated CPU time.

#### `function_profiler`
```c
typedef struct {
    function_entry* entries;
    unsigned int count;
    unsigned int capacity;
} function_profiler;
```

Manages a collection of profiled functions with dynamic allocation.

### Task 3.1 Create Profiler

Implement a function that initializes a new profiler with a specified capacity:

```c
function_profiler create_profiler(unsigned int capacity)
```

**Requirements:**
- Allocate memory for an array of `function_entry` structures
- Initialize the profiler with the given capacity only if the allocation was successful
- Set the count to 0 (no entries initially)
- Return the initialized profiler structure

**Example:**
```c
function_profiler prof = create_profiler(10);
// prof.capacity = 10, prof.count = 0, prof.entries points to allocated memory
```

### Task 3.2 Add Function Call

Implement a function that records individual function calls and their CPU time:

```c
void add_function_call(function_profiler* profiler, const char* func_name, unsigned int cpu_time)
```

**Requirements:**
- Check if the function name already exists in the profiler's entries
- If it exists, increment `call_count` and add to `total_cpu_time`
- If it doesn't exist, create a new entry with a call count of 1 and the given CPU time
- You can assume the profiler has enough capacity

**Example:**
```c
add_function_call(&prof, "process_data", 150);  // Creates new entry
add_function_call(&prof, "process_data", 200);  // Updates existing entry
add_function_call(&prof, "render", 300);        // Creates new entry
```

### Task 3.3 Sort Entries

Implement a function that sorts profiler entries by CPU time consumption:

```c
void sort_entries(function_profiler* profiler)
```

**Requirements:**
- Sort entries in descending order of `total_cpu_time`
- Functions with the highest total CPU time should appear first
- Use any sorting algorithm (bubble sort, quicksort, etc.)

### Task 3.4 Destroy

Implement a function that frees the allocated memory and sets all members to either 0 or NULL.

```c
void destroy_profiler(function_profiler* profiler);
```

**Requirements:**
- Allocated memory is freed
- Members are set to 0 or NULL

### Task 3.5 BONUS: Resizing

This is a bonus task. If you've got enough time, you can do this task to gain additional points.
**Note:** If you have working code for task 3.2, please make sure to create a backup (e.g. copy and comment it out). This will ensure, that you will still get points for that task, even if this Bonus Task might lead to errors in that function. You can also comment this task's code out, if you are unsure whether the implementation works.

Enhance your Profiler's `add_function_call` function (from Task 3.2) to allow for dynamic resizing. Whenever the size of the profiler would exceed the capacity, resize the array accordingly to have enough space for additional items.
When this case happens, the capacity should double. If the resizing fails (no allocation is possible).

Example:
```
function_profiler prof = create_profiler(3);
add_function_call(&prof, "process_data", 150);
add_function_call(&prof, "process_data", 200);
add_function_call(&prof, "render", 400);       // -> size: 3, capacity: 3
add_function_call(&prof, "clear", 100);        // this call would exceed the capacity, therefore double it -> new size: 4, new capacity: 6
```

---

## Task 4 - Encryption

Encryption is vital for securing sensitive information. In this task, you will implement functions for encrypting and decrypting messages using a character offset cipher.

**Header File:** `tasks/encryption.h`

### Task 4.1 Encrypt

Implement a function that encrypts a message and writes it to a file:

```c
void encrypt(const char* message, char offset, FILE* output)
```

**Requirements:**
- Write the message length followed by a semicolon: `<length>;`
- Apply the offset to each character in the message
- Preserve spaces (do not encrypt them)
- Use modulo 26 arithmetic for wrapping around the alphabet
- Write the encrypted message to the output file

**Encryption Algorithm:**
- Each character is shifted by the offset value
- Wrapping: use modulo 26 to keep values within the lowercase letter range

**Example:**
```c
FILE* out = fopen("encrypted.txt", "w");
encrypt("hello", 3, out);
// h+3=k, e+3=h, l+3=o, l+3=o, o+3=r
fclose(out);
// File contains: 5;khoor
```

### Task 4.2 BONUS: Decrypt

This is a bonus task. If you've got enough time, you can do this task to gain additional points.

Implement a function that decrypts a message from a file:

```c
char* decrypt(char offset, FILE* input)
```

**Requirements:**
- Read the message length from the file (format: `<length>;`)
- Allocate memory for the decrypted message
- Apply the reverse offset to each character
- Preserve spaces
- Return a dynamically allocated null-terminated string
- Return NULL if an error occurs

**Decryption Algorithm:**
- Reverse the offset operation to restore original characters
- Use modulo 26 arithmetic for wrapping

**Example:**
```c
FILE* in = fopen("encrypted.txt", "r");
// File contains: 5;khoor
char* message = decrypt(3, in);
// message = "hello"
// k-3=h, h-3=e, o-3=l, o-3=l, r-3=o
free(message);
fclose(in);
```
