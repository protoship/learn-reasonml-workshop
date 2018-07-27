/*
  It is common in all programming languages to want to store and operate on
  collections of the same data type. As you have seen in previous exercises,
  we can achieve this in Reason using the list('a) type, e.g. list(int),
  list(bool), list(list(string)).

  When you first learn to program in languages like C and Java, you use "for"
  loops to operate on all the elements of an array, e.g.:

    for (int i = 0; i < array.length(); i++) { do_something_with(array[i]); }

  In Reason, we use "higher order functions", in other words, functions which
  take other functions as input. Let's take a look at the [List.map] function,
  which has signature:

    let map : (('a => 'b), list('a)) => list('b)

  Let's read this signature together. It takes two arguments:
    1) a function from some type ['a] to some other type ['b]
    2) a list of ['a]s
  and then it returns a list of ['b]s.

  What map(f, la) does is take your function [f], apply it to each element of
  [la], and returns a new list [lb] here the the [i]th element of [lb] is
  equal to the function [f] applied to the [i]th element of [la].

  Let's see some examples:
 */
let myInts: list(int) = [1, 2, 3, 4, 5];

let doubleMyInts = ints : list(int) => List.map(x => x * 2, ints);

let () = assert (doubleMyInts(myInts) == [2, 4, 6, 8, 10]);

let myStrings = ints : list(string) => List.map(string_of_int, ints);

let () = assert (myStrings(myInts) == ["1", "2", "3", "4", "5"]);

/*
  Exercise: implement the value [myNewInts], which is obtained by adding 1 to
  each element of [myInts]
 */
let myNewInts = ints => failwith("For you to implement");

/*
  If the function you want to perform on each element of your list is one that
  returns [unit], meaning that all it does is perform some side-effect (like
  [Js.log]), there is a higher-order function called [List.iter] which has the
  following signature:

  let iter:  ('a => unit, list('a)) => unit
 */
let () = List.iter(i => Js.log("here's an int: " ++ i), myStrings(myInts));

/*
  Another thing you might want to do with a list is combine all the elements
  together in some way. Here is the signature of [List.fold_left]:

  let fold_left: (('b, 'a) => 'b, 'b, list('a)) => 'b

  Let's say your list [l] contains [a1, a2, a3]. Then if you call
  fold_left(f, i, l), then it will end up computing:

    (f (f (f i a1) a2) a3)

  Here's an example of using [fold_left] to compute a sum:
 */
let sumOfMyInts = ints : int =>
  List.fold_left((total, myInt) => total + myInt, 0, ints);

let () = assert (sumOfMyInts(myInts) == 15);

/*
  Exercise: use [List.fold_left] to compute the number of elements of
  [myInts] that are even

  Hint: Use the infix operator `mod`.
    (4 mod 2 == 0)
 */
let numEvenInts = ints => failwith("For you to implement");

/*
  Here's one more example of a useful list function: [List.find]:

  let find: ('a => bool, list('a)) => 'a

 */
let firstNumGreaterThan3 = ints => List.find(x => x > 3, ints);

let () = assert (firstNumGreaterThan3(myInts) == 4);

Test.runAll([
  (myNewInts(myInts) == [2, 3, 4, 5, 6], "my new ints"),
  (numEvenInts(myInts) == 2, "num even ints"),
]);