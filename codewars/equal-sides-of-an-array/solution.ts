export function getAccumulatedSumUntil(arr: number[], index: number): number {
  if (index === 0) return 0;
  return arr[index - 1];
}

export function getAccumulatedSumFrom(arr: number[], index: number): number {
  if (index === arr.length - 1) return 0;
  return arr[arr.length - 1] - arr[index];
}

/**
 * With this solution, we DON'T need to recalculate the sums for each index.
 * We can just memoize the sums and then calculate the left and right sums for
 * each index by accessing the memoized sums and doing simple substractions.
 */
export function findEvenIndex(arr: number[]): number {
  // Memoize the sums
  const memoizedSums: number[] = new Array(arr.length);

  for (let i = 0; i < arr.length; i++) {
    if (i == 0) memoizedSums[i] = arr[i];
    else memoizedSums[i] = memoizedSums[i - 1] + arr[i];
  }

  // Find and index that makes the left and right sums equal
  for (let i = 0; i < arr.length; i++) {
    const [leftSum, rightSum] = [
      getAccumulatedSumUntil(memoizedSums, i),
      getAccumulatedSumFrom(memoizedSums, i),
    ];

    if (leftSum === rightSum) return i;
  }

  return -1;
}

const sampleArr = [1, 2, 3, 4, 3, 2, 1];
findEvenIndex(sampleArr);
