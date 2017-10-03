/* CS261- Assignment 1 - Q.2*/
/* Name: Daniel Rotenberg
 * Date: 10/01/2017
 * Solution description: This program creates three integer variables, represented by 'x', 'y', and 'z'
                        each being assined with 5,6,7 respectively. They are then passed to the function
                        'foo' - 2 by reference, 1 by value, and then reprints the new results
                        to the screen. Only the integer passed by value remains the same.
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2*(*a);
    /*Set b to half its original value*/
    *b = (*b/2);
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    /*Print the values of x, y and z*/
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);
    printf("The value of z is: %d\n", z);
    /*Call foo() appropriately, passing x,y,z as parameters*/
    int fooReturns = foo((void *) &x, (void *) &y, z);
    /*Print the value returned by foo*/
    printf("The value returned by foo is %d\n", fooReturns);
    /*Print the values of x, y and z again*/
    printf("The value of x is: %d\n", x);
    printf("The value of y is: %d\n", y);
    printf("The value of z is: %d\n", z);
    /*Is the return value different than the value of z?  Why?*/

        /*  Yes the return value is different than the value of Z.
            This is because z is based by value, so only a copy
            of z is used when being manipulated by the foo function.
            If the return value was either 'x' or 'y', they would 
            have permanently been changed since they are passed
            by reference */

    return 0;
}
    
    
