#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ifttt.h"
#include "time.h"
int main (int argc, char *argv[])
{
  FILE *fd;
  int n;  
  char buf[100];
  char temp[6];
  double tempe; 
  double temp_max;
  double temp_min;
  double temp_now;
  int i = 0;
  char maxtemp[100];
  char mintemp[100];
  char newtemp[100];
  time_t ts;

while(1){  

  fd = fopen("/sys/bus/w1/devices/28-021313ce22aa/w1_slave","r"); 
 
    if(fd == NULL) { 
    perror("open failed"); 
    (void) exit(1);  
  } 
  
  n = fread(buf, 1, 100, fd); 
  
  if(n == 0) { 
    perror("read fails!"); 
    exit(1); 
  } 

  temp[5] = '\0';
  temp[4] = buf[n-2];
  temp[3] = buf[n-3];
  temp[2] = buf[n-4];
  temp[1] = buf[n-5];
  temp[0] = buf[n-6];
  (void)fclose(fd);
  tempe = atof(temp);
  tempe = tempe/1000;  
printf("temp is %.3f\n", tempe);
   for(i ;i<1;i++ ){
	  double temp_max = tempe; 
	  double temp_min = tempe;
	  double temp_now = tempe;
	  sprintf(newtemp,"Current temperature is %g", temp_now);
	  sprintf(maxtemp,"Max temperature is %g", temp_max);
	  sprintf(mintemp,"Min temperature is %g", temp_min);
	  ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/dImUb3e_p6ayih5X2iy8RE", newtemp, maxtemp, mintemp);

   }

   if(tempe < temp_min){
		temp_min = tempe;
   }
	
   if(tempe > temp_max){
		temp_max = tempe;
   }
   
   if(abs(temp_now - tempe) > 1){
	  sprintf(newtemp,"Current temperature is %g", temp_now);
	  sprintf(maxtemp,"Max temperature is %g", temp_max);
	  sprintf(mintemp,"Min temperature is %g", temp_min);
	  ifttt("https://maker.ifttt.com/trigger/alarm_triggered/with/key/dImUb3e_p6ayih5X2iy8RE", newtemp, maxtemp, mintemp);
	  temp_now = tempe;
   }
   
   ts = time(NULL);
   while(difftime(time(NULL), ts)< 1.00);

}  

return 0;
}
