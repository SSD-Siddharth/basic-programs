var http = require("http");
let fs = require('fs');
var server= http.createServer (function (request, response){
//response.writeHead (200, {'Content Type': 'text/
fs.readFile('./SSD_Prime.html', null, function (error,data){
    if (error) {
        response.writeHead(404);
        respone.write('Whoops! File not');
    }
    else {
        response.write(data);
    }
    response.end();
  });
});
server.listen(8081);
// Console will print the message
console.log('Successful Server running at http://127.0.0.1:8081/ or http://localhost:8081/')
