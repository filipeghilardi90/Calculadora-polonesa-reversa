#ifndef ENGINE_H
#define ENGINE_H
#include "stack.h"
#include "tokenizer.h"

// linhas da pilha mostradas
#define MAX_LINES 5

// avisa erro de sintaxe
void syntax_error();

// "limpa" a tela imprimindo 100 linhas em branco
void cls();

// coloca mais um numero na pilha
void number(Stack *s, Elem num);

// realiza uma operacao
void operate(Stack *s, Operation op);

// imprime as operacoes permitidas
void help();

// atualiza a tela com o conteúdo da pilha
void update(Stack s);

#endif