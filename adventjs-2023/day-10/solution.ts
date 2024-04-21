export function createChristmasTree(ornaments: string, height: number): string {
  // Util function to get the ornaments in a cyclic way
  function* generateOrnament() {
    let currOrnamentIdx = 0;

    while (true) {
      yield ornaments.at(currOrnamentIdx);
      currOrnamentIdx = (currOrnamentIdx + 1) % ornaments.length;
    }
  }
  const ornamentsGenerator = generateOrnament();

  // Generate the leaves
  const leaves = new Array(height).fill("").map((_, idx) => {
    const currLvlOrnaments = new Array(idx + 1)
      .fill("")
      .map(() => ornamentsGenerator.next().value);

    const padding = " ".repeat(height - idx - 1);
    return padding + currLvlOrnaments.join(" ");
  });

  const trunkPadding = " ".repeat(height - 1);
  const trunk = `${trunkPadding}|\n`;
  return [...leaves, trunk].join("\n");
}
