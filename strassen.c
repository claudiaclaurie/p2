#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "strassen.h"


//main function

int main(int argc, char **argv){
  if (argc != 4){
    printf("usage: ./strassen 0 <dimension> <inputﬁle>|r\n");
    return 1;
  }   

    // commandline input
  int dim = atoi(argv[2]);
  dimension = dim;
  //detetmines what type of multiplication 
  int typecode = atoi(argv[1]);
  // 0 = unpotimized normal matrix multiplication; 1 = strassens 

  int **a, **b, **c;
  


 //generate matrix randomly// 

void randmatrix(int n, int **m){
  //Seeds random number generator with time for unique number
  struct timeval t1;
  gettimeofday(&t1, NULL);
  srand(t1.tv_usec * t1.tv_sec);
  
  int i, j;
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      m[i][j] = rand() % 3;
    }
  }
  return;
}

//print generated matrix//
void printmatrix(int n, int **m){
  int i, j;
  for (i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ",m[i][j]);
    }
    printf("\n");
  }
  return;
}

// normal matrix multiplication//

void normalmult(int **a, int **b, int **c, int d){
  int i, j, k;
  int tmp;

  // walk through column
  for (i=0; i<d; i++){
    // walk through row
    for (j=0; j<d; j++){
      tmp = 0;
      // calculate an element
      for (k=0; k<d; k++){
	tmp += a[i][k] * b[k][j];
      }
      c[i][j] = tmp;
    }
  }
}