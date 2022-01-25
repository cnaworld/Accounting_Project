#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<ctype.h>
#include<dos.h>
int  attempts = 0 ;
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
	printf("                           \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
	choice = getche();
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
            printf("\n                          *      | Thank You For using this Soft-ware |     *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            Sleep(3000);
            exit(0);
            break;
        default :
            MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
            system("cls");
            main();
            break ;

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
   printf("\n");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n                          * 1-First and last name must be more than 2 character   *     ");
	printf("\n                          * 2-First and last name can not be non-alphabet!        *     ");
	printf("\n                          * 3-National code must be 10 digit and all Digit        *     ");
	printf("\n                          * 4-Phone number must be started with 09xxx and         *     ");
	printf("\n                          *  11 digit and all digit                               *     ");
	printf("\n                          * 5- Email format must have @ and Dot /  cant start     *     ");
	printf("\n                          *  with letters / dot can not be in the last character  *     ");
	printf("\n                          *  of the email / must be more than 7 character         *     ");
	printf("\n                          * 6-Username must be more than 2 character and Unique   *     ");
	printf("\n                          *                                                       *     ");
	printf("\n                          * 7-Password :  must be more than 5 character           *     ");
	printf("\n                          *               shouldn't exceed 50 characters          *     ");
    printf("\n                          *               be at least one Uppercase               *     ");
    printf("\n                          *               be at least one Lowercase               *     ");
    printf("\n                          *               be at least one Digit                   *     ");
    printf("\n                          *               be at least one Special Character       *     ");
    printf("\n                          *                                                       *     ");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n\n");

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
            printf("\xDB\xDB\xDB\xDB\xB2 First name : ");
            scanf("%s", &std.first_name);
            printf("\n");
            if ( strlen(std.first_name) <= 2 ) // bishtar az 2 harf
                //printf("First name is too short\n") ;
                MessageBox(0,"Your First name is too short!\nPlease Try again!","Error!!",0);
            if (check_chracter(std.first_name)== 0) // hame harfa ch
                //printf("Your first name Cant be non-alphabet \n");
                MessageBox(0,"Your first name Cant be non-alphabet!\nPlease Try again!","Error!!",0);
        } while (check_chracter(std.first_name)== 0 || strlen(std.first_name) <= 2 );

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 Last name : ");
            scanf("%s", &std.last_name);
            printf("\n");
            if ( strlen(std.last_name) <= 2 )
                //printf("last name is too short\n") ;
                MessageBox(0,"last name is too short!\nPlease Try again!","Error!!",0);
            if (check_chracter(std.last_name)== 0)
                //printf("Your latt name Cant be non-alphabet \n");
                MessageBox(0,"Your Last name Cant be non-alphabet!\nPlease Try again!","Error!!",0);
        } while (check_chracter(std.last_name)== 0 || strlen(std.last_name) <= 2 );

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 National_code : ");
            scanf("%s", &std.national_code);
            printf("\n");
            if (strlen(std.national_code) !=  10)
                //printf("National code must be 10 digit\n");
                MessageBox(0,"National code must be 10 digit!\nPlease Try again!","Error!!",0);
            if (check_digit(std.national_code) == 0)
               // printf("Just digit allowed \n");
                MessageBox(0,"Just digit allowed !\nPlease Try again!","Error!!",0);
        } while (check_digit(std.national_code) == 0 || strlen(std.national_code) !=  10 ); // is digit 0 = non digit

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 Phone_number : ");
            scanf("%s", &std.phone_number);
            printf("\n");
            if (strlen(std.phone_number) !=  11)
               // printf("phone number must be 11 digit\n");
                MessageBox(0,"phone number must be 11 digit\nPlease Try again!","Error!!",0);
            if (check_digit(std.phone_number) == 0 )
                //printf("just digit allowed \n");
                MessageBox(0,"just digit allowed !\nPlease Try again!","Error!!",0);
            if  (std.phone_number[0] != '0' || std.phone_number[1] != '9' )
                //printf("The phone number must be start 09xxxxxxxxx \n") ;
                MessageBox(0,"The phone number must be start 09xxxxxxxxx!\nPlease Try again!","Error!!",0);
        } while ( check_digit(std.phone_number) ==0 || strlen(std.phone_number) !=  11 || std.phone_number[0] != '0' || std.phone_number[1] != '9' ) ;

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 Mail : ");
            scanf("%s", &std.mail);
            printf("\n");
        } while (check_email(std.mail) == 0 ) ;

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 Username : ");
            scanf("%s", &std.username);
            printf("\n");
            if (strlen(std.username) <= 2 ) // bishtar az 2 harf
                //printf("Username must be more than 2 character \n") ;
                MessageBox(0,"Username must be more than 2 character \nPlease Try again!","Error!!",0);
                //  if (unique_username(std.username) == 1)
                  //  printf("Username Already in use ! \n");
        } while (strlen(std.username) <= 2 ) ; //|| unique_username(std.username) == 1 )  ;

        do
        {
            printf("\xDB\xDB\xDB\xDB\xB2 Password : ");
            char starPass [50] , c = ' ';
            int i = 0 ;
            while (i<50) // print * instead paswword
                {
                    starPass[i] = getch();
                    c = starPass[i];
                    if (c==13)
                        break ;
                    printf("*");
                    i++;
                }
                starPass[i] = '\0';
                i = 0;
                printf("\n");
            strcpy(std.password , starPass );
            printf("\n");

        } while (check_pass(std.password) == 0 ) ;


        fwrite(&std,sizeof(struct sign_up) , 1 , fp ) ;
        fclose(fp);
    }
    printf("\n");
    printf("\xDB\xDB\xDB\xDB\xB2 Do your want add another record ? [y / n] ") ;
	choice = getch();
	choice=toupper(choice);
        switch (choice)
        {
            case 'Y' :
                system("cls");
                signup();
                break ;
            case 'N' :
                system("cls");
                main();
                break ;
            default :
                system("cls");
                main();
                break ;
        }

}
void login ()
{
    printf("\n\n\n");
    printf("\n                              *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n                              *                                                 *     ");
    printf("\n                              *                                                 *     ");
    printf("\n                              *                   login menu                    *     ");
    printf("\n                              *                                                 *     ");
    printf("\n                              *                                                 *     ");
    printf("\n                              *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");

    char pass_given [50] , c = ' ';
    int i = 0  , j = 0 ;
    printf("\n\n\n                           \xDB\xDB\xDB\xDB\xB2 Please enter your username: ");
    scanf("%s",&user_given);
    FILE *fp ;
    fp = fopen("profiles.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    else
    {
        if( attempts >= 5  )
        {
            printf("Sorry, only allowed 5 attempts.\n ");
            Sleep(3000);
            for (j = 0 ; j <= 900 ; j++)
            {
                printf("\n \xDB\xDB\xDB\xDB\xB2 You can retry after 15 min (900 Sec). \n");

                printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
                printf("\n                          *                                                 *     ");
                printf("\n                          *                                                 *     ");
                printf("\n                          *                       %d Sec                    * ",j);
                printf("\n                          *                                                 *     ");
                printf("\n                          *                                                 *     ");
                printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
                Sleep(1000);
                system("cls");

            }

        }

        while (fread(&std,sizeof(struct sign_up) , 1 , fp )== 1)
        {
            if (strcmp(user_given,std.username) == 0) // check username
            {
                printf("\n                           \xDB\xDB\xDB\xDB\xB2 Please enter your password : "); //get password
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
                    printf("\n\n\n                           \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 Welcome %s \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2" , user_given );
                    Sleep(4000);
                    system("cls");
                    main_menu();


                    break ;
                }
                else if (strcmp(pass_given,std.password) != 0)
                {
                    //printf("\npassword incorrect");
                    MessageBox(0,"Password incorrect!\nPlease Try again!","Error!!",0);
                    attempts++ ;
                    system("cls");
                    login();
                    break;


                }

            }

        }
        if (strcmp(user_given,std.username) != 0 )
        {
            MessageBox(0,"User not found!\nPlease Try again!","Error!!",0);
            attempts++;
            login();
        }

    fclose(fp);

    }

}

void main_menu ()
{
    int choice ;
    system("COLOR a");
    printf("\n");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Add Incomes                           *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. Add expenses                          *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. Statistics                            *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. Settings                              *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 5. Sign Out                              *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 6. Exit                                  *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n\n\n                          \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
	choice = getche();
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
            main ();
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
            printf("\n                          *      | Thank You For using this Soft-ware |     *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            Sleep(3000);
            exit(0);
            break;
        default :
            MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
            system("cls");
            main_menu();
            break ;

    }

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
        if (strcmp(user,std.username) == 0) // if user name is unique - this func return 1
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
        //printf("password must be more than 5 character \n");
        MessageBox(0,"password must be more than 5 character!\nPlease Try again!","Error!!",0);

        else if ( 50 < strlen(pass))
            //printf("Error: Password shouldn't exceed 50 characters ");
            MessageBox(0,"Password shouldn't exceed 50 characters!\nPlease Try again!","Error!!",0);
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
        //printf("There must be at least one Uppercase\n");
        MessageBox(0,"There must be at least one Uppercase!\nPlease Try again!","Error!!",0);
    if (lowwer==0)
        //printf("There must be at least one Lowercase\n");
        MessageBox(0,"There must be at least one Lowercase!\nPlease Try again!","Error!!",0);
    if (digit==0)
        //printf("There must be at least one Digit\n");
        MessageBox(0,"There must be at least one Digit!\nPlease Try again!","Error!!",0);
    if (special_ch==0)
       // printf("There must be at least one Special Character\n");
        MessageBox(0,"There must be at least one Special Character!\nPlease Try again!","Error!!",0);
    else
    {
        do
        {
            printf("\n\xDB\xDB\xDB\xDB\xB2 Confirm your Password : ");
            char starRePass [50] , c = ' ';
            int i = 0 ;
            while (i<50) // print * instead paswword
            {
                starRePass[i] = getch();
                c = starRePass[i];
                if (c==13)
                    break ;
                printf("*");
                i++;
            }
            starRePass[i] = '\0';
            i = 0;
            strcpy(re_password , starRePass );
            printf("\n");
            if(strcmp(re_password,pass)== 1 || strlen(pass) != strlen(re_password) )
            //printf("Password did not match\n");
            MessageBox(0,"Password did not match!\nPlease Try again!","Error!!",0);
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
        //printf("The email address must be start with letter ! \n");
        MessageBox(0,"The email address must be start with letter !\nPlease Try again!","Error!!",0);
    for (i=0 ; i < contain ; i++)
    {
        if (email[i] == '@' )
            adsign = 1;
        if (email[i] == '.' )
            dot = 1 ;

    }

    if (adsign == 0 || dot == 0)
        //printf("The email address must be have @ and DOT. \n");
        MessageBox(0,"The email address must be have @ and DOT. !\nPlease Try again!","Error!!",0);
    if  (email[contain]== '.')
        //printf("dot can not be in the last character of the email.\n");
        MessageBox(0,"dot can not be in the last character of the email.!\nPlease Try again!","Error!!",0);
    if  (contain <= 7 )
        //printf("email must be more than 7 character \n");
        MessageBox(0,"email must be more than 7 character !\nPlease Try again!","Error!!",0);
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
    printf("                          \xDB\xDB\xDB\xDB\xB2 Hello %s!\n\n" , user_given );
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
        else
        {
            system("COLOR c");
            printf("                          \xDB\xDB\xDB\xDB\xB2 Please specify your income type : \n\n");
            int choice ;
            printf("\n");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Programming Salary                    *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. YARANEH                               *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. Pocket money                          *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. University grant                      *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
            choice = getche();
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
                default :
                    MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
                    system("cls");
                    income();
                    break ;


            }
            printf("\n");
            do
            {
                printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please specify the amount of income (Rial): ");
                scanf("%s",&inc.amount);
                if (strlen(inc.amount) <= 2)
                    printf("                     \xDB\xDB\xDB\xDB\xB2 amount must be more than 2 digit\n");
                if (check_digit(inc.amount) == 0)
                    printf("                     \xDB\xDB\xDB\xDB\xB2 Just digit allowed \n");

            } while(check_digit(inc.amount) == 0 || strlen(inc.amount) <= 2 );

            printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please specify the date of income : ");
            do
            {
                printf("   \xB2\xB2\xB2\xB2\xB2 Day : ");
                scanf("%s" ,&inc.day );
                if (check_digit(inc.day) == 0)
                    printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");
            } while(check_digit(inc.day) == 0 ) ;

            do
            {
                printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Month : ");
                scanf("%s", &inc.month );
                if (check_digit(inc.month) == 0)
                printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");

            } while(check_digit(inc.month) == 0 ) ;

            do
            {
            printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Year : ");
            scanf("%s", &inc.year );
            if (check_digit(inc.year) == 0)
            printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");
            } while(check_digit(inc.year) == 0 ) ;

            fflush(stdin);
            printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please enter description : ");
            gets(inc.description);
            printf("\n\n                        \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 All Done ! \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
            strcpy(inc.user_login , user_given) ;

            fwrite(&inc , sizeof(struct add_income) ,1 ,fp) ;
            fclose(fp);

        }
    printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Do you want to enter another Record ? [y/n] ") ;
	choice = getche();
	choice=toupper(choice);
    switch (choice)
    {
        case 'Y' :
            system("cls");
            income();
            break ;
        case 'N' :
            system("cls");
            main_menu();
            break;
        default :
            system("cls");
            main_menu();
            break ;
        }

}

void expenses ()
{
    char choice ;
    FILE *fp ;
    fp = fopen("expenses.txt" , "a+") ;
    printf("                          \xDB\xDB\xDB\xDB\xB2 Hello %s!\n\n" , user_given );
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
        else
        {
            system("COLOR c");
            printf("                          \xDB\xDB\xDB\xDB\xB2 Please specify your expens type : \n\n");
            int choice ;
            printf("\n");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Clothing                              *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. Transportation                        *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. Educational expenses                  *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. Entertainment                         *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 5. Mobile and Internet bill              *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 6. Medical expenses                      *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 7. Donate to charity                     *     ");
            printf("\n                          *                                                 *     ");
            printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
            choice = getche();
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
                default :
                    MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
                    system("cls");
                    expenses();
                    break ;

            }
            printf("\n");
            do
            {
                printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please specify the amount of expens (Rial): ");
                scanf("%s",&exp.amount);
                if (strlen(exp.amount) <= 2)
                    printf("                     \xDB\xDB\xDB\xDB\xB2 amount must be more than 2 digit\n");
                if (check_digit(exp.amount) == 0)
                    printf("                     \xDB\xDB\xDB\xDB\xB2 Just digit allowed \n");

            } while(check_digit(exp.amount) == 0 || strlen(exp.amount) <= 2 );

            printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please specify the date of expens : ");
            do
            {
                printf("   \xB2\xB2\xB2\xB2\xB2 Day : ");
                scanf("%s" ,&exp.day );
                if (check_digit(exp.day) == 0)
                    printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");
            } while(check_digit(exp.day) == 0 ) ;

            do
            {
                printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Month : ");
                scanf("%s", &exp.month );
                if (check_digit(exp.month) == 0)
                printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");

            } while(check_digit(exp.month) == 0 ) ;

            do
            {
            printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Year : ");
            scanf("%s", &exp.year );
            if (check_digit(exp.year) == 0)
            printf("                                                                  \xB2\xB2\xB2\xB2\xB2 Just digit allowed \n");
            } while(check_digit(exp.year) == 0 ) ;

            fflush(stdin);
            printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please enter description : ");
            gets(exp.description);
            printf("\n\n                        \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2 All Done ! \xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
            strcpy(exp.user_login , user_given) ;

            fwrite(&exp , sizeof(struct add_expenses) ,1 ,fp) ;
            fclose(fp);
        }
    printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Do you want to enter another Record ? [y/n] ") ;
	choice = getche();
	choice=toupper(choice);
    switch (choice)
    {
        case 'Y' :
            system("cls");
            expenses();
            break ;
        case 'N' :
            system("cls");
            main_menu();
            break;
        default :
            system("cls");
            main_menu();
            break ;
        }


}

void statistics ()
{


    int choice ;
    system("COLOR d");
    printf("\n");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Incomes Reports                       *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. Expenses Reports                      *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. Account balance Reports               *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. Main Menu                             *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 5. Exit                                  *     ");
    printf("\n                          *                                                 *     ");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
	choice = getche();
	choice=toupper(choice);
	switch(choice)
	{
        case '1':
            system("COLOR b");
            system("cls");
            incomeReports();
            break;
        case '2':
            system("COLOR b");
            system("cls");
            expensesReports();
            break;
        case '3':
            system("COLOR b");
            system("cls");
            balanceReports();
            break;
        case '4':
            system("COLOR b");
            system("cls");
            main_menu ();
            break;
        case '5':
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
        default :
            MessageBox(0,"Enter Valid Number!\nPlease Try again!","Error!!",0);
            system("cls");
            statistics();
            break ;
	}


}

void settings ()
{
    char choice ;
    printf("Hello %s \n " , user_given ) ;
    printf("Do you want to edit your profile ? Y/N : ") ;
    choice = getch();
    choice=toupper(choice);
    if (choice ==  'Y')
    {
        FILE *fp , *newRec  ;
        fp = fopen("profiles.txt" , "r") ;
        newRec = fopen("temp.txt", "w" ) ;

        if (fp == NULL  || newRec == NULL )
        {
            printf("File could not be opened");

        }

        // get user data
        else
        {
            while(fread(&std,sizeof(struct sign_up) , 1 , fp )== 1)
            {
                if ( strcmp (std.username,user_given)==0 )
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

          /*  do
            {
                printf("username : ");
                scanf("%s", &std.username);
                if (strlen(std.username) <= 2 ) // bishtar az 2 harf
                    printf("Username must be more than 2 character \n") ;
            // if (unique_username(std.username) == 1)
                // printf("Username Already in use ! \n");
            } while (strlen(std.username) <= 2 ); //  || unique_username(std.username) == 1 )  ; */
            strcpy(std.username , user_given ) ;

            do
            {
                printf("password : ");
                scanf("%s", &std.password);
            } while (check_pass(std.password) == 0 ) ;

                }
            fwrite(&std , sizeof (struct sign_up) , 1 , newRec );

            }

            fclose(fp);
            fclose(newRec);

            fp = fopen("profiles.txt" , "w") ;
            newRec = fopen("temp.txt", "r" ) ;
            while (fread(&std,sizeof(struct sign_up) , 1 , newRec )== 1)
            {
                fwrite(&std,sizeof(struct sign_up) , 1 , fp ) ;
            }
            fclose(fp);
            fclose(newRec);
            printf("\nSuccessfully edited.\n") ;

           /*

            //fseek(fp,-sizeof(struct sign_up),SEEK_CUR);
			fwrite(&std,sizeof(struct sign_up) , 1 , newRec ) ;
			fclose(fp);
			fclose(newRec);
			//system("cls");
			remove("profiles.txt") ;
			rename("temp.txt" ,"profiles.txt") ;
			printf("\nSuccessfully edited.\n") ; */

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


}

void expensesLinkedList ()
{
    FILE *fp ;
    fp = fopen ("expenses.txt" , "r") ;
    if (fp == NULL )
    {
        printf("File could not be opened");

    }
    // struct add_expenses *startExp , *endExp , *tempExp
    tempExp = malloc(sizeof(struct add_expenses)) ;
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

}

void incomeReports()
{
    incomeLinkedList();
    int choice ;
    system("COLOR d");
    printf("\n");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Total incomes for a specified year                                *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. Total incomes for a period of time                                *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. The amount of a certain type of incomes in a period of time       *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. The ratio of different incomes to each other                      *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 5. Micro-revenues of a period of time                                *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 6. The largest income figure in a period of time                     *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 7. specific word search in the incomes Description field             *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 8. Main Menu                                                         *     ");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
	choice = getche();
	printf("\n");
    if ( choice == '1' )
    {
        system("cls");
        int year ;
        int amount , sum = 0 ;
        int search , select ;
        char checkYear [50];
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *       Total incomes for a specified year        *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter the desired year : ") ;
        scanf("%d" , &year ) ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            search = atoi(tempInc-> year) ;
            if( search == year && strcmp(tempInc->user_login , user_given )== 0  )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rials" , tempInc->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempInc->amount) ;
                sum = amount + sum ;
            }
            tempInc = tempInc->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Incomes for %d is :   %d Rials" ,  year , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        select = getch();
        switch(select)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }

    }

    if (choice == '2' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int amount , sum = 0 ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *       Total incomes for a period of time        *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        int select ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        select = getch();
        printf("\n");
        switch(select)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rial" , tempInc->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempInc->amount) ;
                sum = amount + sum ;

            }

            tempInc = tempInc->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Incomes  is :   %d Rial" , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        int choose ;
        choose = getch();
        switch(choose)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }


    }

    if ( choice == '3' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int amount , sum = 0 ;
        char incomeType [50] ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *      The amount of a certain type of incomes    *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please specify your income type for search ");
            int select ;
            system("COLOR d");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  1. Programming Salary   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  2. YARANEH   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  3. Pocket money   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  4. University grant   ");
            printf("\n\n");
            printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
            select = getche();
            switch(select)
            {
                case '1':
                    strcpy(incomeType,"Programming Salary") ;
                    break;
                case '2':
                    strcpy(incomeType,"YARANEH") ;
                    break;
                case '3':
                    strcpy(incomeType,"Pocket money") ;
                    break;
                case '4':
                    strcpy(incomeType,"University grant") ;
                    break;

            }
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && strcmp(tempInc->source , incomeType) == 0 )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rial" , tempInc->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempInc->amount) ;
                sum = amount + sum ;

            }

            tempInc = tempInc->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Incomes for %s is :   %d Rial" , incomeType , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }
    }

    if ( choice == '4' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        float amount , sum = 0 , programming = 0 , yaraneh = 0 , pocketMoney = 0 , uniGrant = 0  ;
        float sumAmount =0 , sumProgramming = 0 , sumYaraneh = 0 , sumPocketMoney = 0 , sumUniGrant = 0  ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *   The ratio of different incomes to each other  *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 The Ratio :  ") ;
        printf("                                                \xDB\xDB\xDB\xB2\xB2");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 )
            {
                amount = atof(tempInc->amount) ;
                sum = amount + sum ;
            }
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && strcmp(tempInc->source , "Programming Salary") == 0  )
            {
                programming = atof(tempInc->amount) ;
                sumProgramming = programming + sumProgramming ;
            }
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && strcmp(tempInc->source , "YARANEH") == 0  )
            {
                yaraneh = atof(tempInc->amount) ;
                sumYaraneh = yaraneh + sumYaraneh ;
            }
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && strcmp(tempInc->source , "Pocket money") == 0  )
            {
                pocketMoney = atof(tempInc->amount) ;
                sumPocketMoney = pocketMoney + sumPocketMoney ;
            }
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && strcmp(tempInc->source , "University grant") == 0  )
            {
                uniGrant = atof(tempInc->amount) ;
                sumUniGrant = uniGrant + sumUniGrant ;
            }

            tempInc = tempInc->link ;
        }
        programming = ( sumProgramming * 100 ) / sum ;
        yaraneh = ( sumYaraneh * 100 ) / sum ;
        pocketMoney = ( sumPocketMoney * 100 ) / sum ;
        uniGrant = ( sumUniGrant * 100 ) / sum ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Programming Salary : %0.2f%% " , programming) ;
        printf("\n                                    \xDB\xDB\xDB\xDB\xB2 YARANEH :        %0.2f%% " , yaraneh) ;
        printf("\n                                             \xDB\xDB\xDB\xDB\xB2 Pocket money : %0.2f%% " , pocketMoney) ;
        printf("\n                                                      \xDB\xDB\xDB\xDB\xB2 University grant : %0.2f%% " , uniGrant) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }

    }

    if ( choice == '5' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                 Micro-revenues                  *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        tempInc = startInc ;
        //printf("==========================\n");
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 )
            {
                printf("                                                    Amount : %s Rial \n" , tempInc->amount);
                printf("                                                    Source : %s\n" , tempInc->source);
                printf("                                                    Date : %s/%s/%s\n" , tempInc->year , tempInc->month , tempInc->day);
                printf("                                                   Description : %s\n" , tempInc->description);
                printf("                                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

            }

            tempInc = tempInc->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }

    }

    if ( choice == '6' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int maxAmount = 0 , amount ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                 The largest income              *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 )
            {
                amount = atoi(tempInc->amount) ;
                if (amount >= maxAmount )
                    maxAmount = amount ;
            }

            tempInc = tempInc->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("\n                                                 %d Rials\n" , maxAmount );
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }

    }

    if (choice == '7')
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *              Specific Word Search               *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        fflush(stdin);
        char wordSearch [50];
        char *result ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your word for search in description : ");
        gets(wordSearch);
        tempInc = startInc ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        while ( tempInc != NULL )
        {
            result = strstr(tempInc->description,wordSearch) ;
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempInc->user_login , user_given )== 0 && result != NULL )
            {
                printf("                                                    Amount : %s Rial \n" , tempInc->amount);
                printf("                                                    Source : %s\n" , tempInc->source);
                printf("                                                    Date : %s/%s/%s\n" , tempInc->year , tempInc->month , tempInc->day);
                printf("                                                   Description : %s\n" , tempInc->description);
                printf("                                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            }

            tempInc = tempInc->link ;
            }

        if (result == 0 )
            {
                printf("\n                     \xDB\xDB\xDB\xDB\xB2 Word not found in description");

            }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Income Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    incomeReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    incomeReports();
                    break;

            }
    }

    if (choice == '8')
    {
        system("cls") ;
        main_menu () ;
    }

}

void expensesReports ()
{
    expensesLinkedList();
    int choice ;
    printf("\n");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 1. Total Expenses for a specified year                               *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 2. Total Expenses for a period of time                               *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 3. The amount of a certain type of Expenses in a period of time      *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 4. The ratio of different Expenses to each other                     *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 5. Micro-Expenses of a period of time                                *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 6. The largest Expens figure in a period of time                     *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 7. specific word search in the Expenses Description field            *     ");
    printf("\n                          *                                                                             *     ");
    printf("\n                          *  \xDB\xDB\xDB\xDB\xB2 8. Main Menu                                                         *     ");
    printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
    printf("\n\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
	choice = getche();
	printf("\n");

    if ( choice == '1' )
    {
        system("cls");
        int year ;
        int amount , sum = 0 ;
        int search , select ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *       Total Expenses for a specified year       *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter the desired year : ") ;
        scanf("%d" , &year ) ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            search = atoi(tempExp-> year) ;
            if( search == year && strcmp(tempExp->user_login , user_given )== 0  )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rials" , tempExp->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempExp->amount) ;
                sum = amount + sum ;
            }
            tempExp = tempExp->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Expenses for %d is :   %d Rials" ,  year , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expens Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        select = getch();
        switch(select)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }
    }

    if (choice == '2' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int amount , sum = 0 ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *       Total Expenses for a period of time       *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        int select ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        select = getch();
        printf("\n");
        switch(select)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rials" , tempExp->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempExp->amount) ;
                sum = amount + sum ;

            }

            tempExp = tempExp->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Incomes  is :   %d Rial" , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        int choose ;
        choose = getch();
        switch(choose)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }

    }

    if ( choice == '3' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int amount , sum = 0 ;
        char expensType [50] ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *      The amount of a certain type of Expenses   *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
            printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please specify your Expens type for search ");
            int select ;
            system("COLOR c");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  1. Clothing   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  2. Transportation   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  3. Educational expenses   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  4. Entertainment   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  5. Mobile and Internet bill   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  6. Medical expenses   ");
            printf("\n\n");
            printf("                         \xDB\xDB\xDB\xDB\xB2  7. Donate to charity   ");
            printf("\n\n");
            printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
            select = getche();
            switch(select)
            {
                case '1':
                    strcpy(expensType,"Clothing") ;
                    break;
                case '2':
                    strcpy(expensType,"Transportation") ;
                    break;
                case '3':
                    strcpy(expensType,"Educational expenses") ;
                    break;
                case '4':
                    strcpy(expensType,"Entertainment") ;
                    break;
                case '5':
                    strcpy(expensType,"Mobile and Internet bill") ;
                    break;
                case '6':
                    strcpy(expensType,"Medical expenses") ;
                    break;
                case '7':
                    strcpy(expensType,"Donate to charity") ;
                    break;

            }
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Incomes :  ") ;
        printf("                                                  \xB2\xB2\xB2\xB2\xB2");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , expensType) == 0 )
            {
                printf("\n                     \xB2\xB2\xB2\xB2\xB2                      %15s\t Rials" , tempExp->amount);
                printf("               \t\xB2\xB2\xB2\xB2\xB2");
                amount = atoi(tempExp->amount) ;
                sum = amount + sum ;

            }

            tempExp = tempExp->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 The Total Expens for %s is :   %d Rials" , expensType , sum ) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");

        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }
    }

    if ( choice == '4' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        float amount , sum = 0 , clothing = 0 , transportation = 0 , educational = 0 , entertainment = 0 , bill = 0 , medical = 0 , charity = 0   ;
        float sumAmount = 0 , sumClothing = 0 , sumTransportation = 0 , sumEducational = 0 , sumEntertainment = 0 , sumBill = 0 , sumMedical = 0 , sumCharity = 0 ;
         printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *   The ratio of different Expenses to each other *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 The Ratio :  ") ;
        printf("                                                \xDB\xDB\xDB\xB2\xB2");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 )
            {
                amount = atof(tempExp->amount) ;
                sum = amount + sum ;
            }
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Clothing") == 0  )
            {
                clothing = atof(tempExp->amount) ;
                sumClothing = clothing + sumClothing ;
            }
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Transportation") == 0  )
            {
                transportation = atof(tempExp->amount) ;
                sumTransportation = transportation + sumTransportation ;
            }
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Educational expenses") == 0  )
            {
                educational = atof(tempExp->amount) ;
                sumEducational = educational + sumEducational ;
            }
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Entertainment") == 0  )
            {
                entertainment = atof(tempExp->amount) ;
                sumEntertainment = entertainment + sumEntertainment ;
            }
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Mobile and Internet bill") == 0  )
            {
                bill = atof(tempExp->amount) ;
                sumBill = bill + sumBill ;
            }

            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Medical expenses") == 0  )
            {
                medical = atof(tempExp->amount) ;
                sumMedical = medical + sumMedical ;
            }

            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && strcmp(tempExp->source , "Donate to charity") == 0  )
            {
                charity = atof(tempExp->amount) ;
                sumCharity = charity + sumCharity ;
            }


            tempExp = tempExp->link ;
        }
        clothing = ( sumClothing * 100 ) / sum ;
        transportation = ( sumTransportation * 100 ) / sum ;
        educational = ( sumEducational * 100 ) / sum ;
        entertainment = ( sumEntertainment * 100 ) / sum ;
        bill = ( sumBill * 100 ) / sum ;
        medical = ( sumMedical * 100 ) / sum ;
        charity = ( sumCharity * 100 ) / sum ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Clothing : \t%0.2f %% " , clothing) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Transportation : \t%0.2f %% " , transportation) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Educational expenses : \t%0.2f %% " , educational) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Entertainment : \t%0.2f %% " , entertainment) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Mobile and Internet bill : \t%0.2f %% " , bill) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Medical expenses : \t%0.2f %% " , medical) ;
        printf("\n                           \xDB\xDB\xDB\xDB\xB2 Donate to charity : \t%0.2f %% " , charity) ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }

    }

    if ( choice == '5' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                 Micro-Expenses                  *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 )
            {
                printf("                                                    Amount : %s Rial \n" , tempExp->amount);
                printf("                                                    Source : %s\n" , tempExp->source);
                printf("                                                    Date : %s/%s/%s\n" , tempExp->year , tempExp->month , tempExp->day);
                printf("                                                   Description : %s\n" , tempExp->description);
                printf("                                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            }

            tempExp = tempExp->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }

    }
    if ( choice == '6' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int maxAmount = 0 , amount ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                 The largest Expens              *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 )
            {
                amount = atoi(tempExp->amount) ;
                if (amount >= maxAmount )
                    maxAmount = amount ;
            }

            tempExp = tempExp->link ;
        }
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("\n                                                 %d Rials\n" , maxAmount );
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }

    }

    if (choice == '7')
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *              Specific Word Search               *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *                                                 *     ");
        printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
        int choose ;
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  1. All Time   ");
        printf("\n\n");
        printf("                         \xDB\xDB\xDB\xDB\xB2  2. between two Dates   ");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ");
        choose = getche();
        printf("\n");
        switch(choose)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("\n                         \xDB\xDB\xDB\xDB\xB2 Please enter start Date  (yyyy/m/d) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("                         \xDB\xDB\xDB\xDB\xB2 Please enter end Date  (yyyy/m/d) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;
            default :
                system("cls");
                incomeReports();
                break;

        }
        fflush(stdin);
        char wordSearch [50];
        char *result ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your word for search in description : ");
        gets(wordSearch);
        tempExp = startExp ;
        printf("\n                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        while ( tempExp != NULL )
        {
            result = strstr(tempExp->description,wordSearch) ;
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if (validDate == 1 && strcmp(tempExp->user_login , user_given )== 0 && result != NULL )
            {
                printf("                                                    Amount : %s Rial \n" , tempExp->amount);
                printf("                                                    Source : %s\n" , tempExp->source);
                printf("                                                    Date : %s/%s/%s\n" , tempExp->year , tempExp->month , tempExp->day);
                printf("                                                   Description : %s\n" , tempExp->description);
                printf("                                      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            }

            tempExp = tempExp->link ;
            }

       /* if (result == 0 )
            {
                printf("\n                     \xDB\xDB\xDB\xDB\xB2 Word not found in description");

            } */
        printf("\n                     \xDB\xDB\xDB\xDB\xB2               ") ;
        printf("                                               \xDB\xDB\xDB\xB2\xB2\n");
        printf("                     \xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xB2");
        printf("\xDB\xDB\xDB\xDB\xB2\xDB\xDB\xDB\xDB\xDB\xDB\xB2");
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2 Please enter your choice : ") ;
        printf("\n\n                     \xDB\xDB\xDB\xDB\xB2  1. Expenses Reports Menu");
        printf("\n                     \xDB\xDB\xDB\xDB\xB2  2. Main Menu ");
        int pick ;
        pick = getch();
        switch(pick)
            {
                case '1':
                    system("cls");
                    expensesReports();
                case '2':
                    system("cls");
                    main_menu();
                default :
                    system("cls");
                    expensesReports();
                    break;

            }
    }


    if (choice == '8')
    {
        system("cls") ;
        main_menu () ;
    }



}



int checkDate (int startYear , int startDay ,int startMonth ,int endYear ,int endDay ,int endMonth ,int searchYear ,int searchDay ,int searchMonth )
{
    int valid = 0 ;
            if (searchYear > startYear)
            {
                if (searchYear < endYear )
                    valid = 1 ;
            }

            if (searchYear > startYear)
            {
                if(searchYear == endYear )
                {
                    if (searchMonth < endMonth)
                        valid = 1 ;
                }
            }
            if (searchYear > startYear)
            {
                if(searchYear == endYear )
                {
                    if (searchMonth == endMonth)
                    {
                        if (searchDay <= endDay)
                            valid = 1 ;
                    }
                }
            }
            if (searchYear == startYear )
            {
                if (searchYear == endYear)
                {
                    if (searchMonth == startMonth)
                    {
                        if (searchMonth == endMonth)
                        {
                            if (searchDay >= startDay && searchDay <= endDay )
                                valid = 1 ;
                        }
                    }
                }
            }

          if (searchYear == startYear )
            {
                if (searchYear == endYear)
                {
                    if (searchMonth == startMonth)
                    {
                        if (searchMonth < endMonth)
                        {
                            if (searchDay >= startDay )
                                valid = 1 ;
                        }
                    }
                }
            }
            if (searchYear == startYear )
            {
                if (searchYear == endYear)
                {
                    if (searchMonth > startMonth)
                    {
                        if (searchMonth == endMonth)
                        {
                            if (searchDay <= startDay )
                                valid = 1 ;
                        }
                    }
                }
            }
            if (searchYear == startYear )
            {
                if (searchYear == endYear)
                {
                    if (searchMonth > startMonth)
                    {
                        if (searchMonth < endMonth)
                            valid = 1 ;
                    }
                }
            }
            if (searchYear == startYear )
            {
                if (searchYear < endYear)
                {
                    if (searchMonth == startMonth)
                    {
                        if (searchDay >= startDay)
                            valid = 1 ;
                    }
                }
            }
            if (searchYear == startYear )
            {
                if (searchYear < endYear)
                {
                    if (searchMonth > startMonth)
                        valid = 1 ;
                }
            }

            return valid ;

}

void balanceReports ()
{
    incomeLinkedList();
    expensesLinkedList();
    int choice ;
    system("COLOR c");
    printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 1. Current account balance   ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 2. Specified year account balance  ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 3. Account balance for a period of time  ");
	printf("\n\n");
	printf("                           \xDB\xDB\xDB\xDB\xB2 4. Micro-balance of a period of time   ");
	printf("\n\n");
    printf("                           \xDB\xDB\xDB\xDB\xB2 5. Main Menu    ");
	printf("\n\n");
	printf("Please enter your choice : ");
	choice = getche();
	printf("\n");

	if (choice == '1')
    {
        int incomeAmount , incomeSum = 0 , expensAmount , expensSum = 0 ;
        int net ;
        // sum income
        printf("incomes : \n");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            if( strcmp(tempInc->user_login , user_given )== 0  )
            {
                printf("%s+" , tempInc->amount);
                incomeAmount = atoi(tempInc->amount) ;
                incomeSum = incomeAmount + incomeSum ;
            }
            tempInc = tempInc->link ;
        }
        // sum expens
        printf("\n=============\n");
        printf("expenses : \n");
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            if( strcmp(tempExp->user_login , user_given )== 0  )
            {
                printf("%s+" , tempExp->amount);
                expensAmount = atoi(tempExp->amount) ;
                expensSum = expensAmount + expensSum ;
            }
            tempExp = tempExp->link ;
        }
        net = incomeSum - expensSum ;
        printf("\nThe Current account balance is %d " , net  ) ;
        balanceReports();




    }




    if ( choice == '2')
    {
        int incomeAmount , incomeSum = 0 , expensAmount , expensSum = 0 ;
        int net  , year , search ;
        printf("Please enter the desired year : ") ;
        scanf("%d" , &year );
        // sum income
        printf("incomes for %d : \n", year);
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            search = atoi(tempInc-> year) ;
            if( search == year && strcmp(tempInc->user_login , user_given )== 0  )
            {
                printf("%s+" , tempInc->amount);
                incomeAmount = atoi(tempInc->amount) ;
                incomeSum = incomeAmount + incomeSum ;
            }
            tempInc = tempInc->link ;
        }
        // sum expens
        printf("\n=============\n");
        printf("expenses for %d : \n" , year );
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            search = atoi(tempExp-> year) ;
            if( search == year && strcmp(tempExp->user_login , user_given )== 0  )
            {
                printf("%s+" , tempExp->amount);
                expensAmount = atoi(tempExp->amount) ;
                expensSum = expensAmount + expensSum ;
            }
            tempExp = tempExp->link ;
        }
        net = incomeSum - expensSum ;
        printf("\nThe Current account balance for %d is %d " , year, net ) ;
        balanceReports();


    }



    if (choice == '3')
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int incomeAmount , incomeSum = 0 , expensAmount , expensSum = 0 ;
        int net ;
        printf("Please enter the start date(yyyy/mm/dd) : ") ;
        scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
        printf("\nPlease enter the end date(yyyy/mm/dd) : ");
        scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
        // sum income
        printf("incomes : \n");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if( validDate == 1 && strcmp(tempInc->user_login , user_given )== 0  )
            {
                printf("%s+" , tempInc->amount);
                incomeAmount = atoi(tempInc->amount) ;
                incomeSum = incomeAmount + incomeSum ;
            }
            tempInc = tempInc->link ;
        }

        // sum expens
        printf("\n=============\n");
        printf("expenses : \n" );
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if( validDate == 1 && strcmp(tempExp->user_login , user_given )== 0  )
            {
                printf("%s+" , tempExp->amount);
                expensAmount = atoi(tempExp->amount) ;
                expensSum = expensAmount + expensSum ;
            }
            tempExp = tempExp->link ;
        }
        net = incomeSum - expensSum ;
        printf("\nThe account balance is : %d " , net ) ;
        balanceReports();



    }
    if ( choice == '4' )
    {
        system("cls");
        int startYear , startDay , startMonth ;
        int endYear , endDay , endMonth ;
        int searchYear , searchDay , searchMonth ;
        int incomeAmount , incomeSum = 0 , expensAmount , expensSum = 0 ;
        int net ;
        printf("Please specify your expens type  for search: ");
        int select ;
        printf("\n\n");
        printf("                           \xDB\xDB\xDB\xDB\xB2 1. All Time   ");
        printf("\n\n");
        printf("                           \xDB\xDB\xDB\xDB\xB2 2. between two Dates   ");
        printf("\n\n");
        printf("Please enter your choice : ");
        select = getche();
        printf("\n");
        switch(select)
        {
            case '1':
                startYear = 0 , startMonth = 0 , startDay = 0 ;
                endYear = 9999999 , endMonth = 9999999 , endDay = 9999999 ;
                break;
            case '2':
                printf("Tarikh aval ra vared konid (yyyy/mm/dd) : ") ;
                scanf("%d/%d/%d" , &startYear , &startDay , &startMonth) ;
                printf("\nTarikh dovom ra vared konid (yyyy/mm/dd) : ");
                scanf("%d/%d/%d" , &endYear , &endDay , &endMonth) ;
                break;

        }
        // sum income
        printf("incomes : \n");
        tempInc = startInc ;
        while ( tempInc != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempInc->year);
            searchDay = atoi(tempInc->day);
            searchMonth = atoi(tempInc->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if( validDate == 1 && strcmp(tempInc->user_login , user_given )== 0  )
            {
                printf("Amount : %s\n" , tempInc->amount);
                printf("source : %s\n" , tempInc->source);
                printf("Date : %s/%s/%s\n" , tempInc->year , tempInc->month , tempInc->day);
                printf("description : %s\n" , tempInc->description);
                printf("==========================\n");
                incomeAmount = atoi(tempInc->amount) ;
                incomeSum = incomeAmount + incomeSum ;
            }
            tempInc = tempInc->link ;
        }

        // sum expens
        printf("\n=============\n");
        printf("expenses : \n" );
        tempExp = startExp ;
        while ( tempExp != NULL )
        {
            int validDate = 0 ;
            searchYear = atoi(tempExp->year);
            searchDay = atoi(tempExp->day);
            searchMonth = atoi(tempExp->month);
            validDate = checkDate (startYear ,startDay ,startMonth ,endYear ,endDay ,endMonth ,searchYear ,searchDay ,searchMonth );
            if( validDate == 1 && strcmp(tempExp->user_login , user_given )== 0  )
            {
                printf("Amount : %s\n" , tempExp->amount);
                printf("source : %s\n" , tempExp->source);
                printf("Date : %s/%s/%s\n" , tempExp->year , tempExp->month , tempExp->day);
                printf("description : %s\n" , tempExp->description);
                printf("==========================\n");
                expensAmount = atoi(tempExp->amount) ;
                expensSum = expensAmount + expensSum ;
            }
            tempExp = tempExp->link ;
        }
        net = incomeSum - expensSum ;
        printf("\nThe account balance is : %d " , net ) ;
        balanceReports();


    }






    if ( choice == '5' )
    {
        system("cls") ;
        main_menu ();
    }




}



