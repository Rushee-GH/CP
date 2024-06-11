#include <bits/stdc++.h>
using namespace std;

// ~0 -> -1
// -1 -> all bits are set

bool IsOdd(int n) {
    return (n & 1LL);
}

int GetIthBit(int n, int i) {
    int mask = (1LL << i);
    return (n & mask) > 0;
}

int SetIthBit(int n, int i) {
    int mask = (1LL << i);
    n |= mask;
    return n;
}

int ClearIthBit(int n, int i) {
    int mask = ~(1LL << i);
    n &= mask;
    return n;
}

int UpdateIthBitWithV(int n, int i, int v) {
    n = ClearIthBit(n, i);
    int mask = (v << i);
    n |= mask;
    return n;
}

int ClearLastIBits(int n, int i) {
    int mask = (-1 << i);
    n &= mask;
    return n;
}

bool IsPowerOf2(int n) {
    return n > 0 and !(n & (n - 1));
}

bool IsPowerOf4_1(int n) {
    return n > 0 and !(n & (n - 1)) and (n % 3) == 1;
}

bool IsPowerOf4_2(int n) {
    int mask = 0;
    for (int j = 0; j < 32; j += 2) {
        mask |= (1LL << j);
    }
    return IsPowerOf2(n & mask);
}

int CountSetbits(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n &= (n - 1);
    }
    return cnt;
}

// Xor Property use 
// (x ^ x) = 0
// (x ^ 0) = x
int UniqueIn2N_1(vector <int> vec) {
    int XOR = 0;
    for (int &i : vec) {
        XOR ^= i;
    }
    return XOR;
}

pair <int, int> UniqueIn2N_2(vector <int> vec) {
    int XOR = 0;
    for (int &i : vec) {
        XOR ^= i;
    }

    // finding leftmost setbit which only 
    // one of two unique numbers will have
    int mask = 0;
    for (int i = 0; i < 32; i++) {
        if (XOR & (1LL << i)) {
            mask = (1LL << i);
            break;
        }
    }

    // getting one unique number by xoring
    // only those numbers which have found bit
    pair <int, int> ans = {-1, -1};
    int tempXor = 0;
    for (int &i : vec) {
        if (i & (mask)) {
            tempXor ^= i;
        }
    }

    ans.first = tempXor;
    ans.second = tempXor ^ XOR;
    return ans;
}

// Use count bit array
// if at any bit pos if sum % 3 != 0
// then unique no has this bit
int UniqueIn3N_1(vector <int> vec) {

}

void Solve () {
    // cout << IsOdd(1) << ' ' << IsOdd(2) << endl;

    // cout << GetIthBit(6, 1) << endl;

    // cout << SetIthBit(8, 2) << endl;

    // cout << ClearIthBit(8, 3) << endl;

    // cout << UpdateIthBitWithV(12, 2, 1) << endl;
    // cout << UpdateIthBitWithV(12, 2, 0) << endl;

    // cout << ClearLastIBits(15, 3) << endl;

    // cout << IsPowerOf2(2) << endl;

    // cout << IsPowerOf4_1(16) << endl;
    // cout << IsPowerOf4_2(16) << endl;

    // cout << CountSetbits(14) << endl;

    // cout << UniqueIn2N_1({1, 8, 9, 2, 2, 9, 1});

    // cout << UniqueIn2N_2({1, 8, 9, 2, 2, 9, 8, 7}).first << ' ' << UniqueIn2N_2({1, 8, 9, 2, 2, 9, 8, 7}).second << endl;

}

int main () {
    Solve();
    return 0;
} 