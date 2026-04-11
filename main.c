#include "bruteforce.h"
#include "dynamic.h"
#include "data.h"
#include <stdio.h>
#include <time.h>


int main() {   
    int time_bruteforce, time_dynamic, result_brute, result_dynamic; 
    int bruteforce_state[mainset_count], dynamic_state[mainset_count];


    //GET TIME FOR BRUTE FORCE
    time_bruteforce = clock();
    result_brute = solve_brute(bruteforce_state, mainset_count, subset_count, item_count, mainset, subsets);
    time_bruteforce = clock() - time_bruteforce;
    printf("Time taken (brute force): %f seconds\n", ((double)time_bruteforce) / CLOCKS_PER_SEC);

    //GET TIME FOR DYNAMIC PROGRAMMING
    time_dynamic = clock();
    result_dynamic = solve_dynamic(dynamic_state, mainset_count, subset_count, item_count, mainset, subsets);
    time_dynamic = clock() - time_dynamic;
    printf("Time taken (dynamic programming): %f seconds\n", ((double)time_dynamic) / CLOCKS_PER_SEC);

    return 0;
}
