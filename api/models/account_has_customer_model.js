const db = require('../database');

const account_has_customer = {
  getById: function(id, callback) {
    return db.query('select * from account_has_customer where id_account_has_customer=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account_has_customer', callback);
  },
  add: function(account_has_customer, callback) {
    return db.query(
      'insert into account_has_customer (account_id_number,customer_id_customer,account_has_customernumber) values(?,?,?)',
      [account_has_customer.account_id_number, account_has_customer.customer_id_customer, account_has_customer.customer_Account_id_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account_has_customer where id_account_has_customer=?', [id], callback);
  },
  update: function(id, account_has_customer, callback) {
    return db.query(
      'update account_has_customer set account_id_number=?,customer_id_customer=?, account_has_customernumber=? where id_account_has_customer=?',
      [account_has_customer.account_id_number, account_has_customer.customer_id_customer, account_has_customer.customer_Account_id_number, id],
      callback
    );
  }
};
module.exports = account_has_customer;