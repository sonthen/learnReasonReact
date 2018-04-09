open BsReactNative;

let add = (a, b) => a + b;

type counter =
  | Zero
  | Value(int);

type input =
  | Value(string);

type state = {
  counter,
  input,
};

type action =
  | Increment
  | Decrement
  | Reset
  | SetCounter(int);

let component = ReasonReact.reducerComponent("Counter");

module Handlers = {
  let handleIncrement = _e => Increment;
  let handleDecrement = _e => Decrement;
  let handleReset = _e => Reset;
  let handlesetCounter = (inputValue, _e) => SetCounter(inputValue);
};

let toStr = ReasonReact.stringToElement;

let make = _children => {
  ...component,
  initialState: () => {counter: Value(1), input: Value("")},
  reducer: (action, state) =>
    switch (action, state.counter) {
    | (Increment, Zero) => ReasonReact.Update({...state, counter: Value(1)})
    | (Increment, Value(currentCount)) =>
      ReasonReact.Update({...state, counter: Value(currentCount + 1)})
    | (Decrement, Zero) => ReasonReact.NoUpdate
    | (Decrement, Value(currentCount)) =>
      currentCount <= 0 ?
        ReasonReact.Update({...state, counter: Zero}) :
        ReasonReact.Update({...state, counter: Value(currentCount - 1)})
    | (Reset, _) => ReasonReact.Update({...state, counter: Value(0)})
    | (SetCounter(anything), _) =>
      ReasonReact.Update({...state, counter: Value(anything)})
    },
  render: self => {
    let currentCount =
      switch (self.state.counter) {
      | Zero => 0
      | Value(currentCount) => currentCount
      };
    <View>
      <Text> (currentCount |> string_of_int |> toStr) </Text>
      <Button title="+" onPress=(self.reduce(Handlers.handleIncrement)) />
      <Button title="-" onPress=(self.reduce(Handlers.handleDecrement)) />
      <TextInput />
    </View>;
  },
};