const bindings = require('bindings')('uchardet');
const settings = require('../package.json');
const path = require('path');

const detect = (file) => {
  const _ = bindings();
  const source = path.resolve(file);

  try {
    const charset = _.detect(source);
    return charset;
  } catch(e) {
    console.log(e);
  }
}

Object.defineProperty(exports, "__esModule", {
  value: true
});

const version = () => settings.libuchardet;

exports.default = detect;
exports.detect = detect;
exports.version = version;

module.exports = exports.default;
module.exports.version = version;
