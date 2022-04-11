const db = require('../database');

const tili_asiakas = {
  getById: function(id, callback) {
    return db.query('select * from tili_asiakas where id_tili_asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili_asiakas', callback);
  },
  add: function(tili_asiakas, callback) {
    return db.query(
      'insert into tili_asiakas (idasiakas,idtili) values(?,?)',
      [tili_asiakas.idasiakas, tili_asiakas.idtili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili_asiakas where id_tili_asiakas=?', [id], callback);
  },
  update: function(id, tili_asiakas, callback) {
    return db.query(
      'update tili_asiakas set idasiakas=?,idtili=?, where id_tili_asiakas=?',
      [tili_asiakas.idasiakas, tili_asiakas.idtili, id],
      callback
    );
  }
};
module.exports = tili_asiakas;