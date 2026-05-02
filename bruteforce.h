#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H
#include "data.h"

/*
current_state- array where 1 means elements exists and 0 doesnt, for checking which elements are covered
num_main- ilan elements sa mainset meron
num_subsets- ilan subsets meron
num_items- ilan items meron in each subset
mainset- array of the main set
subsets- array of all subsets
current_solution- indexes of which subsets r used in the solution
runt_count- how many times we run the function (icocompare natin to with dynamic)
*/

int solve_brute(int current_state[], int num_main, int num_subsets, int num_items, int mainset[], int subsets[num_subsets][num_items], int current_solution[num_subsets], int* run_count) {

    (*run_count)++;

    //check if we did everything
    int total_covered = 0;
    for (int i = 0; i < num_main; i++) total_covered += current_state[i];
    if (total_covered == num_main) return 0; //finished solve_brute

    //find next thing to cover
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

    //try every subset to find what to add next
    for (int i = 0; i < num_subsets; i++) {
        // We modularized the messy loops here:
        if (is_valid_subset(subsets[i], current_state, mainset, num_main, num_items, target_value)) {
            //create new state by copying current one so far
            int next_state[num_main];
            get_next_state(next_state, current_state, subsets[i], mainset, num_main, num_items);

            //get another subset to use, and so on until we reach exact cover (yung return 0 sa pinaka top)
            //or if we reach a no solution (best_count is still 9999 and is returned)
            int current = solve_brute(next_state, num_main, num_subsets, num_items, mainset, subsets, temp_solution, run_count);

            //check if a sol was found
            if (current != 9999) {
                //check if better than current solution
                if (1 + current < best_count) {
                    best_count = 1 + current;
                    
                    //store current subset first
                    current_solution[0] = i; 
                    //copy the rest of the subsets
                    for (int p = 0; p < current; p++) {
                        current_solution[p + 1] = temp_solution[p];
                    }
                }
            }
        }
    }
    return best_count;
}

#endif