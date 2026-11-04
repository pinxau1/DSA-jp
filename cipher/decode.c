#include <stdio.h>
#include<stdlib.h>
#include"decode.h"
/*

	short int word[4]={17729,21074,18766,18259};
	int *arr;
	char *string;
	int choice;

*/

// Write your functions here...
int* bitmaskToArray(short int word[])
{
  int *arr = malloc(sizeof(int)*64);
  int i = 0;
  for(int k = 0; k < 4; ++k){
    unsigned int mask = 1u << 15;
    while(mask > 0){
      arr[i++] = (word[k] & mask) ? 1: 0;
      mask >>=1;
    }
  }
  return arr;
} 

char* decodeString(int arr[])
{
  char *str = malloc(sizeof(char)*9);
  unsigned int mark; 
  int i = 0, k = 0;
  for(; i < 8; ++i){
    unsigned int kar = 0;  
    for(int j = 0; j < 8; ++j){
      kar = (kar << 1) | arr[k++];
    }
    str[i] = (char)kar;
  }
  str[8] = '\0';
  return str;
}
void displayBitPattern(int arr[])
{   
  for(int i = 0; i < 64; ++i){
    printf("%d", arr[i]);
    if((i + 1) % 16 == 0 && i != 63) printf(", ");
  }
  putchar('\n');
}
