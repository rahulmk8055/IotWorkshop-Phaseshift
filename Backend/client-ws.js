const ws = require('ws');

const client = new ws('ws://localhost:8080/register');

var obj = {
    macId : "1234"
}
client.on('open', () => {
  // Causes the server to print "Hello"
  client.send(JSON.stringify(obj));
});

