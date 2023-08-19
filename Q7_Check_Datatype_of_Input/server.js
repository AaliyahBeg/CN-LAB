const { WebSocketServer } = require("ws");
const wss = new WebSocketServer({ port: 5000 });
const readline = require("readline");

console.log("Listening on port 5000");

//singleton readline
let rl;

/**
 * @description
 * 1. wss.on('connection') is triggered when the client is connected to the server
 * 2. ws.on('message') is triggered when the client sends a message to the server
 * 3. ws.on('close') is triggered when the client is disconnected from the server
 */
wss.on("connection", (ws) => {
  console.log("Client connected");

  ws.on("message", (message) => {
    console.log("\nClient: " + message);
    //pass the message to getdatatype() function which will later call getdatatype function
    dt=getdatatype(message);
  });

  

  const getdatatype = (message) => {
    ans='string';
    char=false;
    inte=false;
    for(let i=0;i<message.length;i++){
        if(message[i]=='.'){
            ans='float';
            break;
        }
        else if(message[i]=='1' || message[i]=='2' || message[i]=='3'|| message[i]=='4'|| message[i]=='5'
        || message[i]=='6'|| message[i]=='7'|| message[i]=='8' || message[i]=='9' || message[i]=='0'){
            ans='Integer';
            inte=true;
        }
        else{
            char=true;
        }

        
    }
    if(char && inte) ans='alphanumeric'
    console.log("Datatype of message: " + ans);
    return ans;
  };

  ws.on("close", () => {
    console.log("Client disconnected");
  });
});