#ifndef _DISTRIBUTION_H
#define _DISTRIBUTION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "file.h"

typedef struct _dist
{
    long int sum;
    size_t size;
    double * dist;
    char ** val;
} Distribution;

Distribution * new_Distribution ();

Distribution * get_ascii_distribution (File * cont);

Distribution * get_ascii2_distribution (File * cont);

#endif
