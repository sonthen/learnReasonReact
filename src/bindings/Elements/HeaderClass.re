[@bs.module "react-native-elements"]
external className: ReasonReact.reactClass = "Header";

let make =
    (
      ~backgroundColor: option(string)=?,
      ~centerComponent: option(ReasonReact.reactElement)=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=
      Js.Nullable.(
        {
          "backgroundColor": fromOption(backgroundColor),
          "centerComponent": fromOption(centerComponent),

         
        }
      ),
    children,
  );