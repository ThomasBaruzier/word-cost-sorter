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
    case 'A': case 'a': index = 20; break;
    case 'Z': case 'z': index = 22; break;
    case 'E': case 'e': index = 24; break;
    case 'R': case 'r': index = 26; break;
    case 'T': case 't': index = 28; break;
    case 'Y': case 'y': index = 30; break;
    case 'U': case 'u': index = 32; break;
    case 'I': case 'i': index = 34; break;
    case 'O': case 'o': index = 36; break;
    case 'P': case 'p': index = 38; break;
    case 'Q': case 'q': index = 40; break;
    case 'S': case 's': index = 42; break;
    case 'D': case 'd': index = 44; break;
    case 'F': case 'f': index = 46; break;
    case 'G': case 'g': index = 48; break;
    case 'H': case 'h': index = 50; break;
    case 'J': case 'j': index = 52; break;
    case 'K': case 'k': index = 54; break;
    case 'L': case 'l': index = 56; break;
    case 'M': case 'm': index = 58; break;
    case 'W': case 'w': index = 63; break;
    case 'X': case 'x': index = 65; break;
    case 'C': case 'c': index = 67; break;
    case 'V': case 'v': index = 69; break;
    case 'B': case 'b': index = 71; break;
    case 'N': case 'n': index = 73; break;
    case '.': index = 77; break;
    default: index = 100;
  }
  return index;
}

int main(int argc, char *argv[])
{
  FILE *file;
  int ch1, ch2, x, y, pos;
  float diff, min_diff = 12;
  char line[1000];
  file = fopen("input", "r");
  if (file == NULL)
  {
    return 0;
  }

  float verbosity = 1;
  if (argc == 2)
  {
    verbosity = atoi(argv[1]);
  }

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
        printf("Unsupported character: %c\n", line[pos+1]);
        return 0;
      }
      x = (ch1 % 20 - ch2 % 20) / 2.0;
      y = (ch1 / 20 - ch2 / 20);
      diff += sqrt((x * x) + (y * y));
      // printf("%c - %c > %f\n", line[pos], line[pos+1], diff);
      pos++;
    }

    if (diff - verbosity <= min_diff)
    {
      pos = 0;
      printf("%0.2f > ", diff);
      while (line[pos] != '\n')
      {
        printf("%c", line[pos]);
        pos++;
      }
      puts("");
      if (diff <= min_diff)
      {
        min_diff = diff;
      }

    }

  }
  fclose(file);
  return 0;
}
