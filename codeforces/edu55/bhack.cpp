#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

char cad[100001];

int main() {
  int n, i, j, maximum, pre_i, pre_j, counter;

  scanf("%d%s", &n, cad);
  i = counter = 0;
  while (i < n) {
    while (i < n && cad[i] == 'S')
      ++i;
    if (i < n) {
      ++counter;
      j = i;
      while (j + 1 < n && cad[j + 1] == 'G')
        ++j;
      // printf("%d %d\n", i, j);
      i = j + 1;
    }
  }

  i = maximum = 0;
  pre_i = pre_j = -1;
  while (i < n) {
    while (i < n && cad[i] == 'S')
      ++i;
    if (i < n) {
      j = i;
      while (j + 1 < n && cad[j + 1] == 'G')
        ++j;
      maximum = max(maximum, j - i + 1);
      if (pre_j != -1 && pre_j + 2 == i)
        maximum = max(maximum,
                      pre_j - pre_i + 1 + j - i + 1 + ((counter > 2) ? 1 : 0));
      pre_i = i;
      pre_j = j;
      // printf("%d %d\n", i, j);
      i = j + 1;
    }
  }

  printf("%d", maximum);

  return 0;
}
