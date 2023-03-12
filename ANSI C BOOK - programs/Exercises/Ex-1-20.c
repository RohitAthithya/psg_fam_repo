/**
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
*/


/* !    My Solution     !*/
#include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];
char detab_line[MAXLINE];

int getLine(void);
void detab(void);

main()
{
    int length;
    extern char line[MAXLINE];
    //execute once to update the length variable
    while((length = getLine()) > 0)
    {
        printf("Before detab:\n%s\n", line);
        detab();
        printf("After detab:\n%s\n", detab_line);
    }
}

int getLine(void)
{
    extern char line[MAXLINE]; //REDUNDANT but doing it for practice
    int ltr;
    int iter;
    for(iter = 0; ((iter<MAXLINE)&&((ltr = getchar()) != '\n')&&(ltr != EOF)); ++iter)
    {
        line[iter] = ltr;
    }
    if('\n' == ltr)
    {
        line[iter] = '\n';
        ++iter;
    }
    line[iter] = '\0';

    return iter;
}

void detab(void)
{
    extern char line[MAXLINE];
    extern char detab_line[MAXLINE];

    int ltr;
    int idx = 0;
    int other_idx = 0;
    for( idx = 0;(((ltr = line[idx]) != '\n') && (ltr != EOF)); ++idx )
    {
        if( '\t' == ltr )
        {
            int temp = 0;
            while (temp < 4)
            {
                detab_line[other_idx] = ' ';
                ++temp;
                ++other_idx;
            }
        }
        else
        {
            detab_line[other_idx] = line[idx];
            ++other_idx;
        }
    }
}