//dated: 13-02-2022
/*Pblm. stt.
Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; 
//a vertical orientation is more challenging
*/
/*soln.:
get the input and count the length of the words 
then print the values in horizontal method
*/
/*new concepts that we can use:
arrays using subscript notation
*/

#include <stdio.h>
#define CTRL(x) (x & 0x1f)
#define IN 1
#define OUT 0

main()
{
    //varible declaration
    int c;
    int word_length = 0;
    int state = 0;

    int array[10] = {0};
    /*instead of initialising the members of the array as 0 with a loop
    I use this representation that automatically assigns all the members as 0
    or if we delcare the array in the global scope then also the automatic assignment 0 occurs
    */
   //for(int i = 0; i < 10; ++i) printf("%d  ", array[i]);//check here


    //decision part of program
    while((c = getchar()) != EOF && c != CTRL('d'))
    {
        if(c == ' ' || c == '\t' || c == '\n' || c == '-')
        {
            if(word_length <= 10)
                array[word_length - 1] = array[word_length - 1] + 1;
            else
                array[9] = array[9] + 1;
            //printf("\ninside array:%d", array[word_length]);
            word_length = 0;
            
        }
        else
        {
            word_length++;
            //printf("%d  ", word_length);
        }
    }

    for(int i = 0; i < 10; ++i)
    {
       // printf("%d  ", array[i]);//check the fullness of the array // it works fine with this piece of code
        //putchar(i);
        if(i == 9)
            printf("\t>%d: ", i+1);
        else
            printf("\t%d: ", i+1);

        for(int j = 0; j < array[i]; ++j)
        {
            putchar('*');
        }

        putchar('\n');
        
    }

}
