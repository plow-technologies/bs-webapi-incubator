/* Mixin */
module Impl = (T: {type t;}) => {
  [@bs.send] external remove : T.t => unit = "";
};
