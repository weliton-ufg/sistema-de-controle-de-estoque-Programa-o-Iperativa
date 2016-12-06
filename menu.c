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
char* menurCadastro(){
    char opcao;
    printf("\n#############           SUB MENUR            #############");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        C – COntinuar cadastrando.                      #");
    printf("\n#        V - Voltar ao menur anterior.                   #");
    printf("\n#        S – Sair                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################\n");
    return opcao=getchar();
}
char* menurProdutos(){
    char opcao;
    printf("\n#############       GESTÃO DE PRODUTOS       #############");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        C – Cadastrar um produto.                       #");
    printf("\n#        L – Listar todos os produtos cadastrados.       #");
    printf("\n#        B – Buscar produto já cadastrado.               #");
    printf("\n#        A – Atualizar um produto cadastrado.            #");
    printf("\n#        S – Atualizar estoque de um produto.            #");
    printf("\n#        E – Excluir um produto cadastrado.              #");
    printf("\n#        Z – Sair                                        #");
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
