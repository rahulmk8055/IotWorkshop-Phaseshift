// BASE SETUP
// =============================================================================

// call the packages we need
var express    = require('express');        // call express
var app        = express();                 // define our app using express
var bodyParser = require('body-parser');
var cors = require('cors')
var appWs = require('express-ws')(app);

app.use(cors())

//this is related to Project 2 (Websocket Client List)
class Clients {
    constructor(){
      this.clientList = {};
      this.registerClient = this.registerClient.bind(this);
      this.deregisterClient = this.deregisterClient.bind(this);
    }
    registerClient(macid, client) {
      this.clientList[macid] = client
    }
    deregisterClient(macid) {
        delete this.clientList[macid];
      }
  }

// Varibale to store sensor State  
let sensorState = {
    temperature : 0,
    humidity : 0
}

// create a instance of Client Object
const clients = new Clients();

// configure app to use bodyParser()
// this will let us get the data from a POST
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var port = process.env.PORT || 8080;        // set our port

// ROUTES FOR OUR API
// =============================================================================
var router = express.Router();              // get an instance of the express Router

// test route to make sure everything is working (accessed at GET http://localhost:8080/api)
router.get('/', function(req, res) {
    res.json({ message: 'hooray! welcome to our api!' });
});



/* ---------- Project 1 ------------------------------------------------*/
// Sensor Data is Received here
router.route('/sensor').post(function(req, res){

  var temperature = req.body.temperature;
  var humidity = req.body.humidity;
  console.log("Received sensor data " + JSON.stringify(req.body));
  sensorState.temperature = temperature;
  sensorState.humidity = humidity;
  res.json("received data in server from nodemcu");

})

// This API is used by FrontEnd
router.route('/sensor').get(function(req, res){
  
  // console.log("Received Get request for sensor API!")
  res.json(sensorState);

})

/* ---------- ------------------------------------------------*/




/* ---------- Project 2 ------------------------------------------------*/

app.ws('/register', function(ws, req) {
    ws.on('message', function(msg) {
      const parsedMsg = JSON.parse(msg);
      console.log("New Device Registering: " + msg);
      clients.registerClient(parsedMsg.macId,ws)
     
    });
  });

  

// Main API
router.route('/sendMessage').post(function(req, res) {


    var macId = req.body.macId;
    var state  = req.body.state;

    let obj = {
        macId : macId,
        state : state
    }
    if (clients.clientList[macId] != undefined){
            clients.clientList[macId].send(JSON.stringify(obj));
            console.log("Sending message to device" + JSON.stringify(obj));
            res.json("message sent");
            return
    } else {
            res.json("websocket connection does not exist")
    }
})


// Main API
router.route('/connectedDevices').get(function(req, res){

    const keys = Object.keys(clients.clientList); 
    let obj = {
        devices : keys
    };
    console.log("These are the connected devices " + JSON.stringify(obj))
    res.json(obj);

})

router.route("/deleteDevice").post(function (req, res) {
    const macid = req.body.macid;
    clients.deregisterClient(macid);
    res.send({
      msg: 'MacId Deleted',
      devices: clients.clientList
    })
  });

// REGISTER OUR ROUTES -------------------------------
// all of our routes will be prefixed with /api
app.use('/api', router);
// app.use(express.json())

// START THE SERVER
// =============================================================================
server = app.listen(port);
console.log('Magic happens on port ' + port);