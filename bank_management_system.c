#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
char name[50];
int accno,balance=10000,depo,trans;
void menu();void deposit_money();void withdraw_money();void account_details();void transaction_details();void transfer_money();
int main(){
    int choice;
    printf("Enter username:");
    fgets(name,sizeof(name),stdin);
    name[strlen(name)-1]='\0';
    printf("Enter accound number:");
    scanf("%d",&accno); 
    while (1){
        menu();
        printf("\nEnter choice");
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
}
void menu(){
    printf("\nAVAILABLE OPTIONS");
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
    printf("Money deposited");
    printf("\nCurrent bank balance:%d",balance);
    fprintf(ptr,"Rs%d has been successfully deposited to your bank on %s . Current bank balance is %d",depo,ctime(&tm),balance);
    fclose(ptr);
    printf("\nPress any key to continue");
    getchar();
}
void withdraw_money(){
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");
    printf("Enter the amount needed to be withdrawn in your account:");
    scanf("%d",&depo);
    if (depo>balance){
        printf("Your bank balance is insufficient for the withdrawal");
        return;
    }
    balance-=depo;
    printf("Money withdrawn");
    printf("\nCurrent bank balance:%d",balance);
    fprintf(ptr,"Rs%d has been successfully withdrawn from your bank on %s . Current bank balance is %d",depo,ctime(&tm),balance);
    fclose(ptr);
    printf("\nPress any key to continue");
    getchar();
}
void account_details(){
    printf("Username:%s",name);
    printf("Account balance:%d",balance);
}
void transfer_money(){
    time_t tm;
    time(&tm);
    FILE *ptr=fopen("Account.txt","a");
    printf("Enter the amount needed to be transferred from your account:");
    scanf("%d",&trans);int ac;
    printf("\nEnter the account number of the receviver:");
    scanf("%d",&ac);
    if(depo>balance){
        printf("Your bank balance is insufficient for the withdrawal");
        return;
    }
    balance-=trans;
    printf("Transaction successful");
    printf("\nCurrent bank balance:%d",balance);
    fprintf(ptr,"Rs%d has  successfully transferred from your bank account to %d on %s . Current bank balance is %d",trans,ac,ctime(&tm),balance);
    fclose(ptr);
    printf("\nPress any key to continue");
    getchar();
}
void transaction_details(){
    FILE *ptr=fopen("Account.txt","r");
    char c=getc(ptr);
    if (c==EOF){
        printf("No transaction done");
        return;
    } 
    printf("TRANSACTION DETAILS");
    while (c!=EOF){
        printf("%c",c);
        c=getc(ptr);
    }

    
}