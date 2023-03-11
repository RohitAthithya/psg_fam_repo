/**
 * Program to store the longest line from the input
 * char longest[] => stores the longest line!
 *
 * This program is given in the ANSI C Book - uses global variables and
 * explicit declaration of using external (global) variables
 * using the extern keyword:
 *
 * We know that local variables are defined with their return type
 * and declared to be AUTOMATIC variables
 *
 * NOTE: the difference between DEFINE and DECLARE
 *
 * ---------------this topic is to be discussed further in the Storage class chapter 4
*/
#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

/*Global variables definition*/
int max; /* maximum length seen so far */
char line[MAXLINE]; /* current input line */
char longest[MAXLINE]; /* longest line saved here */

/*Function declaration*/
int getline(void);
void copy(void);

/* print longest input line; specialized version */
main()
{
    int len;
    extern int max; /*DECALRATION that these variables are external (or) global variables!*/
    extern char longest[];
    max = 0;
    while ((len = getline()) > 0)   /* NOTE: how we don't use a curly brackets! */
        if (len > max)
        {
            max = len;
            copy();
        }
    if (max > 0) /* there was a line */
    printf("%s", longest);
    return 0;
}

/* getline: specialized version */
int getline(void)
{
    int c, i;
    extern char line[];

    for (i = 0; (i < MAXLINE-1)&& (c = getchar) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: specialized version */
void copy(void)
{
    int i;
    extern char line[], longest[]; /*NOTICE how the declaration of usage of multiple global varibale*/
    i = 0;

    while ((longest[i] = line[i]) != '\0') /*LOOK AT THIS: copying technique => chain assignment+conditional stt. within while loop!*/
        ++i;
}