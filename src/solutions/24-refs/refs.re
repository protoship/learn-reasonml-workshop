/*
  It is sometimes useful to create a single mutable value. We can do this
  using a ref. We can create an int ref containing 0 as follows:
 */
let x = ref(0);

/*
  Then we can access the value in the ref using the ^ operator, and
  we can update it using the := operator. So, we could increment our
  ref as follows:
 */
let () = x := x^ + 1;

let rec every = (answer, combine, xs) =>
  switch (xs) {
  | [] => answer
  | [x, ...xs] => combine(x, every(answer, combine, xs))
  };

/*
  Write a function minAndMax which returns a tuple containing the minimum
  and maximum values in a non-empty list of positive integers.

  Your function should iterate over the list and maintain refs of the minimum
  and maximum values seen so far.

  Hint: [max_int] or [min_int].
 */
let minAndMax = lst => {
  (every(max_int, min, lst),  every(min_int, max, lst));
};

Test.runAll([
  (minAndMax([5, 9, 2, 4, 3]) == (2, 9), "min and max"),
  (minAndMax([11, 15, 7, 34]) == (7, 34), "min and max"),
]);