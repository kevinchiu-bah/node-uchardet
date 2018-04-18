# node-uchardet
> Native uchardet Binding for Node

For more information on the native binding: https://www.freedesktop.org/wiki/Software/uchardet/

## Install

### via npm
```shell
npm install -S node-uchardet@icemanbeta/uchardet
```

### via yarn
```shell
yarn add node-uchardet@icemanbeta/uchardet
```

## Usage

### Getting Started
#### CommonJS
```js
const uchardet = require('uchardet');
const charset = uchardet('/path/to/file');
```

#### ES6
```js
import { detect } from 'uchardet'
const charset = detect('/path/to/file');
```

### API
```js
detect(file)
```
* `file` [string]: Relative or absolute path to the file (**Note**: Relative path is resolved to `process.cwd()`, resolve prior if this doesn't work for you)

Example:

```js
const source = './test/resources/sample.ssa';
const charset = detect(source);
console.log(charset);
// => TIS-620
```

```js
version()
```
Example:

```js
console.log(version());
// => 0.0.6
```
