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
    console.log("Message Recieved Successfully!");
    socket.broadcast.emit(message);
  });
  socket.on("message",function(message){ 
    socket.broadcast.emit(message);//send to the different clients connected to that socket , so tht everyone present on the chatroom  can see the message //emit msg/event to all sockets except the client who is typing (broadcasting message)
});



  ws.on("close", () => {
    console.log("Client disconnected");
  });
});