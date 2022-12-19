
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
#define V 2									//voti
#define L 10								//lunghezza stringa del nome e del mese
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = FUNZIONI = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void inserisciRecord(char fileName[], int numRecord);
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
void inserisciRecord(char fileName[], int numRecord)
{	
	stud recordino;
	int err, cont=1, a=0;
	FILE* pf; 								

	pf=fopen(fileName, "ab");			//apre il File
	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return;
	}

	for(int i=0; i<numRecord; i++)
	{
		printf("\n%d^ studente:\n", cont); cont++;
		printf("inserisci il cognome:  ");          			 scanf("%s",  recordino.cognome);
		printf("inserisci il giorno di nascita:   ");           scanf("%d", &recordino.nascita.gg);
		printf("inserisci il mese di nascita(in lettere):   "); scanf("%s",  recordino.nascita.mm);
		printf("inserisci l'anno di nascita:    ");             scanf("%d", &recordino.nascita.aa);
		for(int j=0; j<V; j++) 
		{
			printf("inserisci il voto:\t"); scanf("%d", a);
			recordino.voti[j]=a;
		}
		printf("** *************************************************************************************\n");
	}
}

/** ****************************************************************************************
* @brief  Stampa su monitor (una riga per record) tutte le informazioni contenute nel file; 
* @param  file: nome del file da aprire
* @retval nessuno
* @see    inserisciRecord
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
*/
void stampaFile(char fileName[]) 
{
	stud recordino;
	int err, cont=1, a=0;
	char c;
	FILE* pf;
	while(!feof(pf))		//controlla se finisce il FILE
	{
		c= fgetc(pf);		//prende la lettera
		printf("%c", c);	//stampa
	}	

	err= fclose(pf);					
	printf("\n");		
	system("pause");

	//if(!feof(pf))			//per togliere l'ultimo carattere in piu'

	err= fclose(pf);					
	printf("\n");
	system("pause");
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