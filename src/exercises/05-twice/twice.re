/*
  We can easily write a function that adds 1 to any number.
  Recall that the infix operator (+) will add two integers.
 */
let add1 = x => failwith("For you to implement");

/*
  Let's write a function that squares its argument (multiplies it by itself)
 */
let square = x => failwith("For you to implement");

/*
  Functions are first class in Reason. This means that you can take
  a function and pass it around as an argument to other functions.

  Let's write a function named twice: it will take a function and apply
  that function to itself two times.

  For example, if we wanted to make an "add2" function, we could do it
  by writing:
  let add2 = twice(add1)
 */
let twice = (f, x) => failwith("For you to implement");

/* Now that we have twice, write add2 and raiseToTheFourth */
let add2 = x => failwith("For you to implement"); /* Hint: use add1 */

let raiseToTheFourth = x => failwith("For you to implement"); /* Hint: use square */

Jest.(
  Expect.(
    describe("Twice", () => {
      test("add1", () =>
        expect(add1(4)) |> toBe(5)
      );
      test("square", () =>
        expect(square(4)) |> toBe(16)
      );
      test("square", () =>
        expect(square(-4)) |> toBe(16)
      );
      test("twice", () =>
        expect(twice(add1, 3)) |> toBe(5)
      );
      test("add2", () =>
        expect(add2(1335)) |> toBe(1337)
      );
      test("raiseToTheFourth", () =>
        expect(raiseToTheFourth(1)) |> toBe(1)
      );
      test("raiseToTheFourth", () =>
        expect(raiseToTheFourth(10)) |> toBe(10000)
      );
    })
  )
);