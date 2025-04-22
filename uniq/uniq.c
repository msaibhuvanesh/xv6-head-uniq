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

void pipeFlag(char *argv[]){
   char buffer1[1024];
    char buffer2[1024];
    char temp[1024];
   
    int x=0;
    int i=0;
    int fd = 0;
    printf(1,"unique command is getting executed in user mode\n");
     while (read(fd, buffer1, sizeof(buffer1)) > 0)
   {
        while(buffer1[x]!='\0')
        { 
          if(buffer1[x]!='\n') {
             temp[i]=buffer1[x];
             i++;
            }   
           else {
            temp[i]='\0';
             if(strcmp(buffer2,temp)!=0) {
             
                 if(buffer2[0]!='\0'){
                   printf(1,"%s\n",buffer2);
                 }
                  strcpy(buffer2,temp);
                 i=0;
                 emptyString(temp);
               }  
               else {
                  emptyString(temp);
                  i=0;
               }
         }
         ++x;
        }

        printf(1,"%s\n",buffer2);
        if(strcmp(buffer2,temp)!=0 &&  temp[0]!='\0') {
         printf(1,"%s\n",temp);  
        }
       		  
          sbrk(-1024);
    }

}

void noFlag(char *argv[]){
   char buffer1[1024];
    char buffer2[1024];
    char temp[1024];
   
    int x=0;
    int i=0;
   

 
    char *n = argv[1];
    int fd = open(n, O_RDONLY);
    if (fd < 0) {
        printf(2, "Error opening file: %s\n", n);
        exit();
    }


    printf(1,"unique command is getting executed in user mode\n");
     while (read(fd, buffer1, sizeof(buffer1)) > 0)
   {
       

        while(buffer1[x]!='\0')
        { 
          if(buffer1[x]!='\n') {
             temp[i]=buffer1[x];
             i++;
            }   
           else {
            temp[i]='\0';
             if(strcmp(buffer2,temp)!=0) {
                 if(buffer2[0]!='\0'){
                   printf(1,"%s\n",buffer2);
                 }
                  strcpy(buffer2,temp);

                 i=0;
                 emptyString(temp);
               }  
               else {
                  emptyString(temp);
                  i=0;
               }
         }
         ++x;
        }

        printf(1,"%s\n",buffer2);
        if(strcmp(buffer2,temp)!=0 &&  temp[0]!='\0') {
         printf(1,"%s\n",temp);  
        }
       		  
          sbrk(-1024);
    }

}

void countFlag(char *argv[]){
   char buffer1[1024];
    char buffer2[1024];
    char temp[1024];
   
    int x=0;
    int i=0;
  
    int count=0;
    char *n = argv[2];
    int fd = open(n, O_RDONLY);
    if (fd < 0) {
        printf(2, "Error opening file: %s\n", n);
        exit();
    }


    printf(1,"unique command is getting executed in user mode\n");
     while (read(fd, buffer1, sizeof(buffer1)) > 0)
   {
       
        while(buffer1[x]!='\0')
        {

          if(buffer1[x]!='\n') {
             temp[i]=buffer1[x];
             i++;
            }   
           else {
            temp[i]='\0';
             if(strcmp(buffer2,temp)!=0) {
                 if(buffer2[0]!='\0'){
                   printf(1,"%d %s\n",count,buffer2);
                 }
                  strcpy(buffer2,temp);
      
                 i=0;
                 count=1;
                 emptyString(temp);
               }  
               else {
                  count++;
                  emptyString(temp);
                  i=0;
               }
         }
         ++x;
        }

        printf(1,"%d %s\n",count, buffer2);
        if(strcmp(buffer2,temp)!=0 && temp[0]!='\0') {
         printf(1,"1 %s\n",temp);  
        }
       		  
          sbrk(-1024);
    }

}


void duplicateFlag(char *argv[]){
   char buffer1[1024];
    char buffer2[1024];
    char temp[1024];
   
    int x=0;
    int i=0;
   

    int count=0;
    char *n = argv[2];
    int fd = open(n, O_RDONLY);
    if (fd < 0) {
        printf(2, "Error opening file: %s\n", n);
        exit();
    }


    printf(1,"unique command is getting executed in user mode\n");
   
     while (read(fd, buffer1, sizeof(buffer1)) > 0)
   {
        

        while(buffer1[x]!='\0')
        { 
               

          if(buffer1[x]!='\n') {
             temp[i]=buffer1[x];
             i++;
            }   
           else {
            temp[i]='\0';
             if(strcmp(buffer2,temp)!=0) {
                 if(buffer2[0]!='\0'){
                    if(count>1)
                   printf(1,"%s\n",buffer2);
                 }
                  strcpy(buffer2,temp);

                 i=0;
                 count=1;
                 emptyString(temp);
               }  
               else {
                  count++;
                  emptyString(temp);
                  i=0;
               }
         }
         ++x;
        }


        if(count>1)
        printf(1,"%s\n", buffer2);
        if(strcmp(buffer2,temp)!=0 && temp[0]!='\0') {
         printf(1,"%s\n",temp);  
        }
       		  
          sbrk(-1024);
    }

}

void toLowerCase(char *str){
    int i=0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }

}

void ignoreFlag(char *argv[]){
   char buffer1[1024];
    char buffer2[1024];
    char temp[1024];
   
    int x=0;
    int i=0;

    char *n = argv[2];
    int fd = open(n, O_RDONLY);
    if (fd < 0) {
        printf(2, "Error opening file: %s\n", n);
        exit();
    }


    printf(1,"unique command is getting executed in user mode\n");
 
     while (read(fd, buffer1, sizeof(buffer1)) > 0)
   {
        
        toLowerCase(buffer1);
        while(buffer1[x]!='\0')
        { 
          if(buffer1[x]!='\n') {
             temp[i]=buffer1[x];
             i++;
            }   
           else {
            temp[i]='\0';
             if(strcmp(buffer2,temp)!=0) {
                 if(buffer2[0]!='\0'){
                   printf(1,"%s\n",buffer2);
                 }
                  strcpy(buffer2,temp);
                 i=0;
                 emptyString(temp);
               }  
               else {
                  emptyString(temp);
                  i=0;
               }
         }
         ++x;
        }


        printf(1,"%s\n", buffer2);
        if(strcmp(buffer2,temp)!=0 && temp[0]!='\0') {
         printf(1,"%s\n",temp);  
        }
       		  
          sbrk(-1024);
    }

}


int main(int argc,char *argv[])
{
    if(argc==1) {
       pipeFlag(argv);
    }else if(argc<=2) {
        noFlag(argv);
    } else if(argc==3) {
    
    switch(argv[1][1])
    {
        case 'c':
            countFlag(argv);
            break;
        case 'd':
            duplicateFlag(argv);
            break;
        case 'i':
            ignoreFlag(argv);
            break;
        default:
            printf(1,"Error! operator is not correct");
    }

   }

    
    exit();
}



