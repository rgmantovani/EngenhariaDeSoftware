#include<stdio.h>
#include<stdbool.h>
#define TAM 3

// TAD - p Estática
typedef struct {
    int vetor[TAM];
    int topo; //indexador => posições do vetor
} PilhaEst;

// Inicializando a pilha
void iniciarPilhaEst(PilhaEst *pilha){
    pilha->topo = 0;
}

// Verificando se a pilha está vazia e retornando em bool
bool estaVaziaPilhaEst(PilhaEst *pilha){
    return (pilha->topo == 0);
}

// Verificando se a pilha está cheia e retornando em bool
// IF topo for igual ao tamanho, 3 no caso, retornará true = está cheia
bool estaCheiaPilhaEst(PilhaEst *pilha){
    return (pilha->topo == TAM);
}

// Verificando o tamanho da pilha
int tamanhoPilhaEst(PilhaEst *pilha){
    return(pilha->topo);
}

// Impresão - print, sem tirar do topo
 void imprimePilhaEsta(PilhaEst *pilha){
    printf("Pilha = [");
        for (int i = 0; i < pilha->topo; i++){
            printf("%d ", pilha->vetor[i]);
        }
    printf("]\n");
 }

// Push pilha
void empilhaPilhaEst(PilhaEst *pilha, int x){
    // IF a pilha não estiver cheia =>
    if (!estaCheiaPilhaEst(&pilha)){
        // Adiciona o número passado X na posição indexada pelo topo
        pilha->vetor[pilha->topo] = x;
        // Incrementando o valor do topo;
        pilha->topo++;
    } else {
        printf("Atenção: Pilha está cheia!\n");
    }
};

// Pop pilha
void desempilhaPilhaEst(PilhaEst *pilha){
    // IF a pilha não esta vazia =>
    if(!estaVaziaPilhaEst(pilha)){
        pilha->topo--;
    } else {
        printf("Atenção: Pilha está vazia!\n");
    }
}

// Consulta - Reiniciando pilha
int topoPilhaEst(PilhaEst *pilha){
    int res = pilha->vetor[pilha->topo-1];

    return (res);
}

/*********************************************************/

// Conversão de número inteiro para binário
void ConverteInteBin(PilhaEst *pilha, int numEntrada){
    int resto;
    int InteBin;

    resto = numEntrada;

    // Calculando e convertendo número binário e empilhanod na pilha

    // Realizando divisão
    while ((numEntrada != 1) && (numEntrada != 0)){
        // Quando = 0, 0
        InteBin = resto % 2;
        numEntrada = numEntrada / 2;
        
        empilhaPilhaEst(pilha, InteBin);

        resto = numEntrada;
    }

        if (numEntrada == 1){
            empilhaPilhaEst(pilha, 1);
        } else {
            empilhaPilhaEst(pilha, 0);
        }

}

/******************************************************/

int main(int argc, char *argv[]){
    /* Declarações */
    PilhaEst *pilha;
    int numArqEntrada;
    int tamanho;
    int numSaida;
    int tam;

    char s;

    /* Acessando arquivos */
    FILE *ArqEntrada = fopen(argv[1], "r");
    FILE *ArqAux = fopen(argv[1], "r");
    FILE *ArqSaida = fopen(argv[2], "w");
    
    printf("Saída: %s \n", argv[2]);

    /* Testando arquivos */

    //argv[1]
    // Testando a quantidade de arquivos
    if(argc > 3 || argc < 3){
        printf("Erro na leitura do arquivo de entrada.\n");
        return;
    }

    // Testando a abertura de programas vazios
    if(ArqEntrada == NULL || ArqSaida == NULL){
        printf("Erro na abertura do arquivo de entrada.\n");
        return 0;
    }

    /* Verificando e retornando se a pilha está vazia */
    iniciarPilhaEst(&pilha);
    imprimePilhaEsta(&pilha);

    if (estaVaziaPilhaEst(&pilha)){
        printf("Let go! Pilha está vazia.\n");
    }

       /* Verificando e retornando se a pilha está cheia */
    // if(!estaCheiaPilhaEst(&pilha){
    //     printf("A pilha está cheia, não rola de inserir mais elementos!\n");
    // });

        /* Verificando e retornando o tamanho da pilha */
    tam = tamanhoPilhaEst(&pilha);
    printf("A pilha tem tamanho igual a = %d\n", tam);



    // Enquanto não estiver cheia, chama a função de conversão
    while (!feof(ArqEntrada)){
        topoPilhaEst(&pilha);

        if ((s = fgetc(ArqAux)) !="\n"){
            fscanf(ArqEntrada, "%d", &numArqEntrada);

            ConverteInteBin(&pilha, numArqEntrada);

            imprimePilhaEsta(&pilha);

            // Conforme a pilha vai sendo desempilhada, a saída
            // irá sendo impressa na tela. Sendo o resto da divisão 0 ou 1

            tamanho = tamanhoPilhaEst(&pilha);

            printf("O tamanho da pilha é igual a: %d.\n", tamanho);

            for (int y = 0; y < tamanhoPilhaEst; y++){
                numSaida = desempilhaPilhaEst(&pilha);

                fprintf(ArqSaida, "%d", numSaida);
            }
        }
        fprintf(ArqSaida, "\n");
    }
    fclose(ArqAux);
    fclose(ArqEntrada);
    fclose(ArqSaida);

    return 0;
}