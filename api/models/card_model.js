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
      'insert into card (id_card,cardnumber,pincode,Account_id_number,customer_id_customer,customer_Account_id_number) values(?,?,?,?,?,?)',
      [card.id_card, card.cardnumber, card.pincode,card.Account_id_number,card.customer_id_customer,card.customer_Account_id_number],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from card where id_card=?', [id], callback);
  },
  update: function(id, card, callback) {
    return db.query(
      'update card set id_card=?,cardnumber=?, pincode=?,Account_id_number=?,customer_id_customer=?,customer_Account_id_number=? where id_card=?',
      [card.id_card, card.cardnumber, card.pincode,card.Account_id_number,card.customer_id_customer,card.customer_Account_id_number, id],
      callback
    );
  }
};
module.exports = card;