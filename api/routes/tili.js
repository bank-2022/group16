const express = require('express');
const router = express.Router();
const tili = require('../models/tili_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    tili.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    tili.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  tili.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  tili.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  tili.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
// UUSI
router.get('/Saldo/:Korttinumero',
function(request,response){
  tili.getSaldo(request.params.Korttinumero, function(err,dbResult){
    console.log(request.params.Korttinumero)
  if(err){
    response.json(err);
  }
  else{
    response.json(dbResult);
  }
});
});
  router.put('/Saldo/Nosto/:Korttinumero',
function(request,response){
  tili.updateSaldo(request.params.Korttinumero,request.body.amount, function(err,dbResult){
    console.log(request.params.Korttinumero)
  if(err){
    response.json(err);
  }
  else{
    response.json(dbResult);
  }
});
});
// UUSI

module.exports = router;