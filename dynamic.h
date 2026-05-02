#ifndef DYNAMIC_H
#define DYNAMIC_H
#include "data.h"
#include <stdlib.h>

/*
current_state- array where 1 means elements exists and 0 doesnt, for checking which elements are covered
num_main- ilan elements sa mainset meron
num_subsets- ilan subsets meron
num_items- ilan items meron in each subset
mainset- array of the main set
subsets- array of all subsets
current_solution- indexes of which subsets r used in the solution
run_count- how many times we run the function (icocompare natin to with dynamic)
memory_state- 2D array to store states already solved
memory_result- result found in memory_state
states_recorded- number that just says how much we have in memory
max_memo_size- maximum number of states we can store
*/

int solve_dynamic(
    int current_state[], int num_main, int num_subsets, int num_items, int mainset[], int subsets[num_subsets][num_items], int current_solution[], int* run_count, int memory_state[][num_main], int memory_result[], int* states_recorded, int max_memo_size
) {
    (*run_count)++;

    //check if we did everything
    int total_covered = 0;
    for (int i = 0; i < num_main; i++) total_covered += current_state[i];
    if (total_covered == num_main) return 0; //finished solve_dynamic

    //check is solved before                                            //ETO YUNG BAGO SA DYNAMIC
    for (int i = 0; i < *states_recorded; i++) {
        if (is_same_state(current_state, memory_state[i], num_main)) {
            return memory_result[i];
        }
    }

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
    int temp_sol[num_subsets]; // Temporary storage for recursion

    //try every subset to find what to add next
    for (int i = 0; i < num_subsets; i++) {
        // We modularized the messy loops here:
        if (is_valid_subset(subsets[i], current_state, mainset, num_main, num_items, target_value)) {
            //create new state by copying current one so far
            int next_state[num_main];
            get_next_state(next_state, current_state, subsets[i], mainset, num_main, num_items);

            //get another subset to use, and so on until we reach exact cover (yung return 0 sa pinaka top)
            //or if we reach a no solution (best_count is still 9999 and is returned)
            int res = solve_dynamic(next_state, num_main, num_subsets, num_items, mainset, subsets, temp_sol, run_count, memory_state, memory_result, states_recorded, max_memo_size);

            //check if a sol was found
            if (res != 9999) {
                if (1 + res < best_count) {
                    best_count = 1 + res;
                    
                    //store current subset first
                    current_solution[0] = i;
                    //copy the rest of the subsets
                    for (int p = 0; p < res; p++) {
                        current_solution[p + 1] = temp_sol[p];
                    }
                }
            }
        }
    }
    //store in memory that we solved this na                            //ETO RIN YUNG BAGO SA DYNAMIC
    //check if hindi overflow yung memory
    if (*states_recorded < max_memo_size) {
        for (int k = 0; k < num_main; k++) {
            //store the state in memory
            memory_state[*states_recorded][k] = current_state[k];
        }
        //store the result in memory
        memory_result[*states_recorded] = best_count;
        (*states_recorded)++;
    } else {
        //death sentence
        printf("Memory limit exceeded in dynamic programming.\n");
        exit(1);
    }

    return best_count;
}

#endif