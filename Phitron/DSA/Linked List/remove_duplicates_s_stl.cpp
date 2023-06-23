#include <bits/stdc++.h>

using namespace std;



int main()
{
    list<int> mylist;
    int v;
    
    while(true){
        cin >> v;
        if(v==-1){
            break;
        }
        mylist.push_back(v);
    }
    
    mylist.sort();
    mylist.unique();
    for (auto it = mylist.begin(); it != mylist.end(); ++it) {
        std::cout << *it << " ";
    }
    return 0;
}
