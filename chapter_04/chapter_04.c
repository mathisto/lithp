#include <stdio.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv) {
  /* Print Version and Exit Information */
  puts("Lithp Version 0.0.0.1");
  puts("Press Ctrl+c to Exit\n");

  // In a endless loop...
  while(1) {
    // Output out prompt
    fputs("lithp> ", stdout);

    // Read a line of user input up to 2048 characters
    fgets(input, 2048, stdin);

    // Echo input back to user
    printf("Now you're a %s", input);
  }

  return 0;
}
