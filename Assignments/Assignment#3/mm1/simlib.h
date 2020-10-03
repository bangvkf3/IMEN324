/* This is simlib.h. */

/* Include files. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simlibdefs.h"

/* Declare simlib global variables. */

extern int    *list_rank, *list_size, next_event_type, maxatr, maxlist;
extern float  *transfer, sim_time, prob_distrib[26];
extern struct master {
    float  *value;
    struct master *pr;
    struct master *sr;
} **head, **tail;

/* Declare simlib functions. */

extern void  init_simlib(void);
extern void  list_file(int option, int list);
extern void  list_remove(int option, int list);
extern void  timing(void);
extern void  event_schedule(float time_of_event, int type_of_event);
extern int   event_cancel(int event_type);
extern float sampst(float value, int varibl);
extern float timest(float value, int varibl);
extern float filest(int list);
extern void  out_sampst(FILE *unit, int lowvar, int highvar);
extern void  out_timest(FILE *unit, int lowvar, int highvar);
extern void  out_filest(FILE *unit, int lowlist, int highlist);
extern float expon(float mean, int stream);
extern int   random_integer(float prob_distrib[], int stream);
extern float uniform(float a, float b, int stream);
extern float erlang(int m, float mean, int stream);
extern float lcgrand(int stream);
extern void  lcgrandst(long zset, int stream);
extern long  lcgrandgt(int stream);

