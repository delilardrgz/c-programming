#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n);

int main(void){
  /*
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
  */

  //10
  unsigned array3[] = {-1,1, 2};
  printf("********************************array= {-1,1,2}  size = 3\n");
  size_t size4 = maxSeq(array3,3);
  if (size4 == 3){ 
    printf("read unsigned as int. result= %lu\n", size4);
    return EXIT_FAILURE;
  }
  else if (size4 != 2){
    printf("failed, unsigned int. result =%lu \n", size4);
    return EXIT_FAILURE;
  }

  /*
  //11
  int array4[1] = {11};
  int size5 = maxSeq(array4,1);
  if (size5 != 1){
    printf("fail, size is 1");
    return EXIT_FAILURE;
    }
  */
  /*
  //empty
  int size6 = maxSeq(NULL,0);
  if (size6 != 0){
    printf("Fail to determine empty array\n");
    return EXIT_FAILURE;
    }
  */
  //test for 10, wrong size
  int array5[] = {};
  size_t length = (sizeof(array5) / sizeof(array5[0]));
  //size_t size = 2;
  printf("*******************************array = {} size = 2\n");
  int result = maxSeq(array5, 10);
  if (result != 0){
    printf("Failed to determine wrong size\n");
    return EXIT_FAILURE;
  }else{
    printf("result = %d\n", result);
  }
    /*if (length != size){
      printf("user passed in wrong size, result = %d\n", result);
      //size = length;
      return EXIT_FAILURE;
      }*/
  return EXIT_SUCCESS;
}
