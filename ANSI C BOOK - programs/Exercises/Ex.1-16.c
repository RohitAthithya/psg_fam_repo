/*Exercise 1-16. Revise the main routine of the 
longest-line program so it will correctly print the length of arbitrary long input lines, 
and as much as possible of the text.

- basically we must readthe input and print it
- but if there is >MAXLINE characters => we print till MAXLINE no. of characters
and print the actual length of the string , atleast unto the max_countable length! 
*/


#include <stdio.h>
#define MAXLINE 40/* maximum input line length */
#define CTRL(X)  (X & 0X1F)   

//function prototypes
int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max) 
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("%s", longest);

    printf("\nAnd the length of the actual string input was : %d", max);
    return 0;
}//end of main


/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;
    for (i = 0; i < (lim - 1) && ( (c = getchar()) != EOF ) && c != CTRL('d') && c != '\n'; ++i)
    {
        s[i] = c;
    }

    //here the MAXLINE characters were read and to be printed but the actuall countable length alone is returned
    if(i >= (lim - 1))
    {
        s[i] = '\0';
        
        if ((c = getchar()) != EOF || c != '\n') 
        {
            for( ; i <= __UINT32_MAX__ && (c = getchar()) != EOF && c != CTRL('d') && c != '\n'; )
                ++i;
        }
    }

    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
    
}
