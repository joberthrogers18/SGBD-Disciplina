#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POPRIETARIOS 100

typedef struct{
    char CPF[11];
    char nome[50];
    char telefone[11];
} Proprietario;

/*typedef struct{
    char CPF[11];
    int posicao;
}Index;*/

typedef struct{
    char CPF_proprietario[11];
    char marca[50];
    char modelo[50];
    int ano;
}Automoveis;

Proprietario dono[MAX_POPRIETARIOS];
Automoveis automoveis[MAX_POPRIETARIOS];
//Index indice[MAX_POPRIETARIOS];

int pos_atual_proprietarios = 0;
int pos_atual_automoveis = 0;

void menu();
void cadastrar_proprietario();
void cadastrar_automoveis();
void remover();
void listar();
void escrever_arquivo_proprietarios();
void ler_arquivo_proprietarios();
void escrever_arquivo_automovel();
void ler_arquivo_automoveis();
int main()
{
    ler_arquivo_proprietarios();
    ler_arquivo_automoveis();
    /*printf("%s", dono[1].nome);
    printf("%s", dono[1].CPF);
    printf("%s", dono[1].telefone);*/
    menu();
    return 0;
}
void menu(){
    int op;
    do{
    system("cls");
    printf("\n1 - Cadastrar\n");
    printf("\n2 - Listar\n");
    printf("\n3 - Remover\n");
    printf("\n0 - Sair\n");
    scanf("%d", &op);
    getchar();
    switch(op){
        case 1:
            cadastrar_proprietario();
            break;
        case 2:
            listar();
            break;
        case 3:
            //remover();
            break;
        }
    }while(op != 0);

    escrever_arquivo_proprietarios();
    escrever_arquivo_automovel();
}

void cadastrar_proprietario(){
    int i;
    char nome[50];
    char CPF[11];
    char telefone[11];
    int op;
    //do{
            //system("cls");
            printf("\nCPF: ");
            getchar();
            fgets(CPF, sizeof(CPF), stdin);
            printf("\nNome: ");
            fgets(nome, sizeof(nome), stdin);
            printf("\nTelefone: ");
            fgets(telefone, sizeof(telefone), stdin);
            strcpy(dono[pos_atual_proprietarios].CPF, CPF);
            strcpy(dono[pos_atual_proprietarios].nome, nome);
            strcpy(dono[pos_atual_proprietarios].telefone, telefone);
            /*for(i=0; i < MAX_POPRIETARIOS; i++)
            {
                strcpy(dono[i].CPF, CPF);
                strcpy(dono[i].nome, nome);
                strcpy(dono[i].telefone, telefone);
                fprintf(arquivo,"%s ",dono[i].CPF);
                fprintf(arquivo,"%s ",dono[i].nome);
                fprintf(arquivo," %s\n",dono[i].telefone);

            }*/

            pos_atual_proprietarios++;

            cadastrar_automoveis(CPF);

            //printf("\n1 - continuar\n2 - Menu\n");
            //scanf("%d", &op);

    //}while(op != 2);
}

void cadastrar_automoveis(char *CPF){
    int i;
    char marca[50];
    char modelo[50];
    int ano;
    int op;
    do{
        printf("\nModelo: ");
        getchar();
        fgets(modelo, sizeof(modelo), stdin);
        printf("\nMarca: ");
        fgets(marca, sizeof(marca), stdin);
        printf("\nAno: ");
        scanf("%d",&ano);
        strcpy(automoveis[pos_atual_automoveis].marca, marca);
        strcpy(automoveis[pos_atual_automoveis].modelo, modelo);
        automoveis[pos_atual_automoveis].ano = ano;
        strcpy(automoveis[pos_atual_automoveis].CPF_proprietario, CPF);

        pos_atual_automoveis++;

        printf("\n1 - Cadastrar mais carros \n2 - Menu\n");
        scanf("%d", &op);

    }while(op != 2);
}

void escrever_arquivo_proprietarios(){
    FILE *arquivo;
    arquivo = (fopen("proprietario.txt","wb"));
    fwrite(dono, sizeof(Proprietario), pos_atual_proprietarios,arquivo);
    fclose(arquivo);
}

void ler_arquivo_proprietarios(){
    FILE *arquivo;
    arquivo = (fopen("proprietario.txt","ab+"));

    if(arquivo != NULL){
        while(!feof(arquivo)){
        fread(dono, sizeof(Proprietario), 100, arquivo);
        }

        int i;

        while(strcmp(dono[i].nome,"") != 0){
            pos_atual_proprietarios++;
            i++;
        }
        
    }

    fclose(arquivo);
}

void ler_arquivo_automoveis(){
    FILE *arquivo;
    arquivo = (fopen("automoveis.txt","ab+"));
    if(arquivo != NULL){
        while(!feof(arquivo)){
            fread(automoveis, sizeof(Automoveis), 100, arquivo);
        }

        int i;

        while(strcmp(automoveis[i].modelo,"") != 0){
            pos_atual_automoveis++;
            i++;
        }
    }
    
    fclose(arquivo);
}

void escrever_arquivo_automovel(){
    FILE *arquivo;
    arquivo = (fopen("automoveis.txt", "wb"));

    //int i = 0;
    /*
    while(strcmp(dono[i].nome,"") != 0){
        indice[i].posicao = i;
        strcpy(indice[i].CPF, dono[i].CPF);
        i++;
    }*/

    fwrite(automoveis, sizeof(Automoveis), pos_atual_automoveis, arquivo);
    fclose(arquivo);

}
/*
void remover(){
    int numero, op;
    do{
            system("cls");
    listar();
    printf("\n Digite o numero do proprietario a ser removido: ");
    scanf("%d", &numero);
    --numero;
    dono[numero].ativo=0;
    printf("Cadastro exluido com sucesso!");
    getchar();
    printf("\n1 - continuar\n0 - Menu\n");
    scanf("%d", &op);
    }while(op!=0);
}*/
void listar(){
    int i, op;
    do{
    system("cls");
    printf("\nLista de Proprietarios\n");
    for (i=0; i < MAX_POPRIETARIOS; i++){

        if(strcmp(dono[i].nome, "") != 0){
            printf("Proprietario numero: %d\n", i+1);
            printf("Nome: %s\n", dono[i].nome);
            printf("CPF: %s\n", dono[i].CPF);
            printf("Telefone: %s\n", dono[i].telefone);
        }
    }

     for (i=0; i < MAX_POPRIETARIOS; i++){

        if(strcmp(automoveis[i].modelo, "") != 0){
            printf("CPF automovel: %s\n",automoveis[i].CPF_proprietario );
            printf("Modelo: %s\n", automoveis[i].modelo);
        }
    }
    printf("\n1 - continuar\n0 - Menu\n");
    scanf("%d", &op);
    }while(op!=0);

}
