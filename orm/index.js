const ORM = require('./sdb');

ORM.connect(8080, '127.0.0.1');


ORM.query('select', (err, result) => {
  if (err) return console.error(err);
  console.log("Intial Data",result);
});

ORM.query('insert 2 sahil sahil@gmail.com', (err, result) => {
  if (err) return console.error(err)
    console.log("Data inserted")    
});
ORM.query('insert 3 john sahil@gmail.com', (err, result) => {
  if (err) return console.error(err)
    console.log("Data inserted")   
});


ORM.query('select', (err, result) => {
  if (err) return console.error(err);
  console.log("Final Data",result);
});