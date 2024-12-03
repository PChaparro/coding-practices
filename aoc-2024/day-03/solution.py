from typing import List, Dict
import re

FILE_NAME = "input.txt"

multiple_whitespaces_regex = re.compile(r"\s+")

corrupted_memory: str = ""


# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        corrupted_memory += multiple_whitespaces_regex.sub(" ", rawLine.strip())


# Part 1
def get_valid_instructions(
    corrupted_memory: str,
) -> List[str]:
    valid_mul_instruction_regex = re.compile(r"mul\(\d+\,\d+\)|don't\(\)|do\(\)")

    return re.findall(valid_mul_instruction_regex, corrupted_memory)


def get_valid_mul_instructions(
    corrupted_memory: str,
) -> List[str]:
    valid_mul_instruction_regex = re.compile(r"mul\(\d+\,\d+\)")

    return re.findall(valid_mul_instruction_regex, corrupted_memory)


def run_mul_instructions(
    instructions: List[str],
) -> List[int]:
    results = []

    enabled = True

    for instruction in instructions:
        if "don't" in instruction:
            enabled = False
        elif "do" in instruction:
            enabled = True
        elif "mul" in instruction:
            if enabled:
                values = re.findall(r"\d{1,3}", instruction)
                results.append(int(values[0]) * int(values[1]))

    return results


valid_mul_instructions = get_valid_mul_instructions(corrupted_memory)

executed_instructions = run_mul_instructions(valid_mul_instructions)

added_results = sum(executed_instructions)

print(f"Added results: {added_results}")


# Part 2
valid_instructions = get_valid_instructions(corrupted_memory)

executed_instructions = run_mul_instructions(valid_instructions)

added_results = sum(executed_instructions)

print(f"Added results: {added_results}")
