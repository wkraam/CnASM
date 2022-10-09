#include <stdio.h>

#define MEM_LENGTH 30000

char mem_arr[MEM_LENGTH];
int curr_elem_index = 0;

void initialize(){
    int i = 0;
    while (i < MEM_LENGTH){
        mem_arr[i] = 0;
        i++;
    };
}

/*suurendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue 
väärtuse.*/
int mem_inc(){ return mem_arr[curr_elem_index] += 1; };

/*vähendab indeksiga viidatud massiivi elemendi väärtust ühe võrra. Tagastab uue 
väärtuse.*/
int mem_dec(){ return mem_arr[curr_elem_index] -= 1; };

/*liigutab indeksit vasakule (vähendab selle väärtust ühe võrra). Kui indeks muutub 
negatiivseks, siis liiguta see massiivi lõppu. Tagastab indeksi uue väärtuse.*/
int mem_left(){
    if ((curr_elem_index - 1) < 0){
        return curr_elem_index = MEM_LENGTH - 1;         
    } 
    return curr_elem_index -= 1;
};

/*liigutab indeksit paremale (suurendab selle väärtust ühe võrra). Kui indeks läheb 
üle massiivi piiri, siis liiguta indeks massiivi algusesse. Tagastab indeksi uue 
väärtuse.*/
int mem_right(){
    /*
    if ((curr_elem_index + 1) == MEM_LENGTH){
        return curr_elem_index = 0;         
    }*/ 
    return curr_elem_index += 1;
};

//tagastab antud indeksil oleva väärtuse.
int mem_get(){ return mem_arr[curr_elem_index]; };

//salvestab väärtuse antud indeksile ja tagastab selle 
//väärtuse.
int mem_set(char v){ return mem_arr[curr_elem_index] = v; };


//trükib välja indeksi väärtuse, mälu väärtuse sellel indeksil ja sellele järgnevad 
//9 väärtust (kui massiivi piir tuleb ette, siis liigu tagasi algusesse). 
//Formaadi näidis: index: 10 mem [10 .. 19]: 7 6 10 -12 55 22 0 0 0 0
void mem_printDebug(){
    printf("index: %d mem [%d .. %d]: %d", curr_elem_index, curr_elem_index,
    (curr_elem_index + 9), mem_get());
    int i;
    for (i = 0; i < 9; i++){
        mem_right();
        printf(" %d", mem_get());
    }
    for (i = 9; i > 0; i--){
        mem_left();
    }
    
    printf("\n");
};
