/* This is an mli, a file that declares the interface that the corresponding
      implementation file (problem.ml) exposes to other code.

      The compiler will enforce that the implementations you write for
      [int_average] and [float_average] in problem.ml have the type signatures
      written below.
   */
let int_average: (int, int) => int;

let float_average: (float, float) => float;