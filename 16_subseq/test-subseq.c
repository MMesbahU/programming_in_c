#include<stdio.h>
#include<stdlib.h>

size_t maxSeq(int *array, size_t n);

// Compare different Array
void ans(int *array, size_t n, size_t answer)
{
  if (maxSeq(array, n) != answer )
  {
    printf("Test Failed!\n");
    exit(EXIT_FAILURE);
  }
  else
    {
      printf("Test Succeed\n");
    }
}
// Main Function
int main()
{
  int arr1[] = {-1, 0, 1};
  ans(arr1, 3, 3);

  int arr2[] = {3, 3, 4, 4, 5};
  ans(arr2, 5, 2);
 
  int arr3[] = {1, 2, 3, 3, 4, 5};
  ans(arr3, 6, 3);

  int arr4[] ={0};
  ans(arr4, 0, 0);
  
  int arr5[] = {100, 99, 98};
  ans(arr5, 3, 1); 
 
  return(EXIT_SUCCESS);
}


