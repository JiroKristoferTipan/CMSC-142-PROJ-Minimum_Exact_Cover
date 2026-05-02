#ifndef DATA_H
#define DATA_H
#include <stdio.h>

//SAMPLE DATA
//EDIT NALANG TO TEST DIFFERENT CASES
/*
#define mainset_count 5             //how many elements in main set
#define subset_count 6              //how many subsets we have
#define item_count 5                //how many items in each subset
static int mainset[mainset_count] = {1, 2, 3, 5, 8};
static int subsets[subset_count][item_count] = {
    // -1 means end of subset
    // so basically puro 1-3 members per subset dito
    // bobo lang ako magcode kaya need nila pareparehas lahat ng length
    {1, 2, -1, 0, 0},
    {3, 5, -1, 0, 0},
    {1, -1, 0, 0, 0},
    {2, 1, 8, -1, 0},
    {5, 8, -1, 0, 0},
    {8, -1, 0, 0, 0}
};
*/

#define mainset_count 20            
#define subset_count 18             
#define item_count 15               

// A larger main set to increase the number of possible "states"
static int mainset[mainset_count] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

static int subsets[subset_count][item_count] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -1, 0, 0, 0, 0},
    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, -1, 0, 0, 0, 0},
    
    {1, 2, 3, 4, 5, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {6, 7, 8, 9, 10, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {11, 12, 13, 14, 15, -1, 0, 0, 0, 0, 0, 0, 0, 0},
    {16, 17, 18, 19, 20, -1, 0, 0, 0, 0, 0, 0, 0, 0},

    {1, 6, 11, 16, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 7, 12, 17, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {3, 8, 13, 18, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {4, 9, 14, 19, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {5, 10, 15, 20, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},

    {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, -1, 0, 0, 0, 0}, 
    {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, -1, 0, 0, 0, 0},
    {1, 2, 11, 12, 3, 4, 13, 14, 5, 6, 15, 16, -1, 0, 0},
    
    {5, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {10, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {15, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {20, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void print_sol(int result, int *state, int run_count) {
    if (result == 9999) {
        printf("No solution found.\n");
    } else {
        printf("Minimum Subsets Needed: %d\n", result);
        
        int count = 0;
        for (int i = 0; i < result; i++) {
            //get the subset index from our result array
            int subset_idx = state[i]; 
            
            printf("Subset %d contains: ", subset_idx);
            for (int j = 0; j < item_count; j++) {
                //stop printing if nasa dulo
                if (subsets[subset_idx][j] == -1) break;
                printf("%d ", subsets[subset_idx][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("The function was run %d times to find the solution.\n", run_count);
}

#endif