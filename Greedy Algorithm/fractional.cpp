#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent items
struct Item {
    int weight;
    int value;
    double valuePerWeight;

    Item(int weight, int value) : weight(weight), value(value) {
        valuePerWeight = (double)value / (double)weight;
    }
};

// Comparison function for sorting items based on value per weight in non-increasing order
bool compareItems(const Item& item1, const Item& item2) {
    return item1.valuePerWeight > item2.valuePerWeight;
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(int capacity, const vector<Item>& items) {
    double totalValue = 0.0;
    int remainingCapacity = capacity;

    // Sort items based on value per weight in non-increasing order
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end(), compareItems);

    // Loop through each item
    for (const Item& item : sortedItems) {
        // If the item can be taken completely, take it and update remaining capacity and total value
        if (item.weight <= remainingCapacity) {
            totalValue += item.value;
            remainingCapacity -= item.weight;
        } else { // If the item cannot be taken completely, take a fractional part
            totalValue += (double)item.valuePerWeight * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    // Input the number of items
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    // Input each item's weight and value
    vector<Item> items;
    for (int i = 0; i < numItems; ++i) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        items.emplace_back(weight, value);
    }

    // Input the capacity of the knapsack
    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value obtained: " << maxValue << endl;

    return 0;
}
