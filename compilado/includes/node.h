#ifndef NODE_H
#define NODE_H

//OBS.: chamei os nos de "node" nos comentarios pra evitar o uso de caracteres fora da tabela ASCII

typedef struct No {
    int dado;          //valor armazenado
    struct No* proximo; //ponteiro indicando o proximo valor 
} No;

#endif