#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int left, int right, int mid) {
    int it1 = 0, it2 = 0;
    int result[right - left];

    while (left + it1 < mid && mid + it2 < right) {
        if (a[left + it1] < a[mid + it2]) {
            result[it1 + it2] = a[left + it1];
            ++it1;
        } else {
            result[it1 + it2] = a[mid + it2];
            ++it2;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = a[left + it1];
        ++it1;
    }
    while (mid + it2 < right) {
        result[it1 + it2] = a[mid + it2];
        ++it2;
    }
    for (int i = 0; i < it1 + it2; i++) {
        a[left + i] = result[i];
    }
}

void mergeSort(int a[], int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid = (right + left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);

    merge(a, left, right, mid);
}

int main() {
    bool flag = true;
    int n1 = 3, n2 = 4, m;
    cin >> n1;
    int nums1[n1];

    for (int i = 0; i < n1; i++) {
        cin >> m;
        nums1[i] = m;
    }
    int l = 0, r = n1;
    mergeSort(nums1, l, r);

    cin >> n2;
    int nums2[n2];

    for (int i = 0; i < n2; i++) {
        cin >> m;
        nums2[i] = m;
    }
    l = 0, r = n2;
    mergeSort(nums2, l, r);
    vector<int> numbers1, numbers2;

    for (int i = 0; i < n1 - 1; i++) {
        if (nums1[i] != nums1[i + 1]) {
            numbers1.push_back(nums1[i]);
        }
    } numbers1.push_back(nums1[n1 - 1]);
    for (int i = 0; i < n2 - 1; i++) {
        if (nums2[i] != nums2[i + 1]) {
            numbers2.push_back(nums2[i]);
        }
    } numbers2.push_back(nums2[n2 - 1]);

    if (numbers1.size() == numbers2.size()) {
        for (int i = 0; i < numbers1.size(); i++) {
            if (numbers1[i] != numbers2[i]) {
                flag = false;
            }
        }
        if (flag) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    } else {
        cout << "NO";
    }
    return 0;
}