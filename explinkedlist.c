#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#include<dos.h>
void main ()
{
    struct add_expenses {

    char user_login [50];
    char source [50];
    char amount[20];
    char description [200];
    char day[20] ;
    char month [20];
    char year [20];
    struct add_expenses *link ;

}; struct add_expenses exp ;

struct add_expenses *startExp , *endExp , *tempExp ;

    FILE *fp ;
    fp = fopen ("expenses.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    // struct add_expenses *startExp , *endExp , *tempExp ;
    fread(&exp , sizeof(struct add_expenses ) , 1 , fp );
    strcpy(tempExp->user_login , exp.user_login ) ;
    strcpy(tempExp->source , exp.source ) ;
    strcpy(tempExp->amount , exp.amount ) ;
    strcpy(tempExp->description , exp.description ) ;
    strcpy(tempExp->day , exp.day ) ;
    strcpy(tempExp->month , exp.month ) ;
    strcpy(tempExp->year , exp.year ) ;
    tempExp->link = NULL;
    startExp = tempExp ;
    endExp = tempExp ;
    while (fread(&exp , sizeof (struct add_expenses )  , 1 , fp )==1)
    {
        tempExp = malloc(sizeof(struct add_expenses));
        tempExp->link = NULL;
        strcpy(tempExp->user_login , exp.user_login ) ;
        strcpy(tempExp->source , exp.source ) ;
        strcpy(tempExp->amount , exp.amount ) ;
        strcpy(tempExp->description , exp.description ) ;
        strcpy(tempExp->day , exp.day ) ;
        strcpy(tempExp->month , exp.month ) ;
        strcpy(tempExp->year , exp.year ) ;
        endExp->link = tempExp ;
        endExp = tempExp ;
    }
    tempExp = startExp ;

    while ( tempExp != NULL )
    {
        if(strcmp( tempExp->user_login , "hossein") == 0 )
        {
        printf("user : %s\n" , tempExp-> user_login ) ;
        printf("source : %s\n" , tempExp-> source ) ;
        printf("amount : %s\n" , tempExp-> amount ) ;
        printf("des : %s\n" , tempExp-> description ) ;
        printf("day : %s\n" , tempExp-> day ) ;
        printf("month : %s\n" , tempExp-> month ) ;
        printf("year : %s\n" , tempExp-> year ) ;
        printf("\n----------------------------\n");
        }
        tempExp = tempExp->link ;
    }

}
