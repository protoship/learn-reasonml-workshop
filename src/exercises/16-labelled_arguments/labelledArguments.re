/*
  The following function has the signature:

  let divide : int -> int -> int

  Looking at just the signature, it's not obvious which int argument is
  the dividend and which is the divisor.
 */
let divide = (dividend, divisor) => dividend / divisor;

/*
  We can fix this using labelled arguments.

  To label an argument in a signature, and when defining a function, we
  put a tilde (~) before the name of the argument.

  The following function has the signature:

  let divide: (~dividend:int, ~divisor:int) => int
 */
let divide = (~dividend, ~divisor) => dividend / divisor;

/*
  We can then call it using: divide(~dividend=9, ~divisor=3)

  Labelled arguments can be passed in in any order.

  We can also pass variables into the labelled argument:

  let dividend = 9;
  let divisor  = 3;
  divide(~dividend=dividend, ~divisor=divisor)

  If the variable name happens to be the same as the labelled argument, we
  don't even have to write it twice:

  let dividend = 9;
  let divisor  = 3;
  divide(~dividend, ~divisor)

  This short-hand syntax is called punning.

  Now implement [modulo(~dividend, ~divisor)] using our version of divide with
  labelled arguments (e.g. [modulo(~dividend:7, ~divisor:2)] should equal 1)
 */
let modulo = (~dividend, ~divisor) => failwith("For you to implement");

Test.runAll([
  (modulo(~dividend=17, ~divisor=5) == 2, "modulo"),
  (modulo(~dividend=99, ~divisor=9) == 0, "modulo"),
]);