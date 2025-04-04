// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int k = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[n] + arr[m] == value) {
        k++;
      }
    }
  }
  return k;
}
int countPairs2(int *arr, int len, int value) {
  int k = 0, summa lEl = 0, rEl = len - 1;
  while (lEl < rEl) {
    uint64_t summa = arr[lEl] + arr[rEl];
    if (summa == value) {
      if (arr[lEl] == arr[rEl]) {
        int equalEl = rEl - lEl + 1;
        return k + equalEl * (equalEl - 1) / 2;
      }
      uint64_t eqLel = 1, eqRel = 1;
      while (lEl + eqLel < len && arr[lEl + eqLel]) == arr[lEl])
        eqLel++;
      while (rEl - eqRel >= 0 && arr[rEl - eqRel]) == arr[rEl])
        eqRel++;
      k += eqLel * eqRel;
      lEl += eqLel;
      rEl -= eqRel;
    } else if (summa < value)
      lEl++;
    else rEl--;
  }
  return k;
}
int countPairs3(int *arr, int len, int value) {
    int k = 0, i = 0;
    while (i < len) {
        int lBound = i + 1;
        int rBound = len - 1;
        while (lBound <= rBound) {
            int mid = lBound + (rBound - lBound) / 2;
            if (arr[mid] == value - arr[i]) {
                k++;
                int j = mid - 1;
                while (j >= lBound && arr[j] == value - arr[i]) {
                    k++;
                    j--;
                }
                j = mid + 1;
                while (j <= rBound && arr[j] == value - arr[i]) {
                    k++;
                    j++;
                }
                break;
            }
            else if (arr[mid] < value - arr[i]) {
                lBound = mid + 1;
            }
            else {
                rBound = mid - 1;
            }
        }
        int curr = arr[i];
        do {
            i++;
        } while (i < len && arr[i] == curr;
    }
    return k;
}
