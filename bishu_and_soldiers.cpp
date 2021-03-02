/*
    Bishu went to fight for Coding Club. 
    There were N soldiers with various powers. 
    There will be Q rounds to fight and in each 
    round Bishu's power will be varied. 
    With power M, Bishu can kill all the 
    soldiers whose power is less than or equal to M(<=M). 
    After each round, All the soldiers who are dead in 
    previous round will reborn.Such that in each 
    round there will be N soldiers to fight. 
    As Bishu is weak in mathematics, 
    help him to count the number of soldiers 
    that he can kill in each round and total sum of their powers.
*/

#include<iostream>
using namespace std;
int main()
{
	int n, q; // no of soldiers / q no of rounds
    cin >> n;
    vector<int> a, b(n+1);
 
    for(int i = 0; i < n; i++) {
        int g;
        cin >> g;
        a.push_back(g);
    }
    cin >> q;
 
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if(i > 0) {
            b[i] = a[i] + b[i-1];
        } else {
            b[i] = a[i];
        } 
    }
 
    
    while(q--) {
        int p;
        cin >> p;
        vector<int>::iterator upper;
        upper = upper_bound(a.begin(), a.end(), p);
        int ans1 = (upper - a.begin());
        int ans2 = b[ans1-1];
        cout << ans1 << " " << ans2 << endl;
    } 
    return 0;
}
 