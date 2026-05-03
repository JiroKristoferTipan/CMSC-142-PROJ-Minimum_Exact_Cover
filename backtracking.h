#ifndef BACKTRACKING_H
#define BACKTRACKING_H
#include "data.h"

/*
current_state- array where 1 means elements exists and 0 doesnt, for checking which elements are covered
num_main- ilan elements sa mainset meron
num_subsets- ilan subsets meron
num_items- ilan items meron in each subset
mainset- array of the main set
subsets- array of all subsets
current_solution- indexes of which subsets r used in the solution
run_count- how many times we run the function (icocompare natin to with dynamic)
current_depth- how many subsets have been selected so far
global_best- the minimum number of subsets found so far
*/

int solve_backtracking(int current_state[], int num_main, int num_subsets, int num_items, int mainset[], int subsets[num_subsets][num_items], int current_solution[], int* run_count, int current_depth, int* global_best) {
    (*run_count)++;

    // Check if all elements are covered
    int total_covered = 0;
    for (int i = 0; i < num_main; i++) total_covered += current_state[i];
    if (total_covered == num_main) return 0; // Backtracking finished

    // If current path is already longer than best path found so far, dont bother with it
    if (current_depth >= *global_best) return 9999;

    // Find the next thing to cover
    int target_index = -1;
    for (int i = 0; i < num_main; i++) {
        if (current_state[i] == 0) {
            target_index = i;
            break;
        }
    }
    int target_value = mainset[target_index];
    int best_count = 9999;
    int temp_solution[num_subsets];

    // Loop through all subsets to find one that covers the target element
    for (int i = 0; i < num_subsets; i++) {
        // Check if the current subset is valid
        if (is_valid_subset(subsets[i], current_state, mainset, num_main, num_items, target_value)) {
            // Create the next state
            int next_state[num_main];
            get_next_state(next_state, current_state, subsets[i], mainset, num_main, num_items);

            // Recursively call backtracking for the next state
            int res = solve_backtracking(next_state, num_main, num_subsets, num_items, mainset, subsets, temp_solution, run_count, current_depth + 1, global_best);

            // Check if a solution was found
            if (res != 9999) {
                if (1 + res < best_count) {
                    best_count = 1 + res;

                    // Store the current subset
                    current_solution[0] = i;
                    // Copy the rest of the subsets
                    for (int p = 0; p < res; p++) {
                        current_solution[p + 1] = temp_solution[p];
                    }

                    // Update global best if current path is better
                    if (current_depth + best_count < *global_best) {
                        *global_best = current_depth + best_count;
                    }
                }
            }
        }
    }

    return best_count;
}

#endif