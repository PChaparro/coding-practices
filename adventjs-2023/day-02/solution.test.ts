import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { manufacture } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 02", () => {
  const gifts1 = ["tren", "oso", "pelota"];
  const materials1 = "tronesa";
  assertEquals(manufacture(gifts1, materials1), ["tren", "oso"]);

  const gifts2 = ["juego", "puzzle"];
  const materials2 = "jlepuz";
  assertEquals(manufacture(gifts2, materials2), ["puzzle"]);

  const gifts3 = ["libro", "ps5"];
  const materials3 = "psli";
  assertEquals(manufacture(gifts3, materials3), []);
});
