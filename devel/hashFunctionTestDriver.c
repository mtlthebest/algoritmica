#include <stdio.h>

int hash(char*);
int N = 5; // variabile globale

int main() {

  // Init
  char parola[] = "Ciao!";
  printf("+-----------+-----------------+\n");
  printf("| Carattere | Codice decimale |\n");
  printf("+-----------+-----------------+\n");

  // Stampo a video ogni carattere e il relativo codice decimale
  int i;
  for (i = 0; i < sizeof(parola)/sizeof(char) - 1; i++) {
    printf("|     %c     | ", parola[i]);
    printf("       %i      ");
    if (parola[i] < 100) printf(" ");
    printf("|\n", parola[i]);
  }
  printf("+-----------+-----------------+\n");

  // Stampo a video la formula:
  printf("%i ", parola[0]);
  int acc = parola[0];
  for (i = 1; i < sizeof(parola)/sizeof(char) - 1; i++) {
    acc += parola[i];
    printf("+ %i ", parola[i]);
  }
  printf("= %i, 2N = %i\n", acc, 2*N);

  // Ultima stampa
  printf("hash(\"%s\") = %i %% %i = %i\n", parola, acc, 2*N, 
hash(parola));

  // End main
  return 0;
}

int hash(char nomeOggetto[]) {
  int cur = 0;
  int accumulatore = 0;
  while(nomeOggetto[cur] != '\0') {
    accumulatore += nomeOggetto[cur];
    cur++;
  }
  printf("Accumulatore hash:: %i\n", accumulatore);
  int result = accumulatore % (2*N);
  return result;
}
