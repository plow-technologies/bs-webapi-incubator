type t = Dom.treeWalker;

[@bs.get] external root : t => Dom.node = "";
[@bs.get] external whatToShow : t => Webapi__Dom__Types.WhatToShow.t = "";
[@bs.get] [@bs.return nullable] external filter : t => option(Dom.nodeFilter) = "";
[@bs.get] external currentNode : t => Dom.node = "";
[@bs.set] external setCurrentNode : (t, Dom.node) => unit = "";

[@bs.send] [@bs.return nullable] external parentNode : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external firstChild : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external lastChild : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external previousSibling : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external nextSibling : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external previousNode : T.t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external nextNode : T.t => option(Dom.node) = "";
