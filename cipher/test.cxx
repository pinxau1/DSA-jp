#include<stdio.h>
#include<stdlib.h>

int main(){
  int num = 10;
  int *arr = malloc(sizeof(int)*65);
  int i = 0;
  unsigned int mask = 1;
  while(mask <= num/2){
    mask <<= 1;
  }
  while(mask > 0){
    arr[i++] = (num & mask) ? 1 : 0;
    mask>>=1;
  }
  for(int k = 0; k < i; k++){
    printf("%d", arr[k]);
  }
}
