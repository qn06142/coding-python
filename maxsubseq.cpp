#include<bits/stdc++.h>
using namespace std;

set<int> subsets[2];
int numElements, modulo, elements[44];

void generateSubsets(int sum, int leftIndex, int rightIndex) {
    if (leftIndex == rightIndex) {
        subsets[rightIndex == numElements].insert(sum);
        return;
    }
    generateSubsets((sum + elements[leftIndex]) % modulo, leftIndex + 1, rightIndex);
    generateSubsets(sum, leftIndex + 1, rightIndex);
}

int main() {
    cin >> numElements >> modulo;
    for (int i = 0; i < numElements; i++) {
        cin >> elements[i];
    }
    generateSubsets(0, 0, numElements / 2);
    generateSubsets(0, numElements / 2, numElements);
    subsets[0].insert(0);
    subsets[1].insert(0);
    int maximumSum = 0;
    for (int sum : subsets[0]) {
        int complement = modulo - sum - 1;
        auto it = subsets[1].upper_bound(complement);
        it--;
        maximumSum = max(maximumSum, *it + sum);
    }
    cout << maximumSum << endl;
    return 0;
}

	  		   					  		   	  			  	