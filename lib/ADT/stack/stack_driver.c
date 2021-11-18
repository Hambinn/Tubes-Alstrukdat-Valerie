#include "../../../app/readfile.c"
#include <stdio.h>

ListLinked copyBag(Stack bag) {
    ListLinked l;
    CreateListLinked(&l);
    int i;
    for(i = 0; i < LEN_STACK(bag); i++){
        insertItemFirst(&l,bag.buffer[i]);
    }
    return l;
}

int main() {
    Item x = makeItem(10, 'A', 'Z', 'N', -1);
    ListLinked l;
    CreateListLinked(&l);

    Stack s;
    CreateStack(&s);
    push(&s, x);
    x = makeItem(69, 'B', 'Y', 'H', -1);
    push(&s, x);
    l = copyBag(s);
    displayListLinked(l);
}