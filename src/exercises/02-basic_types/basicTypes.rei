/*
  This is an rei, a file that declares the interface that the corresponding
  implementation file (basicTypes.re) exposes to other code.

  The compiler will enforce that the implementations you write for
  [intAverage] and [floatAverage] in basicTypes.re have the type signatures
  written below.

 */
let intAverage: (int, int) => int;

let floatAverage: (float, float) => float;