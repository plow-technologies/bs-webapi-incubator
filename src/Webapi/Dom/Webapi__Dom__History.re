type t = Dom.history;
type state; /* TODO: should be "anything that can be serializable" apparently */

[@bs.get] external length : t => int = "";
[@bs.get] external scrollRestoration : t => bool = ""; /* experimental */
[@bs.set] external setScrollRestoration : (t, bool) => unit = "scrollRestoration"; /* experimental */
[@bs.get] external state : t => state = "";

[@bs.send] external back : t => unit = "";
[@bs.send] external forward : t => unit = "";
[@bs.send] external go : t => int => unit = "";
[@bs.send] external pushState : t => (state, string, string) => unit = "";
[@bs.send] external replaceState : t => (state, string, string) => unit = "";
