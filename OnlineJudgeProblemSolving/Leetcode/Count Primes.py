# Here in this problem we are given an integer n we have to find the number of primes between 1 to n - 1
# The strategy we will follow here is that
# We will check primality of each number between 1 and n - 1
# if current number is a prime number we increase the count of primes by 1
# at the end of the primality test we return the count of prime numbers

# Now one question remains how would we check if a number is prime or not
# If the number is 1 than it is definately not a prime number
# Otherwise if the number is divisible by any of the numbers betweeen 2 to square root of the number that we are running the primality test for than it is not a prime number

# python code
class Solution:
    def countPrimes(self, n: int) -> int:
        countOfPrimes = 0
        for currNum in range(2, n):
            print(currNum)
            if self.isPrime(currNum):
                countOfPrimes = countOfPrimes + 1
            
        return countOfPrimes
      
    def isPrime(self, candidatePrime):
        if candidatePrime == 1:
            return False

        sqrtOfCandidatePrime = int(math.sqrt(candidatePrime))
        for num in range(2, sqrtOfCandidatePrime + 1):
            if(candidatePrime % num == 0):
                return False
        
        return True
