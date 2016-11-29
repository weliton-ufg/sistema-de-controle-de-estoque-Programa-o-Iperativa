char* menurPrincipal(){
    char opcao;
    printf("\n###############      MENUR PRINCIPAL      ################");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        F – Gerenciar Fornecedores                      #");
    printf("\n#        P – Gerenciar Produtos                          #");
    printf("\n#        I – Informações Gerenciais                      #");
    printf("\n#        S – Sair                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################\n");
   return opcao=getchar();
}
char* menurFornecedores(){
    char opcao;
    printf("\n#############     GESTÃO DE FORNECEDORES     #############");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        C – Cadastrar um fornecedor.                    #");
    printf("\n#        L – Listar todos os fornecedores cadastrados.   #");
    printf("\n#        B – Buscar fornecedor já cadastrado.            #");
    printf("\n#        A – Atualizar um fornecedor cadastrado.         #");
    printf("\n#        V - Voltar ao menur anterior.                   #");
    printf("\n#        S – Sair                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################\n");
    return opcao=getchar();
}

void mensagemFimPrograma(){
    printf("\n#######   OBRIGADO POR ULTILIZAR NOSSO SISTEMA    ########");
    printf("\n#######         AGUARDAREMOS SEU RETORNO          ########");
    printf("\n#######     PROGRAMA FINALIZADO COM SUCESSO       ########");
    printf("\n##########################################################\n");
}
