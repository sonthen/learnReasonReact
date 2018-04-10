[@bs.module "react-native-elements"]
external className : ReasonReact.reactClass = "";

let make = (~placeholder: option(string)=?, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=className,
    ~props=Js.Nullable.({"placeholder": fromOption(placeholder)}),
    children,
  );
/* ~containerStyle: option(BsReactNative.Style.t)=?,
   ~inputContainerStyle: option(BsReactNative.Style.t)=?,
   ~errorMessage: option(string)=?,
   ~errorStyle: option(BsReactNative.Style.t)=?,
   ~inputStyle: option(BsReactNative.Style.t)=?,
   ~label: option(string)=?,
   ~labelString: option(BsReactNative.Style.t)=?,
   ~leftIcon: option(ReasonReact.reactElement)=?,
   ~leftIconContainerStyle: option(BsReactNative.Style.t)=?,
   ~rightIcon: option(ReasonReact.reactElement)=?,
   ~rightIconContainerStyle: option(BsReactNative.Style.t)=?, */
/* "containerStyle": fromOption(containerStyle),
   "inputContainerStyle": fromOption(inputContainerStyle),
   "errorMessage": fromOption(errorMessage),
   "errorStyle": fromOption(errorStyle),
   "inputStyle": fromOption(inputStyle),
   "label": fromOption(label),
   "labelString": fromOption(labelString),
   "leftIcon": fromOption(leftIcon),
   "leftIconContainerStyle": fromOption(leftIconContainerStyle),
   "rightIcon": fromOption(rightIcon),
   "rightIconContainerStyle": fromOption(rightIconContainerStyle), */