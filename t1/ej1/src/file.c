#include "file.h"

size_t _size_file (FILE * pf)
{    
    size_t size = 0;
    fseek (pf, 0L, SEEK_END);
    size = ftell (pf);
    rewind (pf);
    return size;
}

File * new_file ()
{
    File * new = (File*) malloc (sizeof (File));
    new -> size = 0;
    new -> cont = NULL;
    return new;
}

size_t file_size (File * pf)
{
    return pf -> size;
}

char * file_cont (File * pf)
{
    return pf -> cont;
}

File * file_read (FILE * pf)
{
    size_t size = _size_file (pf);
    File * file = new_file ();
    file -> size = size;
    file -> cont = (char*) malloc (sizeof (char) * size);
    fread (file -> cont, sizeof (char), size, pf);
    return file;
}

void file_write (FILE * pf, File * cont)
{
    size_t size = file_size (cont);
    char * _cont = file_cont (cont);
    fwrite ((void*) _cont, sizeof (char), size, pf);
}
