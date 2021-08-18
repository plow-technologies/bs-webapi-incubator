module Impl = (T: {type t;}) => {
  [@bs.get] external data : T.t => string = "";
  [@bs.get] external length : T.t => int = "";

  [@bs.send] external substringData : T.t => (~offset: int, ~count: int) => string = "";
  [@bs.send] external appendData : T.t => string => unit = "";
  [@bs.send] external insertData : T.t => (~offset: int, string) => unit = "";
  [@bs.send] external deleteData : T.t => (~offset: int, ~count: int) => unit = "";
  [@bs.send] external replaceData : T.t => (~offset: int, ~count: int, string) => unit = "";
};

type t = Dom.characterData;

include Webapi__Dom__Node.Impl({ type nonrec t = t; });
include Webapi__Dom__EventTarget.Impl({ type nonrec t = t; });
include Webapi__Dom__NonDocumentTypeChildNode.Impl({ type nonrec t = t; });
include Webapi__Dom__ChildNode.Impl({ type nonrec t = t; });
include Impl({ type nonrec t = t; });
