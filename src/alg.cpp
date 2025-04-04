// Copyright 2021 NNTU-CS
#include <cstdint>
#include <algorithm> 
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int a = 0; a < len; a++) {
        for (int b = a + 1; b < len; b++) {
            if (arr[a] + arr[b] == value) count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
    std::sort(arr, arr + len); // Сортируем массив
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

            int lElCount = 1;
            int rElCount = 1;

            while (lEl + lElCount < len && arr[lEl + lElCount] == arr[lEl]) {
                lElCount++;
            }

            while (rEl - rElCount >= 0 && arr[rEl - rElCount] == arr[rEl]) {
                rElCount++;
            }

            count += lElCount * rElCount;
            lEl += lElCount;
            rEl -= rElCount;
        } else if (summa < value) {
            lEl++;
        } else {
            rEl--;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int i = 0;

    while (i < len) {
        int x = value - arr[i];
        int lEl = i + 1;
        int rEl = len - 1;

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

        int curr = arr[i];
        do {
            i++;
        } while (i < len && arr[i] == curr);
    }
    return count;
}
