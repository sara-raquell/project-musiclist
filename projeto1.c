#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dados
{
    char musica[50];
    char album[50];
    char cantor[50];
    int ano, id, ativo;
    float avaliacao;

};

typedef struct dados dados;

dados music[100];

void cadastrar(int cont);
void listar(int cont);
void buscar(int cont);
void alterar(int cont);
void remover(int cont);
int sair();
int confimarcao();

int main(){
    int opcao, cont = 0, seguir; 
    char conf[5];

    while(seguir == 0){ 
        system("cls");
        printf("-----------------------------------------\n");
        printf("----------BEM VINDO AO MUSICLIST----------\n");
        printf("-----------------------------------------\n");
        printf("O que deseja fazer? \n");
        printf("1- Cadastro\n");
        printf("2- Listar\n");
        printf("3- Buscar\n");
        printf("4- Alterar\n");
        printf("5- remover\n");
        printf("6- Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            do
            {
                system("cls");
                cadastrar(cont);
                printf("\nDeseja realizar outro cadastro? Digite 'sim' para realizar outro cadastro ou 'nao' para retornar ao menu principal \n");
                scanf("%s", conf);
                fflush(stdin);
                cont++;
            } while (strcmp(conf, "sim") == 0);
            break;
        case 2:
            system("cls");
            listar(cont);    
            break;
        case 3:
            system("cls");
            buscar(cont);
            break;
        case 4:
            system("cls");
            alterar(cont);
            break;
        case 5:
            system("cls");
            remover(cont);
            break;
        case 6:
            system("cls");
            seguir = sair();
            break;   
        default:
            printf("Opcao invalida \n");
            break;
        }
    }

    return 0;
}

void cadastrar(int cont){
    printf("--------- CADASTRO DE MUSICAS --------\n");
    printf("Nome da musica: \n");
    fflush(stdin);
    fgets(music[cont].musica, 50, stdin);
    fflush(stdin);
    printf("Album da musica: \n");
    fgets(music[cont].album, 50, stdin);
    fflush(stdin);
    printf("Cantor/Banda da musica: \n");
    fgets(music[cont].cantor, 50, stdin);
    fflush(stdin);
    printf("Ano de lancamento da musica: \n");
    scanf("%d", &music[cont].ano);
    printf("Avaliacao da musica (nota de 1 a 5)\n");
    scanf("%f", &music[cont].avaliacao);
    music[cont].id = cont + 1;
    music[cont].ativo = 1;

    printf("\n____________Musica Cadastrada___________\n");
    printf("\nID: %d \n", music[cont].id);
    printf("\nMusica: %s \n", music[cont].musica);    
    printf("Album: %s \n", music[cont].album);
    printf("Canto/Banda: %s \n", music[cont].cantor);
    printf("Ano de lancamento: %d \n", music[cont].ano);
    printf("\nAvaliacao: %.2f \n", music[cont].avaliacao);
    printf("\n__________________________________________\n");
}

   
   
void listar(int cont){
    int i;
    printf("\n______________________________Musicas Cadastradas______________________________\n");
    if (cont > 0){
        for  (i = 0; i < cont; i++){
            if(music[i].ativo == 1){
                printf("\nID: %d \n", music[i].id);
                printf("\nMusica: %s \n", music[i].musica);    
                printf("Album: %s \n", music[i].album);
                printf("Canto/Banda: %s \n", music[i].cantor);
                printf("Ano de lancamento: %d \n", music[i].ano);
                printf("\nAvaliacao: %.2f \n", music[i].avaliacao);
                printf("__________________________________________\n");
            }
        }
    } else{
        printf("Nenhuma musica cadastrada: \n");
    }
     
   confimarcao();
}

void buscar(int cont){
    int opcao2, id, i, encontrado = 0;  
    char nome[50], album[50], cantor[50];

    printf("\n----- BUSCA DE MUSICAS -----\n");
    printf("Deseja realizar a buscar por qual metodo? \n");
    printf("1- ID\n");
    printf("2- Nome\n");
    printf("3- Buscar musicas de um determinado album\n");
    printf("4- Buscar musicas de um determinado cantor\n");
    scanf("%d", &opcao2);

    switch (opcao2)
    {
    case 1:
        printf("Digite o nome do ID da musica que deseja buscar: \n");
        scanf("%d", &id);
        for (i = 0; i < cont; i++)
        {
            if (music[i].id == id && music[i].ativo == 1)
            {
                printf("\n____________Musica Encontrada___________\n");
                printf("\nID: %d \n", music[i].id);
                printf("\nMusica: %s \n", music[i].musica);    
                printf("Album: %s \n", music[i].album);
                printf("Canto/Banda: %s \n", music[i].cantor);
                printf("Ano de lancamento: %d \n", music[i].ano);
                printf("\nAvaliacao: %.2f \n", music[i].avaliacao);
                printf("__________________________________________\n");
                encontrado = 1;
            } 
        }
        if (encontrado != 1)
            {
                printf("Musica nao encotrada! \n");
            }
        break;
    
    case 2:
        printf("Digite o nome da musica que deseja buscar: \n");
        fflush(stdin);
        fgets(nome, 50, stdin);
        fflush(stdin);
        for (i = 0; i < cont; i++)
        {
            if (strcmp(music[i].musica, nome) == 0 && music[i].ativo == 1)
            {
                printf("\n____________Musica Encontrada___________\n");
                printf("\nID: %d \n", music[i].id);
                printf("\nMusica: %s \n", music[i].musica);    
                printf("Album: %s \n", music[i].album);
                printf("Canto/Banda: %s \n", music[i].cantor);
                printf("Ano de lancamento: %d \n", music[i].ano);
                printf("\nAvaliacao: %.2f \n", music[i].avaliacao);
                printf("__________________________________________\n");
                encontrado = 1; 
            }
        }    
            if (encontrado != 1)
            {
                printf("Musica nao encotrada! \n");
            }
            
        break;
    case 3: 
        printf("Digite o nome do album em que deseja buscar: \n");
        fflush(stdin);
        fgets(album, 50, stdin);
        fflush(stdin);
        printf("---- Musicas do album %s ---- \n", album);
        for (i = 0; i < cont; i++)
        {
            if (strcmp(album, music[i].album) == 0 && music[i].ativo == 1)
            {
                printf("%s \n", music[i].musica);
            }
        }     
        break;
    case 4:
        printf("Digite o nome do cantor em que deseja buscar as musicas: \n");
        fflush(stdin);
        fgets(cantor, 50, stdin);
        fflush(stdin);
        printf("---- Musicas do album %s ---- \n", cantor);
        for (i = 0; i < cont; i++)
        {
            if (strcmp(cantor, music[i].cantor) == 0 && music[i].ativo == 1)
            {
                printf("%s \n", music[i].musica);
            }
        }    
        break;  
    default:
        printf("Opcao invalida\n");
        break;
    }

    confimarcao();
}    

void alterar(int cont){
    int i, opcao;
    char nome[50];

    printf("\n----- ALTERAR MUSICA -----\n");
    printf("Digite o nome da musica que deseja alterar: \n");
    fflush(stdin);
    fgets(nome, 50, stdin);
    fflush(stdin);

    for (i = 0; i < cont; i++)
    {
        if (strcmp(music[i].musica, nome) == 0 && music[i].ativo == 1)
        {
            printf("Escolha o que voce deseja alterar: \n");
            printf("1- Nome da musica. \n");
            printf("2- Album da musica. \n");
            printf("3- Cantor/Banda. \n");
            printf("4- Ano de lancamento. \n");
            printf("5- Avaliacao. \n");
            printf("6- Alterar tudo. \n");
            scanf("%d", &opcao);
            switch (opcao)
            {
                case 1:
                    printf("Digite o novo nome da musica: \n");
                    fflush(stdin);
                    fgets(music[i].musica, 50, stdin);
                    fflush(stdin);
                    break;
                case 2:
                    printf("Digite o novo album da musica: \n");
                    fflush(stdin);
                    fgets(music[i].album, 50, stdin);
                    fflush(stdin);
                    break;
                case 3:
                    printf("Digite o novo cantor/banda: \n");
                    fflush(stdin);
                    fgets(music[i].cantor, 50, stdin);
                    fflush(stdin);
                    break;
                case 4:
                    printf("Digite a nova data de lancamento: \n");
                    scanf("%d", &music[i].ano);
                    break;
                case 5:
                            printf("Digite a nova avaliacao: \n");
                            scanf("%f", &music[i].avaliacao);
                    break;    
                case 6:
                            printf("Informe o novo nome da musica: \n");
                            fflush(stdin);
                            fgets(music[i].musica, 50, stdin);
                            fflush(stdin);
                            printf("Digite o novo album da musica: \n");
                            fgets(music[i].album, 50, stdin);
                            fflush(stdin);
                            printf("Digite o novo cantor/banda: \n");
                            fgets(music[i].cantor, 50, stdin);
                            fflush(stdin);
                            printf("Digite a nova data de lancamento: \n");
                            scanf("%d", &music[i].ano);
                            printf("Informe a nov nota de avaliacao: \n");
                            scanf("%f", &music[i].avaliacao);
                break;    
            default:
                printf("Opcao invalida. \n");
                break;
            }

            printf("\n-----------MUSICA ALTERADA COM SUCESSO -----------\n");
            printf("\nID: %d \n", music[i].id);
            printf("\nMusica: %s \n", music[i].musica);    
            printf("Album: %s \n", music[i].album);
            printf("Canto/Banda: %s \n", music[i].cantor);
            printf("Ano de lancamento: %d \n", music[i].ano);
            printf("\nAvaliacao: %.2f \n", music[i].avaliacao);
            printf("\n----------------------------------------------------\n");     
        }
    }    

    confimarcao();
}

void remover(int cont){
    char nome[50];
    int i;

    printf("Digite o nome da musica que deseja remover: \n");
    fflush(stdin);
    fgets(nome, 50, stdin);
    fflush(stdin);
    for (i = 0; i < cont; i++)
    {
        if (strcmp(music[i].musica, nome) == 0 && music[i].ativo == 1)
        {
            music[i].ativo = 0;

            printf("\n-------------MUSICA REMOVIDA COM SUCESSO------------- \n");
        }
    }

    confimarcao();
}

int sair(){
   char conf[5];

   printf("Tem certeza que deseja encerrar o programa? \n");
   scanf("%s", conf);
   fflush(stdin);
   if (strcmp(conf, "sim") == 0)
   {
        printf("Encerrando o programa... \n");   
        return 1;
   } 
   else 
   {
        return 0;
   }
}

int confimarcao()
{
    char conf[5];
    printf("Deseja voltar para o menu principal? Digite 'sim' para retornar ao menu ou 'nao' para fechar o programa. ");
    fflush(stdin);
    gets(conf);
    fflush(stdin);
    if (strcmp(conf, "sim") == 0)
    {
        return 0;
    } 
    else 
    {
        printf("\nEncerrando o programa... \n");   
        exit(0);
    }
}