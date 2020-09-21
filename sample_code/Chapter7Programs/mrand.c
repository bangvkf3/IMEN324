/* Combined MRG from Sec. 7.3.2, from L'Ecuyer (1999).  Multiple
   (10,000) streams are supported, with seed vectors spaced
   10,000,000,000,000,000 apart.  Throughout, input argument "stream"
   must be an int giving the desired stream number.  The header file
   mrand_seeds.h is included here, so must be available in the
   appropriate directory.  The header file mrand.h must be included in
   the calling program (#include "mrand.h") before using these
   functions.

   Usage: (Three functions)

   1. To obtain the next U(0,1) random number from stream "stream,"
      execute
          u = mrand(stream); 
      where mrand is a double function.  The double variable u will
      contain the next random number.

   2. To set the seed vector for stream "stream" to a desired 6-vector,
      execute
          mrandst(zset, stream);
      where mrandst is a void function and zset must be a double
      vector with positions 0 through 5 set to the desired
      stream 6-vector, as described in Sec. 7.3.2.

   3. To get the current (most recently used) 6-vector of integers in
      the sequences (to use, e.g., as the seed for a subsequent
      independent replication), into positions 0 through 5 of the
      double vector zget, execute
          mrandgt(zget, stream);
      where mrandgt is void function.  */

#include "mrand_seeds.h"
#define norm   2.328306549295728e-10  /* 1.0/(m1+1) */
#define norm2  2.328318825240738e-10  /* 1.0/(m2+1) */
#define m1     4294967087.0
#define m2     4294944443.0

/* Generate the next random number. */

double mrand(int stream)
{
    long k;
    double p,
           s10 = drng[stream][0], s11 = drng[stream][1], s12 = drng[stream][2],
           s20 = drng[stream][3], s21 = drng[stream][4], s22 = drng[stream][5];

    p = 1403580.0 * s11 - 810728.0 * s10;
    k = p / m1;  p -= k*m1;  if (p < 0.0) p += m1;
    s10 = s11;   s11 = s12;  s12 = p;

    p = 527612.0 * s22 - 1370589.0 * s20;
    k = p / m2;  p -= k*m2;  if (p < 0.0) p += m2;
    s20 = s21;   s21 = s22;  s22 = p; 

    drng[stream][0] = s10;  drng[stream][1] = s11;  drng[stream][2] = s12;
    drng[stream][3] = s20;  drng[stream][4] = s21;  drng[stream][5] = s22;

    if (s12 <= s22) return ((s12 - s22 + m1) * norm);
    else return ((s12 - s22) * norm);
}

/* Set seed vector for stream "stream". */

void mrandst(double* seed, int stream)
{
int i;
    for (i = 0; i <= 5; ++i) drng[stream][i] = seed[i];
}

/* Get seed vector for stream "stream". */

void mrandgt(double* seed, int stream)
{
int i;
    for (i = 0; i <= 5; ++i) seed[i] = drng[stream][i];
}
