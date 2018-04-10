[@bs.module "expo"]
external constants : {
  .
  "appOwnership": string,
  "deviceId": string,
  "devinceName": string,
  "deviceYearClass": int,
  "expoRuntimeVersion": string,
  "expoVersion": string,
  "getWebViewUserAgentAsync": unit => unit,
  "isDevice": bool,
  "linkingUri": string,
  "linkingUrl": string,
  "manifest": {
    .
    "bundleUrl": string,
    "debuggerHost": string,
    "developer": {
      .
      "projectRoot": string,
      "tool": string,
    },
  },
  "env": {..}, /* TODO: unsure of type */
  "id": string,
  "isVerified": bool,
  "logUrl": string,
  "mainModuleName": string,
  "name": string,
  "packagerOpts": {..},
  "sdkVersion": string,
  "slug": string,
  "version": string,
  "xde": bool,
  "platform": {..},
  "sessionId": string,
  "statusBarHeight": int,
  "systemFonts": array(string),
} =
  "Constants";

module LinearGradient = {
  [@bs.module "expo"]
  external reactClass : ReasonReact.reactClass = "LinearGradient";
  let make =
      (
        ~colors: list(string),
        ~style: option(BsReactNative.Style.t)=?,
        ~start: option((float, float))=?,
        ~end_: option((float, float))=?,
        ~locations: option(list(float))=?,
        children,
      ) => {
    let colorsArray = colors |> Array.of_list;
    let startCoord =
      switch (start) {
      | Some((x, y)) => Some([|x, y|])
      | None => None
      };
    let endCoord =
      switch (end_) {
      | Some((x, y)) => Some([|x, y|])
      | None => None
      };
    let locationsArray =
      switch (locations) {
      | Some(locs) => Some(Array.of_list(locs))
      | None => None
      };
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "colors": colorsArray,
            "style": fromOption(style),
            "start": fromOption(startCoord),
            "end": fromOption(endCoord),
            "locations": fromOption(locationsArray),
          }
        ),
      children,
    );
  };
};