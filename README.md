# Introduction

Reason is a language that looks and reads like Javascript, writes like Javascript, and even interops nicely with Javascript. But it is in fact a new syntax for OCaml, a powerful statically typed functional programming language. 

The syntax makes ReasonML easy to start playing with, but unless you already know a typed functional language, you will soon run into stumbling blocks because of unfamiliarity with static types and functional programming. 

Fear not! Work through these exercises and learn all the basics - defining and using functions, understanding recursion, lists, list operations, variants, and all the way till mutable variables. They will give you a great foundation to start mastering this beautiful language.

# Credits

These exercises are originally from [a workshop organized by Jane Street](https://blog.janestreet.com/learn-ocaml-nyc/) for teaching `OCaml` to programmers who work in other languages and who do not necessarily have experience with functional languages. [Link to the original repo](https://github.com/janestreet/learn-ocaml-workshop). We adapted the tutorials and exercise code to the Reason syntax and toolchain.

# Setting Up

1. Install [reason-cli](https://reasonml.github.io/docs/en/installation) globally. 

2. Setup your editor. We recommend `VSCode` along with the [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml) extension. If you prefer a different editor check the instructions for [other supported editors](https://reasonml.github.io/docs/en/editor-plugins.html)

3. Clone this repository, and run `npm install`.

# Workflow

The exercises are numerically ordered and can be found in the `src/exercises` directory. 

Start by opening the first exercise in a text editor - `src/exercises/01-introduction/introduction.re`. It will tell you where to go from there. 

All exercises except the first one comes with a test. Run them as you complete each exercise. For example for the second exercise, run its test with:

  ```
  node src/exercises/02-basic_types/basicTypes.bs.js
  ```

This `.bs.js` file is your Reason program (`.re`) compiled to Javascript. `.bs` stands for the [bucklescript compiler](https://bucklescript.github.io/). The `.bs.js` code is readable Javascript - give them a look if you're curious!

You can also run `./run_tests` which will run all the tests automatically for you and stop at the first failing one.

# Support

Please feel free to raise an issue if you have any questions as you work through the exercises. You can also find help in the [Reason Discord channel](https://discord.gg/reasonml), or in the [Reason Discourse forum](https://reasonml.chat/).

