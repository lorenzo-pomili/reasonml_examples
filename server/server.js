const fs = require('fs');
const express = require('express');
const app = express();

const filepath = __dirname+"/mockData.json";

app.use("/", express.static(__dirname + '/../public'));

app.get('/getData', (request, response) => {
  fs.readFile(filepath, function (err, data) {
    if(err){
      throw err;
    }
    console.log("getData: ", JSON.stringify(data));
    response.json(JSON.parse(data));
  });
});

app.listen(8014);
