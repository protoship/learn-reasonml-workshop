# Introduction

Reason is a language that looks and reads like Javascript, writes like Javascript, and even interops nicely with Javascript. But it is in fact a new syntax for OCaml, a powerful statically typed functional programming language. 

The syntax makes ReasonML easy to start playing with, but unless you already know a typed functional language, you will soon run into stumbling blocks because of unfamiliarity with static types and functional programming. 

Fear not! Work through these exercises and learn all the basics - defining and using functions, understanding recursion, lists, list operations, variants, and all the way till mutable variables. They will give you a great foundation to start mastering this beautiful language.

# Credits

These exercises are originally from [a workshop organized by Jane Street](https://blog.janestreet.com/learn-ocaml-nyc/) for teaching `OCaml` to programmers who work in other languages and who do not necessarily have experience with functional languages. [Link to the original repo](https://github.com/janestreet/learn-ocaml-workshop). We adapted the tutorials and exercise code to the Reason syntax and toolchain.

# Setting Up

1. Setup your editor. We recommend `VSCode` along with the [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml) extension. If you prefer a different editor check the instructions for [other supported editors](https://reasonml.github.io/docs/en/editor-plugins.html)

2. Clone the repository and open the project

3. Run `npm install`

# Workflow

The exercises are numerically ordered and can be found in the `src/exercises` directory. 

It is recommended to have two shells open. 

Run `npm run start` in the first shell. It will re-compile the project on every save. This is usefull to catch compilation errors. 

Run `npm run test:watch` in the second shell. It will use Jest to run all the tests. Note that tests run only when the compilation is successfull. If not - we are covered by the first shell.

Tip: when Jest is running, pres `p` and enter a fragment of a filename you are working on. It will run only the tests from the matching file. 
