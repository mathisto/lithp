#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>
#include "mpc.h"

int main(int argc, char** argv) {
  // Introduce the basic polish notation calculator parser
  // One step closer to a LISP. *shivers with excitement*
  mpc_parser_t* Number = mpc_new("number");
  mpc_parser_t* Operator = mpc_new("operator");
  mpc_parser_t* Expression = mpc_new("expression");
  mpc_parser_t* Lithp = mpc_new("lithp");

  // Define the parsers in the context of the lithp language
  mpca_lang(MPCA_LANG_DEFAULT,
  "                                                            \
    number     : /-?[0-9]+/ ;                                   \
    operator   : '+' | '-' | '*' | '/' ;                       \
    expression : <number> | '(' <operator> <expression>+ ')' ; \
    lithp      : /^/ <operator> <expression>+ /$/ ;                       \
  ",
  Number, Operator, Expression, Lithp);

  /* Print Version and Exit Information */
  puts("\x1b[1;31mLithp\x1b[0m - Version 0.0.0.4");
  puts("A LISP inspired by the courage and bravery of Mike Tyson");
  puts("Press Ctrl+c at anytime to exit\n");

  // In a endless loop...
  while(1) {
    // Output out prompt and get input
    char *input = readline("lithp> ");

    // Add input to history
    add_history(input);

    // Attempt to parse user input
    mpc_result_t r;
    if (mpc_parse("<stdin>", input, Lithp, &r)) {
      // Print the Abstract Syntax Tree
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    }
    else
    {
      // Otherwise, print the error
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }

    // Free retrieved input
    free(input);
  }

  mpc_cleanup(4, Number, Operator, Expression, Lithp);
  return 0;
}

/*
// Bonus Marks:
// Write a regular expression matching strings of all a or b such as aababa or bbaa.
  / [ab]+ /
// Write a regular expression matching strings of consecutive a and b such as ababab or aba.
/ ab(a|ab)* /
// Write a regular expression matching pit, pot and respite but not peat, spit, or part.
/ ^(pit|pot|respite)$ /
*/
