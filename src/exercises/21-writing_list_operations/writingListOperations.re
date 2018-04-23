/*
  It is common in all programming languages to want to store and operate on
  collections of the same data type. Reason natively supports linked lists,
  which have type list('a).

  When you first learn to program in languages like C and Java, you use "for"
  loops to operate on all the elements of a collection. For example, if we
  wanted to compute the sum of a list of integers in Python, we could write:

  numbers = [1,2,3] acc = 0 for x in numbers: acc = acc + x

  result = acc assert (6 == result)

  We chose the variable name "acc" to be short for accumulator.

  In Reason, instead of for loops we use "higher order functions"; in other
  words, functions which take other functions as input. Let's take a look at
  the [List.fold_left] function, which has signature:

  let fold_left: (('a, 'b) => 'a, 'a, list('b)) => 'a

  'a is the type of the accumulator, and 'b is the type of the values in the
  input list.

  The 1st argument is a function for updating the accumulator. The 2nd
  argument is the initial accumulator value. The final argument is the list
  to process.

  List.fold_left walks over the list from left to right, updating the
  accumulator at each step and returning the final value of the accumulator
  when it's done.

  Let's rewrite the Python code above in Reason. In this case, types 'a and 'b
  are both equal to int.
 */
let numbers = [1, 2, 3];

let result = List.fold_left((acc, x) => acc + x, 0, numbers);

let () = assert (6 == result);

/* Now let's use List.fold_left to write some other useful List functions. */
module MyList: {
  /*
    map(f, list) takes a function [f] from ('a => 'b) and a list('a) and
    returns a list('b) (e.g. [f] applied to each element)
   */
  let map: ('a => 'b, list('a)) => list('b);
  /*
    iter(f, list) calls [f] on each element in [list]. Since [f] returns
    [unit], there is nothing to return
   */
  let iter: ('a => unit, list('a)) => unit;
  /*
    filter(f, list) runs [f] on each element in [list] and returns a new list
    consisting of all elements [f] returned [true] for
   */
  let filter: ('a => bool, list('a)) => list('a);
} = {
  /* TODO */
  let map = (f, lst) => failwith("For you to implement");
  /* TODO */
  let iter = (f, lst) => failwith("For you to implement");
  /* TODO */
  let filter = (f, lst) => failwith("For you to implement");
};

/*
  Here are some other list functions that you may find useful in future
  exercises.

  You can see the full signature of the List module here:

  https://caml.inria.fr/pub/docs/manual-ocaml/libref/List.html

  List.hd returns the first element of the list. It raises an exception if
  called on an empty list. The signature is:

  let hd: list('a) => 'a;
 */
let () = assert (List.hd([1, 2, 3]) == 1);

/*
  Similarly, List.tl returns all but the first element of the list. It also raises
  an exception if called on an empty list. The signature is:

  let tl: list('a) => list('a);
 */
let () = assert (List.tl([1, 2, 3]) == [2, 3]);

/*
  List.rev returns the reverse of the input list.

  let rev: list('a) => list('a);
 */
let () = assert (List.rev([1, 2, 3]) == [3, 2, 1]);

/*
  List.mem returns a bool indicating if the given element is contained in the
  list.

  let mem: ('a, list('a)) => bool;
 */
let () = assert (List.mem(3, [1, 2, 3]));

/*
  List.sort returns a sorted list in increasing order according to the specified
  comparison function. The comparison function should return a negative number to
  indicate the first element is smaller, 0 to indicate they are equal, and a positive
  number to indicate the first element is larger.

  let sort: (('a, 'a) => int, list('a)) => list('a);
 */
let () = assert (List.sort((x, y) => x - y, [3, 1, 2]) == [1, 2, 3]);

let acc = ref(0);

MyList.iter(
  x =>
    if (x > acc^) {
      acc := x;
    },
  [1, 8, 5, 2, 7, 3],
);

Test.runAll([
  (MyList.map(x => 2 * x, [1, 2, 3, 4]) == [2, 4, 6, 8], "MyList.map"),
  (acc^ == 8, "MyList.iter"),
  (
    MyList.filter(x => x mod 2 == 0, [1, 3, 7, 8, 9, 2]) == [8, 2],
    "MyList.filter",
  ),
]);