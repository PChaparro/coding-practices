import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { findFirstRepeated } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 01", () => {
  const giftIds = [2, 1, 3, 5, 3, 2];
  assertEquals(findFirstRepeated(giftIds), 3);

  const giftIds2 = [1, 2, 3, 4];
  assertEquals(findFirstRepeated(giftIds2), -1);

  const giftIds3 = [5, 1, 5, 1];
  assertEquals(findFirstRepeated(giftIds3), 5);
});
