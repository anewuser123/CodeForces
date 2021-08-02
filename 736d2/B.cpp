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
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> enemy(n);
        vector<int> greg(n);
        vector<int> filled(n,0);
        vector<int> accounted(n,0);
        string s1;cin>>s1;
        string s2;cin>>s2;
        for(int i=0;i<n;i++){
            enemy[i]=s1[i]-'0';
        }
        for(int i=0;i<n;i++){
            greg[i]=s2[i]-'0';
        }
        
        int total=0;
        for(int i=0;i<n;i++){
            if(greg[i]==1&&enemy[i]==0){
                total++;
                filled[i]=1;
                accounted[i]=1;
            }else if(greg[i]==1){
                //start
                if(i==0){
                    if(enemy[i+1]==1){
                        total++;
                        filled[i+1]=1;
                        accounted[i]=1;
                    }
                }else if(i==n-1){
                    //end
                    if(enemy[i-1]==1&&filled[i-1]==0){
                        total++;
                        filled[i-1]=1;
                        accounted[i]=1;
                    }
                }else{
                    if(enemy[i-1]==1&&filled[i-1]==0){
                        total++;
                        filled[i-1]=1;
                        accounted[i]=1;
                    } else if(enemy[i+1]==1&&filled[i+1]==0){
                        total++;
                        filled[i+1]=1;
                        accounted[i]=1;
                    }
                }
            }else{
                accounted[i]=1;
            }
        }
        cout<<total<<endl;
    }
}