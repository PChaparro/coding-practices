export function findFirstRepeated(gifts: number[]): number {
  const registeredGifts = new Set<number>();

  for (const gift of gifts) {
    if (registeredGifts.has(gift)) return gift;
    registeredGifts.add(gift);
  }

  return -1;
}
