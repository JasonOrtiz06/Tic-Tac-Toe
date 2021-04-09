#include <stdio.h>
#include <stdlib.h>
/*
 * Tic-Tac-Toe.c
 *
 *  Projekt Tic-Tac-Toe von Jason
 *  Praktikum April 2021
 */

void spielereingabe_setzespielfeld(char c_spielerzeichen[1], char c_spielername[16], char *c_spielfeld, char *c_spielerfarbe)
{
    int i_einspieler = 0;
    int i_falscheingabe = 0;
    int i_spielereingabecheck = 1;

    printf(" %s %s \x1b[0m Wo soll dein %c gesetzt werden?:", c_spielerfarbe, c_spielername, c_spielerzeichen);
    do
    {

        i_einspieler = 0;
        i_falscheingabe = scanf("%d", &i_einspieler);
        if (i_falscheingabe == 0)
        {
            printf("Das ist keine Zahl du Scherzkeks !!! Versuche es erneut :");
        }

        if (i_einspieler >= 1 && i_einspieler <= 9)
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
        if (c_spielfeld[i_einspieler - 1] == 'O' || c_spielfeld[i_einspieler - 1] == 'X')
        {

            if (c_spielfeld[i_einspieler - 1] == c_spielerzeichen)
            {
                printf("Du hast hier bereits ein %c ! Bitte setze dein %c in ein anderes Feld : ", c_spielerzeichen, c_spielerzeichen);
            }
            else
            {
                printf("Du kannst das Zeichen eines Gegners nicht einfach mit deinem ändern! versuche es erneut!:");
            }

            do
            {
                i_einspieler = 0;
                i_falscheingabe = scanf("%d", &i_einspieler);
                if (i_falscheingabe == 0)
                {
                    printf("Das ist keine Zahl du Scherzkeks !!! Versuche es erneut :");
                }

                if (i_einspieler >= 1 && i_einspieler <= 9)
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
            i_spielereingabecheck = 1;
        }
        else
        {
            c_spielfeld[i_einspieler - 1] = c_spielerzeichen;
            i_spielereingabecheck = 0;
        }
    } while (i_spielereingabecheck == 1);
}

int main(void)
{

    //Variablendeklaration
    char c_spielfeld[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int i_gewinner = 0;
    int i_returncode = 0;
    char c_spielernamespieler1[16];
    char c_spielernamespieler2[16];
    char c_spielerfarbe1[] = "\x1b[36m";
    char c_spielerfarbe2[] = "\x1b[35m";
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
        //if schleife für Spiele1 durchgang
        if (counter == 0 || counter == 2 || counter == 4 || counter == 6 || counter == 8)
        {
            spielereingabe_setzespielfeld('X', c_spielernamespieler1, c_spielfeld, c_spielerfarbe1);
        }
        else
        {
            spielereingabe_setzespielfeld('O', c_spielernamespieler2, c_spielfeld, c_spielerfarbe2);
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
