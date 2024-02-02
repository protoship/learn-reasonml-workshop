/* Here is [every] from the "Sum Product" problem */
let rec every = (answer, combine, xs) =>
  switch (xs) {
  | [] => answer
  | [x, ...xs] => combine(every(answer, combine, xs))
  };

/*
  Here are two functions which compute the largest and smallest integers in a
  list of integers:
 */
let rec largest = xs =>
  switch (xs) {
  | [] => neg_infinity
  | [x, ...ys] => max(x, largest(ys))
  };

let rec smallest = xs =>
  switch (xs) {
  | [] => infinity
  | [x, ...ys] => min(x, smallest(ys))
  };

/* Let's rewrite them using every: */

let largest = xs => every(neg_infinity, largest, xs);

let smallest = xs => every(infinity, smallest, xs);

Test.runAll([
  (simplerSmallest([]) == infinity, "simpler smallest"),
  (simplerSmallest([55.]) == 55., "simpler smallest"),
  (simplerSmallest([5., (-5.), 1., (-1.)]) == (-5.), "simpler smallest"),
  (simplerSmallest([5., 5., 1., 1.]) == 1., "simpler smallest"),
  (simplerLargest([]) == neg_infinity, "simpler largest"),
  (simplerLargest([55.]) == 55., "simpler largest"),
  (simplerLargest([5., (-5.), 1., (-1.)]) == 5., "simpler largest"),
  (simplerLargest([5., 5., 1., 1.]) == 5., "simpler largest"),
]);