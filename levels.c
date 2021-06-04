#define _GNU_SOURCE

#include "levels.h"
#include <strings.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER 30

static void desafio(char * str);
static void paraInvestigar(char * str);

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

int level3(FILE * socket_file,char ** buff, size_t size){ //aca hay que hacer lo del pipe
    desafio("EBADF..\n\nwrite: Bad file descriptor\n");
    paraInvestigar("¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"fk3wfLCm3QvS\n") == 0;
}

int level4(FILE * socket_file,char ** buff, size_t size){ //aca hay que hacer lo de strings
    desafio("respuesta = strings:277\n");
    paraInvestigar("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"too_easy\n") == 0;
}

int level5(FILE * socket_file,char ** buff, size_t size){
    desafio(".data .bss .comment ? .shstrtab .symtab .strtab\n");
    paraInvestigar("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,".RUN_ME\n") == 0;
}

int level6(FILE * socket_file,char ** buff, size_t size){ //este es el de filter error.. siempre se genera la misma salida? digo para el printf porque por ahi hay que printear la salida de error o algo asi directamente
    desafio("Filter error\n\n");
    paraInvestigar("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"K5n2UFfpFMUN\n") == 0;
}

int level7(FILE * socket_file,char ** buff, size_t size){ //este es el que la respuesta es .. esta como tapada en negro y tenes que seleccionar/cambiar el color de la terminal
    desafio("¿?\n\nLa respuesta es BUmyYq5XxXGt\n");
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

int level9(FILE * socket_file,char ** buff, size_t size){ //este es el de quine que creo que tecnicamente no tiene rta
    desafio("quine\n");
    paraInvestigar("¿Cuáles son las características del protocolo SCTP?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"chin_chu_lan_cha\n") == 0;
}

int level10(FILE * socket_file,char ** buff, size_t size){
    desafio("b gdbme y encontrá el valor mágico\n");
    paraInvestigar("¿Qué es un RFC?\n");
    if(getline(buff,&size,socket_file) == -1){
        return -1;
    }
    return strcmp(*buff,"gdb_rules\n") == 0;
}

int level11(FILE * socket_file,char ** buff, size_t size){ //revisar si los numeros devueltos son siempre los mismos
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
    printf("----- PREGUNTA PARA INVESTIGAR -----\n");
    printf("%s\n",str);
}