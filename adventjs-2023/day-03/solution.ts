export function findNaughtyStep(original: string, modified: string): string {
  const [shortestPL, largestPL] =
    original.length > modified.length
      ? [modified, original]
      : [original, modified];

  return [...largestPL].find((s, i) => shortestPL[i] !== s) ?? "";
}
