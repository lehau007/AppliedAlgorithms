#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool compare(Job &a, Job &b) {
    if (a.deadline == b.deadline) {
        return a.profit > b.profit;
    }
    return a.deadline < b.deadline;
}

int maxProfit(vector<Job> &jobs, int n) {
    sort(jobs.begin(), jobs.end(), compare);
    
    // Max heap to keep track of selected job profits
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    int totalProfit = 0;
    
    // Iterate over all jobs
    for (const auto &job : jobs) {
        if (minHeap.size() < job.deadline) {
            // If we can schedule this job, add its profit to the total
            minHeap.push(job.profit);
            totalProfit += job.profit;
        } else if (!minHeap.empty() && minHeap.top() < job.profit) {
            // Replace the job with the least profit with the current more profitable one
            totalProfit += job.profit - minHeap.top();
            minHeap.pop();
            minHeap.push(job.profit);
        }
    }
    
    return totalProfit;
}

int main() {
    int n;
    cin >> n;
    
    vector<Job> jobs(n);
    
    // Reading job deadlines and profits
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    
    // Get the maximum total profit
    cout << maxProfit(jobs, n) << endl;
    
    return 0;
}
