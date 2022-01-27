#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

int main(int argc, char** argv) {
  /* Print Version and Exit Information */
  puts("Lithp Version 0.0.0.2");
  puts("Press Ctrl+c to Exit\n");

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
