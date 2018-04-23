/*
  The append infix operator @ concatenates two lists:

  let (@) : 'a list -> 'a list -> 'a list

  This function is the same as the List.append function.
 */
let () = {
  assert ([5, 1] @ [8, 4] == [5, 1, 8, 4]);
  assert (List.append([5, 1], [8, 4]) == [5, 1, 8, 4]);
};

/*
  TODO: Write a function to construct a list of all integers in the range [from,to_]
  in increasing order.

  let range : int -> int -> int list
 */
let range = (from, to_) => failwith("For you to implement");

Test.runAll([
  (range(1, 4) == [1, 2, 3], "range"),
  (range(-5, 3) == [(-5), (-4), (-3), (-2), (-1), 0, 1, 2], "range"),
]);