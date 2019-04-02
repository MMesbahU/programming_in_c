#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char * str)
{
  //WRITE ME!
  int length = strlen(str);
  char answer[(length + 1)];
  answer[length] = '\0';
  int i = 0;
  int j = length;   
  if (length == 0)
    {
      strcpy(str, answer);
    }
  else if (length > 0)
    {
      while ( i < length && j !=0  )
	{
	  answer[i] = str[j-1];
	  i++;
	  j--;
	}
      strcpy(str, answer);
    }
  else
    {
      exit(EXIT_FAILURE);
    }
}

int main(void) {
  char str0[] = "";
  char str1[] = "123";
  char str2[] = "abcd";
  char str3[] = "Captain's log, Stardate 42523.7";
  char str4[] = "Hello, my name is Inigo Montoya.";
  char str5[] = "You can be my wingman anyday!";
  char str6[] = "Executor Selendis! Unleash the full power of your forces! There may be no tomorrow!";
  char * array[] = {str0, str1, str2, str3, str4, str5, str6};
  for (int i = 0; i < 7; i++) {
    reverse(array[i]);
    printf("%s\n", array[i]);
  }
  return EXIT_SUCCESS;
}
