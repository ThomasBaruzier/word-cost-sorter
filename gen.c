# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int main(int argc, char *argv[])
{
  if (argc <= 1)
  {
    printf("Missing length argument\n");
    exit(1);
  }
  int random, pos, length = atoi(argv[1]);
  int arrSize = 8200000 - ((length + 1) % 8200000);
  int repeat = arrSize / (length + 1);
  char caracter[arrSize + 1];
  srand(time(NULL));

  for (int times = 0; times < 1; times++)
  {
    pos = 0;
    for (int i = 0; i < repeat; i++)
    {
      for (int j = 0; j < length; j++)
      {
        random = rand() % 62;
        switch (random)
        {
          case 0: caracter[pos] = '0'; break;
          case 1: caracter[pos] = '1'; break;
          case 2: caracter[pos] = '2'; break;
          case 3: caracter[pos] = '3'; break;
          case 4: caracter[pos] = '4'; break;
          case 5: caracter[pos] = '5'; break;
          case 6: caracter[pos] = '6'; break;
          case 7: caracter[pos] = '7'; break;
          case 8: caracter[pos] = '8'; break;
          case 9: caracter[pos] = '9'; break;
          case 10: caracter[pos] = 'a'; break;
          case 11: caracter[pos] = 'z'; break;
          case 12: caracter[pos] = 'e'; break;
          case 13: caracter[pos] = 'r'; break;
          case 14: caracter[pos] = 't'; break;
          case 15: caracter[pos] = 'y'; break;
          case 16: caracter[pos] = 'u'; break;
          case 17: caracter[pos] = 'i'; break;
          case 18: caracter[pos] = 'o'; break;
          case 19: caracter[pos] = 'p'; break;
          case 20: caracter[pos] = 'q'; break;
          case 21: caracter[pos] = 's'; break;
          case 22: caracter[pos] = 'd'; break;
          case 23: caracter[pos] = 'f'; break;
          case 24: caracter[pos] = 'g'; break;
          case 25: caracter[pos] = 'h'; break;
          case 26: caracter[pos] = 'j'; break;
          case 27: caracter[pos] = 'k'; break;
          case 28: caracter[pos] = 'l'; break;
          case 29: caracter[pos] = 'm'; break;
          case 30: caracter[pos] = 'w'; break;
          case 31: caracter[pos] = 'x'; break;
          case 32: caracter[pos] = 'c'; break;
          case 33: caracter[pos] = 'v'; break;
          case 34: caracter[pos] = 'b'; break;
          case 35: caracter[pos] = 'n'; break;
          case 36: caracter[pos] = 'A'; break;
          case 37: caracter[pos] = 'Z'; break;
          case 38: caracter[pos] = 'E'; break;
          case 39: caracter[pos] = 'R'; break;
          case 40: caracter[pos] = 'T'; break;
          case 41: caracter[pos] = 'Y'; break;
          case 42: caracter[pos] = 'U'; break;
          case 43: caracter[pos] = 'I'; break;
          case 44: caracter[pos] = 'O'; break;
          case 45: caracter[pos] = 'P'; break;
          case 46: caracter[pos] = 'Q'; break;
          case 47: caracter[pos] = 'S'; break;
          case 48: caracter[pos] = 'D'; break;
          case 49: caracter[pos] = 'F'; break;
          case 50: caracter[pos] = 'G'; break;
          case 51: caracter[pos] = 'H'; break;
          case 52: caracter[pos] = 'J'; break;
          case 53: caracter[pos] = 'K'; break;
          case 54: caracter[pos] = 'L'; break;
          case 55: caracter[pos] = 'M'; break;
          case 56: caracter[pos] = 'W'; break;
          case 57: caracter[pos] = 'X'; break;
          case 58: caracter[pos] = 'C'; break;
          case 59: caracter[pos] = 'V'; break;
          case 60: caracter[pos] = 'B'; break;
          case 61: caracter[pos] = 'N'; break;
        }
        pos++;
      }
      caracter[pos] = '\n';
      pos++;
    }
    caracter[pos-1] = '\0';
    printf("%s\n", caracter);
  }
}
