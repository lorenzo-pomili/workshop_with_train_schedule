[@bs.val] external confirm: string => bool = "window.confirm";

let (=?=) = Belt.Option.getWithDefault;