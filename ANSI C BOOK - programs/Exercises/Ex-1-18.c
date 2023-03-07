/*
Exercise 1-18. Write a program to remove trailing (blanks and tabs) from each line of
input, and to delete entirely blank lines.
*/
//note we don't need to store all the lines, we just need to throw them to the output!
#include <stdio.h>

#define CTRL(x) (x & 0x1F)
#define MAXLINE 1000

int getLine(char string[]);
int processedInputLine(char string[], int length);
int main()
{
    char string[MAXLINE]; // the string was overwritten
    int len = 0;
    while ((len = getLine(string)) > 0)
    {
        if (processedInputLine(string, len) > 0)
            printf("%s", string);
    }
}

int getLine(char string[])
{
    int iter = 0;
    int chr = 0;
    for ( iter = 0; ( (iter < MAXLINE) && ( (chr = getchar()) != '\n' ) && chr != EOF ) ; ++iter )// iteration variable increment stt.
    {
        string[iter] = chr;
    }
    if(chr == '\n')
    {
        string[iter] = '\n';
        ++iter;
    }
    string[iter] = '\0';
    return iter; // count of the characters that was read!]
}

int processedInputLine(char string[], int length)
{
    int i;
    char flag = 1;
    for (i = length-1; flag != 0; --i) //previously I had put i=length and missed a crucial case:
    // string[i] became the character after the NULL character! as the for loop , incremented the length by 1
    //before breaking out of the loop in the getLine() function!
    {
        if (string[i] != ' ' && string[i] != '\t' && string[i] != '\n')
        {
            ++i;
            string[i] = '\n';
            ++i;
            string[i] = '\0';
            flag = 0;
        }
    }
    return i;
}


/* this still fails some test cases like having a ' \t\t ' , '\t \t' => like so ...
int main()
{
    int flag = 1;
    while (flag > 0) //ignores the completely blank lines here
    {
        char string[MAXLINE]; // the string was overwritten
        // continuously for every input => resulting in overwriting of the same string!
        if (getLine(string) > 0)
        {
            printf("%s", string);
        }
        else
            flag = 0;
    }
}

int getLine(char string[])
{
    fflush(stdin);
    int chr = 0;
    int iter = 0;
    for (iter = 0; (iter < MAXLINE) && ((chr = getchar()) != '\n') && (chr != CTRL('d')); ++iter)
    {
        if (chr == ' ')
        {
            string[iter] = chr; // to get just one space
            while ((chr = getchar()) == ' ')
                ;//do nothing until a character other than ' ' is met with!
        }
        // if (chr != '\t')
        //     string[iter] = chr;
        //else ignore that character
        if (chr == '\t')
        {
            while ((chr = getchar()) == '\t')
                ;// do nothing if there are many tabs together
            --iter; // as iter will get updated in the for loop's head!
        }
        string[iter] = chr;
    }
    if (chr == '\n' || chr == CTRL('d'))
    {
        string[iter] = '\n';
        ++iter;
    }
    string[iter] = '\0';
    return iter; // count of the characters that was read!]
}
*/

/* initial => need to work more on the work
#include <stdio.h>
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