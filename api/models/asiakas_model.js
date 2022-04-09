const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where id_asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(asiakas, callback) {
    return db.query(
      'insert into asiakas (idasiakas,nimi,lähiosoite,puhelinnumero) values(?,?,?,?)',
      [asiakas.idasiakas, asiakas.nimi, asiakas.lähiosoite,asiakas.puhelinnumero],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where id_asiakas=?', [id], callback);
  },
  update: function(id, asiakas, callback) {
    return db.query(
      'update asiakas set idasiakas=?,nimi=?, lähiosoite=? where id_asiakas=?',
      [asiakas.idasiakas, asiakas.nimi, asiakas.lähiosoite,asiakas.puhelinnumero, id],
      callback
    );
  }
};
module.exports = asiakas;