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

void p1(vl &l1, vl &l2) {
    ll n = l1.size();
    ll total{};
    for (int i = 0; i < n; i++)
    {
        total += abs(l1[i] - l2[i]);
        //   cout<<total<<'\n';
    }
    cout << total;
}

void p2(vl &l1, vl &l2)
{
    ll n = l1.size();
    unordered_map<ll, ll> mp;
    ll sim_score = 0;

    for (ll i = 0; i < n; i++)
    {
        ll targ = l1[i];
        if (mp.contains(targ))
        {
            sim_score += mp[targ];
            continue;
        }

        auto x = lower_bound(A(l2), targ);

        if (x == l2.end() || *x != targ)
        {
            mp[targ] = 0;
            continue;
        }

        auto y = upper_bound(A(l2), targ);
        ll cnt = y - x;
        ll score = targ * cnt;
        sim_score += score;
        mp[targ] = score;
    }

    cout << sim_score;
}

    int main()
    {
        //   ./a < input1.txt > output1.txt
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        ifstream inputFile("input1.txt");
        vl l1, l2;
        if (inputFile.is_open())
        {
            string line;

            while (std::getline(inputFile, line))
            {
                ll a = stoll(line.substr(0, line.find(" "))), b = stoll(line.substr(line.find(" ")));
                l1.push_back(a);
                l2.push_back(b);
            }
            sort(A(l1));
            sort(A(l2));
            p2(l1, l2);
            inputFile.close();
        }
        else
        {
            std::cerr << "Error: Unable to open file." << std::endl;
        }
    }