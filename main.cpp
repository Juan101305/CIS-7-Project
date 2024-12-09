#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
using namespace std;

// Define the cities and distances given inside of a matrix
const int NUM_CITIES = 4;
int graph[NUM_CITIES][NUM_CITIES] =
{
    {0, 16, 24, 33}, // Riverside (R)
    {16, 0, 18, 26}, // Moreno Valley (M)
    {24, 18, 0, 30}, // Perris (P)
    {33, 26, 30, 0}  // Hemet (H)
};

// Function calculateDistance to calculate the total distance of any given trip variation
int calculateDistance(const vector<int> &path)
{
    int total_distance = 0; // Initialize total distance to zero
// Loop through each city in the path except the last
    for (size_t i = 0; i < path.size() - 1; i++) 
    {
        int from = path[i];       // Get the current city index
        int to = path[i + 1];     // Get the next city index
// Add the distance between the current and next city
        total_distance += graph[from][to]; 
    }
// Add distance from last city back to the first city
    total_distance += graph[path.back()][path[0]]; 
    return total_distance;
}

// Function displayMatrix to display the adjacency matrix with distances
void displayMatrix()
{
    vector<string> city_names = {"Riverside", "Moreno Valley", "Perris",                                    "Hemet"};
    cout << "\nAdjacency Matrix (Distances in miles):\n";
    cout << "       ";
// Loop to display city names at the top row
    for (const auto &name : city_names) 
    {
        cout << setw(15) << name;
    }
    cout << "\n";
// Loop to display distances for each city
    for (int i = 0; i < NUM_CITIES; i++) 
    {
        cout << setw(15) << city_names[i]; // City name in the left column

// Loop through each column to display distances
        for (int j = 0; j < NUM_CITIES; j++) 
        {
// If statement to check for distance of zero (same city)
            if (graph[i][j] == 0) 
                cout << setw(15) << "0";
            else 
                cout << setw(15) << graph[i][j];
        }
        cout << "\n"; 
    }
    cout << "\n";
}

int main()
{
    vector<string> city_names = {"Riverside", "Moreno Valley", "Perris",                                    "Hemet"};

// Call function to display the adjacency matrix
    displayMatrix();

// Initialize the cities for permutations (0 = Riverside, 1 = Moreno Valley, 2 = Perris, 3 = Hemet)
    vector<int> cities = {0, 1, 2, 3};

// Use numeric_limits<int>::max() to initialize the shortest_distance 
    int shortest_distance = numeric_limits<int>::max();
    vector<int> best_path;

    cout << "All variations of the trip and their distances:\n";

// Do-while loop to generate all permutations of the cities
    do
    {
// Calculate the total distance for the current permutation
        int distance = calculateDistance(cities);
        
// Loop through the cities in the current permutation
        for (int city : cities) 
        {
            cout << city_names[city] << " -> "; // Print each city in path
        }
        cout << city_names[cities[0]]; // Return to the start
        cout << " | Distance: " << distance << endl;

// If statement to check if the current path has the shortest distance 
        if (distance < shortest_distance) 
        {
            shortest_distance = distance; // Update the shortest distance
            best_path = cities;           // Update the best path
        }
    } while (next_permutation(cities.begin() + 1, cities.end())); 

// Output the shortest path
    cout << "\nShortest path:\n";
// Loop to print the cities in the best path
    for (int city : best_path) 
    {
        cout << city_names[city] << " -> "; // Print each city in the                                                     shortest path
    }
    cout << city_names[best_path[0]]; // Return to the start
    cout << " | Distance: " << shortest_distance << " miles\n";

    return 0;
}
