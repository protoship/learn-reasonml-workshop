/*
  The append infix operator @ concatenates two lists:

  let (@) : (list('a), list('a)) => list('a)

  This function is the same as the List.append function.
 */
let () = {
  assert([5, 1] @ [8, 4] == [5, 1, 8, 4]);
  assert(List.append([5, 1], [8, 4]) == [5, 1, 8, 4]);
};

/*
  Write a function to construct a list of all integers in the range [from,to_]
  in increasing order.

  let range: (int, int) => list(int)
 */
let range = (from, to_) => failwith("For you to implement");

Jest.(
  Expect.(
    describe("List range", () => {
      test("range", () =>
        expect(range(1, 4)) |> toBe([1, 2, 3])
      );
      test("range", () =>
        expect(range(-5, 3))
        |> toBe([(-5), (-4), (-3), (-2), (-1), 0, 1, 2])
      );
    })
  )
);