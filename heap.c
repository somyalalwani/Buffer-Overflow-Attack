#include <stdlib.h> 

#include <unistd.h> 

#include <string.h> 

#include <stdio.h> 

#include <sys/types.h> 

  

struct data { 

  char name[64]; 

}; 

  

struct fp { 

  int (*fp)(); 

}; 

  

void executeShell(){ 

char *name[2]; 

name[0] = "/bin/sh"; 

name[1] = NULL; 

printf("Success");   

execve(name[0],name,NULL); 

} 

  

void Failed(){ 

printf("You failed to exploit the heap \n"); 

} 

  

int main(int argc, char **argv) 

{ 

  struct data *d; 

  struct fp *f; 

  

  d = malloc(sizeof(struct data)); 

  f = malloc(sizeof(struct fp)); 

  f->fp = Failed; 

  strcpy(d->name, argv[1]); 

  f->fp(); 

  

} 