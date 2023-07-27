#include <iostream>
#include <vector>
#include <queue>

int timeToBuyTickets(std::vector<int>& tickets, int k) {
    int n = tickets.size();
    std::queue<std::pair<int, int>> q; // Queue to represent the line of people
    int time = 0;

    // Push people with their ticket count and position into the queue
    for (int i = 0; i < n; ++i) {
        q.push({tickets[i], i});
    }

    while (!q.empty()) {
        auto frontPerson = q.front();
        q.pop();

        int ticketsToBuy = frontPerson.first;
        int position = frontPerson.second;

        int ticketsBought = std::min(ticketsToBuy, tickets[position]);

        time += ticketsBought;

        ticketsToBuy -= ticketsBought;
        tickets[position] -= ticketsBought;

        // If the person at position k finishes buying tickets, return the time taken
        if (position == k && tickets[position] == 0) {
            return time;
        }

        q.push({ticketsToBuy, position}); // Push the person back to the queue if they still want to buy more tickets
    }

    return -1; // Person at position k never finishes buying tickets
}

int main() {
    // Example usage:
    std::vector<int> tickets = {2, 3, 2};
    int k = 2;

    int result = timeToBuyTickets(tickets, k);
    std::cout << "Output: " << result << std::endl; // Output: 6

    return 0;
}
