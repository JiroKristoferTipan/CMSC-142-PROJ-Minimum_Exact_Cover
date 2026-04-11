#ifndef DATA_H
#define DATA_H

#define mainset_count 5             //how many elements in main set
#define subset_count 6              //how many subsets we have
#define item_count 5                //how many items in each subset

//SAMPLE  DATA
//EDIT NALANG TO TEST DIFFERENT CASES
static int mainset[mainset_count] = {1, 2, 3, 5, 8};
static int subsets[subset_count][item_count] = {
    {1, 2},
    {3, 5},
    {1},
    {2, 3},
    {5, 8},
    {8}
};

#endif