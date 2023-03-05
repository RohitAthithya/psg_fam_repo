/*prblm. stt.
Write a program that prints its input one word per line
*/
/*Soln.:
    when the character is inside the word we can print the word, else if we are outside the word
    say like blankspace or tabspace or newline then print a newline and also skip successive blanks 
    or tabspaces or newlines until a new ord is met

    this code is a combination of the word counting and the previous code of replaces the white spaces with one blank space!
*/
/* code to be reused:
main()
{
    int c;
    int space_count = 0;
    while (c = getchar())
    {   
        if(c == ' ')
        {
            if (space_count == 0)
            {
                putchar(' ');
                space_count++;
            }
        }
        if(c != ' ')//just try commenting this if condition and not the body
        {
            space_count = 0;
            putchar(c);
        }
    }    
}
*/
/*new concepts that we can use:
    -logical AND and OR in expressions
    -if else construct and also if-else-if constructs => chaining of if and else stt.
*/
//I will keep the most optimised that i consider to be here in the main function

#include<stdio.h>
#define CTRL(x)  ( x & 0x1f ) 

#define OUT 0
#define IN 1

main()
{
    int c;
    while((c = getchar()) != EOF && c != CTRL('d'))
    {
        if(c == ' ' || c == '\t' || c == '\n' || c == '-')
        {
            putchar('\n');
            while((c = getchar()) == ' ' || c == '\t' || c == '\n' || c == '-'); //EMPTY LOOP - basically we skip any stt. if 
            //we meet same characters again
        }
        putchar(c);//this saves us from losing a character! //just think of what would happen if we get input in while loop again
        //and not process it, we may loose a character
    }
}

//OTHER SOLUTIONS:
/*method 2:
int c;
    int state;
    int white_space_count = 0;
    while((c = getchar()) != EOF && c != CTRL('d'))
    {
        state = IN;
        if(c == ' ' || c == '\n' || c == '\t') //any of the whitespaces
        {
            //count for the number of whitespaces
            //if more than one, go to next line and wait till new word is met
            white_space_count++;
            state = OUT;
        }
        else
        {
            white_space_count = 0;
            state = 1;
        }
        if(white_space_count == 1 )
        {
            putchar('\n');
            //just for precaution
            state = OUT;
        }
        
        if(state == IN)//only if state == IN => print characters
            putchar(c);
    }

        //the above is the working piece of code
        
        /*version 1 of my code:
        state = IN;
        if(c == ' ' || c == '\n' || c == '\t') //any of the whitespaces
        {
            //count for the number of whitespaces
            //if more than one, go to next line and wait till new word is met
            white_space_count++;
            state = OUT;
        }

        if(white_space_count == 1 )
        {
            putchar('\n');
            //just for precaution
            state = OUT;
        }
        
        if(state == IN)
            putchar(c);
        //only if state == IN => print characters
        *//*
*/


