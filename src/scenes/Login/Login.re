open BsReactNative;

let component = ReasonReact.statelessComponent("Login");

type state = {
  emailInput: string,
  passwordInput: string,
};

module Styles = {
  open Style;
  let buttonStyle =
    style([
      backgroundColor @@ "rgba(92, 99,216, 1)",
      width @@ Pt(300 |> float),
      height @@ Pt(45.),
      borderColor @@ "transparent",
      borderWidth @@ 0.,
      borderRadius @@ 5.,
    ]);
};

let make = _children => {
  let handleClick = _e => Js.log("clicked");
  {
    ...component,
    /* initialState: () => {emailInput: "", passwordInput: ""},
       reducer: (action, state) => {.}, */
    render: _self =>
      <View>
        <Elements.Button
          onPress=(_e => handleClick(_e))
          buttonStyle=Styles.buttonStyle
          title="Login"
        />
      </View>,
  };
};