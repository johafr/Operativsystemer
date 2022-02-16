//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>

//variables


//alarm struct som skal brukes i array
struct alarm {
  int alarmId;
  int PID; 
  time_t ringTime;
};

//har en array som har plass til 10 structs (alarm)
struct alarm alarms[10];


//methods
void actionS() {

  char inputTime[19];

  printf("Schedule alarm at which date and time hei?");

  scanf(" %c", &inputTime);

  inputTime[4] = inputTime[7] = '\0';
  inputTime[13] = inputTime[16] = '\0';
  struct tm tmdate = {0};
  tmdate.tm_year = atoi(&inputTime[0]) - 1900;
  tmdate.tm_mon = atoi(&inputTime[5]) - 1;
  tmdate.tm_mday = atoi(&inputTime[8]);
  tmdate.tm_hour = atoi(&inputTime[11]);
  tmdate.tm_min = atoi(&inputTime[14]);
  tmdate.tm_sec = atoi(&inputTime[17]);
  time_t t = mktime( &tmdate );

  time_t seconds;
  seconds=time (NULL);

  long result=t-seconds;


  printf("Entered time is: %ld", &result);

  /*

  struct tm rawTimeInput;
  time_t timeInput;
  time_t result;

  time_t seconds;
  seconds=time (NULL);

  

  int day=rawTimeInput.tm_mday;
  int mon=rawTimeInput.tm_mon;
  int year=rawTimeInput.tm_year;
  int sec=rawTimeInput.tm_sec;
  int min=rawTimeInput.tm_min;
  int hour=rawTimeInput.tm_hour;


  printf("Schedule alarm at which date and time hei?");

  scanf("%d-%d-%d %d:%d:%d", &rawTimeInput.tm_mday, &rawTimeInput.tm_mon, &rawTimeInput.tm_year, &rawTimeInput.tm_hour, &rawTimeInput.tm_min, &rawTimeInput.tm_sec);


  timeInput=mktime(&rawTimeInput);
  result=timeInput-seconds;


  printf("Entered time is: %ld", &result);

  */
  

 /*
  char input[19];
  struct tm time_struct;

  printf("Schedule alarm at which date and time? ");
  scanf("%19[^\n]", input);
  strptime(input, "%Y-%m-%d %H:%M:%S", &time_struct);

  time_struct.tm_gmtoff=0;
  time_struct.tm_isdst=0;

  time_t tid = mktime(&time_struct);
  long seconds_left = tid - time(NULL);


  printf("%ld",seconds_left);
  */

}

void actionL() {

}

void actionC() {
  
}

void actionX() {
  
}


//main
int main(){

  time_t rawTime;
  struct tm *timeinfo;
  time (&rawTime);
  timeinfo = localtime (&rawTime);
  
  char action; 
  printf("Welcome to the alarm clock! It is currently %s . Please enter 's' (schedule), 'l' (list), 'c' (cancel), 'x' (exit) \n", asctime (timeinfo));
 
  while (action != 'x') {
    scanf(" %c", &action); 
    
    if (action == 's') {
      printf("your input = %c \nyou can schedule an alarm \n", action);
      actionS();
    } else if (action == 'l') {
      printf("your input = %c \nyou can display alarms \n" , action);
      actionL();
    } else if (action == 'c') {
      printf("your input = %c \nyou can cancel alarms \n" , action);
      actionC();
    } else {
      if (action != 'x') {
      printf("wrong bitch \n");
       }
     }
   }
  
  
  printf("Compiled");
  return 0;
}
