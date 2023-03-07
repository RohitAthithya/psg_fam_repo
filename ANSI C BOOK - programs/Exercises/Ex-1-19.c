/**
 * Ex-1-19
 * Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverses its input a line at a time.
*/

#include<stdio.h>
#define MAXLINE 1000


void reverse(char s[], int length); //reverses the original string itself!
int getLine(char string[]);
main()
{
    char string[MAXLINE];
    int length = 0;
    while ((length = getLine(string)) > 0)
    {
        reverse(string,length);
        printf("reversed string:\n%s", string);
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

void reverse(char string[], int length)
{
    //copy the string to temp string, and reverse overwrite the original string!
    //1. Create a temp string
    char temp_str[length];
    int i = 0;

    //2. Copy the original string to this temp string
    for (i = 0; string[i] != '\0'; ++i)
    {
        temp_str[i] = string[i];
    }
    temp_str[i] = '\0'; //last character needs to be NULL character
    --i; //now 'i' has the length of the string, though we can still use the length variable!

    //2.1 test print the temp string
    //printf("%s",temp_str);

    //3. reverse overwrite the original string!
    int chr_idx;
    for ( chr_idx = 0; i >= 0 ; ++chr_idx)
    {   //'i' has the last index!
        if (temp_str[i] == '\n')
            --i;
        string[chr_idx] = temp_str[i]; // 0th  = last
        --i;
    }
    string[chr_idx] = '\n';
    ++chr_idx;
    string[chr_idx] = '\0';


    //3.1 test print the reversed string here:
    //printf("reversed string:\n%s", string);
    return;
}