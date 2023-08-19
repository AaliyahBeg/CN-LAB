#include<bits/stdc++.h>
using namespace std;
string en(string s,int key){
    //key -->no of rows
    string ans;
    vector<vector<int> > a(key,vector<int>(ceil(s.length()/float(key))));
    int no_of_x=key*ceil(s.length()/float(key))-s.length();
    cout<<no_of_x<<"\n";
    while(no_of_x--){
        s+='x';
    }
    int k=0;
    for(int i=0;i<key;i++){
        for(int j=0;j<ceil(s.length()/float(key));j++) a[i][j]=s[k++];
    }
    for(int i=0;i<s.length()/float(key);i++){
        for(int j=0;j<key;j++){
            ans+=a[j][i];
            //cout<<ans<<"\n";
        }
    }
    cout<<ans<<"\n";
    return ans;
}
void de(string s,int key){
    
    //key -->no of rows
    string ans;
    vector<vector<int> > a(key,vector<int>(ceil(s.length()/float(key))));
    int no_of_x=key*ceil(s.length()/float(key))-s.length();
    cout<<no_of_x<<"\n";
    while(no_of_x--){
        s+='x';
    }
    int k=0;
    for(int i=0;i<ceil(s.length()/float(key));i++){
        for(int j=0;j<key;j++) a[j][i]=s[k++];
    }
    for(int i=0;i<key;i++){
        for(int j=0;j<ceil(s.length()/float(key));j++){
            ans+=a[i][j];
            //cout<<ans<<"\n";
        }
    }
    int ptr=0;
    int ptr1=0;
    for(int i=0;i<ans.length();i++){
        if(ans[i]=='x') ptr1++;
        if(ans[i]!='x') {
            ptr++;ptr1++;
        }
    }
    if(ptr1==ans.length()&& ptr!=ans.length()){
        ans=ans.substr(0,ptr);
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    string s;
    int key;
    string ans;
    while(1){
        cout<<"Menu:\n1)Encryption\n2)Decryption\n3)Exit\n";
        int ch;cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the string to be encrypted:\n";
                cin>>s;
                cout<<"Enter the key for encryption:\n";
                cin>>key;
                ans=en(s,key);
                break;
            case 2:
                // cout<<"Enter the string wrt to which Decryption has to be done:\n";
                // cin>>s;
                de(ans,key);
                break;
            case 3:
                cout<<"Exiting\n";
                return 0;
            default:
                cout<<"Enter correct input\n";
                break;
            
        }

    }
    
    return 0;
}

