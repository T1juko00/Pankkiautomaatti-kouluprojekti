const db = require('../database');
const bcrypt = require('bcryptjs');
const saltRounds=10;

const card = {
  getById: function(id, callback) {
    return db.query('select * from card where id_card=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from card', callback);
  },
  add: function(card, callback) {
    bcrypt.hash(card.pincode, saltRounds, function(err, hash){
    return db.query(
      'insert into card (cardnumber,pincode,customer_id_customer,account_id_account) values(?,?,?,?)',
      [card.cardnumber, hash,card.customer_id_customer,card.account_id_account],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    bcrypt.hash(card.pincode, saltRounds, function(err, hash) {
    return db.query(
      'update card set cardnumber=?, pincode=?,customer_id_customer=?,account_id_account=? where id_card=?',
      [card.cardnumber, hash,card.customer_id_customer,card.account_id_account,id],
      callback)
    });
  }
};
module.exports = card;