import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { createChristmasTree } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 10", () => {
  const ornamets1 = "123";
  const height1 = 4;
  const result1 = createChristmasTree(ornamets1, height1);
  assertEquals(result1, "   1\n  2 3\n 1 2 3\n1 2 3 1\n   |\n");

  const ornamets2 = "*@o";
  const height2 = 3;
  const result2 = createChristmasTree(ornamets2, height2);
  assertEquals(result2, "  *\n @ o\n* @ o\n  |\n");
});
