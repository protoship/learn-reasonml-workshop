# Introduction

These exercises are originally from a [workshop organized by Jane Street](https://blog.janestreet.com/learn-ocaml-nyc/) for teaching `OCaml` to programmers who work in other languages and who do not necessarily have experience with functional languages. [Link to original](https://github.com/janestreet/learn-ocaml-workshop).

We updated the exercises to be useful for someone interested in learning Reason.

# Setting Up

1. Install [reason-cli](https://reasonml.github.io/docs/en/global-installation.html) globally

2. The recommended editor is `VSCode` with the [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml) extension. If you prefer a different editor check the instructions for [other supported editors](https://reasonml.github.io/docs/en/editor-plugins.html)

3. Add [Reason Tools](https://github.com/reasonml/reason-tools) to the browser. It tries to detect OCaml documentation pages and automatically convert between Reason and OCaml syntaxes.

# Workflow

The exercises directory contains 24 exercises to get you started with Reason.
```
cd src/exercises/$problem_dir
```

The `Reason` code is compiled to `Javascript` by the bucklescript compiler. You should run the tests after each exercise to verify your implementation. The compiled javascript has the `.bs.js` extension. To run the tests,
```
node src/exercises/$problem_dir/<name>.bs.js
```