/*
  Reason allows you to define record types. These are like structs in C.
  Or in Python, Ruby & Java, these are similar to data members or static
  variables of a class.
 */
/* Here is a [person] record type that contains four fields. */
/* The first field, called "age" is of type int.  */
type person = {
  /* The name of the type is [person] */
  age: int,
  firstName: string,
  lastName: string,
  numberOfCars: int,
};

/*
  We can create a [person] like this. When defining and matching on a record,
  the fields can be listed in any order.
 */
let anExample: person = {
  firstName: "Cotton-eyed",
  lastName: "Joe",
  age: 22,
  numberOfCars: 0,
};

/*
  In order to get a field out of a record we use the "." operator:
  variable.field
 */
let age: int = anExample.age;

let () = assert (age == 22);

/* We can also match on records to get field information. */
let print_info = ({firstName, lastName, age, numberOfCars}) => {
  print_endline(firstName);
  print_endline(lastName);
  print_endline("Age: " ++ string_of_int(age));
  print_endline("# of cars: " ++ string_of_int(numberOfCars));
};

/* If we don't care about an argument we can ignore it using "= _" */
let print_name = ({firstName, lastName, age: _, numberOfCars: _}) => {
  print_endline(firstName);
  print_endline(lastName);
};

/*
  Finally, we can perform "functional updates" by replacing the value of a
  field, yielding a brand new record. We use the ... spread operator to do
  this. The original record isn't mutated.

  let addOneToAge : person -> person
 */
let addOneToAge = person => {...person, age: person.age + 1};

let () = assert (23 == addOneToAge(anExample).age);

/*
  Write a function that does different things for different people:
  When the person's first name is "Jan", you should return a record with
  the age set to 30.

  Otherwise, you should increase the number of cars by 6.

  let modify_person : person -> person
 */
let modifyPerson = (person: person) => failwith("For you to implement");

module ForTesting = {
  let test_ex1: person = {
    firstName: "Jan",
    lastName: "Saffer",
    age: 55,
    numberOfCars: 0,
  };
  let test_ex1': person = {...test_ex1, age: 30};
  let test_ex2: person = {
    firstName: "Hugo",
    lastName: "Heuzard",
    age: 4,
    numberOfCars: 55,
  };
  let test_ex2': person = {...test_ex2, numberOfCars: 61};
};

Test.runAll([
  (
    modifyPerson(ForTesting.test_ex1) == ForTesting.test_ex1',
    "modifyPerson",
  ),
  (
    modifyPerson(ForTesting.test_ex2) == ForTesting.test_ex2',
    "modifyPerson",
  ),
]);