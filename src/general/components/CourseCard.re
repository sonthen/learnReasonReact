open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container =
    flatten([|
      container,
      style([
        backgroundColor @@ "white",
        padding @@ Pt(10.),
        marginBottom @@ Pt(10.),
      ]),
    |]);
  let card =
    style([
      height @@ Pt(100.),
      width @@ Pt(240.),
      backgroundColor @@ "#ababab",
      borderColor @@ "grey",
      borderWidth @@ 1.,
      padding @@ Pt(15.),
      margin @@ Pt(10.),
      borderRadius @@ 2.,
    ]);
  let cardIcon = style([alignSelf @@ FlexEnd, flexDirection @@ Row]);
  let iconLeftSegment =
    style([flexDirection @@ Row, padding @@ Pt(10.), alignItems @@ Center]);
  let iconRightSegment =
    style([flexDirection @@ Row, padding @@ Pt(10.), alignItems @@ Center]);
  let cardText = style([fontWeight(`Bold)]);
  let headerText = style([fontSize @@ Float(26.)]);
};

let component = ReasonReact.statelessComponent("CourseCard");

let make = _child => {
  ...component,
  render: _self =>
    <ScrollView contentContainerStyle=Styles.container>
      <Text style=Styles.headerText value="What Do You Want to Learn Today?" />
      <Elements.Card
        title="Young Gema"
        image=(
          Image.URI(
            Image.imageURISource(
              ~uri=
                "https://preview.ibb.co/ku2TNS/Screen_Shot_2018_04_18_at_3_43_48_PM.png",
              (),
            ),
          )
        )>
        <Text value="Gema yang dulu bukanlah yang sekarang" />
        <View style=Styles.cardIcon>
          <View style=Styles.iconLeftSegment>
            <Elements.Icon type_=MaterialCommunity name="book-variant" />
            <Text value="12" />
          </View>
          <View style=Styles.iconRightSegment>
            <Elements.Icon type_=MaterialCommunity name="clock" />
            <Text value="23 mins" />
          </View>
        </View>
      </Elements.Card>
      <Elements.Card containerStyle=Styles.card>
        <Text value="Mendorong Munculnya Motivasi Diri" />
        <View style=Styles.cardIcon>
          <View style=Styles.iconLeftSegment>
            <Elements.Icon type_=MaterialCommunity name="book-variant" />
            <Text value="12" />
          </View>
          <View style=Styles.iconRightSegment>
            <Elements.Icon type_=MaterialCommunity name="clock" />
            <Text value="23 mins" />
          </View>
        </View>
      </Elements.Card>
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