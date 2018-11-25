/* This function finds the largest element in a list: */
let rec largest = xs =>
  switch (xs) {
  | [] => neg_infinity
  | [x, ...rest] => max(x, largest(rest))
  };

/* Let's write a function to find the smallest element: Hint: the opposite of
   [neg_infinity] is [infinity]. */
let rec smallest = xs => failwith("For you to implement");

Jest.(
  Expect.(
    describe("List min", () => {
      test("smallest", () =>
        expect(smallest([])) |> toBe(infinity)
      );
      test("smallest", () =>
        expect(smallest([55.])) |> toBe(55.)
      );
      test("smallest", () =>
        expect(smallest([5., (-5.), 1., (-1.)])) |> toBe(-5.)
      );
      test("smallest", () =>
        expect(smallest([5., 5., 1., 1.])) |> toBe(1.)
      );
    })
  )
);