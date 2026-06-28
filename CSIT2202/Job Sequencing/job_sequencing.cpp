#include<bits/stdc++.h> // Includes standard C++ headers.
using namespace std; // Uses the standard namespace.

struct Job { // Defines a job record.
    char jobID; // Job identifier.
    int deadline; // Job deadline.
    int profit; // Job profit.

    Job(char id, int d, int p) { // Initializes a job.
        jobID = id; // Sets the ID.
        deadline = d; // Sets the deadline.
        profit = p; // Sets the profit.
    }
}; // Ends Job struct.

// comparator function
bool compare(Job a, Job b) { // Compares two jobs.
    return (a.profit > b.profit); // Higher profit first.
} // Ends compare.

void jobSeq(vector<Job>& jobs) { // Schedules jobs to maximize profit.
    sort(jobs.begin(), jobs.end(), compare); // Sorts by profit.

    int maxDeadline = 0; // Tracks max deadline.

    for (auto& job:jobs) { // Scans each job.
        if (job.deadline > maxDeadline) // Finds the largest deadline.
            maxDeadline = job.deadline; // Updates max deadline.
    }

    vector<char> slots(maxDeadline+1, '-'); // Creates empty slots.

    int maxProfit = 0; // Accumulates total profit.

    for (auto& job:jobs) { // Tries to schedule each job.
        for (int i=job.deadline; i>0; i--) { // Looks backward for a slot.
            if (slots[i] == '-') { // Checks if slot is free.
                slots[i] = job.jobID; // Assigns job to slot.
                maxProfit += job.profit; // Adds profit.
                break; // Stops after scheduling.
            }
        }
    }

    cout << "Slots: "; // Prints slot label.
    for (char& c:slots) { // Iterates over slots.
        if (c != '-') cout << c << " "; // Prints filled slots.
    }
    cout << endl; // Ends line.

    cout << "Max profit = " << maxProfit << endl; // Prints total profit.
} // Ends jobSeq.

int main() { // Program entry point.
    int n = 0; // Number of jobs.
    cout << "How many jobs ? : "; // Prompts for count.
    cin >> n; // Reads count.

    vector<Job> jobs; // Stores jobs.
    jobs.reserve(n); // Reserves capacity.

    for (int idx = 0; idx < n; idx++) { // Reads each job.
        char jobID = '\0'; // Initializes ID.
        int deadline = 0; // Initializes deadline.
        int profit = 0; // Initializes profit.

        cout << "Enter job " << (idx + 1) << " ID (single character): "; // Prompts for ID.
        cin >> jobID; // Reads ID.
        cout << "Enter job " << (idx + 1) << " deadline: "; // Prompts for deadline.
        cin >> deadline; // Reads deadline.
        cout << "Enter job " << (idx + 1) << " profit: "; // Prompts for profit.
        cin >> profit; // Reads profit.

        jobs.emplace_back(jobID, deadline, profit); // Adds job to list.
    }

    jobSeq(jobs); // Runs scheduling.

    return 0; // Exits program.
} // Ends main.
