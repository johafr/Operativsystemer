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
  
  struct tm *alarm;
  
  char date[250];
  int year;
  int month;
  int day;
  printf("enter scheduled date (YYYY-MM-DD): ");
  scanf("%s", &date);
  sscanf(date, "%4d-%2d-%2d", &year, &month, &day);

  alarm->tm_year = year - 1900;
  alarm->tm_mon = month - 1;
  alarm->tm_mday = day;

  char time[250];
  int hour;
  int minute;
  int second;
  
  printf("enter scheduled time (hh:mm:ss): ");
  scanf("%s", &time);
  sscanf(time, "%2d:%2d:%2d", &hour, &minute, &second);

  alarm->tm_hour = hour;
  alarm->tm_min = minute;
  alarm->tm_sec = second;

  printf("the year is: %4d\n", alarm->tm_year + 1900);
  printf("the month is: %2d\n", alarm->tm_mon + 1);
  printf("the day is: %2d\n", alarm->tm_mday);
  printf("the hour is: %2d\n", alarm->tm_hour);
  printf("the second is: %2d\n", alarm->tm_min);
  printf("the second is: %2d\n", alarm->tm_sec);

  time_t alarmTime = mktime(alarm);
  if (alarmTime - currentTime > 0) {
    printf("Scheduling alarm for: %s\n", ctime(&alarmTime));
        for (int i = 0; i < 10; i++) {
          if (alarms[i].PID == 0) {
            alarms[i].ringTime = alarmTime;
            alarms[i].PID = i + 1;
            break;
          }
        }
        printf("Scheduling alarm in %ld seconds\n", alarmTime - currentTime);
  } else {
    printf("Invalid input, try again. \n");
  }
}

void actionL() {                                              // Skal komme med en liste over alle alarmer 
  time_t currentTime;                                         // lager en variabel med currentTime               
  time(&currentTime);                                         // Setter tiden akkurat nå
  printf("Your alarms are set at: \n");
  for (int i = 0; i<10; i++){
    time_t alarmTime = alarms[i].ringTime;
    if (alarms[i].PID != 0) {
      printf("%i %s \n",alarms[i].PID ,ctime(&alarmTime));
    } 
  }
}

void actionC() {
  int index;
  printf("enter the number of the alarm you wish to cancel: \n");
  scanf("%i", &index);
  int deleted = 0;
  for (int i = 0; i < 10; i++) {
    if (alarms[i].PID == index) {
      alarms[i].PID = 0;
      alarms[i].ringTime = time(NULL);
      deleted = 1;
    }
  }
  if (deleted == 0) {
    printf("Alarm does not exist. \n");
  } else {
    printf("Alarm %i is deleted. ", index);
  }
}

void actionX() {
  
}

void menu() {
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
      printf("%s", "next input: ");
    } else if (action == 'l') {
      printf("your input = %c \nyou can display alarms \n" , action);
      actionL();
      printf("%s", "next input: ");
    } else if (action == 'c') {
      printf("your input = %c \nyou can cancel alarms \n" , action);
      actionC();
      printf("%s", "next input: ");
    } else {
      if (action != 'x') {
      printf("wrong bitch \n");
       }
     }
     
   }
}


//main
int main(){
  menu();
  printf("Compiled");
  return 0;
}
