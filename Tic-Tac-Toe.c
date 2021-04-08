#include <stdio.h>
#include <stdlib.h>
/*
 * Tic-Tac-Toe.c
 *
 *  Projekt Tic-Tac-Toe von Jason
 *  Praktikum April 2021
 */
int main(void)
{

    //Variablendeklaration
    char c_spielfeld[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i_einspieler1 = 0;
    int i_einspieler2 = 0;
    int i_gewinner = 0;
    int i_spieler1eingabecheck = 1;
    int i_spieler2eingabecheck = 1;
    int i_returncode = 0;
    int i_falscheingabe = 0;
    char c_spielernamespieler1[16];
    char c_spielernamespieler2[161];
    //Eingabe der Spielernamen

    printf("Spieler1 wie ist dein Name? !!!Der Name darf maximal 15Buchstaben lang sein, ansonsten wird er auf 15 Zeichen gekürzt!!!");
    scanf("%s", &c_spielernamespieler1);
    c_spielernamespieler1[15] = '\0';

    printf("Spieler2 wie ist dein Name !!!Der Name darf maximal 15Buchstaben lang sein, ansonsten wird er auf 15 Zeichen gekürzt!!!");
    scanf("%s", &c_spielernamespieler2);
    c_spielernamespieler2[15] = '\0';

    //Schleife für Spieldurchlauf
    for (int counter = 0; counter < 9; counter++)
    {
        //Löschen des Spielfelds

        system("clear");

        //Spielfeldausgabe
        printf("%c|%c|%c\n-----\n%c|%c|%c\n-----\n%c|%c|%c\n", c_spielfeld[0], c_spielfeld[1], c_spielfeld[2], c_spielfeld[3], c_spielfeld[4], c_spielfeld[5], c_spielfeld[6], c_spielfeld[7], c_spielfeld[8]);
        //Zurücksetzung des Wertes der Variable einspieler1
        i_einspieler1 = 0;
        i_einspieler2 = 0;

        //if schleife für Spiele1 durchgang
        if (counter == 0 || counter == 2 || counter == 4 || counter == 6 || counter == 8)
        {
            printf("%s in welchem der 9 Felder willst du dein X setzen ? :", c_spielernamespieler1);
            do
            {
                i_falscheingabe = scanf("%d", &i_einspieler1);
                if (i_falscheingabe == 0)
                {
                    printf("Das ist keine Zahl du Scherzkeks!!! Versuche es erneut");
                }

                if (i_einspieler1 >= 1 && i_einspieler1 <= 9)
                {
                    i_falscheingabe = 1;
                }
                else
                {

                    i_falscheingabe = 0;
                }

                while (getchar() != '\n')
                    ;
            } while (i_falscheingabe == 0);

            //c_spielfeld[i_einspieler1-1]= 'X';
            do
            {
                if (c_spielfeld[i_einspieler1 - 1] == 'X' || c_spielfeld[i_einspieler1 - 1] == 'O')
                {
                    if (c_spielfeld[i_einspieler1 - 1] == 'X')
                    {
                        printf("Du hast hier bereits ein X ! Bitte setze dein X in ein anderes Feld : ");
                    }
                    else
                    {
                        printf("Du kannst das Zeichen eines Gegners nicht einfach mit deinem ändern! versuche es erneut!:");
                    }

                    do
                    {
                        i_einspieler1 = 0;
                        i_falscheingabe = scanf("%d", &i_einspieler1);
                        if (i_falscheingabe == 0)
                        {
                            printf("das ist kein Zeichen du Scherzkeks !!!  Versuche es erneut  :");
                        }

                        if (i_einspieler1 >= 1 && i_einspieler1 <= 9)
                        {
                            i_falscheingabe = 1;
                        }
                        else
                        {

                            i_falscheingabe = 0;
                        }

                        while (getchar() != '\n')
                            ;
                    } while (i_falscheingabe == 0);
                    i_spieler1eingabecheck = 1;
                }
                else
                {
                    c_spielfeld[i_einspieler1 - 1] = 'X';
                    i_spieler1eingabecheck = 0;
                }
            } while (i_spieler1eingabecheck == 1);
        }
        else
        {
            //Spielfeldausgabe
            //printf("%c|%c|%c\n-----\n%c|%c|%c\n-----\n%c|%c|%c\n", c_spielfeld[0],c_spielfeld[1], c_spielfeld[2], c_spielfeld[3],c_spielfeld[4], c_spielfeld[5], c_spielfeld[6],c_spielfeld[7], c_spielfeld[8]);

            printf("%s Wo soll dein O gesetzt werden?:", c_spielernamespieler2);
            do
            {
                i_einspieler2 = 0;
                i_falscheingabe = scanf("%d", &i_einspieler2);
                if (i_falscheingabe == 0)
                {
                    printf("Das ist keine Zahl du Scherzkeks !!! Versuche es erneut :");
                }

                if (i_einspieler2 >= 1 && i_einspieler2 <= 9)
                {
                    i_falscheingabe = 1;
                }
                else
                {

                    i_falscheingabe = 0;
                }

                while (getchar() != '\n')
                    ;
            } while (i_falscheingabe == 0);

            //c_spielfeld[i_einspieler2-1]= 'O';
            do
            {
                if (c_spielfeld[i_einspieler2 - 1] == 'O' || c_spielfeld[i_einspieler2 - 1] == 'X')
                {

                    if (c_spielfeld[i_einspieler2 - 1] == 'O')
                    {
                        printf("Du hast hier bereits ein O ! Bitte setze dein O in ein anderes Feld : ");
                    }
                    else
                    {
                        printf("Du kannst das Zeichen eines Gegners nicht einfach mit deinem ändern! versuche es erneut!:");
                    }

                    do
                    {
                        i_einspieler2 = 0;
                        i_falscheingabe = scanf("%d", &i_einspieler2);
                        if (i_falscheingabe == 0)
                        {
                            printf("Das ist keine Zahl du Scherzkeks !!! Versuche es erneut :");
                        }

                        if (i_einspieler2 >= 1 && i_einspieler2 <= 9)
                        {
                            i_falscheingabe = 1;
                        }
                        else
                        {

                            i_falscheingabe = 0;
                        }

                        while (getchar() != '\n')
                            ;
                    } while (i_falscheingabe == 0);
                    i_spieler2eingabecheck = 1;
                }
                else
                {
                    c_spielfeld[i_einspieler2 - 1] = 'O';
                    i_spieler2eingabecheck = 0;
                }
            } while (i_spieler2eingabecheck == 1);
        }
        //Horizontale Gewinnfälle Spieler1

        if ((c_spielfeld[0] == 'X' && c_spielfeld[1] == 'X' && c_spielfeld[2] == 'X') ||
            (c_spielfeld[3] == 'X' && c_spielfeld[4] == 'X' && c_spielfeld[5] == 'X') ||
            (c_spielfeld[6] == 'X' && c_spielfeld[7] == 'X' && c_spielfeld[8] == 'X') ||

            //Vertikale Gewinnfälle Spieler1

            (c_spielfeld[0] == 'X' && c_spielfeld[3] == 'X' && c_spielfeld[6] == 'X') ||
            (c_spielfeld[1] == 'X' && c_spielfeld[4] == 'X' && c_spielfeld[7] == 'X') ||
            (c_spielfeld[2] == 'X' && c_spielfeld[5] == 'X' && c_spielfeld[8] == 'X') ||
            //Diagonale Gewinnfälle Spieler1

            (c_spielfeld[2] == 'X' && c_spielfeld[4] == 'X' && c_spielfeld[6] == 'X') ||
            (c_spielfeld[0] == 'X' && c_spielfeld[4] == 'X' && c_spielfeld[8] == 'X'))

        {

            counter = 9;
            i_gewinner = 1;
        }

        //Horizontale Gewinnfälle Spieler2

        else if ((c_spielfeld[0] == 'O' && c_spielfeld[1] == 'O' && c_spielfeld[2] == 'O') ||
                 (c_spielfeld[3] == 'O' && c_spielfeld[4] == 'O' && c_spielfeld[5] == 'O') ||
                 (c_spielfeld[6] == 'O' && c_spielfeld[7] == 'O' && c_spielfeld[8] == 'O') ||

                 //Vertikale Gewinnfälle Spieler1

                 (c_spielfeld[0] == 'O' && c_spielfeld[3] == 'O' && c_spielfeld[6] == 'O') ||
                 (c_spielfeld[1] == 'O' && c_spielfeld[4] == 'O' && c_spielfeld[7] == 'O') ||
                 (c_spielfeld[2] == 'O' && c_spielfeld[5] == 'O' && c_spielfeld[8] == 'O') ||
                 //Diagonale Gewinnfälle Spieler1

                 (c_spielfeld[2] == 'O' && c_spielfeld[4] == 'O' && c_spielfeld[6] == 'O') ||
                 (c_spielfeld[0] == 'O' && c_spielfeld[4] == 'O' && c_spielfeld[8] == 'O'))

        {

            counter = 9;
            i_gewinner = 2;
        }
    }
    switch (i_gewinner)
    {
    case 0:
        printf("Es gibt keinen Gewinner! Unentschieden");
        break;
    case 1:
        printf("%s hat Gewonnen", c_spielernamespieler1);
        break;
    case 2:
        printf("%s hat Gewonnen", c_spielernamespieler2);
        break;
    }
}
