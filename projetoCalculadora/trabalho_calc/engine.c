#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "engine.h"

// USAR
// indica que nao ha elementos
// suficientes para a operacao
void too_few_args() {
  puts("Too few arguments!");
}

// USAR
// indica que tentou dividir por
// zero
void division_by_zero() {
  puts("Division by zero!");
}

// USAR
// indica que o resultado da raiz
// quadrada seria um numero complexo
void complex_root() {
  puts("Complex root!");
}

// USAR
// indica que nao cabem mais numeros
// na pilha
void stack_full() {
  puts("Stack full!");
}

// USAR
// indica que a operacao solicitada
// nao eh uma das implementadas
void invalid_operation() {
  puts("Invalid operation!");
}

// considerando uma pilha assim:
//
// ...  :
// PROX :      a
// TOPO :      b
//--------------
// implementar as funcoes abaixo

// IMPLEMENTAR
// soma o TOPO e o PROX
void sum(Stack *s) {
	Elem x;
	Elem y;
	Elem z;

	 if(s -> depth>1){
	 	pop(s,&x);
	 	pop(s,&y);
	 		z=x+y;
			push(s,z);
	}else{
		too_few_args();
	}
	
}

// IMPLEMENTAR=
// subtrai o TOPO do PROX
void subtract(Stack *s) {
	Elem x;
	Elem y;
	Elem z;
	if(s -> depth>1){
	 	pop(s,&x);
	 	pop(s,&y);
	 		z=x-y;
			push(s,z);
	}else{
		too_few_args();
	}
  	
}

// IMPLEMENTAR
// multiplica o TOPO pelo PROX
void multiply(Stack *s) {
  	Elem x;
	Elem y;
	Elem z;
	 if(s -> depth>1){
	 	pop(s,&x);
	 	pop(s,&y);
	 		z=x*y;
			push(s,z);
	}else{
		too_few_args();
	}
}

// IMPLEMENTAR
// divide PROX pelo TOPO
void divide(Stack *s) {
  	Elem x;
	Elem y;
	Elem z;
	if(s -> depth>1){
	 		pop(s,&x);
	 		pop(s,&y);
	 	 	if(y!=0){
	 	 	z=x/y;
			push(s,z);	
		 }else{
		 	division_by_zero();	
	 		push(s,y);
	 		push(s,x);
		}
	}else{
		too_few_args();
	}
}

// IMPLEMENTAR
// limpa toda a pilha
void clear(Stack *s) {
	Elem x;
	if(s -> depth > 0){
	 
	while(s -> depth!=0){
		pop(s,&x);	
	}
}else{
		invalid_operation();
	}

}

// IMPLEMENTAR
// extrai a raiz quadrada do TOPO
void square_root(Stack *s) {
	Elem x;
	Elem z;
	 if(s -> depth>0){
	 	pop(s,&x);
	 		if(x<0){
	 			complex_root();
		 	}else{
		 
	 			z= sqrt(x);
				push(s,z);
			}
		}else{
			too_few_args();
	}
}

// IMPLEMENTAR
// coloca mais um numero na pilha
void number(Stack *s, Elem num) {
  push(s,num);
  	if(s -> depth == S_MAX){
  		stack_full(); 
  		}
}

// IMPLEMENTAR
// Imprime a pilha
void print(Stack s) { 

 int i;
 for(i = 0; i < S_MAX; i++) {
          if(i > s.depth) {
              printf(" :           \n");
          }
      }
      int j;
      for( j = 0; j < s.depth; j++) {
        printf("%d:           %.2f\n",j, s.vet[j]);
     }
    puts("------------------");
}

/****************************************************
 * N A O   M E X E R  D A Q U I   E M   D I A N T E *
 ****************************************************/

// erro de syntaxe
void syntax_error() {
  puts("Syntax error!");
}

// realiza uma operacao
void operate(Stack *s, Operation op) {
  if (op == QUIT) {
      puts("Good bye!");
      exit(0);
  }
  
  switch (op) {
    case SUM:
      sum(s);
      break;
    case SUBTRACT:
      subtract(s);
      break;
    case MULTIPLY:
      multiply(s);
      break;
    case DIVIDE:
      divide(s);
      break;
    case SQRT:
      square_root(s);
      break;
    case CLEAR:
      clear(s);
      break;
    default:
      invalid_operation();
      // fallthrough!
    case HELP:
      help();
      break;
  }
}

// atualiza a tela com o conteudo da pilha e
// um prompt para o usuário digitar algo
void update(Stack s) {
  print(s);
  printf("^: ");
}

// imprime as operacoes permitidas
void help() {
  const char **op_str = valid_ops();
  Operation op = INVALID_OP;
  puts("Operations:");
  for (op = 0; op < INVALID_OP; op++) {
    if (op > 0) printf(" , ");
    printf("%s", op_str[op]);
  }
  puts("");
}

// "limpa" a tela imprimindo 100 linhas em branco
void cls() {
	int i;
  for (i = 0; i < 100; i++)
    puts("");
}
