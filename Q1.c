/* CS261- Assignment 1 - Q.1*/
/* Name: Daniel Rotenberg
 * Date: 09/29/2017
 * Solution description: This program creates an array of students, populates the array with
                        random and unique ID's and random test scores. It then calculates 
                        the max, min, and average scores and prints this to the screen.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	int id;
	int score;
};

const int NUMSTUDENTS = 10;

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* students = malloc(NUMSTUDENTS * sizeof(struct student*));
     /*return the pointer*/
     return students;
}

void generate(struct student* students){
     /*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
     int x;
     for (x = 0; x < NUMSTUDENTS; x++) {
      // int randNum = (rand() % 10) + 1;  // random # between 1 and 10 
      int randScore = (rand() % 100) + 1;  //random # between 1 and 100 
      students[x].id = x + 1;       // set student[x] id
      students[x].score = randScore;  // set student[x] score
     }

     // randomize student id's
     for (x = NUMSTUDENTS - 1; x > 0; x--) {
      int j =  rand() % (x + 1); //select random index
      int temp = students[x].id; //swap positions
      students[x].id = students[j].id;
      students[j].id = temp;
     }

}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int x;
    printf("\nIDs\tScores\n\n");
    for (x = 0; x < NUMSTUDENTS; x++) {
      printf("%3d\t%4d\n", students[x].id, students[x].score);
    }   
    printf("\n");
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
  int min, max;    // to hold min, max values
  float sum = 0.0;     // to hold sum of all scores
  float average = 0.0;    // to hold average score
  int index;
  for (index = 0; index < NUMSTUDENTS; index++) {
    if (index == 0) {
      min = max = students[index].score;
    }

    if (students[index].score < min) {
      min = students[index].score;
    }

    if (students[index].score > max) {
      max = students[index].score;
    }    

    sum += students[index].score;

  }

  average = sum/NUMSTUDENTS;

  printf("Minimum Score = %d\n", min);
  printf("Maximum Score = %d\n", max);
  printf("Average Score = %.2f\n\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
  free(stud);
}

int main(){
    struct student* stud = NULL;
    srand(time(0));
    
    /*call allocate*/
    struct student* students = allocate();
    /*call generate*/
    generate(students);
    /*call output*/
    output(students);
    /*call summary*/
    summary(students);
    /*call deallocate*/
    deallocate(students);
    return 0;
}
