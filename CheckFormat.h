int check_chracter  ( char name[50] )    //this function check string is alphabet , for alphabet return 1
{
    int i , contain , sum= 0  ;
    contain = strlen(name) ;
    strupr(name);
    for (i= 0 ; i <= contain ; i++ )
    {
         sum = sum + isalpha(name[i]) ; // isalpha for uppercase ch returns 1 ;
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
        if ( 1 == isdigit(digit[i])) //isdigit for digit returns 1
            sum ++ ;
    }
    if ( sum == contain )
        return 1 ;
    else
        return 0 ;
}

int check_pass (char pass [50])
{
    int i , upper= 0 , lowwer =0 , digit =0 , special_ch = 0 ;
    char re_password [50] ;
    if ( 5 > strlen(pass))
        MessageBox(0,"password must be more than 5 character!\nPlease Try again!","Error!!",0);

        else if ( 50 < strlen(pass))
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
        MessageBox(0,"There must be at least one Uppercase!\nPlease Try again!","Error!!",0);
    if (lowwer==0)
        MessageBox(0,"There must be at least one Lowercase!\nPlease Try again!","Error!!",0);
    if (digit==0)
        MessageBox(0,"There must be at least one Digit!\nPlease Try again!","Error!!",0);
    if (special_ch==0)
        MessageBox(0,"There must be at least one Special Character!\nPlease Try again!","Error!!",0);
    else
    {
        do
        {
            printf("\n\xDB\xDB\xDB\xDB\xB2 Confirm your Password : ");
            char starRePass [50] , d = ' ';
            int b = 0 ;
            while (b<50) // print * instead paswword
            {
                starRePass[b] = getch();
                d = starRePass[b];
                if (d==13)
                    break ;
                printf("*");
                b++;
            }
            starRePass[b] = '\0';
            b = 0;
            strcpy(re_password , starRePass );
            printf("\n");
            if(strcmp(re_password,pass)== 1 || strlen(pass) != strlen(re_password) )
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
        MessageBox(0,"The email address must be start with letter !\nPlease Try again!","Error!!",0);
    for (i=0 ; i < contain ; i++)
    {
        if (email[i] == '@' )
            adsign = 1;
        if (email[i] == '.' )
            dot = 1 ;

    }

    if (adsign == 0 || dot == 0)
        MessageBox(0,"The email address must be have @ and DOT. !\nPlease Try again!","Error!!",0);
    if  (email[contain]== '.')
        MessageBox(0,"dot can not be in the last character of the email.!\nPlease Try again!","Error!!",0);
    if  (contain <= 7 )
        MessageBox(0,"email must be more than 7 character !\nPlease Try again!","Error!!",0);
    if (isalpha(email[0])== 0 || adsign == 0 || dot == 0 || email[contain]== '.' || contain <= 7 )
        return 0 ;
    else
        return 1 ;
}
// Check Date algorithm => image is here : https://postimg.cc/hQRr7msv
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
void exitApp(void)
{
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
}


