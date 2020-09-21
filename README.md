IMEN324(00) - Simulation Modeling and Analysis 2019 @KoreaUniversity

## Requirements

- Textbook : Averill M. Law, Simulation Modeling and Analysis (5th Edition), McGraw-Hill, 2015
- Sample code : [www.mhhe.com/law](www.mhhe.com/law)
  - mm1.c
  - mm1alt.c
  - inv.c

## Assignments

- M/M/1, Single-Server Queueing System(𝞴, 𝞵, n)

  - Mean interarrival time: 3.000 minutes
  - Mean service titme: 2.000 minutes
  - Number of customers: 2000

  ```shell
  # Assignments/Assignment#1/mm1
  gcc lcgrand.c mm1.c -o main
  ```

  ```
  ./main
  ```

- M/M/1, Single-Server Queueing System(𝞴, 𝞵, t)

  - Mean interarrival time: 5.000 minutes
  - Mean service titme: 3.000 minutes
  - Length of the simulation : 1400.000 minutes

  ```shell
  # Assignments/Assignment#1/mm1alt
  gcc lcgrand.c mm1alt.c -o main
  ```

  ```shell
  ./main
  ```

- Inventory System

  - Ordering cost: 50 + 3Z(\$)
  - Holding cost: 2(\$)
  - Shortage cost: 8(\$)
  - Inter-Demand time ~ Expo(0.2)
  - Lead time ~ Uniform(1, 2)
  - Demand size: 2, 4, 6, 8 with probabilites 1/5, 2/5, 1/5, 1/5
  - End-simulation time: 240 months
  - Review policy
    - (20, 100)
    - (30, 100)
    - (40, 100)
    - (40, 120)
    - (50, 120)
    - (60, 120)

  ```shell
  # Assignments/Assignment#1/inv
  gcc lcgrand.c inv.c -o main
  ```

  ```shell
  ./main
  ```

컾마일하는건 어차피 gcc라는 걸로 해야해서 에디터 상관없음
