//establish that connection to the server to create the web socket between the two
//we have the access to the io variable since we have downloaded the library
var socket=io.connect('http://localhost:4000');//variable socket for the frontend {different from the one running on the server}

//Query DOM

var message = document.getElementById('message'),
    handle = document.getElementById('handle'),
    btn =document.getElementById('send'),
    output=document.getElementById('output'),
    feedback=document.getElementById('feedback');

//emit event 

btn.addEventListener('click',function(){ //call back function
    socket.emit('chat',{ //socket between ur client and browser //name and paarmeter :: emit event or msg, so that we can send it down the web socket to the server and recieve it on the client
        message: message.value, //send this data along with the msg to the server
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
    output.innerHTML+='<p><strong>'+data.handle+' : </strong>'+ans+'</p>'; //putting it in the HTML of the box
}); //individual socket for this client

//boardcasting msg

socket.on('typing',function(data){ //chat message recieved from the server and (perform function) then output it to the dom
    feedback.innerHTML='<p><em>'+data.handle+' is typing a message...</em></p>';
}); //individual socket for this client
