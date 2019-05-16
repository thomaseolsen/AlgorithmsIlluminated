# Part 1 - 1.2 Integer Multiplication
Because I'm utilizing "auto" typing for the timestamps in the main function, I need to target at least C++11 when building. To save typing, I created a makefile to handle the compiling moving forward. I went ahead and targeted C++17 just in case I run into anything else that I want to use moving forward. I don't like seeing warnings at compilation if they can at all be avoided.

## Grade School Algorithm
In running tests of this algorithm, I had to change my base test markup from Milliseconds to at least Microseconds. This showed the difference between the base C++ multiplication method and my Grade School Algorithm. Extending this further to Nanoseconds looks to be the best option for this algorithm sample because the C++ base method runs in nanoseconds.

The textbook algorithm has a complexity of O(n^2), however because of some programming shortcuts I took, mine has a complexity of O(n). To be proper, I should probably go back and nest the loop to more closely resemble the precise steps the book lays out, but I think I hit the main goals with the current design, so we'll just roll with it for now.

## Recursive Algorithm

## Karatsuba Algorithm
