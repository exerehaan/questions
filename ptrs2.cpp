#include<bits/stdc++.h>
using namespace std;

int main(){
    string str[3] = {
        "To err is human",
        "But to really mess up things",
        "One needs to know C!!"
    };
    
    
    for(int i = 0; i<3; i++){
        int size = str[i].size();
        for(int j =0 ; j<size/2; j++){
            char temp = str[i][j];
            str[i][j] = str[i][size - j -1];
            str[i][size - j -1] = temp;
        }
    }
    
    for(int i = 0; i<3; i++){
        cout<< str[i]<<endl;
    }
    return 0;
}