#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // An Adjective is either "wow", "many", "so" or "such".
  // A Noun is either "lisp", "language", "c", "book" or "build".
  // A Phrase is an Adjective followed by a Noun.
  // A Doge is zero or more Phrases.

  // Build a perser 'Adjective' to recognize descriptions
  mpc_parser_t* Adjective = mpc_or(4,
    mpc_sym("wow"),
    mpc_sym("many"),
    mpc_sym("so"),
    mpc_sym("such")
  );

  // Build a parser 'Noun' to recognize *things*
  mpc_parser_t* Noun = mpc_or(7,
    mpc_sym("lisp"),
    mpc_sym("language"),
    mpc_sym("book"),
    mpc_sym("build"),
    mpc_sym("c"),
    mpc_sym("lithp"),
    mpc_sym("scheme")
  );

  mpc_parser_t* Phrase = mpc_and(2, mpc_strfold,
    Adjective, Noun,
    free
  );

  mpc_parser_t* Doge = mpc_many(mpcf_strfold, Phrase);

  return 0;
}
