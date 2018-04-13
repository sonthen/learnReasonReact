open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container = flatten([|flex1, style([backgroundColor @@ "#2f2f2f"])|]);
};

module Nav = {};

let app = () =>
  <View style=Styles.container>
    <StatusBar barStyle=`lightContent />
    <ShowCaseMenu />
  </View>;