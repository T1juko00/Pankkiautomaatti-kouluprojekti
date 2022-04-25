var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const helmet = require('helmet');
const cors = require('cors');
//const jwt = require('jsonwebtoken');

var indexRouter = require('./routes/index');
var loginRouter = require('./routes/login');
var accountRouter = require('./routes/account');
var account_has_customerRouter = require('./routes/account_has_customer');
var cardRouter = require('./routes/card');
var customerRouter = require('./routes/customer');
var transactionsRouter = require('./routes/transactions');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(helmet());
app.use(cors()); 


app.use('/', indexRouter);
app.use('/login', loginRouter);
//app.use(authenticateToken);

app.use('/account', accountRouter);
app.use('/account_has_customer', account_has_customerRouter);
app.use('/card', cardRouter);
app.use('/customer', customerRouter);
app.use('/transactions', transactionsRouter);
 


/*function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, (err, user) => {
      console.log(err)
  
      if (err) return res.sendStatus(403)
  
      req.user = user
  
      next()
    })
  }*/


module.exports = app;
