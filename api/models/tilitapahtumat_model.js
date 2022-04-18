const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (idTilitapahtumat,Paivays,Tapahtuma,Summa,idTili,idKortti) values(?,?,?,?,?,?)',
      [tilitapahtumat.idTilitapahtumat, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma,tilitapahtumat.Summa,tilitapahtumat.idTili,tilitapahtumat.idKortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set idTilitapahtumat=?,Paivays=?, Tapahtuma=?, Summa=?,idTili=?, idKortti=? where idTilitapahtumat=?',
      [tilitapahtumat.idTilitapahtumat, tilitapahtumat.Paivays, tilitapahtumat.Tapahtuma,tilitapahtumat.Summa,tilitapahtumat.idTili,tilitapahtumat.idKortti, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;