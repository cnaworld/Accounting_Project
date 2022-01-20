#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#include<dos.h>
struct add_income {

    char user_login [50];
    char source [50];
    char amount[20];
    char description [200];
    char day [20];
    char month [20];
    char year [20];
    struct add_income *link ;

}; struct add_income inc ;

struct add_income *startInc , *endInc , *tempInc ;
void main()
{
    incomeLinkedList();
    int choice ;
    system("COLOR c");
    printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 1. Total income for a specified year   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 2. Total income for a period of time  ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 3. The amount of a certain type of income in a range  ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 4. The ratio of different incomes to each other  ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 5. Micro-revenues of a period   ");
	printf("\n\n");
    printf("                           \xDB\xDB\xDB\xDB\xB2 6. The largest income figure in a period   ");
	printf("\n\n");
    printf("                           \xDB\xDB\xDB\xDB\xB2 7.  specific word search in the income Description field   ");
	printf("\n\n");
    printf("                           \xDB\xDB\xDB\xDB\xB2 8.  Main Menu    ");
	printf("\n\n");
	printf("Please enter your choice : ");
	choice = getch();
	choice=toupper(choice);
    if ( choice == '1' )
    {
        int year ;
        int amount , sum = 0 ;
        int search ;
        printf("Please enter year : ") ;
        scanf("%d" , &year ) ;

        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            search = atoi(tempInc-> year) ;
            if( search == year ) //&& strcmp (tempInc->user_login , user_given ) == 0   )
            {
                printf("%s+" , tempInc->amount);
                amount = atoi(tempInc->amount) ;
                sum = amount + sum ;
            }
            tempInc = tempInc->link ;
        }
        printf("\n\n\nkol daramad sal %d : %d" ,  year , sum ) ;

    }

    if (choice == '7')
    {

    }





}
void incomeLinkedList ()
{
    FILE *fp ;
    fp = fopen ("income.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    //struct add_income *start , *end , *temp ;
    tempInc = malloc(sizeof(struct add_income));
    fread(&inc , sizeof(struct add_income ) , 1 , fp );
    strcpy(tempInc->user_login , inc.user_login ) ;
    strcpy(tempInc->source , inc.source ) ;
    strcpy(tempInc->amount , inc.amount ) ;
    strcpy(tempInc->description , inc.description ) ;
    strcpy(tempInc->day , inc.day ) ;
    strcpy(tempInc->month , inc.month ) ;
    strcpy(tempInc->year , inc.year ) ;
    tempInc->link = NULL;
    startInc = tempInc ;
    endInc = tempInc ;
    while (fread(&inc , sizeof (struct add_income )  , 1 , fp )==1)
    {
        tempInc = malloc(sizeof(struct add_income));
        tempInc->link = NULL;
        strcpy(tempInc->user_login , inc.user_login ) ;
        strcpy(tempInc->source , inc.source ) ;
        strcpy(tempInc->amount , inc.amount ) ;
        strcpy(tempInc->description , inc.description ) ;
        strcpy(tempInc->day , inc.day ) ;
        strcpy(tempInc->month , inc.month ) ;
        strcpy(tempInc->year , inc.year ) ;
        endInc->link = tempInc ;
        endInc = tempInc ;
    }
    fclose(fp);
   /* tempInc = startInc ;

    while ( tempInc != NULL )
    {
        if(strcmp( tempInc->user_login , "sina") == 0 )
        {
        printf("user : %s\n" , tempInc-> user_login ) ;
        printf("source : %s\n" , tempInc-> source ) ;
        printf("amount : %s\n" , tempInc-> amount ) ;
        printf("des : %s\n" , tempInc-> description ) ;
        printf("day : %s\n" , tempInc-> day ) ;
        printf("month : %s\n" , tempInc-> month ) ;
        printf("year : %s\n" , tempInc-> year ) ;
        printf("\n----------------------------\n");
        }
        tempInc = tempInc->link ;
    } */


}

