#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include "fornecedor.c"
#include "menu.c"
int main(){
    setlocale(LC_ALL, "Portuguese");
    while(1){
        char opcao;
        VOLTARMENURPRINCIPAL:
        opcao=menurPrincipal();
        fflush(stdin);
        switch(opcao){
            case 'f': case'F':
                system("cls");
                VOLTARMENURFORNECEDORES:
                opcao=menurFornecedores();
                fflush(stdin);
                switch(opcao){
                    case 'c': case'C':
                        CADASTRARFORNECEDOR:
                        cadastrarFornecedor();
                        fflush(stdin);
                        opcao=menurCadastro();
                        fflush(stdin);
                        switch(opcao){
                            case 'c': case'C':
                                system("cls");
                                goto CADASTRARFORNECEDOR;
                            break;
                            case 'v': case'V':
                                system("cls");
                                goto VOLTARMENURFORNECEDORES;
                            break;

                        }
                    break;
                    case 'l': case'L':
                    break;
                    case 'b': case'B':
                    break;
                    case 'a': case'A':
                    break;
                    case 'v': case'V':
                        system("cls");
                        goto VOLTARMENURPRINCIPAL;
                    break;
                    case 's': case'S':
                        mensagemFimPrograma();
                        exit(0);
                    break;
                }
            break;
            case 'p': case'P':
            break;
            case 'i': case'I':
            break;
            case 's': case'S':
                mensagemFimPrograma();
                exit(0);
            break;
        }

    }
    return 0;
}
