
typedef struct{
    int codigo;
    char nome[100];
    char categoria[14];
    double valorUnitario;
    int quantidade;
    int codFornecedor;
    struct Produto *prox;
}Produto;

Produto *primeiroProduto;
Produto *ultimoProduto;
int tamanho;
void criarListaProdutosVazia(){
    primeiroProduto=(Produto*)malloc(sizeof(Produto));
    ultimoProduto=primeiroProduto;
}
//flagOp 0=atualizar
void cadastrarProduto(int codigoFornecedor,int flagOp,int cod){
    Produto produto;
    int flagPedCod=0;
    COD:
    printf("\n\nDADOS DO PRODUTO:");
    if(flagPedCod==1){
        printf("\n\nCódigo:");
        scanf(" %d",&produto.codigo);
        cod=produto.codigo;
    }
    if(flagOp==0){
        printf("\n\nCódigo:");
        scanf(" %d",&produto.codigo);

        if(buscarProduto(2,0,produto.codigo)==1 && produto.codigo!=cod){
            printf("\nCódigo Já Cadastrado!Tente outro Código");
            goto COD;
        }
    }else{
        if(buscarFornecedor(2,0,cod)==1){
            printf("\nCódigo Já Cadastrado!Tente Outro Código");
            flagPedCod=1;
            goto COD;
        }
    }

    printf("\nNome:");
    scanf(" %[^\n]s",produto.nome);
    printf("\nValor Unitario:");
    scanf("%lf",&produto.valorUnitario);
    fflush(stdin);
    printf("\nCATEGORIA:");
    printf("\n1-ALIMENTOS");
    printf("\n2-ELETRÔNICOS");
    printf("\n3-ELETRODOMESTICOS:");
    printf("\n4-MOVEIS:");
    printf("\n5-VESTUÁRIO:");
    int categoria;
    CATEGORIA:
    scanf("%d",&categoria);
    printf("\n%d",categoria);
    if(categoria==1){
      strcpy(produto.categoria,"ALIMENTOS");
    }else if(categoria==2){
        strcpy(produto.categoria,"ELETRÔNICOS");
    }else if(categoria==3){
        strcpy(produto.categoria,"ELETRODOMESTICOS");
    }else if(categoria==4){
        strcpy(produto.categoria,"MOVEIS");
    }else if(categoria==5){
        strcpy(produto.categoria,"VESTUÁRIO");
    }
    else{
        printf("Opção inválida!");
     goto CATEGORIA;
    }

    printf("\nQuantidade:");
    scanf(" %d",&produto.quantidade);
    fflush(stdin);
    produto.codFornecedor=codigoFornecedor;
    inseriProdutoNaLista(produto);
    salvarProdutoNoArquivo();
}
void inseriProdutoNaLista(Produto produto){
    Produto *produtoAux;
    produtoAux = (Produto *)malloc(sizeof(Produto));
    produtoAux->codigo =produto.codigo;
    strcpy( produtoAux->nome,produto.nome);
    produtoAux->quantidade=produto.quantidade;
    produtoAux->valorUnitario=produto.valorUnitario;
    strcpy( produtoAux->categoria,produto.categoria);
    produtoAux->codFornecedor=produto.codFornecedor;
    ultimoProduto->prox=produtoAux;
    ultimoProduto=ultimoProduto->prox;
    produtoAux->prox=NULL;
}
void salvarProdutoNoArquivo(){
    FILE *pont_arq; // cria variável ponteiro para o arquivo
    Produto *produtoAux;
    produtoAux=primeiroProduto->prox;
    pont_arq = fopen("produtos.txt", "w");

  //testando se o arquivo foi realmente criado
    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
     while(produtoAux!= NULL){
        fprintf(pont_arq,"%d;%s;%s;%d;%lf;%d\n",produtoAux->codigo,produtoAux->nome,produtoAux->categoria,
            produtoAux->quantidade,produtoAux->valorUnitario,produtoAux->codFornecedor);

       produtoAux=produtoAux->prox;
     }
     fclose(pont_arq);
     printf("Dados gravados com sucesso!\n");

}
void buscarProdutos(){
  FILE *pont_arq;
  char linha[1024]; // variável do tipo string
  pont_arq = fopen("produtos.txt", "r");
  if(pont_arq == NULL)
  {
     printf("Erro na abertura do arquivo!");
     return 1;
  }
  tamanho=0;
  criarListaProdutosVazia();
    while(fscanf(pont_arq, " %[^\n]s",linha)!=EOF){
        Produto produto;
        char *ptr;
        ptr=strtok(linha,";");
        produto.codigo=atoi(ptr);
        ptr=strtok(NULL,";");
        strcpy(produto.nome,ptr);
        ptr=strtok(NULL,";");
        strcpy(produto.categoria,ptr);
        ptr=strtok(NULL,";");
        produto.quantidade=atoi(ptr);
        ptr=strtok(NULL,";");
        produto.valorUnitario=atoi(ptr);
        ptr=strtok(NULL,";");
        produto.codFornecedor=atoi(ptr);
        ptr=strtok(NULL,";");
        tamanho++;
        inseriProdutoNaLista(produto);

    }
  fclose(pont_arq);
}
void ordernarProdutos(char categoria[60]){

    Produto listaOrdenada[tamanho];
    Produto *produtoAux;
    produtoAux=primeiroProduto->prox;
    int i=0;
    while(produtoAux!= NULL){

        listaOrdenada[i].codigo =produtoAux->codigo;
        strcpy( listaOrdenada[i].nome,produtoAux->nome);
        strcpy( listaOrdenada[i].categoria,produtoAux->categoria);
        listaOrdenada[i].valorUnitario=produtoAux->valorUnitario;
        listaOrdenada[i].quantidade=produtoAux->quantidade;
        listaOrdenada[i].codFornecedor=produtoAux->codFornecedor;

        produtoAux=produtoAux->prox;
        i++;
    }
   selectionSortP(listaOrdenada,tamanho,categoria);

}
void selectionSortP(Produto listaP[], int tamanho,char categoria[60]) {
	int i,j,menor;
	Produto aux;
	for(i = 0; i < tamanho; i++) {
		menor = i;
		for(j = i+1; j < tamanho; j++) {
			if(strcmp(listaP[j].nome, listaP[menor].nome) < 0) {
				menor = j;
			}
		}
		if(i != menor) {
            aux.codigo=listaP[i].codigo;
			strcpy(aux.nome, listaP[i].nome);
            strcpy(aux.categoria, listaP[i].categoria);
			aux.valorUnitario=listaP[i].valorUnitario;
			aux.quantidade=listaP[i].quantidade;
			aux.codFornecedor=listaP[i].codFornecedor;

            listaP[i].codigo=listaP[menor].codigo;
			strcpy(listaP[i].nome, listaP[menor].nome);
            strcpy(listaP[i].categoria, listaP[menor].categoria);
			listaP[i].valorUnitario=listaP[menor].valorUnitario;
			listaP[i].quantidade=listaP[menor].quantidade;
			listaP[i].codFornecedor=listaP[menor].codFornecedor;

            listaP[menor].codigo=aux.codigo;
			strcpy( listaP[menor].nome, aux.nome);
            strcpy( listaP[menor].categoria, aux.categoria);
            listaP[menor].valorUnitario=aux.valorUnitario;
			listaP[menor].quantidade=aux.quantidade;
			listaP[menor].codFornecedor,aux.codFornecedor;

        }
	}
    for(i=0;i<=tamanho-1;i++){
        if(strcmp(categoria,"TODOS")==0){
            printf("\nCódigo:%d ",listaP[i].codigo);
            printf("\nNome:%s ",listaP[i].nome);
            printf("\nCategoria:%s ",listaP[i].categoria);
            printf("\nQuantidade:%d ",listaP[i].quantidade);
            printf("\nValor Unitário:%.2lf ",listaP[i].valorUnitario);
            printf("\nCódigo Fornecedor:%d ",listaP[i].codFornecedor);
            printf("\n");
        }
        if(!strcmp(categoria,"TODOS")==0){
            if(strcmp(categoria,listaP[i].categoria)==0){
                printf("\nCódigo:%d ",listaP[i].codigo);
                printf("\nNome:%s ",listaP[i].nome);
                printf("\nCategoria:%s ",listaP[i].categoria);
                printf("\nQuantidade:%d ",listaP[i].quantidade);
                printf("\nValor Unitário:%.2lf ",listaP[i].valorUnitario);
                printf("\nCódigo Fornecedor:%d ",listaP[i].codFornecedor);
                printf("\n");
            }
        }


    }
}
int buscarProduto(int op,int remove,int codigo){
    int retorno;
    buscarProdutos();
    Produto produto;
    Produto *produtoAux;
    produtoAux=primeiroProduto->prox;
    if(op==1){
        char nome[100];
        printf("\n NOME:\n");
        scanf(" %[^\n]s",nome);
            while(produtoAux!= NULL){
                if(strcmp(produtoAux->nome,nome)==0){
                   mostrarProduto(produtoAux);
                   retorno=1;
                }
                produtoAux=produtoAux->prox;
            }

    }else if(op==2){
            while(produtoAux!= NULL){
                if(produtoAux->codigo==codigo){
                    mostrarProduto(produtoAux);
                    retorno=1;
                }
                produtoAux=produtoAux->prox;
            }
            if(remove==1){
                RemoveProduto(codigo);
            }
    }else{
        printf("PRODUTO NÃO ENCONTRADO\n");
        retorno=0;
    }
return retorno;
}
void mostrarProduto(Produto *produto){
    printf("PRODUTO");
    printf("\nCódigo:%d ",produto->codigo);
    printf("\nNome:%s ",produto->nome);
    printf("\nCategoria:%s ",produto->categoria);
    printf("\nQuantidade:%d ",produto->quantidade);
    printf("\nCódigo:%.2lf R$ ",produto->valorUnitario);
    printf("\nCódigo Fornecedor:%d ",produto->codFornecedor);
    printf("\n");
    int retorno;
    printf("\nFORNECEDOR");
    retorno=buscarFornecedor(2,0,produto->codFornecedor);
}
int RemoveProduto(int dado){
  Produto *ptr, *antes;
  if (primeiroProduto==NULL)
  {
      return 0;  // Lista vazia !!!
  }
  else
  {   // Caso a lista nao esteja vazia
      ptr =primeiroProduto->prox;
      antes = primeiroProduto;
      while (ptr !=NULL)
      {
	 if (ptr->codigo == dado) // achou !!
	 {
	    if (ptr == primeiroProduto) // se esta removendo o primeiro da lista
	    {
	       primeiroProduto = primeiroProduto->prox;
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
