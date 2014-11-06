int hash(char text[]) {
  int cur = 0;
  int acc = 0;
  while(text[cur] != '\0') {
    acc += text[cur];
    cur++;
  }
  return acc % (2*N);
}
