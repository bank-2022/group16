const db = require('../database');

const login={
  checkPIN: function(Korttinumero, callback) {
      return db.query('SELECT PIN FROM kortti WHERE Korttinumero = ?',[Korttinumero], callback); 
    }
};
          
module.exports = login;