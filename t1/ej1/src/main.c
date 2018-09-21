/*  Ejercicio 1 : Tarea 1 - Image Compression
 *  autor       : José Joaquín Zubieta Rico
 *  date        : 08-29-2018
 *  subject     : Image Compression
 *  description : Ejercicio uno de la primer tarea de compresión de imágenes, calcular las distribuciones de los caracteres ascii, así como correlaciones hasta 2er orden.
 #  license     : GPL v3 (https://www.gnu.org/licenses/gpl-3.0.en.html)
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "distribution.h"

int main ( int argc , char * const argv [] )
{
    char * file_name = (char*) malloc (sizeof (char) * 1024);
    if (argc > 1)
    {
        strcpy (file_name, argv [1]);
    }
    else
    {
        printf ("Introduzca el nombre de archivo a analizar.\n");
        scanf ("%s", file_name);
    }

    FILE * pf = fopen (file_name, "rb+");

    if (pf == NULL)
    {
        perror ("No existe tal archivo o soy incapaz de abrirlo.\n");
        exit (EXIT_FAILURE);
    }

    File * file = file_read (pf);

    Distribution * dist_single = get_ascii_distribution (file);

    for (int i=0; i <= 0xFF; ++i);/*
    {
        printf ("P(%c) = %lf\n", (char) i, dist_single -> dist [i]);
        printf ("%d %lf\n", i, dist_single -> dist [i]);
    }*/

    Distribution * dist_double = get_ascii2_distribution (file);

    for (int i = 0; i <= 0x7F; ++i)
    {
        printf ("%d\t", i);
    }
    printf ("\n");
    for (int i = 0; i < 0x7F; ++i)
    {
        printf ("%d\t", ++i);
        for (int j = 0; j < 0x7F; ++j)
        {
            printf ("%.8lf\t", dist_double -> dist [i + 255*j]);
        }
        printf ("\n");
    }

    return 0;
}
