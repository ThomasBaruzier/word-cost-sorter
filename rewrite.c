# include <stdio.h>
# include <stdlib.h>
# include <math.h>

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

int main (void)
{
  FILE *file;
  int ch1, ch2, x, y, pos;
  float diff, min_diff = 1000000;
  char line[1000];
  file = fopen("input", "r");
  if (file == NULL) { return 0; }
  while (fgets (line, 1000, file) != NULL)
  {
    pos = 0;
    diff = 0.0;
    while (line[pos+1] != '\n')
    {
      ch1 = getIndex(line[pos]);
      ch2 = getIndex(line[pos+1]);
      if (ch2 == 100)
      {
        printf("Unsupported character: %c", line[pos]);
        return 0;
      }
      x = (ch1 % 20 - ch2 % 20) / 2.0;
      y = (ch1 / 20 - ch2 / 20);
      diff += sqrt((x * x) + (y * y));
      // printf("%c - %c > %f\n", line[pos], line[pos+1], diff);
      pos++;
    }
    if (diff <= min_diff)
    {
      pos = 0;
      min_diff = diff;
      printf("%f > ", diff);
      while (line[pos] != '\n')
      {
        printf("%c", line[pos]);
        pos++;
      }
      puts("");
    }
  }
  fclose(file);
  return 0;
}
