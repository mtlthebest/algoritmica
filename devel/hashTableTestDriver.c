#include <stdio.h>
#include <stdlib.h>

// definizione costanti e variabili globali
#define MAX_LEN 100
int N = 5;

// definizione strutture dati
struct oggetto {struct oggetto *prev; char nome[MAX_LEN + 1]; int valore; struct oggetto *next;};

// definizione funzioni
#include "libHashFunction.h"
#include "libNuovaTabellaHash.h"
struct oggetto** NuovaTabellaHash();

int main() {
  struct oggetto **ht = NuovaTabellaHash();
  struct oggetto tv = {NULL, "Televisore", 499, NULL};
  ht[1] = &tv;
  printf("Oggetto: %s, valore: %i\n", ht[1]->nome, ht[1]->valore);
  return 0;
}

int Ricerca(struct oggetto** tab, struct oggetto* item) {
}

int Appartiene(struct oggetto** tab, struct oggetto* item) {
  int indice = hash(item->nome);
  if (tab[indice] == NULL) return 0;
  else {
    struct oggetto *cursore = tab[indice];
    while(cursore != NULL) {
      if (strcmp(cursore->nome, item->nome) == 0) return 1;
      cursore = cursore->next;
    } // end while
  } // end else
  return 0;
}

void Inserisci(struct oggetto** tab, struct oggetto* item) {

  int h = hash(item->nome);

  // nuovo oggetto
  if (!Appartiene(tab, item)) {
    if (tab[h] == NULL) // primo oggetto
      tab[h] = item;
    else { // modifico la lista di trabocco
      item->next = tab[h]; // punto al secondo
      tab[h] = item;
      item->next->prev = item; // doppio collegamento
    }
  printf("%s - %i\n", item->nome, item->valore);
  }
  else {
    struct oggetto *cursore = tab[h];
    while(cursore != NULL) {
      if (strcmp(cursore->nome, item->nome) == 0)
        if (cursore->valore < item->valore); // aggiorno
          cursore->valore = item->valore;
      cursore = cursore->next;
    } // end while
  } // end else
}

void Cancella(struct oggetto* primoItem) {

}
