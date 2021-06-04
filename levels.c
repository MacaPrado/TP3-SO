#include "levels.h"
#include <strings.h>
#include <unistd.h>

#define MAX_BUFFER 30

int level0(int sockfd){
    printf("------------- DESAFIO -------------\nBienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\nEn este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\nAdemás tendrán que investigar otras preguntas para responder durante la defensa.\nEl desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n\nAdemás, deberán implementar otro programa para comunicarse conmigo.\n\nDeberán estar atentos a los easter eggs.\n\n");
    printf("Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'");
    char buff[MAX_BUFFER];
    int ans = 0;
    for(;;){
        memset(buff,0,MAX_BUFFER);
        read(sockfd,buff,sizeof(buff));
        printf("buffer: %s\n",buff);
        if(strcmp(buff,"entendido")==0) {
            return 0;
        }else{
            printf("Respuesta incorrecta: %s",buff);
        }
    }
    return 0;
}
/*
int level1(int sockfd){

}

int level2(){
    
}

int level3(){
    
}

int level4(){
    
}

int level5(){
    
}

int level6(){
    
}

int level7(){
    
}

int level8(){
    
}

int level9(){
    
}

int level10(){
    
}
*/


