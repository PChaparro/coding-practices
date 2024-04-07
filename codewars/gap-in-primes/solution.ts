/**
 * Returns an array of prime numbers between the given range (inclusive).
 * This function uses the Sieve of Eratosthenes algorithm to find prime numbers.
 */
export function getPrimes({
  min,
  max,
}: {
  min: number;
  max: number;
}): number[] {
  const isPrime = new Array(max + 1).fill(true);
  isPrime[0] = isPrime[1] = false;

  for (let currentNumber = 2; currentNumber < Math.sqrt(max); currentNumber++) {
    if (isPrime[currentNumber]) {
      // Mark all multiples of the current number as not prime
      for (
        let multipleNumber = currentNumber * 2;
        multipleNumber <= max;
        multipleNumber += currentNumber
      ) {
        isPrime[multipleNumber] = false;
      }
    }
  }

  const primes: number[] = [];

  for (let number = min; number < max; number++) {
    if (isPrime[number]) primes.push(number);
  }

  return primes;
}

/**
 * Problem function
 * @param g - The expected gap between the two prime numbers
 * @param m - The lower bound of the range
 * @param n - The upper bound of the range
 * @returns An array containing the two prime numbers with the gap of `g` between them if found, otherwise null.
 */
export function gap(g: number, m: number, n: number): number[] | null {
  const primes = getPrimes({ min: m, max: n });

  for (let i = 0; i < primes.length - 1; i++) {
    const primesGap = primes[i + 1] - primes[i];
    if (primesGap === g) return [primes[i], primes[i + 1]];
  }

  return null;
}
