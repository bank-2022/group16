var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var asiakasRouter = require('./routes/asiakas');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var KorttiRouter = require('./routes/Kortti');
var tiliRouter = require('./routes/tili');
var tili_asiakasRouter = require('./routes/tili_asiakas');

const { application } = require('express');
const helmet = require('helmet');
const cors = require('cors');

var app = express();


app.use(helmet());
app.use(cors());
app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/asiakas', asiakasRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/Kortti', KorttiRouter);
app.use('/tili', tiliRouter);
app.use('/tili_asiakas', tili_asiakasRouter);

module.exports = app;
