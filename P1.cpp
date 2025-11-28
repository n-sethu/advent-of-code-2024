#include <algorithm>
#include <iostream>
#include <iostream> 
#include <fstream>  
#include <string>
// #include <bitset>
// #include <chrono>
// #include <random>
// #include <iomanip>
// #include <cmath>
// #include <functional>
#include <queue>
// #include <stack>
// #include <string>
// #include <sstream>
// #include <map>
// #include <numeric>
// #include <set>
// #include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vb = vector<bool>;
using vs = vector<string>;
#define G(x) \
    ll x;    \
    cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define A(x) (x).begin(), (x).end()
#define N 100010

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<vb> vis(1000, vb(1000));

int main() {
//   ./a < input1.txt > output1.txt
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ifstream inputFile("input1.txt");
    vl l1, l2;
    if (inputFile.is_open())
    { 
       string line;

        while (std::getline(inputFile, line)) {
          ll a = stoll(line.substr(0, line.find(" "))), b = stoll(line.substr(line.find(" ")));
          l1.push_back(a);
          l2.push_back(b);
        }
        sort(A(l1));
        sort(A(l2));
        ll n = l1.size();
        ll total{};
        for (int i = 0; i < n; i++) {
          total += abs(l1[i]-l2[i]);
        //   cout<<total<<'\n';
        }
        cout<<total;
        inputFile.close(); 
    }
    else
    {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}