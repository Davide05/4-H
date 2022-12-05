/** ****************************************************************************************
* \mainpage <FILE>
* @brief <si prova ad usare dei semplici comandi dei file>
* @author <Davide Hu>
* @date <10.11.2022> 
* @version 1.0 <10.11.2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDES = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include <stdio.h>						//per printf/scanf
#include <stdlib.h>						//per system
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
int main()
{
	char Es_A[]="FILE/Es_A.txt";					//nome del primo File
	char Es_A1[]="FILE/Es_A1.txt";				//nome del secondo File
	int err, err1;								
	char c;									//carattere
	FILE *pFile;							//puntaFile		
	FILE *pFile1;

	if(pf!=NULL)
	{
		printf("Il contenuto del primo FILE:\n\n");
		pFile=fopen(Es_A, "r");						//apre il File
    
		while(!feof(pFile))							//controlla se finisce il FILE
		{
			c= fgetc(pFile);						//prende la lettera
			printf("%c", c);						//stampa
		}	
		err= fclose(pFile);					
		printf("\n");		
		printf("Adesso il programma riapre in un nuovo FILE lo stesso contenuto tutto in maiscolo\n");
		system("pause");
	
		pFile=fopen(Es_A, "r");			 		//apre il File
		pFile1=fopen(Es_A1, "w");
		printf("\n");
		while(!feof(pFile))						//controlla se finisce il FILE
		{
			c= fgetc(pFile);					//prende la lettera
			if(c>='a' && c<='z')				//converte tutto in maiscolo
				c-=32;				
			printf("%c", c);					//stampa
			if(!feof(pFile))					//per togliere l'ultimo carattere in piu'
				fputc(c,pFile1);
		}
		err= fclose(pFile);		
		err1= fclose(pFile1);				
		printf("\n\n");
		system("pause");
	}
	else											
	printf("\nIL FILE NON PUO'ESSERE APERTO!\n");	
}