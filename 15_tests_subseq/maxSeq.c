#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
  //returns the length of the maximum  increasing contiguous subsequence
  // of integers in the array
 
  //create a pointer to the first element
  int * p = &array[0];
  //create a variable of type int named count
  int count;
  //check if array is empty
  if (p == NULL){
    count =0;
    return count;
  }
  //create a variable of type size_t named current,set it equal to array index 1
  size_t current = array[0];
  
  if (n == 0){
    //size is 0
    count = 0;
    return count;
  }
  //create a variable of type int named next which is uninitialized
  int next;
  //there is at least 1 element in the array, set count to 1
  count = 1;
  //count for each item in array
  for (int i = 1; i < n; i++){
  //set next equal to current
    next = current;
    //printf("top of for loop, next is: %d\n", next);
  //set current equal to the address of array[i]
    current = array[i];
    //printf("now current is:%lu\n", current);
  //if current > next
      if (current > next){
  //increment count
	//printf("current is greater than next\n");
	count++;
      }
  }
  //return count
  return count;
}
