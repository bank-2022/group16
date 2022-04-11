const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where id_kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    return db.query(
      'insert into kortti (idkortti,Korttinumero,PIN,idTili,idAsiakas) values(?,?,?,?,?)',
      [kortti.idkortti, kortti.korttinumero, kortti.PIN,kortti.idTili,kortti.idAsiakas],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where id_kortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    return db.query(
      'update kortti set idkortti=?,Korttinumero=?,PIN=?,where id_Tili=?,where id_Asiakas=?, where id_kortti=?',
      [kortti.idkortti,kortti.Korttinumero,kortti.PIN,kortti.idTili,kortti.idAsiakas, id],
      callback
    );
  }
};
module.exports = kortti;