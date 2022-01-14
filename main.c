#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#include<dos.h>
char user_given [50];
struct sign_up {

    char first_name [50];
    char last_name [50];
    char national_code[50] ;
    char phone_number [50];
    char mail [50];
    char username [50];
    char password [50];
    char re_password [50];


}; struct sign_up std ;


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




void main ()
{
    int choice ;
    system("COLOR a");
    printf("\n");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                   WELCOME TO                    *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *           | Sina Accounting Soft-ware |         *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 1. Sign Up!   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 2. Login   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 3. Exit   ");
	printf("\n\n");
	printf("Please enter your choice : ");
	choice = getch();
	choice=toupper(choice);
	switch(choice)
	{
        case '1':
            system("COLOR b");
            system("cls");
            signup();
            break;
        case '2':
            system("COLOR b");
            system("cls");
            login();
            break;
        case '3':
            system("COLOR b");
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *         | Thank You For using the app |         *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            Sleep(3000);
            exit(0);
            break;

	}
	/* if ( choice != 3 || choice != 2 || choice != 1  || choice != 0x0A )
    {
                    MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
                    system("cls");
                    main();
    } */
}

void signup ()
{
    char choice ;
    FILE *fp ;
    fp = fopen("profiles.txt" , "a+") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    // get user data
    else
    {
        do
        {
            printf("First name : ");
            scanf("%s", &std.first_name);
            if ( strlen(std.first_name) <= 2 ) // bishtar az 2 harf
                //printf("First name is too short\n") ;
                MessageBox(0,"First name is too short!\nPlease Try again!","Error!!",0);
            if (check_chracter(std.first_name)== 0) // hame harfa ch
                //printf("Your first name Cant be non-alphabet \n");
                MessageBox(0,"Your first name Cant be non-alphabet!\nPlease Try again!","Error!!",0);
        } while (check_chracter(std.first_name)== 0 || strlen(std.first_name) <= 2 );

        do
        {
            printf("last name : ");
            scanf("%s", &std.last_name);
            if ( strlen(std.last_name) <= 2 )
                printf("last name is too short\n") ;
            if (check_chracter(std.last_name)== 0)
                printf("Your lastt name Cant be non-alphabet \n");
        } while (check_chracter(std.last_name)== 0 || strlen(std.last_name) <= 2 );

        do
        {
            printf("national_code : ");
            scanf("%s", &std.national_code);
            if (strlen(std.national_code) !=  10)
                printf("National code must be 10 digit\n");
            if (check_digit(std.national_code) == 0)
                printf("Just digit allowed \n");
        } while (check_digit(std.national_code) == 0 || strlen(std.national_code) !=  10 ); // is digit 0 = non digit

        do
        {
            printf("phone_number : ");
            scanf("%s", &std.phone_number);
            if (strlen(std.phone_number) !=  11)
                printf("phone number must be 11 digit\n");
            if (check_digit(std.phone_number) == 0 )
                printf("just digit allowed \n");
            if  (std.phone_number[0] != '0' || std.phone_number[1] != '9' )
                printf("The phone number must be start 09xxxxxxxxx \n") ;
        } while ( check_digit(std.phone_number) ==0 || strlen(std.phone_number) !=  11 || std.phone_number[0] != '0' || std.phone_number[1] != '9' ) ;

        do
        {
            printf("mail : ");
            scanf("%s", &std.mail);
        } while (check_email(std.mail) == 0 ) ;

        do
        {
            printf("username : ");
            scanf("%s", &std.username);
            if (strlen(std.username) <= 2 ) // bishtar az 2 harf
                printf("Username must be more than 2 character \n") ;
           // if (unique_username(std.username) == 1)
               // printf("Username Already in use ! \n");
        } while (strlen(std.username) <= 2 ); //  || unique_username(std.username) == 1 )  ;

        do
        {
            printf("password : ");
            scanf("%s", &std.password);
        } while (check_pass(std.password) == 0 ) ;


        fwrite(&std,sizeof(struct sign_up) , 1 , fp ) ;
        fclose(fp);
    }
    printf("Do your want enter another student ? y / n ") ;
	choice = getch();
	choice=toupper(choice);
    if ( choice == 'Y')
    {
        system("cls");
        signup();
    }
        else
        {
            system("cls");
            main();
        }

}
void login ()
{
    char pass_given [50] , c = ' ';
    int i = 0 ;
    printf("Please enter your username: ");
    scanf("%s",&user_given);
    FILE *fp ;
    fp = fopen("profiles.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    else
    {

        while (fread(&std,sizeof(struct sign_up) , 1 , fp )== 1)
        {
            if (strcmp(user_given,std.username) == 0) // check username
            {
                printf("Please enter your password : "); //get password
                while (i<50) // print * instead paswword
                {
                    pass_given[i] = getch();
                    c = pass_given[i];
                    if (c==13)
                        break ;
                    printf("*");
                    i++;
                }
                pass_given[i] = '\0';
                i = 0;
                if (strcmp(pass_given,std.password) == 0)
                {
                    printf("\nWellcome");
                    Sleep(2000);
                    system("cls");
                    main_menu();


                    break ;
                }
                else if (strcmp(pass_given,std.password) != 0)
                {
                    //printf("\npassword incorrect");
                    MessageBox(0,"Password incorrect!\nPlease Try again!","Error!!",0);
                    system("cls");
                    login();
                    break;
                }
            }

        }
        fclose(fp);

    }

}

void main_menu ()
{
    int choice ;
    system("COLOR c");
    printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 1. Income   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 2. expenses   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 3. Statistics   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 4. Settings   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 5. Sign Out   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 5. Exit   ");
	printf("\n\n");
	printf("Please enter your choice : ");
	choice = getch();
	choice=toupper(choice);
	switch(choice)
	{
        case '1':
            system("COLOR b");
            system("cls");
            income();
            break;
        case '2':
            system("COLOR b");
            system("cls");
            expenses();
            break;
        case '3':
            system("COLOR b");
            system("cls");
            statistics();
            break;
        case '4':
            system("COLOR b");
            system("cls");
            settings ();
            break;
        case '5':
            system("COLOR b");
            system("cls");
            expensesLinkedList ();
            break;
        case '6':
            system("COLOR b");
            system("cls");
            printf("\n\n\n\n\n");
            printf("\n");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *         | Thank You For using the app |         *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            Sleep(3000);
            exit(0);
            break;



    }
    	/*if ( choice != 6 || choice != 5 || choice != 4 || choice != 3 || choice != 2 || choice != 1 || choice != 0x0A )
    {
                    MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
                    system("cls");
                    main_menu();

    } */
}
int check_chracter  ( char name[50] )    //this function check string is alphabet , for alphabet return 1
{
    int i , contain , sum= 0  ;
    contain = strlen(name) ;
    strupr(name);
    for (i= 0 ; i <= contain ; i++ )
    {
         sum = sum + isalpha(name[i]) ;
    }
    strlwr(name);
    if ( sum ==  contain  )
        return 1 ;
    else
        return 0 ;

}
int check_digit (char digit[] ) //this function check input is digit , for digit return 1
{
    int i , contain , sum= 0  ;

    contain = strlen(digit) ;
    for (i= 0 ; i <= contain ; i++ )
    {
        if ( 1 == isdigit(digit[i]))
            sum ++ ;
    }
    if ( sum == contain )
        return 1 ;
    else
        return 0 ;
}
int unique_username (char user [50])
{
    FILE *fp ;
    fp = fopen("profiles.txt" , "r") ;
    fread(&std,sizeof(struct sign_up) , 1 , fp ) ;
    rewind(fp);
    while (fread(&std,sizeof(std) , 1 , fp )== 1)
    {
        if (strcmp(user,std.username) == 1) // if user name is unique - this func return 1
            return 1 ;
        else
            return 0 ;
    }

}
int check_pass (char pass [50])
{
    int i , upper= 0 , lowwer =0 , digit =0 , special_ch = 0 ;
    char re_password [50] ;
    if ( 5 > strlen(pass))
        printf("password must be more than 5 character \n");
        else if ( 50 < strlen(pass))
            printf("Error: Password shouldn't exceed 50 characters ");
    for ( i = 0 ;i < strlen(pass) ; i ++)
    {
        if (pass[i]>= 'A' && pass[i]<= 'Z')
            upper++ ;
        if (pass[i]>= 'a' && pass[i]<= 'z')
            lowwer++ ;
        if (pass[i]>= '0' && pass[i]<= '9')
            digit++ ;
        if (pass[i]== '@' || pass[i]== '!' ||pass[i]== '.' || pass[i]== '$' || pass[i]== '#' || pass[i]== '*' || pass[i]== '%' )
            special_ch++ ;
    }
    if (upper==0)
        printf("There must be at least one Uppercase\n");
    if (lowwer==0)
        printf("There must be at least one Lowercase\n");
    if (digit==0)
        printf("There must be at least one Digit\n");
    if (special_ch==0)
        printf("There must be at least one Special Character\n");
    else
    {
        do
        {
        printf("Confirm your Password : ");
        scanf("%s" ,&re_password);
            if(strcmp(re_password,pass)== 1 || strlen(pass) != strlen(re_password) )
            printf("Password did not match\n");
        } while ( strcmp(re_password,pass)== 1 || strlen(pass) != strlen(re_password)) ;

    }


    if ( 5 > strlen(pass) || 50 < strlen(pass) || upper==0 || lowwer==0 || digit==0 || special_ch==0 || strcmp(re_password,pass)== 1 )
        return 0 ;
    else
        return 1 ; // if return 1 , password is good ...

}

int check_email (char email [50]) //if func return 1 , email is valid
{
    int i , contain , adsign = 0  , dot =0;
    contain = strlen(email);
    if(isalpha(email[0])== 0)
        printf("The email address must be start with letter ! \n");
    for (i=0 ; i < contain ; i++)
    {
        if (email[i] == '@' )
            adsign = 1;
        if (email[i] == '.' )
            dot = 1 ;

    }

    if (adsign == 0 || dot == 0)
        printf("The email address must be have @ and DOT. \n");
    if  (email[contain]== '.')
        printf("dot can not be in the last character of the email.\n");
    if  (contain <= 7 )
        printf("email must be more than 7 character \n");
    if (isalpha(email[0])== 0 || adsign == 0 || dot == 0 || email[contain]== '.' || contain <= 7 )
        return 0 ;
    else
        return 1 ;
}
void income()
{
    char choice ;
    FILE *fp ;
    fp = fopen("income.txt" , "a+") ;
    printf("Hello %s\n" , user_given );
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
        else
        {
            printf("Please specify your income type : ");
            int choice ;
            system("COLOR c");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 1. Programming Salary   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 2. YARANEH   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 3. Pocket money   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 4. University grant   ");
            printf("\n\n");
            printf("Please enter your choice : ");
            choice = getch();
            choice=toupper(choice);
            switch(choice)
            {
                case '1':
                    strcpy(inc.source,"Programming Salary") ;
                    break;
                case '2':
                    strcpy(inc.source,"YARANEH") ;
                    break;
                case '3':
                    strcpy(inc.source,"Pocket money") ;
                    break;
                case '4':
                    strcpy(inc.source,"University grant") ;
                    break;

            }
            printf("\n");
            do
            {
                printf("Please specify the amount of income : ");
                scanf("%s",&inc.amount);
                if (strlen(inc.amount) <= 2)
                    printf("amount must be more than 2 digit\n");
                if (check_digit(inc.amount) == 0)
                    printf("Just digit allowed \n");

            } while(check_digit(inc.amount) == 0 || strlen(inc.amount) <= 2 );

            printf("Please specify the date of income : \n");
            printf("Day : ");
            scanf("%s" ,&inc.day );
            printf("Month :");
            scanf("%s", &inc.month );
            printf("Year : ");
            scanf("%s", &inc.year );
            printf("Please enter description : ");
            scanf("%s" , inc.description);
            printf("\n Done!");
            strcpy(inc.user_login , user_given) ;

            fwrite(&inc , sizeof(struct add_income) ,1 ,fp) ;
            fclose(fp);

        }
    printf("\nDo you want to enter another Record ? y / n ") ;
	choice = getch();
	choice=toupper(choice);
    if ( choice == 'Y')
    {
        system("cls");
        income();
    }
        else
        {
            system("cls");
            main_menu();
        }



}

void expenses ()
{
    char choice ;
    FILE *fp ;
    fp = fopen("expenses.txt" , "a+") ;
    printf("Hello %s\n" , user_given );
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
        else
        {
            printf("Please specify your expenses type : ");
            int choice ;
            system("COLOR c");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 1. Clothing   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 2. Transportation   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 3. Educational expenses   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 4. Entertainment   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 5. Mobile and Internet bill   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 6. Medical expenses   ");
            printf("\n\n");
            printf("                           \xDB\xDB\xDB\xDB\xB2 7. Donate to charity   ");
            printf("\n\n");
            printf("Please enter your choice : ");
            choice = getch();
            choice=toupper(choice);
            switch(choice)
            {
                case '1':
                    strcpy(exp.source,"Clothing") ;
                    break;
                case '2':
                    strcpy(exp.source,"Transportation") ;
                    break;
                case '3':
                    strcpy(exp.source,"Educational expenses") ;
                    break;
                case '4':
                    strcpy(exp.source,"Entertainment") ;
                    break;
                case '5':
                    strcpy(exp.source,"Mobile and Internet bill") ;
                    break;
                case '6':
                    strcpy(exp.source,"Medical expenses") ;
                    break;
                case '7':
                    strcpy(exp.source,"Donate to charity") ;
                    break;

            }
            printf("\n");
            do
            {
                printf("Please specify the amount of expenses : ");
                scanf("%s",&exp.amount);
                if (strlen(exp.amount) <= 2)
                    printf("amount must be more than 2 digit\n");
                if (check_digit(exp.amount) == 0)
                    printf("Just digit allowed \n");

            } while(check_digit(exp.amount) == 0 || strlen(exp.amount) <= 2 );

            printf("Please specify the date of income : \n");
            printf("Day : ");
            scanf("%s" ,&exp.day );
            printf("Month :");
            scanf("%s", &exp.month );
            printf("Year : ");
            scanf("%s", &exp.year );
            printf("Please enter description : ");
            scanf("%s" , &exp.description);
            printf("\n Done!");
            strcpy(exp.user_login , user_given) ;

            fwrite(&exp , sizeof(struct add_expenses) ,1 ,fp) ;
            fclose(fp);
        }
    printf("\nDo you want to enter another Record ? y / n ") ;
	choice = getch();
	choice=toupper(choice);
    if ( choice == 'Y')
    {
        system("cls");
        expenses();
    }
        else
        {
            system("cls");
            main_menu();
        }

}

void statistics ()
{
    incomeLinkedList ();
    tempInc = startInc ;
    while ( tempInc != NULL )
    {
        if(strcmp( tempInc->user_login , "hossein") == 0 )
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
    }
    printf("\n*********************\n") ;
    expensesLinkedList ();
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

void settings ()
{
    char choice ;
    printf("Hello %s \n " , user_given ) ;
    printf("Do you want edit your profile ? Y/N : ") ;
    choice = getch();
    choice=toupper(choice);
    if (choice ==  'Y')
    {
        FILE *fp ;
        fp = fopen("profiles.txt" , "r+") ;
        if (fp == NULL )
        {
            printf("File could not be opened");

        }
        // get user data
        else
        {
            do
            {
                printf("First name : ");
                scanf("%s", &std.first_name);
                if ( strlen(std.first_name) <= 2 ) // bishtar az 2 harf
                    //printf("First name is too short\n") ;
                    MessageBox(0,"First name is too short!\nPlease Try again!","Error!!",0);
                if (check_chracter(std.first_name)== 0) // hame harfa ch
                    //printf("Your first name Cant be non-alphabet \n");
                    MessageBox(0,"Your first name Cant be non-alphabet!\nPlease Try again!","Error!!",0);
            } while (check_chracter(std.first_name)== 0 || strlen(std.first_name) <= 2 );

            do
            {
                printf("last name : ");
                scanf("%s", &std.last_name);
                if ( strlen(std.last_name) <= 2 )
                    printf("last name is too short\n") ;
                if (check_chracter(std.last_name)== 0)
                    printf("Your lastt name Cant be non-alphabet \n");
            } while (check_chracter(std.last_name)== 0 || strlen(std.last_name) <= 2 );

            do
            {
                printf("national_code : ");
                scanf("%s", &std.national_code);
                if (strlen(std.national_code) !=  10)
                    printf("National code must be 10 digit\n");
                if (check_digit(std.national_code) == 0)
                    printf("Just digit allowed \n");
            } while (check_digit(std.national_code) == 0 || strlen(std.national_code) !=  10 ); // is digit 0 = non digit

            do
            {
                printf("phone_number : ");
                scanf("%s", &std.phone_number);
                if (strlen(std.phone_number) !=  11)
                    printf("phone number must be 11 digit\n");
                if (check_digit(std.phone_number) == 0 )
                    printf("just digit allowed \n");
                if  (std.phone_number[0] != '0' || std.phone_number[1] != '9' )
                    printf("The phone number must be start 09xxxxxxxxx \n") ;
            } while ( check_digit(std.phone_number) ==0 || strlen(std.phone_number) !=  11 || std.phone_number[0] != '0' || std.phone_number[1] != '9' ) ;

            do
            {
                printf("mail : ");
                scanf("%s", &std.mail);
            } while (check_email(std.mail) == 0 ) ;

            do
            {
                printf("username : ");
                scanf("%s", &std.username);
                if (strlen(std.username) <= 2 ) // bishtar az 2 harf
                    printf("Username must be more than 2 character \n") ;
            // if (unique_username(std.username) == 1)
                // printf("Username Already in use ! \n");
            } while (strlen(std.username) <= 2 ); //  || unique_username(std.username) == 1 )  ;

            do
            {
                printf("password : ");
                scanf("%s", &std.password);
            } while (check_pass(std.password) == 0 ) ;

            fseek(fp,-sizeof(struct sign_up),SEEK_CUR);
			fwrite(&std,sizeof(struct sign_up) , 1 , fp ) ;
			fflush(stdin);
			fclose(fp);
			system("cls");
			printf("\nSuccessfully edited.\n");
        }

    }
        else
            {
                system("cls");
                main_menu();

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
    tempInc = startInc ;

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
    }


}

void expensesLinkedList ()
{
    printf("hello\n");
    FILE *fp ;
    fp = fopen ("expenses.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    printf("hello\n");
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
    fclose(fp);
    tempExp = startExp ;

    while ( tempExp != NULL )
    {
        if(strcmp( tempExp->user_login , "sina") == 0 )
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
    printf("hello\n");


}




