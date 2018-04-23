# Introduction

These exercises are originally from a [workshop organized by Jane Street](https://blog.janestreet.com/learn-ocaml-nyc/) for teaching `OCaml` to programmers who work in other languages and who do not necessarily have experience with functional languages. [Link to original](https://github.com/janestreet/learn-ocaml-workshop).

We updated the exercises to be useful for someone interested in learning Reason. [Reason](https://reasonml.github.io/) is a new syntax and toolchain powered by OCaml. Reason syntax and NPM/Yarn workflow will seem familiar to Javascript programmers.

# Setting Up

1. Install [reason-cli](https://reasonml.github.io/docs/en/global-installation.html) globally. The bundles are larger than 100MB and `npm` does not show progress while downloading. 

2. The recommended editor is `VSCode` along with the [vscode-reasonml](https://github.com/reasonml-editor/vscode-reasonml) extension. If you prefer a different editor check the instructions for [other supported editors](https://reasonml.github.io/docs/en/editor-plugins.html)

3. Add [Reason Tools](https://github.com/reasonml/reason-tools) to the browser extension. It works as a popup where you can copy code to convert between Reason and OCaml syntaxes. When you visit OCaml library documentation you can switch between viewing Reason/OCaml syntax.

# Workflow

The exercises are ordered and can be found within `src/exercises` directory.
```
cd src/exercises/nn-problem_dir
```

To build the code use either `npm run build` or `npm run start`. The `Reason` code is compiled to `Javascript` by the [bucklescript compiler](https://bucklescript.github.io/). Most of the exercises have embedded tests to verify the correctness of your implementation. The results of the embedded tests can be viewed by running the compiled javascript which has the `.bs.js` extension.

```
node src/exercises/nn-problem_dir/<name>.bs.js
```