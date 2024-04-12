import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { maxDistance } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 06", () => {
  const movements = ">>*<";
  const result = maxDistance(movements);
  assertEquals(result, 2);

  const movements2 = "<<<>";
  const result2 = maxDistance(movements2);
  assertEquals(result2, 2);

  const movements3 = ">***>";
  const result3 = maxDistance(movements3);
  assertEquals(result3, 5);
});
