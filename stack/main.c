#include "stack.h"

int main(){
  Stack s;

  initStack(&s);
  push(&s, (Student){1, "jp", 'm', "bscs", 2001});
  push(&s, (Student){2, "idol", 'f', "bsit", 2003});
  pop(&s);
  display((Stack){ .data = {peek(s)}, .top = 0});
  visualize(s);
}
