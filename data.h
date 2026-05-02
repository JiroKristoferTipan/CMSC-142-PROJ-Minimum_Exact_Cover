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

int is_same_state(int s1[], int s2[], int n) {
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) return 0;
    }
    return 1;
}

//1 if pwede isama yung subset sa sol, 0 if no
int is_valid_subset(int subset[], int current_state[], int mainset[], int num_main, int num_items, int target_value) {
    int has_target = 0;
    //get a subset that we can use
    for (int j = 0; j < num_items; j++) {
        int val = subset[j];
        if (val == -1) break;

        if (val == target_value) has_target = 1;

        //check if may overlap
        for (int k = 0; k < num_main; k++) {
            if (mainset[k] == val && current_state[k] == 1) {
                return 0;
            }
        }
    }
    return has_target;
}

//make next state for recursion
void get_next_state(int next_state[], int current_state[], int subset[], int mainset[], int num_main, int num_items) {
    //create new state by copying current one so far
    for (int k = 0; k < num_main; k++) {
        next_state[k] = current_state[k];
    }
    //mark the elements from the new subset as covered
    for (int j = 0; j < num_items; j++) {
        int val = subset[j];
        if (val == -1) break;
        for (int k = 0; k < num_main; k++) {
            if (mainset[k] == val) next_state[k] = 1;
        }
    }
}

#endif