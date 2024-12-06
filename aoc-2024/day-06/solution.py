from typing import List, Dict, Tuple
import re

FILE_NAME = "input.txt"

multiple_whitespaces_regex = re.compile(r"\s+")

map: List[List[str]] = []

SYMBOLS = {
    "GUARD": "^",
    "OBSTACLE": "#",
}

DIRECTIONS = {
    "UP": (0, -1),
    "DOWN": (0, 1),
    "LEFT": (-1, 0),
    "RIGHT": (1, 0),
}

NEXT_LOOKING_DIRECTION = {
    "UP": "RIGHT",
    "RIGHT": "DOWN",
    "DOWN": "LEFT",
    "LEFT": "UP",
}


# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        map_row = multiple_whitespaces_regex.sub(" ", rawLine.strip())
        map.append(list(map_row))


# Part 1
def predict_guard_path(
    map: List[List[str]],
):
    path: List[Tuple[int, int]] = []

    looking_direction = "UP"

    guard_position = get_guard_position(map)

    while True:
        path.append(guard_position)

        direction = DIRECTIONS[looking_direction]

        candidate_position = (
            guard_position[0] + direction[0],
            guard_position[1] + direction[1],
        )

        candidate_position_out_of_bounds = (
            candidate_position[1] < 0
            or candidate_position[1] >= len(map)
            or candidate_position[0] < 0
            or candidate_position[0] >= len(map[0])
        )

        if candidate_position_out_of_bounds:
            break

        has_obstacle = (
            map[candidate_position[1]][candidate_position[0]] == SYMBOLS["OBSTACLE"]
        )

        if has_obstacle:
            looking_direction = NEXT_LOOKING_DIRECTION[looking_direction]
        else:
            guard_position = candidate_position

    return path


def get_guard_position(map: List[List[str]]) -> Tuple[int, int]:
    for y, row in enumerate(map):
        for x, cell in enumerate(row):
            if cell == SYMBOLS["GUARD"]:
                return (x, y)


full_path = predict_guard_path(map)


def get_unique_positions(positions: List[Tuple[int, int]]) -> List[Tuple[int, int]]:
    return list(set(positions))


unique_positions = get_unique_positions(full_path)

print("The guard visited", len(unique_positions), "unique positions")


# Part 2
