open! Base;

/* It is common in all programming languages to want to store and operate on
   collections of the same data type. OCaml natively supports linked lists,
   which have type 'a list.

   When you first learn to program in languages like C and Java, you use "for"
   loops to operate on all the elements of a collection. For example, if we
   wanted to compute the sum of a list of integers in Python, we could write:

   numbers = [1,2,3] acc = 0 for x in numbers: acc = acc + x

   result = acc assert (6 == result)

   We chose the variable name "acc" to be short for accumulator.

   In OCaml, instead of for loops we use "higher order functions"; in other
   words, functions which take other functions as input. Let's take a look at
   the [List.fold_left] function, which has signature:

   val fold_left : f:('a -> 'b -> 'a) -> init:'a -> 'b list -> 'a

   'a is the type of the accumulator, and 'b is the type of the values in the
   input list.

   f is a function for updating the accumulator. init is the initial accumulator
   value. The unlabelled argument is the list to process.

   List.fold_left walks over the list from left to right, updating the
   accumulator at each step and returning the final value of the accumulator
   when it's done.

   Let's rewrite the Python code above in OCaml. In this case, types 'a and 'b
   are both equal to int. */
let numbers = [1, 2, 3];

let result = List.fold_left(numbers, ~init=0, ~f=(acc, x) => acc + x);

let () = assert (6 == result);

/* Now let's use List.fold_left to write some other useful List functions. */
module My_list: {
  /** [map f list] takes a function [f] from ('a -> 'b) and
      an ['a list], and returns a ['b list] (e.g. [f] applied to each element.) */
  let map: ('a => 'b, list('a)) => list('b);
  /** [iter f list] calls [f] on each element of [list]. Since [f]
      returns [unit], there is nothing to return */
  let iter: ('a => unit, list('a)) => unit;
  /** [filter f list] runs [f] on each element in [list] and
      returns a new list consisting of all elements [f] returned
      [true] for. */
  let filter: ('a => bool, list('a)) => list('a);
} = {
  /* TODO */
  let map = (f, lst) => failwith("For you to implement");
  /* TODO */
  let iter = (f, lst) => failwith("For you to implement");
  /* TODO */
  let filter = (f, lst) => failwith("For you to implement");
};

/* Here are some other list functions that you may find useful in future exercies.

      You can see the full signature of the List module here:

      https://ocaml.janestreet.com/ocaml-core/v1.0/doc/base/Base/List/index.html
   */
/* List.hd_exn returns the first element of the list. It raises an exception if
   called on an empty list. The signature is:

   val hd_exn : 'a list -> 'a */
%test
Int.equal(List.hd_exn([1, 2, 3]), 1);

/* Similarly, List.tl returns all but the first element of the list. It also raises
      an exception if called on an empty list. The signature is:

      val tl : 'a list -> 'a list
   */
%test
[%compare.equal: list(int)](List.tl_exn([1, 2, 3]), [2, 3]);

/* List.rev returns the reverse of the input list.

      val rev : 'a list -> 'a list
   */
%test
[%compare.equal: list(int)](List.rev([1, 2, 3]), [3, 2, 1]);

/* List.mem returns a bool indicating if the given element is contained in the list.

      val mem : 'a list -> equal:('a -> 'a -> bool) -> 'a -> bool
   */
let () = assert (List.mem(~equal=Int.equal, [1, 2, 3], 3));

/* List.sort returns a sorted list in increasing order according to the specified
      comparison function. The comparison function should return a negative number to
      indicate the first element is smaller, 0 to indicate they are equal, and a positive
      number to indicate the first element is larger.

      val sort: compare:('a -> 'a -> int) -> 'a list -> 'a list
   */
let () =
  assert (
    [%compare.equal: list(int)](
      List.sort(~cmp=(x, y) => x - y, [3, 1, 2]),
      [1, 2, 3],
    )
  );

/*module My_list : sig
    val map : ('a -> 'b) -> 'a list -> 'b list

    val iter : ('a -> unit) -> 'a list -> unit

    val filter : ('a -> bool) -> 'a list -> 'a list
  end = My_list*/
let%test "Testing My_list.map..." =
  [%compare.equal: list(int)](
    [2, 4, 6, 8],
    My_list.map(x => 2 * x, [1, 2, 3, 4]),
  );

let%test "Testing My_list.iter..." = {
  let acc = ref(0);
  My_list.iter(
    x =>
      if (x > acc^) {
        acc := x;
      },
    [1, 8, 5, 2, 7, 3],
  );
  Int.(==)(8, acc^);
};

let%test "Testing My_list.filter..." =
  [%compare.equal: list(int)](
    [8, 2],
    My_list.filter(x => x % 2 == 0, [1, 3, 7, 8, 9, 2]),
  );
