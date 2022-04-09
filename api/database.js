const mysql = require('mysql');
const connection = mysql.createPool({
  host: 'localhost',
  user: 'banksimuluser',
  password: 'banksimulpass',
  database: 'banksimul'
});
module.exports = connection;