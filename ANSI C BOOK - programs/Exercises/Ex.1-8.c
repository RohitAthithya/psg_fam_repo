#include<stdio.h>

main()
{
    int c;
    int blank_count    = 0;
    int tab_count      = 0;
    int new_line_count = 0;

    while((c = getchar()) != EOF)
    {
        if(c == ' ')
            blank_count++;
        if (c == '\t')
            tab_count++;
        if (c == '\n')
            new_line_count++;
    }

    printf("blank count is\t:%d\n", blank_count);
    printf("tab count is\t:%d\n", tab_count);
    printf("new line count is\t:%d\n", new_line_count);
}
