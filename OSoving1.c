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
  time_t currentTime;
  time(&currentTime);
  
  struct tm *alarm = localtime(&currentTime);
  for (int i = 0; i < 1; i++) {
    int input;
    printf("enter values, (year, month, day, hour, minute, second): ");
    scanf("%i", &input);
    if (i == 0 && input >= alarm->tm_year) {
      alarm->tm_year = input - 1900;
    }
    printf("%i\n", alarm->tm_year);
  }
  time_t alarmTime = mktime(alarm);
  printf("%s\n", ctime(&alarmTime));
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
     printf("%s", "next input: ");
   }
  
  
  printf("Compiled");
  return 0;
}
