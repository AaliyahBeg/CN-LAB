#include<bits/stdc++.h>
#include<map>
using namespace std;

void en(string s,int key,map<int,char>m){
    string ans;

    for(int i=0;i<s.length();i++){
        bool flag=false;
        if(s[i]>='A' and s[i]<='Z'){
            s[i]=char(s[i]+'a'-'A');
            flag=true;
        }
        cout<<s[i]<<endl;
        cout<<m[((s[i]-'a')+key)%26]<<endl;
        if(flag) ans+=char(m[((s[i]-'a')+key)%26]-'a'+'A');
        else ans+=m[((s[i]-'a')+key)%26];
        cout<<ans<<endl;
    }
    cout<<ans<<"\n";
    return ;
}
void de(string s,int key,map<int,char>m){
    string ans;
    for(int i=0;i<s.length();i++){
        bool flag=false;
        if(s[i]>='A' and s[i]<='Z'){
            s[i]=char(s[i]+'a'-'A');
            flag=true;
        }
        cout<<s[i];
        int x= s[i]-'a'-key;
        if(x<0) x=26+x;
        if(flag) ans+=char(m[x]-'a'+'A');
        else ans+=m[x];
    }
    cout<<ans<<"\n";
    return ;
}
int main(){
    map<int,char> m;
    m={{0,'a'},{1,'b'},{2,'c'},{3,'d'},{4,'e'},{5,'f'},{6,'g'},
    {7,'h'},{8,'i'},{9,'j'},{10,'k'},{11,'l'},{12,'m'},{13,'n'},
    {14,'o'},{15,'p'},{16,'q'},{17,'r'},{18,'s'},{19,'t'},{20,'u'},
    {21,'v'},{22,'w'},{23,'x'},{24,'y'},{25,'z'}};
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
                en(s,key,m);
                break;
            case 2:
                cout<<"Enter the string to be decrypted:\n";
                cin>>s;
                cout<<"Enter the Key:\n";
                cin>>key;
                de(s,key,m);
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

