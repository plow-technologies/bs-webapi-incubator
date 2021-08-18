type t = Dom.range;

[@bs.new] external make : unit => t = "Range"; /* experimental */

[@bs.get] external collapsed : t => bool = "";
[@bs.get] external commonAncestorContainer : t => Dom.node = "";
[@bs.get] external endContainer : t => Dom.node = "";
[@bs.get] external endOffset : t => int = "";
[@bs.get] external startContainer : t => Dom.node = "";
[@bs.get] external startOffset : t => int = "";

[@bs.send] external setStart : t => (Dom.node_like('a), int) => unit = "";
[@bs.send] external setEnd : t => (Dom.node_like('a), int) => unit = "";
[@bs.send] external setStartBefore : t => Dom.node_like('a) => unit = "";
[@bs.send] external setStartAfter : t => Dom.node_like('a) => unit = "";
[@bs.send] external setEndBefore : t => Dom.node_like('a) => unit = "";
[@bs.send] external setEndAfter : t => Dom.node_like('a) => unit = "";
[@bs.send] external selectNode : t => Dom.node_like('a) => unit = "";
[@bs.send] external selectNodeContents : t => Dom.node_like('a) => unit = "";
[@bs.send] external collapse : t => unit = "";
[@bs.send] external collapseToStart : t => ([@bs.as {json|true|json}] _) => unit = "collapse";
[@bs.send] external cloneContents : t => Dom.documentFragment = "";
[@bs.send] external deleteContents : t => unit = "";
[@bs.send] external extractContents : t => Dom.documentFragment = "";
[@bs.send] external insertNode : t => Dom.node_like('a) => unit = "";
[@bs.send] external surroundContents : t => Dom.node_like('a) => unit = "";
[@bs.send] external compareBoundaryPoints : t => (int /* compareHow enum */, t) => int /* compareResult enum */ = "";
let compareBoundaryPoint: (Webapi__Dom__Types.compareHow, t, t) => Webapi__Dom__Types.compareResult =
  (how, range, self) =>
    Webapi__Dom__Types.decodeCompareResult(
      compareBoundaryPoints(self, Webapi__Dom__Types.encodeCompareHow(how), range)
    );
[@bs.send] external cloneRange : t => t = "";
[@bs.send] external detach : t => unit = "";
[@bs.send] external toString : t => string = "";
[@bs.send] external comparePoint : t => (Dom.node_like('a), int) => int /* compareRsult enum */ = "";
let comparePoint: (Dom.node_like('a), int, t) => Webapi__Dom__Types.compareResult =
  (node, offset, self) => Webapi__Dom__Types.decodeCompareResult(comparePoint(self, node, offset));
[@bs.send] external createContextualFragment : t => string => Dom.documentFragment = ""; /* experimental, but widely supported */
[@bs.send] external getBoundingClientRect : t => Dom.domRect = ""; /* experimental, but widely supported */
[@bs.send] external getClientRects : t => array(Dom.domRect) = ""; /* experimental, but widely supported */
[@bs.send] external intersectsNode : t => Dom.node_like('a) => bool = "";
[@bs.send] external isPointInRange : t => (Dom.node_like('a), int) => bool = "";
