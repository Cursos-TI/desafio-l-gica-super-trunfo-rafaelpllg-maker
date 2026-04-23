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
    char cod_estado1= 'a', cod_estado2= 'a';            //Variáveis com valores de "A" a "H" para os Estados
    char cod_carta1[4], cod_carta2[4];                  //Variáveis com valores de "01" a "04" para as cidades
    char nome_cidade1[50], nome_cidade2[50];            //Nome da cidade
    unsigned long int populacao1= 0, populacao2 = 0;    //Variáveis com a população
    int pts_turisticos1 = 0, pts_turisticos2 = 0;       //Variáveis com os pontos turísticos
    float pib1 = 0, pib2 = 0;                           //Variáveis com o PIB
    float area1 = 0, area2 = 0;                         //Variáveis com área
    double densidade_pop1 = 0, densidade_pop2 = 0;      //Variável calculada: populacao/area
    double pib_capta1 = 0, pib_capta2 = 0;              //variável calculada: pib/populacao
    double bilhao = 1000000000;                          //Transforma a notação do PIB de bilhões de reais para unidades de real (ex.: 600 bi para 600.000.000.000)
    double super1, super2 = 0;                          //Variável calculada: o 'super poder' da carta com a soma do inverso da densidade com todos os outros atributos da carta
    int compara_pop, compara_area, compara_pib, compara_tur, compara_dens, compara_pcap, compara_sup = 0;   //Variáveis de comparação das cartas

    //Cabeçalho de apresentação do programa
    printf("======================================================\n");
    printf("|           Bem-vindo ao Super Trunfo  1.0           |\n");
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
    printf("  Parabéns! Você salvou todos dados da segunda carta!\n");
    printf("======================================================\n\n");

    //Processando os dados da Carta 1: cálculo do PIB per capta, densidade populacional e super poder
    densidade_pop1 = (double) populacao1 / area1;
    pib_capta1  = (double) (pib1 * bilhao) / populacao1;
    super1 = (double) (1/densidade_pop1) + populacao1 + area1 + pib1 + pts_turisticos1 + pib_capta1;

    //Processando os dados da Carta 2: cálculo do PIB per capta, densidade populacional e super poder
    densidade_pop2 = (double) populacao2 / area2;
    pib_capta2 = (double) (pib2 * bilhao) / populacao2;
    super2 = (double) (1/densidade_pop2) + populacao2 + area2 + pib2 + pts_turisticos2 + pib_capta2;

    //Saída de dados para as cartas 1 e 2
    printf("\n======================================================\n");
    printf("  Imprimindo na tela os dados salvos das duas cartas  \n");
    printf("======================================================\n\n");

    printf("Carta: 1\n\nEstado: %c\nCódigo da carta: %s\nNome da cidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\nNúmero de pontos turísticos: %d\n", cod_estado1, cod_carta1, nome_cidade1, populacao1, area1, pib1, pts_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per Capta: %.2f reais\nSuper Poder: %.2f", densidade_pop1, pib_capta1, super1);
    printf("\n\n");
    printf("Carta: 2\n\nEstado: %c\nCódigo da carta: %s\nNome da cidade: %s\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões de reais\nNúmero de pontos turísticos: %d\n", cod_estado2, cod_carta2, nome_cidade2, populacao2, area2, pib2, pts_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\nPIB per Capta: %.2f reais\nSuper Poder: %.2f", densidade_pop2, pib_capta2, super2);
    printf("\n\n");

    printf("______________________________________________________\n\n");

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    /*
    Processando os dados: sistema de comparação entre os atributos das cartas:

    OBS.: Para as comparações foi necessário resolver o problema dos casos de empate:
    Ambas as comparações "a > b" e "a < b" retornam 0 quando a == b, o que daria vantagem
    à carta 2 na disputa.

    Para respeitar os limites Nível Novato (não usar 'else if'), a solução pensada foi
    usar as propriedades de 1 e 0 como números inteiros e empregar operadores aritméticos.
    
    Dessa forma, a ideia foi subtrair duas comparações, da seguinte forma:

    comparacao = (a > b) - (a < b)

    assim, a variável 'comparacao' pode rebecer 3 valores, e não apenas 2:
    
     1  - para pontuação da carta 1
    -1  - para a carta 2
     0  - para empate
    
    Deste modo é possível já implementar um tratamento para o empate sem usar o 'else if'
    usando uma sequência simples de condicionais 'if'.
    */
    compara_pop = (populacao1 > populacao2) - (populacao1 < populacao2);
    compara_area = (area1 > area2) - (area1 < area2);
    compara_pib = (pib1 > pib2) - (pib1 < pib2);
    compara_tur = (pts_turisticos1 > pts_turisticos2) - (pts_turisticos1 < pts_turisticos2);
    compara_dens = (densidade_pop1 < densidade_pop2) - (densidade_pop1 > densidade_pop2);
    compara_pcap = (pib_capta1 > pib_capta2) - (pib_capta1 < pib_capta2);
    compara_sup = (super1 > super2) - (super1 < super2);

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    //Saída dos dados da comparação das cartas:
    printf("------------------------------------------------------\n");
    printf("           Comparação | Atributo POPULAÇÃO:           \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %lu\n", nome_cidade1, populacao1);
    printf("Carta 2 - %s : %lu\n", nome_cidade2, populacao2);
    if (compara_pop == 0) {
        printf("Empate!\n\n");
    };
    if (compara_pop == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_pop == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("              Comparação | Atributo ÁREA:             \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %.2f\n", nome_cidade1, area1);
    printf("Carta 2 - %s : %.2f\n", nome_cidade2, area2);
    if (compara_area == 0) {
        printf("Empate!\n\n");
    };
    if (compara_area == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_area == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("              Comparação | Atributo PIB:              \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %.2f\n", nome_cidade1, pib1);
    printf("Carta 2 - %s : %.2f\n", nome_cidade2, pib2);
    if (compara_pib == 0) {
        printf("Empate!\n\n");
    };
    if (compara_pib == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_pib == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("       Comparação | Atributo PONTOS TURÍSTICOS:       \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %d\n", nome_cidade1, pts_turisticos1);
    printf("Carta 2 - %s : %d\n", nome_cidade2, pts_turisticos2);
    if (compara_tur == 0) {
        printf("Empate!\n\n");
    };
    if (compara_tur == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_tur == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("     Comparação | Atributo DENSIDADE DEMOGRÁFICA:     \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %.2f\n", nome_cidade1, densidade_pop1);
    printf("Carta 2 - %s : %.2f\n", nome_cidade2, densidade_pop2);
    if (compara_dens == 0) {
        printf("Empate!\n\n");
    };
    if (compara_dens == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_dens == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("         Comparação | Atributo PIB PER CAPTA:         \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %.2f\n", nome_cidade1, pib_capta1);
    printf("Carta 2 - %s : %.2f\n", nome_cidade2, pib_capta2);
    if (compara_pcap == 0) {
        printf("Empate!\n\n");
    };
    if (compara_pcap == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_pcap == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("------------------------------------------------------\n");
    printf("          Comparação | Atributo SUPER PODER:          \n");
    printf("------------------------------------------------------\n\n");
    printf("Carta 1 - %s : %.2f\n", nome_cidade1, super1);
    printf("Carta 2 - %s : %.2f\n", nome_cidade2, super2);
    if (compara_sup == 0) {
        printf("Empate!\n\n");
    };
    if (compara_sup == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n\n", nome_cidade1);
    };
    if (compara_sup == -1) {
        printf("Resultado: Carta 2 (%s) venceu!\n\n", nome_cidade2);
    };

    printf("FIM DA DISPUTA!!\n\n");

    return 0;
}
