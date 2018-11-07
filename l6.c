#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
  FILE *fd;
  int n;  
  char buf[100];
  char temp[6];
  double tempe;
/*  double temp_max;
  double temp_min;
  double temp_now;
  int i;
  char maxtemp[100];
  char mintemp[100];
  char newtemp[100];
*/
  
  
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
   tempe = atof(temp); 
   (void)fclose(fd);
   printf("Current temperature is %f", tempe);
	
}
return 0;
}
