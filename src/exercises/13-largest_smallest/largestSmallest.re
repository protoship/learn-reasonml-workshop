/* Here is [every] from the "Sum Product" problem */
let rec every = (answer, combine, xs) =>
  switch (xs) {
  | [] => answer
  | [x, ...xs] => combine(x, every(answer, combine, xs))
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
let simplerLargest = xs => failwith("For you to implement");

let simplerSmallest = xs => failwith("For you to implement");

Jest.(
  Expect.(
    describe("Largest & smallest", () => {
      test("simpler smallest", () =>
        expect(simplerSmallest([])) |> toBe(infinity)
      );
      test("simpler smallest", () =>
        expect(simplerSmallest([55.])) |> toBe(55.)
      );
      test("simpler smallest", () =>
        expect(simplerSmallest([5., (-5.), 1., (-1.)])) |> toBe(-5.)
      );
      test("simpler smallest", () =>
        expect(simplerSmallest([5., 5., 1., 1.])) |> toBe(1.)
      );
      test("simpler largest", () =>
        expect(simplerLargest([])) |> toBe(neg_infinity)
      );
      test("simpler largest", () =>
        expect(simplerLargest([55.])) |> toBe(55.)
      );
      test("simpler largest", () =>
        expect(simplerLargest([5., (-5.), 1., (-1.)])) |> toBe(5.)
      );
      test("simpler largest", () =>
        expect(simplerLargest([5., 5., 1., 1.])) |> toBe(5.)
      );
    })
  )
);