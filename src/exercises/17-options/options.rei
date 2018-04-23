type option('a) =
  | None
  | Some('a);

let safeDivide: (~dividend: int, ~divisor: int) => option(int);