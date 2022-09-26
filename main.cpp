#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& a, int left, int right, int mid) {
    int it1 = 0, it2 = 0;
    vector<int> result;

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

void mergeSort(vector<int>& a, int left, int right) {
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
    int n1 = 3, n2 = 4/*, m*/;
    //cin >> n1;
    vector<int> nums1 = {1, 7, 9};

    //for (int i = 0; i < n1; i++) {
    //    cin >> m;
    //    nums1[i] = m;
    //}
    int l = 0, r = n1;
    mergeSort(nums1, l, r);

    //cin >> n2;
    vector<int> nums2 = {9, 7, 7, 1};

    //for (int i = 0; i < n2; i++) {
    //    cin >> m;
    //    nums2[i] = m;
    //}
    l = 0, r = n2;
    mergeSort(nums2, l, r);

    for (int i = 0; i < n1 || i < n2; i++) {
        if (nums1[i] == nums1[i + 1] and i < n1) {
            nums1.erase(nums1.begin() + i);
            i--;
        } else if (nums2[i] == nums2[i + 1] and i < n2) {
            nums2.erase(nums2.begin() + i);
            i--;
        }
    }
    if (nums1.size() == nums2.size()) {
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] != nums2[i]) {
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