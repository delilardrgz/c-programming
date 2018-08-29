#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void){
  //two sequence of increasing values
  int array1[] = {1,-1,2,0};
  int size1 = maxSeq(array1,4);
  if (size1 != 2){
    printf("failed to identify 2 sequences, size = %d\n", size1);
    return EXIT_FAILURE;
  }
  //invalid parameters, giving size as negative value produces seg fault
  //size of 0
  int array22[] = {1,-1,2,0};
  int size2 = maxSeq(array22, 0);
  if (size2 != 0){
    printf("failed to identify size of 0, size = %d\n", size2);
    return EXIT_FAILURE;
  }
  //no, increasing, only decreasing
  int array2[] = {10, 9, 8};
  int size3 = maxSeq(array2, 3);
  if (size3 != 1){
    printf("fail, nothing concurent. size = %d\n", size3);
    return EXIT_FAILURE;
    }
  //10
  unsigned array3[] = {-1,0,1};
  unsigned size4 = maxSeq(array3,3);
  if (size4 != 2){
    printf("failed unsigned. size = %u", size4);
    return EXIT_FAILURE;
    }
  //11
  int array4[1] = {11};
  int size5 = maxSeq(array4,1);
  if (size5 != 1){
    printf("fail, size is 1");
    return EXIT_FAILURE;
    }
  //empty
  int size6 = maxSeq(NULL,0);
  if (size6 != 0){
    printf("Fail to determine empty array\n");
    return EXIT_FAILURE;
    }
  //1
  //size bigger than array
  /*int array6[] = {1,2,3};
  int size7 = maxSeq(array6,35);
  if (size7 != 1){
    printf("fail,determined size too big. size = %d", size7);
    return EXIT_FAILURE;
    }
  int array7[] = {1,0,5,6,2,7,8};
  int size8 = maxSeq(array7,7);
  if(size8 != 3){
    
    return EXIT_FAILURE;
    }*/

  return EXIT_SUCCESS;
}
