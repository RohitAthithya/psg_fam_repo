/**
 * Exercise 1.20 -
 *
 * Write a Program detab, which replaces tabs in the input with a proper
 * number of blanks to spaces
 *
 **/
/**
 * Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a vari,able or a symbolic parameter?
 */

/*
Seems like I have misunderstood the tabstops!
tabstops are something:


say for 4 tabstops:
tabstops look like this:
____|____|____|    (they stop at every 4 instances!)

_ represents where the input needs to go!

for 8 tabstops:
tabstops look like this:
________|________|________|    (they stop at every 8 instances!)

*/

#include <stdio.h>

#define TABSTOPLEN 4
#define MAXLINE 1000

char line[MAXLINE];
char detab_line[MAXLINE]; // no need to use these strings, just simple getchar and putchar!8676

int getLine(void);
void detab(void);

main()
{
    int length;
    while ((length = getLine()) > 0)
    {
        //printf("Normal line:\n%s", line);
        detab();
        printf("%s", detab_line);
    }
}

int getLine(void) //uses global string: line
{
    extern char line[MAXLINE]; // REDUNDANT but doing it for practice
    int ltr;
    int iter;
    for (iter = 0; ((iter < MAXLINE) && ((ltr = getchar()) != '\n') && (ltr != EOF)); ++iter)
    {
        line[iter] = ltr;
    }
    if ('\n' == ltr)
    {
        line[iter] = '\n';
        ++iter;
    }
    line[iter] = '\0';

    return iter;
}

/**
 * Input: string from the user
 * Output: the string's tab is replaced by spaces according to the tabstops
 *
 *  -an editor can be referred with rows and columns
 *  -a tab stop is usually 4 spaces | Blanks
 *  -lets start with some row, but column 1 => left most place of a row
 *  -1,2,3,4 are normal character spots, the 4th is also a tabstop
 *  - => i.e. if we were to enter a 'tab space' at column 1, then 4 spaces or blanks will be inserted
 *  - => and the cursor will stand at the 5th spot or 5th column
 * procedure:
 *  -read the string 'line'
 *  -for every character that was read, increment a character count
 *  -track the tabstop using the (character count % TABWIDTH)
 *      => 0th position => left most | starting of the line is a tabstop
 *      => 1,2,3 % 4 => same number
 *      => 4 % 4 => gives 0
 *      => say we encounter a tabstop as input character
 *      => and we are on (character count % TABWIDTH) = 2,
 *      => then we need to put 3 spaces|blanks and then start
 *      => to read the input string again!
 *  -if a tab is encountered, replace with required number of spaces|blanks as discussed above!
 *  -if a character is encountered, cooy as such
 *  -if a newline is encounter, put as such
 *  - do the above till the current character si null, if null include a null and then  stop copying info, as the input string is valid only upto NULL character
 *
 *
*/
void detab(void)
{
    extern char line[MAXLINE];
    extern char detab_line[MAXLINE];

    int track_length = 0;
    int in_iter;
    int out_iter = 0;

    for( in_iter = 0; (line[in_iter] != '\0'); in_iter++)
    {
        track_length++;
        if (line[in_iter] == '\n')
        {
            detab_line[out_iter] = '\n';
            out_iter++;
            track_length = 0;
        }
        else if(line[in_iter] == '\t')
        {
            while((track_length % TABSTOPLEN) != 0)
            {
                detab_line[out_iter] = ' ';
                out_iter++;
                track_length++;
            }
            detab_line[out_iter] = ' ';
            out_iter++;
            track_length++;
        }
        else
        {
            detab_line[out_iter] = line[in_iter];
            out_iter++;
            // track_length++;
        }
    }
    detab_line[out_iter] = '\0';

}

/**Another one of my solution without the detab function
 */
// #include <stdio.h>

// #define TABSTOPLEN 3

// main()
// {
//     int chr;
//     int track_length = 0; // to track the length of input
//     int curr_pos;
//     while ((chr = getchar()) != EOF)
//     {
//         track_length++;
//         // need to handle only tabspaces and newlines -- otherwise just print the input character
//         if (chr == '\n')
//         {
//             // print the next line and reset the track_length
//             putchar(chr);
//             track_length = 0;
//         }
//         else if (chr == '\t')
//         {
//             // check the current location - where is it from the previous tabstop
//             // curr_pos = (track_length % TABSTOPLEN);
//             // while (curr_pos != 0) //
//             while ((track_length % TABSTOPLEN) != 0) //
//             {
//                 putchar(' ');
//                 track_length++;
//             }
//             // extra space is to be put to compensate the loss in logic
//             putchar(' ');
//         }
//         else
//         {
//             putchar(chr);
//         }
//     }
// }
/*
*/

/**Internet solution

#include <stdio.h>

#define TABINC 8

int main(void)
{
    int nb,pos,c;

    nb = 0;
    pos = 1;

    while((c=getchar())!=EOF)
    {
        if( c == '\t')
        {
            nb = TABINC - (( pos - 1) % TABINC);

            while( nb > 0)
            {
                putchar('#');
                ++pos;
                --nb;
            }
        }
        else if( c == '\n')
        {
            putchar(c);
            pos = 1;
        }
        else
        {
            putchar(c);
            ++pos;
        }
    }

    return 0;
}








 */

/* !    My Original Solution     !*/
/* #include <stdio.h>

#define MAXLINE 1000

char line[MAXLINE];
char detab_line[detab_iter]; // no need to use these strings, just simple getchar and putchar!8676

int getLine(void);
void detab(void);

main()
{
    int length;
    extern char line[MAXLINE];
    // execute once to update the length variable
    while ((length = getLine()) > 0)
    {
        printf("Before detab:\n%s\n", line);
        detab();
        printf("After detab:\n%s\n", detab_line);
    }
}

int getLine(void)
{
    extern char line[MAXLINE]; // REDUNDANT but doing it for practice
    int ltr;
    int iter;
    for (iter = 0; ((iter < MAXLINE) && ((ltr = getchar()) != '\n') && (ltr != EOF)); ++iter)
    {
        line[iter] = ltr;
    }
    if ('\n' == ltr)
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
    extern char detab_line[detab_iter];

    int ltr;
    int idx = 0;
    int other_idx = 0;
    for (idx = 0; (((ltr = line[idx]) != '\n') && (ltr != EOF)); ++idx)
    {
        if ('\t' == ltr)
        {
            int temp = 0;
            while (temp < 4)
            {
                detab_line[detab_iter] = ' ';
                ++temp;
                ++other_idx;
            }
        }
        else
        {
            detab_line[detab_iter] = line[idx];
            ++other_idx;
        }
    }
} */