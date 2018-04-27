"use strict";

const uchardet = require('bindings')('uchardet').uchardet;
const fs = require('fs');
const path = require('path');

class UChardet {
  constructor() {
    this._ = new uchardet();
  }

  detect(file) {
    const _ = this._;
    const source = path.resolve(file);

    if(!fs.existsSync(source)) {
      console.error('The file @ ' + source + ' does not exist, please try a different path!');
    }

    try {
      const charset = _.detect(source);
      return charset;
    } catch(e) {
      console.error(e);
    }
  }

  version() {
    return this._.version();
  }
}

module.exports = UChardet;
module.exports.UChardet = UChardet;
