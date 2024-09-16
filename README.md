# Reflection 02, OpenMP I: Trapezoidal Rule

This reflection uses code created in class  that implements the Trapezoidal Rule. With the code, it will be runned on the Ohio Supercomputing Center (OSC). 

This program will run a function that finds the area under the curve using the Trapezoidal rule Using parallelism. This means that over the intervals a=0 and b=16, data will be gathered from running 1 to 12 threads/processors with a value of n ranging from 10,000 to 100,000 in steps of 10,000.
## Runing Program

**TO RUN LOCALLY:**

Compile with Docker:

```
docker run --rm -v ${PWD}:/tmp -w /tmp/Default rgreen13/alpine-bash-gpp make all
```

Run with Docker:

```
docker run --rm -v ${PWD}:/tmp -w /tmp/Default rgreen13/alpine-bash-gpp ./OpenMP
```

**TO RUN ON OSC:**

Clone the project

```bash
  git clone git@github.com:WinstonShi10/CS4170_FA2024_R02_SHI.git Reflection_02
```

Login into the OSC

```bash
  ssh USERNAME@owens.osc.edu
```

Create SSH key and add to account

```bash
  ssh-keygen -t ed25519 -C "USER_EMAIL"
```

Load Git

```bash
  module load git
```

Prevent git from attempting to open a GUI to ask for your username/password

```bash
  unset SSH_ASKPASS
```

Clone project to the OSC

```bash
  git clone git@github.com:WinstonShi10/CS4170_FA2024_R02_SHI.git Reflection_02
```

Switch directory to Git repository

```bash
  cd reflection_02
```

run SLURM jobscript file

```bash
  sbatch jobScript.slurm
```

Check Email to see a confirmation that the program is started/completed

![image](Email Confirmation.jpeg | width=100)

Find Slurm jobscript status

```bash
  squeue -j BATCH_ID_NUM
```

See information about jobs in the OSC queue

```bash
  squeue
```

See detailed information on the batch job, showing:
 * Resource usage statistics
 * CPU usage
 * Memory usage
 * I/O operations
 * Process creation rate

```bash
  sacct -j BATCH_ID_NUM
```

Change directory to Default file

```bash
  cd Default
```

open results file to see results of running the program

```bash
  cat results.csv
```
## Lessons Learned

**Key Lessons**

1. How to clone a repository.

2. How to setup a repository to the class setup standard.

3. Download and run Docker container to run program.

4. Creating and account and running programs on the Ohio Supercompter.

5. How to run a SLURM file that submits a job to OSC

6. How to check the status of a jobscript in the OSC queue

**Key Code**

Setup OMP threads

```c++
 omp_set_num_threads(thread_num); 
```
specify the number of threads used for the following lines

```c++
 #pragma omp parallel num_threads(thread_num)
```

Parallelize the folowing for-loop and aggregate the results

```c++
 #pragma omp parallel for reduction(+:retValue)
```

Setup for the SLURM file
```
 #SBATCH --ntasks=2 
 #SBATCH --time=1:00:00
 #SBATCH --mail-type=END,FAIL
 #SBATCH --account=PCS0288
 #SBATCH --job-name=JOB_NAME
```
## Running Program

When the program was ran, it poduce these results: 

```
[winstonshi@owens-login03 Default]$ cat results.csv
n        Threads     Result     Time
10000   1           1365.33    1.4e-05
n        Threads     Result     Time
10000   2           1365.33    1e-05
n        Threads     Result     Time
10000   3           1365.33    2.6e-05
n        Threads     Result     Time
10000   4           1365.33    4e-05
n        Threads     Result     Time
10000   5           1365.33    4.2e-05
n        Threads     Result     Time
10000   6           1365.33    4.7e-05
n        Threads     Result     Time
10000   7           1365.33    7.2e-05
n        Threads     Result     Time
10000   8           1365.33    6.3e-05
n        Threads     Result     Time
10000   9           1365.33    6.9e-05
n        Threads     Result     Time
10000   10           1365.33    7.8e-05
n        Threads     Result     Time
10000   11           1365.33    0.000113
n        Threads     Result     Time
10000   12           1365.33    9.2e-05
--------------------------------------
n        Threads     Result     Time
20000   1           1365.33    2.3e-05
n        Threads     Result     Time
20000   2           1365.33    2.4e-05
n        Threads     Result     Time
20000   3           1365.33    7.1e-05
n        Threads     Result     Time
20000   4           1365.33    5.6e-05
n        Threads     Result     Time
20000   5           1365.33    6.4e-05
n        Threads     Result     Time
20000   6           1365.33    9.2e-05
n        Threads     Result     Time
20000   7           1365.33    8.1e-05
n        Threads     Result     Time
20000   8           1365.33    9.2e-05
n        Threads     Result     Time
20000   9           1365.33    0.000101
n        Threads     Result     Time
20000   10           1365.33    0.000115
n        Threads     Result     Time
20000   11           1365.33    0.000115
n        Threads     Result     Time
20000   12           1365.33    0.000124
--------------------------------------
n        Threads     Result     Time
30000   1           1365.33    4.5e-05
n        Threads     Result     Time
30000   2           1365.33    4.8e-05
n        Threads     Result     Time
30000   3           1365.33    4.7e-05
n        Threads     Result     Time
30000   4           1365.33    5.2e-05
n        Threads     Result     Time
30000   5           1365.33    5.7e-05
n        Threads     Result     Time
30000   6           1365.33    8.5e-05
n        Threads     Result     Time
30000   7           1365.33    7.7e-05
n        Threads     Result     Time
30000   8           1365.33    8.1e-05
n        Threads     Result     Time
30000   9           1365.33    8.7e-05
n        Threads     Result     Time
30000   10           1365.33    9.4e-05
n        Threads     Result     Time
30000   11           1365.33    0.000102
n        Threads     Result     Time
30000   12           1365.33    0.000113
--------------------------------------
n        Threads     Result     Time
40000   1           1365.33    4.3e-05
n        Threads     Result     Time
40000   2           1365.33    3.5e-05
n        Threads     Result     Time
40000   3           1365.33    4.7e-05
n        Threads     Result     Time
40000   4           1365.33    6e-05
n        Threads     Result     Time
40000   5           1365.33    6.8e-05
n        Threads     Result     Time
40000   6           1365.33    8.8e-05
n        Threads     Result     Time
40000   7           1365.33    8.6e-05
n        Threads     Result     Time
40000   8           1365.33    9.6e-05
n        Threads     Result     Time
40000   9           1365.33    9.2e-05
n        Threads     Result     Time
40000   10           1365.33    9.8e-05
n        Threads     Result     Time
40000   11           1365.33    0.000104
n        Threads     Result     Time
40000   12           1365.33    0.000126
--------------------------------------
n        Threads     Result     Time
50000   1           1365.33    5.3e-05
n        Threads     Result     Time
50000   2           1365.33    4.2e-05
n        Threads     Result     Time
50000   3           1365.33    5.4e-05
n        Threads     Result     Time
50000   4           1365.33    9.2e-05
n        Threads     Result     Time
50000   5           1365.33    0.000101
n        Threads     Result     Time
50000   6           1365.33    0.000112
n        Threads     Result     Time
50000   7           1365.33    0.000122
n        Threads     Result     Time
50000   8           1365.33    0.000133
n        Threads     Result     Time
50000   9           1365.33    0.00014
n        Threads     Result     Time
50000   10           1365.33    0.000151
n        Threads     Result     Time
50000   11           1365.33    0.000164
n        Threads     Result     Time
50000   12           1365.33    0.000164
--------------------------------------
n        Threads     Result     Time
60000   1           1365.33    8.4e-05
n        Threads     Result     Time
60000   2           1365.33    5.1e-05
n        Threads     Result     Time
60000   3           1365.33    9.3e-05
n        Threads     Result     Time
60000   4           1365.33    6.8e-05
n        Threads     Result     Time
60000   5           1365.33    8.5e-05
n        Threads     Result     Time
60000   6           1365.33    0.000115
n        Threads     Result     Time
60000   7           1365.33    0.000124
n        Threads     Result     Time
60000   8           1365.33    0.000136
n        Threads     Result     Time
60000   9           1365.33    0.000142
n        Threads     Result     Time
60000   10           1365.33    0.000133
n        Threads     Result     Time
60000   11           1365.33    0.000136
n        Threads     Result     Time
60000   12           1365.33    0.00014
--------------------------------------
n        Threads     Result     Time
70000   1           1365.33    9.8e-05
n        Threads     Result     Time
70000   2           1365.33    0.0021
n        Threads     Result     Time
70000   3           1365.33    9e-05
n        Threads     Result     Time
70000   4           1365.33    8.1e-05
n        Threads     Result     Time
70000   5           1365.33    9.4e-05
n        Threads     Result     Time
70000   6           1365.33    0.000115
n        Threads     Result     Time
70000   7           1365.33    0.000104
n        Threads     Result     Time
70000   8           1365.33    0.000112
n        Threads     Result     Time
70000   9           1365.33    0.000119
n        Threads     Result     Time
70000   10           1365.33    0.000158
n        Threads     Result     Time
70000   11           1365.33    0.00014
n        Threads     Result     Time
70000   12           1365.33    0.000155
--------------------------------------
n        Threads     Result     Time
80000   1           1365.33    8.5e-05
n        Threads     Result     Time
80000   2           1365.33    6.1e-05
n        Threads     Result     Time
80000   3           1365.33    8.9e-05
n        Threads     Result     Time
80000   4           1365.33    9.5e-05
n        Threads     Result     Time
80000   5           1365.33    0.0001
n        Threads     Result     Time
80000   6           1365.33    0.000116
n        Threads     Result     Time
80000   7           1365.33    0.000125
n        Threads     Result     Time
80000   8           1365.33    0.000133
n        Threads     Result     Time
80000   9           1365.33    0.000137
n        Threads     Result     Time
80000   10           1365.33    0.000151
n        Threads     Result     Time
80000   11           1365.33    0.000161
n        Threads     Result     Time
80000   12           1365.33    0.00016
--------------------------------------
n        Threads     Result     Time
90000   1           1365.33    9.5e-05
n        Threads     Result     Time
90000   2           1365.33    6.8e-05
n        Threads     Result     Time
90000   3           1365.33    8.1e-05
n        Threads     Result     Time
90000   4           1365.33    8.7e-05
n        Threads     Result     Time
90000   5           1365.33    0.000142
n        Threads     Result     Time
90000   6           1365.33    0.000151
n        Threads     Result     Time
90000   7           1365.33    0.000165
n        Threads     Result     Time
90000   8           1365.33    0.00018
n        Threads     Result     Time
90000   9           1365.33    0.000208
n        Threads     Result     Time
90000   10           1365.33    0.000184
n        Threads     Result     Time
90000   11           1365.33    0.000182
n        Threads     Result     Time
90000   12           1365.33    0.000181
--------------------------------------
n        Threads     Result     Time
100000   1           1365.33    0.000133
n        Threads     Result     Time
100000   2           1365.33    0.000114
n        Threads     Result     Time
100000   3           1365.33    0.000124
n        Threads     Result     Time
100000   4           1365.33    0.000103
n        Threads     Result     Time
100000   5           1365.33    0.00012
n        Threads     Result     Time
100000   6           1365.33    0.000129
n        Threads     Result     Time
100000   7           1365.33    0.00014
n        Threads     Result     Time
100000   8           1365.33    0.000148
n        Threads     Result     Time
100000   9           1365.33    0.000151
n        Threads     Result     Time
100000   10           1365.33    0.000153
n        Threads     Result     Time
100000   11           1365.33    0.000163
n        Threads     Result     Time
100000   12           1365.33    0.00017
--------------------------------------
```

### Calculating Speedup

Speedup = T1 / T(n)

Because the reflection asked for parallizing the program with up to 12 threads, N = 12.

| n       | T(1)          | T(N)         | Speedup |
| :------ | :------------ | :----------- | :------ |
| 10,000  | 1.4e-05  sec  | 9.2e-05  sec | 0.15    |
| 20,000  | 2.3e-05  sec  | 0.000124 sec | 0.19    |
| 30,000  | 4.5e-05  sec  | 0.000113 sec | 0.40    |
| 40,000  | 4.3e-05  sec  | 0.000126 sec | 0.34    |
| 50,000  | 5.3e-05  sec  | 0.000164 sec | 0.32    |
| 60,000  | 8.4e-05  sec  | 0.00014  sec | 0.6     |
| 70,000  | 9.8e-05  sec  | 0.000155 sec | 0.63    |
| 80,000  | 8.5e-05  sec  | 0.00016  sec | 0.53    |
| 90,000  | 9.5e-05  sec  | 0.000181 sec | 0.52    |
| 100,000 | 0.000133 sec  | 0.00017  sec | 0.78    |

**Why is the Speedup so bad?**

Probable Cause(s): 
 * Bad Code
 * Incorrect implementation of parallelization
 * Lack of optimization

Potential cause(s): 
 * Communication Overhead between processes, the cost of processes exchanging data
 * Load Imbalance, a process has more or less work than other processes
 * Processes waiting on other processes to finish their task
 * The serial program was efficient as is and parallelizing it creates overhead

### Calculating Efficiency

Efficiency = (Speedup / Number of processors) * 100

| Speedup | Num Processors | Efficiency |
| :------ | :------------- | :--------- |
| 0.15    | 12             | 1.25 %     |
| 0.19    | 12             | 1.58 %     |
| 0.40    | 12             | 3.33 %     |
| 0.34    | 12             | 2.83 %     |
| 0.32    | 12             | 2.67 %     |
| 0.6     | 12             | 5.00 %     |
| 0.63    | 12             | 5.25 %     |
| 0.53    | 12             | 4.41 %     |
| 0.52    | 12             | 4.33 %     |
| 0.78    | 12             | 6.50 %     |

The lack of of effeciency is directly related to lack of speedup of the parallelization.
