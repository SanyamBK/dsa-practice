#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insertion_sort_with_indices(int nums[], int n, int indices[]) {
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    for (int i = 1; i < n; i++) {
        int key = nums[i];
        int key_index = indices[i];
        int j = i - 1;

        while (j >= 0 && nums[j] > key) {
            nums[j + 1] = nums[j];
            indices[j + 1] = indices[j];
            j--;
        }
        nums[j + 1] = key;
        indices[j + 1] = key_index;
    }
}

int largest_index_shift(int nums[], int n) {
    if (n == 0) return 0;

    int* indices = (int*)malloc(n * sizeof(int));
    if (indices == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    insertion_sort_with_indices(nums, n, indices);

    int max_shift = 0;
    for (int i = 0; i < n; i++) {
        int shift = abs(indices[i] - i);
        if (shift > max_shift) {
            max_shift = shift;
        }
    }

    free(indices);
    return max_shift;
}

void test_cases() {
    struct {
        int nums[100];
        int size;
        int expected;
    } tests[] = {
        {{1, 2, 3, 4, 5}, 5, 0},
        {{7, 7, 7, 7}, 4, 0},
        {{40, 10, 20, 50, 30}, 5, 3},
        {{5, 4, 3, 2, 1}, 5, 4},
        {{10}, 1, 0}
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < num_tests; i++) {
        int* nums_copy = (int*)malloc(tests[i].size * sizeof(int));
        if (nums_copy == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        for (int j = 0; j < tests[i].size; j++) {
            nums_copy[j] = tests[i].nums[j];
        }

        int result = largest_index_shift(nums_copy, tests[i].size);
        printf("Test Case %d: Input: ", i + 1);
        for (int j = 0; j < tests[i].size; j++) {
            printf("%d ", tests[i].nums[j]);
        }
        printf("| Expected: %d | Result: %d\n", tests[i].expected, result);
        if (result != tests[i].expected) {
            printf("Test Case %d Failed\n", i + 1);
        }
        free(nums_copy);
    }
    printf("All Test Cases Passed!\n");
}

int main() {
    test_cases();
    return 0;
}
