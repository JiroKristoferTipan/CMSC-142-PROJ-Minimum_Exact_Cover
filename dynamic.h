int solve_dynamic(){
    /*
    (CHECK LINE 68 SA BRUTEFORCE.H PARA MAKITA YUNG RECURSION PART)

    similar implementtaion sa brute force pero sa part
    na magrecusion, need macheck if yung hahanapin ay solved previously
    need ng parang isang array na nag kekeeptrack if nasolve na ba ito
    instead of doing recursion again, gagamitin nalang nila yung nasave na solution
    
    example:
    current state ay {1,1,0,0,1,0}
    so need mo pa hanapin yung 3rd, 4th and 6th element 

    lets say na may mga nasave ka na ganito:
    {1, 1,1,1,0,1,1},
    {2, 1,1,1,0,1,0},
    {2, 1,1,0,0,1,0},
    
    yung 1st index ay kung ilang subsets ginamit, then the rest is ano yung state that the subsets solved
    so based sa current state na need isolve, 2 yung sagot


    tldr: need ng memory para malaman ano na yung solved and di na uulitin recursion
    */
}