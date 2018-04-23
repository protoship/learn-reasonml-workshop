/*
  Reason, like many other languages, provides a way to interact with code via
  interfaces. This allows implementation details to be hidden away, and for
  grouped units of code to restrict how they are used.

  Here's an example of a module signature coupled with an implementation. The
  signature is wrapped in curly braces similar to the implementation.
 */
module Example: {
  /* Here, 'let' indicates that we are exposing a value. This value is an integer */
  let theMeaningOfLifeTheUniverseAndEverything: int;
  /*
    To declare functions, again we use 'let' - in Reason, functions are values.
    This value takes an integer as a parameter and returns an integer
   */
  let subtractOne: int => int;
} = {
  let theMeaningOfLifeTheUniverseAndEverything = 42;
  let subtractOne = x => x - 1;
};

/* Here's how we use these values */
let oneLessThanTheMeaningOfLifeEtc =
  Example.subtractOne(Example.theMeaningOfLifeTheUniverseAndEverything);

assert (oneLessThanTheMeaningOfLifeEtc == 41);

/*
  Types can be exposed via signatures in Reason as well. Here's an example of declaring
  an "abstract" type - one where the definition of the type is not exposed.
 */
module AbstractTypeExample: {
  /* We do not let the user know that [t] is an integer */
  type t;
  /* This function allows [t] to be coerced into an integer */
  let toInt: t => int;
  /* Users need some way to start with some [t] */
  let zero: t;
  let one: t;
  /* Let them do something with the [t]*/
  let add: (t, t) => t;
} = {
  type t = int;
  let toInt = x => x;
  let zero = 0;
  let one = 1;
  let add = (+);
};

/* Here's an example of adding 2 and 2 */
let two =
  AbstractTypeExample.add(AbstractTypeExample.one, AbstractTypeExample.one);

let four = AbstractTypeExample.toInt(AbstractTypeExample.add(two, two));

assert (four == 4);

module Fraction: {
  type t;
  /*
    TODO: Add signatures for the create and value functions to expose them in
    the Fraction module.
   */
} = {
  type t = (int, int);
  let create = (~numerator, ~denominator) => (numerator, denominator);
  let value = ((numerator, denominator)) =>
    float_of_int(numerator) /. float_of_int(denominator);
};
/* TODO: After adding signatures above uncomment the tests below */
/* Test.runAll([
     (
       Fraction.value(Fraction.create(~numerator=5, ~denominator=2)) == 2.5,
       "Fraction.value",
     ),
     (
       Fraction.value(Fraction.create(~numerator=4, ~denominator=10)) == 0.4,
       "Fraction.value",
     ),
   ]); */