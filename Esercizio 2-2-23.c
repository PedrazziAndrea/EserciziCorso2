/******************************************************************************
                     ESERCIZIO QUIZ SCELTA MULTIPLA V. 2  
                                  2/2/2023
*******************************************************************************/

#include <stdio.h>
#include <ctype.h>

/*
*   Definisco delle variabili globali readonly
*   così rendo facile l'aggiunta/modifica 
*   di contenuto in seguito
*/

#define Domanda1 "[1]-Quali tra queste sequenze è composta solo da numeri primi? :\n(A)8 ,9, 6, 2\n(B)22, 12, 2, 4\n(C)2, 3, 11, 13\n"
#define Domanda2 "[2]-Quante sono le lune di Giove? :\n(A)79\n(B)54\n(C)15\n"
#define Domanda3 "[3]-Quali tra questi è una lega? :\n(A)Rame\n(B)Ferro\n(C)Bronzo\n"

#define ErroreChar "Inserisci un carattere valido.\n"

#define NumeroDomande 3

/*
*   Funzione per il controllo del
*   corretto input da parte dell' utente
*/

int Controllo (char control)
{
    char input;
    
    for (; ;)   // ciclo infinito (fin che non viene triggerato un return viene iterato)
    {
        scanf(" %c", &input);
        
        if (input == 'A'|| input == 'B'|| input == 'C')
        {
          if (input == control) return 1; 
            else return 0;
        }else printf(ErroreChar);  
    }        
} 

/*
*   Funzione che determina il gameloop
*   principale e crea modularmete 
*   l'esperienza di gioco all utente,
*   permette l'inserzione di nuove domande 
*   senza toccare il main dato che vengono chiamate
*   in modo dinamico.
*/

int Domanda (int input)
{
   switch (input) 
   {
       case 1: printf(Domanda1);   // riferimento alla variabile globale
            return Controllo('C');  // impostazione risposta corretta
            break; 
            
        case 2: printf(Domanda2);
            return Controllo('A');
            break;
            
        case 3: printf(Domanda3);
            return Controllo('C');
            break;
        
        default :printf("(DEBUG)Inserisci un codice domanda corretto.\n"); // protezione in caso di errori di battitura
            break;
               
   }
}

/*
*   Funzione che permette la chiusura
*   o la creazione di una nuova Partita
*/

int NuovaPartita ()
{
    char input;

    printf("Scegli come vuoi continuare:\n(A)Nuova Partita\n(B)Chiudi\n");
    
    for (; ;)
    {
        scanf (" %c", &input);
    
        if(input == 'A')return 1;
          else if(input == 'B')return 0;
            else printf(ErroreChar);  
    }        
}


int main()                                         
{
    int i = 0;       //  
    int j = 0;      // variabili di iterazione
    
    int c = 0;     // variabile di supporto        
    
    int score = 0;
    char auxNome[30];
    
    
    printf("Ciao utente, questo è un qiz, il tuo scopo è indovinare quante più risposte possibile.\n");
    
    if(NuovaPartita() == 0)return 0;
    
    there:   // sfocio del goto per un nuovo gameloop
    
    printf("Inserisci il tuo nome: \n");
   
    while (c == 0)
    {
        scanf("%s", auxNome);
        
        for(j = 0; j < 30; j++)
        {
           if (isdigit(auxNome[j]) != 0)break;              //
             if(j >= 15)break;                             // Controllo sul nome
               if(auxNome[j] == '\0'){c+=1;break;};       //
        }           
        if(c == 0)
        {
          printf("Lunghezza o caratteri non validi, riprova.\n");
          j = 0;
        }
    }    
   
    for(i = 1; i<NumeroDomande + 1; i++)score += Domanda(i);   // Ogni domanda vine triggerata in modo progressivo e automatico 
    
    if(score == 0)printf("Peccato %s,non ne hai azzeccata neanche una.", auxNome);
     else if (score == 1)printf("Bravo %s, hai fatto un punto!");                   
       else printf("Bravissimo %s, hai fatto %d punti!", auxNome, score);
       
    if(NuovaPartita() == 0)return 0;
    goto there;  
    
    i = 0;                  //
    j = 0;                 //  Reimpostazione valori di default se riavvia  
    c = 0;                // 
    score = 0;           //
}
