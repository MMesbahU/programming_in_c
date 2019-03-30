#include <stdio.h>
#include <stdlib.h>

// maxSeq function
size_t maxSeq(int * array, size_t n)
{
    /* Function to return maximum increasing contiguous subsequence in the array */
  size_t temp = 0;
  size_t current_max = 1;
  size_t max_seq = 1;
  if (n == 0)
    {
      return temp;
    }
  else if (n == 1)
    {
      temp = 1;
      return temp;
    }
  else if (n > 1)
    {
      for (int i = 0; i < n-1 ; i++)
	{
	  if ( array[i] < array[(i+1)] )
            {
              current_max += 1;
              if(current_max > max_seq)
		{
		  max_seq = current_max; 
		}
            }
	  else 
            {
	      current_max = 1;
            }
        }
      return max_seq;
    }
  else
    {
      exit (EXIT_FAILURE);
    }

}  

