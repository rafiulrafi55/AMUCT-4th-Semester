const tags = [" javascript ", " html", "CSS ", " ReAcT "];
const cleanTags = tags.map(tag => tag.trim().toLowerCase());
const newTag = cleanTags.filter(tag => tag.length > 3);
console.log(newTag);
//task 3
const inventory = [
	{ name: "Laptop", price: 1200, stock: 5 },
	{ name: "Mouse", price: 25, stock: 0 },
	{ name: "Keyboard", price: 80, stock: 12 },
	{ name: "Monitor", price: 300, stock: 3 }
];

const requiredItem = inventory.find(item => item.price < 50);
console.log(requiredItem);

//task 4
const allInStock = inventory.every(item => item.stock > 0);
console.log(allInStock);


//task 5
const itemNamesString = inventory.map(item => item.name).join(", ");
console.log(itemNamesString);

//task 6
const transactions = [100, -20, 50, -10, 200, -5];
const deposits = transactions.filter(amount => amount > 0);
console.log(deposits);

//task 7
const totalBalance = transactions.reduce((sum, amount) => sum + amount, 0);
console.log(totalBalance);

//task 8
const reversedTransactions = [transactions].reverse();
console.log(reversedTransactions);

//task 9
const users = ["Admin", "Editor", "Subscriber", "Guest"];
users.pop();
console.log(users);

//task 10
const editorIndex = users.indexOf("Editor");
users[editorIndex] = "Senior Editor";
console.log(users);










