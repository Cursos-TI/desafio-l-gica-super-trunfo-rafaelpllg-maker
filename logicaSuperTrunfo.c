#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    //Declara e inicializa as variáveis que armazenam dados para cada carta do jogo (carta 1 e carta 2)
    
    //Variáveis com os identificadores das cartas e nomes das cidades
    char cod_estado1= 'a', cod_estado2= 'a';
    char cod_carta1[4], cod_carta2[4];
    char nome_cidade1[50], nome_cidade2[50];
    
    //Variáveis com os atributos inseridos pelo usuário
    unsigned long int populacao1= 0, populacao2 = 0;
    int pts_turisticos1 = 0, pts_turisticos2 = 0;
    float pib1 = 0, pib2 = 0;
    float area1 = 0, area2 = 0;

    //Variáveis com os atributos calculados
    double densidade_pop1 = 0, densidade_pop2 = 0;
    double pib_capta1 = 0, pib_capta2 = 0;
    double super1, super2 = 0;

    //Variáveis que guardam as duas escolhas de atributos do usuário
    int escolha_jogador_1 = 0, escolha_jogador_2 = 0;

    //Variáveis para comparação da disputa
    double jogador_atributo1, jogador_atributo2;
    double pc_atributo1, pc_atributo2;

    //Variáveis que guardam os pontos para uma lógica do jogo um pouco mais complexa
    int pontos_jogador = 0, pontos_pc = 0;

    //Recebem as strings dos nomes dos atributos para apresentação
    char *atributo_escolha1=NULL, *atributo_escolha2=NULL;
    char *resultado_opcao1=NULL, *resultado_opcao2=NULL;

    //Funcionalidade extra de reinicialização
    char reiniciar = 'n';

    //Cabeçalho de apresentação do programa
    printf("======================================================\n");
    printf("|           Bem-vindo ao Super Trunfo  1.2           |\n");
    printf("======================================================\n\n");
    
    printf("Escolha suas cartas e insira os valores\nde cada item conforme as instrucões a seguir:\n\n");

    printf("------------------------------------------------------\n");
    printf("  * Insira os valores de cada item da primeira carta. \n");
    printf("------------------------------------------------------\n\n");

    //Entrada de dados da Carta 1
    printf("Insira a letra MAIÚSCULA que representa o Estado\n(a parte alfabética de 'A' a 'H'):\n");
    scanf(" %c", &cod_estado1);
    printf("Insira o código da carta (ex.: 'A01' ou 'D04'):\n");
    scanf("%s", cod_carta1);
    printf("Insira o nome da cidade:\n");
    scanf(" %[^\n]", nome_cidade1);
    printf("Insira a quantidade da População:\n");
    scanf("%lu", &populacao1);
    printf("Insira o valor da Área (em Km²):\n");
    scanf("%f", &area1);
    printf("Insira o valor do PIB:\n");
    scanf("%f", &pib1);
    printf("Insira a quantidade de pontos turísticos:\n");
    scanf("%d", &pts_turisticos1);

    printf("\n======================================================\n");
    printf(" Parabéns! Você salvou todos dados da primeira carta!\n");
    printf("======================================================\n\n");

    printf("------------------------------------------------------\n");
    printf("  * Insira os valores de cada item da segunda carta.  \n");
    printf("------------------------------------------------------\n\n");

    //Entrada de dados da Carta 2
    printf("Insira a letra MAIÚSCULA que representa o Estado\n(a parte alfabética de 'A' a 'H'):\n");
    scanf(" %c", &cod_estado2);
    printf("Insira o código da carta (ex.: 'A01' ou 'D04'):\n");
    scanf("%s", cod_carta2);
    printf("Insira o nome da cidade:\n");
    scanf(" %[^\n]", nome_cidade2);
    printf("Insira a quantidade da População:\n");
    scanf("%lu", &populacao2);
    printf("Insira o valor da área (em Km²):\n");
    scanf("%f", &area2);
    printf("Insira o valor do PIB:\n");
    scanf("%f", &pib2);
    printf("Insira a quantidade de pontos turísticos:\n");
    scanf("%d", &pts_turisticos2);

    printf("\n======================================================\n");
    printf(" Parabéns! Você salvou todos dados da segunda carta! \n");
    printf("======================================================\n\n");

    //Processando os dados da Carta 1: cálculo do PIB per capta, densidade populacional e super poder
    densidade_pop1 = (double) populacao1 / area1;
    pib_capta1  = (double) (pib1 * 1000000000) / populacao1; //multiplica por um bilhão (6 bi -> 6000000000)
    super1 = (double) (1/densidade_pop1) + populacao1 + area1 + pib1 + pts_turisticos1 + pib_capta1;

    //Processando os dados da Carta 2: cálculo do PIB per capta, densidade populacional e super poder
    densidade_pop2 = (double) populacao2 / area2;
    pib_capta2 = (double) (pib2 * 1000000000) / populacao2;
    super2 = (double) (1/densidade_pop2) + populacao2 + area2 + pib2 + pts_turisticos2 + pib_capta2;

    //Menu Jogador 1
    printf("\n======================================================\n");
    printf("Escolha o primeiro atributo que irá usar na batalha:\n");
    printf("======================================================\n\n");

    printf("Carta - JOGADOR:\n\n");
    printf("Estado: %c  |  Código da carta: %s  |  Nome da cidade: %s\n\n", cod_estado1, cod_carta1, nome_cidade1);

    printf("    1. População: %lu\n", populacao1);
    printf("    2. Área: %.2f km²\n", area1);
    printf("    3. PIB: %.2f bilhões de reais\n", pib1);
    printf("    4. Número de pontos turísticos: %d\n", pts_turisticos1);
    printf("    5. Densidade Demográfica: %.2f hab/km²\n", densidade_pop1);
    printf("    6. PIB per Capta: %.2f reais\n", pib_capta1);
    printf("    7. Super Poder: %.2f\n\n", super1);

    printf("Insira o número do atributo que deseja usar (de 1 a 7):   ");
    scanf("%d", &escolha_jogador_1);
    printf("\n\n");
    if (escolha_jogador_1 < 1 || escolha_jogador_1 > 7) {
        printf("Erro: Você NÃO escolheu um número entre 1 e 7!\n");
        printf("Insira o número VÁLIDO ou o jogo será encerrado:    ");
        scanf("%d", &escolha_jogador_1);
    }
    printf("______________________________________________________\n\n");

    //Menu escolha atributo 2
    printf("\n======================================================\n");
    printf("Escolha o segundo atributo que irá usar na batalha:\n");
    printf("======================================================\n\n");

    printf("Carta - JOGADOR:\n\n");
    printf("Estado: %c  |  Código da carta: %s  |  Nome da cidade: %s\n\n", cod_estado1, cod_carta1, nome_cidade1);
    
    //Só mostra as opções válidas para serem escolhidas, excluindo a que já foi selecionada.
    if (escolha_jogador_1 != 1) printf("    1. População: %lu\n", populacao1);
    if (escolha_jogador_1 != 2) printf("    2. Área: %.2f km²\n", area1);
    if (escolha_jogador_1 != 3) printf("    3. PIB: %.2f bilhões de reais\n", pib1);
    if (escolha_jogador_1 != 4) printf("    4. Número de pontos turísticos: %d\n", pts_turisticos1);
    if (escolha_jogador_1 != 5) printf("    5. Densidade Demográfica: %.2f hab/km²\n", densidade_pop1);
    if (escolha_jogador_1 != 6) printf("    6. PIB per Capta: %.2f reais\n", pib_capta1);
    if (escolha_jogador_1 != 7) printf("    7. Super Poder: %.2f\n\n", super1);

    printf("Insira o número do segundo atributo que deseja usar (de 1 a 7):   ");
    scanf("%d", &escolha_jogador_2);
    printf("\n\n");
    printf("______________________________________________________\n\n");

    if (escolha_jogador_1 == escolha_jogador_2) {
        printf("Erro: Você NÃO pode escolher o mesmo atributo duas vezes!\n");
        printf("Insira o número de um atributo DIFERENTE ou o jogo será encerrado:    ");
        scanf("%d", &escolha_jogador_2);
        if (escolha_jogador_2 == escolha_jogador_1) return 0;
    } else if (escolha_jogador_2 < 1 || escolha_jogador_2 > 7) {
        printf("Erro: Você NÃO escolheu um número entre 1 e 7!\n");
        printf("Insira o número VÁLIDO ou o jogo será encerrado:    ");
        scanf("%d", &escolha_jogador_2);
    }
    
    //Menu Carta PC:
    printf("\n======================================================\n");
    printf("           Revelando atributos da Carta PC:           \n");
    printf("======================================================\n\n");
    printf("Carta - PC:\n\n");
    printf("Estado: %c  |  Código da carta: %s  |  Nome da cidade: %s\n\n", cod_estado2, cod_carta2, nome_cidade2);

    printf("    1. População: %lu\n", populacao2);
    printf("    2. Área: %.2f km²\n", area2);
    printf("    3. PIB: %.2f bilhões de reais\n", pib2);
    printf("    4. Número de pontos turísticos: %d\n", pts_turisticos2);
    printf("    5. Densidade Demográfica: %.2f hab/km²\n", densidade_pop2);
    printf("    6. PIB per Capta: %.2f reais\n", pib_capta2);
    printf("    7. Super Poder: %.2f", super2);
    printf("\n\n______________________________________________________\n\n");

    //-----------------------------------INÍCIO DA LÓGICA DE COMPARAÇÃO DOS ATRIBUTOS--------------------------------------------

    //Definindo a escolha do primeiro atributo
    switch (escolha_jogador_1)
    {
    case 1:
        atributo_escolha1 = "POPULAÇÃO";
        jogador_atributo1 = (double)populacao1;
        pc_atributo1 = (double)populacao2;
        break;
    case 2:
        atributo_escolha1 = "ÁREA";
        jogador_atributo1 = area1;
        pc_atributo1 = area2;
        break;
    case 3:
        atributo_escolha1 = "PIB";
        jogador_atributo1 = pib1;
        pc_atributo1 = pib2;
        break;
    case 4:
        atributo_escolha1 = "PONTOS TURÍSTICOS";
        jogador_atributo1 = (double)pts_turisticos1;
        pc_atributo1 = (double)pts_turisticos2;
        break;
    case 5:
        atributo_escolha1 = "DENSIDADE DEMOGRÁFICA";
        jogador_atributo1 = -densidade_pop1; //Deixei esse atributo negativo para inverter a lógica e fazer o menor número ganhar
        pc_atributo1 = -densidade_pop2;
        break;
    case 6:
        atributo_escolha1 = "PIB PER CAPTA";
        jogador_atributo1 = pib_capta1;
        pc_atributo1 = pib_capta2;
        break;
    case 7:
        atributo_escolha1 = "SUPER PODER";
        jogador_atributo1 = super1;
        pc_atributo1 = super2;
        break;
    default:
        return 0;
    }

    //Definindo a escolha do segundo atributo
    switch (escolha_jogador_2)
    {
    case 1:
        atributo_escolha2 = "POPULAÇÃO";
        jogador_atributo2 = (double)populacao1;
        pc_atributo2 = (double)populacao2;
        break;
    case 2:
        atributo_escolha2 = "ÁREA";
        jogador_atributo2 = area1;
        pc_atributo2 = area2;
        break;
    case 3:
        atributo_escolha2 = "PIB";
        jogador_atributo2 = pib1;
        pc_atributo2 = pib2;
        break;
    case 4:
        atributo_escolha2 = "PONTOS TURÍSTICOS";
        jogador_atributo2 = (double)pts_turisticos1;
        pc_atributo2 = (double)pts_turisticos2;
        break;
    case 5:
        atributo_escolha2 = "DENSIDADE DEMOGRÁFICA";
        jogador_atributo2 = -densidade_pop1; //Deixei esse atributo negativo para inverter a lógica e fazer o menor número ganhar
        pc_atributo2 = -densidade_pop2;
        break;
    case 6:
        atributo_escolha2 = "PIB PER CAPTA";
        jogador_atributo2 = pib_capta1;
        pc_atributo2 = pib_capta2;
        break;
    case 7:
        atributo_escolha2 = "SUPER PODER";
        jogador_atributo2 = super1;
        pc_atributo2 = super2;
        break;
    default:
        return 0;
    }

    //Exibição dos atributos escolhidos para comparação:
    
    //Calcula previamente as somas e guarda na memória
    double soma_jogador = jogador_atributo1 + jogador_atributo2;
    double soma_pc = pc_atributo1 + pc_atributo2;

    //Calcula o módulo dos valores dos atributos para apresentação
    //(necessário por conta da inversão da lógica na Densidade Demográfica)
    double mod_jogador_atributo1 = jogador_atributo1 < 0 ? -jogador_atributo1 : jogador_atributo1;
    double mod_jogador_atributo2 = jogador_atributo2 < 0 ? -jogador_atributo2 : jogador_atributo2;
    double mod_pc_atributo1 = pc_atributo1 < 0 ? -pc_atributo1 : pc_atributo1;
    double mod_pc_atributo2 = pc_atributo2 < 0 ? -pc_atributo2 : pc_atributo2;

    printf("------------------------------------------------------\n");
    printf("   Comparação de 2 atributos!!             \n");
    printf("   Atributo 1 %s | Atributo 2 %s:           \n", atributo_escolha1, atributo_escolha2);
    printf("------------------------------------------------------\n\n");
    
    //Imprime atributos Escolha do Jogador
    printf("------------------------------------------------------\n");
    printf("O Jogador vai disputar com a cidade de %s!\n", nome_cidade1);
    printf("------------------------------------------------------\n\n");
    printf("O Jogador escolheu os atributos:\n%s = %.2f e %s = %.2f!!!\n", atributo_escolha1, mod_jogador_atributo1, atributo_escolha2, mod_jogador_atributo2);
    printf("A soma dos atributos é: %.2f\n\n", soma_jogador);
    
    //Imprime atributos do PC
    printf("------------------------------------------------------\n");
    printf("O PC vai disputar com a cidade de %s!\n", nome_cidade2);
    printf("------------------------------------------------------\n\n");
    printf("Os valores dos atributos da carta do PC são:\n%s = %.2f e %s = %.2f!!!\n", atributo_escolha1, mod_pc_atributo1, atributo_escolha2, mod_pc_atributo2);
    printf("A soma dos atributos é: %.2f\n\n", soma_pc);

    //Lógica da comparação primeiro atributo
    printf("------------------------------------------------------\n");
    printf("Disputa do atributo %s:\n\nJogador = %.2f Vs. PC = %.2f:\n\n", atributo_escolha1, mod_jogador_atributo1, mod_pc_atributo1);
    printf("------------------------------------------------------\n\n");
    if (jogador_atributo1 == pc_atributo1) {
        printf("    Empate!\n\n");
    } else if (jogador_atributo1 > pc_atributo1) {
        printf("    Vitória do jogador!\n\n");
        pontos_jogador++;
    } else {
        printf("    Vitória do PC!\n\n");
        pontos_pc++;
    }

    //Lógica da comparação segundo atributo
    printf("------------------------------------------------------\n");    
    printf("Disputa do atributo %s:\n\nJogador = %.2f Vs. PC = %.2f:\n\n", atributo_escolha2, mod_jogador_atributo2, mod_pc_atributo2);
    printf("------------------------------------------------------\n");

    if (jogador_atributo2 == pc_atributo2) {
        printf("    Empate!\n\n");
    } else if (jogador_atributo2 > pc_atributo2) {
        printf("    Vitória do jogador!\n\n");
        pontos_jogador++;
    } else {
        printf("    Vitória do PC!\n\n");
        pontos_pc++;
    }

    //Lógica da comparação das somas SE houver empate
    if (pontos_jogador == pontos_pc) {
        printf("------------------------------------------------------\n");
        printf("Jogador e PC estão empatados e vão pra melhor-de-três!!!!\n\n\n");
        printf("------------------------------------------------------\n");
        printf("DESEMPATE: Disputa da soma dos atributos:\n\n!!!!!%s + %s!!!!!\n\nSOMA do Jogador = %.2f Vs. SOMA do PC = %.2f:\n\n", atributo_escolha1, atributo_escolha2, soma_jogador, soma_pc);
        printf("\n======================================================\n");
        if (soma_jogador == soma_pc) {
            printf("    Empate!    Ninguém ganha o jogo!!!\n\n");
        } else if (soma_jogador > soma_pc) {
            printf("    Vitória do jogador!!!!!!!\n    O jogador venceu no desempate!!!");
        } else {
            printf("    Vitória do PC!\n    A máquina venceu no desempate!!!\n");
        }
    } else if (pontos_jogador > pontos_pc) {
        printf("    Nem precisou de desempate!!!!!!!\n    O jogador venceu o jogo!!!\n");
    } else {
        printf("    Nem precisou de desempate!!!!!!!\n    A máquina ganhou o jogo!!!\n");
    }
        printf("======================================================\n");
    
    printf("\n\n______________________________________________________\n\n");

    printf("FIM DA DISPUTA!!\n\n");

        return 0;
}