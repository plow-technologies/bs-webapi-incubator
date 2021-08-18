open Webapi.Dom;

let handleSelection = (_) => print_endline("change");

let elm = document->Document.createElement("strong");

Element.addSelectionChangeEventListenerWithOptions(elm, handleSelection, {"passive": true, "once": true, "capture": false});
Element.addSelectionChangeEventListenerUseCapture(elm, handleSelection);
Element.removeSelectionChangeEventListener(elm, handleSelection);
Element.removeSelectionChangeEventListenerWithOptions(elm, handleSelection, {"passive": true, "capture": false});
Element.removeSelectionChangeEventListenerUseCapture(elm, handleSelection);

let htmlElm = document->Document.createElement("strong")->HtmlElement.ofElement->TestHelpers.unsafelyUnwrapOption;

HtmlElement.addSelectionChangeEventListenerWithOptions(htmlElm, handleSelection, {"passive": true, "once": true, "capture": false});
HtmlElement.addSelectionChangeEventListenerUseCapture(htmlElm, handleSelection);
HtmlElement.removeSelectionChangeEventListener(htmlElm, handleSelection);
HtmlElement.removeSelectionChangeEventListenerWithOptions(htmlElm, handleSelection, {"passive": true, "capture": false});
HtmlElement.removeSelectionChangeEventListenerUseCapture(htmlElm, handleSelection);

let htmlDoc = document->Document.asHtmlDocument->TestHelpers.unsafelyUnwrapOption;

HtmlDocument.addSelectionChangeEventListenerWithOptions(htmlDoc, handleSelection, {"passive": true, "once": true, "capture": false});
HtmlDocument.addSelectionChangeEventListenerUseCapture(htmlDoc, handleSelection);
HtmlDocument.removeSelectionChangeEventListener(htmlDoc, handleSelection);
HtmlDocument.removeSelectionChangeEventListenerWithOptions(htmlDoc, handleSelection, {"passive": true, "capture": false});
HtmlDocument.removeSelectionChangeEventListenerUseCapture(htmlDoc, handleSelection);

Window.addSelectionChangeEventListenerWithOptions(window, handleSelection, {"passive": true, "once": true, "capture": false});
Window.addSelectionChangeEventListenerUseCapture(window, handleSelection);
Window.removeSelectionChangeEventListener(window, handleSelection);
Window.removeSelectionChangeEventListenerWithOptions(window, handleSelection, {"passive": true, "capture": false});
Window.removeSelectionChangeEventListenerUseCapture(window, handleSelection);
