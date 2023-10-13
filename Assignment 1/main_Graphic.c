/*to compile the code use:
gcc -g -o name name.c `pkg-config --cflags --libs gtk+-3.0`
link: https://www.geeksforgeeks.org/how-to-create-gui-in-c-programming-using-gtk-toolkit/
*/
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define BOMBS 15
int  remainingCells = SIZE * SIZE - BOMBS;


// Define a structure to hold data passed to the callback.
typedef struct
{
    GtkWidget *button;
    char (*board)[SIZE][SIZE];
    int row;
    int col;
} ClickData;

void initializeBoard(char board[SIZE][SIZE])
{
    // The same as main.c you have developed:
    // here initialize all the board with board[i][j] = '-'
}

void placeBombs(char board[SIZE][SIZE])
{   
    // The same as main.c you have developed:
    // here randomly place BOMBS number of bombs in board like board[x][y] = 'X'
}

int countAdjacentBombs(char board[SIZE][SIZE], int x, int y)
{
    // The same as main.c you have developed:
    // here you must do the part counting the bombs around each cell
}

// Function to create and show the "Game Over" message window
void showGameOverMessage(int gameOver_win)
{   
    // after the game is over, this function is called to show a message in a new window
    // if gameOver_win ==0 means the user hit a bomb and in the new opened window it must say:
    // "Game Over! You hit a bomb."
    // OR 
    // ameOver_win ==1 which the user won the game 
    // and new opened window says: "Congratulations! You've won!"
    // for this part you use the code in "int mian()" function to open another window
}

// This function updates the buttons to reveal bombs
void updateBombButtons(GtkWidget *grid, char board[SIZE][SIZE])
{
    // This function is called when the game is over
    // here for all the elements in board[i][j]
    // if board[row][col] == 'X', you must update the window and put the image bomb.png
}

// This function is called when a grid item is clicked.
void grid_item_clicked(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
    ClickData *click_data = (ClickData *)data;
    int gameOver_win = 0;
    /* x and y are exactly the inputs given by user in the Terminal
    but Here they are received by user clicking on the board*/
    int x = click_data->row;
    int y = click_data->col;
    char(*board)[SIZE][SIZE] = click_data->board;

    if ((*board)[x][y] == 'X')
    {
        // In main.c we would print `X` if the user lose the game, but here
        // Instead of printing 'X' in the bomb cell I put the image
        // I call the function "updateBombButtons" to do this
        updateBombButtons(GTK_WIDGET(gtk_widget_get_parent(widget)), *board);

        // I use this line to print out the indexes of elements clicked by the user
        // I do this for troubleshooting. You must remove it when you finish your work
        // otherwise it means you just copied and
        // possibly you dont have any understanding of this code
        printf("Game Over! You hit a bomb.\n");

        // setting the flag to zero means the user lost the game
        gameOver_win = 0;
        // send this flag to "showGameOverMessage" function to open a new window
        showGameOverMessage(gameOver_win);
    }
    else
    {
        // in case the user chose a non-bomb cell
        remainingCells--;
        // Here if the chosen cell is not a bomb, count how many bombs are around
        int bombsNearby = countAdjacentBombs(*board, x, y);
        (*board)[x][y] = (char)('0' + bombsNearby);

        // Here I tell to put this number in each cell clicked by the user
        char label[2];
        snprintf(label, sizeof(label), "%c", (*board)[x][y]);
        gtk_button_set_label(GTK_BUTTON(click_data->button), label);

        if (remainingCells == 0)
        {   
            // if all non-bomb elements are guessed there are no cell left,
            // so the user won the game.
            updateBombButtons(GTK_WIDGET(gtk_widget_get_parent(widget)), *board);
            printf("Congratulations! You've won!\n");
            gameOver_win = 1;
            showGameOverMessage(gameOver_win);
        }
        // I use this line to print out the indexes of elements clicked by the user
        // I do this for troubleshooting. You must remove it when you finish your work
        // otherwise it means you just copied and
        // possibly you dont have any understanding of this code
        g_print("Clicked on Row %d, Column %d\n", x, y);
    }
}

int main(int argc, char *argv[])
{
    // I just initialize gtk, you can do it in any other way you want
    gtk_init(&argc, &argv);

    // declare a bunch of variables we need here
    char board[SIZE][SIZE];
    initializeBoard(board);
    placeBombs(board);

    /* declare a window with data type "GtkWidget"
    where you want to show everything in it*/
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Minesweeper Game - Pedram");
    /* with the following line of code, If we press "X" of the window
    it will get out of the game. You compile and run without this line and close
    the game and see the difference in the Terminal*/
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // I want to create a grid system on the window to make multiple buttons
    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Here is for a two dimensional buttons on the window
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            // Here is the image I want to put on all the buttons initially
            GtkWidget *image = gtk_image_new_from_file("unclicked.png");

            // Here I create the button
            GtkWidget *button = gtk_button_new();

            // Here I put the image on the button
            gtk_button_set_image(GTK_BUTTON(button), image);

            /* You can use this part of the code to change the shape of buttons
            //Apply custom CSS to make the button square
            const gchar *css = "button { border-radius: 0; }";
            GtkCssProvider *provider = gtk_css_provider_new();
            gtk_css_provider_load_from_data(provider, css, -1, NULL);
            gtk_style_context_add_provider(gtk_widget_get_style_context(button), GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_USER);
            */

            /* IMPORTANT: data structure is something we learn in the section
            4.2 Structures. Study this part from lecture notes, then come back here.
            I did this code with data structure, you may do it in your own way!
            Here I have made a data structure and I called it ClickData.
            Then I declared and initialized a variable named "data" with the type ClickData.
            I want to send all these information with "data" to the function I need.
            */
            ClickData *data = g_new(ClickData, 1);
            data->button = button;
            data->board = &board;
            data->row = row;
            data->col = col;

            // I created a function named "grid_item_clicked",
            // to handle user inputs and game scenarios.
            // I pass "data" to this function.
            g_signal_connect(button, "button-press-event", G_CALLBACK(grid_item_clicked), data);

            // col and row are the locations of each button in the grid
            gtk_grid_attach(GTK_GRID(grid), button, col, row, 1, 1);
        }
    }

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
