int solve_brute(int current_state[], int num_main, int num_subsets, int num_items, int mainset[], int subsets[num_subsets][num_items]) {
    //current_state- array where 1 means elements exists and 0 doesnt, for checking which elements are covered
    //num_main- ilan elements sa mainset meron
    //num_subsets- ilan subsets meron
    //num_items- ilan items meron in each subset
    //mainset- array of the main set
    //subsets- array of all subsets

    //check if we did everything
    int total_covered = 0;
    for (int i = 0; i < num_main; i++) {
        total_covered += current_state[i];
    }
    
    if (total_covered == num_main) {
        return 0; // finished solve_brute
    }

    //find next thing to cover
    int target_index = -1;
    for (int i = 0; i < num_main; i++) {
        if (current_state[i] == 0) {
            target_index = i;
            break;
        }
    }
    int target_value = mainset[target_index];
    int best_count = 9999;

    //try every subset to find what to add next
    for (int i = 0; i < num_subsets; i++) {
        int has_element = 0;
        int has_overlap = 0;
        for (int j = 0; j < num_main; j++) {
            int val = subsets[i][j];
            //check if it has what were looking for
            if (val == target_value) {
                has_element = 1;
            }

            //find overlaps
            for (int k = 0; k < num_main; k++) {
                if (mainset[k] == val && current_state[k] == 1) {
                    has_overlap = 1;
                    break;
                }
            }
        }
        //cannot use this iteration
        if (has_overlap) break;

        //if element can be used)
        if (has_element && !has_overlap) {
            //update which one is added and run again to find next one to add
            int next_state[num_main];
            for (int j = 0; j < num_main; j++) {
                next_state[j] = current_state[j];
            }
            //mark the elements in the subset as covered
            for (int j = 0; j < num_items; j++) {
                int val = subsets[i][j];
                for (int k = 0; k < num_main; k++) {
                    if (mainset[k] == val) next_state[k] = 1;
                }
            }

            int current = 1 + solve_brute(next_state, num_main, num_subsets, num_items, mainset, subsets);
            if (current < best_count) {
                best_count = current;
            }
        }
    }
    return best_count;
}