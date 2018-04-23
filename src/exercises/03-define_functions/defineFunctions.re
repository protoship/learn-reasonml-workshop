/*
  We use let to define functions.

  Definitions take on the form:
  let functionName = (arg1, arg2) => body;

  For example, here we define a function add1 that takes a single int
  argument and returns that argument plus 1.
 */
let add1 = arg => arg + 1;

/* This function uses the built-in ++ operator to append strings. */
let stringAppend = (x, y) => x ++ y;

/* Let's define our own functions using +, -, *, and / below. */
let plus = (x, y) => failwith("For you to implement");

let times = (x, y) => failwith("For you to implement");

let minus = (x, y) => failwith("For you to implement");

let divide = (x, y) => failwith("For you to implement");

Test.runAll([
  (plus(1, 1) == 2, "plus"),
  (plus(50, -1) == 49, "plus"),
  (times(8, 8) == 64, "times"),
  (times(2, -1024) == (-2048), "times"),
  (minus(-2, 2) == (-4), "minus"),
  (minus(1337, 337) == 1000, "minus"),
  (divide(1024, 2) == 512, "divide"),
  (divide(31337, 31) == 1010, "divide"),
]);