# Part 1 - 1.2 Integer Multiplication
* C++
Because I'm utilizing "auto" typing for the timestamps in the main function, I need to target at least C++11 when building. To save typing, I created a makefile to handle the compiling moving forward. I went ahead and targeted C++17 just in case I run into anything else that I want to use moving forward. I don't like seeing warnings at compilation if they can at all be avoided.

* Python
Due to a project assignment at work, it looks like I'll be working in Python a fair bit. I'm going to start working through these algorithms in both C++ and Python, though probably with a preference for Python to learn the language and syntax. I'm using a nanosecond timer that requires Python 3.7 or greater, so that should be noted when attempting to run these scripts.

## Language Base Algorithm
* C++
I am utilizing the C++ multiplication method as my baseline. I'm hoping that working through these exercises I may get close to it in performance. The latency is so quick it forced me to require nanosecond precision with my timers.

* Python
Comparing the Python multiplication with C++ was a bit surprising. Everyone touts Python's prowess with numbers, and that's probably true when we start working with insane numbers, but for these test calculations it is actually running about 5-6 times slower than C++ (95ns vs 556ns).

## Grade School Algorithm
* C++
In running tests of this algorithm, I had to change my base test markup from Milliseconds to at least Microseconds. This showed the difference between the base C++ multiplication method and my Grade School Algorithm. Extending this further to Nanoseconds looks to be the best option for this algorithm sample because the C++ base method runs in nanoseconds.

The textbook algorithm has a complexity of O(n^2), however because of some programming shortcuts I took, mine has a complexity of O(n). To be proper, I should probably go back and nest the loop to more closely resemble the precise steps the book lays out, but I think I hit the main goals with the current design, so we'll just roll with it for now.

* Python
Implementing this was trivial with the C++ algorithm in place. Because Python makes it so easy to convert an integer into a string array, I can flip them back and forth at will. I think this ease within the language comes at a performance cost (especially if the coder does so indiscriminantly). The code is definitely much simpler, though. It's worth noting that with the simplifications I made with this algorithm over C++, I was able to cut the time by about 1/3 (25217ns vs 7092ns).

I think my Python script has a complexity of O(n) still. It does have a hidden loop in reversing the string array (and may have a hidden loop in creating the string array to begin with) but none of the loops nest, so I think it's still just linear and not exponential.

## Recursive Algorithm
* C++
With the recursive algorithm, I took a few approaches before having a fully working product. I kept trying to shortcut the algorithm from the book, but that turned out to be a big mistake. You really do need all of the steps, including recursively determining ac, ad, bc, and bd. That was the big mistake I made, trying to do it all within the return statement. The other major blocker I had was when one value was twice the length or more larger than the other. I broke out two if statements to handle these cases. While still an improvement over the Grade School Algorithm, it's not as much of an improvement as I expected. I'm starting to wonder what C++ does since it's so much faster than these two methods.

I created a v2 of the C++ recursive algorithm. After making some changes in Python to bring it closer to the C++ performance (which I expected it would be comparable), I realized that I could make some similar tweaks in C++ to improve performance there. Not to junk everything I did the first time around (for learning purposes more than anything else) I copied the logic, changed the input variables to integers rather than vectors of integers (I overloaded the method) and made my changes. Rather than manipulating the vectors, I'm using power of 10 division and modulus operations to get the left/right halves of each number. The performance increase with this change was substantial (25845ns vs 2685ns). That's not a typo, it was ten times faster. I'll do a little more work on the Python inplementation before moving on to Karatsuba.

Complexity of this algorithm would be O(log(n)). I made the decision to require that an integer array (vector, in this case) be passed in rather than actual integers. That may be a little bit of a cheat, but to be honest I only need the values in a primative integer form for the base cases. All other work (including all recursions) happen on the arrays/vectors.

* Python
This was the last algorithm already written and working in C++ when I switched to Python. Converting it, too, was pretty simple. My biggest surprise with this one has been how much slower it is than the C++ version of the same method. I attribute this to my switching back and forth between integer and string values so frequently, however at this time I don't see another way to handle this in Python. If I come across a better idea, I'll make sure to try it out and document it here. The current algorithm doesn't compare very well (25932ns vs 120909ns).

In trying to remove the unecessary lag I introduced in this algorithm, I found that changing from (len(str(x))) to (int(math.log10(x)) + 1) reduced lag by a full 1/3 (82533ns). This is the fist step in making Python comparable to C++ in this algorithm. I found this little hack online, and it's quite ingenious. I'll have to remember it for other times I may need this information.

Taking it a small step further, I removed the string array and integer back and forth. Utilizing division and modulus, I can achieve a little more speed (71292ns). I'm going to dig a little more to see what else could possibly be cleaned up.

Complexity of this algorithm is O(nlog(n)) (I think). I grant O(log(n)) for the recursive action of dividing the work in half each time, however I don't think you can ignore all of the calls that translate integers to string arrays and string arrays back to integers. While each one itself would be O(n) and there are a lot of them, they're still not nested, so we'll stick with O(nlog(n)).

## Karatsuba Algorithm
