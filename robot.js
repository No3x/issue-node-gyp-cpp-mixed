'use strict'

const { getSolution } = require('bindings')('robot')

// Use your bindings defined in your C files
module.exports = { getSolution }