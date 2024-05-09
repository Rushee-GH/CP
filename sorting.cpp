#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vi &a) {
    int n = sz(a);
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void insertion_sort(vi &a) {
    int n = sz(a);
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j + 1] < a[j]) {
                swap(a[j + 1], a[j]);
            } else {
                break;
            }
        }
    }
}

void selection_sort(vi &a) {
    int n = sz(a);
    for (int i = 0; i < n; i++) {
        int minEle = a[i], minPos = i;
        for (int j = i; j < n; j++) {
            if (a[j] < minEle) {
                minEle = a[j];
                minPos = j;
            }
        }
        swap(a[i], a[minPos]);
    }
}

void merge (vi &a, int l, int mid, int r) {
    int s = r - l + 1;
    vi temp(s);

    int x = l, y = mid + 1, i = 0;
    while (x <= mid and y <= r) {
        if (a[x] <= a[y]) {
            temp[i] = a[x++];
        } else {
            temp[i] = a[y++];
        }
        i++;
    }

    while (x <= mid) {
        temp[i++] = a[x++];
    }

    while (y <= r) {
        temp[i++] = a[y++];
    }

    i = 0;
    while (l <= r) {
        a[l++] = temp[i++];
    }
}

void merge_sort(vi &a, int s, int e) {
    if (e <= s)
        return;
    int mid = s + (e - s) / 2;
    merge_sort(a, s, mid);
    merge_sort(a, mid + 1, e);

    merge(a, s, mid, e);
}

int Partition (vi &a, int s, int e) {
    int pivot = e;
    int j = s;
    for (int i = s; i < e; i++) {
        if (a[i] <= a[pivot]) {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[pivot]);
    return j;
}

void quick_sort(vi &a, int s, int e) {
    if (s < e) {
        int pivot = Partition(a, s, e);

        quick_sort(a, s, pivot - 1);
        quick_sort(a, pivot + 1, e);
    }
}

void Solve () {
    // 1 6 2 4 8 3
    vi a = {1, 5, 2, 6, 2, 7};
    quick_sort(a, 0, sz(a) - 1);
    print(a);
}

signed main () {
    Solve();
}