// Copyright 2021 NNTU-CS
#include <cstdint>
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) count++;
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
            if (arr[left] == arr[right]) {
                int n = right - left + 1;
                count += n * (n - 1) / 2;
                break;
            }
            int left_val = arr[left];
            int right_val = arr[right];
            int left_count = 1;
            int right_count = 1;

            while (left + left_count < len && arr[left + left_count] == left_val) {
                left_count++;
            }
            while (right - right_count >= 0 && arr[right - right_count] == right_val) {
                right_count++;
            }
            count += left_count * right_count;
            left += left_count;
            right -= right_count;
        } 
        else if (sum < value) left++;
        else right--;
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;        
        int left = i + 1;
        int right = len - 1;
        int target = value - arr[i];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                for (int j = mid - 1; j >= left && arr[j] == target; j--) count++;
                for (int j = mid + 1; j <= right && arr[j] == target; j++) count++;
                break;
            }
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
    }
    return count;
}
