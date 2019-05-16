# Part 1 - 1.2 Integer Multiplication
Because I'm utilizing "auto" typing for the timestamps in the main function, I need to target at least C++11 when building. To save typing, I created a makefile to handle the compiling moving forward. I went ahead and targeted C++17 just in case I run into anything else that I want to use moving forward. I don't like seeing warnings at compilation if they can at all be avoided.

## Grade School Algorithm
In running tests of this algorithm, I had to change my base test markup from Milliseconds to at least Microseconds. This showed the difference between the base C++ multiplication method and my Grade School Algorithm. Extending this further to Nanoseconds looks to be the best option for this algorithm sample because the C++ base method runs in nanoseconds.

The textbook algorithm has a complexity of O(n^2), however because of some programming shortcuts I took, mine has a complexity of O(n). To be proper, I should probably go back and nest the loop to more closely resemble the precise steps the book lays out, but I think I hit the main goals with the current design, so we'll just roll with it for now.

## Recursive Algorithm
With the recursive algorithm, I took a few approaches before having a fully working product. I kept trying to shortcut the algorithm from the book, but that turned out to be a big mistake. You really do need all of the steps, including recursively determining ac, ad, bc, and bd. That was the big mistake I made, trying to do it all within the return statement. The other major blocker I had was when one value was twice the length or more larger than the other. I broke out two if statements to handle these cases. While still an improvement over the Grade School Algorithm, it's not as much of an improvement as I expected. I'm starting to wonder what C++ does since it's so much faster than these two methods.

## Karatsuba Algorithm
