#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    string cmd = "codeforces";

    while (test--) {
    string s;
    cin >> s;

        if (cmd.find(s) != string::npos) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

