const db = require('../database');

const customer = {
  getById: function(id, callback) {
    return db.query('select * from customer where id_customer=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from customer', callback);
  },
  add: function(customer, callback) {
    return db.query(
      'insert into customer (id_customer,fname,lname,password,username,Account_id_number) values(?,?,?,?,?,?)',
      [customer.id_customer, customer.fname, customer.lname,customer.password,customer.username,customer.Account_id_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from customer where id_customer=?', [id], callback);
  },
  update: function(id, customer, callback) {
    return db.query(
      'update customer set id_customer=?,fname=?, lname=?,password=?,username=?,Account_id_number=? where id_customer=?',
      [customer.id_customer, customer.fname, customer.lname,customer.password,customer.username,customer.Account_id_number, id],
      callback
    );
  }
};
module.exports = customer;