#include <stdio.h>
#include <string.h>

// Definir o tamanho máximo para o nome do país
#define TAMANHO_NOME 50

// Estrutura para armazenar os dados da carta
typedef struct {
    char nome[TAMANHO_NOME]; // Nome do país
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// Função para calcular a densidade populacional
float calcular_densidade_populacional(Carta carta) {
    return carta.populacao / carta.area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(Carta carta) {
    return carta.pib / carta.populacao;
}

// Função para calcular o Super Poder
float calcular_super_poder(Carta carta) {
    return carta.populacao + carta.area + carta.pib + carta.pontos_turisticos + (1 / carta.densidade_populacional);
}

// Função para exibir os dados da carta
void exibir_dados(Carta carta, int numero_carta) {
    printf("\n--- Dados da Carta %d: %s ---\n", numero_carta, carta.nome);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta.densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta.pib_per_capita);
    printf("Super Poder: %.2f\n", carta.super_poder);
}

// Função para comparar os atributos das cartas baseado na escolha do usuário
int comparar_atributo(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // Comparando População
            return (carta1.populacao > carta2.populacao) ? 1 : (carta1.populacao < carta2.populacao) ? -1 : 0;
        case 2: // Comparando Área
            return (carta1.area > carta2.area) ? 1 : (carta1.area < carta2.area) ? -1 : 0;
        case 3: // Comparando PIB
            return (carta1.pib > carta2.pib) ? 1 : (carta1.pib < carta2.pib) ? -1 : 0;
        case 4: // Comparando Pontos Turísticos
            return (carta1.pontos_turisticos > carta2.pontos_turisticos) ? 1 : (carta1.pontos_turisticos < carta2.pontos_turisticos) ? -1 : 0;
        case 5: // Comparando Densidade Populacional (menor vence)
            return (carta1.densidade_populacional < carta2.densidade_populacional) ? 1 : (carta1.densidade_populacional > carta2.densidade_populacional) ? -1 : 0;
        case 6: // Comparando Super Poder
            return (carta1.super_poder > carta2.super_poder) ? 1 : (carta1.super_poder < carta2.super_poder) ? -1 : 0;
        default:
            return 0;
    }
}

// Função para exibir o menu e pegar a escolha do usuário
int exibir_menu(const char *atributo1, const char *atributo2) {
    int escolha;

    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. Super Poder\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    // Verificar se o atributo já foi escolhido
    if (escolha < 1 || escolha > 6 || (strcmp(atributo1, "none") != 0 && (escolha == atoi(atributo1)))) {
        printf("Atributo inválido ou já escolhido, tente novamente.\n");
        return exibir_menu(atributo1, atributo2);
    }

    return escolha;
}

// Função para comparar os dois atributos escolhidos e calcular a soma
void comparar_duas_cartas(Carta carta1, Carta carta2) {
    int atributo1 = 0, atributo2 = 0;
    char atributo1_nome[50] = "none", atributo2_nome[50] = "none";

    // Escolher o primeiro atributo
    atributo1 = exibir_menu(atributo1_nome, atributo2_nome);
    switch (atributo1) {
        case 1: strcpy(atributo1_nome, "População"); break;
        case 2: strcpy(atributo1_nome, "Área"); break;
        case 3: strcpy(atributo1_nome, "PIB"); break;
        case 4: strcpy(atributo1_nome, "Pontos Turísticos"); break;
        case 5: strcpy(atributo1_nome, "Densidade Populacional"); break;
        case 6: strcpy(atributo1_nome, "Super Poder"); break;
    }

    // Escolher o segundo atributo
    atributo2 = exibir_menu(atributo1_nome, atributo2_nome);
    switch (atributo2) {
        case 1: strcpy(atributo2_nome, "População"); break;
        case 2: strcpy(atributo2_nome, "Área"); break;
        case 3: strcpy(atributo2_nome, "PIB"); break;
        case 4: strcpy(atributo2_nome, "Pontos Turísticos"); break;
        case 5: strcpy(atributo2_nome, "Densidade Populacional"); break;
        case 6: strcpy(atributo2_nome, "Super Poder"); break;
    }

    // Comparar os dois atributos e somar os resultados
    int resultado1 = comparar_atributo(carta1, carta2, atributo1);
    int resultado2 = comparar_atributo(carta1, carta2, atributo2);

    float soma_carta1 = 0.0, soma_carta2 = 0.0;

    // Determinar a carta vencedora para o primeiro atributo
    soma_carta1 += (resultado1 == 1) ? 1 : (resultado1 == 0) ? 0 : -1;
    soma_carta2 += (resultado1 == -1) ? 1 : (resultado1 == 0) ? 0 : -1;

    // Determinar a carta vencedora para o segundo atributo
    soma_carta1 += (resultado2 == 1) ? 1 : (resultado2 == 0) ? 0 : -1;
    soma_carta2 += (resultado2 == -1) ? 1 : (resultado2 == 0) ? 0 : -1;

    // Exibir os resultados da comparação
    printf("\nComparação entre os atributos: %s e %s\n", atributo1_nome, atributo2_nome);
    printf("\n%s:\n", carta1.nome);
    printf("Valor de %s: %.2f\n", atributo1_nome, (atributo1 == 1) ? carta1.populacao : (atributo1 == 2) ? carta1.area : carta1.pib);
    printf("Valor de %s: %.2f\n", atributo2_nome, (atributo2 == 1) ? carta1.populacao : (atributo2 == 2) ? carta1.area : carta1.pib);
    printf("\n%s:\n", carta2.nome);
    printf("Valor de %s: %.2f\n", atributo1_nome, (atributo1 == 1) ? carta2.populacao : (atributo1 == 2) ? carta2.area : carta2.pib);
    printf("Valor de %s: %.2f\n", atributo2_nome, (atributo2 == 1) ? carta2.populacao : (atributo2 == 2) ? carta2.area : carta2.pib);

    // Exibir o vencedor
    if (soma_carta1 > soma_carta2) {
        printf("\n%s vence a rodada!\n", carta1.nome);
    } else if (soma_carta2 > soma_carta1) {
        printf("\n%s vence a rodada!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }
}

// Função para capturar os dados do jogador para as cartas
Carta capturar_dados_carta(int numero_carta) {
    Carta carta;
    printf("\nDigite os dados para a carta %d:\n", numero_carta);
    printf("Nome do país: ");
    scanf(" %49[^\n]", carta.nome);
    printf("População: ");
    scanf("%lu", &carta.populacao);
    printf("Área: ");
    scanf("%f", &carta.area);
    printf("PIB: ");
    scanf("%f", &carta.pib);
    printf("Pontos turísticos: ");
    scanf("%d", &carta.pontos_turisticos);
    
    carta.densidade_populacional = calcular_densidade_populacional(carta);
    carta.pib_per_capita = calcular_pib_per_capita(carta);
    carta.super_poder = calcular_super_poder(carta);

    return carta;
}

// Função para o menu inicial
void menu_inicial(Carta* carta1, Carta* carta2) {
    int opcao;
    printf("Bem-vindo ao jogo de comparação de cartas!\n");
    printf("Escolha uma opção:\n");
    printf("1. Usar cartas pré-definidas (Brasil vs Estados Unidos)\n");
    printf("2. Digitar seus próprios dados para as cartas\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        // Usar cartas pré-definidas
        strcpy(carta1->nome, "Brasil");
        carta1->populacao = 213993437;
        carta1->area = 8515767.0;
        carta1->pib = 2170000.0;
        carta1->pontos_turisticos = 250;
        carta1->densidade_populacional = calcular_densidade_populacional(*carta1);
        carta1->pib_per_capita = calcular_pib_per_capita(*carta1);
        carta1->super_poder = calcular_super_poder(*carta1);

        strcpy(carta2->nome, "Estados Unidos");
        carta2->populacao = 331002651;
        carta2->area = 9833517.0;
        carta2->pib = 21000000.0;
        carta2->pontos_turisticos = 500;
        carta2->densidade_populacional = calcular_densidade_populacional(*carta2);
        carta2->pib_per_capita = calcular_pib_per_capita(*carta2);
        carta2->super_poder = calcular_super_poder(*carta2);
    } else if (opcao == 2) {
        // Digitar os dados do jogador
        *carta1 = capturar_dados_carta(1);
        *carta2 = capturar_dados_carta(2);
    } else {
        printf("Opção inválida! Tentando novamente.\n");
        menu_inicial(carta1, carta2);
    }
}

// Função principal
int main() {
    Carta carta1, carta2;
    char continuar;
    
    menu_inicial(&carta1, &carta2);
    
    do {
        // Exibir dados das cartas
        exibir_dados(carta1, 1);
        exibir_dados(carta2, 2);
        
        // Realizar a comparação de atributos
        comparar_duas_cartas(carta1, carta2);
        
        // Perguntar se o jogador quer continuar
        printf("\nDeseja jogar outra rodada? (s/n): ");
        scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');

    printf("\nJogo encerrado. Obrigado por jogar!\n");

    return 0;
}
