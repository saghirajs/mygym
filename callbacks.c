#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "modifier_regime.h"
#include <gtk/gtk.h>
#include "list_des_adherants.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include "fiche_regime.h"
#include "ajout_regime.h"
#include "treeview.h"
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>




void on_modifier_regime_clicked (GtkButton *objet_graphique, gpointer user_data)
{	GtkWidget *in3;
  	in3=lookup_widget(objet_graphique, "fiche_regime");
  	gtk_widget_hide (in3);
  	
  	/* (in3);
  	

   	GtkWidget *label16;
   	char label_16[50];
  	label_16[50]=gtk_label_get_label (label16);*/


  	GtkWidget *window4;
	window4 = create_modifier_regime ();
	gtk_widget_show(window4);

   
    

    GtkWidget *labell;
  	labell=lookup_widget(window4,"label18");
  	gtk_label_set_text(GTK_LABEL(labell),labell);

	
}




void on_quitter_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void on_liste_adherants_clicked (GtkButton *objet_graphique, gpointer user_data)
{	GtkWidget *in;
  	in=lookup_widget(objet_graphique, "Menu");
  	gtk_widget_hide (in);

  	GtkWidget *window2;
	window2 = create_list_des_adherants ();
  	gtk_widget_show (window2);



}


void on_agenda_clicked (GtkButton *objet_graphique, gpointer user_data)
{	GtkWidget *in5;
  	in5=lookup_widget(objet_graphique, "Menu");
  	gtk_widget_hide (in5);

	GtkWidget *window5;
	window5 = create_Agenda ();
  	gtk_widget_show (window5);
  	
  	
  	/*liste=lookup_widget(objet_graphique,"treeview6");*/
  	//liste=lookup_widget(window5,"treeview6");
  	//afficher_message(liste);
  
  GtkWidget *treeview6;
  GtkWidget *liste;
  
  liste=lookup_widget(objet_graphique,"treeview6");
  liste=lookup_widget(window5,"treeview6");
  afficher(liste);


}


void on_quitter1_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void on_quitter2_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void on_modifier_agenda_clicked (GtkButton *objet_graphique, gpointer user_data)
{

}


void on_supprimer_clicked (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *in6;
	GtkWidget *supp;
	supp=lookup_widget(objet_graphique,"label25");
	

	/*GtkWidget *input ;
	
	input=lookup_widget(objet_graphique,"nadimentry2");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	supprimer(id,n);*/
	


	GtkWidget *input ;
		
	
	int n=5;
	char id[5];
	input=lookup_widget(objet_graphique,"nadimentry2");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
	//supprimer(id,n);

	
	

  	gtk_label_set_text(GTK_LABEL(supp),"le fichier a été supprimer");



}


void on_quitter3_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void on_valider_modi_clicked (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *input1;
    FILE* fichier = NULL;
    
 	
 	fichier = fopen("user1_diet.txt", "r+");

 	input1=lookup_widget(objet_graphique, "textview2");
 	GtkTextIter start, end;
	GtkTextBuffer *buffer = gtk_text_view_get_buffer (input1);
	gchar *text;

	gtk_text_buffer_get_bounds (buffer, &start, &end);
	text = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);
	 	
 	
 	if(write_data_in_file(text, fichier) > 0) {
 		printf("done\n");
 	}else 
 	{
 		printf("Error\n");
 	}

 	GtkWidget *in7;
	
  	in7=lookup_widget(objet_graphique, "modifier_regime");
  	gtk_widget_hide (in7);


  	GtkWidget *window2;
	window2 = create_fiche_regime ();
  	gtk_widget_show (window2);

}

void on_fich_regime_clicked (GtkButton *objet_graphique, gpointer user_data)
{	GtkWidget *label26;
	
	char *name_entry;
	char *first_name_entry;
	GtkWidget *a;
	GtkWidget *b;
	label26=lookup_widget(objet_graphique,"label26");
	a=lookup_widget(objet_graphique,"entry_nom");
	b=lookup_widget(objet_graphique,"entry_prenom");
	first_name_entry=gtk_entry_get_text(GTK_ENTRY(b));
	name_entry=gtk_entry_get_text(GTK_ENTRY(a));
	






	int n=150;
	int check = -1;
    check = check_user_regime(name_entry,first_name_entry,n);
    if (check==0){
    strcat(name_entry," ");
    strcat(name_entry,first_name_entry);
    GtkWidget *label16;
  	
    GtkWidget *in1;
  	in1=lookup_widget(objet_graphique, "list_des_adherants");
  	gtk_widget_hide (in1);

	GtkWidget *window3;
    
  	window3 = create_fiche_regime ();
  	gtk_widget_show (window3);

    GtkWidget *labell;
  	labell=lookup_widget(window3,"label16");
  	gtk_label_set_text(GTK_LABEL(labell),name_entry);
  	
  	//int r=-1;
    /*FILE* file;
    char dejeuner[150];
    GtkWidget *output1;
    
    output1=lookup_widget(objet_graphique, "textview1");
	file=fopen("/Home/saghirr/Desktop/users_diets_dejeuner.txt","r");
	if(file!=NULL)
	{
		 while(fscanf(file,"%s %s",test_nom,dejeuner)!=EOF){
          if (strcmp(test_nom,name_entry)==0)*/
         	


    FILE *fichierliste;
    char dejeuner[150]; //texte_entry[30];
    GtkTextBuffer *pBuffer=NULL;
    GtkTextIter fin;
    char test_nom[150],texte_entry[30]; 
    
 	GtkWidget *tviewliste;
 	tviewliste = lookup_widget(objet_graphique,"textview7");
 	tviewliste=lookup_widget(window3,"textview7");
    
    
    //GtkWidget *entry = lookup_widget(objet_graphique,"entry1");
 
  
     pBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tviewliste));
     fichierliste=fopen("/Home/saghirr/Desktop/users_diets_dejeuner.txt","r");

     if(fichierliste!=NULL) {
              while(fscanf(fichierliste,"%s%s",test_nom,dejeuner)!=EOF){
          	  if (strcmp(test_nom,name_entry)==0){
           
				gtk_text_buffer_get_end_iter(pBuffer, &fin);
                  
                  gtk_text_buffer_insert(pBuffer,&fin,dejeuner,strlen(dejeuner));
              }
              }
     }     
    
    fclose(fichierliste);


          	
              //r = 0;
	}


	else{
    gtk_label_set_text(GTK_LABEL(label26),"Wrong user id");
    }
    
   



}


void on_quitter12_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}

void on_quitter17_clicked (GtkButton *objet_graphique, gpointer user_data)
{
gtk_main_quit();
}


void on_valider_ajout_clicked (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *input3;
    FILE* fichier1 = NULL;
    
 	
 	fichier1 = fopen("saghir.txt", "w");

 	input3=lookup_widget(objet_graphique, "textview3");
 	GtkTextIter start, end;
	GtkTextBuffer *buffer1 = gtk_text_view_get_buffer (input3);
	gchar *text1;

	gtk_text_buffer_get_bounds (buffer1, &start, &end);
	text1 = gtk_text_buffer_get_text (buffer1, &start, &end, FALSE);
	 	
 	
 	if(write_data_in_file(text1, fichier1) > 0) {
 		printf("done\n");
 	}else {
 		printf("Error\n");
 	}

 	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "ajouter_regime");
  	gtk_widget_hide (ine);

  	GtkWidget *window28;
	window28 = create_fiche_regime ();
  	gtk_widget_show (window28);
}


void
on_ajouter1_clicked (GtkButton *objet_graphique, gpointer user_data)
{	
	GtkWidget *label23;
	char *name_entry;
	char *first_name_entry;
	GtkWidget *a;
	GtkWidget *b;
	label23=lookup_widget(objet_graphique,"label23");
	a=lookup_widget(objet_graphique,"entry_nom");
	b=lookup_widget(objet_graphique,"entry_prenom");
	first_name_entry=gtk_entry_get_text(GTK_ENTRY(b));
	name_entry=gtk_entry_get_text(GTK_ENTRY(a));

	GtkWidget *in3;
  	in3=lookup_widget(objet_graphique, "list_des_adherants");
  	gtk_widget_hide (in3);

	GtkWidget *window3;
	window3 = create_ajouter_regime ();
  	gtk_widget_show (window3);
  	strcat(name_entry," ");
    strcat(name_entry,first_name_entry);
  	GtkWidget *labell;
  	labell=lookup_widget(window3,"label23");
  	gtk_label_set_text(GTK_LABEL(labell),name_entry);
  	FILE* f;
  	f=fopen("/home/saghirr/Desktop/users.txt","a");
  	if (f!=NULL)
  	{
  		fprintf(f, "%s\n",name_entry );
  		fclose(f);
  	}
}



void
on_retour_clicked (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "ajouter_regime");
  	gtk_widget_hide (ine);

  	GtkWidget *window28;
	window28 = create_fiche_regime ();
  	gtk_widget_show (window28);
}



void
on_button19_clicked  (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "Agenda");
  	gtk_widget_hide(ine);

  	GtkWidget *window28;
	window28 = create_Menu ();
  	gtk_widget_show (window28);
}


void
on_button20_clicked  (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "fiche_regime");
  	gtk_widget_hide(ine);

  	GtkWidget *window28;
	window28 = create_list_des_adherants ();
  	gtk_widget_show (window28);
}


void
on_button21_clicked  (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "modifier_regime");
  	gtk_widget_hide(ine);

  	GtkWidget *window28;
	window28 = create_fiche_regime ();
  	gtk_widget_show (window28);
}


void
on_button23_clicked  (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "list_des_adherants");
  	gtk_widget_hide(ine);

  	GtkWidget *window28;
	window28 = create_Menu ();
  	gtk_widget_show (window28);	
}


void
on_button22_clicked (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "ajout_regime");
  	gtk_widget_hide(ine);

  	GtkWidget *window28;
	window28 = create_list_des_adherants();
  	gtk_widget_show (window28);

}


/*void supprimer(char id[],int n){
  char dejeuner[200];
  char test_nom;
  FILE*f;
  FILE*f1;
  f=fopen("user_dejeuner.txt","a+");
  f1=fopen("users_dejeuner","a+");
  if(f!=NULL) {
    while(fscanf(f,"%s %s\n",nom,dejeuner)!=EOF){
      if (strcmp(test_nom,id)!=0){
          fprintf(f1,"%s %s\n",);
        }
  }
}
fclose(f);
fclose(f1);
remove("cure.txt");
rename("cures.txt","cure.txt");
}*/
void
on_button24_clicked  (GtkButton *objet_graphique, gpointer user_data)
{
	GtkWidget *ine;
  	ine=lookup_widget(objet_graphique, "fiche_regime");
  	gtk_widget_destroy(ine);

  	GtkWidget *window28;
	window28 = create_list_des_adherants ();
  	gtk_widget_show (window28);
}

const gchar* gtk_label_get_label (GtkLabel *label16);