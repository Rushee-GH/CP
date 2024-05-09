#include <bits/stdc++.h>
using namespace std;

#define  int    long long
#define  mod    1000000007
#define  modd   998244353
#define  inf    INT32_MAX
#define  INF    9e18
#define  ff     first
#define  ss     second
#define  pb     push_back
#define  nl     '\n'
#define  sz(s)  (int)((s).size())
#define  all(x) (x).begin(),(x).end()

template<typename T1, typename T2> static inline void umin(T1 &x, T2 y) {if (y < x) x = y;}
template<typename T1, typename T2> static inline void umax(T1 &x, T2 y) {if (y > x) x = y;}

typedef pair   <int,int>       pii;
typedef vector <int>           vi;
typedef vector <vector<int>>   vvi;
typedef vector <pair<int,int>> vpi;
typedef map    <int,int>       mii;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
    #define debug(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
    #define debug(x...)
#endif

#define pd(ar, n) cerr << #ar << " = [ "; for (int i = 0; i < n; i++) {cerr << ar[i] << " ";} cerr << "] " << endl;
#define pdd(ar, n, m) cerr << #ar << endl; for (int i = 0; i < n; i++) {{cerr << " [ "; for (int j = 0; j < m; j++) {cerr << ar[i][j] << " ";}; cerr << "]" << endl;}};

void __print (int x) {cerr << x;}
void __print (double x) {cerr << x;}
void __print (char x) {cerr << "'" << x << "'";}
void __print (const string &x) {cerr << '"' << x << '"';}
void __print (bool x) {cerr << (x ? "True" : "False");}
void _print() {cerr << "]\n";}
template <typename A, typename B> void __print (const pair<A,B> &x) {cerr << "("; __print(x.first); cerr << ","; __print(x.second); cerr << ")";}
template <typename A> void __print (const A &x) {int f = 0; cerr << "{"; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
template <typename A, typename... B> void _print (A t, B... v) {__print(t); if (sizeof...(v)) cerr << ","; _print(v...);} 
template <typename T1, typename T2> istream& operator>>(istream &istream, pair <T1,T2> &p) {return (istream >> p.ff >> p.ss);}
template <typename T1, typename T2> ostream& operator<<(ostream &ostream , pair <T1,T2> &p) { ostream << p.ff << ' ' << p.ss << endl; return ostream;}
template <typename T> istream& operator>>(istream &istream, vector <T> &v) {for (auto &i : v) istream >> i;  return istream;}
template <typename T> ostream& operator<<(ostream &ostream, vector <T> &v) {for (auto &i : v) ostream << i << ' ';  return ostream;}
template <typename T> void print(T &&t) {cout << t << "\n";}
template <typename T, typename... Args> void print(T &&t, Args &&... args) {cout << t << " "; print(forward<Args>(args)...);}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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