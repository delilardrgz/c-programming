#include <stdio.h>
#include <stdlib.h>

size_t maxSeq(int * array, size_t n){
 //returns the length of the maximum  increasing contiguous subsequence
  // of integers in the array
  printf("In maxSeq\n"); 
  //create a pointer to the first element
  int * p = &array[0];
  printf("created pointer p: %p\n", p);
  //create a variable of type int named count
  int count;
  printf("created count\n");
  //check if array is empty
  if (p == NULL){
    printf("p is NULL\n");
    count =0;
    printf("count = 0. returning 0. exiting maxSeq\n");
    return count;
  }
  //create a variable of type size_t named current,set it equal to array index 1
  size_t current = array[0];
  printf("creating current of type size_t = %lu\n", current);

  if (n == 0){
    printf("size passed in was 0\n");
    //size is 0
    count = 0;
    printf("count = 0. returning 0. exiting maxSeq\n");
    return count;
  }
  //create a variable of type int named next which is uninitialized
  int next;
  printf("creating next\n");
  //there is at least 1 element in the array, set count to 1
  count = 1;
  printf("count = 1\n");
  //count for each item in array
  for (int i = 1; i < n; i++){
    printf("in for loop, i = %d\n", i);
  //set next equal to current
    next = current;
    printf("the next number in the array = %d\n", next);
  //set current equal to the address of array[i]
    current = array[i];
    printf("now current is:%lu\n", current);
  //if current > next
      if (current > next){
  //increment count
	printf("current is greater than next\n");
	count++;
	printf("count incremented. count = %d\n", count);
      }
  }
  //return count
  printf("retuning count = %d. exiting maxSeq\n", count);
  return count;
}
