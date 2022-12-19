
/** ****************************************************************************************
* \mainpage <FILE BINARI>
*
* @brief <richiamare le funzioni per gestire un file di record con i campi cognome, data di nascita, e 8 voti>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <Davide Hu>
* @date <15.12.2022> 
* @version 1.0 <12.12.2022> Versione iniziale
* @version 1.1 <19/12/2022> Proseguimento programma
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDE = DEFINE = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#include <stdio.h>							//per printf/scanf
#include <stdlib.h>							//per system
#define V 8									//voti
#define L 10								//lunghezza stringa del nome
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = FUNZIONI = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void inserisciRecord(char file[], int numRecord);
void stampaFile(char fileName[]);
int ricercaRecord(char fileName[]);
int stampaRecord(char fileName[], int posizione);
int correggiRecord(char fileName[], int posizione);
int numeroRecord(char fileName[]);
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = STRUCT = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
struct data 							
{
	int gg;									//giorno
	int mm; 								//mese
	int aa;									//anno
}typedef data; 								//nome di defoult data

struct stud 								
{
	char cognome[L];
	data nascita;
	int  voti[V];
}typedef stud; 								//nome di defoult stud
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main()
{
	char file []="datifile.txt";					//nome del primo File
	int err, numRecord;							
	char c;											//carattere
	FILE *pf;										//puntaFile	

	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return 0;
	}
		printf("inserisci il numero di record che voresti creare:\t");
		scanf("%d", &numRecord);
		pf=fopen(file, "r+");						//apre il File
		inserisciRecord(file, numRecord);
		
    
		while(!feof(pf))							//controlla se finisce il FILE
		{
			c= fgetc(pf);							//prende la lettera
			printf("%c", c);						//stampa
		}	
		
		err= fclose(pf);					
		printf("\n");		
		system("pause");
	
		//if(!feof(pf))						//per togliere l'ultimo carattere in piu'
		
		err= fclose(pf);					
		printf("\n\n");
		system("pause");
		return 0;
}												

/** ****************************************************************************************
* @brief <inserire in seguito n record chiesti dall'utente dal main>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <19.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
void inserisciRecord(char file[], int numRecord)
{	
	stud recordino; 							//dichiarazione di un record
	int err, cont=1; 							//per far funzionare le funzioni di file
	FILE* pf; 								
	for(int i=0; i<numRecord; i++)
	{
		printf("\n%d^ studente:\n", cont); cont++;
		printf("\ninserisci il cognome dello studente:\t");            scanf("%s",  recordino.cognome);
		printf("\ninserisci il giorno di nascita:\t");                 scanf("%d", &recordino.nascita.gg);
		printf("\ninserisci il mese di nascita(in lettere):\t");       scanf("%s",  recordino.nascita.mm);
		printf("\ninserisci l'anno di nascita:\t");                    scanf("%d", &recordino.nascita.aa);
		printf("** *************************************************************************************");
		for(int j=0; j<V; j++)
		{
			int a=rand()%10+1;
			recordino.voti[j]=a;
		}
	}
}

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/

/** ****************************************************************************************
* @brief <inserire una breve descrizione della routine>
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/