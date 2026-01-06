#ifndef PSTAT_H
#define PSTAT_H

#include "kernel/types.h"
#include "kernel/param.h"

// NPROC IS MAX NUMBER OF PROCESSES
struct pstat {
  int pid[NPROC];     // PID of each process
  int inuse[NPROC];   // Whether slot is in use (0 or 1)
  int priority[NPROC]; // Current priority (0-3)
  int ticks[NPROC];    // How many ticks it has run at current level
  int state[NPROC];    // State (RUNNABLE, SLEEPING, etc.)
};

#endif // PSTAT_H
