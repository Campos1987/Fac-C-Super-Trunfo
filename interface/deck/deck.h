// deck.h

#define TOTAL_CARD 2

typedef struct {
  char state[2];
  int cod;
  char city[100];
  int population;
  float area;
  float pib;
  int turistic;
  double density;
  double pibPerCapita;
  double superTrunfo;
} Card;

void creatCard(Card *card);
void displayCards(Card *card);