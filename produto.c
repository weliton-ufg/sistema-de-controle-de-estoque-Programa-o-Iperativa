#include <stdio.h>
#include <stdlib.h>
#include "fornecedor.c"
typedef struct{
    int codigo;
    char nome[100];
    char categoria[14];
    double valorUnitario;
    int quantidade;
    Fornecedor fornecedor;
}Produto;
