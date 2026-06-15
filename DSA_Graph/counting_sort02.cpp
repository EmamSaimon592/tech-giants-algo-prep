#include <iostream>
using namespace std;

void countingSort(int A[], int n) {
    // Step 1: Find maximum value (R)
    int R = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > R)
            R = A[i];
    }

    // Step 2: Create count[] and output[] arrays
    int count[1000] = {0};  // assuming values <= 999
    int output[1000];

    // Step 3: Count occurrences
    for (int i = 0; i < n; i++) {
        count[A[i]]++;
    }

    // Step 4: Cumulative count
    for (int i = 1; i <= R; i++) {
        count[i] += count[i - 1];
    }

    // Step 5: Build the output array (in reverse order for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[--count[A[i]]] = A[i];
    }

    // Step 6: Copy back to A[]
    for (int i = 0; i < n; i++) {
        A[i] = output[i];
    }
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);

    countingSort(A, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
