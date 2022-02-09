//Unix based alarm clock
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//variables


//structs
struct alarm {
  int alarmId;
  int PID; 
  time_t ringTime;
};

struct alarm alarms[10];

//methods
void actionS() {
  struct tm *alarmTime;
  printf("When should the alarm go off? (format: yyyy-mm-dd hh:mm:ss): ");
  scanf("%s", alarmTime);
  time_t rawTime = mktime(&alarmTime);
  for (int i = 0; i < 10; i++) {
    if (alarms[i].alarmId == NULL) {
      alarms[i].alarmId = i + 1;
      alarms[i].ringTime = rawTime;

      break;
    }
  }
  printf("alarm goes off %s: ", rawTime);
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
