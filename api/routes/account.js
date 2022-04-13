const express = require('express');
const router = express.Router();
const account = require('../models/account_model');
const transactions = require('../models/transactions_model');

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

router.get('/withdraw20/:id', 
function(request, response) {
  if(request.params.id) {
  account.withdraw20(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else { 
      
      response.json(dbResult);

    }
  });
}
}); 

router.get('/withdraw40/:id', 
function(request, response) {
  if(request.params.id) {
  account.withdraw40(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else { 
      
      response.json(dbResult);

    }
  });
}
}); 

router.get('/withdraw50/:id', 
function(request, response) {
  if(request.params.id) {
  account.withdraw50(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else { 
      
      response.json(dbResult);

    }
  });
}
}); 

router.get('/withdraw100/:id', 
function(request, response) {
  if(request.params.id) {
  account.withdraw100(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else { 
      
      response.json(dbResult);

    }
  });
}
}); 

module.exports = router;