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
int tamanho;
//flagOp 0=atualizar
void cadastrarFornecedor(int cod ,int flagOp){
    Fornecedor fornecedor;
    int flagPedCod=0;
    printf("\nFORNECEDOR:");
    COD:
    if(flagPedCod==1){
        printf("\n\nCódigo:");
        scanf(" %d",&fornecedor.codigo);
        cod=fornecedor.codigo;
    }
    if(flagOp==0){
        printf("\n\nCódigo:");
        scanf(" %d",&fornecedor.codigo);

        if(buscarFornecedor(2,0,fornecedor.codigo)==1 && fornecedor.codigo!=cod){
            printf("\nCódigo Já Cadastrado!Tente outro Código");
            goto COD;
        }
    }else{
        if(buscarFornecedor(2,0,cod)==1){
            printf("\nCódigo Já Cadastrado!Tente outro Código");
            flagPedCod=1;
            goto COD;
        }
    }
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
    printf("Teste %s",fornecedor.endereco.bairro);
    printf("\nLogradouro:");
    scanf(" %[^\n]s",fornecedor.endereco.logradouro);
    printf("\nComplemento:");
    scanf(" %[^\n]s",fornecedor.endereco.complemento);
    inseriNaLista(fornecedor);
    salvarForncedorNoArquivo();
}

int buscarFornecedores(){
  FILE *pont_arq;
  char linha[1024]; // variável do tipo string
  pont_arq = fopen("fornecedores.txt", "r");
  if(pont_arq == NULL)
  {
     printf("Erro na abertura do arquivo!");
     return 1;
  }
  tamanho=0;
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
        tamanho++;
        inseriNaLista(fornecedor);
    }
  fclose(pont_arq);
}

void salvarForncedorNoArquivo(){
    FILE *pont_arq; // cria variável ponteiro para o arquivo
    Fornecedor *fornecedorAux;
    fornecedorAux=primeiroFornecedor->prox;
    pont_arq = fopen("fornecedores.txt", "w");

  //testando se o arquivo foi realmente criado
    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
     while(fornecedorAux!= NULL){
        fprintf(pont_arq, "%d;%s;%s;%s;%d;%s;%s;%s;%s;%s;%s\n",fornecedorAux->codigo,fornecedorAux->nome,fornecedorAux->cnpj,fornecedorAux->telefone,
            fornecedorAux->endereco.codigo,fornecedorAux->endereco.cep,fornecedorAux->endereco.uf,fornecedorAux->endereco.cidade,fornecedorAux->endereco.bairro,
            fornecedorAux->endereco.logradouro,fornecedorAux->endereco.complemento);

       fornecedorAux=fornecedorAux->prox;
     }
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

void listarForncedores(){
    orndernar();
}
void orndernar(){

    Fornecedor listaOrdenada[tamanho];
    Fornecedor *fornecedorAux;
    fornecedorAux=primeiroFornecedor->prox;
    int i=0;
    while(fornecedorAux!= NULL){

        listaOrdenada[i].codigo =fornecedorAux->codigo;
        strcpy( listaOrdenada[i].nome,fornecedorAux->nome);
        strcpy( listaOrdenada[i].cnpj,fornecedorAux->cnpj);
        strcpy( listaOrdenada[i].telefone,fornecedorAux->telefone);
        listaOrdenada[i].endereco.codigo=fornecedorAux->endereco.codigo;
        strcpy( listaOrdenada[i].endereco.cep,fornecedorAux->endereco.cep);
        strcpy( listaOrdenada[i].endereco.uf,fornecedorAux->endereco.uf);
        strcpy( listaOrdenada[i].endereco.cidade,fornecedorAux->endereco.cidade);
        strcpy( listaOrdenada[i].endereco.bairro,fornecedorAux->endereco.bairro);
        strcpy( listaOrdenada[i].endereco.logradouro,fornecedorAux->endereco.logradouro);
        strcpy( listaOrdenada[i].endereco.complemento,fornecedorAux->endereco.complemento);
        fornecedorAux=fornecedorAux->prox;
        i++;
    }
    selectionSort(listaOrdenada,tamanho);

}
void selectionSort(Fornecedor lista[], int tamanho) {
	int i,j,menor;
	Fornecedor aux;
	for(i = 0; i < tamanho; i++) {
		menor = i;
		for(j = i+1; j < tamanho; j++) {
			if(strcmp(lista[j].nome, lista[menor].nome) < 0) {
				menor = j;
			}
		}
		if(i != menor) {
            aux.codigo=lista[i].codigo;
			strcpy(aux.nome, lista[i].nome);
            strcpy(aux.cnpj, lista[i].cnpj);
			strcpy(aux.telefone, lista[i].telefone);
			aux.endereco.codigo=lista[i].endereco.codigo;
			strcpy(aux.endereco.cep,lista[i].endereco.cep);
			strcpy(aux.endereco.uf,lista[i].endereco.uf);
			strcpy(aux.endereco.cidade,lista[i].endereco.cidade);
			strcpy(aux.endereco.bairro,lista[i].endereco.bairro);
			strcpy(aux.endereco.logradouro,lista[i].endereco.logradouro);
			strcpy(aux.endereco.complemento,lista[i].endereco.complemento);

            lista[i].codigo=lista[menor].codigo;
			strcpy(lista[i].nome, lista[menor].nome);
            strcpy(lista[i].cnpj, lista[menor].cnpj);
			strcpy(lista[i].telefone, lista[menor].telefone);
			lista[i].endereco.codigo=lista[menor].codigo;
			strcpy(lista[i].endereco.cep,lista[menor].endereco.cep);
			strcpy(lista[i].endereco.uf,lista[menor].endereco.uf);
			strcpy(lista[i].endereco.cidade,lista[menor].endereco.cidade);
			strcpy(lista[i].endereco.bairro,lista[menor].endereco.bairro);
			strcpy(lista[i].endereco.logradouro,lista[menor].endereco.logradouro);
			strcpy(lista[i].endereco.complemento,lista[menor].endereco.complemento);

            lista[menor].codigo=aux.codigo;
			strcpy( lista[menor].nome, aux.nome);
            strcpy( lista[menor].cnpj, aux.cnpj);
            lista[menor].endereco.codigo=aux.codigo;
			strcpy( lista[menor].endereco.cep,aux.endereco.cep);
			strcpy( lista[menor].endereco.uf,aux.endereco.uf);
			strcpy( lista[menor].endereco.cidade,aux.endereco.cidade);
			strcpy( lista[menor].endereco.bairro,aux.endereco.bairro);
			strcpy( lista[menor].endereco.logradouro,aux.endereco.logradouro);
			strcpy( lista[menor].endereco.complemento,aux.endereco.complemento);

		}
	}
    for(i=0;i<=tamanho-1;i++){

        printf("\nCódigo:%d ",lista[i].codigo);
        printf("\nNome:%s ",lista[i].nome);
        printf("\nTelefone:%s ",lista[i].cnpj);
        printf("\nIdade:%s ",lista[i].telefone);
        printf("\nEndereço");
        printf("\nCódigo:%d ",lista[i].endereco.codigo);
        printf("\nCep:%s ",lista[i].endereco.cep);
        printf("\nUf:%s ",lista[i].endereco.uf);
        printf("\nCidade:%s ",lista[i].endereco.cidade);
        printf("\nBairro:%s ",lista[i].endereco.bairro);
        printf("\nLogradouro:%s ",lista[i].endereco.logradouro);
        printf("\nComplemento:%s ",lista[i].endereco.complemento);
        printf("\n");

    }
}
int buscarFornecedor(int op,int remove,int codigo){
    int retorno;
    buscarFornecedores();
    Fornecedor fornecedor;
    Fornecedor *fornecedorAux;
    fornecedorAux=primeiroFornecedor->prox;
    if(op==1){
        char nome[100];
        printf("\n NOME:\n");
        scanf(" %[^\n]s",nome);
            while(fornecedorAux!= NULL){
                if(strcmp(fornecedorAux->nome,nome)==0){
                    mostrar(fornecedorAux);
                   retorno=1;
                }
                fornecedorAux=fornecedorAux->prox;
            }

    }else if(op==2){
            while(fornecedorAux!= NULL){
                if(fornecedorAux->codigo==codigo){
                    mostrar(fornecedorAux);
                    retorno=1;
                }
                fornecedorAux=fornecedorAux->prox;
            }
            if(remove==1){
                RemoveDado(codigo);
            }
    }else{
        printf("FORNCEDOR NÃO ENCONTRADO\n");
        retorno=0;
    }
return retorno;
}
void mostrar(Fornecedor *fornecedor){
    printf("\nCódigo:%d ",fornecedor->codigo);
    printf("\nNome:%s ",fornecedor->nome);
    printf("\nTelefone:%s ",fornecedor->cnpj);
    printf("\nIdade:%s ",fornecedor->telefone);
    printf("\nEndereço");
    printf("\nCódigo:%d ",fornecedor->endereco.codigo);
    printf("\nCep:%s ",fornecedor->endereco.cep);
    printf("\nUf:%s ",fornecedor->endereco.uf);
    printf("\nCidade:%s ",fornecedor->endereco.cidade);
    printf("\nBairro:%s ",fornecedor->endereco.bairro);
    printf("\nLogradouro:%s ",fornecedor->endereco.logradouro);
    printf("\nComplemento:%s ",fornecedor->endereco.complemento);
    printf("\n");
}
int RemoveDado(int dado)
{
  Fornecedor *ptr, *antes;
  if (primeiroFornecedor==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {   // Caso a lista nao esteja vazia
      ptr =primeiroFornecedor->prox;
      antes = primeiroFornecedor;
      while (ptr !=NULL)
      {
	 if (ptr->codigo == dado) // achou !!
	 {
	    if (ptr == primeiroFornecedor) // se esta removendo o primeiro da lista
	    {
	       primeiroFornecedor = primeiroFornecedor->prox;
	       free(ptr);
	       return 1; // removeu !!
	    }
	    else  // esta removendo do meio da lista
	    {
	      antes->prox = ptr->prox;  // Refaz o encadeamento
	      free(ptr);                // Libera a area do nodo
	      return 1;   // removeu !!
	    }
	 }
	 else  // continua procurando no prox. nodo
	 {
	    antes = ptr;
	    ptr = ptr->prox;
	 }
      }
      return 0; // Nao achou !!!
  }
}
