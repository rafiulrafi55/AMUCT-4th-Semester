#include<bits/stdc++.h> // Include standard C++ headers for I/O, containers, algorithms, etc.
using namespace std; // Avoid std:: prefix for readability in this small example.

struct Item { // Group weight and profit into a single item record.
    float weight; // Store item weight as float to support fractional capacity.
    float profit; // Store item profit as float for ratio calculations.

    Item(float w, float p) { // Construct an item from weight and profit inputs.
        weight = w; // Assign provided weight to the item.
        profit = p; // Assign provided profit to the item.
    }
}; // End of Item definition.

// comparator function
bool compare(Item a, Item b) { // Sort items by decreasing profit-to-weight ratio.
    float r1 = a.profit / a.weight; // Compute ratio for item a to prioritize best value.
    float r2 = b.profit / b.weight; // Compute ratio for item b for comparison.

    return (r1 > r2); // Place higher ratio items first.
}

void fracKnap(vector<Item>& items, float capacity) { // Compute maximum profit for fractional knapsack.
    sort(items.begin(), items.end(), compare); // Sort by best value density before selecting.

    float maxProfit = 0.0; // Track total profit accumulated so far.

    for (auto& i:items) { // Traverse items in sorted order.
        if (i.weight <= capacity) { // If full item fits, take all of it.
            capacity = capacity - i.weight; // Reduce remaining capacity by item weight.
            maxProfit += i.profit; // Add full profit of the item.
        }
        else { // Otherwise, take only the fraction that fits.
            maxProfit += i.profit * (capacity / i.weight); // Add proportional profit for remaining capacity.
            break; // Knapsack is full, stop selecting items.
        }
    }

    cout << "Max profit = " << maxProfit << endl; // Output the computed maximum profit.
}

int main() { // Program entry point.
    int n = 0; // Store number of items to read.
    cout << "How many items ? : "; // Prompt user for item count.
    cin >> n; // Read item count from standard input.

    vector<Item> items; // Dynamic container for user-provided items.
    items.reserve(n); // Reserve space to avoid reallocations during input.

    for (int idx = 0; idx < n; idx++) { // Read each item's weight and profit.
        float weight = 0.0f; // Temporary storage for item weight.
        float profit = 0.0f; // Temporary storage for item profit.

        cout << "Enter item " << (idx + 1) << " weight: "; // Prompt for weight.
        cin >> weight; // Read weight value.
        cout << "Enter item " << (idx + 1) << " profit: "; // Prompt for profit.
        cin >> profit; // Read profit value.

        items.emplace_back(weight, profit); // Add the item to the list.
    }

    float capacity = 0.0f; // Store knapsack capacity.
    cout << "Enter knapsack capacity: "; // Prompt for capacity.
    cin >> capacity; // Read capacity from input.

    fracKnap(items, capacity); // Compute and print the maximum profit.

    return 0; // Indicate successful program termination.
}
