open! Base;

type option('a) =
  | None
  | Some('a);

let safe_divide: (~dividend: int, ~divisor: int) => option(int);
