/*
  Another non-basic type in Reason is a tuple. A tuple is an ordered collection
  of values that can each be of a different type.
 */
type intStringAndChar = (int, string, char);

/* Tuples are created by supplying values in place of their basic types: */
let example: intStringAndChar = (5, "hello", 'A');

/* You can also extract the components of a tuple: */
let (i, s, c) = example;

let () = {
  assert (i == 5);
  assert (s == "hello");
  assert (c == 'A');
};

/*
  Consider a coordinate type containing the x and y values of a coordinate.
  Write a function that computes the sum of two coordinates.
 */
type coordinate = (int, int);

/* TODO */
let add = (coord1, coord2) => failwith("For you to implement");

/* Now consider a name type containing strings representing first and last name. */
type name = (string, string);

/* Or an initials type containing chars representing first and last initials */
type initials = (char, char);

/*
  Say we want to write a function that extracts the first element from a coordinate,
  name, or initials. We currently can't write that because they all have different
  types.

  Lets define a new pair type which is parameterized over the type contained in
  the pair. We write this as:
 */
type pair('a) = ('a, 'a);

/*
  Our types defined above could be rewritten as

    type coordinate = pair(int)
    type name       = pair(string)
    type initials   = pair(char)

  We can construct pairs just like we construct regular tuples
 */
let intPair: pair(int) = (5, 7);

let stringPair: pair(string) = ("foo", "bar");

let nestedCharPair: pair(pair(char)) = (('a', 'b'), ('c', 'd'));

/* Write functions to extract the first and second elements from a pair. */
/* let first: pair('a) => 'a */
/* TODO */
let first = pair => failwith("For you to implement");

/* let second: pair('a) => 'a */
/* TODO */
let second = pair => failwith("For you to implement");

Test.runAll([
  (add((1, 2), (3, 4)) == (4, 6), "add"),
  (first(("foo", "bar")) == "foo", "first"),
  (second(('a', 'b')) == 'b', "second"),
]);