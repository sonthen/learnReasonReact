open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container = flatten([|flex1, style([backgroundColor @@ "#2f2f2f"])|]);
};

module Nav = {
  let component = ReasonReact.statelessComponent("Nav");
  let make = _children => {
    ...component,
    render: _children =>
      <View> <Text> ("nav" |> ReasonReact.stringToElement) </Text> </View>,
  };
};

let app = () => <ShowCaseMenu />;