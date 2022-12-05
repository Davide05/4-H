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
	char file []="FILE/Es_A.txt";					//nome del primo File
	char file1[]="FILE/Es_A1.txt";					//nome del secondo File
	int err, err1;								
	char c;											//carattere
	FILE *pf;										//puntaFile		
	FILE *pf1;

	if(pf!=NULL)
	{
		printf("Il contenuto del primo FILE:\n\n");
		pFile=fopen(file, "r");						//apre il File
    
		while(!feof(pf))							//controlla se finisce il FILE
		{
			c= fgetc(pf);							//prende la lettera
			printf("%c", c);						//stampa
		}	
		err= fclose(pf);					
		printf("\n");		
		printf("Adesso il programma riapre in un nuovo FILE lo stesso contenuto tutto in maiscolo\n");
		system("pause");
	
		pf=fopen(file, "r");			 		//apre il File
		pf1=fopen(file1, "w");
		printf("\n");
		while(!feof(pf))						//controlla se finisce il FILE
		{
			c= fgetc(pf);						//prende la lettera
			if(c>='a' && c<='z')				//converte tutto in maiscolo
				c-=32;				
			printf("%c", c);					//stampa
			if(!feof(pf))						//per togliere l'ultimo carattere in piu'
				fputc(c,pf1);
		}
		err= fclose(pf);		
		err1= fclose(pf1);				
		printf("\n\n");
		system("pause");
	}
	else											
	printf("\nIL FILE NON PUO'ESSERE APERTO!\n");	
}