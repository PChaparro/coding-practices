import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { decode } from "./solution.ts";

Deno.test("AdventJS 2023 - Day 04", () => {
  const original1 = "hola (odnum)";
  assertEquals(decode(original1), "hola mundo");

  const original2 = "(olleh) (dlrow)!";
  assertEquals(decode(original2), "hello world!");

  const original3 = "sa(u(cla)atn)s";
  assertEquals(decode(original3), "santaclaus");
});
