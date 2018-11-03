#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[])
{
  FLIE* fd;
  int n;  
  char buf[100];
  char temp[6];
  
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
  temp[4] = buf[n-1];
  temp[3] = buf[n-2];
  temp[2] = buf[n-3];
  temp[1] = buf[n-4];
  temp[0] = buf[n-5];
  
  printf("Temperature is '%s' C\n", temp/1000); 

  (void)fclose(fd);
}
