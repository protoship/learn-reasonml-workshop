type t = {
  expr: bool,
  desc: string,
};

let create = ((expr, desc)) => {expr, desc};

let test = t => t.expr;

let runAll = xs => {
  let toString = t =>
    "Testing " ++ t.desc ++ "... " ++ string_of_bool(t.expr);
  let count = List.length(xs);
  let tests = List.map(create, xs);
  let successCount =
    tests |> List.map(test) |> List.filter(y => y) |> List.length;
  let descriptions = List.map(toString, tests);
  print_endline("");
  print_endline("==============Begin Test==============");
  print_endline("");
  List.iteri(
    (i, x) => print_endline(string_of_int(i + 1) ++ ". " ++ x),
    descriptions,
  );
  print_endline("");
  if (count == successCount) {
    print_endline("All tests passed!");
  } else {
    print_endline(
      string_of_int(successCount)
      ++ " out of "
      ++ string_of_int(count)
      ++ " tests passed.",
    );
  };
  print_endline("");
  print_endline("===============End Test===============");
  print_endline("");
};