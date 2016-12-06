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
                        printf("\n CÓDIGO:\n");
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
                        printf("\nDigite Qualquer Tecla Para Continuar\n");
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
                        printf("\n 2-BUSCAR POR CÓDIGO\n");
                        scanf("%d",&op);
                        if(op==1){
                            buscarFornecedor(1,0,NULL);
                        }if(op==2){
                            int codigo;
                            printf("\n CÓDIGO:\n");
                            scanf(" %i",&codigo);
                            buscarFornecedor(2,0,codigo);
                        }
                        fflush(stdin);
                        printf("\nDigite Qualquer Tecla Para Continuar\n");
                        char tecla2;
                        scanf("%c",&tecla2);
                        fflush(stdin);
                        system("cls");
                        goto VOLTARMENURFORNECEDORES;
                    break;
                    case 'a': case'A':
                        CODFA:
                        printf("\n CÓDIGO:\n");
                        int codFornecedor;
                        scanf(" %i",&codFornecedor);
                        if( buscarFornecedor(2,1,codFornecedor)==1){
                           salvarForncedorNoArquivo();
                           system("cls");
                        }else{
                             printf("\nFornecedor Não Encontrado! Tente Novamente\n");
                            goto CODFA;
                        }

                        cadastrarFornecedor(codigoFornecedor,0);
                        fflush(stdin);
                        printf("\nDigite Qualquer Tecla Para Continuar\n");
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
                                cadastrarProduto(cod,1,NULL);
                            }else{
                                printf("\nFornecedor Não Encontrado! Tente Novamente\n");
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
                            printf("\n2-ELETRÔNICOS");
                            printf("\n3-ELETRODOMESTICOS:");
                            printf("\n4-VESTUÁRIO:");
                            printf("\n5-TODOS:\n");
                            int categoria;
                            CATEGORIA:
                            scanf("%d",&categoria);
                            printf("\n%d",categoria);
                            buscarProdutos();
                            if(categoria==1){
                                ordernarProdutos("ALIMENTOS");
                            }else if(categoria==2){
                                ordernarProdutos("ELETRÔNICOS");
                            }else if(categoria==3){
                                ordernarProdutos("ELETRODOMESTICOS");
                            }else if(categoria==4){
                                ordernarProdutos("VESTUÁRIO");
                            }else if(categoria==5){
                                ordernarProdutos("TODOS");
                            }else{
                                printf("Opção inválida!");
                             goto CATEGORIA;
                            }
                            fflush(stdin);
                            printf("\nDigite Qualquer Tecla Para Continuar\n");
                            char tecla;
                            scanf("%c",&tecla);
                            fflush(stdin);
                            system("cls");
                            goto VOLTARMENURPRODUTOS;
                        break;
                        case 'b': case 'B':
                            fflush(stdin);
                            int op;
                            printf("\nBUSCAR PRODUTO\n");
                            printf("\n 1-BUSCAR POR NOME");
                            printf("\n 2-BUSCAR POR CÓDIGO\n");
                            scanf("%d",&op);
                            if(op==1){
                                buscarProduto(1,0,NULL);
                            }if(op==2){
                                int codigoP;
                                printf("\n CÓDIGO:\n");
                                scanf(" %i",&codigoP);
                                buscarProduto(2,0,codigoP);
                            }
                            fflush(stdin);
                            printf("\nDigite Qualquer Tecla Para Continuar\n");
                            char tecla4;
                            scanf("%c",&tecla4);
                            fflush(stdin);
                            system("cls");
                            goto VOLTARMENURPRODUTOS;
                            break;
                        case 'e': case'E':
                            fflush(stdin);
                            int codPexc;
                            printf("\nEXCLUIR PRODUTO\n");
                            int codigoP;
                            CODP:
                            printf("\nCÓDIGO:\n");
                            scanf(" %i",&codigoP);
                            if(buscarProduto(2,1,codigoP)==1){
                                printf("\nEXCLUIDO COM SUCESSO!\n");
                                salvarProdutoNoArquivo();
                            }else{
                                printf("\nProduto Não Encontrado");
                                printf("\nTente Com Outro Código!\n");
                                goto CODP;
                            }

                            fflush(stdin);
                            printf("\nDigite Qualquer Tecla Para Continuar\n");
                            char tecla5;
                            scanf("%c",&tecla5);
                            fflush(stdin);
                            system("cls");
                            goto VOLTARMENURPRODUTOS;
                            break;

                        break;
                        case 'a': case'A':
                            CODP1:
                            printf("\n CÓDIGO:\n");
                            int codProduto;
                            scanf(" %i",&codProduto);
                            if(buscarProduto(2,1,codProduto)==1){
                                CODF1:
                                printf("\nCodigo Do Fornecedor:");
                                scanf("%d",&cod);
                                if(buscarFornecedor(2,0,cod)==1){
                                    salvarProdutoNoArquivo();
                                    system("cls");
                                     cadastrarProduto(cod,0,codProduto);
                                }else{
                                    printf("\nFornecedor Não Encontrado! Tente Novamente\n");
                                    goto CODF1;
                                }
                            }else{
                                 printf("\nProduto Não Encontrado! Tente Novamente\n");
                                 goto CODP1;
                            }

                            fflush(stdin);
                            printf("\nDigite Qualquer Tecla Para Continuar\n");
                            char tecla3;
                            scanf("%c",&tecla3);
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
