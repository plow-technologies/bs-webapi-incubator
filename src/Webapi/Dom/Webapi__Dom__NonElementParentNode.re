/* Mixin */
module Impl = (T: {type t;}) => {
  [@bs.send] [@bs.return nullable] external getElementById : T.t => string => option(Dom.element) = "";
};
