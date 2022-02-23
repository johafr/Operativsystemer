//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <unistd.h>


//variables


//alarm struct som skal brukes i array
struct alarm {
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
  for (int i = 0; i < 6; i++) {
    int input;
    printf("enter values, (year, month, day, hour, minute, second): ");
    scanf("%i", &input);
    if (i == 0 && input >= alarm->tm_year) {
      alarm->tm_year = input - 1900;
    }
    if (i == 1) {
      alarm->tm_mon = input - 1;
    }
    if (i == 2) {
      alarm->tm_mday = input;
    }
    if (i == 3 && input <= 24) {
      alarm->tm_hour = input;
    }
    if (i == 4 && input <= 60) {
      alarm->tm_min = input;
    }
    if (i == 5 && input <= 60) {
      alarm->tm_sec = input;
    }
  }
  time_t alarmTime = mktime(alarm);
  printf("Scheduling alarm for: %s\n", ctime(&alarmTime));
  for (int i = 0; i < 10; i++) {
    if (alarms[i].PID == 0) {
      alarms[i].ringTime = alarmTime;
      alarms[i].PID = i;
      break;
    }
  }
  printf("%ld", alarmTime - currentTime);
}

void actionL() {                                              // Skal komme med en liste over alle alarmer 
  time_t currentTime;                                         // lager en variabel med currentTime               
  time(&currentTime);                                         // Setter tiden akkurat nå
  printf("Your alarms are set at: \n");
  for (int i = 0; i<10; i++){
    time_t test2 = alarms[i].ringTime;
    printf("%s \n", ctime(&test2));
  }
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
