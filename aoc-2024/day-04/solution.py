from typing import List, Dict, Tuple
import re

FILE_NAME = "input.txt"

multiple_whitespaces_regex = re.compile(r"\s+")

WORD_TO_SEARCH = "XMAS"

word_search: List[List[str]] = []

# seen: List[List[str]] = []


# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        sanitizedLine = multiple_whitespaces_regex.sub(" ", rawLine.strip())

        row = []

        for word in sanitizedLine:
            row.append(word)

        word_search.append(row)
        # seen.append(["." for _ in range(len(row))])


# Part 1
def count_word(word_search: List[List[str]], word: str) -> int:
    count = 0

    first_letter = word[0]

    for rowIndex in range(len(word_search)):
        row = word_search[rowIndex]

        for colIndex in range(len(row)):
            letter = row[colIndex]

            if letter == first_letter:
                count += search_vertical(word_search, word, (rowIndex, colIndex))
                count += search_horizontal(word_search, word, (rowIndex, colIndex))
                count += search_diagonal(word_search, word, (rowIndex, colIndex))

    return count


def search_vertical(
    word_search: List[List[str]], word: str, start_coords: Tuple[int, int]
) -> int:
    count = 0

    for row_direction in range(-1, 2, 2):
        letter_index = 0

        while True:
            next_row = start_coords[0] + letter_index * row_direction

            next_row_out_of_bounds = next_row < 0 or next_row >= len(word_search)

            word_index_out_of_bounds = letter_index >= len(word)

            if next_row_out_of_bounds or word_index_out_of_bounds:
                break

            letter_match = word[letter_index] == word_search[next_row][start_coords[1]]

            if not letter_match:
                break

            # seen[next_row][start_coords[1]] = word[letter_index]

            letter_index += 1

            if letter_index == len(word):
                count += 1
                break

    """ print(
        f"Searched for {word} vertically starting at {start_coords} and found {count} matches"
    ) """

    return count


def search_horizontal(
    word_search: List[List[str]], word: str, start_coords: Tuple[int, int]
) -> int:
    count = 0

    for col_direction in range(-1, 2, 2):
        letter_index = 0

        while True:
            next_col = start_coords[1] + letter_index * col_direction

            next_col_out_of_bounds = next_col < 0 or next_col >= len(word_search[0])

            word_index_out_of_bounds = letter_index >= len(word)

            if next_col_out_of_bounds or word_index_out_of_bounds:
                break

            letter_match = word[letter_index] == word_search[start_coords[0]][next_col]

            if not letter_match:
                break

            # seen[start_coords[0]][next_col] = word[letter_index]

            letter_index += 1

            if letter_index == len(word):
                count += 1
                break

    """ print(
        f"Searched for {word} horizontally starting at {start_coords} and found {count} matches"
    ) """

    return count


def search_diagonal(
    word_search: List[List[str]], word: str, start_coords: Tuple[int, int]
) -> int:
    count = 0

    for row_direction in range(-1, 2, 2):
        for col_direction in range(-1, 2, 2):
            letter_index = 0

            while True:
                next_row = start_coords[0] + letter_index * row_direction
                next_col = start_coords[1] + letter_index * col_direction

                next_row_out_of_bounds = next_row < 0 or next_row >= len(word_search)
                next_col_out_of_bounds = next_col < 0 or next_col >= len(word_search[0])

                word_index_out_of_bounds = letter_index >= len(word)

                if (
                    next_row_out_of_bounds
                    or next_col_out_of_bounds
                    or word_index_out_of_bounds
                ):
                    break

                letter_match = word[letter_index] == word_search[next_row][next_col]

                if not letter_match:
                    break

                # seen[next_row][next_col] = word[letter_index]

                letter_index += 1

                if letter_index == len(word):
                    count += 1
                    break

    """ print(
        f"Searched for {word} diagonally starting at {start_coords} and found {count} matches"
    ) """

    return count


count = count_word(word_search, WORD_TO_SEARCH)

print(f"Found {count} occurrences of the word {WORD_TO_SEARCH}")


# Part 2
