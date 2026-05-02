#include "bruteforce.h"
#include "dynamic.h"
#include "data.h"
#include <stdio.h>
#include <time.h>


int main() {
    /*
    time - ilan secs to run
    result - ilan subsets ginamit
    selected - checker lang, it should be all 1s if tama
    state - which subsets are selected, 1 if selected, 0 if not
    */
    int time_bruteforce, time_dynamic, result_brute, result_dynamic;
    int runcount_brute = 0, runcount_dynamic = 0; 
    int bruteforce_selected[mainset_count] = {0}, bruteforce_state[subset_count] = {0}, dynamic_selected[mainset_count] = {0}, dynamic_state[subset_count] = {0};

    int max_memo = 5000;
    int memo_states[5000][mainset_count]; // num_main must be known or use a fixed size
    int memo_results[5000];
    int states_recorded = 0;
    int run_count = 0;

    //GET TIME FOR BRUTE FORCE
    time_bruteforce = clock();
    result_brute = solve_brute(bruteforce_selected, mainset_count, subset_count, item_count, mainset, subsets, bruteforce_state, &runcount_brute);
    time_bruteforce = clock() - time_bruteforce;
    printf("Time taken (brute force): %f seconds\n", ((double)time_bruteforce) / CLOCKS_PER_SEC);
    print_sol(result_brute, bruteforce_state, runcount_brute);

    printf("\n--------------------------------------------------\n\n");
    
    //GET TIME FOR DYNAMIC PROGRAMMING
    time_dynamic = clock();
    result_dynamic = solve_dynamic(dynamic_selected, mainset_count, subset_count, item_count, mainset, subsets, dynamic_state, &runcount_dynamic, memo_states, memo_results, &states_recorded, max_memo);
    time_dynamic = clock() - time_dynamic;
    printf("Time taken (dynamic programming): %f seconds\n", ((double)time_dynamic) / CLOCKS_PER_SEC);
    print_sol(result_dynamic, dynamic_state, runcount_dynamic);

    return 0;
}
