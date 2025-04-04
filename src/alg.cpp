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

            int left = arr[lEl];
            int right = arr[rEl];
            int lElCount = 0;
            int rElCount = 0;

            while (lEl < len && arr[lEl] == left) {
                lEl++;
                lElCount++;
            }

            while (rEl >= 0 && arr[rEl] == right) {
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

    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;

        int left = i + 1;
        int right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == value - arr[i]) {
                count++;

                int j = mid - 1;
                while (j >= left && arr[j] == value - arr[i]) {
                    count++;
                    j--;
                }

                j = mid + 1;
                while (j <= right && arr[j] == value - arr[i]) {
                    count++;
                    j++;
                }

                break;
            } else if (arr[mid] < value - arr[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
