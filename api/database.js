const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'Kalamiehen2toveri?',
  database: 'bankautomat'
});
module.exports = connection;