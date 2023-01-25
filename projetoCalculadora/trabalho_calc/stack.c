#include "stack.h"

// cria uma nova pilha
Stack new_stack() {
  Stack s;
  s.depth = 0;
  return s;
}

// coloca um elemento no topo
int push(Stack *s, Elem e) {
  if (s->depth >= S_MAX)
    return 0;

  s->vet[s->depth] = e;
  s->depth++;
  return s->depth;
}

// remove um elemento do topo
int pop(Stack *s, Elem *e) {
  if (s->depth <= 0) return 0;

  *e = s->vet[s->depth-1];
  return s->depth--;
}