const db = require('../database');

const account = {
  getById: function(id, callback) {
    return db.query('select * from account where id_account=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from account', callback);
  },
  add: function(account, callback) {
    return db.query(
      'insert into account (balance,accountnumber) values(?,?)',
      [account.balance, account.accountnumber],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from account where id_account=?', [id], callback);
  },
  update: function(id, account, callback) {
    return db.query(
      'update account set balance=?,accountnumber=? where id_account=?',
      [account.balance,account.accountnumber, id],
      callback
    );
  },

  withdrawlog: function(params, callback) {
    
    return db.query(
      'CALL sp_withdrawmoney(?,?)',
      [params.amount, params.first_id],
      
      callback
    );
  } 


  
  
};
module.exports = account;