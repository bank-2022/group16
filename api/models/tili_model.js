const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(tili, callback) {
    return db.query(
      'insert into tili (idTili,Tilinumero,Saldo) values(?,?,?)',
      [tili.idTili, tili.Tilinumero, tili.Saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idTili=?', [id], callback);
  },
  update: function(id, tili, callback) {
    return db.query(
      'update tili set idTili=?,Tilinumero=?, Saldo=? where idTili=?',
      [tili.idTili, tili.Tilinumero, tili.Saldo, id],
      callback
    );
  },    // UUSI
  getSaldo:function(Korttinumero,callback){
    return db.query('select Saldo from tili inner join Kortti on tili.idTili=Kortti.idTili where Korttinumero=?', [Korttinumero],callback);
  },
  updateSaldo:function(idTili,amount, callback)     /*(Korttinumero, callback)*/{
    return db.query(
      //'update tili set amount=?, Saldo=(Saldo - amount) inner join Kortti on tili.idTili=Kortti.idTili where Korttinumero=?',[amount,Korttinumero], callback);
    'update tili set amount=?, Saldo=(Saldo - amount) where idTili=?', [amount,idTili],callback)
    
  }   

};
module.exports = tili;