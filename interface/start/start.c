// start.c
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void playSolo() {
  system("clear");
  printf("1 - Montar Deck\n");
  printf("2 - Gerar Deck Aleatorio\n");

  int option;
  scanf(" %d", &option);

  if (option == 1) {
    int player;
    printf("Numero de cartas: ");
    scanf(" %d", &player);
  } else if (option == 2) {
  }
}

void startGame() {
  system("clear");
  printf("==================================\n");
  printf("========// SUPER TRUNFO //========\n");
  printf("==================================\n");
  printf("Selcione um mode de jogo\n");
  printf("1 - Solo\n");
  printf("2 - Multiplayer\n");
  printf("3 - Sair\n");

  int option;
  scanf(" %d", &option);

  if (option == 1) {
    playSolo();
  } else if (option == 2) {

  } else if (option == 3) {
  }
}