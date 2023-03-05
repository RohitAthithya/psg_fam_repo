//dated: 18-02-2022
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
#include <stdint.h>
#define CTRL(x) (x & 0x1f)


int main(void)
{
    //varible declaration
    uint16_t c;
    int word_length = 0;
    uint8_t state = 0;

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
    }//result: array is populated : count of word length of the input from 1,2,...9, >= 10

    printf("\n\nThe count array is:\n");//some new lines

    for(register int i = 0; i<10; printf("%3d ",array[i]), ++i);//so the array is populated properly

    //find the max of the array
    int max = array[0];
    for(int i = 1 ; i < 10; ++i)
    {
        if(array[i] >= max)
        {
            max = array[i];
        }
    }
    printf("\nmax of the array is : %3d\n\n",max); //the max of the array is working properly
    int temp_max = max;
    //print the histogram in vertical format
    for(register uint8_t i = 0; i < 50; putchar('='),++i);
    printf("\nThe Vertical Histogram is :\n");
    for(register volatile int i = max; i > 0; --i)
    {
        putchar('\t');
        for(int j = 0; j < 10; ++j)
        {
            if(array[j] == temp_max)
            {
                putchar('*');
                --*(array+j);
            }
            else
                putchar(' ');
            
            putchar(' ');
        }
        --temp_max;
        putchar('\n');
    }

    //print numbers for reference of the word_length count
    printf("\t");
    for(register int i = 1; i <= 9; ++i)
        printf("%1d ",i);  
    //to print ">10"
    printf(">10");

    return 0;
}

//completed on 02 - 03 - 2022 (yep! i took some time off lol!)


