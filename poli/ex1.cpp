#include <bits/stdc++.h>
#include<vector>
#include <iostream>
using namespace std;

int main() {
    vector<char> v;
    char s[30];
    char copie_i;
    char operatori[5] = "*/+-";
    int i;
    int ok=1;
    cin.get(s, 30);
    int k=strlen(s);
    for ( i = 0; i < strlen(s); ++i)
        v.push_back(s[i]);
    while (k>2) {
        ok=1;
        for ( i = 0; i <= k; ++i) {
            if(ok==0)
                break;
            for (int j = 0; j < strlen(operatori); ++j) {
                if (v[i] == operatori[j] and v[i-1]!=operatori[j] and v[i-2]!=operatori[j]){
                    if(j==0)
                    {     vector<char>::iterator itr = v.begin();
                        itr+=(i-1);
                        v[i-2]=(char)(48+((int)(v[i-2])-48)*((int)(v[i-1])-48));
                        v.erase(itr);
                        v.erase(itr);
                        k-=2;
                        ok=0;
                        break;
                    }
                    if(j==1)
                    {     vector<char>::iterator itr = v.begin();
                        itr+=(i-1);
                        v[i-2]=(char)(48+((int)(v[i-2])-48)/((int)(v[i-1])-48));
                        v.erase(itr);
                        v.erase(itr);
                        k-=2;
                        ok=0;
                        break;
                    }
                    if(j==2)
                    {     vector<char>::iterator itr = v.begin();
                        itr+=(i-1);
                        v[i-2]=(char)(48+((int)(v[i-2])-48)+((int)(v[i-1])-48));
                        v.erase(itr);
                        v.erase(itr);
                        k-=2;
                        ok=0;
                        break;
                    }
                    if(j==3)
                    {     vector<char>::iterator itr = v.begin();
                        itr+=(i-1);
                        v[i-2]=(char)((int)(48+(v[i-2])-48)-((int)(v[i-1])-48));
                        v.erase(itr);
                        v.erase(itr);
                        k-=2;
                        ok=0;
                        break;
                    }
                }
            }

        }
    }
    for(int l=0;l<k;l++)
        cout<<(int)(v[l]-48);
}
