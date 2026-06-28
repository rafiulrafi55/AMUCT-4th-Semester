//"use strict";
//myFunction(); //hoisted 

//function myFunction(){
  //carName = "Volvo";}

//console.log(carName); //now it works, because carName is a global variable.

//const dateInfo = new Date();
//console.log(dateInfo.toDateString());

const user = [
  { name: "John", age: 30 , hobbies: ["reading", "traveling"], phone : ["123-456-7890", "987-654-3210"]},
  { name: "Jane", age: 25 , hobbies: ["cooking", "painting"], phone : ["555-123-4567", "555-987-6543"]},
  { name: "Doe", age: 40 ,hobbies: ["gaming"], phone : ["555-555-5555"]}
];

// for (const user of User) {
//   console.log(user.phone[1]);
// }

// const size = User.length;
// console.log(size);

// const newUsers = user.toString();
// console.log(newUsers);

user.push({ name : "Rafi", age : 22, hobbies : ["coding", "music"], phone : ["111-222-3333"]});

// console.log(user);

const deletedUser = user.pop();
console.log(deletedUser);