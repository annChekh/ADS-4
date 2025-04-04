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
                count += n * (n - 1) / 2;
                break;
            }

            int current_lEl = arr[lEl];
            int current_rEl = arr[rEl];
            int lElCount = 0;
            int rElCount = 0;

            while (lEl < len && arr[lEl] == current_lEl) {
                lEl++;
                lElCount++;
            }

            while (rEl >= 0 && arr[rEl] == current_rEl) {
                rEl--;
                rElCount++;
            }

            count += lElCount * rElCount;
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
        int lEl = i + 1;
        int rEl = len - 1;
        int x = value - arr[i];

        while (lEl <= rEl) {
            int mid = lEl + (rEl - lEl) / 2;
            if (arr[mid] == x) {
                count++;

                int j = mid - 1;
                while (j >= lEl && arr[j] == x) {
                    count++;
                    j--;
                }

                j = mid + 1;
                while (j <= rEl && arr[j] == x) {
                    count++;
                    j++;
                }

                break;
            } else if (arr[mid] < x) {
                lEl = mid + 1;
            } else {
                rEl = mid - 1;
            }
        }

        int current = arr[i];
        do {
            i++;
        } while (i < len && arr[i] == current);
    }
    return count;
}
