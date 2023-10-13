#include <gtk/gtk.h>
/*to compile the code use:
gcc -g -o name name.c `pkg-config --cflags --libs gtk+-3.0`
Read more if you want: https://www.geeksforgeeks.org/how-to-create-gui-in-c-programming-using-gtk-toolkit/
*/
static GtkWidget *button;
static gboolean image_visible = FALSE;

// This function is called when the button is clicked.
void button_clicked(GtkButton *button, gpointer data) {
    image_visible = !image_visible; // Toggle image visibility

    if (image_visible) {
        GtkWidget *image = gtk_image_new_from_file("bomb.png");
        gtk_button_set_image(GTK_BUTTON(button), image);
    } else {
        GtkWidget *image = gtk_image_new_from_file("unclicked.png");
        gtk_button_set_image(GTK_BUTTON(button), image);
    }
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *grid;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Image Button Example");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create an image widget for the button
    GtkWidget *image = gtk_image_new_from_file("unclicked.png");
    button = gtk_button_new();
    gtk_button_set_image(GTK_BUTTON(button), image);
    g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 1, 1);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
