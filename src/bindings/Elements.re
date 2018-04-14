module Button = {
  type p;
  [@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Button";
  let make =
      (
        ~buttonStyle: option(BsReactNative.Style.t)=?,
        ~clear: option(bool)=?,
        ~containerStyle: option(BsReactNative.Style.t)=?,
        ~disabled: option(bool)=?,
        ~disabledStyle: option(BsReactNative.Style.t)=?,
        ~disabledTitleStyle: option(BsReactNative.Style.t)=?,
        ~icon: option(ReasonReact.reactElement)=?,
        ~iconContainerStyle: option(BsReactNative.Style.t)=?,
        ~iconRight: option(bool)=?,
        ~loading: option(bool)=?,
        ~loadingProps: option(BsReactNative.Style.t)=?,
        ~loadingStyle: option(BsReactNative.Style.t)=?,
        ~onPress: option(p => unit)=?,
        ~title: option(string)=?,
        ~titleProps: option(BsReactNative.Style.t)=?,
        ~titleStyle: option(BsReactNative.Style.t)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=
        Js.Nullable.(
          {
            "buttonStyle": fromOption(buttonStyle),
            "clear": fromOption(clear),
            "containerStyle": fromOption(containerStyle),
            "disabled": fromOption(disabled),
            "disabledStyle": fromOption(disabledStyle),
            "disabledTitleStyle": fromOption(disabledTitleStyle),
            "icon": fromOption(icon),
            "iconContainerStyle": fromOption(iconContainerStyle),
            "iconRight": fromOption(iconRight),
            "loading": fromOption(loading),
            "loadingProps": fromOption(loadingProps),
            "loadingStyle": fromOption(loadingStyle),
            "onPress": fromOption(onPress),
            "title": fromOption(title),
            "titleProps": fromOption(titleProps),
            "titleStyle": fromOption(titleStyle),
          }
        ),
      children,
    );
};

module Header = {
  [@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Header";
  let make =
      (
        ~backgroundColor: option(string)=?,
        ~centerComponent: option(ReasonReact.reactElement)=?,
        children,
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
};

module Input = {
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
};

module Badge = {
  [@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Badge";
  /* type stringOrInt = [| `String(string) | Number(int) ]; */
  /* type of the value could either be string or integer */
  type value =
    | String(string)
    | Num(int);
  let valueChecker = v =>
    switch (v) {
    | String(input) => input
    | Num(input) => input |> string_of_int
    };
  let unwrapValue = v =>
    switch (v) {
    | None => ""
    | Some(v) => valueChecker(v)
    };
  /* end checks for value ! */
  let make = (~value: option(value)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=Js.Nullable.({"value": unwrapValue(value)}),
      children,
    );
};

module Card = {
  [@bs.module "react-native-elements"]
  external className : ReasonReact.reactClass = "Card";
  /* type for title could either be a string or a react component */
  type title =
    | String(string)
    | Component(ReasonReact.reactElement);
  let titleChecker = v =>
    switch (v) {
    | String(str) =>
      BsReactNative.(<Text> (str |> ReasonReact.stringToElement) </Text>)
    | Component(component) => component
    };
  let unwrwapTitle = opt =>
    switch (opt) {
    | None => ReasonReact.nullElement
    | Some(v) => titleChecker(v)
    };
  /* end the checks for title ! */
  let make =
      (
        ~containerStyle: option(BsReactNative.Style.t)=?,
        ~dividerStyle: option(BsReactNative.Style.t)=?,
        ~title: option(string)=?,
        ~image: option(BsReactNative.Image.imageSource)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=className,
      ~props=
        Js.Nullable.(
          {
            "containerStyle": fromOption(containerStyle),
            "dividerStyle": fromOption(dividerStyle),
            "title": fromOption(title),
            "image": fromOption(image),
          }
        ),
      children,
    );
};