import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { findNaughtyStep } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 03", () => {
  const original1 = "abcd";
  const modified1 = "abcde";
  assertEquals(findNaughtyStep(original1, modified1), "e");

  const original2 = "stepfor";
  const modified2 = "stepor";
  assertEquals(findNaughtyStep(original2, modified2), "f");

  const original3 = "abcde";
  const modified3 = "abcde";
  assertEquals(findNaughtyStep(original3, modified3), "");
});
