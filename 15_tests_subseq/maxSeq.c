#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  //returns the length of the maximum  increasing contiguous subsequence
  // of integers in the array

  //create a variable of type int named current, set it equal to array index 1
  int current = array[0];
  //printf("pointer to first element in array is: %d\n", current);
  //create a variable of type int named size, set it equal to n
  int size = n;
  //printf("size is: %d\n", size);
  int length =(sizeof(array)/sizeof(current));
  //printf("length is: %d\n", length +1);
  //create a variable of type int named count
  int count;
  //create a variable of type int named next which is uninitialized
  int next;
  //if array is empty or equal to 0, return 0
  //if (current == NULL){
    //return 0;
    //}
  if (size == 0){
    return 0;
  }
  else{
    //array has at least 1 element, count = 1
    count = 1;
  }
  if (size != (length +1)){
    return EXIT_FAILURE;
  }
  //count for each item in array
  for (int i = 1; i < size; i++){
  //set next equal to what current is pointing to
    next = current;
    //printf("now next is: %d\n", next);
  //set current equal to the address of array[i]
    current = array[i];
  //if current > next
      if (current > next){
  //increment count
	count++;
      }
  //else count = 0
      else{
        count = 0;
      }
  }
  //return count
  //printf("count is: %d\n", count);
  return count;
}
