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
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        int left = i + 1;
        int right = len - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                int j = mid - 1;
                while (j > i && arr[j] == target) {
                    count++;
                    j--;
                }
                j = mid + 1;
                while (j < len && arr[j] == target) {
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
        while (i + 1 < len && arr[i] == arr[i + 1]) {
            i++;
        }
    }
    return count;
}
