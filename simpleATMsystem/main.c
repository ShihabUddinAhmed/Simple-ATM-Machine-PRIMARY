#include<stdio.h>
#include<stdlib.h>
#define j 10
#include<conio.h>
void welcome()//welcome of my customer
{
    system("color 4B");
    printf("\n\n\n\n:::::::::::::::::::::::::::::::::::::::::::::::::The City Bank Ltd::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf("\n\n\n\n                                           WELOCOME TO OUR ATM SYSTEM\n");
    system("pause");
    system("color 07");
    return 0;
}
int main()
{
    FILE *flRec;
    FILE *flName;
    FILE *flBal;
    FILE *flPin;
    int accN,accP;
    welcome();

    char name[j][50];
    flName=fopen("accnames.txt","r");//read all data from the file & save to the buffer

    for(int i=0;i<j;i++)
    {
        fgets(name[i],50,flName);
    }
    //for(int i=0;i<j;i++)
    //{
    //    printf("%s",name[i]);//some print functions to check while updating software
    //}
    fclose(flName);
    int acN[j];
    flRec=fopen("accountRec.txt","r");
    for(int i=0;i<j;i++)
    {
        fscanf(flRec,"%d",&acN[i]);
    }
    //for(int i=0;i<j;i++)
    //{
    //    printf("%d\n",acN[i]);//some print functions to check while updating software
    //}
    fclose(flRec);
    int acB[j];
    flBal=fopen("accbalance.txt","r");
    for(int i=0;i<j;i++)
    {
        fscanf(flBal,"%d",&acB[i]);
    }
    //for(int i=0;i<j;i++)
    //{
    //    printf("%d\n",acB[i]);//some print functions to check while updating software
    //}
    fclose(flBal);
    int acP[j];
    flPin=fopen("accpins.txt","r");
    for(int i=0;i<j;i++)
    {
        fscanf(flPin,"%d",&acP[i]);
    }
    //for(int i=0;i<j;i++)
    //{
    //    printf("%d\n",acP[i]);//some print functions to check while updating software
    //}
    fclose(flPin);
    char ans='y';
    int i,temp,tempH;
    while(ans=='y'||ans=='Y')
    {
        system("cls");
        system("color 07");
    printf("\n                                              YOU MUST LOGIN FIRST\n");
    printf("\n                                       Please Enter Your Account Number(8 digit)\n                                                   ");
    scanf("%d",&accN);
    if(accN==38960389)//admin account login
    {
        system("cls");
        system("color 61");
        printf("\n                              SIR, PLEASE GIVE THE RECORDS ACCORDING TO THE SERIAL\n");
        char nameA[50];
        int accoN,accoB,accoP;
        fflush(stdin);
        scanf("%[^\n]s",nameA);
        scanf("%d%d%d",&accoN,&accoB,&accoP);
        FILE *admin;
        admin=fopen("accnames.txt","a");
        fprintf(admin,"\n%s",nameA);
        fclose(admin);
        FILE *adminN;
        adminN=fopen("accountRec.txt","a");
        fprintf(adminN,"\n%d",accoN);
        fclose(adminN);
        FILE *adminB;
        adminB=fopen("accbalance.txt","a");
        fprintf(adminB,"\n%d",accoB);
        fclose(adminB);
        FILE *adminP;
        adminP=fopen("accpins.txt","a");
        fprintf(adminP,"\n%d",accoP);
        fclose(adminP);
        printf("\n\n                                                       THANK YOU SIR!\n\n");
    }
    else//customer account login
    {for(i=0;i<=j;i++)
    {
        tempH=i;
        if(acN[i] == accN)
        {
        temp = i;
        //printf("\n%d",temp);//some print functions to check while updating software
        break;
        }
    }
    if(tempH==j)
    {
        system("cls");
        system("color 47");
        printf("\n                                            YOU HAVE ENTERED WRONG ACCOUNT NUMBER.\n                                                     TRY AGAIN.\n");
    }
    else
    {
    printf("                                             Enter your pin number\n                                                ");
    scanf("%d",&accP);
    system("cls");
    if(accP==acP[temp])//checking pin
    {
        system("color 20");

    printf("                                                      WELCOME\n");
    printf("                                               %s\n",name[temp]);
    printf("                                            Please enter your choice:\n                                           1.MONEY WITHDRAW\n                                           2.CHECK BALANCE\n                                           3.TRANSFER\n                                           4.EXIT\n                                           ");
        int ch;
        scanf("%d",&ch);
        switch(ch)//evaluating customer's choice
        {
        case 1:
            {
                printf("Please enter the amount to be withdrawn      ");
                int amnt;
                scanf("%d",&amnt);
                if(amnt<=acB[temp])
                {
                if(amnt>=500)
                {
                acB[temp]=acB[temp]-amnt;
                printf("Now the available balance is %d\n",acB[temp]);
                FILE *mnyW;
                mnyW=fopen("accbalance.txt","w");
                for(i=0;i<j;i++)
                {
                    fprintf(mnyW,"%d\n",acB[i]);
                }
                fclose(mnyW);
                }
                else
                {
                    system("color 70");
                    printf("                                            Sorry, amount should be more than 500 BDT\n");}
                }
                else
                    {
                        system("color 70");
                        printf("                                            INSUFFICIENT BALLANCE\n");
                    }
                    break;
            }
        case 2:
            {
                printf("Your account balance is %d BDT\n",acB[temp]);
                break;
            }
        case 3:
            {
                printf("Enter the account number\n");
                int tnfrAc,tnfrM;
                scanf("%d",&tnfrAc);
                int tempA,tempB;
                for(i=0;i<=j;i++)
                {
                    tempB=i;
                    if(tnfrAc == acN[i])
                        {
                            tempA = i;
                            //printf("\n%d",tempA);//some print functions to check while updating software
                            break;
                        }
                }
                if(tempB==j)
                {
                    system("color 70");
                    printf("\n                                            Sorry account number is wrong\n");
                    system("pause");
                    break;

                }
                else if(tempA==temp)
                {
                    system("color 70");
                    printf("\n                                            You can't transfer money to your own account\n");
                    system("pause");
                    break;

                }
                else
                {
                    //printf("%d",temp);
                    printf("Enter the ammount to tranfer to %s",name[tempA]);
                    scanf("%d",&tnfrM);
                    if(tnfrM<=acB[temp])
                    {
                        //printf("yes");
                    acB[temp]=acB[temp]-tnfrM;
                    acB[tempA]=acB[tempA]+tnfrM;
                    FILE *mnyT;
                    mnyT=fopen("accbalance.txt","w");
                    for(i=0;i<j;i++)
                    {
                        fprintf(mnyT,"%d\n",acB[i]);
                    }
                    fclose(mnyT);
                    //printf("%d,%d",acB[temp],acB[tempA]);//some print functions to check while updating software
                    }
                    else
                    {
                        system("color 70");
                        printf("                                            Amount exceeded your current balance");
                    }
                }
                break;
            }
        case 4:
            {
                system("cls");
                system("color 61");
                printf("\n                                            THANK YOU\n                                            FOR USING OUR ATM SYSTEM.\n");
            }
        default:
            printf("\n                                             SORRY YOUR CHOICE IS WRONG. PLEASE FOLLOW THE NUMBERS SHOWING  ABOVE\n");
        }
    }
    else//access denied for wrong pin
    {
        system("color 47");
        printf("\n                                      SORRY , YOU HAVE ENTERED WRONG PIN\n");
    }
    }
    }
    system("pause");
    system("cls");//process turn to the start
    printf("\n                                                 Do you want to continue?(Y/N)\n                                                 ");
    fflush(stdin);
    scanf("%c",&ans);

    }
    if(ans=='n'||ans=='N')//defining the other option
    {
        printf("\n                                               Thanks! Best wishes for you...\n");
        system("pause");
        exit(1);

    }
    system("pause");
}
