#ifndef __STACK_H__
#define __STACK_H__

//
int stack_length;


void stack_push(int elem);

//Fn. stack_pop
int stack_pop(void);

//Kontrollib, kas stack on tühi või mitte, tagastab 1 kui on tühi ja 0 kui ei ole tühi
int stack_isEmpty(void);

//tagastab kõige pealmise stack vaste
int stack_peek(void);

//Fn. prindi stack, mis prindib newlinile alustades esimesest elemendist.
int stack_print(void);

#endif