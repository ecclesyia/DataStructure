#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[50];
    int id;
} Course;

int main() {
    printf("--- Session 01: Dynamic Memory Allocation (Heap) ---\n\n");

    int initial_size = 2;
    // Allocate heap memory for 2 Course structures
    Course *course_list = (Course *)malloc(initial_size * sizeof(Course));

    // Always check if allocation was successful
    if (course_list == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate initial items
    strcpy(course_list[0].title, "Data Structures");
    course_list[0].id = 101;

    strcpy(course_list[1].title, "Algorithms & Programming");
    course_list[1].id = 102;

    printf("[1] Initial List (Heap Allocated):\n");
    for (int i = 0; i < initial_size; i++) {
        printf("Course %d: ID = %d | Title = %s\n", i + 1, course_list[i].id, course_list[i].title);
    }
    printf("\n");

    // Let's expand the list to hold 3 items using realloc
    int new_size = 3;
    printf("[2] Resizing list using realloc to size %d...\n", new_size);
    Course *temp = (Course *)realloc(course_list, new_size * sizeof(Course));

    if (temp == NULL) {
        printf("Resizing failed! Original memory remains allocated.\n");
        free(course_list); // Free original before exit to avoid memory leak
        return 1;
    }
    course_list = temp; // Point to new resized block

    // Populate the new element
    strcpy(course_list[2].title, "Discrete Mathematics");
    course_list[2].id = 103;

    printf("[3] Resized List:\n");
    for (int i = 0; i < new_size; i++) {
        printf("Course %d: ID = %d | Title = %s\n", i + 1, course_list[i].id, course_list[i].title);
    }
    printf("\n");

    // Clean up heap memory to avoid leaks
    printf("[4] Freeing heap memory...\n");
    free(course_list);
    course_list = NULL; // Good practice: prevent dangling pointer reference

    printf("Memory successfully cleared.\n");

    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}
