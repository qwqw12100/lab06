int main (int argc, char *argv[])
{
  FLIE* fd
  int n;  
  fd = fopen("/sys/bus/w1/devices/28-021313ce22aa/w1_slave","r");
  char buf[sizeof(/sys/bus/w1/devices/28-021313ce22aa/w1_slave)];  

  if(fd == (FILE *)NULL) { 
    perror("open failed"); 
    (void) exit(1);  
  } 

  n = fread(buf, 1, 100, fd); 

  if(n == 0) { 
    perror("read fails!"); 
    exit(1); 
  } 

  buf[n] = '\0'; 
  fprintf(stdout, "Read '%s'\n", buf); 

  (void)fclose(fd);
}
