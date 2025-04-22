#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

void emptyString(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = '\0';
    }
}

void zerocase(char *argv[])
{
  printf(1,"head command is running in user mode\n");
  int i;
  char buffer[1024];
 
  for(i=0;i<14;i++)
  {
      read(0,buffer,sizeof(buffer));
      printf(1,"%s",buffer);
  }
  exit();
}

void firstcase(int y,char *argv[])
{
   printf(1,"head command is running in user mode\n");
  char buffer[1024];
  char temp[1024];
  int i=0;
  int z=0;
  char *a=argv[1];
  int fp=open(a,O_RDONLY);
  if (fp < 0) {
        printf(2, "Error opening file: %s\n", a);
        exit();
    }
  while(read(fp,buffer,sizeof(buffer))>0)
  {
    while(buffer[z]!='\0' && y!=0)
        { 
          if(buffer[z]!='\n') {
             temp[i]=buffer[z];
             i++;
            }  
            else
            {
              printf(1,"%s\n",temp);
              emptyString(temp); 
              i=0;
              y--;
            }
            z++;        
       }
  }
}

void secondcase(char *argv[])
{
   printf(1,"head command is running in user mode\n");
  char buffer[1024];
  char temp[1024];
  int l=atoi(argv[2]);
  int i=0;
  int z=0;
  char *a=argv[3];
  int fp=open(a,O_RDONLY);
  if (fp < 0) {
        printf(2, "Error opening file: %s\n", a);
        exit();
    }
  while(read(fp,buffer,sizeof(buffer))>0)
  {
    while(buffer[z]!='\0' && l!=0)
        { 
          if(buffer[z]!='\n') {
             temp[i]=buffer[z];
             i++;
            }  
            else
            {
              printf(1,"%s\n",temp);
              emptyString(temp); 
              i=0;
              l--;
            }
            z++;        
       }
  }
}


void thirdcase(int g,char *argv[],int a1,int a2)
{
   printf(1,"head command is running in user mode\n");
  char buffer[100];
  char buffer2[100];
  char temp[100];
  char temp2[100];
  char *a=argv[a1];
  char *b=argv[a2];
  int z=0;
  int m=0;
  int k=g;
  int i=0;
  int y=0;
  int fp=open(a,O_RDONLY);
  int fd=open(b,O_RDONLY);
  if (fp < 0) {
        printf(2, "Error opening file: %s\n", a);
        exit();
    }
  if (fd < 0) {
        printf(2, "Error opening file: %s\n", b);
        exit();
    }
 
  while(read(fp,buffer,sizeof(buffer))>0)
  {printf(1,"%s \n",argv[a1]);
    while(buffer[z]!='\0' && g!=0)
        { 
          if(buffer[z]!='\n') {
             temp[i]=buffer[z];
             i++;
            }  
            else
            {
              printf(1,"%s\n",temp);
              emptyString(temp); 
              i=0;
              g--;
            }
            z++;        
       }
  }
  while(read(fd,buffer2,sizeof(buffer2))>0)
  {
    printf(1,"%s \n",argv[a2]);
   
    while(buffer2[m]!='\0' && k!=0)
        { 
          if(buffer2[m]!='\n') {
             temp2[y]=buffer2[m];
             y++;
            }  
            else
            {
              printf(1,"%s\n",temp2);
              emptyString(temp2); 
              y=0;
              k--;
            }
            m++;        
       }
  }
}


int main(int argc,char *argv[])
{
  int x;
  
  if(argc==1)
  {
    zerocase(argv);
  }
    if(argc==2) 
    {
      x=14;
      firstcase(x,argv);
    }
    if(argc==4)
    {
      if(argv[1][0]=='-')
      {
        secondcase(argv);
      }
    }
     if(argc==3)
    {
       int s=14;
       thirdcase(s,argv,1,2);
    }
    if(argc==5)
    {
       int s=atoi(argv[2]);
       thirdcase(s,argv,3,4);
    }
    exit();
   
   }

    
   




