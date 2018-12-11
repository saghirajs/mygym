#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include <string.h>
#include <stdio.h>
#include "modifier_regime.h"

int create_data_in_file(const char* chaine1, FILE* pointeurSurFichier1)

{	
	
 
    if (pointeurSurFichier1 != NULL)

    {
    // On l'écrit dans le fichier

		
        fprintf(pointeurSurFichier1, "%s\n", chaine1);

        fclose(pointeurSurFichier1);
       return 1;

    }
 

    return -1;

}


