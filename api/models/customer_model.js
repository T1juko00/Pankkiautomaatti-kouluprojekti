const db = require('../database');
const bcrypt = require('bcryptjs');
const saltRounds=10;

const customer = {
  getById: function(id, callback) {
    return db.query('select * from customer where id_customer=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  add: function(customer, callback) {
    bcrypt.hash(customer.password, saltRounds, function(err,hash) {
    return db.query(
      'insert into customer (fname,lname,password,username) values(?,?,?,?)',
      [customer.fname, customer.lname, hash , customer.username,],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from customer where id_customer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    bcrypt.hash(customer.password, saltRounds, function(err, hash) {
    return db.query(
      'update customer set fname=?, lname=?,password=?,username=? where id_customer=?',
      [customer.fname, customer.lname, hash,customer.username, id],
      callback)
    });
  },
  getBalance:function(username,callback){
    return db.query(
      'SELECT fname, lname, cardnumber, balance FROM card inner join customer on card.customer_id_customer = customer.id_customer inner join account  on account.id_account = card.account_id_account where username =?', [username],callback);
  }


};
module.exports = customer;