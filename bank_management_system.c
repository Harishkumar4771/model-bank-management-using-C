#include<stdio.h>
#include<string.h>
char name[50];
int accno,balance=10000,depo;
void menu();
int main(){
    printf("Enter username:");
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';
    printf("Enter accound number:");
    scanf("%d",&accno);
    printf("%s",name);
    printf("%d",accno);
}