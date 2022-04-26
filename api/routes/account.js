const express = require('express');
const router = express.Router();
const account = require('../models/account_model');


router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    account.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  } else {
    account.getAll(function(err, dbResult) {
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
  account.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  account.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  account.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
}); 

router.post('/withdrawlog/', 
function(request, response) {
<<<<<<< HEAD
  console.log ("request body",request.body.id_account, request.body.balance)
  params = {id_account,balance} = request.body
=======
  params = {amount, id_account} = request.body
>>>>>>> c0663870a12d2f8099e8b697f3581b4d20a8b29f
  account.withdrawlog(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});
 

module.exports = router;