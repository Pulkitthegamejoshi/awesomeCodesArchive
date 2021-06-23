//Aggressive Cows from SPOJ. Visit https://www.spoj.com/problems/AGGRCOW/ for full problem.

#include<bits/stdc++.h>

using namespace std;

int location(int x, int n, int c, int stalls[]) { 
    int cowsplaced = 1, lastpos = stalls[0]; 
    for(int i = 1 ; i < n ; i++) { 
        if(stalls[i] - lastpos >= x) { 
            if(++cowsplaced == c)
                return 1; 
            lastpos = stalls[i]; 
        } 
    } 
    return 0; 
} 

int solve() {
    int n, c, stalls[100001];
    cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> stalls[i];
    }
    sort(stalls, stalls + n);
    int start = 0, end = stalls[n-1] - stalls[0] + 1, mid; 
    while(end-start > 1) 
    { 
        mid = start + (end - start) / 2; 
        (location(mid, n, c, stalls) ? start : end) = mid; 
    }
    return start; 
}   

int main() {
    int t;
    cin >> t;
    while(t--) {
        int ans = solve();
        cout << ans << endl;
    }
}