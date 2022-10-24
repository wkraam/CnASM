#include <stdio.h>
#include <stdlib.h>
#include "mem.h"
#include "stack.h"

enum instructions_e {
    /* Liiguta mälu indeksit paremale. */
    BF_RIGHT      = '>',

    /* Liiguta mälu indeksit vasakule. */
    BF_LEFT       = '<',

    /* Suurenda mälu indeksil olevat väärtust. */
    BF_INCREASE   = '+',

    /* Vähenda mälu indeksil olevat väärtust. */
    BF_DECREASE   = '-',

    /* Loe kasutajalt sisendit ja salvesta see mäluindeksile. */
    BF_READ       = ',',

    /* Trüki välja mälu indeksil olev väärtus char'ina. */
    BF_PRINT      = '.',

    /* Tsükli algus. */
    BF_START_LOOP = '[',

    /* Tsükli lõpp. */
    BF_END_LOOP   = ']',

    /* Trüki silumise informatsioon. */
    BF_DEBUG      = '#'
};

int loopInterpreter(char *input){
    printf("Jõudsime loopi sisse\n");
    int l = 0;
    int returnValue = input[0];

    while((int)input[l]!=0){
        switch (input[l]) {
            case BF_START_LOOP: {
                if (mem_get() != 0) { // täidame tsükli sisu
                    int loopEnd = l;
                    //leiame loopi pikkuse ja indeksid, millega me saadame listi, mis on nende indeksite vahedega
                    while (input[loopEnd] != BF_END_LOOP)//liigume edasi kuniks leiame ']' characteri ehk BF_END_LOOP ja liigutame endaga indexit kaasa.
                    {
                        loopEnd++;
                        printf("uue loopi uus loopEnd index on %i\n", loopEnd);
                    }
                    int vahe = loopEnd-l;
                    char loop[vahe];// array, mis läheb loopima, et vasteks saaks char väärtuse, mis saab olema vastuses.

                    for (size_t k = 0; k < vahe-1; k++) // Sisestame i kohal olevad elemendid uude loopi
                    {
                        l++;//me ei taha loopi saata '[' elementi
                        loop[k] = input[l];
                    }

                    //saadame uue loopi uude interpreterisse,!!! ilma loopi märkideta !!!, ning saame tagasi int elemendi, mille me pushime stacki.
                    loopInterpreter(loop);
                    
                } else {
                    //printf("läksin programmis otsima lõppu, sest mäluväärtus on 0\n");
                    while (input[l] != BF_END_LOOP)//liigume edasi kuniks leiame ']' characteri ehk BF_END_LOOP ja liigutame endaga indexit kaasa.
                    {
                        l++;
                        printf("l uus index on %i\n", l);
                    }
                    break;
                }
                break;
            }
            case BF_END_LOOP: {
                if (mem_get() != 0) {
                    l = stack_pop();
                    break;
                }
                break;
            }
            case BF_INCREASE:
                mem_inc();
                break;
            case BF_DECREASE:
                mem_dec();
                break;
            case BF_RIGHT:
                mem_right();
                break;
            case BF_LEFT:
                mem_left();
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_READ: {
                /* Loeme märgi standardsisendist (kasutaja sisestab konsooli). */
                int c = getc(stdin);
                if (EOF == c) {
                    /* Sisendi lõpu korral lõpetame interpretaatori töö. */
                    printf("Sisendi lõpp!\n");
                    continue;
                }

                /* Lisame mällu loetud väärtuse. */
                mem_set((char) c);
                break;
            }
            case BF_PRINT: {
                char c = mem_get();
                printf("%c", c);
                break;
            }
            default:;
                /* Ignoreerime sümboleid, mida me ei tunne. */
                break;
        }
        l++;
    }

    return returnValue;
}

void interpret(char *program) {
    int i = 0;

    while ((int)program[i] != 0 ) {
        switch (program[i]) {
            case BF_START_LOOP: {
                //kui mem_get() !=0 siis tuleb tsükli sisu täita
                //kui mem_get() == 0 siis tuleb otsida BF_END_LOOP char ja sellest edasi liikuda
                if (mem_get() != 0) { // täidame tsükli sisu - but how?
                    int loopEnd = i;

                    //leiame loopi pikkuse ja indeksid, millega me saadame listi, mis on nende indeksite vahedega
                    while (program[loopEnd] != BF_END_LOOP)//liigume edasi kuniks leiame ']' characteri ehk BF_END_LOOP ja liigutame endaga indexit kaasa.
                    {
                        loopEnd++;
                        printf("loopEnd uus index on %i\n", loopEnd);
                    }
                    int vahe = loopEnd-i;
                    char loop[vahe];// array, mis läheb loopima, et vasteks saaks char väärtuse, mis saab olema vastuses.

                    //printf("loopi lisame: "); //***debug***//
                    for (size_t j = 0; j < vahe-1; j++) // Sisestame i kohal olevad elemendid uude loopi
                    {
                        i++;//me ei taha loopi saata '[' elementi
                        loop[j] = program[i];
                        //printf("%c", program[i]); //***debug***//
                    }
                    //printf("\n"); //***debug***//

                    //saadame uue loopi uude interpreterisse,!!! ilma loopi märkideta !!!, ning saame tagasi int elemendi, mille me pushime stacki.
                    loopInterpreter(loop);
                    printf("hetke char kohal i on: %c ja indeks on: %i\n", program[i], i);

                    break;
                    
                } else {
                    //printf("läksin programmis otsima lõppu, sest mäluväärtus on 0\n");
                    while (program[i] != BF_END_LOOP)//liigume edasi kuniks leiame ']' characteri ehk BF_END_LOOP ja liigutame endaga indexit kaasa.
                    {
                        i++;
                        printf("i uus index on %i\n", i);
                    }
                    break;
                }
                break;
            }
            case BF_END_LOOP: {
                if (mem_get() != 0) {
                    i = stack_pop();
                    break;
                }
                break;
            }
            case BF_INCREASE:
                mem_inc();
                break;
            case BF_DECREASE:
                mem_dec();
                break;
            case BF_RIGHT:
                mem_right();
                break;
            case BF_LEFT:
                mem_left();
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_READ: {
                /* Loeme märgi standardsisendist (kasutaja sisestab konsooli). */
                int c = getc(stdin);
                if (EOF == c) {
                    /* Sisendi lõpu korral lõpetame interpretaatori töö. */
                    printf("Sisendi lõpp!\n");
                    continue;
                }

                /* Lisame mällu loetud väärtuse. */
                mem_set((char) c);
                break;
            }
            case BF_PRINT: {
                char c = mem_get();
                printf("%c", c);
                break;
            }
            default:;
                printf("ignon elementi");
                /* Ignoreerime sümboleid, mida me ei tunne. */
                break;
        }

        i++;
        printf("kas järgmine loop indeksiga %i läheb while loopist läbi?: %i\n",i , program[i]!=0);
        //printf("%c ... %i\n",program[i]);
        if ((int)program[i] == 0) break;
    }

    printf("----------------------kõik-------------------------\n");
}

int main(int argc, char **argv) {
    /* Kontrollime, et programmile anti täpselt üks parameeter (lisaks programmi nimele endale). */
    if (argc != 2) {
        printf("Programmil peab olema üks parameeter, milleks on BF programm!\n");

        /* Tagastame veakoodi. */
        return 1;
    }

    /* Käivitame programmi, mille kasutaja andis käsurealt. */
    interpret(argv[1]);

    return 0;
}