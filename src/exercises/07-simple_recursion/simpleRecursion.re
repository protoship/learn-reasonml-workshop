/*
  Remember that functions can call functions?
  They can call themselves too. But only with a special keyword.

  Try changing "let rec" to "let" and you'll see the following compiler error:
  "The value addEveryNumberUpTo can't be found"
 */
let rec addEveryNumberUpTo = x => {
  /* make sure we don't call this on negative numbers! */
  assert(x >= 0);
  switch (x) {
  | 0 => 0
  | _ => x + addEveryNumberUpTo(x - 1)
  };
};

/*
  Let's write a function to multiply every number up to x.
  Remember: [factorial 0] is 1
 */
let rec factorial = x => {
  assert(x >= 0);
  failwith("For you to implement");
};

Jest.(
  Expect.(
    describe("Simple recursion", () => {
      test("factorial", () =>
        expect(factorial(0)) |> toBe(1)
      );
      test("factorial", () =>
        expect(factorial(5)) |> toBe(120)
      );
      test("factorial", () =>
        expect(factorial(12)) |> toBe(479001600)
      );
    })
  )
);