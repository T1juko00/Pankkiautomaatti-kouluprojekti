const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_number=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (id_number,balance,accountnumber) values(?,?,?)',
      [account.id_number, account.balance, account.accountnumber],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_number=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set id_number=?,balance=?, accountnumber=? where id_number=?',
      [account.id_number, account.balance, account.accountnumber, id],
      callback
    );
  }
};
module.exports = account;