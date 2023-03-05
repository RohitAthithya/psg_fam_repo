/*Verify that the expression getchar() != EOF is 0 or 1*/
//refer : https://stackoverflow.com/a/28121480/14827069
//run this code by entering EOF once and any other character than EOF once! => this allows us to understand that the 

#include<stdio.h>

main()
{
    int c;
    /*type any char*/
    // _flushall();
    int a = (getchar() != EOF);
    printf("%d\n", a);
    //_flushall();
    /*don't type -1 here 
    type ctrl+z => as in windows prompt the end of file is denoted by ^Z*/
    a = (getchar() != EOF);
    printf("%d\n", a);
}

//if we input anything other than EOF , we get 1
//or else we get 0

//if we do a = getchar() != EOF ; then we dont get to store the input character in 'a' i.e. as per our intention
//so we have to do (a = getchar() != EOF) inorder to store the character and then do Comparison
