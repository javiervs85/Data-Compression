#ifndef _FILE_H
#define _FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _file 
{
    size_t size;
    char * cont;
} File;

File * new_file ();

size_t file_size (File * pf);

char * file_cont (File * pf);

File * file_read (FILE *pf);

void file_write (FILE *pf, File * cont);

#endif
