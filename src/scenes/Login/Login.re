open BsReactNative;

let component = ReasonReact.statelessComponent("Login");

type state = {
  emailInput: string,
  passwordInput: string,
};

let make = _children => {
  let handleClick = _e => Js.log("clicked");
  {
    ...component,
    /* initialState: () => {emailInput: "", passwordInput: ""},
       reducer: (action, state) => {.}, */
    render: _self =>
      <View>
        <Text> (ReasonReact.stringToElement("hi")) </Text>
        <Elements.Button
          onPress=(_e => handleClick(_e))
          buttonStyle=Style.(
                        style([
                          backgroundColor @@ "rgba(92, 99,216, 1)",
                          width @@ Pt(300 |> float),
                          height @@ Pt(45.),
                          borderColor @@ "transparent",
                          borderWidth @@ 0.,
                          borderRadius @@ 5.,
                        ])
                      )
          title="Login"
        />
      </View>,
  };
};