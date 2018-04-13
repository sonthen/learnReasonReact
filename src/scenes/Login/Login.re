open BsReactNative;

let component = ReasonReact.statelessComponent("Login");

type state = {
  emailInput: string,
  passwordInput: string,
};

module Cards = {
  let component = ReasonReact.statelessComponent("Cards");
  let make = _children => {
    ...component,
    render: _self =>
      <ScrollView horizontal=true>
        <Elements.Card
          title="hi this is it"
          image=(
            Image.URI(
              Image.imageURISource(
                ~uri=
                  "https://i.pinimg.com/736x/a6/a8/1c/a6a81c805d682e3fd2236aa129174fa7--cute-stuff-random-stuff.jpg",
                (),
              ),
            )
          )>
          <Text style=Style.(style([marginBottom @@ Pt(0.)]))>
            (
              "The idea with React Native Elements is more about component structure than actual design. "
              |> ReasonReact.stringToElement
            )
          </Text>
          <Elements.Button
            buttonStyle=Style.(
                          style([
                            backgroundColor @@ "#03A9F4",
                            borderRadius @@ 0.,
                            marginLeft @@ Pt(0.),
                            marginRight @@ Pt(0.),
                            marginBottom @@ Pt(0.),
                          ])
                        )
            title="View Now"
          />
        </Elements.Card>
        <Elements.Card
          title="hi this is it"
          image=(
            Image.URI(
              Image.imageURISource(
                ~uri=
                  "https://i.pinimg.com/736x/a6/a8/1c/a6a81c805d682e3fd2236aa129174fa7--cute-stuff-random-stuff.jpg",
                (),
              ),
            )
          )
        />
        <Elements.Card
          title="hi this is it"
          image=(
            Image.URI(
              Image.imageURISource(
                ~uri=
                  "https://i.pinimg.com/736x/a6/a8/1c/a6a81c805d682e3fd2236aa129174fa7--cute-stuff-random-stuff.jpg",
                (),
              ),
            )
          )
        />
        <Elements.Card
          title="hi this is it"
          image=(
            Image.URI(
              Image.imageURISource(
                ~uri=
                  "https://i.pinimg.com/736x/a6/a8/1c/a6a81c805d682e3fd2236aa129174fa7--cute-stuff-random-stuff.jpg",
                (),
              ),
            )
          )
        />
        <Elements.Card
          title="hi this is it"
          image=(
            Image.URI(
              Image.imageURISource(
                ~uri=
                  "https://i.pinimg.com/736x/a6/a8/1c/a6a81c805d682e3fd2236aa129174fa7--cute-stuff-random-stuff.jpg",
                (),
              ),
            )
          )
        />
      </ScrollView>,
  };
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
      <View style=GlobalStyles.container>
        <View style=Style.(style([flex @@ 2.]))> <Cards /> </View>
        <View style=Style.(style([flex @@ 8.]))>
          <Text> (UtilsCaml.times(4, 5) |> string_of_int |> Utils.str) </Text>
          <Elements.Badge value=(Num(65)) />
          <Elements.Button
            onPress=(_e => handleClick(_e))
            buttonStyle=Styles.buttonStyle
            title="Login"
          />
        </View>
      </View>,
  };
};