#include "bruteforce.h"
#include "dynamic.h"
#include "data.h"
#include <stdio.h>
#include <time.h>
#define MAX_MEMORY 5000

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

    //memory stuff ng dynamic, change stuff here if needed (pati rin MAX_MEMORY)
    int memo_states[MAX_MEMORY][mainset_count];
    int memo_results[MAX_MEMORY];
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
    result_dynamic = solve_dynamic(dynamic_selected, mainset_count, subset_count, item_count, mainset, subsets, dynamic_state, &runcount_dynamic, memo_states, memo_results, &states_recorded, MAX_MEMORY);
    time_dynamic = clock() - time_dynamic;
    printf("Time taken (dynamic programming): %f seconds\n", ((double)time_dynamic) / CLOCKS_PER_SEC);
    print_sol(result_dynamic, dynamic_state, runcount_dynamic);

    return 0;
}
