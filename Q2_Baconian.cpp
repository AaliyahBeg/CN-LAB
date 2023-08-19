#include<bits/stdc++.h>
using namespace std;
string decimal_to_binary(int decimal){
    string ans;
    while(decimal){
        if(decimal%2){
            ans+='1';
        }else{
            ans+='0';
        }
        decimal/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int binary_to_decimal(string binary){
    // cout<<binary<<"\n";
    int ans=0;
    int p=binary.length()-1;
    for(int i=0;i<binary.length();i++){
        if(binary[i]=='1'){
            ans+=pow(2,p);
        }
        p--;
    }
    return ans;
}
string en(string s){
    string ans;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    for(int i=0;i<s.length();i++){
        string binary=decimal_to_binary(int(s[i]-'a'));
        int num_of_zero=5-binary.length();
        while(num_of_zero--){
            binary='0'+binary;
        }
        for(int i=0;i<binary.length();i++){
            if(binary[i]=='1') ans+='a';
            else ans+='b';
        }
    }
    cout<<ans<<"\n";
    return ans;
}
void de(string st,string s){
    // cout<<st<<"\n";
    string final_ans;
   
    for(int i=0;i<st.length();i+=5){
        string ans,target;
        // cout<<st.length();
        target=st.substr(i,5);
          // target=st[i]+st[i+1]+st[i+2]+st[i+3]+st[i+4];
        for(int i=0;i<target.length();i++){
            if(target[i]=='a') ans+='1';
            else ans+='0';
        }
        int num=binary_to_decimal(ans);
        //cout<<num<<"\n";
        final_ans+=char(num+'a');
        
    }
    for(int i=0;i<final_ans.length();i++){
        if(s[i]>='a' and s[i]<='z'){
            if(final_ans[i]>='A' and final_ans[i]<='Z')
            final_ans[i]=char(final_ans[i]-'A'+'a');
        }else {
            if(final_ans[i]>='a' and final_ans[i]<='z')
            final_ans[i]=char(final_ans[i]+'A'-'a');
        }
    }
    cout<<final_ans<<"\n";
    return ;
}
int main(){
    string s,ans;
    while(1){
        cout<<"Menu:\n1)Encryption\n2)Decryption\n3)Exit\n";
        int ch;cin>>ch;
        switch(ch){
            case 1:
                cout<<"Enter the string to be encrypted:\n";
                cin>>s;
                ans=en(s);
                break;
            case 2:
                cout<<"Enter the string wrt to which Decryption has to be done:\n";
                cin>>s;
                de(ans,s);
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