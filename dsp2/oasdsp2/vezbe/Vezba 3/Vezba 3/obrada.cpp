#include <math.h>
#include <stdlib.h>
#include "obrada.h"
#include "sr_fft.h"

double time_buffer[FFT_SIZE];
double fft_buffer[FFT_SIZE];
double in_delay[FFT_SIZE/2];
double out_delay[FFT_SIZE/2];

extern double window[FFT_SIZE];

void obrada(double *in, double *out, int N)
{
  int i;

  for (i=0; i<N; i++)
    out[i] = in[i];
}
