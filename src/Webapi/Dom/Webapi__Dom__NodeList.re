type t = Dom.nodeList;

[@bs.val] external toArray : t => array(Dom.node) = "Array.prototype.slice.call";

[@bs.send] external forEach : t => ((Dom.node, int) => unit) => unit = "";

[@bs.get] external length : t => int = "";

[@bs.send] [@bs.return nullable] external item : t => int => option(Dom.node) = "";
