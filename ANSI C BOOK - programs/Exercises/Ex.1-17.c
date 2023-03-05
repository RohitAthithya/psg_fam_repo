/*Exercise 1-17. Write a program to print all input lines that are longer than 80 characters.*/

#include <stdio.h>
#define MAXLINE 1000 // maximum input line length is upto 80
#define LIMIT 80
#define CTRL(x)  (x & 0x1F)   

//function prototypes
int getLine(char line[], int limit); //this returns the length of the line that was read => to measure if it is >0

//Main: Print all the lines from the input, upto 80characters of input 
main()
{
    int length;
    char lines[MAXLINE];
    while((length = getLine(lines, MAXLINE)) > 0)
    {
        if (length > LIMIT)
            printf("%s", lines);
    }

    return 0;
}

// getline: read a line into s, return length 
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < (lim - 1) &&  (c = getchar()) != EOF  && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i ; //we are just going to return 1 or 0 because here we check if length is >0 or not only!
}
