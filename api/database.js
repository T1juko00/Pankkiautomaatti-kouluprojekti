const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
  password: 'veleho_123',
  database: 'bankautomat',
  multipleStatements: true
});
module.exports = connection;