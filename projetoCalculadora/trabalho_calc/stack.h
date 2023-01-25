#ifndef STACK_H
#define STACK_H

// tamanho maximo da pilha
#define S_MAX 10

// tipo dos elementos armazenados
typedef double Elem;

// definicao da pilha
typedef struct {
  unsigned int depth;
  Elem vet[S_MAX];
} Stack;

// cria uma nova pilha
Stack new_stack();

// coloca um elemento no topo
int push(Stack *s, Elem e);

// remove um elemento do topo
int pop(Stack *s, Elem *e);

#endif