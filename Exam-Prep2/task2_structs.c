#include "task2_structs.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

double student_average(const Student *s) 
{
    if(s == NULL || s->grade_count == 0) return 0.0;
    
    double all_grades = s->grades[0];

    for(int i = 1; i < s->grade_count; i++)
    {
        all_grades += s->grades[i];
    }

    double average = all_grades / (double)s->grade_count;
    return average;
}

Student *find_best_student(Student *students, int n) 
{
    if(n <= 0 ||students == NULL) return NULL;
    
    int best_index = 0;
    float best_grades = student_average(&students[0]);

    for (unsigned int i = 1; i < n; i++)
    {
        if(student_average(&students[i]) < best_grades)
        {
            best_grades = student_average(&students[i]);
            best_index = i;
        }
        
    }
    
    return &students[best_index];
}

void sort_students_by_average(Student *students, int n) 
{
    if(n <= 0 || students == NULL) return;

    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if(student_average(&students[j]) > student_average(&students[j + 1]))
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp; 
            }
        }
    }
}

int student_passed_all(const Student *s) 
{
    if(s == NULL || s->grade_count == 0) return 0;

    for(int i = 0; i < s->grade_count; i++)
    {
        if(s->grades[i] > 4.0)
        {        
            return 0;
        }
    }
    
    return 1;
}