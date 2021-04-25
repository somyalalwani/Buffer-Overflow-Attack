## System and Network Security

## A Practical Ethical hacking: Buffer-overflow attack

### Stack overflow

**stack.c**
```
//This program has a buffer overflow vulnerability
//The task is to exploit this vulnerability
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int bof(char *str)
{
char buffer[64];
strcpy(buffer,str);
return 1;
}
int main(int argc, char **argv)
{
char str[517];
FILE * malfile;
malfile = fopen("malfile", "r");
fread(str, sizeof(char), 517, malfile); bof(str);
printf("Returned Properly\n");
return 1;
}
```

- What is Stack guard? What is ASLR protection?

- Perform a stack overflow attack on the stack.c and launch shell as root under when Stack is executable stack and ASLR is turned off.

- Perform a stack overflow attack on the stack.c and launch shell as root and perform seteuid() under when Stack is executable stack and ASLR is turned off.

- Perform a stack overflow attack on the stack.c and kill all processes when Stack is executable stack and ASLR is turned off. It is a kind of Denial of Service attack.

- Perform a stack overflow attack on the stack.c and reboot the system when Stack is executable stack and ASLR is turned off.

- Now turn on ASLR and perform all the tasks from 2 to 5.

- Turn on a non-executable stack . Perform any ret2libc attack.


### Heap overflow

**heap1.c**

```
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct data {
char name[64];
};

struct fp {
int (*fp)();
};

void executeShell()
{
char *name[2];
name[0] = "/bin/sh";
name[1] = NULL;
execve(name[0],name,NULL);
}

void Failed()
{
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

```
- Exploit the heap and try to execute executeShell function to launch a shell.
