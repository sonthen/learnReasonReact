let minus a b = a - b;;
let tambah a b = a + b;;
let even x = x mod 2 = 0;;
let odd x = x mod 2 <> 0;;
let times a b = a * b;;

let rec camelRange x =
  match x with
  | 0 -> []
  | num -> num :: camelRange (x-1);;

let sum_if_true (test: int -> bool) (first: int) (second: int) =
  (if test first then first else 0) + (if test second then second else 0);;