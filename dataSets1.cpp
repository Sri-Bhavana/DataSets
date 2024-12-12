#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; ++i)
        left[i] = nums[low + i];
    for (int j = 0; j < n2; ++j)
        right[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] < right[j]) {
            nums[k] = left[i];
            i++;
        }
        else {
            nums[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        nums[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        nums[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
}

//Example to sort a large array
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 1000000; // 1 million elements
    vector<int> nums(SIZE);

    // Generate a large random dataset
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % 10000000;
    }

    cout << "Original unsorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    // Sort the large array using merge sort
    mergeSort(nums, 0, SIZE - 1);

    cout << "\nSorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    return 0;
}