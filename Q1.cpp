#include<iostream>
using namespace std;
void en(string s,int key){
    string ans;
    int z=int('z');
    int Z=int('Z');
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' and s[i]<='z'){
            int x=char((s[i]+key)%z);
            if(int(s[i]+key)>=z) x=x+int('a')-1;
            ans+=char(x);
        }else if(s[i]>='A' and s[i]<='Z'){
            int x=char((s[i]+key)%Z);
            if(int(s[i]+key)>=Z) x=x+int('A')-1;
            ans+=char(x);
        }
    }
    cout<<ans<<"\n";
    return ;
}
void de(string s,int key){
    string ans;
    int z=int('z');
    int Z=int('Z');
    key=key%26;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' and s[i]<='z' and s[i]-key<int('a')){
            ans+=char('z'-key+s[i]-'a'-1);
            if(int(s[i]+key)>=z) ans+='a';
        }else if(s[i]>='A' and s[i]<='Z' and s[i]-key<int('A')){
            ans+=char('Z'-key+s[i]-'A'-1);
            if(int(s[i]+key)>=Z) ans+='A';
        } else if(s[i]>='a' and s[i]<='z'){
            ans+=char(s[i]-key);
        }else if(s[i]>='A' and s[i]<='Z'){
            ans+=char(s[i]-key);
        }
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    string s;
    int key;
    while(1){
        cout<<"Menu:\n1)Encryption\n2)Decryption\n3)Exit\n";
        int ch;cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the string to be encrypted:\n";
                cin>>s;
                cout<<"Enter the Key:\n";
                cin>>key;
                en(s,key);
                break;
            case 2:
                cout<<"Enter the string to be decrypted:\n";
                cin>>s;
                cout<<"Enter the Key:\n";
                cin>>key;
                de(s,key);
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
