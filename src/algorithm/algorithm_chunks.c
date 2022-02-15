/**

ok lets write

i have a stack of a give number of ints

i will go chunk by chunk so i only have to worry about it being 
lower than or equal to the given border.

So i will go smallest by smallest chunk


now how do i push the items to stack?

i can combine the two 

so i find the number that takes the least number of moves to take to the top of stack a
then i push it.

so i do that for the first three without caring about the order i push them, i just push them 

then i sort them in reverse order 

Then for the first chunk i follow the previous algorithm i had but i add the extra condition that
it has to be smaller or equal to the border. 

-----------------------------------------------------------------------------------------------------

Ok so to find the number that takes the least number of moves.
I find the number closest to the top that is inside of chunk one 
then i find the number closet to the bottom 


ok lets do two or one function that does this 

Done

sent the first three number to stack b and reverse ordered them 

Now i have to do the rest of the numbers inside the chunk

How?
what will be the loop condition 
    -check the stack and see if there are still any numbers of the given chunk
    -loop the size of the chunk, this might be the fastest way

    ok the function that does the first chunk is done

    now what i have is the first chunk in descending order in stack b

    Every number that will be pushed now should be bigger than every number in stack b

    so the first number will be bigger necessarily bigger than than x, no need to even check the 
    
    Ok so far what i have is two algorithms

    the first one and the second are like this

    First one

    First three chosen numbers are push and ordered.

    Then

    -Check is the next number is bigger than all the numbers in stack b
        rotate the number in stacka until it is at the top of the stacka
        pushb
    -Check if the next number is smaller than all the numbers in stackb
        rotate the number in stacka until it is at the top of stacka
        pushb
        ->one possible optimization is to then at that moment check for the next chosen number
            ->and see if it is bigger than stackb->x and smaller than stackb->y
            if it is bigger
                pb
                rb
        rb
    -The number is an intermediate number
        -Check if it is bigger than midpoint
            -rotate the number in stacka until it is at the top of stacka
            -(rb * distance)
            -pb
            -OPTIMIZATION:
                -before the first rrb find the next chosen number
                    if (new.num > x && new.num < y)
                        pb
            -(rrb * distance)
                -OPTIMIZATION:
                    -After each rrb
                        find the next chosen number
                            if (new.num > x && new.num < y)
                                rotate number
                                pb
                            if not
                                go to next rrb
                
        -Check if it is smaller than midpoint
            -rotate the number in stack a until it is at the top of stacka
            -(rrb * distance)
            -pb
            -OPTIMIZATION:
                before the first rb find the next chosen number
                    if (new.num > x && new.num < y)
                        rotate
                        pb
            (rb * distance + 1)
            OPTIMIZATION:
                -After each rb
                    find the next chosen number
                        if (new.num > x && new.num < y)
                            rotate number
                            pb
                        if not
                            go to next rb



another take into the algorithm

-ok so my other idea for further optimization 

if it is an intermediate number
-I rotate stack a to get the number on top
-rb the given number of times so it is placed correctly
    optimization -> if next_hold  pb
    if not 
    optimization 2
        get next_hold (same as the next_hold of optimization1)
            see if it is 



**/