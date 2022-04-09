const db = require('../database');

const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(tilitapahtumat, callback) {
    return db.query(
      'insert into tilitapahtumat (idtilitapahtumat,Päiväys,Tapahtuma,Summa,idtili,idkortti) values(?,?,?,?,?,?)',
      [tilitapahtumat.idtilitapahtumat, tilitapahtumat.Päiväys, tilitapahtumat.Tapahtuma,tilitapahtumat.Summa,tilitapahtumat.idtili,tilitapahtumat.idkortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where id_tilitapahtumat=?', [id], callback);
  },
  update: function(id, tilitapahtumat, callback) {
    return db.query(
      'update tilitapahtumat set idtilitapahtumat=?,Päiväys=?, Tapahtuma=?, where Summa=?,where idtili=?,where idkortti=?',
      [tilitapahtumat.idtilitapahtumat, tilitapahtumat.Päiväys, tilitapahtumat.Tapahtuma,tilitapahtumat.Summa,tilitapahtumat.idtili,tilitapahtumat.idkortti, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;