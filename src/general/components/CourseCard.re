open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container =
    flatten([|container, style([backgroundColor @@ "white"])|]);
  let card =
    style([
      height @@ Pt(100.),
      width @@ Pt(240.),
      backgroundColor @@ "#ababab",
      padding @@ Pt(10.),
      margin @@ Pt(10.),
      borderRadius @@ 2.,
    ]);
  let cardText = style([fontWeight(`Bold)]);
};

let component = ReasonReact.statelessComponent("CourseCard");

let make = _child => {
  ...component,
  render: _self =>
    <ScrollView contentContainerStyle=Styles.container>
      <View style=Styles.card>
        <Text
          style=Styles.cardText
          value="Mendorong Munculnya Motivasi Diri"
        />
      </View>
      <View style=Styles.card>
        <Text style=Styles.cardText value="CourseCard" />
      </View>
    </ScrollView>,
};