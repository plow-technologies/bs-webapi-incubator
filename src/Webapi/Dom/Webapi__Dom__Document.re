module Impl = (T: {type t;}) => {
  external asDocument : T.t => Dom.document = "%identity";

  let asHtmlDocument: T.t => option(Dom.htmlDocument) = [%raw {|
    function(document) {
      var defaultView = document.defaultView;

      if (defaultView != null) {
        var HTMLDocument = defaultView.HTMLDocument;

        if (HTMLDocument != null && document instanceof HTMLDocument) {
          return document;
        }
      }
    }
  |}];

  /** Unsafe cast, use [ashtmlDocument] instead */
  external unsafeAsHtmlDocument : T.t => Dom.htmlDocument = "%identity";

  let ofNode = (node: Dom.node) : option(T.t) =>
    Webapi__Dom__Node.nodeType(node) == Webapi__Dom__Types.Document ?
      Some(Obj.magic(node)) :
      None;

  [@bs.get] external characterSet : T.t => string = "";
  [@bs.get] external compatMode : T.t => string /* compatMode enum */ = ""; /* experimental */
  let compatMode: T.t => Webapi__Dom__Types.compatMode =
    (self) => Webapi__Dom__Types.decodeCompatMode(compatMode(self));
  [@bs.get] external doctype : T.t => Dom.documentType = "";
  [@bs.get] external documentElement : T.t => Dom.element = "";
  [@bs.get] external documentURI : T.t => string = "";
  [@bs.get] external hidden : T.t => bool = "";
  [@bs.get] external implementation : T.t => Dom.domImplementation = "";
  [@bs.get] external lastStyleSheetSet : T.t => string = "";
  [@bs.get] [@bs.return nullable] external pointerLockElement : T.t => option(Dom.element) = ""; /* experimental */

  [@bs.get] external preferredStyleSheetSet : T.t => string = "";
  [@bs.get] [@bs.return nullable] external scrollingElement : T.t => option(Dom.element) = "";
  [@bs.get] external selectedStyleSheetSet : T.t => string = "";
  [@bs.set] external setSelectedStyleSheetSet : (T.t, string) => unit = "selectedStyleSheetSet";
  [@bs.get] external styleSheets : T.t => array(Dom.cssStyleSheet) = ""; /* return StyleSheetList, not array */
  [@bs.get] external styleSheetSets : T.t => array(string) = "";
  [@bs.get] external visibilityState : T.t => string /* visibilityState enum */ = "";
  let visibilityState: T.t => Webapi__Dom__Types.visibilityState =
    (self) => Webapi__Dom__Types.decodeVisibilityState(visibilityState(self));

  [@bs.send] external adoptNode : T.t => Dom.element_like('a) => Dom.element_like('a) = "";
  [@bs.send] external createAttribute : T.t => string => Dom.attr = "";
  [@bs.send] external createAttributeNS : T.t => (string, string) => Dom.attr = "";
  [@bs.send] external createComment : T.t => string => Dom.comment = "";
  [@bs.send] external createDocumentFragment : T.t => Dom.documentFragment = "";
  [@bs.send] external createElement : T.t => string => Dom.element = "";
  [@bs.send] external createElementWithOptions : T.t => (string, Js.t({..})) => Dom.element = "createElement"; /* not widely supported */
  [@bs.send] external createElementNS : T.t => (string, string) => Dom.element = "";
  [@bs.send] external createElementNSWithOptions : T.t => (string, string, Js.t({..})) => Dom.element = "createElementNS"; /* not widely supported */
  [@bs.send] external createEvent : T.t => string /* large enum */ => Dom.event = ""; /* discouraged (but not deprecated) in favor of Event constructors */
  [@bs.send] external createNodeIterator : T.t => Dom.node_like('a) => Dom.nodeIterator = "";
  [@bs.send] external createNodeIteratorWithWhatToShow : T.t => (Dom.node_like('a), Webapi__Dom__Types.WhatToShow.t) => Dom.nodeIterator = "createNodeIterator";
  [@bs.send] external createNodeIteratorWithWhatToShowFilter : T.t => (Dom.node_like('a), Webapi__Dom__Types.WhatToShow.t, Dom.nodeFilter) => Dom.nodeIterator = "createNodeIterator"; /* createProcessingInstruction */
  [@bs.send] external createRange : T.t => Dom.range = "";
  [@bs.send] external createTextNode : T.t => string => Dom.text = "";
  [@bs.send] external createTreeWalker : T.t => Dom.element_like('a) => Dom.treeWalker = "";
  [@bs.send] external createTreeWalkerWithWhatToShow : T.t => (Dom.element_like('a), Webapi__Dom__Types.WhatToShow.t) => Dom.treeWalker = "createTreeWalker";
  [@bs.send] external createTreeWalkerWithWhatToShowFilter : T.t => (Dom.element_like('a), Webapi__Dom__Types.WhatToShow.t, Dom.nodeFilter) => Dom.treeWalker = "createTreeWalker";
  [@bs.send] external elementFromPoint : T.t => (int, int) => Dom.element = ""; /* experimental, but widely supported */
  [@bs.send] external elementsFromPoint : T.t => (int, int) => array(Dom.element) = ""; /* experimental */
  [@bs.send] external enableStyleSheetsForSet : T.t => string => unit = "";
  [@bs.send] external exitPointerLock : T.t => unit = ""; /* experimental */
  [@bs.send] external getAnimations : T.t => array(Dom.animation) = ""; /* experimental */
  [@bs.send] external getElementsByClassName : T.t => string => Dom.htmlCollection = "";
  [@bs.send] external getElementsByTagName : T.t => string => Dom.htmlCollection = "";
  [@bs.send] external getElementsByTagNameNS : T.t => (string, string) => Dom.htmlCollection = "";
  [@bs.send] external importNode : T.t => Dom.element_like('a) => Dom.element_like('a) = "";
  [@bs.send] external importNodeDeep : T.t => (Dom.element_like('a), [@bs.as {json|true|json}] _) => Dom.element_like('a) = "importNode";
  [@bs.send] external registerElement : T.t => (string, unit) => Dom.element = ""; /* experimental and deprecated in favor of customElements.define() */
  [@bs.send] external registerElementWithOptions : T.t => (string, Js.t({..}), unit) => Dom.element = "registerElement"; /* experimental and deprecated in favor of customElements.define() */

  /** XPath stuff */
  /* createExpression */
  /* createNSResolver */
  /* evaluate */

  /* GlobalEventHandlers interface */
};

type t = Dom.document;

include Webapi__Dom__Node.Impl({ type nonrec t = t; });
include Webapi__Dom__EventTarget.Impl({ type nonrec t = t; });
include Webapi__Dom__NonElementParentNode.Impl({ type nonrec t = t; });
include Webapi__Dom__DocumentOrShadowRoot.Impl({ type nonrec t = t; });
include Webapi__Dom__ParentNode.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
