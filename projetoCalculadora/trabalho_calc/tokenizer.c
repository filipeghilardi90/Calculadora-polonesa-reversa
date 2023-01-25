#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

// comandos validos
const char* op_str[INVALID_OP] = {
  "+",
  "-",
  "*",
  "/",
  "clear",
  "help",
  "quit",
  "sqrt"
};

// retorna os comandos validos
const char **valid_ops() {
  return op_str;
}

// retorna o codigo da operacao
Operation get_op(char *buffer) {
  Operation op = INVALID_OP;

  for (op = 0; op < INVALID_OP; op++) {
    if (!strncmp(buffer, op_str[op], TK_MAX))
      return op;
  }
  return op;
}

// le um token do teclado
Token get_token() {
  Token tk;
  char buffer[TK_MAX];

  if (scanf("%255s", buffer) != 1) {
    tk.t = INVALID;
  } else if (sscanf(buffer, "%lf", &tk.value.num) == 1) {
    tk.t = NUMBER;
  } else {
    tk.t = OPERATION;
    tk.value.op = get_op(buffer);
  }
  return tk;
}