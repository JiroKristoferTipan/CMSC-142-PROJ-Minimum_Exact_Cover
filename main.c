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
    int bruteforce_selected[mainset_count], bruteforce_state[subset_count], dynamic_selected[mainset_count], dynamic_state[subset_count] = {0};


    //GET TIME FOR BRUTE FORCE
    time_bruteforce = clock();
    result_brute = solve_brute(bruteforce_selected, mainset_count, subset_count, item_count, mainset, subsets, bruteforce_state);
    time_bruteforce = clock() - time_bruteforce;
    printf("Time taken (brute force): %f seconds\n", ((double)time_bruteforce) / CLOCKS_PER_SEC);
    print_sol(result_brute, bruteforce_state);

    //GET TIME FOR DYNAMIC PROGRAMMING
    time_dynamic = clock();
    result_dynamic = solve_dynamic(dynamic_state, mainset_count, subset_count, item_count, mainset, subsets, dynamic_selected);
    time_dynamic = clock() - time_dynamic;
    printf("Time taken (dynamic programming): %f seconds\n", ((double)time_dynamic) / CLOCKS_PER_SEC);
    // print_sol(result_dynamic, dynamic_state);

    return 0;
}
