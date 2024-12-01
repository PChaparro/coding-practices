from typing import List, Dict
import re

FILE_NAME = "input.txt"

multiple_whitespaces_regex = re.compile(r"\s+")

first_group_locations = []
second_group_locations = []

# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        sanitizedLine = multiple_whitespaces_regex.sub(" ", rawLine.strip())

        [first_group_location, second_group_location] = sanitizedLine.split(" ")

        first_group_locations.append(int(first_group_location))
        second_group_locations.append(int(second_group_location))

# Sort the arrays
first_group_locations.sort()
second_group_locations.sort()


# Calculate the distances
def calculate_total_distance(
    first_group_locations: list[int], second_group_locations: List[int]
) -> int:
    total_distance = 0

    for i in range(len(first_group_locations)):
        total_distance += abs(first_group_locations[i] - second_group_locations[i])

    return total_distance


total_distance = calculate_total_distance(first_group_locations, second_group_locations)

print("Total distance is: {distance}".format(distance=total_distance))


# Calculate the similarity score
def calculate_similarity_score(
    first_group_locations: List[int], second_group_locations: List[int]
) -> int:
    similarity_score = 0
    appearances_in_second_group_list: Dict[int, int] = {}

    for location in second_group_locations:
        appearances_in_second_group_list[location] = (
            appearances_in_second_group_list.get(location, 0) + 1
        )

    for location in first_group_locations:
        similarity_score += location * appearances_in_second_group_list.get(location, 0)

    return similarity_score


similarity_score = calculate_similarity_score(
    first_group_locations, second_group_locations
)

print("Similarity score is: {score}".format(score=similarity_score))
