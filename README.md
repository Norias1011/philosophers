# Philosopher Project

## Introduction
Welcome to the Philosopher Project, a concurrent programming project developed for School 42. This project is designed to deepen understanding of threading, mutexes, and concurrency in a practical context inspired by the classic "Dining Philosophers" problem.

## Description
The Philosopher Project simulates the scenario of a group of philosophers sitting around a dining table with a bowl of spaghetti. Each philosopher alternates between thinking and eating. However, there are only a limited number of forks available, and a philosopher needs two forks to eat. Thus, they must coordinate with each other to prevent deadlock and starvation.

## Features
- **Concurrency**: Utilizes multi-threading to simulate philosophers and forks.
- **Mutexes**: Implements mutexes to manage access to shared resources, such as forks.
- **Deadlock Prevention**: Incorporates a solution to prevent deadlock by enforcing a resource allocation hierarchy.
- **Starvation Avoidance**: Ensures that all philosophers have a fair chance to eat by implementing a mechanism to prevent starvation.

## How to Use
To compile the program, simply run the provided Makefile:
```bash
make
```
This will generate an executable named `philosopher`.

To run the program, execute the following command:
```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
Replace the placeholders with appropriate values for your simulation. For example:
```bash
./philo 5 800 200 200 7
```
This command will simulate 5 philosophers, with a time to die of 800 milliseconds, time to eat of 200 milliseconds, time to sleep of 200 milliseconds, and each philosopher must eat 7 times before the simulation ends.


## License
This project is licensed under the [MIT License](LICENSE).

## Acknowledgments
Special thanks to School 42 for providing the inspiration and resources for this project.

---
