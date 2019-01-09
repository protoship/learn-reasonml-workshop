/*
  In Reason there are 6 basic types: int, float, char, string, bool, and unit.

  The following exercises and examples will give you a brief introduction to
  these types. Feel free to play around with them in rtop.

  Note the keyword [let], which is how variable assignment is done in Reason.

  In Reason floats are distinguished from ints by their decimal points. 0 is an
  int, 0. is a float.

  In addition the basic math operations are also distinguished by a decimal
  point. For example, + allows you to add two ints and +. allows you to add two
  floats.

  Signatures
  ==========

  four is a value with the type int. We write the signature like this:

  let four : int

  Read it like this: "[four] is a value of type int".

  Signatures are similar to type declarations in other languages. They tell the
  compiler (and human readers of your code!) the types of variables and
  functions in your program. For example, in C, C++, and Java, the signature
  above would be written like so:

  int four;
 */
let four = 4;

/*
  floatFour is a value with the type float. We write the signature like this:

  let floatFour : float

  You may have noticed that the two signatures we showed you were in comments.
  Signatures are not always required! In many situations, you may omit them,
  and the compiler will infer the type of values.

  However, if you do write a signature for a value, the compiler will make sure
  to check that it's consistent with how that value is used.

  Try inserting an incorrect signature for [floatFour] to see what error the
  compiler gives you.
 */
let floatFour = 4.;

/*
  Function signatures
  ===================

  In Reason, functions are also values! And so, functions also have type
  signatures.

  In a function signature, types of parameters are enclosed within parentheses.
  The return value is the described last and preceded immediately by an arrow
  [=>].

  So the signature for a function that takes two integers and returns an
  integer is:

  let intAverage: (int, int) => int

  In Reason there's no explicit return statement: functions just return the
  value of the last statement in that function.
 */
/* let intAverage = (x, y) => failwith("For you to implement"); */
let intAverage = (x, y) => failwith("For you to implement");

/* let floatAverage : (float, float) => float */
/* let floatAverage = (x, y) => failwith("For you to implement"); */
let floatAverage = (x, y) => failwith("For you to implement");

/*
  The following expression computes the average of 10 and 20:

  intAverage(10, 20)

  As in many languages strings are denoted with "" and chars are denoted with ''.

  String concatenation is done with the ++ operator.

  let firstName : string
 */
let firstName = "Fred";

/* You can also write type annotations in definitions */
let lastName: string = "Flintstone";

/*
  But Reason has very strong type inference, so you can most often omit types,
  and the compiler can infer that fullName is a string.
 */
let fullName = firstName ++ " " ++ lastName;

let aBooleanFalse: bool = false;

/*
  You can use
  && for logical and
  || for logical or
  !  for logical not
 */
let () = assert (true || aBooleanFalse);

/*
  The [unit] type
  ===============

  unit is a special type in Reason that has only one possible value written ().
  It is generally used for mutation and io-operations such as printing.

  (I/O stands for input/output. Examples: printing to screen, reading a file,
  sending and receiving network requests.)

  To combine several unit operations together the ; operator is used contained
  within curly braces.
 */
let () = {
  print_endline("Hi, My name is ");
  print_endline(fullName);
  print_endline(" and I am 5 years old");
};

/*
  The lines that follow are inline tests. Each evaluates a boolean expression.
  They are run during the build, and failures -- evaluating to false -- are
  treated like compile errors by the build tool and editors.

  We will see other kinds of inline tests later, and some interesting patterns
  for using them.
  While Reason supports polymorphic comparison, it is good practice to use
  equality and comparison functions specific to each type.

  So, [Int.equal] is the [equal] function defined in the [Int] module. Its
  signature is

  val equal : int -> int -> bool

  In words: [equal] takes two [int]s and returns a [bool]. The following line
  is applying that function to two inputs, [5] and [int_average 5 5].
 */
Test.runAll([
  (intAverage(5, 5) == 5, "int average"),
  (floatAverage(5., 5.) == 5., "float average"),
  (floatAverage(5., 10.) == 7.5, "float average"),
]);
/*
  .rei files
  ==========

  Check out the [basicTypes.rei] file in this directory! It declares the types for
  the two functions you had to implement. If the types in the [.rei] don't
  match the types of the values in the [.re], the compiler will flag that as an
  error.
 */
