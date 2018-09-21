#include "distribution.h"

Distribution * new_Distribution ()
{
    Distribution * new = (Distribution*) malloc (sizeof (Distribution));
    new -> sum = 0;
    new -> size = 0;
    new -> dist = NULL;
    new -> val = NULL;
}

void delete_Distribution (Distribution * dist)
{
    free (dist -> dist);
    free (dist -> val);
}

long int set_dist_sum (long int sum, Distribution * pd)
{
    return (pd -> sum = sum);
}

long int set_dist_size (size_t size, Distribution * pd)
{
    return (pd -> size = size);
}

double * set_dist_dist (double * dist, Distribution * pd)
{
    return (pd -> dist = dist);
}

char ** set_dist_val (char ** val, Distribution * pd)
{
    return (pd -> val = val);
}

void set_distribution (long int sum, size_t size, double * dist, char ** val, Distribution * pd)
{
    set_dist_sum (sum, pd);
    set_dist_size (size, pd);
    set_dist_dist (dist, pd);
    set_dist_val (val, pd);
}

Distribution * get_ascii_distribution (File * cont)
{
    Distribution * new = new_Distribution ();
    double * dist = (double*) malloc (sizeof (double) * 255);
    memset (dist, 0, sizeof (double) * 255);
    char ** val = (char**) malloc (sizeof (char*) * 255);
    for (int i = 0x0; i < 0xFF; ++i)
    {
        val [i] = (char*) malloc (2 * sizeof (char));
        val [i][0] = (char) (i+1), val [i][1] = '\0';
    }
    char * _cont = file_cont (cont);
    size_t size = file_size (cont);
    for (int i = 0; i < size; ++i)
    {
        dist [_cont [i]] += 1.0f;
    }
    for (int i = 0; i < 0xFF; ++i)
    {
        dist [i] /= (double)size;
    }
    set_distribution (size, 255, dist, val, new);
    return new;
}

Distribution * get_ascii2_distribution (File * cont)
{
    Distribution * single_dist = get_ascii_distribution (cont);    /* Distribution of single characters. */
    double * dist_single = single_dist -> dist;
    Distribution * new = new_Distribution ();
    double * dist = (double*) malloc (sizeof (double) * 255 * 255);
    memset (dist, 0, sizeof (double) * 255 * 255);
    char ** val = (char**) malloc (sizeof (char*) * 255 * 255);
    for (int i = 0x0; i < 0xFF; ++i)
    {
        for (int j = 0x0; j < 0xFF; ++j)
        {
            val [i + j * 255] = (char*) malloc (3 * sizeof (char));
            val [i + j * 255][0] = (char) (i+1), val [i + j * 255][1] = (char) (j+1), val [i + j * 255][2] = '\0';
        }
    }
    char * _cont = file_cont (cont);
    long int size = file_size (cont);
    for (int i = 0; i < size-1; ++i)
    {
        dist [_cont [i] + 255 * _cont [i+1]] += 1.0f;
    }
    for (int i = 0; i <= 255*255; ++i)
    {
        dist [i] /= (double)size;
    }
    for (int i = 0; i < 0xFF; ++i)
    {
        for (int j = 0; j < 0xFF; ++j)
        {
            dist [i + 255 * j] /= (dist_single [j] != 0.0f)? \
                                  dist_single [j] : \
                                  1.0f;                         // Ésta obtiene la probabilidad como 
                                                                // P (A | B) = P (A n B) / P(B)
        }
    }
    set_distribution (size, 255 * 255, dist, val, new);
    return new;
}
