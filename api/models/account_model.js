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
  
  withdraw20: function(id,callback){
    return db.query(
      'update account set balance=balance-20 where id_account=?',
      [id],
      callback
    );
    
  }, 

  withdraw40: function(id,callback){
    return db.query(
      'update account set balance=balance-40 where id_account=?',
      [id],
      callback
    );
    
  },

  withdraw50: function(id,callback){
    return db.query(
      'update account set balance=balance-50 where id_account=?',
      [id],
      callback
    );
    
  }, 

  withdraw100: function(id,callback){
    return db.query(
      'update account set balance=balance-100 where id_account=?',
      [id],
      callback
    );
    
  },

  
};
module.exports = account;