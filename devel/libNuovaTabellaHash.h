struct oggetto** NuovaTabellaHash() {
  struct oggetto** tab = malloc(2*N * sizeof(struct oggetto*));
  int i;
  for (i = 0; i < 2*N; i++)
    tab[i] = NULL;
  return tab;
}
