module AList = {
  type t = list(int);
  let of_list = x => x;
  let empty = [];
  let filter = (f, x) => List.filter(f, x);
  let numbersFrom0To50 = {
    let rec compute = (x, acc) =>
      if (x == 0) {
        [0, ...acc];
      } else {
        compute(x - 1, [x, ...acc]);
      };
    compute(50, []);
  };
};

let numbersFrom0To50 = {
  let rec compute = (x, acc) =>
    if (x == 0) {
      [0, ...acc];
    } else {
      compute(x - 1, [x, ...acc]);
    };
  compute(50, []);
};

let evensFrom0To50': AList.t =
  List.filter(x => x mod 2 == 0, numbersFrom0To50);

let oddsFrom0To50': AList.t =
  List.filter(x => x mod 2 == 1, numbersFrom0To50);

let numbersFrom0To10': AList.t = List.filter(x => x <= 10, numbersFrom0To50);