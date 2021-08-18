open Webapi.Dom;
open EventTarget;

let target = document->Document.createElement("strong")->Element.asEventTarget;
let event = Event.make("my-event");
let handleClick = (_) => print_endline("asd");

addEventListener(target, "click", handleClick);
addEventListenerWithOptions(target, "click",handleClick, {"passive": true, "once": true, "capture": false});
addEventListenerUseCapture(target, "click", handleClick);
removeEventListener(target, "click", handleClick);
removeEventListenerWithOptions(target, "click", handleClick, {"passive": true, "capture": false});
removeEventListenerUseCapture(target, "click", handleClick);
let _ = dispatchEvent(target, event);

/* https://github.com/reasonml-community/bs-webapi-incubator/issues/103 */
let customEvent = CustomEvent.makeWithOptions("custom-event", {"detail": {"test": "test"}});
dispatchEvent(target, customEvent)->ignore;
