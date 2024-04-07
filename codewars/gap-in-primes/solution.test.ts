import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import { getPrimes, gap } from "./solution.ts";

Deno.test("getPrimes function", () => {
  const primesBetween1and10 = getPrimes({ min: 1, max: 10 });
  assertEquals(primesBetween1and10, [2, 3, 5, 7]);

  const primesBetween1and100 = getPrimes({ min: 1, max: 100 });
  assertEquals(
    primesBetween1and100,
    [
      2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
      71, 73, 79, 83, 89, 97,
    ]
  );

  const primesBetween75and100 = getPrimes({ min: 75, max: 100 });
  assertEquals(primesBetween75and100, [79, 83, 89, 97]);
});

/**
 * Problem tests taken from: https://www.codewars.com/kata/561e9c843a2ef5a40c0000a4/train/typescript
 */
Deno.test("Problem tests", () => {
  assertEquals(gap(2, 100, 110), [101, 103]);
  assertEquals(gap(4, 100, 110), [103, 107]);
  assertEquals(gap(6, 100, 110), null);
  assertEquals(gap(8, 300, 400), [359, 367]);
  assertEquals(gap(10, 300, 400), [337, 347]);
});
