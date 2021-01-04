/*
  Hello,

  Reason is not a new language. It is syntactic sugar for the OCaml language
  created in 1996. The new Reason syntax will look familiar to those who have
  programmed in Javascript.

  These challenges are originally from the workshop run by Jane Street to
  teach OCaml. It was ported over to Reason with the help of `refmt` (Reason
  format) binary that helps you convert to/from Reason/OCaml syntax.

  This exercise is to familiarize you with the code-compile cycle.

  To compile your code, run in a terminal session in the root directory

    $ npm run build

  You should see a compilation error because it's missing the end quote. Add
  the end quote and re-run. You should see that the code compiled successfully!

  For convenience you can build whenever you change the code by running the
  compiler in watch mode. For that, run

    $ npm run start

  You can also execute code in Reason's REPL (rtop) directly. To start rtop from
  your terminal run:

    $ rtop

  Now try pasting the code below into it.

  *Note:* Use `Ctrl-d` to exit the rtop session.

  Try these out and move on to the next exercise!
 */
let () = print_endline("Hello, World!");