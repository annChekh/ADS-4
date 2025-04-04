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
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
            // Пропускаем дубликаты
            while (left < right && arr[left] == arr[left - 1]) left++;
            while (left < right && arr[right] == arr[right + 1]) right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    std::sort(arr, arr + len);
    int count = 0;
    int i = 0;

    while (i < len) {
        int target = value - arr[i];
        int lEl = i + 1;
        int rEl = len - 1;

        while (lEl <= rEl) {
            int mid = lEl + (rEl - lEl) / 2;
            if (arr[mid] == target) {
                count++;
                int j = mid - 1;
                while (j >= lEl && arr[j] == target) {
                    count++;
                    j--;
                }
                j = mid + 1;
                while (j <= rEl && arr[j] == target) {
                    count++;
                    j++;
                }

                break;
            } else if (arr[mid] < target) {
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
