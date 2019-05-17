import math
import sys
import time

def pythonMultiplication(x, y):
  t1 = time.perf_counter_ns()
  result = x * y
  t2 = time.perf_counter_ns()
  print ("Base Python multiplication took " + str(t2 - t1) + " nanoseconds to return " + str(result) + ".")

def gradeSchoolMultiplication(x, y):
  t1 = time.perf_counter_ns()
  place = 0
  result = 0

  for yCurr in reversed(str(y)):
    result += x * int(yCurr) * 10**place
    place += 1

  t2 = time.perf_counter_ns()
  print ("Grade School ALgorithm multiplication took " + str(t2 - t1) + " nanoseconds to return " + str(result) + ".")

def recursiveMultiplication(x, y):
  xSize = int(math.log10(x)) + 1
  ySize = int(math.log10(y)) + 1
  n = xSize if xSize > ySize else ySize # Max size
  ac = 0
  ad = 0
  bc = 0
  bd = 0

  if (xSize == 1 or ySize == 1):
    return int(x * y)
  else:
    if (xSize >= ySize * 2):
      a, b = int(x / 10**(n/2)), int(x % 10**(n/2))
      d = y

      ac = 0
      ad = recursiveMultiplication(a, d)
      bc = 0
      bd = recursiveMultiplication(b, d)
    elif (ySize >= xSize * 2):
      b = x
      c, d = int(y / 10**(n/2)), int(y % 10**(n/2))

      ac = 0
      ad = 0
      bc = recursiveMultiplication(b, c)
      bd = recursiveMultiplication(b, d)
    else:
      a, b = int(x / 10**(n/2)), int(x % 10**(n/2))
      c, d = int(y / 10**(n/2)), int(y % 10**(n/2))

      ac = recursiveMultiplication(a, c)
      ad = recursiveMultiplication(a, d)
      bc = recursiveMultiplication(b, c)
      bd = recursiveMultiplication(b, d)

  # 10^n * ac + 10^(n/2) * (ad + bc) + bd
  return int(10**n * ac + 10**(n / 2) * (ad + bc) + bd)

def recursiveMultiplicationPrint(x, y):
  t1 = time.perf_counter_ns()
  result = recursiveMultiplication(x, y)
  t2 = time.perf_counter_ns()
  print ("Grade School ALgorithm multiplication took " + str(t2 - t1) + " nanoseconds to return " + str(result) + ".")

def main():
  if len(sys.argv) < 2:
    print ("Too few parameters were input. Please input two integer values.")
    return

  x = int(sys.argv[1])
  y = int(sys.argv[2])

  pythonMultiplication(x, y)
  gradeSchoolMultiplication(x, y)
  recursiveMultiplicationPrint(x, y)

if __name__ == "__main__":
    main()
