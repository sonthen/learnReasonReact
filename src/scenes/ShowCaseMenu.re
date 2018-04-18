open BsReactNative;

module Styles = {
  open Style;
  let showcaseContainer = style([flex @@ 1.]);
  let whiteText = style([color @@ "white", fontWeight @@ `Bold]);
  let showcaseHeader =
    flatten([|
      GlobalStyles.container,
      style([backgroundColor @@ "blue", flex @@ 1.]),
    |]);
  let showcaseContent =
    flatten([|
      GlobalStyles.container,
      style([
        backgroundColor @@ "white",
        justifyContent @@ SpaceAround,
        padding @@ Pt(10.),
        flex @@ 8.,
      ]),
    |]);
  let buttonStyle =
    style([
      backgroundColor @@ "#DB4D3F",
      width @@ Pt(300 |> float),
      height @@ Pt(45.),
      borderRadius @@ 5.,
      marginVertical @@ Pt(5.),
    ]);
};

type menuButton = {key: string};

let component = ReasonReact.statelessComponent("Showcase");

/* let renderButton = (menu: FlatList.renderBag(menuButton)) =>
   <Elements.Button
     buttonStyle=Styles.buttonStyle
     title=menu.item.key
     onPress=(
       (_) =>
         ReactNavigation.Navigation.(
           navigate(navigation, createNavigateParams(~routeName=item.key, ()))
         )
     )
   />; */
let showcaseItem = [|
  {key: Routes.Showcase.card},
  {key: Routes.Showcase.button},
  {key: Routes.Showcase.homepage},
|];

let make = (~navigation: ReactNavigation.Navigation.t, _children) => {
  ...component,
  render: _self =>
    <View style=Styles.showcaseContainer>
      <View style=Styles.showcaseHeader>
        <Text value="Showcase" style=Styles.whiteText />
      </View>
      <View style=Styles.showcaseContent>
        <FlatList
          data=showcaseItem
          keyExtractor=((item, _index) => item.key)
          /* renderItem=(FlatList.renderItem(renderButton)) */
          renderItem=(
            FlatList.renderItem((menu: FlatList.renderBag(menuButton)) =>
              <Elements.Button
                buttonStyle=Styles.buttonStyle
                title=menu.item.key
                onPress=(
                  (_) =>
                    ReactNavigation.Navigation.(
                      navigate(
                        navigation,
                        createNavigateParams(~routeName=menu.item.key, ()),
                      )
                    )
                )
              />
            )
          )
        />
      </View>
    </View>,
};