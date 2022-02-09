//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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



int main() {

  printf("Compiled");
  return 0;
}
