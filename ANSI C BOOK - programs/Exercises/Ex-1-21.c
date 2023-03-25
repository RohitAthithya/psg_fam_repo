/**
 * Exercise 1-21.
 * Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
*/

#include <stdio.h>

#define MAXLINE 1000
#define TABWIDTH 4
main()
{
    int chr;
    int blank = 0;
    while (((chr = getchar()) != EOF) && ( TABWIDTH != 0))
    {
        if (' ' == chr)
        {
            ++blank;
        }
        else
        {
            while(blank > 0)
            {
                if ((blank >= TABWIDTH))
                {
                    putchar('\t');
                    blank = blank - TABWIDTH;
                }
                else
                {
                    putchar(' ');
                    blank = blank - 1;
                }
            }
            putchar(chr);
        }
    }
}



