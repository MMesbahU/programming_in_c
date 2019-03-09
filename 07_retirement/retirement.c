#include <stdio.h>
#include <stdlib.h>

// this is a "retirement saving" calculator
struct _retire_info { 
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

// abstraction
// balance structure
struct balance_t{
  double current_balanc;
  int current_age;
};
typedef struct balance_t balance_info;
// calculate current balance
balance_info currentBalance (balance_info balanc, retire_info retire){
  balance_info ans;
  ans.current_balanc = balanc.current_balanc;
  ans.current_age = balanc.current_age;
  for(int i = 0; i < retire.months; i++){
    printf("Age %3d month %2d you have $%.2lf\n", ans.current_age/12, ans.current_age%12, ans.current_balanc);
    ans.current_balanc += ans.current_balanc * retire.rate_of_return + retire.contribution;
    ans.current_age += 1;
  }
  return ans;
}


// Writing the function
void retirement (int startAge,
		 double initial,
		 retire_info working,
		 retire_info retired){
  balance_info init_balance; 
  init_balance.current_age = startAge;
  init_balance.current_balanc = initial;
  balance_info current_balance;
  // During Work
  current_balance = currentBalance(init_balance, working);
  // After retirement
  currentBalance(current_balance, retired);
}

// Run the program
int main (void) {
  retire_info w1;
  w1.months = 489;
  w1.contribution = 1000;
  w1.rate_of_return = 0.045/12;
  //printf("The Working info %d\n",w1);
  retire_info r1;
  r1.months = 384;
  r1.contribution = -4000;
  r1.rate_of_return = 0.01/12;
  int startAge = 327;
  double initial = 21345;
  retirement (startAge, initial,  w1, r1);   
  return EXIT_SUCCESS;
}
 
      
