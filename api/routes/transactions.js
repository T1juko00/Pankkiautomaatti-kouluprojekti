const express = require('express');
const router = express.Router();
const transactions = require('../models/transactions_model');

router.get('/:id?',
 function(request, response) {
  if (request.params.id) {
    transactions.getById(request.params.id, function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult.rows);
      }
    });
  } else {
    transactions.getAll(function(err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        console.log(dbResult.rows);
        response.json(dbResult.rows);
      }
    });
  }
});


router.post('/', 
function(request, response) {
  transactions.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  transactions.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  transactions.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

module.exports = router;