/*
This application demonstrates how to simulate a workload using a lambda function in C++.
*/

/*
Include header files to let us work with input and output objects, threads, promises, time, function objects, and random numbers.
*/
#include <iostream>     // For input and output objects like cout and cin
#include <thread>       // For threads
#include <future>       // For promises
#include <chrono>       // For time
#include <functional>   // For function objects
#include <random>       // For random numbers


/*
Create a lambda function named 'job' that simulates a workload.
Arguments:
- 'workload': an integer representing the number of steps in the workload
Returns: void
Details:
- Use a 'for loop' to to simulate a workload by iterating from the given workload value down to 1. 
- For each iteration, it performs the following steps:
    1) Generates a random sleep time between 0.5 and 1.5 seconds.
    2) Pauses the execution for the generated sleep time.
    3) Prints a message indicating the completion of the current step.
Example:
job(10); // Simulates a workload with 10 steps
*/

auto job = [](int workload) {
    for (int i = workload; i > 0; i--) {
        // Generate a random sleep time between 0.5 and 1.5 seconds
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.5, 1.5);
        double sleep_time = dis(gen);

        // Pause the execution for the generated sleep time
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleep_time * 1000)));

        // Print a message indicating the completion of the current step
        std::cout << "Step " << i << " completed." << std::endl;
    }
};

/*
Create a function 'main' to run the application.
Set the number of steps in the workload to 20 and call the 'job' function to simulate the workload.
*/
int main() {
    // Set the number of steps in the workload
    int workload = 20;

    // Call the 'job' function to simulate the workload
    job(workload);

    return 0;
}
