/*Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank.*/
//NICE CODE TO LOOK FOR THE : read until new line character

#include <stdio.h>
#include<stdlib.h>

//i/p : aaaa    a   a a        aaaaaaaa    aaaaaaaaaaaaaaaaaaaaaaaaa                    aaaaaaa     a
main()
{
    /*
    char str[100];
    char mod_str[100]; //it was said to copy from i/p to o/p!
    printf("Enter the sentence:\n");
    scanf("%[^\n]", str);
    */
   /*
    // oru % ah maranthuttu ! yebbaaa!!
    //actually i wanted to check if the read sentence contains a \0 token at the end of the "string"
    /*
    for (int i = 0; ;++i)
    if(str[i] == '\0')
    {
        printf("found at %d", i);
        break;
    };
    printf("\n%s", str);
    */
   //of course this works in our case
    //finite state machine model!
    //read input - check if i/p is ' ' - if yes check count of ' ' previously read - 
    //if >= 1 - read i/p again - if 0 then print ' ' and go to read i/p
    int c;
    int space_count = 0;
    while (c = getchar())
    {   
        if(c == ' ')
        {
            //if(space_count >= 1) //try commenting this if block alone
            //    continue;
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
