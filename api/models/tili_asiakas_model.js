const db = require('../database');

const tili_asiakas = {
  getById: function(id, callback) {
    return db.query('select * from tili_asiakas where tili_asiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili_asiakas', callback);
  },
  add: function(tili_asiakas, callback) {
    return db.query(
      'insert into tili_asiakas (idAsiakas,idTili) values(?,?)',
      [tili_asiakas.idAsiakas, tili_asiakas.idTili],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili_asiakas where tili_asiakas=?', [id], callback);
  },
  update: function(id, tili_asiakas, callback) {
    return db.query(
      'update tili_asiakas set idAsiakas=?,idTili=? where tili_asiakas=?',
      [tili_asiakas.idAsiakas, tili_asiakas.idTili, id],
      callback
    );
  }
};
module.exports = tili_asiakas;