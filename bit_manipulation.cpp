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

}

int main () {
    Solve();
    return 0;
} 