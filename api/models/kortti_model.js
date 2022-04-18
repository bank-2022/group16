const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.PIN, saltRounds, function
      (err,hash){
        return db.query(
          'insert into kortti (idkortti,Korttinumero,PIN,idTili,idAsiakas) values(?,?,?,?,?)',
          [kortti.idKortti, kortti.Korttinumero, hash,kortti.idTili,kortti.idAsiakas],
          callback );
        });
      },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.PIN, saltRounds, function
      (err,hash){
        return db.query(
          'update kortti set idkortti=?,Korttinumero=?,PIN=?,idTili=?,idAsiakas=? where idkortti=?',
          [kortti.idKortti, kortti.Korttinumero, hash,kortti.idTili,kortti.idAsiakas, id],
          callback );
        });
  }
};
module.exports = kortti;