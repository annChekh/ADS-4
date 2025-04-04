// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, lEl = 0, rEl = len - 1;
    while (lEl < rEl) {
        int summa = arr[lEl] + arr[rEl];
        if (summa == value) {
            if (arr[lEl] == arr[rEl]) {
                int n = rEl - lEl + 1;
                return count + n * (n - 1) / 2;
            }
            int eqLel = 1, eqRel = 1;
            while (lEl + eqLel < len && arr[lEl + eqLel] == arr[lEl])
              eqLel++;
            while (rEl - eqRel >= 0 && arr[rEl - eqRel] == arr[rEl])
              eqRel++;          
            count += eqLel * eqRel;
            lEl += eqLel;
            rEl -= eqRel;
        }
        else if (summa < value) lEl++;
        else rEl--;
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0, i = 0;    
    while (i < len) {
        int lBound = i + 1;
        int rBound = len - 1;
        while (lBound <= rBound) {
            int mid = lBound + (rBound - lBound) / 2;
            if (arr[mid] == value - arr[i]) {
                count++;
                int j = mid - 1;
                while (j >= lBound && arr[j] == value - arr[i]) {
                    count++;
                    j--;
                }
                j = mid + 1;
                while (j <= rBound && arr[j] == value - arr[i]) {
                    count++;
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
        } while (i < len && arr[i] == curr);
    }
    return count;
}
