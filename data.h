#include <stdio.h>
#include <stdlib.h>

#define mainset_count 5             //how many elements in main set
#define subset_count 6              //how many subsets we have
#define item_count 5                //how many items in each subset

//SAMPLE  DATA
//EDIT NALANG TO TEST DIFFERENT CASES
int mainset[mainset_count] = {1, 2, 3, 4, 5};
int subsets[subset_count][item_count] = {
    {1, 2},
    {3, 4},
    {1},
    {2, 3},
    {4, 5},
    {5}
};