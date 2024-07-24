#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> arr) {
    cout << "[";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if(i != arr.size()-1) {
            cout << ", ";
        }
    }
    cout << "] ";
}

vector<int> merge(vector<int> leftArr, vector<int> rightArr) {
    vector<int> combine;
    // we make leftArr to be the one always smaller;
    int i = 0;
    int j = 0;
    while(i < leftArr.size() && j < rightArr.size()) {
        if(leftArr[i] < rightArr[j]) {
            combine.push_back(leftArr[i]);
            i++;
        } else {
            combine.push_back(rightArr[j]);
            j++;
        }
    }

    while(j < rightArr.size()) {
        combine.push_back(rightArr[j]);
        j++;
    }

    while(i < leftArr.size()) {
        combine.push_back(leftArr[i]);
        i++;
    }

    // cout << "combine: ";
    printVector(combine);
    cout << endl;
    return combine;
}

vector<int> mergeSort(vector<int> arr) {
    if(arr.size() <= 1) return arr;

    int mid = arr.size()/2;

    vector<int> leftArr(arr.begin(), arr.begin()+mid);
    vector<int> rightArr(arr.begin()+mid, arr.end());
    printVector(leftArr);
    printVector(rightArr);
    cout << endl;

    vector<int> sortedLeft = mergeSort(leftArr);
    vector<int> sortedRight = mergeSort(rightArr);

    // printVector(sortedLeft);
    // printVector(sortedRight);
    // cout << endl;

    return merge(sortedLeft, sortedRight);
}

int main() {
    vector<int> arr = {5,2,8,6,1,9,3,0,4};
    printVector(arr);
    cout << endl;
    vector<int> sortedArr = mergeSort(arr);
    printVector(sortedArr);
    cout << endl;
}