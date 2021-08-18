module Impl = (T: {type t;}) => {
  external asNode : T.t => Dom.node = "%identity";

  /* baseURI */
  [@bs.get] external childNodes : T.t => Dom.nodeList = "";
  [@bs.get] [@bs.return nullable] external firstChild : T.t => option(Dom.node) = "";
  [@bs.get] external innerText : T.t => string = "";
  [@bs.set] external setInnerText : (T.t, string) => unit = "innerText";
  [@bs.get] [@bs.return nullable] external lastChild : T.t => option(Dom.node) = "";
  [@bs.get] [@bs.return nullable] external nextSibling : T.t => option(Dom.node) = "";
  [@bs.get] external nodeName : T.t => string = ""; /* nodePrincipal */
  [@bs.get] external nodeType : T.t => int /* nodeType enum */ = "";
  let nodeType: T.t => Webapi__Dom__Types.nodeType = (self) => Webapi__Dom__Types.decodeNodeType(nodeType(self));
  [@bs.get] [@bs.return nullable] external nodeValue : T.t => option(string) = "";
  [@bs.set] external setNodeValue : (T.t, Js.null(string)) => unit = "nodeValue";
  /* let setNodeValue : T.t => option string => unit = fun self value => setNodeValue self (Js.Null.fromOption value); */ /* temporarily removed to reduce codegen size */
  /* Not supported yet
  external setNodeValue : T.t => string => unit = "nodeValue" [@@bs.set];
  external clearNodeValue : T.t => _ [@bs.as {json|null|json}] => unit = "nodeValue" [@@bs.set];
  */
  /* outerText */
  [@bs.get] external ownerDocument : T.t => Dom.document = "";
  [@bs.get] [@bs.return nullable] external parentElement : T.t => option(Dom.element) = "";
  [@bs.get] [@bs.return nullable] external parentNode : T.t => option(Dom.node) = "";
  [@bs.get] [@bs.return nullable] external previousSibling : T.t => option(Dom.node) = "";
  [@bs.get] external rootNode : T.t => Dom.node = "";
  [@bs.get] external textContent : T.t => string = "";
  [@bs.set] external setTextContent : (T.t, string) => unit = "textContent";

  [@bs.send] external appendChild : T.t => Dom.node_like('a) => unit = "";
  [@bs.send] external cloneNode : T.t => T.t = "";
  [@bs.send] external cloneNodeDeep : T.t => ([@bs.as {json|true|json}] _) => T.t = "cloneNode";
  [@bs.send] external compareDocumentPosition : T.t => Dom.node_like('a) => int = ""; /* returns a bitmask which could also be represeneted as an enum, see https://developer.mozilla.org/en-US/docs/Web/API/Node/compareDocumentPosition */
  [@bs.send] external contains : T.t => Dom.node_like('a) => bool = "";
  [@bs.send] external getRootNode : T.t => Dom.node = "";
  [@bs.send] external getRootNodeComposed : T.t => ([@bs.as {json|{ "composed": true }|json}] _) => Dom.node = "getRootNode";
  [@bs.send] external hasChildNodes : T.t => bool = "";
  [@bs.send] external insertBefore : T.t => (Dom.node_like('a), Dom.node_like('b)) => Dom.node_like('a) = "";
  /* (temporarily?) removed to reduce codegen size. This variant is just for convenience, `appendChild` can be used in place of passing `null` to `insertBefore`
  external insertBefore : Dom.node_like 'a => Js.null (Dom.node_like 'b) => Dom.node_like 'a = "" [@@bs.send.pipe: T.t];
  let insertBefore : Dom.node_like 'a => option (Dom.node_like 'b) => T.t => Dom.node_like 'a = fun node reference self => insertBefore node (Js.Null.fromOption reference) self;
  */
  [@bs.send] external isDefaultNamespace : T.t => string => bool = "";
  [@bs.send] external isEqualNode : T.t => Dom.node_like('a) => bool = "";
  [@bs.send] external isSameNode : T.t => Dom.node_like('a) => bool = "";
  [@bs.send] [@bs.return nullable] external lookupNamespaceURI : T.t => string => option(string) = "";
  [@bs.send] [@bs.return nullable] external lookupDefaultNamespaceURI : T.t => ([@bs.as {json|null|json}] _) => option(string) = "lookupNamespaceURI";
  [@bs.send] external lookupPrefix : T.t => string = "lookupPrefix";
  [@bs.send] external normalize : T.t => unit = "";
  [@bs.send] external removeChild : T.t => Dom.node_like('a) => Dom.node_like('a) = "";

  /** @since 0.19.0 */
  [@bs.send] external replaceChild : T.t => (Dom.node_like('a), Dom.node_like('b)) => Dom.node_like('b) = "";
};

type t = Dom.node;

include Webapi__Dom__EventTarget.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
