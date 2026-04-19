#ifndef DATA_H
#define DATA_H

//SAMPLE DATA
//EDIT NALANG TO TEST DIFFERENT CASES
#define mainset_count 5             //how many elements in main set
#define subset_count 6              //how many subsets we have
#define item_count 5                //how many items in each subset
static int mainset[mainset_count] = {1, 2, 3, 5, 8};
static int subsets[subset_count][item_count] = {
    {1, 2, -1, 0, 0},
    {3, 5, -1, 0, 0},
    {1, -1, 0, 0, 0},
    {2, 1, 8, -1, 0},
    {5, 8, -1, 0, 0},
    {8, -1, 0, 0, 0}
};

void print_sol(int result, int *state) {
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
}

#endif