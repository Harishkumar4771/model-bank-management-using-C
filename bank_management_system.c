#include<stdio.h>
#include<string.h>
#include<time.h>
char name[50];
int accno,balance=10000,depo;
void menu();void deposit_money();void withdraw_money();void account_details();void transaction_details();void transfer_money();
int main(){
    int choice;
    printf("Enter username:");
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';
    printf("Enter accound number:");
    scanf("%d",&accno); 
    menu();
    printf("Enter choice");
    scanf("%d",&choice);
    switch (choice){
        case 1:
            deposit_money();
            break;
        case 2:
            withdraw_money();
            break;
        case 3:
            account_details();
            break;
        case 4:
            transaction_details();
            break;
        case 5:
            transfer_money();
            break; 
        case 6:
            printf("Exiting...");
            exit(0);
        default:
            printf("Invalid Case");
            break;    
    }
}
void menu(){
    printf("AVAILABLE OPTIONS");
    printf("\nPRESS THE REPECTIVE NUMBERS TO PERFORM SPECIFIC OPERATION");
    printf("\n1.Deposit money");
    printf("\n2.Withdraw money");
    printf("\n3.Check account details");
    printf("\n4.Check transaction details");
    printf("\n5.Transfer Money");
    printf("\n6.EXIT");
}
void deposit_money(){
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");
    printf("Enter the amount needed to be deposited in your account:");
    scanf("%d",&depo);
    balance+=depo;
    printf("Money deposired");
    printf("\nCurrent bank balance:%d",balance);
    fprintf(ptr,"Rs%d has been successfully deposited to your bank on %s . Current bank balance is %d",depo,ctime(&tm),balance);
}
