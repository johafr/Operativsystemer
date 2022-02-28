//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

//alarm struct som skal brukes i array
struct alarm {
  int alarmId;
  pid_t PID; 
  time_t ringTime;
} newAlarm;

//har en array som har plass til 10 structs (alarm)
struct alarm alarms[10];


//methods
void cancelAlarm(int index);

int getNumAlarms() {
  time_t currentTime;                                                       
  time(&currentTime);                                         
  int num = 0;
  for (int i = 0; i<10; i++){
    time_t alarmTime = alarms[i].ringTime;
    if (alarms[i].ringTime - currentTime > 0) {
      num++;
    } 
  }
  return num;
}

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
    printf("Scheduling alarm for: %s\n", ctime(&alarmTime));
    time(&currentTime); //updates the time
    time_t secondsLeft = alarmTime - currentTime;
    printf("Scheduling alarm in %ld seconds\n", secondsLeft);
        int index = 0;
        for (int i = 0; i < 10; i++) {
          if (alarms[i].alarmId == 0) {
            alarms[i].ringTime = alarmTime;
            alarms[i].alarmId = i + 1;
            index = i + 1;

            int forked = fork();
            if (forked == 0) {  //fork child
              alarms[i].PID = forked;
              sleep(secondsLeft);
              printf("Ring!\n");
              cancelAlarm(index);
              printf("next input: ");
              exit(EXIT_SUCCESS);
            } else {
              alarms[i].PID = forked;
            }

            break;
          }
        }
        
        
  } else {
    if (getNumAlarms() == 10) {
      printf("Too many alarms, remove one to add another");
    } else {
      printf("Invalid input, try again. \n");
    }
  } 
}



void actionL() {                                              
  time_t currentTime;                                                       
  time(&currentTime);                                         
  printf("Your alarms: \n\n");
  int num = 0;
  for (int i = 0; i<10; i++){
    time_t alarmTime = alarms[i].ringTime;
    if (alarms[i].ringTime - currentTime > 0) {
      printf("%i %s \n",alarms[i].alarmId ,ctime(&alarmTime));
      num++;
    } 
  }
  if (num == 0) {
    printf("You currently don't have any alarms set: \n\n");
  }
}


void cancelAlarm(int index) {
  for (int i = 0; i < 10; i++) {
    if (alarms[i].alarmId == index) {
      alarms[i].alarmId = 0;
      alarms[i].ringTime = time(NULL);
      //trenger å slette alarmen i parent forken
    }
  }
}

void actionC() {
  int index;
  printf("PID of first alarm: %i\n", alarms[0].PID);
  printf("enter the number of the alarm you wish to cancel: \n");
  scanf("%i", &index);
  int deleted = -1;
  for (int i = 0; i < 10; i++) {
    if (alarms[i].alarmId == index) {
      alarms[i].alarmId = 0;
      alarms[i].ringTime = time(NULL);
      deleted = 1; 
      kill(alarms[i].PID, SIGKILL);
    }
  }
  if (deleted == -1) {
    printf("Alarm does not exist. \n");
  } else {
    printf("Alarm %i is deleted. \n", index);
  }
}

void catchZombies() {
  pid_t PID = waitpid(-1, NULL, WNOHANG);
  if (PID == 0) {
    return;
  }
  int index = -1;
  for (int i = 0; i < getNumAlarms(); i++) {
    if (alarms[i].PID == PID) {
      index = i;
      break;
    }
  }  
  if (index==-1) {
    return;
  }
  alarms[index].alarmId = 0;
  alarms[index].ringTime = time(NULL);
  kill(alarms[index].PID, SIGKILL);
}

void menu() {
  time_t rawTime;
  struct tm *timeinfo;
  time (&rawTime);
  timeinfo = localtime (&rawTime);
  
  
  char action;
  printf("Welcome to the alarm clock! It is currently %s . Please enter 's' (schedule), 'l' (list), 'c' (cancel), 'x' (exit) \n", asctime (timeinfo));
 
  while (action != 'x') {
    //makes sure there are no zombies before new input.
    catchZombies();
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

int main(){
  menu();
  printf("Compiled\n");
  return 0;
}