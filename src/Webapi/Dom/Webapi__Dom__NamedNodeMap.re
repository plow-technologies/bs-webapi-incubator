type t = Dom.namedNodeMap;

[@bs.get] external length : t => int = "";

[@bs.send] [@bs.return nullable] external item : t => int => option(Dom.attr) = "";
[@bs.send] [@bs.return nullable] external getNamedItem : t => string => option(Dom.attr) = "";
[@bs.send] [@bs.return nullable] external getNamedItemNS : t => (string, string) => option(Dom.attr) = "";
[@bs.send] external setNamedItem : t => Dom.attr => unit = "";
[@bs.send] external setNamedItemNS : t => Dom.attr => unit = "";
[@bs.send] external removeNamedItem : t => string => Dom.attr = "";
[@bs.send] external removeNamedItemNS : t => (string, string) => Dom.attr = "";

[@bs.val] [@bs.scope ("Array", "prototype", "slice")] external toArray : t => array(Dom.attr) = "call";
