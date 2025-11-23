#include <stdio.h>
#include <stdlib.h>


// Desafio Tetris Stack
// Tema 3 - Integração de Fila e Pilha
// Este código inicial serve como base para o desenvolvimento do sistema de controle de peças.
// Use as instruções de cada nível para desenvolver o desafio.


// parametros globais com max de 5 peças 
#define MAX 5
// função para limpeza de buffer após uso
void limparBufferEntrada(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);

};
//estrutura das peças
typedef struct{
    char nome[30] ;
    int id;
}Pecas;

// estrutura da fila 
typedef struct{
    Pecas itens[MAX];
    int inicio;
    int fim;
    int total;
}Fila;



//função de iniciar a fila 
void incializar(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}
// função pra verificar se a fila esta cheia
int filaCheia(Fila *f){
    return f->total == MAX;
}
// função para ver se a fila esta vazia 
int filaVazia(Fila *f){
    return f->total == 0;
}
// função de inserir a peça, verificando se esta cheia a fila 
void InserirPeca(Fila *f, Pecas p){
    if(filaCheia(f)){
        printf("Você não pode mais gerar peças, pois a fila está cheia!.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}


// função para jogar peça, verificando se a fila esta vazia
void JogarPeca(Fila *f, Pecas *p){
    if(filaVazia(f)){
        printf("Você não pode jogar a peça, pois a lista está VAZIA!.\n");
        return;
    }
    *p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;
}

//função para ver o status da fila e suas  peças 
void MostraPeca(Fila *f){
    if(filaVazia(f)){
        printf("Nenhuma peça!\n");
        return;
    }
    printf("Fila de peças: ");
    for(int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % MAX){
        printf("[%s %d],", f->itens[idx].nome, idx);
    }
}

// função de gerar aleatoriamente as peças
void GerarPeca(Pecas *p){
    const char *nomes[] = {"I", "T", "L", "O"};
    int tipo = rand() % 5;
    snprintf(p->nome, sizeof(p->nome), "%s", nomes[tipo]);
    
}



int main(){

    Fila f;
    incializar(&f);
    Pecas removida;
    Pecas nova;
    int opcao;
    srand(time(NULL));
    
    //criando a lista de inicio com ela cheia e peças criadas com seus nomes e ids
    for(int i = 0; i < MAX; i++){
        Pecas nova;
        GerarPeca(&nova);
        InserirPeca(&f, nova);
    }
    
    MostraPeca(&f);

// função princial e menu para usuário escolhe ro que deseja fazer 
    do{

        printf("\n---TETRIS---\n");
        printf("1 - Jogar peça!\n");
        printf("2 - Inserir nova peça!\n");
        printf("0 - Sair do jogo.!\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao){
        case 1:
            printf("======================\n");
            printf("---Jogando um peça.---\n");
            printf("======================\n");
            JogarPeca(&f, &removida);
            printf("Peça %s removida \n", removida.nome);
            MostraPeca(&f);
            printf("\n------------------------\n");
            printf("\nPressione [ENTER] para continuar...\n");
            getchar();
            break;
        case 2:
            printf("========================\n");
            printf("---Inserindo uma peça---\n");
            printf("=========================\n");
            
            GerarPeca(&nova);
            InserirPeca(&f, nova );
            MostraPeca(&f);
            printf("\n-------------------------\n");
            printf("\nPressione [ENTER] para continuar...\n");
            getchar();

            break;
        case 0:
            printf("Saindo do jogo...\n");
            break;
        default:
            printf("==================================\n");
            printf("Opção inválida, escolha novamente!\n");
            printf("==================================\n");
            break;
        }



    }while(opcao);



    // 🧠 Nível Aventureiro: Adição da Pilha de Reserva
    //
    // - Implemente uma pilha linear com capacidade para 3 peças.
    // - Crie funções como inicializarPilha(), push(), pop(), pilhaCheia(), pilhaVazia().
    // - Permita enviar uma peça da fila para a pilha (reserva).
    // - Crie um menu com opção:
    //      2 - Enviar peça da fila para a reserva (pilha)
    //      3 - Usar peça da reserva (remover do topo da pilha)
    // - Exiba a pilha junto com a fila após cada ação com mostrarPilha().
    // - Mantenha a fila sempre com 5 peças (repondo com gerarPeca()).


    // 🔄 Nível Mestre: Integração Estratégica entre Fila e Pilha
    //
    // - Implemente interações avançadas entre as estruturas:
    //      4 - Trocar a peça da frente da fila com o topo da pilha
    //      5 - Trocar os 3 primeiros da fila com as 3 peças da pilha
    // - Para a opção 4:
    //      Verifique se a fila não está vazia e a pilha tem ao menos 1 peça.
    //      Troque os elementos diretamente nos arrays.
    // - Para a opção 5:
    //      Verifique se a pilha tem exatamente 3 peças e a fila ao menos 3.
    //      Use a lógica de índice circular para acessar os primeiros da fila.
    // - Sempre valide as condições antes da troca e informe mensagens claras ao usuário.
    // - Use funções auxiliares, se quiser, para modularizar a lógica de troca.
    // - O menu deve ficar assim:
    //      4 - Trocar peça da frente com topo da pilha
    //      5 - Trocar 3 primeiros da fila com os 3 da pilha


    return 0;
}

