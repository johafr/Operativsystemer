//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>

//defines

//variables

//alarm struct som skal brukes i array
struct alarm {
  int alarmId;
  pid_t PID; 
  time_t ringTime;
};

//har en array som har plass til 10 structs (alarm)
struct alarm alarms[10];


//methods
void cancelAlarm(int index);

void actionS() {
  time_t currentTime;
  time(&currentTime);
  
  struct tm alarm;
  
  char date[250];
  int year;
  int month;
  int day;

  printf("enter scheduled date (YYYY-MM-DD): ");
  scanf("%s", date);
  sscanf(date, "%4d-%2d-%2d", &year, &month, &day);

  alarm.tm_year = year - 1900;
  alarm.tm_mon = month - 1;
  alarm.tm_mday = day;

  char timeOfDay[250];
  int hour;
  int minute;
  int second;
  
  printf("enter scheduled time (hh:mm:ss): ");
  scanf("%s", timeOfDay);
  sscanf(timeOfDay, "%2d:%2d:%2d", &hour, &minute, &second);

  alarm.tm_hour = hour;
  alarm.tm_min = minute;
  alarm.tm_sec = second;

  time_t alarmTime = mktime(&alarm);
  if (alarmTime - currentTime > 0) {
    struct alarm currentAlarm;
    printf("Scheduling alarm for: %s\n", ctime(&alarmTime));
        int index = 0;
        for (int i = 0; i < 10; i++) {
          if (alarms[i].alarmId == 0) {
            alarms[i].ringTime = alarmTime;
            alarms[i].alarmId = i + 1;
            index = i + 1;
            currentAlarm = alarms[i];
            break;
          }
        }
        //updates time
        time(&currentTime);
        time_t secondsLeft = alarmTime - currentTime;
        printf("Scheduling alarm in %ld seconds\n", secondsLeft);
        
        int forked = fork();
        //fork child
        if (forked == 0) {
          currentAlarm.PID = forked;
          printf("Child PID: %i\n", currentAlarm.PID);
          sleep(secondsLeft);
          printf("Ring!\n");
          cancelAlarm(index);
          printf("next input: ");
          exit(EXIT_SUCCESS);
        } else {
          currentAlarm.PID = forked;
          printf("parent PID: %i\n", currentAlarm.PID);
        }
  } else {
    printf("Invalid input, try again. \n");
  } 
}



void actionL() {                                              // Skal komme med en liste over alle alarmer 
  time_t currentTime;                                         // lager en variabel med currentTime               
  time(&currentTime);                                         // Setter tiden akkurat nå
  printf("Your alarms: \n");
  int num = 0;
  for (int i = 0; i<10; i++){
    time_t alarmTime = alarms[i].ringTime;
    if (alarms[i].ringTime - currentTime > 0) {
      printf("%i %s \n",alarms[i].alarmId ,ctime(&alarmTime));
      num++;
    } 
  }
  if (num == 0) {
    printf("You currently don't have any alarms set: \n");
  }
}


void cancelAlarm(int index) {
  for (int i = 0; i < 10; i++) {
    if (alarms[i].alarmId == index) {
      alarms[i].alarmId = 0;
      alarms[i].ringTime = time(NULL);
    }
  }
}

void actionC() {
  int index;
  printf("PID of first alarm: %i\n", alarms[0].PID);
  printf("enter the number of the alarm you wish to cancel: \n");
  scanf("%i", &index);
  int deleted = 0;
  for (int i = 0; i < 10; i++) {
    printf("PID alarm: %i + i = %i \n", alarms[i].PID, i);
    if (alarms[i].alarmId == index) {
      printf("PID of process = %i\n",alarms[i].PID);
      int test = kill(/*PID of child process alarm*/ alarms[i].PID, 0);
      alarms[i].alarmId = 0;
      alarms[i].ringTime = time(NULL);
      deleted = 1;
      printf("kill input = %i\n", test);
    }
  }
  if (deleted == 0) {
    printf("Alarm does not exist. \n");
  } else {
    printf("Alarm %i is deleted. ", index);
  }
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
      printf("wrong input \n");
       }
     }
     
   }
}


//main
int main(){
  menu();
  printf("Compiled\n");
  return 0;
}
