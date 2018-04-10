[@bs.module "react-native-elements"]
external className : ReasonReact.reactClass = "Badge";

type value =
  | String(string)
  | Num(int);

let valueChecker = v =>
  switch (v) {
  | String(input) => input
  | Num(v) => v |> string_of_int
  };

let unwrapValue = v =>
  switch (v) {
  | None => ""
  | Some(v) => valueChecker(v)
  };

let make = (~value: option(value)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=Js.Nullable.({"value": unwrapValue(value)}),
    children,
  );