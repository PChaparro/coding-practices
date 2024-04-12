import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { organizeGifts } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 08", () => {
  const gifts = "76a11b";
  const result = organizeGifts(gifts);
  assertEquals(result, "[a]{a}{a}(aaaaaa){b}(b)");
});
