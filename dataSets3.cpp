#include <iostream>
#include <vector>

using namespace std;

const int MAX_VALUE = 1e7 + 1;   // Assuming the dataset contains integer values within this range

void countingSort(vector<int>& nums) {
    int n = nums.size();

    // Create a count array to store the frequency of each element
    vector<int> count(MAX_VALUE, 0);

    // Count occurrences of each element in the input array
    for (int num : nums) {
        count[num]++;
    }

    // Compute the cumulative sum to determine the positions in the sorted array
    for (int i = 1; i < MAX_VALUE; i++) {
        count[i] += count[i - 1];
    }

    // Create an output array and populate it with the sorted elements
    vector<int> output(n);
    for (int num : nums) {
        output[--count[num]] = num;
    }

    // Copy the sorted output back to the input array
    for (int i = 0; i < n; ++i) {
        nums[i] = output[i];
    }
}

//Example to sort a large array
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 1000000; // 1 million elements
    vector<int> nums(SIZE);

    // Generate a large random dataset within the range [0, MAX_VALUE - 1]
    for (int i = 0; i < SIZE; i++) {
        nums[i] = rand() % MAX_VALUE;
    }

    cout << "Original unsorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    // Sort the large array using counting sort
    countingSort(nums);

    cout << "\nSorted array:\n";
    for (int i = 0; i < 10; i++) {
        cout << nums[i] << " ";
    }
    cout << "..." << endl;

    return 0;
}
