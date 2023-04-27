#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int c1=0,c2=0,c3=0,c4=0,c5=1; 
struct details{
    char name[50];
    int age;
    int voterid;
    char address[50];
    int c1,c2,c3,c4;
};

char raipur[4][20]={"KAMAL","HANSRAJ","B. K. PANDEY","AMIT SHAH"};
char sahebganj[4][20]={"RAUNAK","AMAN","RAM KUMAR","GULAB"};

void  login();
void vote(struct details v);
void displayresult(struct details v);
void registration(struct details v);
void update(struct details v);

void update(struct details v){
    FILE *fp1;
    char address[50];
    fp1=fopen("login.txt","w+");
    char line[50];
    printf("ENTER YOUR VOTER ID: ");
    int voterid;
    scanf("%d",&voterid);
    printf("ENTER THE UPDATED NAME: ");
    char name[50];
    scanf("%s",name);
    printf("ENTER THE UPDATED ADDRESS: ");
    scanf("%s",address);
while(fgets(line,50, fp1) != NULL){
    if (sscanf(line, "%d %s %d %s\n",&v.voterid,v.name,&v.age,v.address) == 4){
        if (v.voterid == voterid){
            strcpy(v.name,name);
            strcpy(v.address,address);
            fprintf(fp1,"%d %s %d %s",v.voterid,v.name,v.age,v.address);
            system("cls");
            break;
        }
    }
}
printf("DATABASE UPDATED SUCCESSFULLY");
printf("DO YOU WANT TO\n");
        printf("1. GIVE VOTE\n");
        printf("2. POSITIONS OF VOTING\n");
        printf("3 .UPDATE PROFILE \n");
        printf("4. ANOTHER REGISTRATION\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE\n"); 
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: vote(v);
            break;
            case 2: displayresult(v); break;
            case 3: update(v); break;
            case 4: main(); break;
            case 5: exit(0);
            default:
            printf("INVALID INPUT");
        }
}

void vote(struct details v)
{
    int vote1;
    if(strcmp(v.address,"raipur")==0){
    printf("ENTER YOUR VOTE:\n1. KAMAL \n2. HANSRAJ \n3. B. K. PANDEY \n4. AMIT SHAH\n"); }
    else if(strcmp(v.address,"sahebganj")==0){
        printf("ENTER YOUR VOTE:\n1. RAUNAK\n2. AMAN\n3. RAM KUMAR\n4. GULAB\n");
    }
    scanf("%d",&vote1);
    switch(vote1)
    {
        case 1:
            v.c1++;
            break;
        case 2:
            v.c2++;
            break;
        case 3:
            v.c3++;
            break;
        case 4:
            v.c4++;
            break;
        default:
            printf("WRONG CHOICE");
    }
    FILE *fp1;
    fp1=fopen("login.txt","a");
    fprintf(fp1,"%d %d %d %d",v.c1,v.c2,v.c3,v.c4);
    system("cls");
    printf("DO YOU WANT TO\n");
        printf("1. GIVE VOTE\n");
        printf("2. POSITIONS OF VOTING\n");
        printf("3. UPDATE PROFILE \n");
        printf("4. ANOTHER REGISTRATION\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE\n"); 
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: vote(v);
            break;
            case 2: displayresult(v); break;
            case 3: update(v); break;
            case 4: main(); break;
            case 5: exit(0);
            default:
            printf("INVALID INPUT");
        }
}

void displayresult(struct details v){
    FILE *fp1;
    fp1=fopen("login.txt","r");
    char line[50];
    while(fgets(line,50, fp1) != NULL){
    if (sscanf(line, "%d %d %d %d\n",&v.c1,&v.c2,&v.c3,&v.c4) == 4){

    if(strcmp(v.address,"raipur")==0){
        if(v.c1>v.c2 && v.c1>v.c3 && v.c1 >v.c4)
        {
            printf("%d LEADING",raipur[0]);}
        else if (v.c2>v.c3 && v.c2>v.c4 && v.c2 >v.c1)
        {
            printf("%d LEADING",raipur[1]);}
        else if(v.c3 >v.c4 && v.c3>v.c2 && v.c3 >v.c1)
        {
            printf("%d LEADING",raipur[2]);}
        else if(v.c4>v.c1 && v.c4>v.c2 && v.c4>v.c3)
        {
            printf("%d LEADING",raipur[3]);}
        else
            printf("Warning !!! No-win situation--");
        }
    
    else if(strcmp(v.address,"sahebganj")==0){
        if(v.c1>v.c2 && v.c1>v.c3 && v.c1 >v.c4)
        {
            printf("%d LEADING",sahebganj[0]);}
        else if (v.c2>v.c3 && v.c2>v.c4 && v.c2 >v.c1)
        {
            printf("%d LEADING",sahebganj[1]);}
        else if(v.c3 >v.c4 && v.c3>v.c2 && v.c3 >v.c1)
        {
            printf("%d LEADING",sahebganj[2]);}
        else if(v.c4>v.c1 && v.c4>v.c2 && v.c4>v.c3)
        {
            printf("%d LEADING",sahebganj[3]);}
        else
            printf("Warning !!! No-win situation--");
        }
}
    }
        printf("DO YOU WANT TO\n");
        printf("1. GIVE VOTE\n");
        printf("2. POSITIONS OF VOTING\n");
        printf("3. UPDATE PROFILE \n");
        printf("4. ANOTHER REGISTRATION\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE\n"); 
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: vote(v);
            break;
            case 2: displayresult(v); break;
            case 3: update(v); break;
            case 4: main(); break;
            case 5: exit(0);
            default:
            printf("INVALID INPUT");
        }
}

void registration (struct details v){
    system("cls");        
    FILE *log;
    log=fopen("login.txt","a");
    if(log==NULL){
        system("cls");
        printf("ERROR OPENING FILE\n");
        exit(1);
    }
        fprintf(log,"%d %s %d %s\n",v.voterid, v.name,v.age,v.address); fclose(log);
        system("CLS");
        printf("REGISTRATION SUCCESSFUL \nNOW PLEASE LOGIN\n");
        login();
}
void login(){
    int voterid;
    FILE *fp1;
    int flag=0;
    fp1=fopen("login.txt","r");
    struct details v;
    printf("ENTER VOTERID\n");
    scanf("%d",&voterid);
    
    if(fp1==NULL){
        system("cls");
        printf("ERROR OPENING FILE\n"); exit(1);
    }
    char line[50];
while(fgets(line,50, fp1) != NULL){
    if (sscanf(line, "%d %s %d %s\n",&v.voterid,v.name,&v.age,v.address) == 4){
        if (v.voterid == voterid){
            flag+=1;
            printf("YOU HAVE SUCCESSFULLY LOGGED IN");
            system("cls");
            break;
        }
    }
    else{
        printf("Error reading input data from the file.");
        
        }
}
    sleep(2);
    printf("%d",voterid);
    fclose(fp1); 
    if(flag==0){
        printf("YOU DO NOT HAVE AN ACCOUNT YET. \n REGISTER PLEASE\n");
    }
    else{
        system("cls");
        printf("DO YOU WANT TO\n");
        printf("1. GIVE VOTE\n");
        printf("2. POSITIONS OF VOTING\n");
        printf("3. UPDATE PROFILE \n");
        printf("4. ANOTHER REGISTRATION\n");
        printf("5. EXIT\n");
        printf("ENTER YOUR CHOICE\n"); 
        int choice;
        scanf("%d",&choice);
        switch(choice){
            case 1: vote(v);
            break;
            case 2: displayresult(v); break;
            case 3: update(v); break;
            case 4: main(); break;
            case 5: exit(0);
            default:
            printf("INVALID INPUT");
        }
}
}
int main(){
    system("cls");
    printf("************************************\n");
    printf("Welcome to the online voting system \n");
    printf("************************************\n");
    printf("1.REGISTER\n");
    printf("2.LOGIN\n");
    printf("3.UPDATE PROFILE \n");
    printf("4.GIVE VOTE\n");
    printf("5.DISPLAY RESULT\n");
    int choice;
    struct details v;
    int age;
    printf("ENTER YOUR CHOICE \n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
    system("cls");
        printf("\tWELCOME TO REGISTRATION\n");
        printf("PLEASE ENTER YOUR NAME: ");
        scanf("%s",v.name);
        printf("ENTER YOUR ADDRESS: ");
        scanf("%s",v.address);
        printf("ENTER YOUR AGE: ");
        scanf("%d",&age);
        getchar();
        if(age>=18){
            v.age=age;
        }
        else{
            printf("You are not yet eligible for voting");
            exit(0);
        }
        srand(time(0));
        int voterid=rand()%1000+1;
        v.voterid=voterid;
        printf("THE DATE ON WHICH YOU HAVE TO VOTE IS 15 AUGUST 2023,TUESDAY");
        printf("\nHERE IS OUR UNIQUE THREE DIGIT VOTERID: %d",voterid);
        sleep(3);
        registration (v);
        break;
    case 2:
        login();
    break;
    case 3:
        update(v);
    break;
    case 4: 
        vote(v);
        break;
    case 5:
        displayresult(v);
        break;
    default:
        printf("WRONG CHOICE INPUT");
    }
}