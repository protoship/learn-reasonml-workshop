/*
  Reason natively supports linked lists as part of the language.
  Lists are commonly referred to as having heads and tails.
  The head is the first element of the linked list
  The tail is everything else.

  [] means "the empty list".
  [hd, ...tl] means "the element hd added to the front of the list tl".

  When matching on a list, it's either empty or non-empty. To say it another
  way, it's either equal to [] or equal to ([hd, ...tl]) where hd is the first
  element of the list and tl is all the rest of the elements of the list
  (which may itself be empty).

  This function computes the length of a list.
 */
let rec length = lst =>
  switch (lst) {
  | [] => 0
  | [_, ...tl] => 1 + length(tl)
  };

/* Write a function to add up the elements of a list by matching on it. */
let rec sum = lst => failwith("For you to implement");

/*
  The signature for the append operator is
  let (@) : (list('a), list('a)) => list('a)

  It's an infix operator.
 */
let listAppend = (first, second) => first @ second;

/*
  The way you put something on the head to the list uses the same kind of
  syntax for matching on lists. This is called the spread syntax.
 */
let newHead = (hd, rest) => [hd, ...rest];

Test.runAll([
  (sum([]) == 0, "sum"),
  (sum([55]) == 55, "sum"),
  (sum([5, (-5), 1, (-1)]) == 0, "sum"),
  (sum([5, 5, 1, 1]) == 12, "sum"),
]);