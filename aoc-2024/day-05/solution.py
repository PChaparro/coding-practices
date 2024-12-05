from typing import List, Dict, Tuple
import re

FILE_NAME = "input.txt"

multiple_whitespaces_regex = re.compile(r"\s+")

must_be_before_rules: Dict[int, List[int]] = {}

update_manuals: List[int] = []


# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        sanitizedLine = multiple_whitespaces_regex.sub(" ", rawLine.strip())

        is_rule = "|" in sanitizedLine
        is_manual = "," in sanitizedLine

        if is_rule:
            before, after = sanitizedLine.split("|")
            must_be_before_rules[int(after)] = must_be_before_rules.get(
                int(after), []
            ) + [int(before)]
        elif len(sanitizedLine) == 0:
            continue
        elif is_manual:
            update_manuals.append(list(map(int, sanitizedLine.split(","))))


# Part 1
def classify_update_manuals_by_order(
    must_be_before_rules: Dict[int, List[int]], update_manuals: List[int]
) -> List[int]:
    correctly_ordered_update_manuals = []
    unordered_update_manuals = []

    """
    Create a regex to match ALL PAGES that must be before a given page. This 
    should offer a performance improvement over checking each page individually.
    """
    must_be_before_rules_regex = generate_regex_for_before_rules(must_be_before_rules)

    for manual in update_manuals:
        is_correctly_ordered = True

        """
        For each page in the manual, check if the pages that must be before it
        are actually before it.
        """
        for page_index in range(len(manual)):
            page = manual[page_index]

            next_pages = manual[page_index + 1 :]

            if page in must_be_before_rules:
                """
                Convert the list of pages that must be before the current page
                to a string to be able to use the regex.
                """
                next_pages_str = ",".join(map(str, next_pages))

                if must_be_before_rules_regex[page].search(next_pages_str):
                    is_correctly_ordered = False
                    break

        if is_correctly_ordered:
            correctly_ordered_update_manuals.append(manual)
        else:
            unordered_update_manuals.append(manual)

    return {
        "ordered": correctly_ordered_update_manuals,
        "unordered": unordered_update_manuals,
    }


def generate_regex_for_before_rules(
    must_be_before_rules: Dict[int, List[int]]
) -> Dict[int, re.Pattern]:
    return {
        after: re.compile("|".join(map(str, before)))
        for after, before in must_be_before_rules.items()
    }


def get_middle_pages(
    update_manuals: List[int],
):
    return list(map(lambda manual: manual[len(manual) // 2], update_manuals))


# Classify update manuals by order
classified_update_manuals = classify_update_manuals_by_order(
    must_be_before_rules, update_manuals
)

correctly_ordered_update_manuals = classified_update_manuals["ordered"]

unordered_update_manuals = classified_update_manuals["unordered"]

# Obtain and sum the middle pages of the correctly ordered update manuals
middle_page = get_middle_pages(correctly_ordered_update_manuals)

middle_page_sum = sum(middle_page)

print(f"Middle page sum: {middle_page_sum}")


# Part 2
