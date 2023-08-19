ans='string';
    char=false;
    inte=false;
    for(let i=0;i<data.message.length;i++){
        if(data.message[i]=='.'){
            ans='float';
            break;
        }
        else if(data.message[i]=='1' || data.message[i]=='2' || data.message[i]=='3'|| data.message[i]=='4'|| data.message[i]=='5'
        || data.message[i]=='6'|| data.message[i]=='7'|| data.message[i]=='8' || data.message[i]=='9' || data.message[i]=='0'){
            ans='Integer';
            inte=true;
        }
        else{
            char=true;
        }

        
    }
    if(char && inte) ans='alphanumeric'