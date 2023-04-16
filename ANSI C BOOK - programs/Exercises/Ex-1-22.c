/** Exercise 1-22
 * Write a program to "fold" long input lines into two or more shorter lines after the
 * last non-blank character that occurs before the n-th column of input.
 * Make sure your program does something intelligent with very long lines,
 * and if there are no blanks or tabs before the specified column.
*/
#include<stdio.h>

#define MAXLINE 1000
#define PAGESTOP_COLNUM 10
#define NEAREST_BLANK_LIMIT 5
// page stop column number 0 -> 96 => 1 -> 97

char line[MAXLINE];
char folded_line[MAXLINE];
// a global variable => default value is 0 or '\0'
int fold_line_iter;
int no_of_folds;

int getLine(void);
int nearestBlank(int rev_start);
void fold_input_line(int inp_len);
void copyToOutput(int start_idx, int end_idx);

main()
{
    int input_length = 0;
    extern int fold_line_iter;
    fold_line_iter = 0;
    while ((input_length = getLine()) > 0 )
    {
        if (input_length > PAGESTOP_COLNUM) // only long lines undergo folding! Exactly as the question mentions
        {
            fold_input_line(input_length);
            printf("%s", folded_line);
        }
        else // print the input line as such as it is!
            printf("%s",line);
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

void fold_input_line(int inp_len) // only if the line has to be folded, this function is called
{
    extern int no_of_folds;
    no_of_folds = 0;
    int rem_chars = inp_len;
    int in_iter = 0;
    int start = 0;
    int end = 0;
    int blank_at = 0;
    while ((rem_chars - (PAGESTOP_COLNUM)) > 0 )
    {
        // step 1:
        start = (PAGESTOP_COLNUM * no_of_folds);
        end = start + (PAGESTOP_COLNUM - NEAREST_BLANK_LIMIT - 1);
        copyToOutput(start, end);
        in_iter = end + 1;
        // step 2:
        blank_at = nearestBlank((PAGESTOP_COLNUM * (1 + no_of_folds)));
        // step 3:
        if (blank_at >= end)
        {
            // yay, blank found at: blank_at
            start = in_iter;
            end = blank_at;
            copyToOutput(start, end-1);
            in_iter = end + 1;
            folded_line[fold_line_iter] = '\n';
            fold_line_iter++;
            start = in_iter;
            end = (PAGESTOP_COLNUM * (1 + no_of_folds)) - 1;
            copyToOutput(start, end);
            in_iter = end + 1;
            // printf("in_iter = %d\n",in_iter);
        }
        else // blank not found => do hypenation
        {
            start = in_iter;
            end = (PAGESTOP_COLNUM * (1 + no_of_folds)) - 1;
            if (no_of_folds >= 1)
                end = end - 1;
            copyToOutput(start, end);
            in_iter = end + 1; //96th character!
            // printf("in_iter = %d\n",in_iter);
            folded_line[fold_line_iter] = '-';
            fold_line_iter++;
            folded_line[fold_line_iter] = '\n';
            fold_line_iter++;
            folded_line[fold_line_iter] = '-';
            fold_line_iter++;
        }
        // step 4:
        no_of_folds++;
        rem_chars = rem_chars - PAGESTOP_COLNUM;
    }
    if (rem_chars > 0)
    {
        start = in_iter;
        end = inp_len;
        copyToOutput(start, end);
    }
}

int nearestBlank(int rev_start)
{
    int idx = rev_start;
    int nearest_blank_at = -1;
    while((nearest_blank_at == -1 ) && (idx >= (PAGESTOP_COLNUM * (1 + no_of_folds)) - NEAREST_BLANK_LIMIT))
    {
        if (line[idx] == ' ' || line[idx] == '\t')
        {
            nearest_blank_at = idx;
        }
        else
            idx--;
    }
    return nearest_blank_at; // if -1 => blank not found , else found at idx
}

void copyToOutput(int start_idx, int end_idx)
{
    extern char line[MAXLINE];
    extern char folded_line[MAXLINE];
    extern int fold_line_iter;

    if (start_idx <= end_idx)
    {
        for (int i = start_idx; i <= end_idx; ++i)
        {
            folded_line[fold_line_iter] = line[i];
            fold_line_iter++;
        }
    }
}



/** nth column => 10
 * aaaaaaaaaaaaaaaa
 *
 *
 *
 *
 * This is    Rohit here
 * =>
 * This is
 * Rohit here
*/