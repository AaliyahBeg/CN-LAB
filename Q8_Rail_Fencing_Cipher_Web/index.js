var express=require('express'); //node clever enough to look for express in node_modules
var socket=require('socket.io');
//App setup
var app=express();
var server=app.listen(4000,function(){ //we create an express app and store it in this server and store it in this variable so that we can pass it so the socket function
    console.log('listening to requests on port 4000');
});
// Static files middleware to serve public or static files
app.use(express.static('public')); //part of express ..specify a folder (public folder)

//Socket Setup
var io = socket(server); //invoke the function and pass the parameter i.e what server we wanna work on
//waiting for a connection
// (setup on backend)
io.on('connection',(socket)=>{ //call back function which fires --socket variable refer to the instance when that particular 
    //socket is made every client has their own socket . this socket parameter is that socket between tht particular client and server
    console.log('made socket connection',socket.id);
    //listen to the msg sent to us by client

    socket.on('chat',function(data){ //listening to all my sockets; when I hear tht chat msg sent to me , I will fire tht call back fn  ..  recieve the data and pass it to this function 
        //decryption
        key=3;
        var decrypted_string="";
        function createArray(length) {
            var arr = new Array(length || 0),
                i = length;
          
            if (arguments.length > 1) {
                var args = Array.prototype.slice.call(arguments, 1);
                while(i--) arr[length-1 - i] = createArray.apply(this, args);
            }
          
            return arr;
        }
        
        flag=false;
        console.log(data.message);
        len=data.length;
        var array= createArray(key,len);
        for(let i=0;i<data.message;i++){
            for(let j=0;j<key;j++){
                mat[i][j]='\n';
            }
        }
        for(let i=0;j<data.message;j++){
            if(flag){
                for(let j=0;j<key;j++){
                    mat[i][j]='*';
                }
            }else{
                for(let j=key-1;j>-1;j--){
                    mat[i][j]='*';
                }
            }
            flag=!flag;
        }   
        for(var i=0;i<len;i++){
            for(var j=0;j<key;j++){
                if(mat[i][j]=='*') mat[i][j]=data.message[i];
            }
        }
        for(var j=0;j<key;j++){
            for(var i=0;i<len;i++){
                if(mat[i][j]!='*') decrypted_string+=mat[i][j];
            }
        }
        //sending decrypted string 
        console.log('Decryted String',decrypted_string);
        data.message=decrypted_string;
        io.sockets.emit('chat',data);//send to the different clients connected to that socket , so tht everyone present on the chatroom  can see the message //emit msg/event to all sockets
    });//socket between the server and client that is sending the msg between the sever and the client ; listening to the 'chat' msg coming to the server and fire the function and recieve the data we sent from the client
    socket.on('typing',function(data){ 
        socket.broadcast.emit('typing',data);//send to the different clients connected to that socket , so tht everyone present on the chatroom  can see the message //emit msg/event to all sockets except the client who is typing (broadcasting message)
    });
});