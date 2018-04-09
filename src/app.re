open BsReactNative;

/* open Elements; */
let app = () =>
  <View
    style=Style.(
            style([
              flex @@ 1.,
              justifyContent @@ Center,
              alignItems @@ Center,
            ])
          )>
    <Text> ("Counter App" |> ReasonReact.stringToElement) </Text>
    <Login />
  </View>;