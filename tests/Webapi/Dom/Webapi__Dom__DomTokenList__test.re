open Webapi.Dom;
open DomTokenList;

let tlist =
  document
  ->Document.createElement("div")
  ->Element.classList;

let _ = length(tlist);
let _ = item(tlist, 3);

add(tlist, "my-class");
addMany(tlist, [|"my-class", "my-other-class"|]);
let _ = contains(tlist, "my-class");
forEach(tlist, (item, _) => print_endline(item));
remove(tlist, "my-class");
removeMany(tlist, [|"my-class", "my-other-class"|]);
replace(tlist, "my-class", "my-other-class");
let _ = supports(tlist, "my-class");
let _ = toggle(tlist, "my-class");
let _ = toggleForced(tlist, "my-class");
let _ = toString(tlist);
let _ = value(tlist);
let _ = setValue(tlist, "foo");
