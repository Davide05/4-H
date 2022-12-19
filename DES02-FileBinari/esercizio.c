
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
#define L 10								//lunghezza stringa del nome e del mese
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
	int gg;			//giorno
	char mm[L]; 	//mese
	int aa;			//anno
}typedef data; 		//nome di defoult data

struct stud 								
{
	char cognome[L];
	data nascita;
	int  voti[V];
}typedef stud; 		//nome di defoult stud
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main()
{
	char fileName[]="datifile.txt";	//nome del File da aprire
	int err, numRecord;							
	char c;
	
	printf("inserisci il numero di record che voresti creare:\t");
	scanf("%d", &numRecord);
	inserisciRecord(fileName, numRecord);

	stampaFile(fileName);
/*
	while(!feof(pf))				//controlla se finisce il FILE
	{
	c= fgetc(pf);					//prende la lettera
	printf("%c", c);				//stampa
	}	

	err= fclose(pf);					
	printf("\n");		
	system("pause");

	//if(!feof(pf))						//per togliere l'ultimo carattere in piu'

	err= fclose(pf);					
	printf("\n\n");
	system("pause");
*/
	return 0;
}												

/** ****************************************************************************************
* @brief Inserire in seguito n record chiesti
* @param file: nome del file da aprire; numRecord: numero di record da inserire
* @retval nessuno
* @see stampaRecord
*
* @author Davide Hu
* @version 1.0 19.12.2022 Versione iniziale
*/
void inserisciRecord(char file[], int numRecord)
{	
	stud recordino;
	int err, cont=1;
	FILE* pf; 								

	pf=fopen(file, "ab");			//apre il File
	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return;
	}

	for(int i=0; i<numRecord; i++)
	{
		printf("\n%d^ studente:\n", cont); cont++;
		printf("inserisci il cognome:\t");            			scanf("%s",  recordino.cognome);
		printf("inserisci il giorno di nascita:\t");            scanf("%d", &recordino.nascita.gg);
		printf("inserisci il mese di nascita(in lettere):\t");  scanf("%s",  recordino.nascita.mm);
		printf("inserisci l'anno di nascita:\t");               scanf("%d", &recordino.nascita.aa);
		printf("** *************************************************************************************");
		for(int j=0; j<V; j++) //TODO: inseriti dall'utente
		{
			int a=rand()%10+1;
			recordino.voti[j]=a;
		}
	}
}

/** ****************************************************************************************
* @brief  Stampa su monitor (una riga per record) tutte le informazioni contenute nel file; 
* @param  <elenco dei parametri in ingresso alla funzione>
* @retval <valori restituiti>
* @see <See Also: Describes a cross-reference to classes, functions, methods, variables, ...>
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
void stampaFile(char fileName[]) 
{
	;
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