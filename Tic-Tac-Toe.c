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
            printf("Spieler1 in welchem Feld soll dein X gesetzt werden");
            do
            {
                i_falscheingabe = scanf("%d", &i_einspieler1);
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
                    printf("Spieler1 setze dein X bitte in einem anderen Feld ");
                    do
                    {
                        i_falscheingabe = scanf("%d", &i_einspieler1);
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

            printf("Spieler2 in welchem Feld soll dein o gesetzt werden");
            do
            {
                i_falscheingabe = scanf("%d", &i_einspieler2);
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
                    printf("Spieler2 setze dein O bitte in einem anderen Feld ");

                    do
                    {
                        i_falscheingabe = scanf("%d", &i_einspieler2);
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
        printf("Unentschieden");
        break;
    case 1:
        printf("Spieler1 hat das Match gewonnen!!!");
        break;
    case 2:
        printf("Spieler 2 hat das Match gewonnen!!!");
        break;
    }
}
