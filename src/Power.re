let rec range = x =>
  switch (x) {
  | 0 => []
  | num => [num, ...range(x - 1)] |> List.sort(compare)
  };

let powersOfTwo = x =>
  range(x + 1)
  |> List.mapi((_anything, id) => 2. ** (id - 1 |> float))
  |> List.map(n => n |> int_of_float);

let intPow = (base, pow) => {
  let resultFloat = (base |> float) ** (pow |> float);
  resultFloat |> int_of_float;
};

let rec powerOfTwo2 = x =>
  switch (x) {
  | 0 => [1]
  | num => [intPow(2, num), ...powerOfTwo2(x - 1)]
  };

