#include "endereco.c"
typedef struct{
    int codigo;
    char nome[100];
    char cnpj[14];
    char telefone[14];
    Endereco endereco;
}Fornecedor;

void cadastrarFornecedor(){
    Fornecedor fornecedor;
    printf("\nFORNECEDOR:");
    printf("\nCódigo:");
    scanf(" %d",&fornecedor.codigo);
    printf("\nNome:");
    scanf(" %[^\n]s",fornecedor.nome);
    printf("\nCnpj:");
    scanf(" %[^\n]s",fornecedor.cnpj);
    printf("\nTelefone:");
    scanf(" %[^\n]s",fornecedor.telefone);

    printf("\nENDEREÇO:");
    printf("\nCódigo:");
    scanf(" %d",&fornecedor.endereco.codigo);
    printf("\nCep:");
    scanf(" %[^\n]s",fornecedor.endereco.cep);
    printf("\nUf:");
    scanf(" %[^\n]s",fornecedor.endereco.uf);
    printf("\nCidade:");
    scanf(" %[^\n]s",fornecedor.endereco.cidade);
    printf("\nBairro:");
    scanf(" %[^\n]s",fornecedor.endereco.bairro);
    printf("\nLogradouro:");
    scanf(" %[^\n]s",fornecedor.endereco.logradouro);
    printf("\nComplemento:");
    scanf(" %[^\n]s",fornecedor.endereco.complemento);
    salvarForncedorNoArquivo(fornecedor);
}
void salvarForncedorNoArquivo(Fornecedor fornecedor){
    FILE *pont_arq; // cria variável ponteiro para o arquivo

    pont_arq = fopen("fornecedores.txt", "a");

  //testando se o arquivo foi realmente criado
    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    fprintf(pont_arq, "%d;%s;%s;%s;%d;%s;%s;%s;%s;%s;%s\n",fornecedor.codigo,fornecedor.nome,fornecedor.cnpj,fornecedor.telefone,
            fornecedor.endereco.codigo,fornecedor.endereco.cep,fornecedor.endereco.uf,fornecedor.endereco.cidade,fornecedor.endereco.bairro,
            fornecedor.endereco.logradouro,fornecedor.endereco.complemento);
    fclose(pont_arq);
    printf("Dados gravados com sucesso!\n");
}
