/* Mixin */
module Impl = (T: {type t;}) => {
  [@bs.get] external children : T.t => Dom.htmlCollection = "";
  [@bs.get] [@bs.return nullable] external firstElementChild : T.t => option(Dom.element) = "";
  [@bs.get] [@bs.return nullable] external lastElementChild : T.t => option(Dom.element) = "";
  [@bs.get] external childElementCount : T.t => int = "";
  [@bs.send] [@bs.return nullable] external querySelector : T.t => string => option(Dom.element) = "";
  [@bs.send] external querySelectorAll : T.t => string => Dom.nodeList = "";
};
