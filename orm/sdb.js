const net = require('net');

let client = null;

const ORM = {
  connect(port = 8080, host = '127.0.0.1') {
    client = new net.Socket();
    client.connect(port, host, () => {
      console.log("Connected to C DB");
    });
  },

  query(sql, callback) {
    if (!client) {
      callback("Not connected.", null);
      return;
    }

    client.write(sql + '\n');
    client.once('data', (data) => {
      callback(null, data.toString());
    });
  }
};

module.exports = ORM;
