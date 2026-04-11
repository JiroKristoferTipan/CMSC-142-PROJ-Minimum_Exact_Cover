#include "bruteforce.h"
#include "dynamic.h"
#include <time.h>


int main() {   
    int time_bruteforce, time_dynamic; 

    //GET TIME FOR BRUTE FORCE
    time_bruteforce = clock();
    brute_force_search();
    time_bruteforce = clock() - time_bruteforce;
    printf("Time taken (brute force): %f seconds\n", ((double)time_bruteforce) / CLOCKS_PER_SEC);

    //GET TIME FOR DYNAMIC PROGRAMMING
    time_dynamic = clock();
    dynamic_search();
    time_dynamic = clock() - time_dynamic;
    printf("Time taken (dynamic programming): %f seconds\n", ((double)time_dynamic) / CLOCKS_PER_SEC);

    return 0;
}
