#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "pstat.h" // Χρειάζεσαι αυτό για να ξέρεις τη struct pstat
#include "kernel/param.h"

int main(int argc, char *argv[])
{
  struct pstat st;
  // Κλήση του getpinfo για να γεμίσεις τη δομή pstat
  if(getpinfo(&st) == -1){
    printf("getpinfo failed\n");
    exit(1);
  }
  // Εκτύπωση των πληροφοριών διεργασιών
  printf("PID\tPriority\tState\tTicks\n");

  // Βρόχος για όλες τις διεργασίες
  for(int i = 0; i < NPROC; i++){
    if(st.inuse[i]){
      printf("%d\t%d\t\t%d\t%d\n", st.pid[i], st.priority[i], st.state[i], st.ticks[i]);
    }
  }

  exit(0); 
}