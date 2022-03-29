const db = require('../database');

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    return db.query(
      'insert into card (cardnumber,pincode,customer_id_customer,account_id_account) values(?,?,?,?)',
      [card.cardnumber, card.pincode,card.customer_id_customer,card.account_id_account],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    return db.query(
      'update card set cardnumber=?, pincode=?,customer_id_customer=?,account_id_account=? where id_card=?',
      [card.cardnumber, card.pincode,card.customer_id_customer,card.account_id_account,id],
      callback
    );
  }
};
module.exports = card;