#ifndef TOKENIZER_H
#define TOKENIZER_H
#include "stack.h"

// tamanho maximo em caracteres de um token
#define TK_MAX 255

// codigos das operacoes
typedef enum {
  SUM,
  SUBTRACT,
  MULTIPLY,
  DIVIDE,
  CLEAR,
  HELP,
  QUIT,
  SQRT,
  INVALID_OP
} Operation;

// tipos de tokens
typedef enum {
  OPERATION,
  NUMBER,
  INVALID
} Type;

// definicao de um token
typedef struct {
  Type t;
  union {
    Operation op;
    Elem num;
  } value;
} Token;

// le um token do teclado
Token get_token();

// retorna os comandos validos
const char **valid_ops();

#endif