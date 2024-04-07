import { assertEquals } from "https://deno.land/std@0.221.0/assert/mod.ts";
import {
  getAccumulatedSumFrom,
  getAccumulatedSumUntil,
  findEvenIndex,
} from "./solution.ts";

const arr = [1, 2, 3, 4, 3, 2, 1];
const sumsArr = [1, 3, 6, 10, 13, 15, 16];

Deno.test("getAccumulatedSumUntil function", () => {
  const assertAccumulatedSumUntil = ({
    index,
    expected,
  }: {
    index: number;
    expected: number;
  }) => {
    assertEquals(getAccumulatedSumUntil(sumsArr, index), expected);
  };

  assertAccumulatedSumUntil({ index: 0, expected: 0 });
  assertAccumulatedSumUntil({ index: 1, expected: 1 });
  assertAccumulatedSumUntil({ index: 2, expected: 3 });
  assertAccumulatedSumUntil({ index: 3, expected: 6 });
  assertAccumulatedSumUntil({ index: 4, expected: 10 });
  assertAccumulatedSumUntil({ index: 5, expected: 13 });
  assertAccumulatedSumUntil({ index: 6, expected: 15 });
});

Deno.test("getAccumulatedSumFrom function", () => {
  const assertAccumulatedSumFrom = ({
    index,
    expected,
  }: {
    index: number;
    expected: number;
  }) => {
    assertEquals(getAccumulatedSumFrom(sumsArr, index), expected);
  };

  assertAccumulatedSumFrom({ index: 0, expected: 15 });
  assertAccumulatedSumFrom({ index: 1, expected: 13 });
  assertAccumulatedSumFrom({ index: 2, expected: 10 });
  assertAccumulatedSumFrom({ index: 3, expected: 6 });
  assertAccumulatedSumFrom({ index: 4, expected: 3 });
  assertAccumulatedSumFrom({ index: 5, expected: 1 });
  assertAccumulatedSumFrom({ index: 6, expected: 0 });
});

/**
 * Problem tests taken from: https://www.codewars.com/kata/5679aa472b8f57fb8c000047/train/typescript
 */
Deno.test("findEvenIndex function", () => {
  const assertFindEvenIndex = ({
    arr,
    expected,
  }: {
    arr: number[];
    expected: number;
  }) => {
    assertEquals(findEvenIndex(arr), expected);
  };

  assertFindEvenIndex({ arr, expected: 3 });
  assertFindEvenIndex({ arr: [1, 100, 50, -51, 1, 1], expected: 1 });
  assertFindEvenIndex({ arr: [1, 2, 3, 4, 5, 6], expected: -1 });
  assertFindEvenIndex({ arr: [20, 10, 30, 10, 10, 15, 35], expected: 3 });
});
