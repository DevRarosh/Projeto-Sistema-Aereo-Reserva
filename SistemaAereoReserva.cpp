#include <iostream>
#include <locale> // Inclui a biblioteca locale
#include <cstdio>

using namespace std;

// Códigos ANSI para cores
#define AZUL "\033[34m"   // Azul
#define VERMELHO "\033[31m" // Vermelho
#define RESET "\033[0m"   // Reseta para a cor padrão

void mostrarQuadro(char reserva[10][6]) {
    printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
    for (int x = 0; x < 10; x++) {
        if (x != 9) printf("\n\t0%d\t", x + 1);
        else printf("\n\t%d\t", x + 1);    
        
        for (int y = 0; y < 6; y++) {
            if (reserva[x][y] == 'R') {
                printf(VERMELHO "🔴 " RESET); // Assento reservado em vermelho
            } else {
                printf(AZUL "⚪ " RESET); // Assento disponível em azul
            }
            if (y == 2) {
                printf("\t"); // Adiciona um espaço extra entre as colunas
            }
        }
        printf("\n"); // Adiciona uma nova linha ao final de cada fileira
    }
    printf("\n");
}

int main(int argc, char** argv) {
    // Configuração da localidade para UTF-8
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Define a localidade para Português do Brasil

    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    int fileira = -1, assento = -1;
    char poltrona = ' ';
    int opcao = -1;
    int categoria = -1;

    while (true) {
        printf("Escolha uma opção:");
        printf("\n[1] Reservar poltrona");
        printf("\n[2] Mostrar quadro de poltronas");
        printf("\n[3] Sair\n");
        scanf("%i", &opcao);

        if (opcao == 1) {
            mostrarQuadro(reserva); // Mostrar quadro de poltronas antes de reservar

            do {
                printf("\nEscolha a categoria da sua reserva: \n");
                printf("\n[1] Executiva\n");
                printf("\n[2] Econômica\n");
                scanf("%i", &categoria);
                
                if (categoria == 1) { // Categoria Executiva
                    printf("\nDigite a fileira (1-10): ");
                    scanf("%d", &fileira);
                    printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
                    scanf(" %c", &poltrona);
                    
                    switch (poltrona) {
                        case 'A':
                        case 'a':
                            assento = 0;
                            break;
                        case 'B':
                        case 'b':
                            assento = 1;
                            break;
                        case 'C':
                        case 'c':
                            assento = 2;
                            break;
                        case 'D':
                        case 'd':
                            assento = 3;
                            break;
                        case 'E':
                        case 'e':
                            assento = 4;
                            break;
                        case 'F':
                        case 'f':
                            assento = 5;
                            break;
                        default:
                            printf("\nPoltrona inválida\n");
                            continue; // Continue to ask for a valid seat
                    }
                    
                    // Verifica se o assento já está reservado
                    if (reserva[fileira-1][assento] == 'R') {
                        printf("Esse assento já está reservado. Por favor, escolha outro.\n");
                    } else {
                        reserva[fileira-1][assento] = 'R'; // Reserva o assento
                        printf("Assento reservado com sucesso.\n");
                    }
                } else if (categoria == 2) { // Categoria Econômica
                    printf("\nDigite a fileira (1-10): ");
                    scanf("%d", &fileira);
                    printf("\nDigite a poltrona [B][C][D][E]: ");
                    scanf(" %c", &poltrona);
                    
                    switch (poltrona) {
                        case 'B':
                        case 'b':
                            assento = 1;
                            break;
                        case 'C':
                        case 'c':
                            assento = 2;
                            break;
                        case 'D':
                        case 'd':
                            assento = 3;
                            break;
                        case 'E':
                        case 'e':
                            assento = 4;
                            break;
                        default:
                            printf("\nPoltrona não disponível na sua categoria\n");
                            continue; // Continue to ask for a valid seat
                    }
                    
                    // Verifica se o assento já está reservado
                    if (reserva[fileira-1][assento] == 'R') {
                        printf("Esse assento já está reservado. Por favor, escolha outro.\n");
                    } else {
                        reserva[fileira-1][assento] = 'R'; // Reserva o assento
                        printf("Assento reservado com sucesso.\n");
                    }
                } else {
                    printf("Categoria inválida. Por favor, escolha uma opção válida.\n");
                }

                // Pergunta se o atendente deseja fazer outra reserva
                char continuar;
                printf("Deseja realizar outra reserva? (s/n): ");
                scanf(" %c", &continuar);
                if (continuar == 'n' || continuar == 'N') {
                    break; // Encerra o loop
                }

            } while (true); // Loop para tentar fazer outra reserva
        }    

        if (opcao == 2) {
            mostrarQuadro(reserva); // Mostra o quadro de poltronas
        }
        
        if (opcao == 3) {
            printf("Encerrando o sistema de reservas...\n");
            break; // Encerra o programa
        }
    }
    
    return 0;
}

