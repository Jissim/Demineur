#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int NBR_LIGNES = 5;
const int NBR_COLONNES = 5;
char tabjeu[NBR_LIGNES][NBR_COLONNES];
char tabjeu2[NBR_LIGNES][NBR_COLONNES];
int tab_mines[NBR_LIGNES][NBR_COLONNES];
int NbMines,saisie,ligne, colonne, x, y, score, finPartie;

//FONCTION D'AFFICHAGE DE L'INTERFACE DE JEU (1)
void Affichejeu()
{

    tabjeu[NBR_LIGNES][NBR_COLONNES];
    for (int i = 0; i < NBR_LIGNES; i++)
    {
        for (int j = 0; j < NBR_COLONNES; j++)
        {
            tabjeu[i][j] = '+';// cases cachées            
            tab_mines[i][j] = 0;
        }
    }
    printf("\n\n\t[DEMINEUR]\n\n");

    printf("\n\n");
    printf("   | 1  2  3  4  5\n");
    printf("___|______________\n");
    for (int i = 0; i < NBR_LIGNES; i++)
    {
        if (i < 9)
            printf(" %d | ", i + 1);
        else
            printf("%d | ", i + 1);
        for (int j = 0; j < NBR_COLONNES; j++)
        {
            printf("%c  ", tabjeu[i][j]);
        }
        printf("\n");
    }
    

}

////////////////////////////////////////////////////////////////////
void readfile()
{
    FILE* fichier1;

    char c;

    if ((fichier1 = fopen("D:\\dem.txt", "r")) == NULL)//lecture 
    {
        printf("Error! opening file"); // en cas d'erreurs
        exit(1);
    }

    printf("----Regles du jeu----\n");
    //fgets(buffer, 100, fptr); autre méthode plus chiante
    //printf("%s\n", buffer);

    while ((c = getc(fichier1)) != EOF) printf("%c", c);
    fclose(fichier1);
}

/*void write_save()
{
    FILE* fichier2;
    char c;
    if ((fichier2 = fopen("D:\\vroum.txt", "r+")) == NULL) //écriture
    {
        printf("Error! opening file");
        exit(1);
    }
       fputs("Here we go !",fichier2);
       while ((c = getc(fichier2)) != EOF) printf("%c", c);
       fclose(fichier2);
       
       
}*/

//FONCTION PLACER LES MINES (3)
int PlacerMines()
{
    int CompteMines = 0;//compteur de mines
    int NbMines;
    printf("\nCombien de mines voulez vous ?\t");
    scanf_s("%d", &NbMines);
    while (NbMines > 24)
    {
        printf("\nsaisir le nombre de mines\t");
        scanf_s("%d", &NbMines);
    }
    printf("Vous avez choisi de placer %d bombes\n", NbMines);
    printf("Bonne chance !");



    while (CompteMines < NbMines)
    {
        ligne = rand() % NBR_LIGNES;//on choisit la ligne de manière aléatoire
        colonne = rand() % NBR_COLONNES;//on choisit la colonne de manière aléatoire
        if (tab_mines[ligne][colonne] == 0)//On vérifie que la case est libre
        {
            tab_mines[ligne][colonne] = 1;//on place un 1 pour indiquer qu'il y a une mine
            CompteMines++;  // pour la boucle recommence jusqu'a ce que la condition soit remplie
        }

    }
    return NbMines;
}
    
    /// ////////////////
    /*
    printf("\n\n"); // TEST
    printf("   | 1 2 3 4 5\n");
    printf("___|__________\n");
    for (int i = 0; i < NBR_LIGNES; i++)
    {
        if (i < 5)
            printf(" %d | ", i + 1);
        else
            printf(" %d | ", i + 1);
        for (int j = 0; j < NBR_COLONNES; j++)
        {
            printf("%d ", tab_mines[i][j]);
        }
        printf("\n");
    }
    
}*/
////////////////////////////////////
// Mines autours
int MinesAutour()
{
    NbMines = 0;
    if (tab_mines[x][y] == 1)
    {

        ///////////////////////////////////////////////////////////////////
        printf("\n\n");
        printf("   | 1 2 3 4 5\n");
        printf("___|_____________\n");
        for (int i = 0; i < NBR_LIGNES; i++)
        {
            if (i < 9)
                printf(" %d | ", i + 1);
            else
                printf("%d | ", i + 1);
            for (int j = 0; j < NBR_COLONNES; j++)
            {
                printf("%d ", tab_mines[i][j]);
            }
            printf("\n");
        }
        finPartie = 1;

        ///////////////////////////////////////////////////////////////////////

    }
    else if (x < 4 && x > 0 && y < 4 && y > 0) // Conditions hors bordures [1;3]
    {


        if (tab_mines[x - 1][y - 1] == 1)// R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y + 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y - 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x][y + 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y - 1] == 1)//R3
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R3
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y + 1] == 1)//R3
        {
            NbMines++;
        }
    }
    else if (x == 4 && y < 4 && x > 0) // condition L4
    {
        if (tab_mines[x - 1][y - 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y + 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y - 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x][y + 1] == 1)//R2
        {
            NbMines++;
        }
    }
    else if (x == 0 && y < 4 && y > 0)//condition L1
    {
        if (tab_mines[x][y - 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y + 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y - 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y + 1] == 1)//R2
        {
            NbMines++;
        }
    }
    else if (x < 4 && x > 0 && y == 4) // condition C4
    {
        if (tab_mines[x - 1][y - 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y - 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y - 1] == 1)//R3
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R3
        {
            NbMines++;
        }
    }
    else if (x < 4 && x > 0 && y == 0) // condition C0
    {
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y + 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y + 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R3
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y + 1] == 1)//R3
        {
            NbMines++;
        }
    }
    else if (x == 4 && y == 0) // [position 4;0]
    {
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y + 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x][y + 1] == 1)//R2
        {
            NbMines++;
        }
    }
    else if (x == 0 && y == 0) // [position 0;0]
    {
        if (tab_mines[x + 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y + 1] == 1)//R2
        {
            NbMines++;
        }
    }
    else if (x == 0 && y == 4) // [position 0;4] 
    {
        if (tab_mines[x][y - 1] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y - 1] == 1)//R2
        {
            NbMines++;
        }
        if (tab_mines[x + 1][y] == 1)//R
        {
            NbMines++;
        }
    }
    else if (x == 4 && y == 4) // [position 4;4]
    {
        if (tab_mines[x - 1][y] == 1)//R1
        {
            NbMines++;
        }
        if (tab_mines[x - 1][y - 1] == 1)//R1
        {
            NbMines;
        }
        if (tab_mines[x][y - 1] == 1)//R2
        {
            NbMines++;
        }
    }
    tabjeu[x][y] = NbMines + '0' ; // conversion char     // Boucle de jeu avec les cases révélées 
    score += 1; //initialisation du score
    printf("\n\n");
    printf("   | 1  2  3  4  5\n");
    printf("___|______________\n");
    for (int i = 0; i < NBR_LIGNES; i++) // ré affichage de la grille de jeu 
    {
        if (i < 5)
            printf(" %d | ", i + 1);
        else
            printf("%d | ", i + 1);
        for (int j = 0; j < NBR_COLONNES; j++)
        {
            printf("%c  ", tabjeu[i][j]);
        }
        printf("\n");
    }

    return NbMines;
}
void stepback()
{

    tabjeu[x][y] = tabjeu2[NBR_LIGNES][NBR_COLONNES];
    printf("voulez retourner en arrière ? Si oui veuillez entrer 1.");
    scanf_s("%d", &saisie);
    if (saisie == '1')
    {
            for (int i = 0; i < NBR_LIGNES; i++)
            {
                for (int j = 0; j < NBR_COLONNES; j++)
                {
                    tabjeu[i][j] = '+';// cases cachées            
                    tab_mines[i][j] = 0;
                }
            }
        printf("\n\n\t[DEMINEUR]\n\n");

        printf("\n\n");
        printf("   | 1  2  3  4  5\n");
        printf("___|______________\n");
        for (int i = 0; i < NBR_LIGNES; i++)
        {
            if (i < 9)
                printf(" %d | ", i + 1);
            else
                printf("%d | ", i + 1);
            for (int j = 0; j < NBR_COLONNES; j++)
            {
                printf("%c  ", tabjeu2[i][j]);
            }
            printf("\n");
        }
    }
     

    
}
/*void presskeys()
{
    int a = 0, compteur = 1;
    
    char c;
    c = getchar();
    while (a<compteur)
    if (c == 113)//q 
    {
        tabjeu[NBR_LIGNES][NBR_COLONNES - 1];
        a++;
    }
    if (c == 100)//d
    {
        tabjeu[NBR_LIGNES][NBR_COLONNES + 1];
        a++;
    }
    if (c == 122)//z
    {
        tabjeu[NBR_LIGNES + 1][NBR_COLONNES];
        a++;
    }
    if (c == 115)//s
    {
        tabjeu[NBR_LIGNES - 1][NBR_COLONNES];
        a++;
    }

}*/



// CHOIX DE LA CASE    (2)
void Choisir(int NbMines)
{
    int maxTour = (NBR_LIGNES * NBR_COLONNES) - NbMines;
    
    int r = 0;
    do {
        /* do {
        x = rand() % 5;
        y = rand() % 5;
    } while (tabjeu[x][y] != '+');// De façon à ce que tout le tableau soit remplit 
    printf("\ncase (%d,%d) decouverte !\n", x + 1, y + 1);
    MinesAutour();// vérification 
    */
            printf("\nchoisissez une case maintenant en indiquant les cordonnees du type : x y  ! \n");
            scanf_s("%d %d", &x, &y);
            printf("Vous avez choisi la case (%d,%d)\n", x, y);
            x -= 1;
            y -= 1;
            MinesAutour();
        r++;
    } while (r < maxTour && finPartie == 0); //condition pour que la partie ce termine 
   

    if (finPartie == 1) 
    {
        printf("case (%d,%d) est une bombe !\n", x, y);
        printf("\n GAME OVER\n");
        printf("SCORE : %d ", score - 1);
    }
    else {
        printf("\n GG!\n");
        printf("SCORE : %d ", score);
        
    }
    


}

int main()
{
    srand(time(NULL));
    readfile(); 
    int mines = 0;
    Affichejeu(); //appel de l'interface
    //presskeys();
    mines=PlacerMines();// on place les mines de façon "random"
    Choisir(mines);// l'user choisit des cases et on appelle la fonction mineautours pour déterminer les conditions de jeu par rapport aux coordonnées saisies
    
    return 0;

}
