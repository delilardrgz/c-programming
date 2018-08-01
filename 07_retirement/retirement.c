#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double computeBalance(double balance, double rate, int contribution){
  //compute balance increase from returns
  double rate_per_month = balance * rate;
  //add that to current balance
  balance += rate_per_month;
  //add monthly contribution to current balance
  balance += contribution;
  
  return balance;
}
  
void retirement (int startAge,
		 double initial,
		 retire_info working,
		 retire_info retired){
  double balance = 0;
  if (balance == 0){
    balance = initial;
  }
  int age = startAge;
  int age_year;
  int age_month;
   
  for (int j = 1; j <= working.months; j++){
    //print at the start of each month before the balance changes
    age_year = age / 12;
    age_month = age % 12;
    printf("Age %3d month %2d you have $%.2f\n", age_year, age_month, balance);      
    balance = computeBalance(balance, working.rate_of_return, working.contribution);
    age +=1;
  }
   //perform similar computation for each month of retirement
   //use info in retired structure instead of working structure
  for (int i = 1; i <= retired.months; i++){
    age_year = age /12;
    age_month = age % 12;
    printf("Age %3d month %2d you have $%.2f\n", age_year, age_month, balance);
    balance = computeBalance(balance, retired.rate_of_return, retired.contribution);
    age += 1;
  }
 }

int main(){
  retire_info working;
  retire_info retired;

  working.months = 489; //489
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12;

  retired.months = 384; //384
  retired.contribution = -4000;
  retired.rate_of_return = 0.01 / 12;

  retirement(327, 21345, working, retired);
  
  return EXIT_SUCCESS;
}
