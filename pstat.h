#ifndef PSTAT_H
#define PSTAT_H

#include "kernel/types.h"
#include "kernel/param.h"

// NPROC IS MAX NUMBER OF PROCESSES
struct pstat {
  int inuse[NPROC];      // Αν χρησιμοποιείται η θυρίδα
  int pid[NPROC];        // Process ID
  int ppid[NPROC];       // Parent Process ID (ΝΕΟ)
  uint64 sz[NPROC];      // Μέγεθος διεργασίας σε bytes (ΝΕΟ)
  char name[NPROC][16];  // Όνομα διεργασίας (ΝΕΟ)
  int priority[NPROC];   // Προτεραιότητα
  int state[NPROC];      // Κατάσταση (RUNNABLE, SLEEPING, κλπ)
  int ticks[NPROC];      // Ticks που έχει καταναλώσει
};

#endif // PSTAT_H
