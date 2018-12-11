#include <gtk/gtk.h>
#include <string.h>
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>


#include "modifier_regime.h"
#include <gtk/gtk.h>
#include "list_des_adherants.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>

#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>

/*enum 
  {
    Jour,
    Matin,
    Soir,
    COLUMNS
  };

void afficher(GtkWidget *liste)
{
GtkCellRenderer*renderer;
GtkTreeViewColumn * column;
GtkTreeIter iter;

GtkListStore*store;
char jour[50];
char disponibilite_matin[30];
char disponibilite_soir[30];


store=NULL;
FILE*f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Jour",renderer,"text",jour,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Matin",renderer,"text",disponibilite_matin,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes(" Soir",renderer,"text",disponibilite_soir,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("agenda.txt","r");
if(f==NULL)
return;
else
{
f=fopen("agenda.txt","a+");
while(fscanf(f,"%s %s %s",Jour,jour,Matin,disponibilite_matin,Soir,disponibilite_soir)!=EOF)
{
gtk_list_store_append (store,&iter);

gtk_list_store_set(store,&iter,jour,disponibilite_matin,disponibilite_soir,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}}

gtk_tree_view_append_column(GTK_TREE_VIEW(liste),GtkTreeViewColumn)


/*void on_button10_clicked (GtkWidget *objet_graphique,gpointer user_data)
{
  GtkWidget *window23;
  GtkWidget *window2;
  GtkWidget *treeview6;
  GtkWidget *liste;
  window2=lookup_widget(object_graphique,"window2");
  gtk_widget_hide(window2);
  window23=create_window23();
  gtk_widget_show(window23);
  liste=lookup_widget(object_graphique,"treeview6");
  liste=lookup_widget(window23,"treeview6");
  afficher_message(liste);
}*/