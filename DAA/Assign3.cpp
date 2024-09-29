#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
    double ratio;
};

//sort items by value-to-weight ratio
bool compare(Item a, Item b) {
    return a.ratio > b.ratio; // descending order
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    
    for (auto& item : items) {
        item.ratio = static_cast<double>(item.value) / item.weight;
    }
    
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    
    for (const auto& item : items) {
        if (capacity == 0) {
            break; // Knapsack is full
        }

        // If the item can be completely fit into the knapsack
        if (item.weight <= capacity) {
            totalValue += item.value;
            capacity -= item.weight;
        } else {
            // Take the fraction of the remaining capacity
            totalValue += item.ratio * capacity;
            capacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    int n; 
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight for each item (value weight):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}

/*
OUTPUT: 

Enter the number of items: 3
Enter value and weight for each item (value weight):
60 10
100 20
120 30
Enter the capacity of the knapsack: 50
Maximum value in the knapsack = 240
 */