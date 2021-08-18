/* internal, moved out of Impl to reduce unnecessary code duplication */
let ofNode = (node: Dom.node) : option('a) =>
  Webapi__Dom__Node.nodeType(node) == Webapi__Dom__Types.Element ?
    Some(Obj.magic(node)) :
    None;

module Impl = (T: {type t;}) => {
  let asHtmlElement: T.t => option(Dom.htmlElement) = [%raw {|
    function(element) {
      var ownerDocument = element.ownerDocument;

      if (ownerDocument != null) {
        var defaultView = ownerDocument.defaultView;

        if (defaultView != null) {
          var HTMLElement = defaultView.HTMLElement;

          if (HTMLElement != null && element instanceof HTMLElement) {
            return element;
          }
        }
      }
    }
  |}];

  /** Unsafe cast, use [asHtmlElement] instead */
  external unsafeAsHtmlElement : T.t => Dom.htmlElement = "%identity";

  let ofNode: Dom.node => option(T.t) = ofNode;

  [@bs.get] external attributes : T.t => Dom.namedNodeMap = "";
  [@bs.get] external classList : T.t => Dom.domTokenList = "";
  [@bs.get] external className : T.t => string = "";
  [@bs.set] external setClassName : (T.t, string) => unit = "className";
  [@bs.get] external clientHeight : T.t => int = ""; /* experimental */
  [@bs.get] external clientLeft : T.t => int = ""; /* experimental */
  [@bs.get] external clientTop : T.t => int = ""; /* experimental */
  [@bs.get] external clientWidth : T.t => int = ""; /* experimental */
  [@bs.get] external id : T.t => string = "";
  [@bs.set] external setId : (T.t, string) => unit = "id";
  [@bs.get] external innerHTML : T.t => string = "";
  [@bs.set] external setInnerHTML : (T.t, string) => unit = "innerHTML";
  [@bs.get] external localName : T.t => string = "";
  [@bs.get] [@bs.return nullable] external namespaceURI : T.t => option(string) = "";
  [@bs.get] external outerHTML : T.t => string = ""; /* experimental, but widely supported */
  [@bs.set] external setOuterHTML : (T.t, string) => unit = "outerHTML"; /* experimental, but widely supported */
  [@bs.get] [@bs.return nullable] external prefix : T.t => option(string) = "";
  [@bs.get] external scrollHeight : T.t => int = ""; /* experimental, but widely supported */
  [@bs.get] external scrollLeft : T.t => float = ""; /* experimental */
  [@bs.set] external setScrollLeft : (T.t, float) => unit = "scrollLeft"; /* experimental */
  [@bs.get] external scrollTop : T.t => float = ""; /* experimental, but widely supported */
  [@bs.set] external setScrollTop : (T.t, float) => unit = "scrollTop"; /* experimental, but widely supported */
  [@bs.get] external scrollWidth : T.t => int = ""; /* experimental */
  [@bs.get] external shadowRoot : T.t => Dom.element = ""; /* experimental */
  [@bs.get] external slot : T.t => string = ""; /* experimental */
  [@bs.set] external setSlot : (T.t, string) => unit = "slot"; /* experimental */
  [@bs.get] external tagName : T.t => string = "";

  [@bs.send] external attachShadow : T.t => {. "mode": string} => Dom.shadowRoot = ""; /* experimental */
  [@bs.send] external attachShadowOpen : T.t => ([@bs.as {json|{ "mode": "open" }|json}] _) => Dom.shadowRoot = "attachShadow"; /* experimental */
  [@bs.send] external attachShadowClosed : T.t => ([@bs.as {json|{ "mode": "closed" }|json}] _) => Dom.shadowRoot = "attachShadow"; /* experimental */
  [@bs.send] external animate : T.t => (Js.t({..}), Js.t({..})) => Dom.animation = ""; /* experimental */
  [@bs.send] [@bs.return nullable] external closest : T.t => string => option(Dom.element) = ""; /* experimental */
  [@bs.send] external createShadowRoot : T.t => Dom.shadowRoot = ""; /* experimental AND deprecated (?!) */
  [@bs.send] [@bs.return nullable] external getAttribute : T.t => string => option(string) = "";
  [@bs.send] [@bs.return nullable] external getAttributeNS : T.t => (string, string) => option(string) = "";
  [@bs.send] external getBoundingClientRect : T.t => Dom.domRect = "";
  [@bs.send] external getClientRects : T.t => array(Dom.domRect) = "";
  [@bs.send] external getElementsByClassName : T.t => string => Dom.htmlCollection = "";
  [@bs.send] external getElementsByTagName : T.t => string => Dom.htmlCollection = "";
  [@bs.send] external getElementsByTagNameNS : T.t => (string, string) => Dom.htmlCollection = "";
  [@bs.send] external hasAttribute : T.t => string => bool = "";
  [@bs.send] external hasAttributeNS : T.t => (string, string) => bool = "";
  [@bs.send] external hasAttributes : T.t => bool = "";
  [@bs.send] external insertAdjacentElement : T.t => (string /* insertPosition enum */, Dom.element_like('a)) => unit = ""; /* experimental, but widely supported */
  let insertAdjacentElement: (Webapi__Dom__Types.insertPosition, Dom.element_like('a), T.t) => unit =
    (position, element, self) =>
      insertAdjacentElement(self, Webapi__Dom__Types.encodeInsertPosition(position), element);
  [@bs.send] external insertAdjacentHTML : T.t => (string /* insertPosition enum */, string) => unit = ""; /* experimental, but widely supported */
  let insertAdjacentHTML: (Webapi__Dom__Types.insertPosition, string, T.t) => unit =
    (position, text, self) =>
      insertAdjacentHTML(self, Webapi__Dom__Types.encodeInsertPosition(position), text);
  [@bs.send] external insertAdjacentText : T.t => (string /* insertPosition enum */, string) => unit = ""; /* experimental, but widely supported */
  let insertAdjacentText: (Webapi__Dom__Types.insertPosition, string, T.t) => unit =
    (position, text, self) =>
      insertAdjacentText(self, Webapi__Dom__Types.encodeInsertPosition(position), text);
  [@bs.send] external matches : T.t => string => bool = ""; /* experimental, but widely supported */
  [@bs.send] external releasePointerCapture : T.t => Dom.eventPointerId => unit = "";
  [@bs.send] external removeAttribute : T.t => string => unit = "";
  [@bs.send] external removeAttributeNS : T.t => (string, string) => unit = "";
  [@bs.send] external requestFullscreen : T.t => unit = ""; /* experimental */
  [@bs.send] external requestPointerLock : T.t => unit = ""; /* experimental */
  [@bs.send] external scrollIntoView : T.t => unit = ""; /* experimental, but widely supported */
  [@bs.send] external scrollIntoViewNoAlignToTop : T.t => ([@bs.as {json|true|json}] _) => unit = "scrollIntoView"; /* experimental, but widely supported */
  [@bs.send] external scrollIntoViewWithOptions : T.t => {. "behavior": string, "block": string} => unit = "scrollIntoView"; /* experimental */
  [@bs.send] external scrollBy : T.t => (float, float) => unit = "";
  [@bs.send] external scrollByWithOptions : T.t => {. "top": float, "left": float, "behavior": string} => unit = "scrollBy";
  [@bs.send] external scrollTo : T.t => (float, float) => unit = "";
  [@bs.send] external scrollToWithOptions : T.t => {. "top": float, "left": float, "behavior": string} => unit = "scrollTo";
  [@bs.send] external setAttribute : T.t => (string, string) => unit = "";
  [@bs.send] external setAttributeNS : T.t => (string, string, string) => unit = "";
  [@bs.send] external setPointerCapture : T.t => Dom.eventPointerId => unit = "";

  /* GlobalEventHandlers interface */
  /* Not sure this should be exposed, since EventTarget seems like a better API */

  [@bs.set] external setOnClick : (T.t, Dom.mouseEvent => unit) => unit = "onclick";
};

/* TODO: This doesn't work. Why?
module Tree (T: { type t; }) => {
  include NodeRe.Impl { type t = Type };
  include EventTargetRe.Impl { type t = Type };
  include Impl { type t = Type };
};

include Tree { type t = Dom.element };
*/

type t = Dom.element;

include Webapi__Dom__Node.Impl({ type nonrec t = t; });
include Webapi__Dom__EventTarget.Impl({ type nonrec t = t; });
include Webapi__Dom__GlobalEventHandlers.Impl({ type nonrec t = t; });
include Webapi__Dom__ParentNode.Impl({ type nonrec t = t; });
include Webapi__Dom__NonDocumentTypeChildNode.Impl({ type nonrec t = t; });
include Webapi__Dom__ChildNode.Impl({ type nonrec t = t; });
include Webapi__Dom__Slotable.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
