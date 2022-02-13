# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <string.h>

int getIndex(char letter)
{
  int index;
  switch (letter)
  {
    case '1': index = 0; break;
    case '2': index = 2; break;
    case '3': index = 4; break;
    case '4': index = 6; break;
    case '5': index = 8; break;
    case '6': index = 10; break;
    case '7': index = 12; break;
    case '8': index = 14; break;
    case '9': index = 16; break;
    case '0': index = 18; break;
    case 'a': index = 20; break;
    case 'z': index = 22; break;
    case 'e': index = 24; break;
    case 'r': index = 26; break;
    case 't': index = 28; break;
    case 'y': index = 30; break;
    case 'u': index = 32; break;
    case 'i': index = 34; break;
    case 'o': index = 36; break;
    case 'p': index = 38; break;
    case 'q': index = 40; break;
    case 's': index = 42; break;
    case 'd': index = 44; break;
    case 'f': index = 46; break;
    case 'g': index = 48; break;
    case 'h': index = 50; break;
    case 'j': index = 52; break;
    case 'k': index = 54; break;
    case 'l': index = 56; break;
    case 'm': index = 58; break;
    case 'w': index = 63; break;
    case 'x': index = 65; break;
    case 'c': index = 67; break;
    case 'v': index = 69; break;
    case 'b': index = 71; break;
    case 'n': index = 73; break;
    case 'A': index = 20; break;
    case 'Z': index = 22; break;
    case 'E': index = 24; break;
    case 'R': index = 26; break;
    case 'T': index = 28; break;
    case 'Y': index = 30; break;
    case 'U': index = 32; break;
    case 'I': index = 34; break;
    case 'O': index = 36; break;
    case 'P': index = 38; break;
    case 'Q': index = 40; break;
    case 'S': index = 42; break;
    case 'D': index = 44; break;
    case 'F': index = 46; break;
    case 'G': index = 48; break;
    case 'H': index = 50; break;
    case 'J': index = 52; break;
    case 'K': index = 54; break;
    case 'L': index = 56; break;
    case 'M': index = 58; break;
    case 'W': index = 63; break;
    case 'X': index = 65; break;
    case 'C': index = 67; break;
    case 'V': index = 69; break;
    case 'B': index = 71; break;
    case 'N': index = 73; break;
    case '.': index = 77; break;
    default: index = 100;
  }
  return index;
}

int main(void)
{
  FILE* file;
  file = fopen("input", "r");
  char word[50];
  int i = 0, i1, i2, y;
  float x, diff = 0.0, min_diff = 1000000;

  if (NULL == file)
  {
    printf("File doesn't exist\n");
    return 0;
  }

  while (fgets(word, 50, file) != NULL)
  {

    diff = 0.0;
    i = 0;
    while (1)
    {
      i1 = getIndex(word[i]);
      i2 = getIndex(word[i+1]);
      if (i2 == 100)
      {
        if (diff <= min_diff)
        {
          min_diff = diff;
          printf("%s~%f\n", word, diff);
        }
        break;
      }
      x = (i1 % 20 - i2 % 20) / 2.0;
      y = (i1 / 20 - i2 / 20);
      diff += sqrt((x * x) + (y * y));
//      printf("%c - %c > %f\n", word[i], word[i+1], diff);
      i++;
    }

  }

  printf("\nDone.\n");
  fclose(file);
  return 0;
}
