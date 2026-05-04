#ifndef DATA_H
#define DATA_H
#include <stdio.h>
#include "test_cases.h"

// Change TEST_CASE in test_cases.h to change test case

static int *mainset = mainset_val;
static int (*subsets)[item_count] = subsets_val;

void print_sol(int result, int *state, int run_count) {
    if (result == 9999) {
        printf("No solution found.\n");
    } else {
        printf("Minimum Subsets Needed: %d\n", result);
        
        for (int i = 0; i < result; i++) {
            int subset_idx = state[i]; 
            printf("Subset %d contains: ", subset_idx);
            for (int j = 0; j < item_count; j++) {
                if (subsets[subset_idx][j] <= 0 && subsets[subset_idx][j] != -1) break;
                if (subsets[subset_idx][j] == -1) break;
                printf("%d ", subsets[subset_idx][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("The function was run %d times to find the solution.\n", run_count);
}

int is_same_state(int s1[], int s2[], int n) {
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

int is_valid_subset(int subset[], int current_state[], int mainset_ref[], int num_main, int num_items, int target_value) {
    int has_target = 0;
    for (int j = 0; j < num_items; j++) {
        int val = subset[j];
        if (val == -1 || val == 0) break;

        if (val == target_value) has_target = 1;

        for (int k = 0; k < num_main; k++) {
            if (mainset_ref[k] == val && current_state[k] == 1) {
                return 0;
            }
        }
    }
    return has_target;
}

void get_next_state(int next_state[], int current_state[], int subset[], int mainset_ref[], int num_main, int num_items) {
    for (int k = 0; k < num_main; k++) {
        next_state[k] = current_state[k];
    }
    for (int j = 0; j < num_items; j++) {
        int val = subset[j];
        if (val == -1 || val == 0) break;
        for (int k = 0; k < num_main; k++) {
            if (mainset_ref[k] == val) next_state[k] = 1;
        }
    }
}

#endif