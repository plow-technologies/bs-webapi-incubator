type t; /* Main type, representing the 2d canvas rendering context object */
type gradient;
type pattern;
type measureText;

/* Sub-modules (and their interfaces) for string enum arguments: */
module type CompositeType = {
  type t = pri string;

  let sourceOver: t;
  let sourceIn: t;
  let sourceOut: t;
  let sourceAtop: t;
  let destinationOver: t;
  let destinationIn: t;
  let destinationOut: t;
  let destinationAtop: t;
  let lighter: t;
  let copy: t;
  let xor: t;
};

module Composite: CompositeType = {
  type t = string;

  let sourceOver: t = "source-over";
  let sourceIn: t = "source-in";
  let sourceOut: t = "source-out";
  let sourceAtop: t = "source-atop";
  let destinationOver: t = "destination-over";
  let destinationIn: t = "destination-in";
  let destinationOut: t = "destination-out";
  let destinationAtop: t = "destination-atop";
  let lighter: t = "lighter";
  let copy: t = "copy";
  let xor: t = "xor";
};

module type LineCapType = {
  type t = pri string;

  let butt: t;
  let round: t;
  let square: t;
};

module LineCap: LineCapType = {
  type t = string;

  let butt: t = "butt";
  let round: t = "round";
  let square: t = "square";
};

module type LineJoinType = {
  type t = pri string;

  let round: t;
  let bevel: t;
  let miter: t;
};

module LineJoin: LineJoinType = {
  type t = string;

  let round: t = "round";
  let bevel: t = "bevel";
  let miter: t = "miter";
};

type image('a) =
  | Number: image(float)
  | ImageData: image(Webapi__Dom__Image.t);

type style(_) =
  | String: style(string)
  | Gradient: style(gradient)
  | Pattern: style(pattern);

/* 2d Canvas API, following https://simon.html5.org/dump/html5-canvas-cheat-sheet.html */
[@bs.send] external save : t => unit = "";
[@bs.send] external restore : t => unit = "";

/* Transformation */
[@bs.send] external scale : t => (~x: float, ~y: float) => unit = "";
[@bs.send] external rotate : t => float => unit = "";
[@bs.send] external translate : t => (~x: float, ~y: float) => unit = "";
[@bs.send] external transform : t => (~m11: float, ~m12: float, ~m21: float, ~m22: float, ~dx: float, ~dy: float) => unit = "";
[@bs.send] external setTransform : t => (~m11: float, ~m12: float, ~m21: float, ~m22: float, ~dx: float, ~dy: float) => unit = "";

/* Compositing */
[@bs.set] external globalAlpha : (t, float) => unit = "";
[@bs.set] external globalCompositeOperation : (t, Composite.t) => unit = "";

/* Line Styles */
[@bs.set] external lineWidth : (t, float) => unit = "";
[@bs.set] external lineCap : (t, LineCap.t) => unit = "";
[@bs.set] external lineJoin : (t, LineJoin.t) => unit = "";
[@bs.set] external miterLimit : (t, float) => unit = "";

/* Colors, Styles, and Shadows */
[@bs.set] external setFillStyle : (t, 'a) => unit = "fillStyle";
[@bs.set] external setStrokeStyle : (t, 'a) => unit = "strokeStyle";

/* in re unused warnings
   awaiting release of https://github.com/bloomberg/bucklescript/issues/1656
   to just use [@@bs.set] directly with an ignored (style a) */
let setStrokeStyle = (type a, ctx: t, _: style(a), v: a) =>
  setStrokeStyle(ctx, v);

let setFillStyle = (type a, ctx: t, _: style(a), v: a) =>
  setFillStyle(ctx, v);

let reifyStyle = (type a, x: 'a) : (style(a), a) => {
  let isCanvasGradient: 'a => bool = [%raw {|
    function(x) { return x instanceof CanvasGradient; }
  |}];

  let isCanvasPattern: 'a => bool = [%raw {|
    function(x) { return x instanceof CanvasPattern; }
  |}];

  (
    if (Js.typeof(x) == "string") Obj.magic(String)
    else if (isCanvasGradient(x)) Obj.magic(Gradient)
    else if (isCanvasPattern(x)) Obj.magic(Pattern)
    else invalid_arg(
      "Unknown canvas style kind. Known values are: String, CanvasGradient, CanvasPattern"),
    Obj.magic(x)
  );
};

[@bs.get] external fillStyle : t => 'a = "";
[@bs.get] external strokeStyle : t => 'a = "";

let fillStyle = (ctx: t) =>
  ctx |> fillStyle |> reifyStyle;

let strokeStyle = (ctx: t) =>
  ctx |> strokeStyle |> reifyStyle;

[@bs.set] external shadowOffsetX : (t, float) => unit = "";
[@bs.set] external shadowOffsetY : (t, float) => unit = "";
[@bs.set] external shadowBlur : (t, float) => unit = "";
[@bs.set] external shadowColor : (t, string) => unit = "";

/* Gradients */
[@bs.send] external createLinearGradient : t => (~x0: float, ~y0: float, ~x1: float, ~y1: float) => gradient = "";
[@bs.send] external createRadialGradient : t => (~x0: float, ~y0: float, ~x1: float, ~y1: float, ~r0: float, ~r1: float) => gradient = "";
[@bs.send] external addColorStop : gradient => (float, string) => unit = "";
[@bs.val] external createPattern : (
    t,
    Dom.element,
    [@bs.string] [
      | `repeat
      [@bs.as "repeat-x"] | `repeatX
      [@bs.as "repeat-y"] | `repeatY
      [@bs.as "no-repeat"] | `noRepeat
    ]
  )
  => pattern = "";

/* Paths */
[@bs.send] external beginPath : t => unit = "";
[@bs.send] external closePath : t => unit = "";
[@bs.send] external fill : t => unit = "";
[@bs.send] external stroke : t => unit = "";
[@bs.send] external clip : t => unit = "";
[@bs.send] external moveTo : t => (~x: float, ~y: float) => unit = "";
[@bs.send] external lineTo : t => (~x: float, ~y: float) => unit = "";
[@bs.send] external quadraticCurveTo : t => (~cp1x: float, ~cp1y: float, ~x: float, ~y: float) => unit = "";
[@bs.send] external bezierCurveTo : t => (~cp1x: float, ~cp1y: float, ~cp2x: float, ~cp2y: float, ~x: float, ~y: float) => unit = "";
[@bs.send] external arcTo : t => (~x1: float, ~y1: float, ~x2: float, ~y2: float, ~r: float) => unit = "";
[@bs.send] external arc : t => (~x: float, ~y: float, ~r: float, ~startAngle: float, ~endAngle: float, ~anticw: bool) => unit = "";
[@bs.send] external rect : t => (~x: float, ~y: float, ~w: float, ~h: float) => unit = "";
[@bs.send] external isPointInPath : t => (~x: float, ~y: float) => bool = "";

/* Text */
[@bs.set] external font : (t, string) => unit = "";
[@bs.set] external textAlign : (t, string) => unit = "";
[@bs.set] external textBaseline : (t, string) => unit = "";
[@bs.send] external fillText : t => (string, ~x: float, ~y: float, ~maxWidth: float=?) => unit = "";
[@bs.send] external strokeText : t => (string, ~x: float, ~y: float, ~maxWidth: float=?) => unit = "";
[@bs.send] external measureText : t => string => measureText = "";
[@bs.get] external width : measureText => float = "";

/* Rectangles */
[@bs.send] external fillRect : t => (~x: float, ~y: float, ~w: float, ~h: float) => unit = "";
[@bs.send] external strokeRect : t => (~x: float, ~y: float, ~w: float, ~h: float) => unit = "";
[@bs.send] external clearRect : t => (~x: float, ~y: float, ~w: float, ~h: float) => unit = "";

[@bs.send] external createImageDataCoords : (t, ~width: float, ~height: float) => Webapi__Dom__Image.t = "createImageData";
[@bs.send] external createImageDataFromImage : (t, Webapi__Dom__Image.t) => Webapi__Dom__Image.t = "createImageData";

[@bs.send] external getImageData : (t, ~sx: float, ~sy: float, ~sw: float, ~sh: float) => Webapi__Dom__Image.t = "";

[@bs.send] external putImageData : (
    t,
    ~imageData: Webapi__Dom__Image.t,
    ~dx: float,
    ~dy: float
  )
  => unit = "";

[@bs.send] external putImageDataWithDirtyRect : (
    t,
    ~imageData: Webapi__Dom__Image.t,
    ~dx: float,
    ~dy: float,
    ~dirtyX: float,
    ~dirtyY: float,
    ~dirtyWidth: float,
    ~dirtyHeight: float
  )
  => unit = "putImageData";
