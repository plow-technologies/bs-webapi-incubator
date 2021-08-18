module Impl = (T: {type t;}) => {
  external asEventTarget : T.t => Dom.eventTarget = "%identity";

  [@bs.send] external addEventListener : T.t => (string, Dom.event => unit) => unit = "";
  [@bs.send] external addEventListenerWithOptions : T.t => (string, Dom.event => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addEventListenerUseCapture : T.t => (string, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeEventListener : T.t => (string, Dom.event => unit) => unit = "";
  [@bs.send] external removeEventListenerWithOptions : T.t => (string, Dom.event => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeEventListenerUseCapture : T.t => (string, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";
  [@bs.send] external dispatchEvent : T.t => Dom.event_like('a) => bool = "";

  /**
   *  non-standard event-specific functions
   */

   /* UI */

  [@bs.send] external addLoadEventListener : T.t => ([@bs.as "load"] _, Dom.event => unit) => unit = "addEventListener";
  [@bs.send] external addLoadEventListenerWithOptions : T.t => ([@bs.as "load"] _, Dom.event => unit,{. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addLoadEventListenerUseCapture : T.t => ([@bs.as "load"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeLoadEventListener : T.t => ([@bs.as "load"] _, Dom.event => unit) => unit= "removeEventListener";
  [@bs.send] external removeLoadEventListenerWithOptions : T.t => ([@bs.as "load"] _, Dom.event => unit, {. "capture": bool, "passive": bool})=> unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeLoadEventListenerUseCapture : T.t => ([@bs.as "load"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addUnloadEventListener : T.t => ([@bs.as "unload"] _, Dom.event => unit) => unit = "addEventListener";
  [@bs.send] external addUnloadEventListenerWithOptions : T.t => ([@bs.as "unload"] _, Dom.event=> unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addUnloadEventListenerUseCapture : T.t => ([@bs.as "unload"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeUnloadEventListener : T.t => ([@bs.as "unload"] _, Dom.event => unit) => unit = "removeEventListener";
  [@bs.send] external removeUnloadEventListenerWithOptions : T.t => ([@bs.as "unload"] _, Dom.event => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeUnloadEventListenerUseCapture : T.t => ([@bs.as "unload"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addAbortEventListener : T.t => ([@bs.as "abort"] _, Dom.event => unit) => unit = "addEventListener";
  [@bs.send] external addAbortEventListenerWithOptions : T.t => ([@bs.as "abort"] _, Dom.event => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addAbortEventListenerUseCapture : T.t => ([@bs.as "abort"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeAbortEventListener : T.t => ([@bs.as "abort"] _, Dom.event => unit) => unit = "removeEventListener";
  [@bs.send] external removeAbortEventListenerWithOptions : T.t => ([@bs.as "abort"] _, Dom.event => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeAbortEventListenerUseCapture : T.t => ([@bs.as "abort"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addErrorEventListener : T.t => ([@bs.as "error"] _, Dom.event => unit) => unit = "addEventListener";
  [@bs.send] external addErrorEventListenerWithOptions : T.t => ([@bs.as "error"] _, Dom.event => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addErrorEventListenerUseCapture : T.t => ([@bs.as "error"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeErrorEventListener : T.t => ([@bs.as "error"] _, Dom.event => unit) => unit = "removeEventListener";
  [@bs.send] external removeErrorEventListenerWithOptions : T.t => ([@bs.as "error"] _, Dom.event => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeErrorEventListenerUseCapture : T.t => ([@bs.as "error"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addSelectEventListener : T.t => ([@bs.as "select"] _, Dom.event => unit) => unit = "addEventListener";
  [@bs.send] external addSelectEventListenerWithOptions : T.t => ([@bs.as "select"] _, Dom.event => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addSelectEventListenerUseCapture : T.t => ([@bs.as "select"] _, Dom.event => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeSelectEventListener : T.t => ([@bs.as "select"] _, Dom.event => unit) => unit = "removeEventListener";
  [@bs.send] external removeSelectEventListenerWithOptions : T.t => ([@bs.as "select"] _, Dom.event => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeSelectEventListenerUseCapture : T.t => ([@bs.as "select"] _, Dom.event =>unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Focus */

  [@bs.send] external addBlurEventListener : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit) => unit = "addEventListener";
  [@bs.send] external addBlurEventListenerWithOptions : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addBlurEventListenerUseCapture : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeBlurEventListener : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeBlurEventListenerWithOptions : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeBlurEventListenerUseCapture : T.t => ([@bs.as "blur"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addFocusEventListener : T.t => ([@bs.as "focus"] _, Dom.focusEvent => unit) => unit = "addEventListener";
  [@bs.send] external addFocusEventListenerWithOptions : T.t => ([@bs.as "focus"] _, Dom.focusEvent => unit, {. "capture": bool, "once": bool,"passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addFocusEventListenerUseCapture : T.t => ([@bs.as "focus"] _, Dom.focusEvent =>unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeFocusEventListener : T.t => ([@bs.as "focus"] _, Dom.focusEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeFocusEventListenerWithOptions : T.t => ([@bs.as "focus"] _, Dom.focusEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeFocusEventListenerUseCapture : T.t => ([@bs.as "focus"] _, Dom.focusEvent=> unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addFocusInEventListener : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit) => unit = "addEventListener";
  [@bs.send] external addFocusInEventListenerWithOptions : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addFocusInEventListenerUseCapture : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeFocusInEventListener : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeFocusInEventListenerWithOptions : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeFocusInEventListenerUseCapture : T.t => ([@bs.as "focusin"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addFocusOutEventListener : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit) => unit = "addEventListener";
  [@bs.send] external addFocusOutEventListenerWithOptions : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addFocusOutEventListenerUseCapture : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeFocusOutEventListener : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeFocusOutEventListenerWithOptions : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeFocusOutEventListenerUseCapture : T.t => ([@bs.as "focusout"] _, Dom.focusEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Mouse */

  [@bs.send] external addClickEventListener : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addClickEventListenerWithOptions : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addClickEventListenerUseCapture : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeClickEventListener : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeClickEventListenerWithOptions : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeClickEventListenerUseCapture : T.t => ([@bs.as "click"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDblClickEventListener : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDblClickEventListenerWithOptions : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDblClickEventListenerUseCapture : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDblClickEventListener : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDblClickEventListenerWithOptions : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDblClickEventListenerUseCapture : T.t => ([@bs.as "dblclick"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseDownEventListener : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseDownEventListenerWithOptions : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseDownEventListenerUseCapture : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseDownEventListener : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseDownEventListenerWithOptions : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseDownEventListenerUseCapture : T.t => ([@bs.as "mousedown"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseEnterEventListener : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseEnterEventListenerWithOptions : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseEnterEventListenerUseCapture : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseEnterEventListener : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseEnterEventListenerWithOptions : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseEnterEventListenerUseCapture : T.t => ([@bs.as "mouseenter"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseMoveEventListener : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseMoveEventListenerWithOptions : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseMoveEventListenerUseCapture : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseMoveEventListener : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseMoveEventListenerWithOptions : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseMoveEventListenerUseCapture : T.t => ([@bs.as "mousemove"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseOutEventListener : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseOutEventListenerWithOptions : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseOutEventListenerUseCapture : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseOutEventListener : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseOutEventListenerWithOptions : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseOutEventListenerUseCapture : T.t => ([@bs.as "mouseout"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseOverEventListener : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseOverEventListenerWithOptions : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseOverEventListenerUseCapture : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseOverEventListener : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseOverEventListenerWithOptions : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseOverEventListenerUseCapture : T.t => ([@bs.as "mouseover"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addMouseUpEventListener : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit) => unit = "addEventListener";
  [@bs.send] external addMouseUpEventListenerWithOptions : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addMouseUpEventListenerUseCapture : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeMouseUpEventListener : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeMouseUpEventListenerWithOptions : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeMouseUpEventListenerUseCapture : T.t => ([@bs.as "mouseup"] _, Dom.mouseEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Wheel */

  [@bs.send] external addWheelEventListener : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit) => unit = "addEventListener";
  [@bs.send] external addWheelEventListenerWithOptions : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addWheelEventListenerUseCapture : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeWheelEventListener : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeWheelEventListenerWithOptions : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeWheelEventListenerUseCapture : T.t => ([@bs.as "wheel"] _, Dom.wheelEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Input */

  [@bs.send] external addBeforeInputEventListener : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit) => unit = "addEventListener";
  [@bs.send] external addBeforeInputEventListenerWithOptions : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addBeforeInputEventListenerUseCapture : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeBeforeInputEventListener : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeBeforeInputEventListenerWithOptions : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeBeforeInputEventListenerUseCapture : T.t => ([@bs.as "beforeinput"] _, Dom.inputEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addInputEventListener : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit) => unit = "addEventListener";
  [@bs.send] external addInputEventListenerWithOptions : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addInputEventListenerUseCapture : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeInputEventListener : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeInputEventListenerWithOptions : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeInputEventListenerUseCapture : T.t => ([@bs.as "input"] _, Dom.inputEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Keyboard */

  [@bs.send] external addKeyDownEventListener : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit) => unit = "addEventListener";
  [@bs.send] external addKeyDownEventListenerWithOptions : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addKeyDownEventListenerUseCapture : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeKeyDownEventListener : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeKeyDownEventListenerWithOptions : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeKeyDownEventListenerUseCapture : T.t => ([@bs.as "keydown"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addKeyUpEventListener : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit) => unit = "addEventListener";
  [@bs.send] external addKeyUpEventListenerWithOptions : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addKeyUpEventListenerUseCapture : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeKeyUpEventListener : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeKeyUpEventListenerWithOptions : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeKeyUpEventListenerUseCapture : T.t => ([@bs.as "keyup"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addKeyPressEventListener : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit) => unit = "addEventListener";
  [@bs.send] external addKeyPressEventListenerWithOptions : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addKeyPressEventListenerUseCapture : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeKeyPressEventListener : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeKeyPressEventListenerWithOptions : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeKeyPressEventListenerUseCapture : T.t => ([@bs.as "keypress"] _, Dom.keyboardEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Composition */

  [@bs.send] external addCompositionStartEventListener : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit) => unit = "addEventListener";
  [@bs.send] external addCompositionStartEventListenerWithOptions : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addCompositionStartEventListenerUseCapture : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeCompositionStartEventListener : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeCompositionStartEventListenerWithOptions : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeCompositionStartEventListenerUseCapture : T.t => ([@bs.as "compositionstart"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addCompositionUpdateEventListener : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit) => unit = "addEventListener";
  [@bs.send] external addCompositionUpdateEventListenerWithOptions : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addCompositionUpdateEventListenerUseCapture : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeCompositionUpdateEventListener : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeCompositionUpdateEventListenerWithOptions : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeCompositionUpdateEventListenerUseCapture : T.t => ([@bs.as "compositionupdate"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addCompositionEndEventListener : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit) => unit = "addEventListener";
  [@bs.send] external addCompositionEndEventListenerWithOptions : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addCompositionEndEventListenerUseCapture : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeCompositionEndEventListener : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeCompositionEndEventListenerWithOptions : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeCompositionEndEventListenerUseCapture : T.t => ([@bs.as "compositionend"] _, Dom.compositionEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Drag */

  [@bs.send] external addDragEventListener : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragEventListenerWithOptions : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragEventListenerUseCapture : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragEventListener : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragEventListenerWithOptions : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragEventListenerUseCapture : T.t => ([@bs.as "drag"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragEndEventListener : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragEndEventListenerWithOptions : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragEndEventListenerUseCapture : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragEndEventListener : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragEndEventListenerWithOptions : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragEndEventListenerUseCapture : T.t => ([@bs.as "dragend"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragEnterEventListener : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragEnterEventListenerWithOptions : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragEnterEventListenerUseCapture : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragEnterEventListener : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragEnterEventListenerWithOptions : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragEnterEventListenerUseCapture : T.t => ([@bs.as "dragenter"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragExitEventListener : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragExitEventListenerWithOptions : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragExitEventListenerUseCapture : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragExitEventListener : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragExitEventListenerWithOptions : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragExitEventListenerUseCapture : T.t => ([@bs.as "dragexit"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragLeaveEventListener : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragLeaveEventListenerWithOptions : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragLeaveEventListenerUseCapture : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragLeaveEventListener : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragLeaveEventListenerWithOptions : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragLeaveEventListenerUseCapture : T.t => ([@bs.as "dragleave"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragOverEventListener : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragOverEventListenerWithOptions : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragOverEventListenerUseCapture : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragOverEventListener : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragOverEventListenerWithOptions : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragOverEventListenerUseCapture : T.t => ([@bs.as "dragover"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDragStartEventListener : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDragStartEventListenerWithOptions : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDragStartEventListenerUseCapture : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDragStartEventListener : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDragStartEventListenerWithOptions : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDragStartEventListenerUseCapture : T.t => ([@bs.as "dragstart"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addDropEventListener : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit) => unit = "addEventListener";
  [@bs.send] external addDropEventListenerWithOptions : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addDropEventListenerUseCapture : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeDropEventListener : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeDropEventListenerWithOptions : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeDropEventListenerUseCapture : T.t => ([@bs.as "drop"] _, Dom.dragEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Touch */

  [@bs.send] external addTouchCancelEventListener : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit) => unit = "addEventListener";
  [@bs.send] external addTouchCancelEventListenerWithOptions : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addTouchCancelEventListenerUseCapture : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeTouchCancelEventListener : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeTouchCancelEventListenerWithOptions : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeTouchCancelEventListenerUseCapture : T.t => ([@bs.as "touchcancel"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addTouchEndEventListener : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit) => unit = "addEventListener";
  [@bs.send] external addTouchEndEventListenerWithOptions : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addTouchEndEventListenerUseCapture : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeTouchEndEventListener : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeTouchEndEventListenerWithOptions : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeTouchEndEventListenerUseCapture : T.t => ([@bs.as "touchend"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addTouchMoveEventListener : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit) => unit = "addEventListener";
  [@bs.send] external addTouchMoveEventListenerWithOptions : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addTouchMoveEventListenerUseCapture : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeTouchMoveEventListener : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeTouchMoveEventListenerWithOptions : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeTouchMoveEventListenerUseCapture : T.t => ([@bs.as "touchmove"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addTouchStartEventListener : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit) => unit = "addEventListener";
  [@bs.send] external addTouchStartEventListenerWithOptions : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addTouchStartEventListenerUseCapture : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeTouchStartEventListener : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeTouchStartEventListenerWithOptions : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeTouchStartEventListenerUseCapture : T.t => ([@bs.as "touchstart"] _, Dom.touchEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  /* Animation */

  [@bs.send] external addAnimationCancelEventListener : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit) => unit = "addEventListener";
  [@bs.send] external addAnimationCancelEventListenerWithOptions : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addAnimationCancelEventListenerUseCapture : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeAnimationCancelEventListener : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeAnimationCancelEventListenerWithOptions : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeAnimationCancelEventListenerUseCapture : T.t => ([@bs.as "animationcancel"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addAnimationEndEventListener : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit) => unit = "addEventListener";
  [@bs.send] external addAnimationEndEventListenerWithOptions : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addAnimationEndEventListenerUseCapture : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeAnimationEndEventListener : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeAnimationEndEventListenerWithOptions : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeAnimationEndEventListenerUseCapture : T.t => ([@bs.as "animationend"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addAnimationIterationEventListener : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit) => unit = "addEventListener";
  [@bs.send] external addAnimationIterationEventListenerWithOptions : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addAnimationIterationEventListenerUseCapture : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeAnimationIterationEventListener : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeAnimationIterationEventListenerWithOptions : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeAnimationIterationEventListenerUseCapture : T.t => ([@bs.as "animationiteration"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";

  [@bs.send] external addAnimationStartEventListener : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit) => unit = "addEventListener";
  [@bs.send] external addAnimationStartEventListenerWithOptions : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit, {. "capture": bool, "once": bool, "passive": bool}) => unit = "addEventListener"; /* not widely supported */
  [@bs.send] external addAnimationStartEventListenerUseCapture : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "addEventListener";
  [@bs.send] external removeAnimationStartEventListener : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit) => unit = "removeEventListener";
  [@bs.send] external removeAnimationStartEventListenerWithOptions : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit, {. "capture": bool, "passive": bool}) => unit = "removeEventListener"; /* not widely supported */
  [@bs.send] external removeAnimationStartEventListenerUseCapture : T.t => ([@bs.as "animationstart"] _, Dom.animationEvent => unit, [@bs.as {json|true|json}] _) => unit = "removeEventListener";
};

include Impl({ type nonrec t = Dom.eventTarget; });

external unsafeAsDocument : Dom.eventTarget => Dom.document = "%identity";
external unsafeAsElement : Dom.eventTarget => Dom.element = "%identity";
external unsafeAsWindow : Dom.eventTarget => Dom.window = "%identity";
