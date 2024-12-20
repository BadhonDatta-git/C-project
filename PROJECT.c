#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

char username[50];  //username variable declare
char password[50];   // password variable decalre
int new_amount1=50000;    //the amount user has from the start variable declaration and assigned for Transaction history.txt
double new_amount2=50000; //the amount user has from the start variable declaration and assigned for Balance.txt
int points=90;  //the amount of points user has fromt he start variable delaration and assigned
void file_history (char phone_number[],int amount,char reference[]);   //function prototypes declaration
void file_balance(double balance);
void menu ();
void send_money_local();
void send_money_foreign();
void pay_bills();
int transaction_history();

void games ();
void quizzard ();
char square[10]= {'o','1','2','3','4','5','6','7','8','9'};
int tic_tac_toe ();
void board ();
int check_win();

void withdraw_points();
int balance_check();
int exit_program();
int login();







int main()
{
    system("COLOR BC");


    printf("                              ---                                                                                 \n");
    printf("                             /   \\                                                                               \n");
    printf("                            /     \\                                                                              \n");
    printf("                           /       \\                                                                             \n");
    printf("                          /         \\                                                                            \n");
    printf("                         /    .      \\                                                                           \n");
    printf("                        /    / \\      \\                                                                         \n");
    printf("                       /    /   \\      \\                                                                        \n");
    printf("                      /    /     \\      \\                                                                       \n");
    printf("                     /    /       \\      \\                                                                      \n");
    printf("                    /    /         \\      \\                                                                     \n");
    printf("                   /    /           \\    /                                                                       \n");
    printf("                  /    /             \\  /                                                                        \n");
    printf("                 /    /               \\/                                                                         \n");
    printf("                /    /                                                                                            \n");
    printf("               /    /                                                                                             \n");
    printf("              /    /        .                                                                                     \n");
    printf("             /    /         | \\       | .-------  |       |      .------- .-------. .-------  |       |          \n");
    printf("            /    /          |  \\      | |         |       |      |        |       | |         |       |          \n");
    printf("           /    /           |   \\     | |         |       |      |        |       | |         |       |          \n");
    printf("          /    /            |    \\    | .-------. |       |      |        |-------| .-------. |-------|          \n");
    printf("         /    /             |     \\   |         | |       |      |        |       |         | |       |          \n");
    printf("        /    /              |      \\  |         | |       |      |        |       |         | |       |          \n");
    printf("       /    /               |       \\ |         | |       |      |        |       |         | |       |          \n");
    printf("      /    /                |        \\.  -------. .-------.      .------- |       |  -------. |       |          \n");
    printf("     /    /                                                                                                       \n");
    printf("    /    /                =================================================================================       \n");
    printf("   /    /                                                                                                         \n");
    printf("  /    /                                                                                                          \n");
    printf(" /    /                                                                                                           \n");
    printf(" \\   /--------------------------------------------------------|                                                  \n");
    printf("  \\                                                           |                                                  \n");
    printf("   -----------------------------------------------------------|                                                   \n");




    Sleep(5000);
    system("cls");
    login();

}





void file_balance(double balance) //create and write balance on Balance.txt
{
    new_amount2=new_amount1;  //update the value of balance after every transaction
    FILE *fptr;
    fptr = fopen("Balance.txt","w");
    char command1[100]="Current_Balance";
    fprintf(fptr,"%s\n",command1);
    fprintf(fptr,"%.0lf\t",new_amount2);
    fclose(fptr);


}

void file_history (char phone_number[],int amount,char reference[]) //create and update all of the transaction on Transaction History.txt
{
    char command1[30]="Phone_Number:";
    char command2[30]="Transacted_Amount:";
    char command3[100]="Reference:";
    char command4[30]="Current_Amount:";
    FILE *fptr;
    fptr = fopen("Transaction History.txt","a");
    fprintf(fptr,"%s\n",command1);
    fprintf(fptr,"%s\t",phone_number);

    fprintf(fptr,"\n%s",command2);
    fprintf(fptr,"\t%d\t",amount);

    fprintf(fptr,"\n%s",command3);
    fprintf(fptr,"%s\t",reference);


    new_amount1=new_amount1-amount;
    fprintf(fptr,"\n%s",command4);
    fprintf(fptr,"\t%d\n",new_amount1);

    fclose(fptr);
}




int login()  //log in with username and password
{
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                     USER LOG IN SYSTEM                         ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    printf("Username:");
    fflush(stdin);
    gets(username);
    if(strcmp(username,"Team01")==0)
    {
        printf("Give password:");
        fflush(stdin);
        gets(password);

        if(strcmp(password,"admin01")==0)
        {
            system("cls");
            printf("\n\t\t\tLogin Successful\n");

            menu();
        }
        else
        {
            printf("Wrong Password");
           Sleep(1000);
           system("cls");

            login();
        }
    }
    else
    {
        printf("Invalid Username");
          Sleep(1000);
         system("cls");
        login();
    }


    return 0;
}


void menu ()  //calling functions
{
    int option;
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                           MENU                                 ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");

    printf("1.Send Money(Local)\n");
    printf("2.Send Money(Foreign)\n");
    printf("3.Pay Biils\n");
    printf("4.Transaction History\n");
    printf("5.Play games to win rewards\n");
    printf("6.Withdraw game points for cash\n");
    printf("7.Balance\n");
    printf("8.Exit\n\n");

    printf("What service would you wanna take:");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
    {
        send_money_local();
    }
    break;
    case 2:
    {
        send_money_foreign();
    }
    break;
    case 3:
    {
        pay_bills();
    }
    break;
    case 4:
    {
        transaction_history();
    }
    break;
    case 5:
    {
        games ();
    }
    break;
    case 6:
    {
        withdraw_points();
    }
    break;
    case 7:
    {
        balance_check();
    }
    break;
    case 8:
    {
        exit_program();
    }
    break;

    }
}

void send_money_local() //send money function works
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                       SEND MONEY (LOCAL)                       ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    int amount;
    char confirm,reference[1000],phone_number[20];
    printf("Enter Phone number:+88");
    scanf("%s",phone_number);

    printf("Enter Amount:");
    scanf("%d",&amount);


    printf("Reference:");
    fflush(stdin);
    gets(reference);

    printf("Enter password:");
    fflush(stdin);
    gets(password);


    if(strcmp(password,"admin01")==0)
    {
        fflush(stdin);
        printf("Press any key to confirm and \"n\" to stop: ");
        scanf("   %c",&confirm);

        if(confirm == 'n')
        {
            system("cls");
            send_money_local();
        }
        else
        {
            printf("Transaction completed");
            file_history(phone_number,amount,reference);
            file_balance(amount);
        }
    }
    else
    {
        printf("Wrong Password");
    }

    printf("\nGoing  to menu");
    Sleep(1000);
    system("cls");
    menu();

}


void send_money_foreign()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                       SEND MONEY (Foreign)                     ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    int amount;
    char confirm,country[10],reference[100],phone_number[20];
    printf("Enter country:");
    fflush(stdin);
    gets(country);

    if(strcmp(country,"India")==0 || strcmp(country,"INDIA")==0 || strcmp(country,"india")==0)
    {
        int country_code=91;
        printf("Enter Phone number:+%d",country_code);
        scanf("%s",phone_number);
    }
    else if(strcmp(country,"Canada")==0 || strcmp(country,"CANADA")==0 || strcmp(country,"canda")==0)
    {
        int country_code=1;
        printf("Enter Phone number:+%d",country_code);
        scanf("%s",phone_number);
    }
    else if(strcmp(country,"England")==0 || strcmp(country,"ENGLAND")==0 || strcmp(country,"england")==0)
    {
        int country_code=44;
        printf("Enter Phone number:+%d",country_code);
        scanf("%s",phone_number);
    }
    else if(strcmp(country,"China")==0 || strcmp(country,"CHINA")==0 || strcmp(country,"china")==0)
    {
        int country_code=86;
        printf("Enter Phone number:+%d",country_code);
        scanf("%s",phone_number);
    }
    else
    {
        printf("Can't transact money to this country");
        Sleep(1000);
        send_money_foreign();
    }

    printf("Enter Amount:");
    scanf("%d",&amount);


    printf("Reference:");
    fflush(stdin);
    gets(reference);


    printf("Enter password:");
    fflush(stdin);
    gets(password);



    if(strcmp(password,"admin01")==0)
    {
        fflush(stdin);
        printf("Press any key to confirm and \"n\" to stop: ");
        scanf("   %c",&confirm);

        if(confirm == 'n')
        {
            system("cls");
            send_money_foreign();
        }
        else
        {
            printf("Transaction completed");
            file_history(phone_number,amount,reference);
            file_balance(amount);
        }
    }
    else
    {
        printf("Wrong Password");
    }


    printf("\nGoing  to menu");
    Sleep(1000);
    system("cls");
    menu();


}



void  pay_bills()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                           PAY BILLS                            ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    int billchoose;
    printf("\t\tBill Payment");
    printf("\n1.Pay Electricity bill\n");
    printf("2.Pay Gas bill\n");
    printf("3.Pay Water bill\n");
    printf("4.Pay internet bill\n");

    printf("What bill do you want to pay:");

    scanf("%d",&billchoose);

    switch(billchoose)
    {
    case 1:
    {
        system("cls");
        printf("|----------------------------------------------------------------------|\n");
        printf("|**********************************************************************|\n");
        printf("|***                        PAY ELECTRICITY BILL                    ***|\n");
        printf("|**********************************************************************|\n");
        printf("|----------------------------------------------------------------------|\n");
        int amount;
        char confirm,reference[100],phone_number[20];
        printf("Enter Phone number:+88");
        scanf("%s",phone_number);

        printf("Enter Amount:");
        scanf("%d",&amount);


        printf("Reference(service name & service id):");
        fflush(stdin);
        gets(reference);

        printf("Enter password:");
        fflush(stdin);
        gets(password);


        if(strcmp(password,"admin01")==0)
        {
            fflush(stdin);
            printf("Press any key to confirm and \"n\" to stop: ");
            scanf("   %c",&confirm);

            if(confirm == 'n')
            {
                system("cls");
                pay_bills();
            }
            else
            {
                printf("Transaction completed");
                file_history(phone_number,amount,reference);
                file_balance(amount);
            }
        }
        else
        {
            printf("Wrong Password");
        }

        printf("\nGoing  to menu");
        Sleep(1000);
        system("cls");
        menu();

    }
    break;
    case 2:
    {
        system("cls");
        printf("|----------------------------------------------------------------------|\n");
        printf("|**********************************************************************|\n");
        printf("|***                          PAY GAS BILL                          ***|\n");
        printf("|**********************************************************************|\n");
        printf("|----------------------------------------------------------------------|\n");
        int amount;
        char confirm,reference[100],phone_number[20];
        printf("Enter Phone number:+88");
        scanf("%s",phone_number);

        printf("Enter Amount:");
        scanf("%d",&amount);


        printf("Reference(service name & service id):");
        fflush(stdin);
        gets(reference);

        printf("Enter password:");
        fflush(stdin);
        gets(password);


        if(strcmp(password,"admin01")==0)
        {
            fflush(stdin);
            printf("Press any key to confirm and \"n\" to stop: ");
            scanf("   %c",&confirm);

            if(confirm == 'n')
            {
                system("cls");
                pay_bills();
            }
            else
            {
                printf("Transaction completed");
                file_history(phone_number,amount,reference);
                file_balance(amount);
            }
        }
        else
        {
            printf("Wrong Password");
        }

        printf("\nGoing  to menu");
        Sleep(1000);
        system("cls");
        menu();

    }
    break;
    case 3:
    {
        system("cls");
        printf("|----------------------------------------------------------------------|\n");
        printf("|**********************************************************************|\n");
        printf("|***                          PAY WATER BILL                        ***|\n");
        printf("|**********************************************************************|\n");
        printf("|----------------------------------------------------------------------|\n");
        int amount;
        char confirm,reference[100],phone_number[20];
        printf("Enter Phone number:+88");
        scanf("%s",phone_number);

        printf("Enter Amount:");
        scanf("%d",&amount);


        printf("Reference (service name & service id):");
        fflush(stdin);
        gets(reference);

        printf("Enter password:");
        fflush(stdin);
        gets(password);


        if(strcmp(password,"admin01")==0)
        {
            fflush(stdin);
            printf("Press any key to confirm and \"n\" to stop: ");
            scanf("   %c",&confirm);

            if(confirm == 'n')
            {
                system("cls");
                pay_bills();
            }
            else
            {
                printf("Transaction completed");
                file_history(phone_number,amount,reference);
                file_balance(amount);
            }
        }
        else
        {
            printf("Wrong Password");
        }

        printf("\nGoing  to menu");
        Sleep(1000);
        system("cls");
        menu();

    }
    break;
    case 4:
    {
        system("cls");
        printf("|----------------------------------------------------------------------|\n");
        printf("|**********************************************************************|\n");
        printf("|***                        PAY INTERNET BILL                       ***|\n");
        printf("|**********************************************************************|\n");
        printf("|----------------------------------------------------------------------|\n");
        int amount;
        char confirm,reference[100],phone_number[20];
        printf("Enter Phone number:+88");
        scanf("%s",&phone_number);

        printf("Enter Amount:");
        scanf("%d",&amount);


        printf("Reference(service name & service id):");
        fflush(stdin);
        gets(reference);

        printf("Enter password:");
        fflush(stdin);
        gets(password);


        if(strcmp(password,"admin01")==0)
        {
            fflush(stdin);
            printf("Press any key to confirm and \"n\" to stop: ");
            scanf("   %c",&confirm);

            if(confirm == 'n')
            {
                system("cls");
                pay_bills();
            }
            else
            {
                printf("Transaction completed");
                file_history(phone_number,amount,reference);
                file_balance(amount);
            }
        }
        else
        {
            printf("Wrong Password");
        }

        printf("\nGoing  to menu");
        Sleep(1000);
        system("cls");
        menu();

    }
    break;
    }

}

int transaction_history()
{
    char confirm;
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                      TRANSACTION HISTORY                       ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    FILE* ptr = fopen("Transaction History.txt", "r");
    if (ptr == NULL)
    {
        printf("no such file.");
        return 0;
    }


    char buf[10000];
    while (fscanf(ptr, "%s ", buf) == 1)
        printf("%s\n", buf);


    printf("\nPress any key to go to menu: ");
    scanf("   %c",&confirm);
    Sleep(1000);
    system("cls");
    menu();

}



void games ()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                           GAMES                                ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    int input;

    printf("\nWelcome.\nWhich game would you like to play?\n");
    printf("1.Tic-Tac-Toe\n");
    printf("2.Quizzard\n");

    scanf("%d",&input);

    if(input==1 || input==2 )
    {
        if(input==1)
        {
            tic_tac_toe();
        }
        else if(input==2)
        {
            quizzard();
        }
        else
        {
            printf("Invalid request");
        }

    }
}


int tic_tac_toe ()
{
    int player = 1, i, choice;

    char mark;


    do
    {
        board();
        player = (player % 2) ? 1 : 2;

        printf("Player %d, Enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';

        if (choice == 1 && square[1] == '1')
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");

            player--;
            getch();
        }
        i = check_win();

        player++;
    }

    while (i ==  - 1);

    board();

    if (i == 1)
    {
        printf("==>\aPlayer %d win ", --player);
        points=points+10;

        printf("\nGoing  to menu");
        Sleep(1000);
        system("cls");
        menu();


    }
    else
        printf("==>\aGame draw");

    getch();

    return 0;

};

void board ()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                          TIC-TAC-TOE                           ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");

}


int check_win()
{

    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
             != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;

}



void quizzard ()
{

    int lvl,point=0,lose_point=0;
    char answer1[50],answer2[50],answer3[50],answer4[50],answer5[50];
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                          QUIZZARD                              ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");

    printf("\n\nSelect your difficulty level:\n");
    printf("1.Easy\n");
    printf("2.Moderate\n");
    printf("3.Hard\n");
    scanf("%d",&lvl);
    int    cond1= lvl==1;
    int    cond2= lvl==2;
    int    cond3= lvl==3;


    if(cond1==1 || cond2==1 || cond3==1)
    {
        switch(cond1)
        {
        case 1:
        {
            system("cls");
            printf("|----------------------------------------------------------------------|\n");
            printf("|**********************************************************************|\n");
            printf("|***                          QUIZZARD                              ***|\n");
            printf("|**********************************************************************|\n");
            printf("|----------------------------------------------------------------------|\n");
            printf("You chose your difficulty level Easy\n");
            printf("\nQuestion 1:Which state is famous for Hollywood?");
            scanf("%s",&answer1);
            {
                if(strcmp(answer1,"California")==0 || strcmp(answer1,"california")==0)
                {
                    printf("\nCorrect");
                    point++;
                }
                else
                {
                    printf("\nWrong");
                    lose_point++;
                }
            }
            printf("\nQuestion 2:On which holiday do you go trick-or-treating?");
            scanf("%s",&answer2);
            if(strcmp(answer2,"Halloween")==0||strcmp(answer2,"halloween")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 3:In which season do leaves die?");
            scanf("%s",&answer3);
            if(strcmp(answer3,"Fall")==0||strcmp(answer3,"fall")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 4:Where is the Great Pyramid of Giza?");
            scanf("%s",&answer4);
            if(strcmp(answer4,"egypt")==0||strcmp(answer4,"Egypt")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nQuestion 5:Which is the fastest land animal?");
            scanf("%s",&answer5);
            if(strcmp(answer5,"Cheetah")==0||strcmp(answer5,"cheetah")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nCorrect=%d",point);
            printf("\nWrong=%d",lose_point);
            points=points+point;

            printf("\nGoing  to menu");
            Sleep(1000);
            system("cls");
            menu();

        }
        break;
        }
        switch(cond2)
        {
        case 1:
        {
            system("cls");
            printf("|----------------------------------------------------------------------|\n");
            printf("|**********************************************************************|\n");
            printf("|***                          QUIZZARD                              ***|\n");
            printf("|**********************************************************************|\n");
            printf("|----------------------------------------------------------------------|\n");
            printf("You chose your difficulty level Moderate\n");
            printf("\nQuestion 1:What is the shortcut for the copy function on most computers?");
            scanf("%s",&answer1);
            {
                if(strcmp(answer1,"cntrl+c")==0)
                {
                    printf("\nCorrect");
                    point++;
                }
                else
                {
                    printf("\nWrong");
                    lose_point++;
                }
            }
            printf("\nQuestion 2:Which email service is owned by Microsoft?");
            scanf("%s",&answer2);
            if(strcmp(answer2,"Hotmail")==0||strcmp(answer2,"hotmail")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 3:What part of the atom has no electric charge?");
            scanf("%s",&answer3);
            if(strcmp(answer3,"Neutron")==0||strcmp(answer3,"neutron")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 4:Which planet has the most gravity?");
            scanf("%s",&answer4);
            if(strcmp(answer4,"Jupiter")==0||strcmp(answer4,"jupiter")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nQuestion 5:Which country invented tea?");
            scanf("%s",&answer5);
            if(strcmp(answer5,"China")==0||strcmp(answer5,"china")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nCorrect=%d",point);
            printf("\nWrong=%d",lose_point);
            points=points+point;

            printf("\nGoing  to menu");
            Sleep(1000);
            system("cls");
            menu();
            break;
        }

        }
        switch(cond3)
        {
        case 1:
        {
            system("cls");
            printf("|----------------------------------------------------------------------|\n");
            printf("|**********************************************************************|\n");
            printf("|***                          QUIZZARD                              ***|\n");
            printf("|**********************************************************************|\n");
            printf("|----------------------------------------------------------------------|\n");
            printf("You chose your difficulty level Hard");
            printf("\nQuestion 1:Which company makes the Galaxy series of smartphones?");
            scanf("%s",&answer1);
            {
                if(strcmp(answer1,"Samsung")==0 || strcmp(answer1,"samsung")==0)
                {
                    printf("\nCorrect");
                    point++;
                }
                else
                {
                    printf("\nWrong");
                    lose_point++;
                }
            }
            printf("\nQuestion 2: Elon Musk is the CEO of which famous brand?");
            scanf("%s",&answer2);
            if(strcmp(answer2,"Tesla")==0||strcmp(answer2,"tesla")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 3:Which force attracts everything towards the earth?");
            scanf("%s",&answer3);
            if(strcmp(answer3,"Gravity")==0||strcmp(answer3,"gravity")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }


            printf("\nQuestion 4:What is the study of kidneys called?");
            scanf("%s",&answer4);
            if(strcmp(answer4,"Nephrology")==0||strcmp(answer4,"nephrology")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nQuestion 5:What is the technical term for a lie detector?");
            scanf("%s",&answer5);
            if(strcmp(answer5,"Polygraph")==0||strcmp(answer5,"polygraph")==0)
            {
                printf("\nCorrect");
                point++;
            }
            else
            {
                printf("\nWrong");
                lose_point++;
            }

            printf("\nCorrect=%d",point);
            printf("\nWrong=%d",lose_point);
            points=points+point;
            printf("\nGoing  to menu");
            Sleep(1000);
            system("cls");
            menu();
        }
        break;
        }

    }
    else
    {
        printf("Invalid Input");

        Sleep(1000);
        system("cls");
        quizzard();


    }

}


void withdraw_points()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                    WITHDRAW MONEY FROM POINTS                  ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    int convert;
    char confirm;
    printf("Your current points are:%d",points);
    if(points>=100)
    {
        printf("\nHow much points do you want to convert(10tk for every 100points):");
        scanf("%d",&convert);
        if(convert%100==0)
        {


            printf("Enter password:");
            fflush(stdin);
            gets(password);



            if(strcmp(password,"admin01")==0)
            {
                fflush(stdin);
                printf("Press any key to confirm and \"n\" to stop: ");
                scanf("   %c",&confirm);

                if(confirm == 'n')
                {
                    system("cls");
                    withdraw_points();
                }
                else
                {
                    printf("Transaction completed");
            new_amount1=new_amount1+((convert/100)*10);
            new_amount2=new_amount2+((convert/100)*10);
            file_balance((convert/100)*10);
                    printf("\nNew amount:%d",new_amount1);
                    points=points-convert;
                    printf("\nPoints:%d",points);
                }
            }
            else
            {
                printf("Wrong Password");
            }



            printf("\nGoing  to menu");
            Sleep(3000);
            system("cls");
            menu();


        }
        else
        {

            printf("\nInvalid amount(The amount must be divisible by 100)");
            Sleep(1000);
            system("cls");
            withdraw_points();

        }

    }
    else
    {
        printf("\nYou don't have enough points");
        Sleep(1000);
        system("cls");
        withdraw_points();
    }

    printf("\nGoing  to menu");
    Sleep(1000);

    menu();
}

int  balance_check()
{
    system("cls");
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                          BALANCE CHECK                         ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    char confirm;

    FILE* ptr = fopen("Balance.txt", "r");
    if (ptr == NULL)
    {
        printf("no such file.");
        return 0;
    }


    char buf[10000];
    while (fscanf(ptr, "%s ", buf) == 1)
        printf("%s\n", buf);


    printf("Press any key to go to menu: ");
    scanf("   %c",&confirm);
    Sleep(1000);
    system("cls");
    menu();


}

int exit_program()
{
    printf("|----------------------------------------------------------------------|\n");
    printf("|**********************************************************************|\n");
    printf("|***                           EXIT                                 ***|\n");
    printf("|**********************************************************************|\n");
    printf("|----------------------------------------------------------------------|\n");
    system("cls");
    getch();

}
