// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var React       = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function str(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("Main");

function make() {
  var newrecord = component.slice();
  newrecord[/* render */9] = (function () {
      return React.createElement("div", undefined, "Hello world!");
    });
  return newrecord;
}

exports.str       = str;
exports.component = component;
exports.make      = make;
/* component Not a pure module */