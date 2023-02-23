# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main(int argc, char *argv[])
{
  // argument checking
  if (argc != 4) {
    printf("Usage : %s <filename> <string length> <number of lines>\n", argv[0]);
    exit(1);
  }

  // vars
  srand(time(NULL));
  int random, pos;
  int length = atoi(argv[2]);
  int lines = atoi(argv[3]);
  char line[length];
  char dict[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'z', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'q', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'w', 'x', 'c', 'v', 'b', 'n', 'A', 'Z', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'Q', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'W', 'X', 'C', 'V', 'B', 'N'};

  // file
  FILE *file;
  file = fopen(argv[1], "w");
  if (file == NULL) {
    printf("Error opening %s!\n", argv[1]);
    return 1;
  }

  // random string generation
  for (int i = 0; i < lines; i++) {
    pos = 0;
    for (int j = 0; j < length; j++) {
      random = rand() % 62;
      line[pos] = dict[random];
      pos++;
    }
    line[pos] = '\0';
    fprintf(file, "%s\n", line);
  }

  // cleaning
  fclose(file);
  return 0;
}
