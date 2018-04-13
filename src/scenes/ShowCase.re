open BsReactNative;

module Styles = {
  open Style;
  let showCaseContainer = style([flex @@ 1., justifyContent @@ Center]);
  let buttonStyle =
    style([
      backgroundColor @@ "#DB4D3F",
      width @@ Pt(300 |> float),
      height @@ Pt(45.),
      borderColor @@ "transparent",
      borderWidth @@ 0.,
      borderRadius @@ 5.,
    ]);
};

let component = ReasonReact.statelessComponent("ShowCase");

let make = _children => {
  ...component,
  render: _self =>
    <View
      style=Style.(
              flatten([|
                GlobalStyles.container,
                style([
                  backgroundColor @@ "#2f2f2f",
                  justifyContent @@ SpaceAround,
                  marginVertical @@ Pt(290.),
                ]),
              |])
            )>
      <Elements.Button buttonStyle=Styles.buttonStyle title="Card Showcase" />
      <Elements.Button
        buttonStyle=Styles.buttonStyle
        title="Homepage Showcase"
      />
      <Elements.Button
        buttonStyle=Styles.buttonStyle
        title="Button Showcase"
      />
    </View>,
};