// Copyright 2021 NNTU-CS
#include <cstdint>
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int a = 0; a < len; a++) {
        for (int b = a + 1; b < len; b++) {
            if (arr[a] + arr[b] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    int lEl = i + 1;
    int rEl = len - 1;
    while (lEl <= rEl) {
      int centre = lEl + (rEl - lEl) / 2;
      if (arr[i] + arr[centre] == value) {
        k++;
        int l = centre - 1;
        while (l >= lEl && arr[i] + arr[l] == value) {
          k++;
          l--;
        }
        int r = centre + 1;
        while (r <= rEl && arr[i] + arr[r] == value) {
          k++;
          r++;
        }
        break;
      } else if (arr[i] + arr[centre] < value) {
        lEl = centre + 1;
      } else {
        rEl = centre - 1;
      }
    }
  }
  return k;
}


int countPairs3(int *arr, int len, int value) {
  int k = 0;
  int lEl = 0;
  int rEl = len - 1;
  while (lEl < rEl) {
    int summa = arr[lEl] + arr[rEl];
    if (summa == value) {
      if (arr[lEl] != arr[rEl]) {
        int lEl_val = arr[lEl];
        int rEl_val = arr[rEl];
        int lEl_k = 1;
        int rEl_k = 1;
        while (lEl + 1 < rEl && arr[lEl + 1] == lEl_val) {
          lEl++;
          lEl_k++;
        }
        while (rEl - 1 > lEl && arr[rEl - 1] == rEl_val) {
          rEl--;
          rEl_k++;
        }
        k += lEl_k * rEl_k;
        lEl++;
        rEl--;
      } else {
        k += (rEl - lEl + 1) * (rEl - lEl) / 2;
        break;
      }
    } else if (summa < value) {
      lEl++;
    } else {
      rEl--;
    }
  }
  return k;
}
