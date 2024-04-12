import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { adjustLights } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 09", () => {
  const lights1 = ["🟢", "🔴", "🟢", "🟢", "🟢"];
  const lights2 = ["🔴", "🔴", "🟢", "🟢", "🔴"];
  const lights3 = ["🟢", "🔴", "🟢", "🔴", "🟢"];
  const lights4 = ["🔴", "🔴", "🔴"];

  assertEquals(adjustLights(lights1), 1);
  assertEquals(adjustLights(lights2), 2);
  assertEquals(adjustLights(lights3), 0);
  assertEquals(adjustLights(lights4), 1);
});
