#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GtkWidget* Entry, *Entry2;
GtkWidget* EqualResult, *DifferentResult;

char Texto1[100], Texto2[100];

static void CompararTextos();

int main(int argc, char *argv[])
{
    /* Declarando variáveis e inicializando o GTK */
    GtkWidget* Window;
    GtkWidget* Box;
    GtkWidget* Button;

    gtk_init(&argc, &argv);

    /* Atribuindo valor as variaveis anteriormente declaradas */
    Window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    Box = gtk_box_new(TRUE, 1);
    Button = gtk_button_new_with_label("Comparar textos");
    Entry = gtk_entry_new();
    Entry2 = gtk_entry_new();
    EqualResult = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Ambos os textos são iguais!"
    );

    DifferentResult = gtk_message_dialog_new(
        NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Ambos os textos são diferentes!"
    );
    /* Criando containers, tornando objetos visiveis e etc */
    gtk_container_add(GTK_CONTAINER(Window), Box);
    gtk_box_pack_start(GTK_BOX(Box), Entry, TRUE, TRUE, 1);
    gtk_box_pack_start(GTK_BOX(Box), Entry2, TRUE, TRUE, 1);
    gtk_box_pack_start(GTK_BOX(Box), Button, TRUE, TRUE, 1);
    gtk_widget_show_all(Window);
    gtk_widget_show_all(Entry);
    gtk_widget_show_all(Entry2);
    gtk_widget_show_all(Button);

    /* Adicionando título e redimensionando a janela */
    gtk_widget_set_size_request(GTK_WIDGET(Window), 300, 200);
    gtk_window_set_title(GTK_WINDOW(Window), "Simples comparador de texto feito em C!");
    
    /* Eventos */
    g_signal_connect(G_OBJECT(Button), "clicked", G_CALLBACK(CompararTextos), NULL);
    /* Loop do GTK */
    gtk_main();

    return 0;
}

static void CompararTextos()
{
    strcpy((char *) Texto1, gtk_entry_get_text(GTK_ENTRY(Entry)));
    strcpy((char *) Texto2, gtk_entry_get_text(GTK_ENTRY(Entry2)));

    if (strlen((char *) Texto1) <= strlen((char *) Texto2) && strcmp((char *) Texto1, (char *) Texto2) == 1 || strlen((char *) Texto2) > strlen((char *) Texto1))
    {
        g_print("Ambos os textos apresentam diferenças!\n");
        gtk_dialog_run(GTK_DIALOG(DifferentResult));
        gtk_widget_destroy(DifferentResult);
        gtk_main_quit();
    }
    else if (strlen((char *) Texto1) == strlen((char *) Texto2) && strcmp((char *) Texto1, (char *) Texto2) == 0)
    {
        g_print("Ambos os textos são iguais!\n");
        gtk_dialog_run(GTK_DIALOG(EqualResult));
        gtk_widget_destroy(EqualResult);
        gtk_main_quit();
    }
}
