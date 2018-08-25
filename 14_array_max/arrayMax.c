#include <stdio.h>
#include <stdlib.h>

int * arrayMax(int * array, int n) {
  if (n == 0){
    //if length is 0, return NULL
    return NULL;
  }
  // set largElement equal to array[0]
  int largElement = array[0];
  //count, for each element in the array, compare largElemnet to array[i]
  for (int i=1; i < n; i++){
    // printf("array[%d]: %d\n", i, array[i]);
    if (array[i] > largElement){
      //printf("%d is larger than %d\n", array[i], largElement);
      largElement = array[i];
    }
  }
  //printf("Largest element is: %d\n", largElement);
  // create pointer of type int that points to the address of largElement
  int * p = &largElement;
  return p;
}

void doTest(int * array, int n) {
  printf("arrayMax(");
  if (array == NULL) {
    printf("NULL");
  }
  else {
    printf("{");
    for (int i =0; i < n; i++) {
      printf("%d", array[i]);
      if (i < n -1) {
	printf(", ");
      }
    }
    printf("}");
  }
  printf(", %d) is \n", n);
  int * p = arrayMax (array, n);
  if (p == NULL) {
    printf("NULL\n");
  }
  else {
    printf("%d\n", *p);
  }
}

int main(void) {
  int array1[] = { 77, 33, 19, 99, 42, 6, 27, 4};
  int array2[] = { -3, -42, -99, -1000, -999, -88, -77};
  int array3[] = { 425, 59, -3, 77, 0, 36};

  doTest (array1, 8);
  doTest (array2, 7);
  doTest (array3, 6);
  doTest (NULL, 0);
  doTest (array1, 0);
  
  return EXIT_SUCCESS;
}
