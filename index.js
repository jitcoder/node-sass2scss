var binding = require('bindings')('node_sass2scss.node');
var Sass2Scss = function(sassContents){
  return binding.convert(sassContents);
};

module.exports = Sass2Scss;
