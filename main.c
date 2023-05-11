#include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

// Single 3 X 3 Matrix operation
GtkWidget *row1Column1;
gchar   *resultString;
GtkWidget *row1Column2;
GtkWidget *row1Column3;

GtkWidget *row2Column1;
GtkWidget *row2Column2;
GtkWidget *row2Column3;

GtkWidget *row3Column1;
GtkWidget *row3Column2;
GtkWidget *row3Column3;

// Arithmetic operation
GtkWidget *aRow1Column1;
GtkWidget *aRow1Column2;
GtkWidget *aRow1Column3;

GtkWidget *aRow2Column1;
GtkWidget *aRow2Column2;
GtkWidget *aRow2Column3;

GtkWidget *aRow3Column1;
GtkWidget *aRow3Column2;
GtkWidget *aRow3Column3;

GtkWidget *bRow1Column1;
GtkWidget *bRow1Column2;
GtkWidget *bRow1Column3;

GtkWidget *bRow2Column1;
GtkWidget *bRow2Column2;
GtkWidget *bRow2Column3;

GtkWidget *bRow3Column1;
GtkWidget *bRow3Column2;
GtkWidget *bRow3Column3;

GtkWidget *label_operation;
GtkWidget *label_result_string;
GtkWidget *labelHeading;
GtkWidget *selectOperation;
GtkWidget *bothMatrixElementsLabel;
GtkWidget *labelResultMatrix;



// single matrix operation declaration
int givenMatrix[3][3];
int transposeMatrix[3][3];
int cofactorMatrix[3][3];
int transposeOfCofactor[3][3];
float inverseMatrix[3][3];

// arithmetic operation matrix declaration
int givenAmatrix[3][3];
int givenBmatrix[3][3];
int additionResultMatrix[3][3];
int subtractionResultMatrix[3][3];
int multiplicationResultMatrix[3][3];

// converting user input to integer - single matrix
void convert_into_int()
{

    givenMatrix[0][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row1Column1)));
    givenMatrix[0][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row1Column2)));
    givenMatrix[0][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row1Column3)));

    givenMatrix[1][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row2Column1)));
    givenMatrix[1][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row2Column2)));
    givenMatrix[1][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row2Column3)));

    givenMatrix[2][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row3Column1)));
    givenMatrix[2][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row3Column2)));
    givenMatrix[2][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(row3Column3)));
}

// converting user input to integer - single matrix
void convert_into_int_both_matrix()
{

    givenAmatrix[0][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow1Column1)));
    givenAmatrix[0][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow1Column2)));
    givenAmatrix[0][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow1Column3)));

    givenAmatrix[1][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow2Column1)));
    givenAmatrix[1][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow2Column2)));
    givenAmatrix[1][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow2Column3)));

    givenAmatrix[2][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow3Column1)));
    givenAmatrix[2][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow3Column2)));
    givenAmatrix[2][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(aRow3Column3)));

    givenBmatrix[0][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow1Column1)));
    givenBmatrix[0][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow1Column2)));
    givenBmatrix[0][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow1Column3)));

    givenBmatrix[1][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow2Column1)));
    givenBmatrix[1][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow2Column2)));
    givenBmatrix[1][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow2Column3)));

    givenBmatrix[2][0] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow3Column1)));
    givenBmatrix[2][1] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow3Column2)));
    givenBmatrix[2][2] = atoi((char *)gtk_entry_get_text(GTK_ENTRY(bRow3Column3)));
}

// transpose matrix logic
void transpose_logic()
{
    // logic of transpose matrix
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transposeMatrix[j][i] = givenMatrix[i][j];
        }
    }
}

// determinant logic of matrix;
int determinant_logic()
{

    int det = (givenMatrix[0][0] * ((givenMatrix[1][1] * givenMatrix[2][2]) - (givenMatrix[1][2] * givenMatrix[2][1]))) - (givenMatrix[0][1] * ((givenMatrix[1][0] * givenMatrix[2][2]) - (givenMatrix[1][2] * givenMatrix[2][0]))) + (givenMatrix[0][2] * ((givenMatrix[1][0] * givenMatrix[2][1]) - (givenMatrix[1][1] * givenMatrix[2][0])));
    return det;
}

// inverse logic of the matrix
void inverse_logic()
{
    convert_into_int();
    float det = determinant_logic();

    cofactorMatrix[0][0] = ((givenMatrix[1][1] * givenMatrix[2][2]) - (givenMatrix[1][2] * givenMatrix[2][1]));
    cofactorMatrix[0][1] = (-1) * ((givenMatrix[1][0] * givenMatrix[2][2]) - (givenMatrix[1][2] * givenMatrix[2][0]));
    cofactorMatrix[0][2] = ((givenMatrix[1][0] * givenMatrix[2][1]) - (givenMatrix[1][1] * givenMatrix[2][0]));

    cofactorMatrix[1][0] = (-1) * ((givenMatrix[0][1] * givenMatrix[2][2]) - (givenMatrix[0][2] * givenMatrix[2][1]));
    cofactorMatrix[1][1] = ((givenMatrix[0][0] * givenMatrix[2][2]) - (givenMatrix[0][2] * givenMatrix[2][0]));
    cofactorMatrix[1][2] = (-1) * ((givenMatrix[0][0] * givenMatrix[2][1]) - (givenMatrix[0][1] * givenMatrix[2][0]));

    cofactorMatrix[2][0] = ((givenMatrix[0][1] * givenMatrix[1][2]) - (givenMatrix[0][2] * givenMatrix[1][1]));
    cofactorMatrix[2][1] = (-1) * ((givenMatrix[0][0] * givenMatrix[1][2]) - (givenMatrix[0][2] * givenMatrix[1][0]));
    cofactorMatrix[2][2] = ((givenMatrix[1][1] * givenMatrix[0][0]) - (givenMatrix[1][0] * givenMatrix[0][1]));

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            transposeOfCofactor[i][j] = cofactorMatrix[j][i];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            inverseMatrix[i][j] = (transposeOfCofactor[i][j]) / det;
        }
    }

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "\n%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f\n%.1f\t%.1f\t%.1f",
             inverseMatrix[0][0], inverseMatrix[0][1], inverseMatrix[0][2],
             inverseMatrix[1][0], inverseMatrix[1][1], inverseMatrix[1][2],
             inverseMatrix[2][0], inverseMatrix[2][1], inverseMatrix[2][2]);
    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}

// addition logic of matrix
int addition_logic()
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            additionResultMatrix[i][j] = givenAmatrix[i][j] + givenBmatrix[i][j];
        }
    }
}

// subtraction logic of matrix

int subtraction_logic()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            subtractionResultMatrix[i][j] = givenAmatrix[i][j] - givenBmatrix[i][j];
        }
    }
}

// multiplication logic of the matrix
void multiplication_logic()
{
    convert_into_int_both_matrix();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            multiplicationResultMatrix[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                multiplicationResultMatrix[i][j] += (givenAmatrix[i][k] * givenBmatrix[k][j]);
            }
        }
    }
}

// transpose of the matrix
void print_transpose(GtkWindow *widget, gpointer data)
{
    convert_into_int();
    transpose_logic();

    // Printing on the window
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d",
             transposeMatrix[0][0], transposeMatrix[0][1], transposeMatrix[0][2],
             transposeMatrix[1][0], transposeMatrix[1][1], transposeMatrix[1][2],
             transposeMatrix[2][0], transposeMatrix[2][1], transposeMatrix[2][2]);

    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}
// determinant of the matrix
void print_determinant(GtkWindow *widget, gpointer data)
{
    convert_into_int();
    int det = determinant_logic();

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "\nDeterminant: %d", det);
    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}

// inverse of the matrix
void print_inverse(GtkWindow *widget, gpointer data)
{

    convert_into_int();
    determinant_logic();
    int det = determinant_logic();
    if (det == 0)
    {
        char buffer[256];
        snprintf(buffer, sizeof(buffer), "\nInverse doesn't exist\n");
        gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
    }
    else
    {
        inverse_logic();
    }
}

// addition of matrix
void print_addition(GtkWidget *widget, gpointer data)
{
    char buffer[256];
    gchar *operationLabel = " + ";
    gtk_label_set_markup(GTK_LABEL(label_operation), operationLabel);
    snprintf(buffer, sizeof(buffer), operationLabel);
    gtk_label_set_text(GTK_LABEL(label_operation), buffer);

    convert_into_int_both_matrix();
    addition_logic();

    snprintf(buffer, sizeof(buffer), "\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d",
             additionResultMatrix[0][0], additionResultMatrix[0][1], additionResultMatrix[0][2],
             additionResultMatrix[1][0], additionResultMatrix[1][1], additionResultMatrix[1][2],
             additionResultMatrix[2][0], additionResultMatrix[2][1], additionResultMatrix[2][2]);
    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}

// subtraction of matrix
void print_subtraction(GtkWindow *widget, gpointer data)
{
    char buffer[256];
    gchar *operationLabel = " - ";
    snprintf(buffer, sizeof(buffer), operationLabel);
    gtk_label_set_text(GTK_LABEL(label_operation), buffer);

    convert_into_int_both_matrix();
    subtraction_logic();

    snprintf(buffer, sizeof(buffer), "\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d",
             subtractionResultMatrix[0][0], subtractionResultMatrix[0][1], subtractionResultMatrix[0][2],
             subtractionResultMatrix[1][0], subtractionResultMatrix[1][1], subtractionResultMatrix[1][2],
             subtractionResultMatrix[2][0], subtractionResultMatrix[2][1], subtractionResultMatrix[2][2]);
    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}

// multiplication of the matrix
void print_multiplication(GtkWindow *widget, gpointer data)
{
    char buffer[256];
    gchar *operationLabel = " x ";
    snprintf(buffer, sizeof(buffer), operationLabel);
    gtk_label_set_text(GTK_LABEL(label_operation), buffer);
    multiplication_logic();
    snprintf(buffer, sizeof(buffer), "\n%d\t%d\t%d\n%d\t%d\t%d\n%d\t%d\t%d\n",
             multiplicationResultMatrix[0][0], multiplicationResultMatrix[0][1], multiplicationResultMatrix[0][2],
             multiplicationResultMatrix[1][0], multiplicationResultMatrix[1][1], multiplicationResultMatrix[1][2],
             multiplicationResultMatrix[2][0], multiplicationResultMatrix[2][1], multiplicationResultMatrix[2][2]);
    gtk_label_set_text(GTK_LABEL(label_result_string), buffer);
}

// activate the application
void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window;
    GtkWidget *grid;
    GtkCssProvider *provider;
    GdkDisplay *display;
    GdkScreen *screen;
    GtkWidget *buttonAddition;
    GtkWidget *buttonSubtraction;
    GtkWidget *buttonMultiplication;
    GtkWidget *buttonTranspose;
    GtkWidget *buttonDeterminant;
    GtkWidget *buttonInverse;
    GtkWidget *label;

    /* create a new window, and set its title */
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Matrix Calculator");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 600);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), TRUE);

    /* construct the container that is going pack our buttons */
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    //GTK CSS PROVIDER
    provider = gtk_css_provider_new();
    display = gdk_display_get_default();
    screen = gdk_display_get_default_screen(display);
    gtk_style_context_add_provider_for_screen(screen, GTK_STYLE_PROVIDER(provider),GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gsize bytes_written, bytes_read;
    const gchar *file = "calculator.css";
    GError *error = 0;
    gtk_css_provider_load_from_path(provider,g_filename_to_utf8(file,strlen(file),&bytes_read, &bytes_written, &error),NULL);
    g_object_unref(provider);
    gchar *labelText = "Enter the  Matrix:";
    labelHeading = gtk_label_new(NULL);
    gtk_widget_set_name(labelHeading,"elements-label");
    gtk_label_set_markup(GTK_LABEL(labelHeading), labelText);
    gtk_grid_attach(GTK_GRID(grid), labelHeading, 0, 0, 1, 1);

    row1Column1 = gtk_entry_new();
    gtk_widget_set_name(row1Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row1Column1), "a11");
    gtk_grid_attach(GTK_GRID(grid), row1Column1, 0, 1, 1, 1);

    row1Column2 = gtk_entry_new();
    gtk_widget_set_name(row1Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row1Column2), "a12");
    gtk_grid_attach(GTK_GRID(grid), row1Column2, 1, 1, 1, 1);

    row1Column3 = gtk_entry_new();
    gtk_widget_set_name(row1Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row1Column3), "a13");
    gtk_grid_attach(GTK_GRID(grid), row1Column3, 2, 1, 2, 1);

    row2Column1 = gtk_entry_new();
    gtk_widget_set_name(row2Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row2Column1), "a21");
    gtk_grid_attach(GTK_GRID(grid), row2Column1, 0, 2, 1, 1);

    row2Column2 = gtk_entry_new();
    gtk_widget_set_name(row2Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row2Column2), "a22");
    gtk_grid_attach(GTK_GRID(grid), row2Column2, 1, 2, 1, 1);

    row2Column3 = gtk_entry_new();
    gtk_widget_set_name(row2Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row2Column3), "a23");
    gtk_grid_attach(GTK_GRID(grid), row2Column3, 2, 2, 2, 1);

    row3Column1 = gtk_entry_new();
    gtk_widget_set_name(row3Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row3Column1), "a31");
    gtk_grid_attach(GTK_GRID(grid), row3Column1, 0, 3, 1, 1);

    row3Column2 = gtk_entry_new();
    gtk_widget_set_name(row3Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row3Column2), "a32");
    gtk_grid_attach(GTK_GRID(grid), row3Column2, 1, 3, 1, 1);

    row3Column3 = gtk_entry_new();
    gtk_widget_set_name(row3Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(row3Column3), "a33");
    gtk_grid_attach(GTK_GRID(grid), row3Column3, 2, 3, 2, 1);

    /* Creating label for the user*/
    gchar *str = "";
    selectOperation = gtk_label_new(NULL);
    gtk_widget_set_name(selectOperation,"selectOperation");
    gtk_label_set_markup(GTK_LABEL(selectOperation), str);
    gtk_label_set_xalign (selectOperation, 0.1);
    gtk_grid_attach(GTK_GRID(grid), selectOperation, 0, 4, 1, 1);

    /* Matrix Calculator Button */
    buttonTranspose = gtk_button_new_with_label("Transpose");
    gtk_widget_set_name(buttonTranspose, "btn-single-matrix");
    gtk_widget_set_tooltip_text(buttonTranspose, "Transpose of a 3x3 Matrix");
    g_signal_connect(buttonTranspose, "clicked", G_CALLBACK(print_transpose), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonTranspose, 0, 5, 1, 1);

    buttonDeterminant = gtk_button_new_with_label("Determinant");
    gtk_widget_set_name(buttonDeterminant, "btn-single-matrix");
    gtk_widget_set_tooltip_text(buttonDeterminant, "determinant of a 3x3 matrix");
    g_signal_connect(buttonDeterminant, "clicked", G_CALLBACK(print_determinant), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonDeterminant, 1, 5, 1, 1);

    buttonInverse = gtk_button_new_with_label("Inverse");
    gtk_widget_set_name(buttonInverse, "btn-single-matrix");
    gtk_widget_set_tooltip_text(buttonInverse, "inverse of a 3x3 matrix");
    g_signal_connect(buttonInverse, "clicked", G_CALLBACK(print_inverse), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonInverse, 2, 5, 1, 1);

    gchar *labelTextNew = "Enter the  Matrix:";
    bothMatrixElementsLabel = gtk_label_new(NULL);
    gtk_widget_set_name(bothMatrixElementsLabel, "label-both-matrix-elements");
    gtk_label_set_markup(GTK_LABEL(bothMatrixElementsLabel), labelTextNew);
    gtk_grid_attach(GTK_GRID(grid), bothMatrixElementsLabel, 0, 9, 1, 1);

    // Elements of the matrix A
    aRow1Column1 = gtk_entry_new();
    gtk_widget_set_name(aRow1Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow1Column1), "a11");
    gtk_grid_attach(GTK_GRID(grid), aRow1Column1, 0, 10, 1, 1);

    aRow1Column2 = gtk_entry_new();
    gtk_widget_set_name(aRow1Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow1Column2), "a12");
    gtk_grid_attach(GTK_GRID(grid), aRow1Column2, 1, 10, 1, 1);

    aRow1Column3 = gtk_entry_new();
    gtk_widget_set_name(aRow1Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow1Column3), "a13");
    gtk_grid_attach(GTK_GRID(grid), aRow1Column3, 2, 10, 1, 1);

    aRow2Column1 = gtk_entry_new();
    gtk_widget_set_name(aRow2Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow2Column1), "a21");
    gtk_grid_attach(GTK_GRID(grid), aRow2Column1, 0, 11, 1, 1);

    aRow2Column2 = gtk_entry_new();
    gtk_widget_set_name(aRow2Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow2Column2), "a22");
    gtk_grid_attach(GTK_GRID(grid), aRow2Column2, 1, 11, 1, 1);

    aRow2Column3 = gtk_entry_new();
    gtk_widget_set_name(aRow2Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow2Column3), "a23");
    gtk_grid_attach(GTK_GRID(grid), aRow2Column3, 2, 11, 1, 1);

    aRow3Column1 = gtk_entry_new();
    gtk_widget_set_name(aRow3Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow3Column1), "a31");
    gtk_grid_attach(GTK_GRID(grid), aRow3Column1, 0, 12, 1, 1);

    aRow3Column2 = gtk_entry_new();
    gtk_widget_set_name(aRow3Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow3Column2), "a32");
    gtk_grid_attach(GTK_GRID(grid), aRow3Column2, 1, 12, 1, 1);

    aRow3Column3 = gtk_entry_new();
    gtk_widget_set_name(aRow3Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(aRow3Column3), "a33");
    gtk_grid_attach(GTK_GRID(grid), aRow3Column3, 2, 12, 1, 1);

    gchar *operationLabel = "<b>?</b>";
    label_operation = gtk_label_new(NULL);
    gtk_widget_set_name(label_operation,"operation-label");
    gtk_label_set_markup(GTK_LABEL(label_operation), operationLabel);
    gtk_grid_attach(GTK_GRID(grid), label_operation, 1, 13, 1, 1);

    // Elements of the Matrix B
    bRow1Column1 = gtk_entry_new();
    gtk_widget_set_name(bRow1Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow1Column1), "b11");
    gtk_grid_attach(GTK_GRID(grid), bRow1Column1, 0, 14, 1, 1);

    bRow1Column2 = gtk_entry_new();
    gtk_widget_set_name(bRow1Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow1Column2), "b12");
    gtk_grid_attach(GTK_GRID(grid), bRow1Column2, 1, 14, 1, 1);

    bRow1Column3 = gtk_entry_new();
    gtk_widget_set_name(bRow1Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow1Column3), "b13");
    gtk_grid_attach(GTK_GRID(grid), bRow1Column3, 2, 14, 1, 1);

    bRow2Column1 = gtk_entry_new();
    gtk_widget_set_name(bRow2Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow2Column1), "b21");
    gtk_grid_attach(GTK_GRID(grid), bRow2Column1, 0, 15, 1, 1);

    bRow2Column2 = gtk_entry_new();
    gtk_widget_set_name(bRow2Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow2Column2), "b22");
    gtk_grid_attach(GTK_GRID(grid), bRow2Column2, 1, 15, 1, 1);

    bRow2Column3 = gtk_entry_new();
    gtk_widget_set_name(bRow2Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow2Column3), "b23");
    gtk_grid_attach(GTK_GRID(grid), bRow2Column3, 2, 15, 1, 1);

    bRow3Column1 = gtk_entry_new();
    gtk_widget_set_name(bRow3Column1, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow3Column1), "b31");
    gtk_grid_attach(GTK_GRID(grid), bRow3Column1, 0, 16, 1, 1);

    bRow3Column2 = gtk_entry_new();
    gtk_widget_set_name(bRow3Column2, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow3Column2), "b32");
    gtk_grid_attach(GTK_GRID(grid), bRow3Column2, 1, 16, 1, 1);

    bRow3Column3 = gtk_entry_new();
    gtk_widget_set_name(bRow3Column3, "input-field");
    gtk_entry_set_placeholder_text(GTK_ENTRY(bRow3Column3), "b33");
    gtk_grid_attach(GTK_GRID(grid), bRow3Column3, 2, 16, 1, 1);

    /* Creating label for the user*/
    str = "";
    GtkWidget *arithmeticOperationLabel;
    arithmeticOperationLabel = gtk_label_new(NULL);
    gtk_widget_set_name(arithmeticOperationLabel,"arithmetic-operation-label");
    gtk_label_set_markup(GTK_LABEL(arithmeticOperationLabel), str);
    gtk_label_set_xalign (arithmeticOperationLabel, 0.1);
    gtk_grid_attach(GTK_GRID(grid), arithmeticOperationLabel, 0, 17, 1, 1);

    buttonAddition = gtk_button_new_with_label("Addition");
    gtk_widget_set_name(buttonAddition, "btn-two-matrix");
    gtk_widget_set_tooltip_text(buttonAddition, "Add two 3x3 Matrix");
    g_signal_connect(buttonAddition, "clicked", G_CALLBACK(print_addition), NULL);

    gtk_grid_attach(GTK_GRID(grid), buttonAddition, 0, 18, 1, 1);

    buttonSubtraction = gtk_button_new_with_label("Subtraction");
    gtk_widget_set_name(buttonSubtraction, "btn-two-matrix");
    gtk_widget_set_tooltip_text(buttonSubtraction, "Subtract two 3x3 matrix");
    g_signal_connect(buttonSubtraction, "clicked", G_CALLBACK(print_subtraction), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonSubtraction, 1, 18, 1, 1);

    buttonMultiplication = gtk_button_new_with_label("Multiplication");
    gtk_widget_set_name(buttonMultiplication, "btn-two-matrix");
    gtk_widget_set_tooltip_text(buttonMultiplication, "Multiply two 3x3 matrix");
    g_signal_connect(buttonMultiplication, "clicked", G_CALLBACK(print_multiplication), NULL);
    gtk_grid_attach(GTK_GRID(grid), buttonMultiplication, 2, 18, 1, 1);

    GtkWidget *result_label;
    gchar *resultText = "Output:";
    result_label = gtk_label_new(NULL);
    gtk_widget_set_name(result_label,"result-label");
    gtk_label_set_xalign (result_label, 0.1);
    gtk_label_set_markup(GTK_LABEL(result_label), resultText);
    gtk_grid_attach(GTK_GRID(grid), result_label, 0, 19, 1, 1);

    resultString = "-";
    label_result_string = gtk_label_new(NULL);
    gtk_widget_set_name(label_result_string,"label-result-content");
    gtk_label_set_xalign(label_result_string, 0.1);
    gtk_grid_attach(GTK_GRID(grid), label_result_string, 0, 20, 1, 1);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{


    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);

    g_object_unref(app);

    return status;
}
