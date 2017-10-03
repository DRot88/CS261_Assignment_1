/* CS261- Assignment 1 - Q.5*/
/* Name: Daniel Rotenberg
 * Date: 10/02/2017
 * Solution description: Takes a word as input and coverts it to sticky caps.
            This means that every other letter will be in CAPS and the rest
            will be lowercase.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
  int ch; 
  for(ch = 0; ch < strlen(word); ch++) {
    if (ch % 2 == 1) { /* if ch is odd, conver to lower */
      if(word[ch] >= 'A' && word[ch] <= 'Z') {
        word[ch] = toLowerCase(word[ch]);
      }
    } else { /* if ch if even, convert to upper */
      if(word[ch] >= 'a' && word[ch] <= 'z') {
       word[ch] = toUpperCase(word[ch]);
      }
    }
  }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char str[256];
    printf("\nPlease enter any word you like to be converted into StIcKy CaPs: ");
    scanf("%s", str);
    /*Call sticky*/
    sticky(str);
    /*Print the new word*/
    printf("%s\n", str);
    
    return 0;
}
