const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'root',
<<<<<<< HEAD
  password: 'veleho_123',
=======
  password: 'Kalamiehen2toveri?',
>>>>>>> 903923fea8ad51008ca09c788cd956e8e7c3595a
  database: 'bankautomat'
});
module.exports = connection;