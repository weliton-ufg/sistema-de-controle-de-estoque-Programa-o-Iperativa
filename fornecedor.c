#include "endereco.c"
typedef struct {
    int codigo;
    char nome[100];
    char cnpj[14];
    char telefone[14];
    Endereco endereco;
    struct Fornecedor *prox;
}Fornecedor;

Fornecedor *primeiroFornecedor;
Fornecedor *ultimoFornecedor;

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

void listarForncedores(){
  FILE *pont_arq;
  char linha[1024]; // variável do tipo string
  pont_arq = fopen("fornecedores.txt", "r");
  if(pont_arq == NULL)
  {
     printf("Erro na abertura do arquivo!");
     return 1;
  }
  criarListaVazia();
     while(fscanf(pont_arq, " %[^\n]s",linha)!=EOF){
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
        inseriNaLista(fornecedor);
    }
    imprimir();
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

void criarListaVazia(){
    primeiroFornecedor= (Fornecedor *)malloc(sizeof(Fornecedor));
    ultimoFornecedor=primeiroFornecedor;
}
void inseriNaLista(Fornecedor fornecedor){
    Fornecedor *fornecedorAux;
    fornecedorAux = (Fornecedor *)malloc(sizeof(Fornecedor));
    fornecedorAux->codigo =fornecedor.codigo;
    strcpy( fornecedorAux->nome,fornecedor.nome);
    strcpy( fornecedorAux->cnpj,fornecedor.cnpj);
    strcpy( fornecedorAux->telefone,fornecedor.telefone);
    fornecedorAux->endereco.codigo=fornecedor.endereco.codigo;
    strcpy( fornecedorAux->endereco.cep,fornecedor.endereco.cep);
    strcpy( fornecedorAux->endereco.uf,fornecedor.endereco.uf);
    strcpy( fornecedorAux->endereco.cidade,fornecedor.endereco.cidade);
    strcpy( fornecedorAux->endereco.bairro,fornecedor.endereco.bairro);
    strcpy( fornecedorAux->endereco.logradouro,fornecedor.endereco.logradouro);
    strcpy( fornecedorAux->endereco.complemento,fornecedor.endereco.complemento);
    ultimoFornecedor->prox=fornecedorAux;
    ultimoFornecedor=ultimoFornecedor->prox;
    fornecedorAux->prox=NULL;
}
void imprimir(){
    Fornecedor *fornecedorAux;
    fornecedorAux=primeiroFornecedor->prox;
    while(fornecedorAux!= NULL){
        printf("\nCódigo:%d ",fornecedorAux->codigo);
        printf("\nNome:%s ",fornecedorAux->nome);
        printf("\nTelefone:%s ",fornecedorAux->cnpj);
        printf("\nIdade:%s ",fornecedorAux->telefone);
        printf("\nEndereço");
        printf("\nCódigo:%d ",fornecedorAux->endereco.codigo);
        printf("\nCep:%s ",fornecedorAux->endereco.cep);
        printf("\nUf:%s ",fornecedorAux->endereco.uf);
        printf("\nCidade:%s ",fornecedorAux->endereco.cidade);
        printf("\nBairro:%s ",fornecedorAux->endereco.bairro);
        printf("\nLogradouro:%s ",fornecedorAux->endereco.logradouro);
        printf("\nComplemento:%s ",fornecedorAux->endereco.complemento);
        printf("\n");
        fornecedorAux=fornecedorAux->prox;
    }
}
