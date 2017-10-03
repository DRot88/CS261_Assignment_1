/* CS261- Assignment 1 - Q.4*/
/* Name: Daniel Rotenberg
 * Date: 10/1/2017
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
  int a,b;

  for (a = 0; a < n; a++) {
    for (b = 0; b < n-1; b++) {
      if (students[b].score > students[b+1].score) {
        int tempScore = students[b].score;
        int tempId = students[b].id;
        students[b].score = students[b+1].score;
        students[b].id = students[b+1].id;
        students[b+1].score = tempScore;
        students[b+1].id = tempId;
      }
    }
  }    
}

int main(){
    srand(time(0));
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    /*Allocate memory for n students using malloc.*/
    struct student* students = malloc(n * sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
    int x;
     for (x = 0; x < n; x++) {
      // int randNum = (rand() % 10) + 1;  // random # between 1 and 10 
      int randScore = (rand() % 100) + 1;  //random # between 1 and 100 
      students[x].id = x + 1;       // set student[x] id
      students[x].score = randScore;  // set student[x] score
     }

    // randomize student id's
     for (x = n - 1; x > 0; x--) {
      int j =  rand() % (x + 1); //select random index
      int temp = students[x].id; //swap positions
      students[x].id = students[j].id;
      students[j].id = temp;
     }
    /*Print the contents of the array of n students.*/
    int i;
    printf("\nIDs\tScores\n\n");
    for (i = 0; i < n; i++) {
      printf("%3d\t%4d\n", students[i].id, students[i].score);
    }   
    printf("\n");

    /*Pass this array along with n to the sort() function*/

    sort(students, n);
    
    /*Print the contents of the array of n students.*/

    printf("\nIDs\tScores\n\n");
    for (i = 0; i < n; i++) {
      printf("%3d\t%4d\n", students[i].id, students[i].score);
    }   
    printf("\n");
    
    return 0;
}
