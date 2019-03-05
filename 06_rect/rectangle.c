#include <stdio.h>
#include <stdlib.h>

//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

//Declare your rectangle structure here!
struct rect_t {
  int x;
  int y;
  int width;
  int height;
};

typedef struct rect_t rectangle;


rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTION
  rectangle r_temp;
  if (r.width < 0 && r.height < 0){
     r_temp.width = abs(r.width);
     r_temp.x = r.x - r_temp.width;
     r_temp.height = abs(r.height);
     r_temp.y = r.y - r_temp.height;
     return r_temp;
  }
  else if (r.height < 0 && r.width >= 0){
     r_temp.height = abs(r.height);
     r_temp.y = r.y - r_temp.height;
     r_temp.x = r.x;
     r_temp.width = r.width;
     return r_temp;
  }
  else if (r.width < 0 && r.height >= 0){
     r_temp.width = abs(r.width);
     r_temp.x = r.x - r_temp.width;
     r_temp.height = r.height;
     r_temp.y = r.y;
     return r_temp;
  }
  else {
    r_temp.width = r.width;
    r_temp.x = r.x;
    r_temp.height = r.height;
    r_temp.y = r.y;
    return r_temp;
  }
}
rectangle intersection(rectangle r1, rectangle r2) {
  //WRITE THIS FUNCTION
  r1 = canonicalize(r1);
  r2 = canonicalize(r2);
  int min_right = min(r1.x + r1.width, r2.x + r2.width);
  int max_left = max(r1.x, r2.x);
  int min_top = min(r1.y + r1.height, r2.y + r2.height);
  int max_bottom = max(r1.y, r2.y);
  rectangle ans;
  
  // check whether both are same rectangle
  if(r1.x == r2.x && r1.y == r2.y && r1.width == r2.width && r1.height == r2.height){
    ans.x = r1.x;
    ans.y = r1.y;
    ans.width = r1.width;
    ans.height = r1.height; 
    ans = canonicalize(ans);
    return ans;
  }
  // Non-overlapping cases
  else if ( ((min_right - max_left) < 0) || ((min_top - max_bottom) < 0) ){
    ans.x = r1.x;
    ans.y = r1.y;
    ans.width = 0;
    ans.height = 0;
    return ans;
  }
  // One side overlap only 
  else if ( ((min_right - max_left) == 0) || ((min_top - max_bottom) == 0)  ){
    ans.x = max(r1.x, r2.x);
    ans.y = max(r1.y, r2.y);
    ans.width = ( min( (r1.x + r1.width), (r2.x + r2.width) ) - ans.x);
    ans.height = ( min( (r1.y + r1.height), (r2.y + r2.height) ) - ans.y);
    ans = canonicalize(ans);
    return ans;   
  }
  // Overlapping rectangles
  else {//if ( ((min_right - max_left) > 0) && ((min_top - max_bottom) > 0) ) {
    ans.x = max(r1.x, r2.x);
    ans.y = max(r1.y, r2.y);
    ans.width = (min(r1.width + r1.x, r2.width + r2.x) - ans.x);
    ans.height = (min(r1.height + r1.y, r2.height + r2.y) - ans.y);
    ans = canonicalize(ans);
    return ans;
    }
}
//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
