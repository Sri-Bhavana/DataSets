#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int>& nums, int minValue, int maxValue) {
    int range = maxValue - minValue + 1;

    vector<int> count(range, 0);

    // Count occurrences of each element in the input array
    for (int num : nums) {
        count[num - minValue]++;
    }

    // Calculate the cumulative sum of count array
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array and place elements based on their counts
    vector<int> output(nums.size());
    for (int num : nums) {
        output[--count[num - minValue]] = num;
    }

    // Copy the sorted elements back to the input array
    nums = output;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 1000000; // 1 million elements
    int minValue, maxValue;

    // Assume the dataset has a known range of values
    minValue = 1;
    maxValue = 100000;

    vector<int> nums(SIZE);

    // Generate a large random dataset within the specified range
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % (maxValue - minValue + 1) + minValue;
    }

    cout << "Original unsorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    // Sort the large array using counting sort
    countingSort(nums, minValue, maxValue);

    cout << "\nSorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    return 0;
}