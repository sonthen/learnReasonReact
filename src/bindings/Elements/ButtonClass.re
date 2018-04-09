open BsReactNative;

/*
    TODO: (Gemx) Props for button.
    buttonStyle
    clear
    containerStyle
    disabled
    disabledStyle
    disabledTitleStyle
    icon
    iconContainerStyle
    iconRight
    linearGradientProps
    loading
    loadingProps
    loadingStyle
    onPress
    title
    titleProps
    titleStyle
    TouchableComponent
    ViewComponent
 */
[@bs.module "react-native-elements"]
external componentClass : ReasonReact.reactClass = "Button";

let make =
    (
      ~buttonStyle: option(BsReactNative.Style.t)=?,
      ~clear: option(bool)=?,
      ~containerStyle: option(BsReactNative.Style.t)=?,
      ~disabled: option(bool)=?,
      ~disabledStyle: option(BsReactNative.Style.t)=?,
      ~disabledTitleStyle: option(BsReactNative.Style.t)=?,
      ~title: string,
      ~loading: option(bool)=?,
      ~onPress: option(_ => _)=?,
      ~loadingProps: option(BsReactNative.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=componentClass,
    ~props=
      Js.Nullable.(
        {
          "title": title,
          "buttonStyle": fromOption(buttonStyle),
          "clear": fromOption(clear),
          "loading": fromOption(loading),
          "onPress": fromOption(onPress),
          "containerStyle": containerStyle,
          "loadingProps": loadingProps,
        }
      ),
    children,
  );