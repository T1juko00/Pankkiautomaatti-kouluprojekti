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
      'insert into transactions (id_transactions,DATE_CLOCK,events,amount,Account_id_number,) values(?,?,?,?,?)',
      [transactions.id_transactions, transactions.DATE_CLOCK, transactions.events,transactions.amount,transactions.Account_id_number,transactions.Account_id_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from transactions where id_transactions=?', [id], callback);
  },
  update: function(id, transactions, callback) {
    return db.query(
      'update transactions set id_transactions=?,DATE_CLOCK=?, events=?,amount=?,Account_id_number=?,where id_transactions=?',
      [transactions.id_transactions, transactions.DATE_CLOCK, transactions.events,transactions.amount,transactions.Account_id_number, id],
      callback
    );
  }
};
module.exports = transactions;