/* Mixin */
module Impl = (T: {type t;}) => {
  [@bs.send] external addSelectionChangeEventListener : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent => unit) => unit = "addEventListener";
  [@bs.send] external addSelectionChangeEventListenerWithOptions : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addSelectionChangeEventListenerUseCapture : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeSelectionChangeEventListener : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeSelectionChangeEventListenerWithOptions : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeSelectionChangeEventListenerUseCapture : T.t => ([@bs.as "selectionchange"] _, Dom.focusEvent =>unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";
};
