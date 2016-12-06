#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
#include "fornecedor.c"
#include "menu.c"
#include "produto.c"
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
                        buscarFornecedores();
                        printf("\n C�DIGO:\n");
                        int codigoFornecedor;
                        scanf(" %i",&codigoFornecedor);
                        cadastrarFornecedor(codigoFornecedor,1);
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
                        fflush(stdin);
                        buscarFornecedores();
                        listarForncedores();
                        printf("\nDigite qualquer tecla para continuar\n");
                        char tecla;
                        scanf("%c",&tecla);
                        fflush(stdin);
                        system("cls");
                        goto VOLTARMENURFORNECEDORES;
                    break;
                    case 'b': case'B':
                        fflush(stdin);
                        int op;
                        printf("\nBUSCAR FORNECEDOR\n");
                        printf("\n 1-BUSCAR POR NOME");
                        printf("\n 2-BUSCAR POR C�DIGO\n");
                        scanf("%d",&op);
                        if(op==1){
                            buscarFornecedor(1,0,NULL);
                        }if(op==2){
                            int codigo;
                            printf("\n C�DIGO:\n");
                            scanf(" %i",&codigo);
                            buscarFornecedor(2,0,codigo);
                        }
                        fflush(stdin);
                        printf("\nDigite qualquer tecla para continuar\n");
                        char tecla2;
                        scanf("%c",&tecla2);
                        fflush(stdin);
                        system("cls");
                        goto VOLTARMENURFORNECEDORES;
                    break;
                    case 'a': case'A':

                        printf("\n C�DIGO:\n");
                        int codFornecedor;
                        scanf(" %i",&codFornecedor);
                        buscarFornecedor(2,1,codFornecedor);
                        cadastrarFornecedor(codigoFornecedor,0);
                        fflush(stdin);
                        printf("\nDigite qualquer tecla para continuar\n");
                        char tecla3;
                        scanf("%c",&tecla3);
                        fflush(stdin);
                        system("cls");
                        goto VOLTARMENURFORNECEDORES;
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
                system("cls");
                VOLTARMENURPRODUTOS:
                opcao=menurProdutos();
                fflush(stdin);
                switch(opcao){
                        case 'c': case'C':
                            CADASTRARPRODUTO:
                            buscarProdutos();
                            int codF,cod;
                            system("cls");
                            CODF:
                            printf("\nCodigo Do Fornecedor:");
                            scanf("%d",&cod);
                            codF=buscarFornecedor(2,0,cod);
                            if(codF==1){
                                cadastrarProduto(cod);
                            }else{
                                printf("\nFornecedor N�o encontrado! Tente Novamente\n");
                                goto CODF;
                            }

                            fflush(stdin);
                            opcao=menurCadastro();
                            fflush(stdin);
                            switch(opcao){
                                case 'c': case'C':
                                    system("cls");
                                    goto CADASTRARPRODUTO;
                                break;
                                case 'v': case'V':
                                    system("cls");
                                    goto VOLTARMENURPRODUTOS;
                                break;

                            }
                        break;
                        case 'v': case'V':
                            system("cls");
                            goto VOLTARMENURPRINCIPAL;
                        break;
                        case 'l': case'L':
                            fflush(stdin);
                            printf("\nESCOLHA UMA CATEGORIA:");
                            printf("\n1-ALIMENTOS");
                            printf("\n2-ELETR�NICOS");
                            printf("\n3-ELETRODOMESTICOS:");
                            printf("\n4-VESTU�RIO:");
                            printf("\n5-TODOS:\n");
                            int categoria;
                            CATEGORIA:
                            scanf("%d",&categoria);
                            printf("\n%d",categoria);
                            buscarProdutos();
                            if(categoria==1){
                                ordernarProdutos("ALIMENTOS");
                            }else if(categoria==2){
                                ordernarProdutos("ELETR�NICOS");
                            }else if(categoria==3){
                                ordernarProdutos("ELETRODOMESTICOS");
                            }else if(categoria==4){
                                ordernarProdutos("VESTU�RIO");
                            }else if(categoria==5){
                                ordernarProdutos("TODOS");
                            }else{
                                printf("Op��o inv�lida!");
                             goto CATEGORIA;
                            }
                            fflush(stdin);
                            printf("\nDigite qualquer tecla para continuar\n");
                            char tecla;
                            scanf("%c",&tecla);
                            fflush(stdin);
                            system("cls");
                            goto VOLTARMENURPRODUTOS;
                        break;
                        case 'z': case'Z':
                            mensagemFimPrograma();
                        exit(0);
                    break;

                    }

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
