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
void listarrForncedores(){
  FILE *pont_arq;
  char linha[1024]; // variável do tipo string
  pont_arq = fopen("fornecedores.txt", "r");
  if(pont_arq == NULL)
  {
     printf("Erro na abertura do arquivo!");
     return 1;
  }
     while(fscanf(pont_arq, " %[^\n]s",linha)!=EOF){

        //strcpy(linha,"weliton;3232323;12");
        Fornecedor fornecedor;
        char *ptr;
        ptr=strtok(linha,";");
        fornecedor.codigo=atoi(ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.nome,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.cnpj,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.telefone,ptr);
        ptr=strtok(NULL,";");
        fornecedor.endereco.codigo=atoi(ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.cep,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.uf,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.cidade,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.bairro,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.logradouro,ptr);
        ptr=strtok(NULL,";");
        strcpy(fornecedor.endereco.complemento,ptr);
        ptr=strtok(NULL,";");

        printf("\nCódigo:%d ",fornecedor.codigo);
        printf("\nNome:%s ",fornecedor.nome);
        printf("\nTelefone:%s ",fornecedor.cnpj);
        printf("\nIdade:%s ",fornecedor.telefone);
        printf("\nEndereço");
        printf("\nCódigo:%d ",fornecedor.endereco.codigo);
        printf("\nCep:%s ",fornecedor.endereco.cep);
        printf("\nUf:%s ",fornecedor.endereco.uf);
        printf("\nCidade:%s ",fornecedor.endereco.cidade);
        printf("\nBairro:%s ",fornecedor.endereco.bairro);
        printf("\nLogradouro:%s ",fornecedor.endereco.logradouro);
        printf("\nComplemento:%s ",fornecedor.endereco.complemento);

        printf("\n");
    }
  fclose(pont_arq);
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

