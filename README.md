*This project has been created as part of the 42 curriculum by schoinsk, jasiuda.*

# push_swap

## Description

`push_swap` sorts a sequence of unique signed integers with two stacks and a
restricted instruction set. The program does not print the sorted values. It
prints the operations required to transform stack A into ascending order, with
the smallest value at the top and stack B empty.

The project focuses on algorithm selection and operation complexity. It embeds
four sorting strategies and can select one at runtime. Its default adaptive
mode measures how disordered the original input is, then chooses an algorithm
suited to that input.

## Rules

The first input value starts at the top of stack A. Stack B starts empty. The
program may emit only these instructions:

| Instruction | Effect |
| --- | --- |
| `sa` | Swap the first two values of A. |
| `sb` | Swap the first two values of B. |
| `ss` | Run `sa` and `sb` together. |
| `pa` | Move the top value of B to the top of A. |
| `pb` | Move the top value of A to the top of B. |
| `ra` | Rotate A upward; the first value becomes the last. |
| `rb` | Rotate B upward; the first value becomes the last. |
| `rr` | Run `ra` and `rb` together. |
| `rra` | Reverse-rotate A; the last value becomes the first. |
| `rrb` | Reverse-rotate B; the last value becomes the first. |
| `rrr` | Run `rra` and `rrb` together. |

Each operation is written to standard output on its own line. Diagnostic and
benchmark information never belongs to the operation stream.

## Algorithms

Before sorting, the program assigns every value its rank in ascending order.
Rank compression maps arbitrary signed integers to the range `0` through
`n - 1` while preserving their order. The sorting strategies can then compare
compact, non-negative indices.

Complexities below count generated push_swap operations, as required by the
subject. Rank compression uses `O(n)` auxiliary storage.

### Simple: selection by rank — `O(n²)`

The simple strategy searches stack A for the next smallest rank. It rotates A
in the shorter direction, pushes that value to B, and repeats until one value
remains in A. It then pushes every value back from B to A.

At most `O(n)` rotations are needed for each of `n` values, so the strategy
generates `O(n²)` operations. It provides a predictable baseline and satisfies
the mandatory quadratic strategy requirement.

### Medium: chunk sort — `O(n√n)`

The medium strategy divides the rank range into moving chunks whose width is
based on `√n`. While scanning A, it:

1. pushes ranks below the current lower boundary to B and rotates B;
2. pushes ranks inside the current chunk directly to B;
3. rotates A when the top rank lies beyond the current chunk.

After A becomes empty, the algorithm repeatedly finds the largest rank in B,
rotates B in the shorter direction, and pushes that value back to A. Chunking
limits the search range and yields an `O(n√n)` upper bound in the push_swap
operation model.

### Complex: binary LSD radix sort — `O(n log n)`

The complex strategy processes compressed ranks one bit at a time, starting
with the least significant bit. For each bit:

- a zero bit sends the top value from A to B with `pb`;
- a one bit keeps the value in A and rotates it with `ra`;
- after one full pass, `pa` returns every value from B to A.

Rank values need `⌈log₂ n⌉` bits. Each pass performs at most `2n` operations,
which gives an `O(n log n)` operation bound and `O(n)` stack storage.

### Adaptive strategy

Adaptive mode computes the inversion ratio before performing any operation. An
inversion is a pair `(i, j)` for which `i < j` but `A[i] > A[j]`.

```text
                    number of inverted pairs
disorder = ---------------------------------------------
             n * (n - 1) / 2 possible ordered pairs
```

The ratio ranges from `0` for an ascending sequence to `1` for a descending
sequence. Benchmark output presents the same value as a percentage.

| Disorder | Selected internal strategy | Operation bound |
| --- | --- | --- |
| `< 0.20` | Simple selection by rank | `O(n²)` |
| `0.20 ≤ disorder < 0.50` | Medium chunk sort | `O(n√n)` |
| `≥ 0.50` | Complex binary radix sort | `O(n log n)` |

The boundaries separate three useful regimes and follow the mandatory subject
thresholds. Low-disorder inputs contain relatively few inversions, so the
simple baseline remains easy to trace. Medium-disorder inputs benefit from
range-based grouping. High-disorder inputs use radix sort, whose operation
count depends on input size rather than inversion placement.

Adaptive mode requires `O(n²)` CPU work to count all pairs and `O(1)` extra
space for the metric itself. The selected sorting strategy uses the operation
bound shown in the table and `O(n)` storage for the two stacks and rank data.

## Instructions

### Requirements

- a C compiler available as `cc`;
- `make`;
- a POSIX-like environment;
- the 42 Norminette for submission checks;
- the provided `checker_linux` binary when validating on Linux.

### Compilation

Build the mandatory program:

```sh
make
```

The Makefile compiles with `-Wall -Wextra -Werror` and creates `./push_swap`.
It also provides the required maintenance rules:

```sh
make clean   # remove object files
make fclean  # remove object files, libft.a, and push_swap
make re      # rebuild everything
```

### Basic usage

Pass integers as separate arguments:

```sh
./push_swap 4 67 3 87 23
```

You may also pass the list as one quoted argument:

```sh
./push_swap "4 67 3 87 23"
```

With no strategy selector, the program uses adaptive mode. A sorted input
produces no operations, and an invocation without arguments prints nothing.

### Strategy selectors

Place at most one strategy selector before the integer list:

```sh
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

| Selector | Strategy |
| --- | --- |
| `--simple` | Force the `O(n²)` selection strategy. |
| `--medium` | Force the `O(n√n)` chunk strategy. |
| `--complex` | Force the `O(n log n)` radix strategy. |
| `--adaptive` | Select a strategy from the measured disorder. |

Every selector accepts every valid input size and disorder level.

## Benchmark mode

Add `--bench` before the integer list to print metrics after sorting:

```sh
./push_swap --bench --adaptive 4 67 3 87 23
```

Operations remain on standard output. Benchmark data goes to standard error and
contains:

- disorder as a percentage with two decimal places;
- the selected strategy and its theoretical operation complexity;
- the total operation count;
- separate counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`,
  `rrb`, and `rrr`.

You can separate the two streams:

```sh
./push_swap --bench 4 67 3 87 23 \
    > operations.txt 2> benchmark.txt
```

Hide operations and display only benchmark data:

```sh
./push_swap --bench 4 67 3 87 23 > /dev/null
```

## Validation

Pipe the generated instructions to the provided checker on Linux:

```sh
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

The checker prints `OK` when A is sorted and B is empty. It prints `KO` when the
operation sequence does not produce the required final state.

Count operations without running the checker:

```sh
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Generate a random 100-value test on systems that provide `shuf`:

```sh
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

The mandatory performance thresholds are:

| Input size | Pass | Good | Excellent |
| ---: | ---: | ---: | ---: |
| 100 | `< 2000` operations | `< 1500` | `< 700` |
| 500 | `< 12000` operations | `< 8000` | `< 5500` |

Useful checks before submission:

```sh
make re
norminette *.c *.h libft/*.c libft/*.h
```

Test at least the following input classes:

- zero, one, two, three, and five values;
- ascending and descending sequences;
- `INT_MIN` and `INT_MAX`;
- random sequences of 100 and 500 unique values;
- duplicate values, invalid tokens, empty strings, and integer overflow;
- every strategy with and without `--bench`.

## Error handling

Invalid input writes exactly `Error` followed by a newline to standard error.
Errors include:

- a token that is not a signed decimal integer;
- a value outside the 32-bit signed integer range;
- duplicate values;
- an empty numeric argument;
- an unknown flag;
- more than one strategy selector.

The operation stream on standard output remains free of error and benchmark
messages.

## Project structure

| Files | Responsibility |
| --- | --- |
| `main.c`, `init_and_check*.c` | Program entry point and option validation. |
| `parser*.c` | Integer parsing, range checks, and duplicate detection. |
| `stack*.c` | Stack allocation, inspection, initialization, and cleanup. |
| `swap.c`, `push.c`, `rotate.c`, `rev_rotate.c` | Push_swap operations. |
| `operation_controller.c` | Operation dispatch and benchmark counters. |
| `index.c` | Rank compression. |
| `disorder.c` | Inversion-based disorder measurement. |
| `simple_sort.c` | Quadratic selection strategy. |
| `medium_sort*.c` | Chunk strategy and its helpers. |
| `sort_radix.c` | Binary LSD radix strategy. |
| `adaptive_sort.c` | Disorder-based strategy selection. |
| `bench_mode_controller.c` | Benchmark formatting on standard error. |
| `libft/` | Project-local implementation of permitted utility functions. |
| `Makefile` | Build and cleanup rules. |

The main execution flow is:

```text
arguments -> flags -> parser -> stack A -> disorder -> rank indexing
          -> strategy selection -> operations -> optional benchmark
```

## Team contributions

Both authors contributed to integration, debugging, testing, algorithm review,
and preparation for the defense. Each author is expected to understand and
explain the complete codebase.

| Author | Main areas of contribution |
| --- | --- |
| `schoinsk` | CLI flow, parsing and validation, benchmark mode, disorder measurement, adaptive selection, simple and medium strategy integration. |
| `jasiuda` | Stack representation, core stack operations, rank indexing and radix-sort foundations, integration and debugging. |

## Resources

- `subject.txt` — project specification and evaluation requirements.
- `man 2 read`, `man 2 write` — permitted POSIX I/O functions.
- `man 3 malloc`, `man 3 free`, `man 3 exit` — memory management and process termination.
- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, and Clifford Stein,
  *Introduction to Algorithms* — asymptotic analysis, sorting, and radix sort.
- Donald E. Knuth, *The Art of Computer Programming, Volume 3: Sorting and
  Searching* — sorting models and algorithm analysis.
- The official 42 Norminette repository — C formatting and submission checks:
  <https://github.com/42School/norminette>.

### Use of AI

Generative AI was used as a supporting tool for:

- comparing the implementation with the project subject;
- reviewing parser, memory-management, and edge-case behavior;
- designing randomized and boundary-focused test cases;
- structuring and editing this README.

The authors reviewed the generated suggestions, made the implementation
decisions, and remain responsible for the submitted code. AI-generated output
was not treated as a substitute for understanding, testing, or peer review.

## Authors

- `schoinsk`
- `jasiuda`
