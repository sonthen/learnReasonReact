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