#include<bits/stdc++.h>
using namespace std;
//encryption
void en(string s,string key){
    string ans;
    for(int i=0;i<s.length();i++){
        if(s[i]=='j') s[i]='i';
    }
    vector<int> freq(26,0);
    freq['j'-'a']++;
    vector<vector<char> >v (5,vector<char>(5));
    int k=0;
    int l=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(k<key.length()){
                v[i][j] = key[k];
                freq[key[k]-'a']++;
                k++;
                
            }
            else{
                while(freq[l]) l++;
                v[i][j]=char(l+'a');
                freq[l]++;
                
            }
        }
    }
    //  for(int i=0;i<5;i++){
    //     for(int j=0;j<5;j++){
    //         cout<<v[i][j]<<" ";
    //     }cout<<"\n";
    // }
    if(s.length()%2) s+='x';
    for(int i=1;i<s.length();i++){
        if(s[i]==s[i-1]) s[i]='x';
    }
    //cout<<s<<"\n";
    for(int i=0;i<s.length();i+=2){
        char a=s[i];
        char b=s[i+1];
        //cout<<a<< " "<<b<<"\n";
        int row_a,row_b,col_a,col_b;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(v[i][j]==a){
                    row_a=i;
                    col_a=j;
                }else if(v[i][j]==b){
                    row_b=i;
                    col_b=j;
                }
            }
        }
        if(row_a==row_b){
            row_a++;
            row_b++;
            if(row_a==5) row_a=0;
            if(row_b==5) row_b=0;
        }else if(col_a==col_b){
            col_a++;
            col_b++;
            if(col_a==5) col_a=0;
            if(col_b==5) col_b=0;
        }else{
            int temp=col_a;
            col_a=col_b;
            col_b=temp;
        }
        // cout<<row_a<<" "<<col_a<<"\n";
        // cout<<row_b<<" "<<col_b<<"\n";
        string ss;
        ss+=v[row_a][col_a];
        ss+=v[row_b][col_b];
        ans+=ss;
        //cout<<ss<<"\n";
    }

    cout<<ans<<"\n";
    return ;
}
int main(){
    string s;
    string key;
    while(1){
        cout<<"Menu:\n1)Encryption\n2)Exit\n";
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
                cout<<"Exiting\n";
                return 0;
            default:
                cout<<"Enter correct input\n";
                break;
            
        }

    }
    
    return 0;
}
