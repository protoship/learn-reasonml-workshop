/*
  In Reason, functions are values, so we can pass them in as
  arguments to other functions.

  To represent a function in a signature, you wrap its type in parenthesis,
  with arrows separating arguments and the type of the functions result.

  Recall: a function called add1 which takes an integer and returns an integer
  has the type
  let add1 : int => int

  so, to use that signature in a type, we'd write
  (int => int)

  We now define a function called mapOption.
  mapOption takes a function and an option.

  If the option has a value of None, mapOption returns None
  If the option has a value of Some x, the function is called on x, and
  wrapped up in a Some.

  This may seem unintuitive, but this kind of function is very useful.
  It means that you can continue working on data, and ignore if
  the data isn't there (no null pointer exceptions!)

  The signature for the function is

  let mapOption : (('a => 'b), option('a)) => option('b)
 */
let mapOption = (f, opt) =>
  switch (opt) {
  | None => None
  | Some(i) => Some(f(i))
  };

let double = i => 2 * i;

let () = assert (mapOption(double, None) == None);

let () = assert (mapOption(double, Some(2)) == Some(4));

/*
  Instead of defining the function double beforehand, we can use an anonymous
  function.
 */
let () = assert (mapOption(i => 2 * i, Some(2)) == Some(4));

/*
  Define a function applyIfNonzero which takes a function from (int => int)
  and an int, and applies the function if the integer is not zero, and
  otherwise just returns 0.
 */
let applyIfNonzero = (f, i) => failwith("For you to implement");

Test.runAll([
  (applyIfNonzero(x => 10 / x, 0) == 0, "apply if non-zero"),
  (applyIfNonzero(x => 10 / x, 5) == 2, "apply if non-zero"),
]);