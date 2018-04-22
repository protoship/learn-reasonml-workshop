/*
  This is an rei, a file that declares the interface that the corresponding
  implementation file (basicTypes.re) exposes to other code.

  The compiler will enforce that the implementations you write for
  [int_average] and [float_average] in basicTypes.ml have the type signatures
  written below.

 */
let intAverage: (int, int) => int;

let floatAverage: (float, float) => float;