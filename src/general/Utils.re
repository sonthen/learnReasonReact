let optionMap = (fn, opt) =>
  switch (opt) {
  | Some(value) => Some(fn(value))
  | None => None
  };

let str = ReasonReact.stringToElement;