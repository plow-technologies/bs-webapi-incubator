type t = Dom.nodeIterator;

[@bs.get] external root : t => Dom.node = "";
[@bs.get] external referenceNode : t => Dom.node = "";
[@bs.get] external pointerBeforeReferenceNode : t => bool = "";
[@bs.get] external whatToShow : t => Webapi__Dom__Types.WhatToShow.t = "";
[@bs.get] [@bs.return nullable] external filter : t => option(Dom.nodeFilter) = "";

[@bs.send] [@bs.return nullable] external nextNode : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external previousNode : t => option(Dom.node) = "";
[@bs.send] external detach : t => unit = "";
