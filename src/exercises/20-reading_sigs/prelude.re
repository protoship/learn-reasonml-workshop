module AList = {
  type t = list(int);
  let of_list = x => x;
  let empty = [];
  let filter = (f, x) => List.filter(f, x);
  let numbers_from_0_to_50 = {
    let rec compute = (x, acc) =>
      if (x == 0) {
        [0, ...acc];
      } else {
        compute(x - 1, [x, ...acc]);
      };
    compute(50, []);
  };
};

let numbers_from_0_to_50 = {
  let rec compute = (x, acc) =>
    if (x == 0) {
      [0, ...acc];
    } else {
      compute(x - 1, [x, ...acc]);
    };
  compute(50, []);
};

let evens_from_0_to_50': AList.t =
  List.filter(x => x mod 2 == 0, numbers_from_0_to_50);

let odds_from_0_to_50': AList.t =
  List.filter(x => x mod 2 == 1, numbers_from_0_to_50);

let numbers_from_0_to_10': AList.t =
  List.filter(x => x <= 10, numbers_from_0_to_50);
