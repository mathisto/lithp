#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // An Adjective is either "wow", "many", "so" or "such".
  // A Noun is either "lisp", "language", "c", "book" or "build".
  // A Phrase is an Adjective followed by a Noun.
  // A Doge is zero or more Phrases.
  mpc_parser_t* Adjective = mpc_new("Adjective");
  mpc_parser_t* Noun = mpc_new("Noun");
  mpc_parser_t* Phrase = mpc_new("Phrase");
  mpc_parser_t* Doge = mpc_new("Doge");

  mpca_lang(MPCA_LANG_DEFAULT,
    "                                               \
       adjective : \"wow\" | \"many\"               \
                 | \"so\"  | \"such\";              \
       noun      : \"lisp\" | \"language\"          \
                 | \"book\" | \"build\"             \
                 | \"c\"    | \"scheme\"            \
                 | \"lithp\";                       \
       phrase    : <adjective> <noun>;              \
       doge      : <phrase>*;                       \
    ",
    Adjective, Noun, Phrase, Doge);

  // Parse dat doge right here

  mpc_cleanup(4, Adjective, Noun, Phrase, Doge);

  return 0;
}
