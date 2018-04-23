/* This function finds the largest element in a list: */
let rec largest = xs =>
  switch (xs) {
  | [] => neg_infinity
  | [x, ...rest] => max(x, largest(rest))
  };

/* Let's write a function to find the smallest element: Hint: the opposite of
   [min_int] is [max_int]. */
let rec smallest = xs => failwith("For you to implement");

Test.runAll([
  (smallest([]) == infinity, "smallest"),
  (smallest([55.]) == 55., "smallest"),
  (smallest([5., (-5.), 1., (-1.)]) == (-5.), "smallest"),
  (smallest([5., 5., 1., 1.]) == 1., "smallest"),
]);