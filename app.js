var addon = require('./build/Release/QtQuery');

var query = new addon.QtQuery();

console.log("query : " + query);

console.log("result : " + query.getUserId("test"));

