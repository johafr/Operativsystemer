//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct alarm {
  int alarmId;
  int PID; //Stod at vi kunne trenge det i oppgaven
  struct alarm *next;
}alarm;

alarm *createAlarm(int alarmId) {
  alarm *newAlarm = malloc(sizeof(alarm));
  newAlarm -> alarmId = alarmId;
  newAlarm -> next = NULL;
  return newAlarm;
}

char* menu() {
  return "Welcome to the alarm clock! It is currently 'insert time'. Please enter 's' (schedule), 'l' (list), 'c' (cancel), 'x' (exit) \n";
}

int main(){
  char action; 
  
  while (action != 'x') {
    printf(menu());
    scanf(" %c", &action); 

    
    if (action == 's') {
      printf("your input = %c \nyou can schedule an alarm \n", action);
    } else if (action == 'l') {
      printf("your input = %c \nyou can display alarms \n" , action);
    } else if (action == 'c') {
      printf("your input = %c \nyou can cancel alarms \n" , action);
    } else {
      if (action != 'x') {
      printf("wrong bitch \n");
      }
    }
  }
  
  
  printf("Compiled");
  return 0;
}
