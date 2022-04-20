const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'veleho_123',
  database: 'bankautomat'
});
module.exports = connection;