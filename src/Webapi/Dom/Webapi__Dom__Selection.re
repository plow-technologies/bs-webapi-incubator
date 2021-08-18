type t = Dom.selection;

[@bs.get] [@bs.return nullable] external anchorNode : t => option(Dom.node) = "";
[@bs.get] external anchorOffset : t => int = "";
[@bs.get] [@bs.return nullable] external focusNode : t => option(Dom.node) = "";
[@bs.get] external focusOffset : t => int = "";
[@bs.get] external isCollapsed : t => bool = "";
[@bs.get] external rangeCount : t => int = "";

[@bs.send] external getRangeAt : t => int => Dom.range = "";
[@bs.send] external collapse : t => (Dom.node_like(_), int) => unit = "";
[@bs.send] external extend : t => (Dom.node_like(_), int) => unit = "";
[@bs.send] external collapseToStart : t => unit = "";
[@bs.send] external collapseToEnd : t => unit = "";
[@bs.send] external selectAllChildren : t => Dom.node_like(_) => unit = "";
[@bs.send] external setBaseAndExtent : t => (Dom.node_like(_), int,  Dom.node_like(_), int) => unit = "";
[@bs.send] external addRange : t => Dom.range => unit = "";
[@bs.send] external removeRange : t => Dom.range => unit = "";
[@bs.send] external removeAllRanges : t => unit = "";
[@bs.send] external deleteFromDocument : t => unit = "";
[@bs.send] external toString : t => string = "";
[@bs.send] external containsNode : t => (Dom.node_like(_), [@bs.as {json|false|json}] _) => bool = "";
[@bs.send] external containsNodePartly : t => (Dom.node_like(_), [@bs.as {json|true|json}] _) => bool = "containsNode";
