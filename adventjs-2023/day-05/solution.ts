export function cyberReindeer(road: string, time: number): string[] {
  const movementFrames = [road];

  // Constants
  const ROAD_CHARS = {
      ROAD: ".",
      SANTA_SLED: "S",
      BARRIER: "|",
      OPEN_BARRIER: "*",
    },
    TIME_TO_OPEN_BARRIERS = 5;

  // Aux vars
  const initialSantaPos = road.indexOf(ROAD_CHARS.SANTA_SLED)!;

  let currentSantaPos = initialSantaPos,
    currentTick = 1,
    previousItemWasBarrier = false;

  while (currentTick < time) {
    if (currentTick === TIME_TO_OPEN_BARRIERS) {
      road = road.replaceAll(ROAD_CHARS.BARRIER, ROAD_CHARS.OPEN_BARRIER);
    }

    const canMove = road[currentSantaPos + 1] !== ROAD_CHARS.BARRIER;

    if (canMove) {
      const newSantaPosition = currentSantaPos + 1;

      // Check if the previous item was a barrier or a normal road
      const itemToReplaceSanta = previousItemWasBarrier
        ? ROAD_CHARS.OPEN_BARRIER
        : ROAD_CHARS.ROAD;

      // Update the flag according to the new position for the next iteration
      previousItemWasBarrier =
        road[newSantaPosition] === ROAD_CHARS.OPEN_BARRIER;

      const updatedRoad = [...road];
      updatedRoad[currentSantaPos] = itemToReplaceSanta;
      updatedRoad[newSantaPosition] = ROAD_CHARS.SANTA_SLED;

      road = updatedRoad.join("");
      currentSantaPos = newSantaPosition;
    }

    movementFrames.push(road);
    currentTick++;
  }

  return movementFrames;
}
