#include <gtk/gtk.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include <string.h>
#include <stdio.h>
#include "list_des_adherants.h"

int check_user_regime(char name_entry[], char first_name_entry[],int n)
{	
	
 	
	int r = -1;
    FILE* f;
    char test_nom[150]; char test_prenom[150];
    f=fopen("/home/saghirr/Desktop/users.txt","r");
    if (f!=NULL) {
      /* code */
      while(fscanf(f,"%s %s",test_nom,test_prenom)!=EOF){
          if ((strcmp(test_nom,name_entry)==0) && (strcmp(test_prenom,first_name_entry)==0))
              r = 0;
      }
      
    fclose(f);
    }
    else{
    	
      printf("Error: missing file users.txt");
    }

    return r;
}


