#include <stdio.h>
#include <stdlib.h>

/*Glob stack fix. pikkus*/
#define STACK_SIZE 100

/*Glob stack pikkus*/
int stack_length = 0;

/*Globaalne stack ise*/
int stack[STACK_SIZE];

/*Fn. push ehk me lisame stacki antud elemendi*/
void stack_push(int elem){
    /*kontrollme, kas pinus on ruumi, või mitte*/
    if (stack_length >= STACK_SIZE)
    {
        printf("Error: No more space in stack");
        return;
    }

    //teame, et pinus on ruumi, siis me jõuame siia.
    stack[stack_length] = elem;
    stack_length++;

    return;
}

//Fn. stack_pop
int stack_pop(void){
    //kontrollime, kas pinus on veel elemente
    if (stack_length == 0)
    {
        return 0;
    }

    //teame, et pinus on element olemas, siis eemaldame selle listist
    int eemaldatav_element = stack[stack_length -1];
    stack_length--;

    return eemaldatav_element;
    
}

int stack_isEmpty(void){
    return stack_length == 0;
    //return !(stack_length < 0);ff
}

//tagastab kõige pealmise stack vaste
int stack_peek(void){
    if (stack_length == 0)   
    {
        return 0;
    }
    return stack[stack_length-1];
}

//Fn. prindi stack, mis prindib newlinile alustades esimesest elemendist.
int stack_print(void){
    int i = stack_length -1;
    while(i>=0){
        printf("%d\n", stack[i]);
        i--;
    }
}