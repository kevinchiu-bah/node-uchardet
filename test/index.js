const test = require('ava');
const path = require('path');
const uchardet = require('../lib');

test('Module is exporting correctly', t => {
  const type = typeof(uchardet);
  t.is(type, 'function');
});

test('Detects and returns charset encoding of file', t => {
  const target = path.resolve(__dirname, './resources/sample.ssa');
  const charset = uchardet(target);
  const expected = 'TIS-620';
  t.is(charset, expected);
});

test('Call to version() returns the correct version number', t => {
  const version = uchardet.version();
  const expected = require('../package.json').libuchardet;
  t.is(version, expected);
});
