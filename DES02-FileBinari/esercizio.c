/******************************************************************************************
* \mainpage <FILE BINARI>
* @brief <richiamare le funzioni per gestire un file di record con i campi cognome, data di nascita, e 8 voti>
* <specifiche del progetto>
* <specifiche del collaudo>
* 
* @author <Davide Hu>
* @date <15.12.2022> 
* @version 1.0 <12.12.2022> Versione iniziale
* @version 1.1 <19/12/2022> Proseguimento programma
* @version 1.2 <21/12/2022> Proseguimento programma
* @version 1.3 <22/12/2022> Commenti delle funzioni
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDE = DEFINE = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#include <stdio.h>			//per printf/scanf
#include <stdlib.h>			//per system
#include <string.h>			//per stcmp							
#define V 2					//voti
#define L 10				//lunghezza stringa del nome e del mese
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
	int r;       //richiama le funzioni							
	int posizione; //dare la posizione del record che si vuole trovare
	
	
	printf("inserisci il numero di record che voresti creare:\t");
	scanf("%d", &numRecord);
	inserisciRecord(fileName, numRecord);

 
	printf("la funzione esegue la stampa del file di record\n\n");
	stampaFile(fileName);


	printf("la funzione fa la ricerca della stringa(cognome)\ninserisci:   ");
	r=ricercaRecord(fileName);            
	system("pause");
				
	printf("la funzione controlla la posizione e stampa il record\n");
	printf("inserisci una posizione(numero):   ");
	scanf("%d", &posizione);
	printf("\n");		
	r=stampaRecord(fileName, posizione);

	return 0;
}												

/** ****************************************************************************************
* @brief Inserire in seguito n record chiesti
* @param fileName: nome del file da aprire; numRecord: numero di record da inserire
* @retval nessuno
* @see stampaRecord
*
* @author Davide Hu
* @version 1.0  19.12.2022 Versione iniziale
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
		printf("inserisci il cognome:  ");          		scanf("%s",  recordino.cognome);
		printf("inserisci il giorno di nascita(numeri):   ");   scanf("%d", &recordino.nascita.gg);
		printf("inserisci il mese di nascita(in lettere):   "); scanf("%s",  recordino.nascita.mm);
		printf("inserisci l'anno di nascita(numeri):    ");     scanf("%d", &recordino.nascita.aa);
		printf("inserisci %d voti:\n", V);
		for(int j=0; j<V; j++) 
		{ 
			scanf("%d", &a);
			recordino.voti[j]=a;
		}
		printf("***************************************************************************************\n");
		err=fwrite(&recordino,sizeof(recordino),1,pf);	//il record vine memorizzato nel file 
	}
	system("pause");
	system("cls");
	err=fclose(pf);
}

/** ****************************************************************************************
* @brief  Stampa su monitor (una riga per record) tutte le informazioni contenute nel file; 
* @param  fileName: nome del file da aprire
* @retval nessuno
* @see    inserisciRecord
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
*/
void stampaFile(char fileName[]) 
{
	stud recordino;
	int err;
	FILE* pf=fopen(fileName,"rb");

	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return;
	}
	
	while(!feof(pf))								
		{						    					 //1°parametro= record, 2°/3°posizione del record, 4°puntafile
			err=fread(&recordino,sizeof(recordino),1,pf);//estrapola un record dal file, e lo mette nel record(programma)
			if(err!=0)
			{
				printf("cognome:  %s\n",recordino.cognome);
				printf("data di nascita:   ");
				printf("%d/",recordino.nascita.gg);
				printf("%s/",recordino.nascita.mm);
				printf("%d\n",recordino.nascita.aa);
				printf("voti:\n");
				for(int i=0;i<V;i++)
				{
					printf("%d   ", recordino.voti[i]);
				}
				printf("\n");
			}
		}	
	printf("****************************************************************************\n");
	err= fclose(pf);					
	system("pause");
}

/** ****************************************************************************************
* @brief controlla la posizione inserito nel parametro e visualizza il record
* @param  fileName: nome del file da aprire;
* @retval restituisce due interi, 0 se esiste, -1 se non esiste
* @see stampaRecord
*
* @author Davide Hu
* @version 1.0 <15.12.2022> <Versione iniziale>
*/
int ricercaRecord(char fileName[])
{
	stud recordino;
	int err; 
	int media, eta, anno=2022;
	int finalvote=0; 	//voto finale
	int flag=0;		//variabile di controllo
	int cont=0;
	char stringa[L];
	FILE* pf;										
	pf=fopen(fileName,"rb");
	
	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return -1;
	}
	
	scanf("%s",stringa);  //stringa chiesta nel main
	printf("\n");											
	while(!feof(pf))								
	{
		err=fread(&recordino,sizeof(recordino),1,pf);	
		if(err!=0)
		{
			if(strcmp(recordino.cognome,stringa)==0)			//controlla se è lo stesso cognome
			{
				printf("cognome:   %s\n",recordino.cognome);
				eta=anno-recordino.nascita.aa;
				printf("eta':   %d\n",eta);
				finalvote=0;		//per azzerarlo dopo usato
													
				for(int i=0;i<V;i++)
				{
					finalvote+=recordino.voti[i];		
				}
				media=finalvote/V;					
				printf("la media dei voti:   %d\n\n",media);
				flag=1;		//controlla se vieni seguito il ccontrollo
			}
				
			if(flag==1)
			{
				cont++;			
			}
		}
	}
	if(flag==0)			//se non vine trovato la stringa nel record
		cont=-1;		//restituisce -1
	err=fclose(pf);								
	return cont;
}

/*******************************************************************************************
* @brief controlla la posizione inserito nel parametro e modifica il record
* @param  char fileName[]: nome del file da aprire; int posizione: indica la posizione di un record
* @retval restituisce due interi, 0 se esiste, -1 se non esiste
* @see stampaFile
*
* @author Davide Hu
* @version 1.0 <21.12.2022> <Versione iniziale>
*/
int stampaRecord(char fileName[], int posizione)
{
	stud recordino;
	int err;
	int cont;   //variabile di controllo
	FILE* pf=fopen(fileName,"rb"); //lettura in binario

	if(pf==NULL)
	{
		printf("\nIL FILE NON PUO'ESSERE APERTO!\n");
		return -1;
	}
	
	fseek(pf,posizione*sizeof(recordino),SEEK_SET);	//posiziona il puntatore sulla posizione desiderata	
	
	cont=fread(&recordino, sizeof(recordino),1,pf);	//funzione di lettura per leggere i dati nel file
		
		if(cont>0)   //controlla che il record viene letto 
		{
			printf("cognome:   %s\n",recordino.cognome); 
			printf("data di nascita:   ");
			printf("%d/",recordino.nascita.gg);
			printf("%s/",recordino.nascita.mm);
			printf("%d\n",recordino.nascita.aa);
			printf("voti:\n");
			for(int i=0;i<V;i++)
			{
				printf("%d   ", recordino.voti[i]);
			}
			printf("\n");
			fclose(pf);
			return 0;
		}
		else
			fclose(pf);
		return -1;		
}
