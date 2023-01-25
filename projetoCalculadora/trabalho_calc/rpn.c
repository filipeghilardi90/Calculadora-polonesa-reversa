#include "stack.h"
#include "tokenizer.h"
#include "engine.h"

// programa principal
int main() {
  Token tk;
  Stack s = new_stack();

  cls();
  operate(&s, HELP);
  update(s);
  for (;;) {
    tk = get_token();
    cls();
    switch (tk.t) {
      case OPERATION:
        operate(&s, tk.value.op);
        break;
      case NUMBER:
        number(&s,tk.value.num);
        break;
      default:
        syntax_error();
        break;
    }
    update(s);
  }
}