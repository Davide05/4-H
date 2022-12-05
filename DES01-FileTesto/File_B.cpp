/** ****************************************************************************************
* \mainpage <FILE>
* @brief <si prova ad usare dei semplici comandi dei file>
* @author <Davide Hu>
* @date <27.11.2022> 
* @version 1.0 <27.11.2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = INCLUDES = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include <stdio.h>							//per printf/scanf
#include <stdlib.h>							//per system
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
int main()
{
	char file[]="Es_B.txt";						//nome del  File
	char file1[]="Es_B1.txt";					
	int err, err1;							//intero per chiudere il FILE		
	char c;								//carattere		
	FILE *pf;							//puntaFile		
	FILE *pf1;
	
	printf("Il contenuto del primo FILE:\n\n");
 	pf=fopen(file, "r");						//apre il File
    
    	if(pf!=NULL)
   	{
		while(!feof(pf))					//controlla se finisce il FILE
		{
			c= fgetc(pf);					//prende la lettera
			printf("%c", c);				//stampa
		}
	err= fclose(pf);					
		
	printf("\n\nIl programma riapre in un nuovo FILE lo stesso contenuto\n");
	system("pause");

	pf=fopen(file, "r");				    		//apre il File
	pf1=fopen(file1, "w+");
	printf("\n");
		while(!feof(pf))					//controlla se finisce il FILE
		{
			c= fgetc(pf);					//prende la lettera				
			printf("%c", c);				//stampa
			if(!feof(pf))					//per togliere l'ultimo carattere(\0) in piu'
				fputc(c,pf1);
		}
	err= fclose(pf);		
	err1= fclose(pf1);				
	printf("\n");
	}
	else											
	printf("\nIL FILE NON PUO'ESSERE APERTO!\n");	
}
