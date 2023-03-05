/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of
 input, and to delete entirely blank lines.*/

#include <stdio.h>

#define CTRL(x) (x & 0x1F)
#define MAXLINE 1000

int getLine(char str[]);
int main()
{
    char string[MAXLINE];
    while (getLine(string) > 0)
    {
        printf("%s", string);
    }
}

int getLine(char string[])
{
    int chr = 0, i;
    // chr = getchar();
    for (i = 0; (i < MAXLINE) && (chr = getchar()) != '\n' && chr != CTRL('d'); ++i)
    {
        string[i] = chr;
        // if tabspace - do nothing
    }
    if (chr == '\n' || chr == CTRL('d'))
    {
        string[i] = '\n';
        ++i;
    }
    string[i] = '\0';

    return i; // count of the characters that was read!
}

/* #include <stdio.h>
#include <stdint.h>
#define CTRL(x)  (x & 0x1F)
#define MAXLINE 1000

int getLine(char s[], int lim);
int removeTrailSpaces(char input[]);

main()
{
    int length;
    char line[MAXLINE];

    while((length = getLine(line,MAXLINE)) > 0)
    {
        if(removeTrailSpaces(line) > 0)
            printf("%s\n", line);
    }


    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < (lim - 1) &&  (c = getchar()) != CTRL('d') ; ++i) //i have removed the newline char
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';//here the input string is read and then store, with last character as NULL char!
    return i; //we are just going to return 1 or 0 because here we check if length is >0 or not only!
}

int removeTrailSpaces(char input[])
{
    int i;
    int spaces_removed;
    //traverse to the end of the input line
    for(i = 0; input[i] != '\0'; ++i)
        ;

    //i is placed at null position
    //now we have to traverse in the reverse manner to ignore all the spaces until we meet a character
    for( spaces_removed = 0; (input[i] == ' ') || (input[i] == '\t') ; ++spaces_removed, --i)
        ;

    //i i now placed at the string's last character's positon
    input[i + 1] = '\0';// if at all we pass the string to the printf, then it shall read until this NULL character

    printf(" number of spaces removed are = %d and i = %d\n", spaces_removed, i);
    return i;
} */