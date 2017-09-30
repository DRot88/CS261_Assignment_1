/* CS261- Assignment 1 - Q. 0*/
/* Name: Daniel Rotenberg
 * Date: 09/29/2017
 * Solution description: fooA takes a pointer to an integer
   and prints the value, address of value, address of pointer                 
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("Value pointed to by iptr = %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr = %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("Address of iptr = %p\n", (void *) &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 0;
    /*print the address of x*/
    printf("\nAddress of x = %p\n", (void *) &x);
    /*Call fooA() with the address of x*/
    fooA((void*) &x);
    /*print the value of x*/
    printf("Value of x = %d\n", x);
    printf("\n");

    return 0;
}
