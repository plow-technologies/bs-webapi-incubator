type t = Dom.treeWalker;

[@bs.get] external root : t => Dom.node = "";
[@bs.get] external whatToShow : t => Webapi__Dom__Types.WhatToShow.t = "";
[@bs.get] [@bs.return nullable] external filter : t => option(Dom.nodeFilter) = "";
[@bs.get] external currentNode : t => Dom.node = "";
[@bs.set] external setCurrentNode : (t, Dom.node) => unit = "";

[@bs.send] [@bs.return nullable] external parentNode : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external firstChild : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external lastChild : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external previousSibling : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external nextSibling : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external previousNode : t => option(Dom.node) = "";
[@bs.send] [@bs.return nullable] external nextNode : t => option(Dom.node) = "";
