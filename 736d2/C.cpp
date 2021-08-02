#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<int> nobles_cla(n,0);
    int tot=n;
    //count number of links above for each noble
    for(int i=0;i<m;i++){
        int t1,t2;
        cin>>t1>>t2;
        nobles_cla[min(t1,t2)]++;
        if(nobles_cla[min(t1,t2)]==1){
            tot--;
        }
    }
    //see what additional friends do
    int q;cin>>q;
    for(int i=0;i<q;i++){
        int type; cin>>type;
        if(type==1){
            int t1,t2;
            cin>>t1>>t2;
            nobles_cla[min(t1,t2)]++;
            if(nobles_cla[min(t1,t2)]==1){
                tot--;
            }
        }else if(type==2){
            int t1,t2;
            cin>>t1>>t2;
            nobles_cla[min(t1,t2)]--;
            if(nobles_cla[min(t1,t2)]==0){
                tot++;
            }
        }else{
            cout<<tot<<endl;
        }
    }
}