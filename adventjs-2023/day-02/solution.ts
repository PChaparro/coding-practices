export function manufacture(gifts: string[], materials: string): string[] {
  const matsSet = new Set<string>([...materials]);

  return gifts.filter((gift) => {
    const uniqueGiftMats = [...new Set<string>([...gift])];
    return uniqueGiftMats.every((mat) => matsSet.has(mat));
  });
}
