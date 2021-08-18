open Webapi.Dom;
open Selection;

let node = document->Document.createElement("strong");
let sel =
  document
  ->Document.asHtmlDocument
  ->TestHelpers.unsafelyUnwrapOption
  ->HtmlDocument.getSelection;

let range = Range.make();

let _ = anchorNode(sel);
let _ = anchorOffset(sel);
let _ = focusNode(sel);
let _ = focusOffset(sel);
let _ = isCollapsed(sel);
let _ = rangeCount(sel);
let _ = getRangeAt(sel, 0);

collapse(sel, node, 0);
extend(sel, node, 0);
collapseToStart(sel);
collapseToEnd(sel);
selectAllChildren(sel, node);
addRange(sel, range);
removeRange(sel, range);
removeAllRanges(sel);
deleteFromDocument(sel);
setBaseAndExtent(sel, node, 0, node, 0);
let _ = toString(sel);
let _ = containsNode(sel, node);
let _ = containsNodePartly(sel, node);
