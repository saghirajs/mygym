#include <gtk/gtk.h>
#include <string.h>
#include "treeview.h"
#include <stdio.h>
#include <stdlib.h>


enum 
  {
    Jour,
    Matin,
    Soir,
    COLUMNS
  };


void afficher(GtkWidget*liste)
{
GtkCellRenderer*renderer;
GtkTreeViewColumn*column;
GtkTreeIter iter;

GtkListStore*store;
char jour[50];
char disponibilite_matin[50];
char disponibilite_soir[50];


store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",Jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" 8h-12h",renderer,"text",Matin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" 15h-23h",renderer,"text",Soir,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("/home/saghirr/Desktop/agenda_disponibilité.txt","r");
if(f==NULL)
return;
else
{
//f=fopen("agenda.txt","a+");
while(fscanf(f,"%s%s%s",jour,disponibilite_matin,disponibilite_soir)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set( store, &iter, Jour, jour, Matin, disponibilite_matin, Soir, disponibilite_soir,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
