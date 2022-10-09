#include <stdio.h>
#include <stdlib.h>

//kasutame stack.h failis olevaid fn. deklaratsioone
#include "stack.h"


int main(int argc, char const *argv[]){
    int sisend;
    while(1){
        //rintf("palun sisesta 0, et printida stack");

        scanf("%d", &sisend);

        if (sisend !=0 ){
            if (stack_length==0){//kontrollib, et kas stack on tühi või mitte ja lisab selle väärtuse sinna
                stack_push(sisend);
            }
            else if (sisend > 0){
                if (stack_peek>0){
                    stack_push(sisend);
                }
                if (stack_peek<0){
                    int temp_int = stack_pop();
                    int result = sisend+temp_int;
                    stack_push(result);
                }
            }
            else if(sisend < 0){
                int temp_int = stack_pop();
                int result = sisend+temp_int;
                stack_push(result);
            }            
        }else{ //ss kui sisendiks on 0
            stack_print();
            break;
        }        

        //printf("%d\n", sisend); //seda pole selle ül. jaoks vaja.
    }
}