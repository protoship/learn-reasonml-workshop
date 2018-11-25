/*
  We use let to define functions.

  Definitions take on the form:
  let functionName = (arg1, arg2) => body;

  For example, here we define a function add1 that takes a single int
  argument and returns that argument plus 1.
 */
let add1 = arg => arg + 1;

/* This function uses the built-in ++ operator to append strings. */
let stringAppend = (x, y) => x ++ y;

/* Let's define our own functions using +, -, *, and / below. */
let plus = (x, y) => failwith("For you to implement");

let times = (x, y) => failwith("For you to implement");

let minus = (x, y) => failwith("For you to implement");

let divide = (x, y) => failwith("For you to implement");

Jest.(
  Expect.(
    describe("Define functions", () => {
      test("plus", () =>
        expect(plus(1, 1)) |> toBe(2)
      );
      test("plus", () =>
        expect(plus(50, -1)) |> toBe(49)
      );
      test("times", () =>
        expect(times(8, 8)) |> toBe(64)
      );
      test("times", () =>
        expect(times(2, -1024)) |> toBe(-2048)
      );
      test("minus", () =>
        expect(minus(-2, 2)) |> toBe(-4)
      );
      test("minus", () =>
        expect(minus(1337, 337)) |> toBe(1000)
      );
      test("divide", () =>
        expect(divide(1024, 2)) |> toBe(512)
      );
      test("divide", () =>
        expect(divide(31337, 31)) |> toBe(1010)
      );
    })
  )
);