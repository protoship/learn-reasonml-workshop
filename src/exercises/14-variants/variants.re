/*
  As in most languages, you can define your own types.
  The keyword "type" introduces a type definition.

  One of the non-basic types in Reason is called the variant type.
  Variant types are similar to Enums in other languages. They are
  types which may take on multiple forms, where each form is marked
  by an explicit tag. A variant type is defined as follows:
 */
type color =
  | Red
  | Green
  | Blue;

/* Variants are very useful in combination with pattern matching */
let toString = color =>
  switch (color) {
  | Red => "red"
  | Green => "green"
  | Blue => "blue"
  };

/*
  Reason variants are in many ways more powerful than Enums because the different
  constructors of your variant can include data in them. Here's an example:
 */
type cardValue =
  | Ace
  | King
  | Queen
  | Jack
  | Number(int);

let oneCardValue: cardValue = Queen;

let anotherCardValue: cardValue = Number(8);

let cardValueToString = cardValue =>
  switch (cardValue) {
  | Ace => "Ace"
  | King => "King"
  | Queen => "Queen"
  | Jack => "Jack"
  | Number(i) => string_of_int(i)
  };

/*
  Write a function that computes the score of a card (aces should score 11
  and face cards should score 10).
 */
let cardValueToScore = cardValue => failwith("For you to implement");

Jest.(
  Expect.(
    describe("Variants", () => {
      test("card value to score", () =>
        expect(cardValueToScore(Ace)) |> toBe(11)
      );
      test("card value to score", () =>
        expect(cardValueToScore(King)) |> toBe(10)
      );
      test("card value to score", () =>
        expect(cardValueToScore(Queen)) |> toBe(10)
      );
      test("card value to score", () =>
        expect(cardValueToScore(Jack)) |> toBe(10)
      );
      test("card value to score", () =>
        expect(cardValueToScore(Number(5))) |> toBe(5)
      );
    })
  )
);