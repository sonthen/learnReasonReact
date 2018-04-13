open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container = flatten([|flex1|]);
};

let app = () =>
  <View style=Styles.container>
    <StatusBar barStyle=`lightContent />
    <Elements.Header backgroundColor="#000" />
    <View
      style=Style.(
              style([
                flex @@ 1.,
                justifyContent @@ Center,
                alignItems @@ Center,
              ])
            )>
      <Login />
    </View>
  </View>;