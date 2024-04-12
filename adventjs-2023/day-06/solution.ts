export function maxDistance(movements: string): number {
  const directionsCount = [...movements].reduce(
    (acc, curr) => {
      acc[curr]++;
      return acc;
    },
    { "<": 0, ">": 0, "*": 0 } as Record<string, number>
  );

  const [largerDirection, shorterDirection] =
    directionsCount["<"] > directionsCount[">"]
      ? [directionsCount["<"], directionsCount[">"]]
      : [directionsCount[">"], directionsCount["<"]];

  return largerDirection - shorterDirection + directionsCount["*"];
}
