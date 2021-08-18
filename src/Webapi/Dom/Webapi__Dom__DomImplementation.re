type t = Dom.domImplementation;

[@bs.send] external createDocumentType : t => (~qualifiedName: string, ~publicId: string, ~systemId: string) => Dom.documentType = "";
[@bs.send] external createDocument : t => (Js.null(string), string, Js.null(Dom.documentType)) => Dom.xmlDocument = "";
let createDocument = (~namespace: option(string)=?, ~qualifiedName: string, ~docType: option(Dom.documentType)=?) =>
  createDocument(Js.Null.fromOption(namespace), qualifiedName, Js.Null.fromOption(docType));
[@bs.send] external createHTMLDocument : t => Dom.htmlDocument = "";
[@bs.send] external createHTMLDocumentWithTitle : t => string => Dom.htmlDocument = "createHTMLDocument";
[@bs.send] external hasFeature : t => bool = ""; /* useless; always returns true (this is exact wording from the actual spec) */
