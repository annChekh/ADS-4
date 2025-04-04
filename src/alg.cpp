// Copyright 2021 NNTU-CS
#include <cstdint>
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
    int count = 0;
    int lEl = 0;
    int rEl = len - 1;

    while (lEl < rEl) {
        int summa = arr[lEl] + arr[rEl];
        if (summa == value) {
            if (arr[lEl] == arr[rEl]) {
                int n = rEl - lEl + 1;
                return count + n * (n - 1) / 2;
            }

            int eqLel = 1;
            while (lEl + eqLel < len && arr[lEl + eqLel] == arr[lEl]) {
                eqLel++;
            }

            int eqRel = 1;
            while (rEl - eqRel >= 0 && arr[rEl - eqRel] == arr[rEl]) {
                eqRel++;
            }

            count += eqLel * eqRel;
            lEl += eqLel;
            rEl -= eqRel;
        } else if (summa < value) {
            lEl++;
        } else {
            rEl--;
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int i = 0;

    while (i < len) {
        int left = i + 1;
        int right = len - 1;
        int target = value - arr[i];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;

                int j = mid - 1;
                while (j >= left && arr[j] == target) {
                    count++;
                    j--;
                }

                j = mid + 1;
                while (j <= right && arr[j] == target) {
                    count++;
                    j++;
                }

                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int current = arr[i];
        do {
            i++;
        } while (i < len && arr[i] == current);
    }

    return count;
}
