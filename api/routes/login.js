const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const login = require('../models/login_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    if(request.body.Korttinumero && request.body.PIN){
      const Korttinumero = request.body.Korttinumero;
      const PIN = request.body.PIN;
        login.checkPIN(Korttinumero, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(PIN,dbResult[0].PIN, function(err,compareResult) {
                if(compareResult) {
                  console.log("Success!");
                  const token = generateAccessToken({Korttinumero: Korttinumero});
                  response.send(token);
                }
                else {
                    console.log("Wrong PIN!");
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("User does not exists");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("Card number or PIN missing!");
      response.send(false);
    }
  }
);

function generateAccessToken(Korttinumero) {
  dotenv.config();
  return jwt.sign(Korttinumero, process.env.MY_TOKEN, { expiresIn: '1800s' });
}
module.exports=router;