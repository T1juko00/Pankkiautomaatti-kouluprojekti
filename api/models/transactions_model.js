const db = require('../database');

const transactions = {
  getById: function(id, callback) {
    return db.query('select * from transactions where id_transactions=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from transactions', callback);
  },
  add: function(transactions, callback) {
    return db.query(
      'insert into transactions (events,amount,account_id_account) values(?,?,?)',
      [ transactions.events,transactions.amount,transactions.account_id_account],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where id_transactions=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(
      'update transactions set DATE_CLOCK=?, events=?,amount=?,account_id_account=? where id_transactions=?',
      [transactions.DATE_CLOCK, transactions.events,transactions.amount,transactions.account_id_account, id],
      callback
    );
  }
};
module.exports = transactions;