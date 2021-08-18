type t = Dom.domTokenList;

[@bs.get] external length : t => int = "";

[@bs.send] [@bs.return nullable] external item : t => int => option(string) = "";
[@bs.send] external add : t => string => unit = "";
[@bs.send] [@bs.splice] external addMany : t => array(string) => unit = "add";
[@bs.send] external contains : t => string => bool = "contains";
/* entries: iterator API, should have language support */
[@bs.send] external forEach : t => ((string, int) => unit) => unit = "";
/* keys: iterator API, should have language support */
[@bs.send] external remove : t => string => unit = "";
[@bs.send] [@bs.splice] external removeMany : t => array(string) => unit = "remove";
[@bs.send] external replace : t => (string, string) => unit = ""; /* experimental */
[@bs.send] external supports : t => string => bool = ""; /* experimental, Content Management Level 1 */
[@bs.send] external toggle : t => string => bool = "";
[@bs.send] external toggleForced : t => (string, [@bs.as {json|true|json}] _) => bool = "toggle";
[@bs.send] external toString : t => string = "";
/* values: iterator API, should have language support */

[@bs.get] external value : t => string = ""; /* experimental, from being merged with domSettableTokenList */
[@bs.set] external setValue : (t, string) => unit = "value"; /* experimental, from being merged with domSettableTokenList */
