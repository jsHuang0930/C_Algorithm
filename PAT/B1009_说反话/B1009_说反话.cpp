#include <bits/stdc++.h>
using namespace std;
int main()
{
  char words[90][90]; //字符串总长度不超过90
  int wordscount = 0;
  while (scanf("%s", words[wordscount]) != EOF)
  { //ctrl+z enter 告诉系统到了EOF
    wordscount++;
  }
  for (int i = wordscount - 1; i > 0; i--)
  {
    printf("%s ", words[i]);
  }
  printf("%s", words[0]);
  return 0;
}