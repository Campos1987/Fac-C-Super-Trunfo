// deck.c
#include "../deck/deck.h"
#include "../start/header.h"
#include <stdio.h>
#include <string.h>

double calculateDensity(Card *card) { return card->population / card->area; }

double calculatePIB(Card *card) {
  return card->pib * 1000000000.0 / card->population;
}

double calculateSuperTrunfo(Card *card) {
  return ((float)card->population + card->area + (card->pib * 1000000000.0) +
          (float)card->turistic + card->density) -
         card->pibPerCapita;
}

void creatCard(Card *card) {

  char state[2];
  char city[100];
  int population;
  float area;
  float pib;
  int turistic;

  header();

  printf("Estado (A-H): ");
  scanf(" %1s", state);

  printf("Nome da Cidade: ");
  scanf(" %99[^\n]", city);

  printf("Qual o tamanho da populacao? ");
  scanf(" %d", &population);

  printf("Qual o tamanho da area? (Km²) ");
  scanf(" %f", &area);

  printf("Qual o tamanho do PIB? (Bilhoes) ");
  scanf(" %f", &pib);

  printf("Qual o tamanho do turistico? ");
  scanf(" %d", &turistic);

  strcpy(card->state, state);
  strcpy(card->city, city);
  card->population = population;
  card->area = area;
  card->pib = pib;
  card->turistic = turistic;
  card->density = calculateDensity(card);
  card->pibPerCapita = calculatePIB(card);
  card->superTrunfo = calculateSuperTrunfo(card);
}

void cardInfo(Card *card) {
  printf("Estado: %s\n", card->state);
  printf("Código: %s%d\n", card->state, card->cod);
  printf("Cidade: %s\n", card->city);
  printf("Populacao: %d\n", card->population);
  printf("Area: %.2f Km²\n", card->area);
  printf("PIB: %.2f bilhoes de reais\n", card->pib);
  printf("Número de pontos turísticos: %d\n", card->turistic);
  printf("Densidade Populacional: %.2f hab/km²\n", card->density);
  printf("PIB per capita: %.2f reais\n", card->pibPerCapita);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  printf("Super Trunfo: %.2f\n", card->superTrunfo);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}

void displayCards(Card *cards) {
  cardInfo(cards);
  printf("\n");
}
