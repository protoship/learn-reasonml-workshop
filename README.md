# Introduction

These exercises are originally from [a workshop organized by Jane Street](https://blog.janestreet.com/learn-ocaml-nyc/) for teaching `OCaml` to programmers who work in other languages and who do not necessarily have experience with functional languages. [Link to the original repo](https://github.com/janestreet/learn-ocaml-workshop).

We updated the exercises to be useful for someone interested in learning Reason. [Reason](https://reasonml.github.io/) is a new syntax and toolchain powered by OCaml. Reason syntax and NPM/Yarn workflow will seem familiar to Javascript programmers.

# Setting Up

1. Install [reason-cli](https://reasonml.github.io/docs/en/global-installation.html) globally. The bundles are larger than 100MB and `npm` does not show progress while downloading. 

2. The recommended editor is `VSCode` along with the [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml) extension. If you prefer a different editor check the instructions for [other supported editors](https://reasonml.github.io/docs/en/editor-plugins.html)

3. Add the [Reason Tools](https://github.com/reasonml/reason-tools) browser extension. It works as a popup where you can copy code to convert between Reason and OCaml syntaxes. When you visit OCaml library documentation you can switch between viewing Reason/OCaml syntax.

4. Run `npm install`.

# Workflow

The exercises are ordered and can be found within `src/exercises` directory. Start with the first exercise - `src/exercises/01-introduction/introduction.re`.

After completing each exercise, run its test. For example for the second exercise, run the test as:

  ```
  node src/exercises/02-basic_types/basicTypes.bs.js
  ```

This `.bs.js` file is your Reason program `.re` compiled to Javascript. `.bs` stands for the [bucklescript compiler](https://bucklescript.github.io/). You should read the `.bs.js` file for each exercise and compare the Javascript output to the original Reason code. This will help you develop an intuition for the language very quickly.

You can also run `./run_tests` which will run all the tests automatically for you and stop at the first failing one.

