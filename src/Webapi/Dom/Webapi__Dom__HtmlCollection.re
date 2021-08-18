type t = Dom.htmlCollection;

[@bs.val] [@bs.scope ("Array", "prototype", "slice")] external toArray : t => array(Dom.element) = "call";

[@bs.get] external length : t => int = "";
[@bs.send] [@bs.return nullable] external item : t => int => option(Dom.element) = "";
[@bs.send] [@bs.return nullable] external namedItem : t => string => option(Dom.element) = "";
