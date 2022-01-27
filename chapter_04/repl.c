#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

int main(int argc, char** argv) {
  /* Print Version and Exit Information */
  puts("\x1b[1;31mLithp\x1b[0m - Version 0.0.0.3");
  puts("A LISP inspired by the courage and bravery of Mike Tyson");
  puts("Press Ctrl+c at anytime to exit\n");

  // In a endless loop...
  while(1) {
    // Output out prompt and get input
    char *input = readline("lithp> ");

    // Add input to history
    add_history(input);

    // Echo input back to user
    printf("No! You're a %s\n", input);

    // Free retrieved input
    free(input);
  }

  return 0;
}
