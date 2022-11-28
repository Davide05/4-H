/** ****************************************************************************************
* \mainpage <FILE>
* @brief <si prova ad usare dei semplici comandi dei file>
* @author <Davide Hu>
* @date <26.11.2022> 
* @version 1.0 <26.11.2022> Versione iniziale
* @version 1.1 <data> <Descrivere le modifiche apportate>
*/
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = INCLUDES = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
#include <stdio.h>		//per printf/scanf
#include <stdlib.h>		//per system
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//= = = MAIN = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
int main()
{
	char file[]="Es_C.txt";						//nome delFile
	int carattere=0,righe=0;		
	int err;									//intero per chiudere il FILE
	char c,cp, parole=0;						//c=carattere preso dal FILE cp=carattere prima della c	
	FILE *pf;									//puntaFile										
	printf("Il contenuto del FILE:\n");		
											
    pf=fopen(file, "r");						//apre il File
	while(!feof(pf))							//ciclo per
	{										
		c= fgetc(pf);							//prende la lettera										
		printf("%c", c);
		
		if(c!=EOF && c!='\n')				
		carattere++;							
			
		if(cp>='A' && cp<='Z'|| cp>='a' && cp<='z')
		{
			if(c<'A' || c>'Z' && c<'a' || c>'z')
			parole++;
		}	
		
		if(c==EOF || c=='\n')					//controlla fine carattere
			righe++;
		cp=c;							
	}										
	err= fclose(pf);							
											
	printf("\nIl programma conta i caratteri, le parole e le righe presenti in un file di testo");						
	printf("\n\nIl FILE ha %d caratteri\n\n", carattere);	
	printf(". . . . . . %d righe\n\n", righe);
	printf(". . . . . . %d parole\n", parole);
	printf("\n");
	system("pause");	
}
