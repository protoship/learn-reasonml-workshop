let plus = (x, y) => x + y;

let times = (x, y) => x * y;

/* Sometimes, multiple functions look similar: */
let rec addEveryNumberUpTo = x =>
  switch (x) {
  | 0 => 0
  | _ => plus(x, addEveryNumberUpTo(x - 1))
  };

let rec factorial = x =>
  switch (x) {
  | 0 => 1
  | _ => times(x, factorial(x - 1))
  };

/*
  These functions have a lot in common:

  let rec NAME x =
    switch (x) {
    | 0 => ANSWER
    | _ => COMBINE(x, NAME(x-1))
    }

  Reason lets us write the common parts just once.
  We just add an extra input for every part that changes (other than the name):
 */
let rec upTo = (answer, combine, x) =>
  switch (x) {
  | 0 => answer
  | _ => combine(x, upTo(answer, combine, x - 1))
  };

/* Now we can write our original functions in one line each! */
let simplerAddEveryNumberUpTo = x => upTo(0, plus, x);

let simplerFactorial = x => upTo(1, times, x);

/*
  Note that with infix operators like + and *, you can actually pass them as
  functions! You can do this by writing ( + ) and ( * ). So another way to
  write the above two functions would be:

  let simplerAddEveryNumberUpTo = x => upTo(0, ( + ), x);
  let simplerFactorial = x => upTo(1, ( * ), x);

  Remember sum and product?
 */
let rec sum = xs =>
  switch (xs) {
  | [] => 0
  | [x, ...rest] => plus(x, sum(rest))
  };

let rec product = xs =>
  switch (xs) {
  | [] => 1
  | [x, ...rest] => times(x, product(rest))
  };

/*
 These functions look pretty similar too:

 let rec NAME xs =
  switch (xs) {
  | [] => ANSWER
  | [x, ...rest] => COMBINE(x, NAME(rest))
  }

 Let's write the common parts just once:
 */
let rec every = (answer, combine, xs) => failwith("For you to implement");

/* Now let's rewrite sum and product in just one line each using every */
let simplerSum = xs => failwith("For you to implement");

let simplerProduct = xs => failwith("For you to implement");

Jest.(
  Expect.(
    describe("Sum & product", () => {
      test("simpler product", () =>
        expect(simplerProduct([])) |> toBe(1)
      );
      test("simpler product", () =>
        expect(simplerProduct([55])) |> toBe(55)
      );
      test("simpler product", () =>
        expect(simplerProduct([5, (-5), 1, (-1)])) |> toBe(25)
      );
      test("simpler product", () =>
        expect(simplerProduct([5, 5, 1, 1])) |> toBe(25)
      );
      test("simpler sum", () =>
        expect(simplerSum([])) |> toBe(0)
      );
      test("simpler sum", () =>
        expect(simplerSum([55])) |> toBe(55)
      );
      test("simpler sum", () =>
        expect(simplerSum([5, (-5), 1, (-1)])) |> toBe(0)
      );
      test("simpler sum", () =>
        expect(simplerSum([5, 5, 1, 1])) |> toBe(12)
      );
    })
  )
);