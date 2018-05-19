/**
* Parse CLI Arguments
*/
const fs = require('fs');
const mkdir = require('mkdirp');
const path = require('path');
const exec = require('child_process').exec;
const pkg = require('../package.json');

function parse(args) {
 const options = {
   force: (process.env.npm_config_force === 'true'),
 };

 options.args = args.filter(function(arg) {
   if (arg === '-f' || arg === '--force') {
     options.force = true;
     return false;
   } else if (arg === '-d' || arg === '--debug') {
     options.debug = true;
   }

   return true;
 });

 return options;
}

/**
 * Check Build to Verify Build Status
 */
function check(options) {
  console.log('Verifying Build!')

  if (options.force) {
    // Rebuild with force flag
    return true;
  }

  const build = {
    type: options.debug ? 'Debug' : 'Release',
    version: pkg.libuchardet,
    target: 'uchardet.node',
  };

  const binaryPath = path.join(__dirname, `../build/${build.type}/${build.target}`);
  const isBinaryExist = fs.existsSync(binaryPath);

  try {
    const wrapper = require(`../${pkg.main}`);

    // Rebuild on version mismatch
    if(wrapper.version() !== pkg.version) {
      console.log(`${wrapper.version()} !== ${pkg.version}`)
      return true
    }
  } catch(e) {
    // Rebuild on bad builds
    return true;
  }

  return false;
}

/**
 * Run Build
 */
function build(options) {
  const cmd = [
    path.normalize('./scripts/env.sh') + ' &&',
    'CXXFLAGS="-fPIC"',
    'node',
    require.resolve(path.normalize('node-gyp/bin/node-gyp.js')),
    'rebuild'
  ].concat(
  ([ 'verbose', 'debug'])
    .filter(function(flag) {
      return options[flag] ? true : false;
    })
    .map(function(flag) {
      return `--${flag}`;
    })
  ).join(' ');

  exec(cmd, function(error, stdout, stderr) {
    if(!error) {
      console.log('Binary successfully built!');
      return;
    } else if (error.code === 127 ) {
      console.error(`node-gyp isn't available at: ${gyp}`);
     } else {
       console.error('Build failed with error code:', error.code);
       console.info(error);
     }

     process.exit(1);
  });
}

/**
 * Apply arguments and run
 */
const options = parse(process.argv.slice(2));
const doBuild = check(options);

if(doBuild) {
  console.log('Starting build...');
  build(options);
} else {
  console.log('Integrity of binary verified - no build is neccessary! [node-gyp rebuild uchardet --force]');
}
