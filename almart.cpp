#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int s[26];

int main(){
 
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
 
 int n;
 cin >> n;
 for(int i=0;i<n;i++){
  cin >> s[i];
 }
 
 long long ans=0;
 if(n==1){
  cout << ans;
  return 0;
 }
 
 for(int i=0;i<n-1;i++){
  
  for(int j=i+1;j<n;j++){
   if(s[j]>=s[i]){
    s[j]-=s[i];
    ans+=s[i];
   }else{
    ans += s[j];
    s[i] = s[j];
    s[j] = 0;
   }
  }
  
 }
 
 cout << ans;
 
 return 0;
}

