#include <iostream>
#include <vector>
using namespace std;

void countingSort(int A[], int n, int R) {
    vector<int> count(R + 1, 0);
    vector<int> output(n);

    // Step 1: Count each element
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Step 2: Cumulative sum
    for (int i = 1; i <= R; i++) {
        count[i] += count[i - 1];
    }

    // Step 3: Build output array (in reverse for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[--count[A[i]]] = A[i];
    }

    // Step 4: Copy sorted elements back to A
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    // Find the maximum value (R)
    int R = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > R)
            R = A[i];
    }

    countingSort(A, n, R);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
