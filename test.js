var convert = require('./index');
var fs = require('fs');

fs.readFile('test.sass','utf8',function(e,d){
  if(!e){
    console.log(convert(d));
  }
});
