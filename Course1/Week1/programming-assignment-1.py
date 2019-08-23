    
#####################################################################
#In this programming assignment you will implement one or more of the integer multiplication algorithms described in lecture.
#To get the most out of this assignment, your program should restrict itself to multiplying only pairs of single-digit numbers. 
#You can implement the grade-school algorithm if you want, but to get the most out of the assignment you'll want to implement recursive 
#integer multiplication and/or Karatsuba's algorithm.
#So: what's the product of the following two 64-digit numbers?
#3141592653589793238462643383279502884197169399375105820974944592
#2718281828459045235360287471352662497757247093699959574966967627
#[TIP: before submitting, first test the correctness of your program on some small test cases of your own devising. 
#Then post your best test cases to the discussion forums to help your fellow students!]
#[Food for thought: the number of digits in each input number is a power of 2. Does this make your life easier? 
#Does it depend on which algorithm you're implementing?]
####################################################################
def mKaratsubaMultiply(xFirstNum, xSecondNum):
    if(xFirstNum < 10 or xSecondNum < 10):
        return xFirstNum*xSecondNum;
    xFirstNumStr = str(xFirstNum)
    xSecondNumStr = str(xSecondNum)
    lFirstHalfIndex  = int(max(len(xFirstNumStr), len(xSecondNumStr))/2)
    a, b = int(xFirstNumStr[:-lFirstHalfIndex ]), int(xFirstNumStr[-lFirstHalfIndex :])
    c, d = int(xSecondNumStr[:-lFirstHalfIndex ]), int(xSecondNumStr[-lFirstHalfIndex :])
    lFirstProduct  = mKaratsubaMultiply(a, c)
    lSecondProduct  = mKaratsubaMultiply(b, d)
    lThirdProduct  = mKaratsubaMultiply(a + b, c + d)
    
    return (lFirstProduct  * 10 ** (2 * lFirstHalfIndex )) + ((lThirdProduct  - lFirstProduct  - lSecondProduct ) * 10 ** lFirstHalfIndex ) + lSecondProduct 

def main():
    lFirstNum = 3141592653589793238462643383279502884197169399375105820974944592
    lSecondNum = 2718281828459045235360287471352662497757247093699959574966967627
    print(mKaratsubaMultiply(lFirstNum, lSecondNum))


if __name__ == "__main__":
    main()
