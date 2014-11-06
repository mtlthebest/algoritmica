#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

int N; // numero di oggetti da processare
struct oggetto {struct oggetto *prev; char nome[MAX_LEN + 1]; int valore; struct oggetto *next;};

void inserisci(struct oggetto**, struct oggetto*);
void eliminaRiga(struct oggetto*);
int hash(char*);
int cfrAlfa(const void*, const void*);

int main() {

  // 1.) Ricezione del numero di oggetti
  scanf("%i", &N);

  // 2.) Creazione tabella hash vuota con la giusta dimensione
  struct oggetto** tabella = malloc(2*N * sizeof(struct oggetto*));
  int index;
  for (index = 0; index < 2*N; index++)
    tabella[index] = NULL;

  // 3.) Ciclo: riempimento della tabella hash
  int i;
  char tempName[MAX_LEN + 1];
  int tempValue;
  for (i = 0; i < N; i++) {
    scanf("%s100", tempName);
    scanf("%i", &tempValue);

    struct oggetto* new = malloc(sizeof(struct oggetto));

    strcpy(new->nome, tempName);
    new->valore = tempValue;
    new->prev = NULL;
    new->next = NULL;

    inserisci(tabella, new);
  }

  // 4.) Ordinamento della tabella hash

  // creazione array di supporto
  struct oggetto** arraySupporto = malloc(2*N * sizeof(struct oggetto*));;
  for (index = 0; index < 2*N; index++)
    arraySupporto[index] = NULL;

  // scansione tabella e costruzione array
  int h = 0; // indice tabella
  index = 0; // indice arraySupporto
  struct oggetto *cur = NULL;

  while (h < 2*N) {
    if(tabella[h] != NULL) {
      cur = tabella[h];
      arraySupporto[index] = tabella[h]; // copia primo elemento
      while(cur->next != NULL) {
        arraySupporto[index] = cur;
        index++;
        cur = cur->next;
      } // end while
    } // end if
    h++;
  } // end while

  // applicazione ordinamento
  //qsort(arraySupporto, 2*N, sizeof(struct oggetto*), cfrAlfa); 

  //cfrAlfa da sistemare

  // 5.) Stampa a video
  int k;
  for (k = 0; k < 15; k++) {
    if (arraySupporto[k] == NULL)
      break;
    printf("%s\n", arraySupporto[k]->nome);
  } // end for

  // 6.) Deallocazione memoria dinamica
  for(i = 0; i < 2*N; i++)
    eliminaRiga(tabella[i]);
  free(tabella);

  // 7.) End main
  return 0;
}

int contiene(struct oggetto** tab, struct oggetto* item) {
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

void inserisci(struct oggetto** tab, struct oggetto* item) {

  int h = hash(item->nome);

  // nuovo oggetto
  if (!contiene(tab, item)) {
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

void eliminaRiga(struct oggetto* primoItem) {

}

int hash(char nomeOggetto[]) {
  int cur = 0;
  int accumulatore = 0;
  while(nomeOggetto[cur] != '\0') {
    accumulatore += nomeOggetto[cur];
    cur++;
  }
  return accumulatore % 2*N;
}
/*
int cfrAlfa(const void* el1, const void* el2) {
  char* p1 = (struct oggetto**) el1;
  char* p2 = (struct oggetto**) el2;
  return strcmp(p1->nome, p2->nome);
}
*/


