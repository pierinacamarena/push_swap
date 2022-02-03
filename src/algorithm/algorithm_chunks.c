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





**/