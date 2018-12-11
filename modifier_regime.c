#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include <string.h>
#include <stdio.h>
#include "modifier_regime.h"

int write_data_in_file(const char* chaine, FILE* pointeurSurFichier)

{	
	
 
    if (pointeurSurFichier != NULL)

    {
    // On l'écrit dans le fichier

		
        fprintf(pointeurSurFichier, "%s\n", chaine);

        fclose(pointeurSurFichier);
       return 1;

    }
 

    return -1;

}


