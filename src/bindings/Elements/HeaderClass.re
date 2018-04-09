[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "Header";

let make =
    (
      ~backgroundColor: option(string)=?,children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      Js.Nullable.(
        {
          "backgroundColor": fromOption(backgroundColor),
         
        }
      ),
    children,
  );