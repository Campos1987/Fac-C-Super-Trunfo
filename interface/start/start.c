// start.c
#include "../deck/deck.h"
#include "./header.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>

double getAttribute(Card *card, int option) {
  switch (option) {
  case 1:
    return (double)card->population;
  case 2:
    return (double)card->area;
  case 3:
    return (double)card->pib;
  case 4:
    return (double)card->turistic;
  case 5:
    return (double)card->density;
  case 6:
    return (double)card->pibPerCapita;
  default:
    return 0;
  }
}

// Retorna 0 para card1, 1 para card2, -1 para empate
int cardCompare(double c1, double c2, int isLowerBetter) {
  if (c1 == c2)
    return -1;
  if (isLowerBetter)
    return (c1 < c2) ? 0 : 1;
  return (c1 > c2) ? 0 : 1;
}

char *attributeName(int option) {
  switch (option) {
  case 1:
    return "População";
  case 2:
    return "Área";
  case 3:
    return "PIB";
  case 4:
    return "Pontos Turísticos";
  case 5:
    return "Densidade Populacional";
  case 6:
    return "PIB per capita";
  default:
    return "";
  }
}

void selectAttributes(int *selected) {

  const char *optionSelect[] = {"População",
                                "Area",
                                "PIB",
                                "Pontos Turísticos",
                                "Densidade Populacional",
                                "PIB per capita"};

  int count = 0;
  int totalOptions = sizeof(optionSelect) / sizeof(optionSelect[0]);
  // Inicializamos com 0 para garantir que a comparação funcione na primeira
  // rodada
  selected[0] = 0;
  selected[1] = 0;

  while (count < 2) {
    header();

    for (int i = 0; i < totalOptions; i++) {
      int numeroDaOpcao = i + 1; // 1, 2, 3, 4, 5, 6
      // Só imprime se o número desta opção for diferente do que já foi
      // escolhido
      if (numeroDaOpcao != selected[0]) {
        printf("%d - %s\n", numeroDaOpcao, optionSelect[i]);
      }
    }

    printf("\nEscolha o %dº atributo: ", count + 1);
    int input;
    scanf("%d", &input);

    // Validação
    if (input < 1 || input > 6) {
      printf("Opção inválida! Escolha entre 1 e 6.\n");
    } else if (count == 1 && input == selected[0]) {
      printf("Esse atributo já foi escolhido e deveria estar oculto! Tente "
             "outro.\n");
    } else {
      selected[count] = input;
      count++;
    }
  }
}

void displayResult(Card *cards, double c1_v1, double c1_v2, double c2_v1,
                   double c2_v2, int att1, int att2) {

  char *attName1 = attributeName(att1);
  char *attName2 = attributeName(att2);
  char resc1_v1[15], resc1_v2[15], resc2_v1[15], resc2_v2[15], resc1_total[15],
      resc2_total[15];
  double total_c1 = c1_v1 + c1_v2;
  double total_c2 = c2_v1 + c2_v2;

  header();

  printf("\n%s >>> Vs <<< %s\n", cards[0].city, cards[1].city);
  if (c1_v1 > c2_v1) {
    strcpy(resc1_v1, "(VENCEDOR)");
    strcpy(resc2_v1, "");
  } else if (c1_v1 == c2_v1) {
    strcpy(resc1_v1, "(EMPATE)");
    strcpy(resc2_v1, "(EMPATE)");
  } else {
    strcpy(resc1_v1, "");
    strcpy(resc2_v1, "(VENCEDOR)");
  }
  if (c1_v2 > c2_v2) {
    strcpy(resc1_v2, "(VENCEDOR)");
    strcpy(resc2_v2, "");
  } else if (c1_v2 == c2_v2) {
    strcpy(resc1_v2, "(EMPATE)");
    strcpy(resc2_v2, "(EMPATE)");
  } else {
    strcpy(resc1_v2, "");
    strcpy(resc2_v2, "(VENCEDOR)");
  }

  if (total_c1 > total_c2) {
    strcpy(resc1_total, "(VENCEDOR)");
    strcpy(resc2_total, "");
  } else if (total_c1 == total_c2) {
    strcpy(resc1_total, "(EMPATE)");
    strcpy(resc2_total, "(EMPATE)");
  } else {
    strcpy(resc1_total, "");
    strcpy(resc2_total, "(VENCEDOR)");
  }

  printf("Round 1: %s\n", attName1);
  printf("%s: %.2f %s\n", cards[0].city, c1_v1, resc1_v1);
  printf("%s: %.2f %s\n", cards[1].city, c2_v1, resc2_v1);

  printf("\nRound 2: %s\n", attName2);
  printf("%s: %.2f %s\n", cards[0].city, c1_v2, resc1_v2);
  printf("%s: %.2f %s\n", cards[1].city, c2_v2, resc2_v2);

  printf("\nRound 3: Total\n");
  printf("%s: %.2f %s\n", cards[0].city, total_c1, resc1_total);
  printf("%s: %.2f %s\n", cards[1].city, total_c2, resc2_total);
}

void startBattle(Card *cards) {
  printf("Iniciando Batalha!\n");

  int c1, c2;
  int lowerIsBetter = 0; // Por padrão, maior vence
  int result;
  int attributes[2]; // Array para guardar os dois números

  selectAttributes(attributes);

  // Fazemos as comparações
  double c1_v1 = getAttribute(&cards[0], attributes[0]);
  double c1_v2 = getAttribute(&cards[0], attributes[1]);

  double c2_v1 = getAttribute(&cards[1], attributes[0]);
  double c2_v2 = getAttribute(&cards[1], attributes[1]);

  displayResult(cards, c1_v1, c1_v2, c2_v1, c2_v2, attributes[0],
                attributes[1]);
}

void startGame() {
  header();

  Card card[2];

  for (int i = 0; i < TOTAL_CARD; i++) {
    printf("\n--- Criando Carta %d ---\n", i + 1);
    creatCard(&card[i]);
    card[i].cod = i + 1;
  }

  startBattle(card);

  /*
  header();
  for (int j = 0; j < TOTAL_CARD; j++) {
    printf("===\\ Carta %d \\===\n", j + 1);
    displayCards(&card[j]);
  }
    */
}