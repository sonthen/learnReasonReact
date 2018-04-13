type obj;

external toObj : 'a => obj = "%identity";

external toJsObj : 'a => Js.t({..}) = "%identity";

module Mode = {
  type t =
    | Card
    | Modal;
  let toString = t =>
    switch (t) {
    | Card => "card"
    | Modal => "modal"
    };
};

module HeaderMode = {
  type t =
    | Float
    | Screen
    | None;
  let toString = t =>
    switch (t) {
    | Float => "float"
    | Screen => "screen"
    | None => "none"
    };
};

module HeaderTransitionPreset = {
  type t =
    | FadeInPlace
    | UiKit;
  let toString = t =>
    switch (t) {
    | FadeInPlace => "fade-in-place"
    | UiKit => "uikit"
    };
};

module GestureDirection = {
  type t =
    | Default
    | Inverted;
  let toString = t =>
    switch (t) {
    | Default => "default"
    | Inverted => "inverted"
    };
};

type gestureResponseDistance = {
  horizontal: int,
  vertical: int,
};

module NavigationOptions = {
  type js('obj) = {
    .
    "title": Js.Nullable.t(string),
    "header": Js.Nullable.t(ReasonReact.reactElement),
    "headerTitle": Js.Nullable.t(string),
    "headerTitleAllowFontScaling": Js.Nullable.t(bool),
    "headerBackImage": Js.Nullable.t(ReasonReact.reactElement),
    "headerBackTitle": Js.Nullable.t(string),
    "headerTruncatedBackTitle": Js.Nullable.t(string),
    "headerRight": Js.Nullable.t(ReasonReact.reactElement),
    "headerLeft": Js.Nullable.t(ReasonReact.reactElement),
    "headerStyle": Js.Nullable.t(BsReactNative.Style.t),
    "headerForceInset": Js.Nullable.t('obj),
    "headerTitleStyle": Js.Nullable.t(BsReactNative.Style.t),
    "headerBackTitleStyle": Js.Nullable.t(BsReactNative.Style.t),
    "headerTintColor": Js.Nullable.t(string),
    "headerPressColorAndroid": Js.Nullable.t(string),
    "headerTransparent": Js.Nullable.t(bool),
    "headerBackground": Js.Nullable.t(string),
    "gesturesEnabled": Js.Nullable.t(bool),
    "gestureResponseDistance": Js.Nullable.t(gestureResponseDistance),
    "gestureDirection": Js.Nullable.t(GestureDirection.t),
  };
  let create =
      (
        ~title: option(string)=?,
        ~header: option(ReasonReact.reactElement)=?,
        ~headerTitle: option(string)=?,
        ~headerTitleAllowFontScaling: option(bool)=?,
        ~headerBackImage: option(ReasonReact.reactElement)=?,
        ~headerBackTitle: option(string)=?,
        ~headerTruncatedBackTitle: option(string)=?,
        ~headerRight: option(ReasonReact.reactElement)=?,
        ~headerLeft: option(ReasonReact.reactElement)=?,
        ~headerStyle: option(BsReactNative.Style.t)=?,
        ~headerForceInset: option(Js.t({..}))=?,
        ~headerTitleStyle: option(BsReactNative.Style.t)=?,
        ~headerBackTitleStyle: option(BsReactNative.Style.t)=?,
        ~headerTintColor: option(string)=?,
        ~headerPressColorAndroid: option(string)=?,
        ~headerTransparent: option(bool)=?,
        ~headerBackground: option(string)=?,
        ~gesturesEnabled: option(bool)=?,
        ~gestureResponseDistance: option(gestureResponseDistance)=?,
        ~gestureDirection: option(GestureDirection.t)=?,
        (),
      )
      : js(Js.t({..})) =>
    Js.Nullable.(
      {
        "title": fromOption(title),
        "header": fromOption(header),
        "headerTitle": fromOption(headerTitle),
        "headerTitleAllowFontScaling":
          fromOption(headerTitleAllowFontScaling),
        "headerBackImage": fromOption(headerBackImage),
        "headerBackTitle": fromOption(headerBackTitle),
        "headerTruncatedBackTitle": fromOption(headerTruncatedBackTitle),
        "headerRight": fromOption(headerRight),
        "headerLeft": fromOption(headerLeft),
        "headerStyle": fromOption(headerStyle),
        "headerForceInset": fromOption(headerForceInset),
        "headerTitleStyle": fromOption(headerTitleStyle),
        "headerBackTitleStyle": fromOption(headerBackTitleStyle),
        "headerTintColor": fromOption(headerTintColor),
        "headerPressColorAndroid": fromOption(headerPressColorAndroid),
        "headerTransparent": fromOption(headerTransparent),
        "headerBackground": fromOption(headerBackground),
        "gesturesEnabled": fromOption(gesturesEnabled),
        "gestureResponseDistance": fromOption(gestureResponseDistance),
        "gestureDirection": fromOption(gestureDirection),
      }
    );
};

module Navigation = {
  type t;
  type action;
  type navigateParams('obj) = {
    .
    "routeName": string,
    "params": Js.Nullable.t('obj),
    "action": Js.Nullable.t(action),
    "key": Js.Nullable.t(string),
  };
  let createNavigateParams = (~routeName, ~params=?, ~action=?, ~key=?, ()) =>
    Js.Nullable.(
      {
        "routeName": routeName,
        "params": fromOption(params),
        "action": fromOption(action),
        "key": fromOption(key),
      }
    );
  [@bs.send]
  external navigate : (t, navigateParams(Js.t({..}))) => unit = "";
  [@bs.send] external goBack : (t, Js.Nullable.t(string)) => unit = "";
  /* remaining: addListener, isFocused, state, setParams, getParams */
  /* stack navigator specifics: push, pop, popToTop, replace */
  /* advanced: dispatch */
};

module RouteConfig = {
  type jsConfig('obj) = {
    .
    "screen":
      {
        .
        "navigation": Navigation.t,
        "screenProps": Js.Nullable.t('obj),
      } =>
      ReasonReact.reactElement,
    "path": string,
    "navigationOptions": Js.Nullable.t(NavigationOptions.js('obj)),
  };
  type js('obj) = Js.Dict.t(jsConfig('obj));
  let route =
      (
        ~screen:
           {
             .
             "navigation": Navigation.t,
             "screenProps": Js.Nullable.t(Js.t({..})),
           } =>
           ReasonReact.reactElement,
        ~path: string,
        ~navigationOptions: option(NavigationOptions.js(Js.t({..})))=?,
        (),
      )
      : jsConfig(Js.t({..})) => {
    "screen": screen,
    "path": path,
    "navigationOptions": Js.Nullable.fromOption(navigationOptions),
  };
  let create = (routes: list((string, jsConfig(Js.t({..}))))) =>
    Js.Dict.fromList(routes);
};

module StackNavigatorConfig = {
  type transition;
  type t('obj) = {
    initialRouteName: option(string),
    initialRouteParams: option(obj),
    navigationOptions: option(NavigationOptions.js('obj)),
    paths: option(Js.Dict.t(string)), /* TODO: unsure of the type */
    mode: option(Mode.t),
    headerMode: option(HeaderMode.t),
    headerTransitionPreset: option(HeaderTransitionPreset.t),
    cardStyle: option(BsReactNative.Style.t),
    transitionConfig: option((transition, transition, bool) => transition),
    onTransitionStart: option((transition, transition) => unit),
    onTransitionEnd: option((transition, transition) => unit),
  };
  type js('obj) = {
    .
    "initialRouteName": Js.Nullable.t(string),
    "initialRouteParams": Js.Nullable.t('obj),
    "navigationOptions": Js.Nullable.t(NavigationOptions.js('obj)),
    "paths": Js.Nullable.t(Js.Dict.t(string)), /* TODO: unsure of the type */
    "mode": Js.Nullable.t(string),
    "headerMode": Js.Nullable.t(string),
    "headerTransitionPreset": Js.Nullable.t(string),
    "cardStyle": Js.Nullable.t(BsReactNative.Style.t),
    "transitionConfig":
      Js.Nullable.t((transition, transition, bool) => transition),
    "onTransitionStart": Js.Nullable.t((transition, transition) => unit),
    "onTransitionEnd": Js.Nullable.t((transition, transition) => unit),
  };
  let create =
      (
        ~initialRouteName: option(string)=?,
        ~initialRouteParams: option(Js.t({..}))=?,
        ~navigationOptions: option(NavigationOptions.js(Js.t({..})))=?,
        ~paths: option(Js.Dict.t(string))=?,
        ~mode: option(Mode.t)=?,
        ~headerMode: option(HeaderMode.t)=?,
        ~headerTransitionPreset: option(HeaderTransitionPreset.t)=?,
        ~cardStyle: option(BsReactNative.Style.t)=?,
        ~transitionConfig:
           option((transition, transition, bool) => transition)=?,
        ~onTransitionStart: option((transition, transition) => unit)=?,
        ~onTransitionEnd: option((transition, transition) => unit)=?,
        (),
      )
      : js(Js.t({..})) =>
    Js.Nullable.(
      {
        "initialRouteName": fromOption(initialRouteName),
        "initialRouteParams": fromOption(initialRouteParams),
        "navigationOptions": fromOption(navigationOptions),
        "paths": fromOption(paths),
        "mode": fromOption(Utils.optionMap(Mode.toString, mode)),
        "headerMode":
          fromOption(Utils.optionMap(HeaderMode.toString, headerMode)),
        "headerTransitionPreset":
          fromOption(
            Utils.optionMap(
              HeaderTransitionPreset.toString,
              headerTransitionPreset,
            ),
          ),
        "cardStyle": fromOption(cardStyle),
        "transitionConfig": fromOption(transitionConfig),
        "onTransitionStart": fromOption(onTransitionStart),
        "onTransitionEnd": fromOption(onTransitionEnd),
      }
    );
};

module StackNavigator = {
  [@bs.module "react-navigation"]
  external _StackNavigator :
    (
      RouteConfig.js(Js.t({..})),
      Js.Nullable.t(StackNavigatorConfig.js(Js.t({..})))
    ) =>
    ReasonReact.reactClass =
    "StackNavigator";
  let make =
      (
        ~config: option(StackNavigatorConfig.js(Js.t({..})))=?,
        ~routes: RouteConfig.js(Js.t({..})),
      ) => {
    let reactClass = _StackNavigator(routes, Js.Nullable.fromOption(config));
    (
      ~screenProps: option(Js.t({..}))=?,
      children: array(ReasonReact.reactElement),
    ) =>
      ReasonReact.wrapJsForReason(
        ~reactClass,
        ~props={"screenProps": Js.Nullable.fromOption(screenProps)},
        children,
      );
  };
};

module NavigationActions = {
  type t;
  type action;
  [@bs.module "react-navigation"]
  external navgationActions : t = "NavigationActions";
  type navigateParams('obj) = {
    .
    "routeName": string,
    "params": Js.Nullable.t('obj),
    "action": Js.Nullable.t(action),
    "key": Js.Nullable.t(string),
  };
  let createNavigationParams =
      (~routeName, ~params=?, ~action=?, ~key=?, ())
      : navigateParams(Js.t({..})) =>
    Js.Nullable.(
      {
        "routeName": routeName,
        "params": fromOption(params),
        "action": fromOption(action),
        "key": fromOption(key),
      }
    );
  [@bs.send]
  external navigate : (t, navigateParams(Js.t({..}))) => action = "";
  type resetParams = {
    .
    "index": int,
    "actions": array(action),
    "key": Js.Nullable.t(string),
  };
  let createResetParams = (~index, ~actions, ~key=?, ()) : resetParams =>
    Js.Nullable.(
      {"index": index, "actions": actions, "key": fromOption(key)}
    );
  [@bs.send] external reset : (t, resetParams) => action = "";
  type replaceParams('obj) = {
    .
    "key": string,
    "newKey": Js.Nullable.t(string),
    "routeName": string,
    "params": Js.Nullable.t('obj),
    "action": Js.Nullable.t('obj),
    "immediate": Js.Nullable.t(bool),
  };
  let createReplaceParams =
      (~key, ~newKey=?, ~routeName, ~params=?, ~action=?, ~immediate=?, ())
      : replaceParams(Js.t({..})) =>
    Js.Nullable.(
      {
        "key": key,
        "newKey": fromOption(newKey),
        "routeName": routeName,
        "params": fromOption(params),
        "action": fromOption(action),
        "immediate": fromOption(immediate),
      }
    );
  [@bs.send]
  external replace : (t, replaceParams(Js.t({..}))) => action = "";
  type backParams = {. "key": Js.Nullable.t(string)};
  let createBackParams = (~key=?, ()) => {
    "key": Js.Nullable.fromOption(key),
  };
  [@bs.send] external back : (t, backParams) => action = "";
  type setParamsParams('obj) = {
    .
    "key": string,
    "params": 'obj,
  };
  let createSetParamsParams = (~key, ~params) : setParamsParams(Js.t({..})) => {
    "key": key,
    "params": params,
  };
  [@bs.send]
  external setParams : (t, setParamsParams(Js.t({..}))) => action = "";
};