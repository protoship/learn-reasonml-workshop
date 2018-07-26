/*
  Sometimes rather than redefining the record you would like to have a field or
  a set of fields that you can modify on the fly.

  In Reason if you want to have a field in a record that can be updated in place,
  you must use some additional syntax. The mutable keyword makes the field
  modifiable.

  Then you can update those fields in place with the = operator.
 */
type color =
  | Red
  | Yellow
  | Green;

type stoplight = {
  location: string, /* stoplights don't usually move */
  mutable color /* but they often change color */
};

/* On creation mutable fields are defined just like normal fields */
let anExample: stoplight = {
  location: "The corner of Vesey Street and the West Side highway",
  color: Red,
};

/*
  Now rather than using a functional update we can use a mutable update.
  This doesn't return a new stoplight, it modifies the input stoplight.
 */
let setColor = (stoplight, color) => stoplight.color = color;

/*
  Since we know that stoplights always go from Green to Yellow, Yellow to
  Red, and Red to Green, we can just write a function to advance the color
  of the light without taking an input color.
 */
let advanceColor = stoplight => failwith("For you to implement");

module ForTesting = {
  let test_ex_red: stoplight = {location: "", color: Red};
  let test_ex_red': stoplight = {...test_ex_red, color: Green};
  let test_ex_yellow: stoplight = {location: "", color: Yellow};
  let test_ex_yellow': stoplight = {...test_ex_red, color: Red};
  let test_ex_green: stoplight = {location: "", color: Green};
  let test_ex_green': stoplight = {...test_ex_red, color: Yellow};
};

advanceColor(ForTesting.test_ex_red);

advanceColor(ForTesting.test_ex_yellow);

advanceColor(ForTesting.test_ex_green);

Test.runAll([
  (ForTesting.test_ex_red == ForTesting.test_ex_red', "advance color"),
  (ForTesting.test_ex_yellow == ForTesting.test_ex_yellow', "advance color"),
  (ForTesting.test_ex_green == ForTesting.test_ex_green', "advance color"),
]);