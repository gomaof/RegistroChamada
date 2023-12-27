#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char cpf[18];
    char nome[80];
    int tipoatendimento;
} registros;

void registrar(registros atendimentos[], int *numero);
void listarregistros(registros atendimentos[], int numero);
void listarsetor(registros atendimentos[], int numero, int setor);

void registrar(registros atendimentos[], int *numero) {
    system("cls");
    printf("Digite seu Nome: ");
    fflush(stdin);
    fgets(atendimentos[*numero].nome, sizeof(atendimentos[*numero].nome), stdin);
    atendimentos[*numero].nome[strcspn(atendimentos[*numero].nome, "\n")] = '\0';
    printf("Digite seu CPF: ");
    scanf("%s", atendimentos[*numero].cpf);
    printf("\nEscolha seu atendimento: \n");
    printf("\t1 - Abertura de Conta\n\t2 - Caixa\n\t3 - Gerente Pessoa Física\n\t4 - Gerente Pessoa Jurídica\n");
    scanf("%d", &atendimentos[*numero].tipoatendimento);
    (*numero)++;
    printf("Atendimento registrado com sucesso!\n\n\n");
    system("pause");
    system("cls");
}

void listarregistros(registros atendimentos[], int numero);
void listarregistros(registros atendimentos[], int numero) {
    system("cls");
    if (numero == 0) {
        printf("Nenhum atendimento registrado ainda.\n\n\n");
    } else {
        printf("Lista de todos os atendimentos registrados:\n");
        int i;
        for (i = 0; i < numero; i++) {
            printf("\nNome: %s\nCPF: %s\nTipo Atendimento - %d - ", atendimentos[i].nome, atendimentos[i].cpf, atendimentos[i].tipoatendimento);
            switch (atendimentos[i].tipoatendimento) {
                case 1:
                    printf("Abertura de Conta\n");
                    break;
                case 2:
                    printf("Caixa\n");
                    break;
                case 3:
                    printf("Gerente Pessoa Física\n");
                    break;
                case 4:
                    printf("Gerente Pessoa Jurídica\n");
                    break;
                default:
                    printf("OpÃ§Ã£o invÃ¡lida. Tente novamente.\n\n\n");
            }
            printf("=========================\n");
        }
    }
    system("pause");
    system("cls");
}

void listarsetor(registros atendimentos[], int numero, int setor);
void listarsetor(registros atendimentos[], int numero, int setor) {
    system("cls");
    if (numero == 0) {
        printf("Nenhum atendimento registrado ainda.\n\n\n");
    } else {
    	int i;
        for (i = 0; i < numero; i++) {
            if (atendimentos[i].tipoatendimento == setor) {
                printf("\nNome: %s\nCPF: %s\nTipo Atendimento - %d - ", atendimentos[i].nome, atendimentos[i].cpf, atendimentos[i].tipoatendimento);
                switch (atendimentos[i].tipoatendimento) {
                    case 1:
                        printf("Abertura de Conta\n");
                        break;
                    case 2:
                        printf("Caixa\n");
                        break;
                    case 3:
                        printf("Gerente Pessoa Física\n");
                        break;
                    case 4:
                        printf("Gerente Pessoa Jurídica\n");
                        break;
                    default:
                        printf("OpÃ§Ã£o invÃ¡lida. Tente novamente.\n\n\n");
                }
                printf("=========================\n");
            }
        }
    }
    system("pause");
    system("cls");
}

int main() {
    registros atendimentos[50];
    int opcao, numero = 0;
    setlocale(LC_ALL, "Portuguese");

    do {
        printf("\n\tBem-vindo ao sistema de atendimento\n\n");
        printf("\n\n1 - Solicitar Atendimento\n\n");
        printf("\n\n2 - Listar Atendimento Registrados\n\n");
        printf("\n\n3 - Listar Atendimento por Setor\n\n");
        printf("\n\n4 - Sair\n\n");
        printf("\n\nEscolha sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                registrar(atendimentos, &numero);
                break;
            case 2:
                listarregistros(atendimentos, numero);
                break;
            case 3:
                system("cls");
                printf("Informe o setor registrado:\n\n1 - Abertura de Conta\n\n2 - Caixa\n\n3 - Gerente Pessoa Física\n\n4 - Gerente Pessoa Jurídica\n\n");
                int setor;
                scanf("%d", &setor);
                listarsetor(atendimentos, numero, setor);
                break;
            case 4:
                printf("Atendimento encerrado!\n\nPara fechar o sistema, clique em alguma tecla.\n\n");
                break;
            default:
                printf("Opçãoo Incorreta! Tente Novamente.");
        }
    } while (opcao != 4);

    return 0;
}