open BsReactNative;

module Styles = {
  open GlobalStyles;
  open Style;
  let container = flatten([|flex1, style([backgroundColor @@ "white"])|]);
  let statusBar = style([height @@ Pt(23.)]);
};

module Nav = {
  let component = ReasonReact.statelessComponent("Nav");
  let make = _children => {
    ...component,
    render: _self =>
      ReactNavigation.(
        <StackNavigator
          routes=(
            RouteConfig.create([
              (
                Routes.showcaseMenu,
                RouteConfig.route(
                  ~screen=
                    props => <ShowcaseMenu navigation=props##navigation />,
                  ~path="/",
                  (),
                ),
              ),
              (
                Routes.Showcase.card,
                RouteConfig.route(
                  ~screen=_props => <CourseCard />,
                  ~path="/card",
                  (),
                ),
              ),
              (
                Routes.Showcase.homepage,
                RouteConfig.route(
                  ~screen=
                    _props =>
                      <View style=Styles.container>
                        <Text value="homepage" />
                      </View>,
                  ~path="/homepage",
                  (),
                ),
              ),
              (
                Routes.Showcase.button,
                RouteConfig.route(
                  ~screen=
                    _props =>
                      <View style=Styles.container>
                        <Text value="button" />
                      </View>,
                  ~path="/button",
                  (),
                ),
              ),
            ])
          )
          config=(
            StackNavigatorConfig.create(
              ~initialRouteName=Routes.showcaseMenu,
              ~headerMode=HeaderMode.None,
              (),
            )
          )
        />
      ),
  };
};

let app = () =>
  <View style=Styles.container>
    <StatusBar barStyle=`darkContent />
    <View style=Styles.statusBar />
    <Nav />
  </View>;