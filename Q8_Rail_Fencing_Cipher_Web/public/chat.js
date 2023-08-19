//establish that connection to the server to create the web socket between the two
//we have the access to the io variable since we have downloaded the library
var socket=io.connect('http://localhost:4000');//variable socket for the frontend {different from the one running on the server}

//Query DOM

var message = document.getElementById('message'),
    handle = document.getElementById('handle'),
    btn = document.getElementById('send'),
    output = document.getElementById('output'),
    feedback = document.getElementById('feedback');

//emit event 

btn.addEventListener('click',function(){ //call back function
    var length=message.value.length;
    console.log(length)
    // function createArray(length) {
    //     var arr = new Array(length || 0),
    //         i = length;
      
    //     if (arguments.length > 1) {
    //         var args = Array.prototype.slice.call(arguments, 1);
    //         while(i--) arr[length-1 - i] = createArray.apply(this, args);
    //     }
      
    //     return arr;
    // }
    key=3;
    var mat=Array(key).fill(Array(length).fill('\0'));
    // var mat= createArray(key,length);
    // console.log(mat);
    flag=true;
    
    // for(let i=0;i<length;i++){
    //     for(let j=0;j<key;j++){
    //         mat[i][j]='\0';
    //     }
    // }
    let j=0;
    for(let i=0;i<length;i++){
        // console.log(i,message.value[i],j);
        if(flag){
            mat[i][j]=message.value[i];
            j=j+1;
        }else{
            // console.log('x');
            // console.log(i,j);
            mat[i][j]=message.value[i];
            // console.log('x');
            j=j-1;
        }
        if(i && i%(key-1)==0){
            if(flag){
                j-=2;

            }else{
                j+=2;
            } flag=!flag;
            // console.log(flag);
        }
    // } console.log(mat);  
    }
    encrypted_string="";
    for(let i=0;i<length;i++){
        for(let j=0;j<key;j++){
            if(mat[i][j]!='\n') encrypted_string+=mat[i][j];
        }
    }

    console.log('Encryted String',encrypted_string);
    socket.emit('chat',{ //socket between ur client and browser //name and parameter :: emit event or msg, so that we can send it down the web socket to the server and recieve it on the client
        
        
        message: encrypted_string, //send this data along with the msg to the server
        handle: handle.value
    })
}); //vanilla javascript for listening to event

message.addEventListener('keypress',function(){ //call back function
    socket.emit('typing',{ //socket between ur client and browser //name and parameter :: emit event or msg, so that we can send it down the web socket to the server and recieve it on the client
        //send this data along with the msg to the server
        handle: handle.value
    })
});

//output it to the screen
//listen for event on frontend

socket.on('chat',function(data){ //chat message recieved from the server and (perform function) then output it to the dom
    feedback.innerHTML='';
    ans=false;
    if(message.data==data.message) ans=true;
    output.innerHTML+='<p><strong>'+data.handle+' : </strong>'+ans+'</p>'; //putting it in the HTML of the box
}); //individual socket for this client

//boardcasting msg

socket.on('typing',function(data){ //chat message recieved from the server and (perform function) then output it to the dom
    feedback.innerHTML='<p><em>'+data.handle+' is typing a message...</em></p>';
}); //individual socket for this client
