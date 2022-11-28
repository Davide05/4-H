/** ****************************************************************************************
* \mainpage <FILE>
* @brief <si prova ad usare dei semplici comandi dei file>
* @author <Davide Hu>
* @date <27.11.2022> 
* @version 1.0 <27.11.2022> Versione iniziale
* @version 1.1 <data> <>
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDES = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include <stdio.h>		//per printf/scanf
#include <stdlib.h>		//per system
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = FUNZIONI = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void crypt(char[],char[]);
void decrypt(char[],char[]);
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main()
{
	char file[]= "Es_E.txt";
	char file1[]="Es_E1.txt"; 								//nomi dei file
	int err,err1;										//usati per far funzionare fclose
	
	FILE* pf;										//puntaFILE
	FILE* pf1;									
	
	char c;											//usato per prendere le lettera e modificarli
	
	pf= fopen(file,"r");									//apertura dei FILE
	pf1=fopen(file1,"w+");	
							
	if(pf!=NULL && pf1!=NULL)								//controlla se ce ancora il testo
	{
		printf("Il programma decrypta il carattere di tre posti nel codice ascii\n");
		printf("Se il conto alla rovrscia supera A/a riprende la Z/z\n");
		system("pause");
		
		crypt(file,file1);								//cripta il messagio
		decrypt(file1,file);								//decripta il messagio
		printf("\n\nL'esecuzione conclusa -\tcontrollare nella cartella il FILE\n");									
	}
	else											//se non esiste 
	{
		printf("\nIL FILE NON PUO ESSERE APERTO!\n");
	}
}
/** ****************************************************************************************
* @brief crypta il carattere del FILE di testo
* @param  FILE,stringa
* @retval 
* @see 
*
* @author Davide Hu
* @version 1.0 27/11/2022 
* @version 1.1  
*/
void crypt(char f[],char f1[])
{
	int err,err1;						
	FILE* pf;								
	FILE* pf1;								
	char c;									
	pf=fopen(f,"r");						//apre i file
	pf1=fopen(f1,"w");					
	while(!feof(pf))						//controlla se ce ancora il testo
	{
		c=fgetc(pf);						//prende un caratere
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')			//controlla se è una letera
		{
			c-=3;						//sposta la posizione della lettera a 3 letere prima
			if(c<'A' || c<'a' &&  c>'Z')			//se è più picolo di A ed compreso tra Z e ai
			{
				c+=26;					//aggiunge e prende la letera 
			}
		}
		if(!feof(pf))						//se è diverso da \0
		fputc(c,pf1);						//se è vero lo mette nel secondo FILE
	}
	err= fclose(pf);						//chiude i FILE
	err1=fclose(pf1);						
}
/** ****************************************************************************************
* @brief decrypta il carattere del FILE di testo
* @param FILE,stringa
* @retval 
* @see 
*
* @author Davide Hu
* @version 1.0 27/11/2022 
* @version 1.1  
*/
void decrypt(char f[],char f1[])
{
	int err,err1;								
	FILE* pf;							
	FILE* pf1;								
	char c;										
	pf= fopen(f,"r");						//apre i file
	pf1=fopen(f1,"w");						
	while(!feof(pf))						//controlla se ce ancora il testo
	{
		c=fgetc(pf);						//prende un caratere
		if(c>='a'&&c<='z'||c>='A'&&c<='Z')			//controlla se è una letera
		{
			c+=3;						//sposta la posizione della lettera a 3 letere dopo
			if(c>'Z' && c<'a'||c>'z')			//se compreso tra Z e a oppure piu grade di z
			{
				c-=26;					//dopo sottrato lo prende							
			}
		}
		if(!feof(pf))						//se è diverso da \0
		fputc(c,pf1);						//se è vero lo mette nel secondo FILE
	}
	err=fclose(pf);							//chiude i FILE
	err1=fclose(pf1);						
}
