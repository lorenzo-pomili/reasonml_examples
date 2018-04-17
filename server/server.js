const fs = require('fs');
const express = require('express');
const app = express();

const filepath = __dirname+"/mockData.json";
const filepathStorage = __dirname+"/dataStorage.json";

app.use("/", express.static(__dirname + '/../public'));

const getData = (request, response, path) => {
  fs.readFile(path, function (err, data) {
    if(err){
      throw err;
    }
    console.log("getData: ", JSON.stringify(data));
    response.json(JSON.parse(data));
  });
}

app.get('/getData', (request, response) => {
   getData(request, response, filepath);
});

app.get('/getDataStorage', (request, response) => {
  getData(request, response, filepathStorage);
});

const writeFile = (filepath, fileContent) => {
  fs.writeFile(filepath, JSON.stringify(fileContent), (err) => {
    if (err) throw err;

    console.log("The file was succesfully saved!");
  });
};

app.post('/setData', (req, res) => {
  let bodyStr = '';
  req.on("data",function(chunk){
      bodyStr += chunk.toString();
  });
  req.on("end",function(){
      console.log(bodyStr);
      writeFile(filepathStorage, JSON.parse(bodyStr));
      res.send(bodyStr);
  });
});

app.all("*", function(req, res){
    res.sendfile('index.html', { root: __dirname + '/../public' } );
});

app.listen(8014);
console.log("App served on: http://localhost:8014");
