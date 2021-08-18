type t = Dom.mutationObserver;

[@bs.new] external make : ((array(Dom.mutationRecord), t) => unit) => t = "MutationObserver";

[@bs.send] external observe : t => (Dom.node_like('a), Js.t({..})) => unit = "";
[@bs.send] external disconnect : t => unit = "";
[@bs.send] external takeRecords : t => array(Dom.mutationRecord) = "";
