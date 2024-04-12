export function adjustLights(lights: string[]): number {
  const lightsPositionsCount = lights.reduce(
    (acc, curr, idx) => {
      const currLight = curr as "🔴" | "🟢";
      const isEven = idx % 2 === 0;
      isEven ? acc[currLight].even++ : acc[currLight].odd++;

      return acc;
    },
    {
      "🔴": { even: 0, odd: 0 },
      "🟢": { even: 0, odd: 0 },
    }
  );

  const costToSetOddsRedAndEvensGreen =
    lightsPositionsCount["🔴"].even + lightsPositionsCount["🟢"].odd;

  const costToSetOddsGreenAndEvensRed =
    lightsPositionsCount["🔴"].odd + lightsPositionsCount["🟢"].even;

  return costToSetOddsRedAndEvensGreen > costToSetOddsGreenAndEvensRed
    ? costToSetOddsGreenAndEvensRed
    : costToSetOddsRedAndEvensGreen;
}

adjustLights(["🟢", "🔴", "🟢", "🟢", "🟢"]);
