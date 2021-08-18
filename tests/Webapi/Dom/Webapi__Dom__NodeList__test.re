open Webapi.Dom;
open NodeList;

let items = document->Document.querySelectorAll(".item");

forEach(items, (item, _) => Js.log(item));
