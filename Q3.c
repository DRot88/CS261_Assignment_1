/* CS261- Assignment 1 - Q.3*/
/* Name: Daniel Rotenberg
 * Date: 10/01/2017
 * Solution description: This program creates an array of 20 integers and assigns them 
                          random numbers (I set it between 1-1000) and outputs these to
                          the console. It then sorts the array and reprints it.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void sort(int* number, int n){
     /*Sort the given array number , of length n*/     
  int i,j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < n-1; j++) {
      if (number[j] > number[j+1]) {
        int temp = number[j];
        number[j] = number[j+1];
        number[j+1] = temp;
      }
    }
  }

}

int main(){
    srand(time(0));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    int x;

    for (x = 0; x < n; x++) {
      int randNum = rand() % 1000 + 1;
      array[x] = randNum;
    }
    /*Print the contents of the array.*/

    for (x = 0; x < n; x++) {
      printf("Array[%d]: %d\n", x, array[x]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    printf("\nArray has been sorted\n");
    /*Print the contents of the array.*/    
    
    for (x = 0; x < n; x++) {
      printf("Array[%d]: %d\n", x, array[x]);
    }

    if (array != 0) {
      free(array);
    }

    return 0;
}
