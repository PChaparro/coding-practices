import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { cyberReindeer } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 05", () => {
  const road = "S..|...|..";
  const time = 10;
  const result = cyberReindeer(road, time);
  assertEquals(result, [
    "S..|...|..",
    ".S.|...|..",
    "..S|...|..",
    "..S|...|..",
    "..S|...|..",
    "...S...*..",
    "...*S..*..",
    "...*.S.*..",
    "...*..S*..",
    "...*...S..",
  ]);
});
