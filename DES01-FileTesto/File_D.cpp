/** ****************************************************************************************
* \mainpage <FILE>
* @brief <si prova ad usare dei semplici comandi dei file>
* @author <Davide Hu>
* @date <27.11.2022> 
* @version 1.0 <27.11.2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDES = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
#include <stdio.h>		//per printf/scanf
#include <stdlib.h>		//per system
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
int main()
{								//nome del File
	char file[]="Es_D.txt";					//numeri.txt
	char file1[]="Es_D1.txt";				//pari.txt
	char file2[]="Es_D2.txt";				//dispari.txt
	
	int err, err1, err2;					//intero per chiudere il FILE			
	
	char c;							//carattere		
	FILE *pf;						//puntaFile		
	FILE *pf1; 								
	FILE *pf2;
	
   	pf=fopen(file,"r");					//apre il FILE: numeri;
	pf1=fopen(file1,"w+"); 					//pari;
	pf2=fopen(file2,"w+");					//dispari;
   	printf("Il programma apre il primo FILE, controlla se il numero e'pari lo mette nel secondo FILE\n");
   	printf("se dispari lo mette nel terzo FILE\n\n");
   	system("pause");
   
   	if(pf!=NULL && pf1!=NULL && pf2!=NULL)						//controlla l'apertura dei file
	{
		while(!feof(pf))							//controlla l'ultimo carattere del FILE
		{
			c=fgetc(pf);							//prende il caratere
			if(c>='0'&& c<='9')						//controlla se un numero
			{
				if(c%2==0)														 
				{
					fputc(c,pf1);					//se pari lo salva in ES_D1								
					fputc((int)'\t',pf1);				//fa la tabulazione
				}
				else
				{
					fputc(c,pf2);					//invece se è dispari mette nel terzo FILE
					fputc((int)'\t',pf2);						
				}
			}
		}
		err=fclose(pf);								//chiude i FILE
		err1=fclose(pf1);								
		err2=fclose(pf2);
		printf("\nL'esecuzione conclusa -\tcontrollare nella cartella il FILE\n");									
		system("pause");
	}
	else										//se non esiste 
	{
		printf("\nIL FILE NON PUO ESSERE APERTO!\n");
	}
}
