#define _GNU_SOURCE

#include "levels.h"
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_BUFFER 30
#define PI 3.141592653589793

#define BLACK_T "\x1b[30m"
#define BLACK_F "\x1b[40m"
#define RESET_COLOR "\x1b[0m"

static void desafio(char * str);
static void paraInvestigar(char * str);

char too_easy = 1;

__attribute__((section(".RUN_ME")))

int level0(FILE * socket_file,char ** buff, size_t size){
    printf(
        "Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
        "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel."
        "Además tendrán que investigar otras preguntas para responder durante la defensa."
        "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos"
        " y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta."
        "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
        "Deberán estar atentos a los easter eggs.\n\n"
        "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n");
    paraInvestigar("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"entendido\n") == 0;
}

int level1(FILE * socket_file,char ** buff, size_t size){
    desafio(
        "The Wire S1E5\n"
        "5295 888 6288\n");
    paraInvestigar("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");
    if(getline(buff,&size,socket_file)==-1){
        return -1;
    }
    return strcmp(*buff,"itba\n") == 0;
}

int level2(FILE * socket_file,char ** buff, size_t size){
    desafio("https://ibb.co/tc0Hb6w\n");
    paraInvestigar("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"M4GFKZ289aku\n") == 0;
}

int level3(FILE * socket_file,char ** buff, size_t size){ 
    desafio("EBADF..\n");

    if( write(13,"fk3wfLCm3QvS",strlen("fk3wfLCm3QvS")) == -1){ 
        perror("write");
    }
    
    paraInvestigar("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"fk3wfLCm3QvS\n") == 0;
}

int level4(FILE * socket_file,char ** buff, size_t size){
    desafio("respuesta = strings:459\n");
    paraInvestigar("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");
    if(too_easy);
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"too_easy\n") == 0;
}

int level5(FILE * socket_file,char ** buff, size_t size){
    desafio(".init .text ? .fini .rodata\n");
    paraInvestigar("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n");
    
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,".RUN_ME\n") == 0;
}

int level6(FILE * socket_file,char ** buff, size_t size){ 
    desafio("Filter error\n\n");
    char aux[30];
    srand(time(NULL));
    int i,r;
    for(i=0 ; i<30 ; i++){
        r = (rand() % 126);
        aux[i] = r + '0';
    }
    aux[i-1]=0;
    write(2,aux,strlen(aux));
    write(1,"K5n2UFfpFMUN",9);
    paraInvestigar("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"K5n2UFfpFMUN\n") == 0;
}

int level7(FILE * socket_file,char ** buff, size_t size){ 
    desafio("¿?\n");
    printf(BLACK_T BLACK_F "La respuesta es BUmyYq5XxXGt" RESET_COLOR "\n");
    paraInvestigar("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"BUmyYq5XxXGt\n") == 0;
}

int level8(FILE * socket_file,char ** buff, size_t size){
    desafio("Latexme\n\nSi\n\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\nentonces\ny = \n");
    paraInvestigar("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"u^v\n") == 0;
}

int level9(FILE * socket_file,char ** buff, size_t size){ 
    desafio("quine\n");
    int res = system("gcc quine.c -o quine");
    if(!res){ //existe el archivo quine
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
        if((res = system("./quine | diff - quine.c")) == 0){
            printf("La respuesta es chin_chu_lan_cha\n");
        }else{
            printf("diff encontró diferencias.\n");
        }
    }
    if(res){ //diff retornó 1
        printf("ENTER para reintentar.\n");
    }
    paraInvestigar("¿Cuáles son las características del protocolo SCTP?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"chin_chu_lan_cha\n") == 0;
}

void gdbme(){
    if(getpid()==4194305){
        printf("gdb_rules\n");
    }
}

int level10(FILE * socket_file,char ** buff, size_t size){
    desafio("b gdbme y encontrá el valor mágico\n\n");
    printf("ENTER para reintentar.\n\n");
    paraInvestigar("¿Qué es un RFC?\n");
    gdbme();
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"gdb_rules\n") == 0;
}

void normal(){
    srand(time(NULL));
    double x,y;
    for(int i=0; i< 400 ;i++){
        x = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        y = (double)rand() / (double)((unsigned)RAND_MAX + 1);
        printf("%.6f ",(sqrt(-2 * log(x)) * cos(2 * M_PI * y)));
    }
}


int level11(FILE * socket_file,char ** buff, size_t size){
    desafio("Me conoces\n");
    normal();
    paraInvestigar("¿Fue divertido?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"normal\n") == 0;
}

static void desafio(char * str){
    printf("------------- DESAFIO -------------\n");
    printf("%s\n",str);
}

static void paraInvestigar(char * str){
    printf("\n----- PREGUNTA PARA INVESTIGAR -----\n");
    printf("%s\n",str);
}