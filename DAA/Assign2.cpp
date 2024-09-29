#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int id; 
    int deadline; 
    int profit;   
    
    // Constructor
    Job(int id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

// Comparator function to sort jobs according to profit in descending order
bool comparison(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(vector<Job>& jobs) {
    // Sort jobs according to profit
    sort(jobs.begin(), jobs.end(), comparison);

    int n = jobs.size();
    vector<bool> slot(n, false); 
    vector<int> result(n);       
    int maxProfit = 0;                

    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            // If the slot is free
            if (!slot[j]) {
                slot[j] = true;  //slot as filled
                result[j] = jobs[i].id; // Add this job to the result
                maxProfit += jobs[i].profit; // Add profit
                break;
            }
        }
    }

    //scheduled jobs
    cout << "Scheduled jobs: ";
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << "\nTotal profit: " << maxProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs;

    for (int i = 0; i < n; i++) {
        int id, deadline, profit;
        cout << "Enter job ID, deadline, and profit for job " << (i + 1) << ": ";
        cin >> id >> deadline >> profit;
        jobs.push_back(Job(id, deadline, profit));
    }

    jobSequencing(jobs);
    return 0;
}
