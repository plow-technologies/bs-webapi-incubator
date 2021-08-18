open Webapi.Dom;
open Document;

let el = document->createElement("strong");

let _ = characterSet(document);
let _ = compatMode(document);
let _ = doctype(document);
let _ = documentElement(document);
let _ = documentURI(document);
let _ = hidden(document);
let _ = implementation(document);
let _ = lastStyleSheetSet(document);
let _ = pointerLockElement(document);
let _ = preferredStyleSheetSet(document);
let _ = scrollingElement(document);
let _ = selectedStyleSheetSet(document);
let _ = setSelectedStyleSheetSet(document, "muh-stylesheet");
let _ = styleSheets(document);
let _ = styleSheetSets(document);
let _ = visibilityState(document);

let _ = adoptNode(document, el);
let _ = createAttribute(document, "data-foo");
let _ = createAttributeNS(document, "http://...", "foo");
let _ = createComment(document, "witty comment");
let _ = createDocumentFragment(document);
let _ = createElement(document, "div");
let _ = createElementWithOptions(document, "div", [%bs.raw "{}"]); /* I've no idea what this options object is supposed to be, even the spec doesn't seem to bother explaining it */
let _ = createElementNS(document, "http://...", "foo");
let _ = createElementNSWithOptions(document, "http://...", "div", [%bs.raw "{}"]); /* I've no idea what this options object is supposed to be, even the spec doesn't seem to bother explaining it */
let _ = createEvent(document, "MyCustomEvent");
let _ = createNodeIterator(document, el);
let _ = createNodeIteratorWithWhatToShow(document, el, WhatToShow._All);
let _ = createNodeIteratorWithWhatToShowFilter(document, el, WhatToShow.(many([_Element, _Attribute])), NodeFilter.make((_) => 0));
let _ = createRange(document);
let _ = createTextNode(document, "Very reasonable!");
let _ = createTreeWalker(document, el);
let _ = createTreeWalkerWithWhatToShow(document, el, WhatToShow._All);
let _ = createTreeWalkerWithWhatToShowFilter(document, el, WhatToShow.(many([_Element, _Attribute])), NodeFilter.make((_) => 0));
let _ = elementFromPoint(document, 0, 0);
let _ = elementsFromPoint(document, 0, 0);
let _ = enableStyleSheetsForSet(document, "my-stylesheet-set");
let _ = exitPointerLock(document);
let _ = getAnimations(document);
let _ = getElementsByClassName(document, "lstlisting");
let _ = getElementsByTagName(document, "code");
let _ = getElementsByTagNameNS(document, "http://...", "foo");
let _ = importNode(document, el);
let _ = importNodeDeep(document, el);
/* TODO: These get dead code eliminated
let _ = registerElement(document, "my-component");
let _ = registerElementWithOptions(document, "my-component", [%bs.raw "{}"]);
*/
let _ = getElementById(document, "root");
let _ = querySelector(document, ".lstlisting");
let _ = querySelectorAll(document, ".lstlisting");
