/*Exercise 1-14. Write a program to print a histogram of the frequencies of different characters in its input.*/

#include <stdio.h>
#define CTRL(x) (x & 0x1f)
#define IN 1
#define OUT 0

main()
{
    int c;
    int word_length = 0;
    int state = 0;
    int array[27] = {0}; //to store frequencies of 26 characters and then non-character chars like space, tab space, newline, etc..
    //fflush();
    while((c = getchar()) != EOF && c != CTRL('d'))
    {
        if(c >= 'A' && c <= 'Z')
            c = 'a' + 26 - ('Z' - c);

        if(c >= 'a' && c <= 'z')
            array[(c - 'a')]++;

        if(c == ' ' || c == '\t' || c == '\n' || c == '-')
            array[26]++;
        
    }
/* Print the Contents of the array that has the count of characters it has!
    for(int i = 0; i < 27; printf("%d  ", array[i]), ++i);//fflush();
    putchar('\n');
    for(int i = 0; i < 27; printf("%c  ", 'a' + i), ++i);//fflush();
    putchar('\n');
*/
    
// Print the Horizontal Histogram
    for(int i = 0; i < 27; ++i)
    {
       // printf("%d  ", array[i]);//check the fullness of the array // it works fine with this piece of code
        //putchar(i);
        printf("\t%c: ", i+1);

        for(int j = 0; j < array[i]; ++j)
        {
            putchar('*');
        }

        putchar('\n');
    }

}//end of main()
