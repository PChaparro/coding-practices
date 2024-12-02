from typing import List, Dict
import re

FILE_NAME = "input.txt"

DELTA_THRESHOLD = 3

multiple_whitespaces_regex = re.compile(r"\s+")

reports: List[List[str]] = []


# Read the content of the file
with open(FILE_NAME, "r") as file:
    for rawLine in file:
        report = multiple_whitespaces_regex.sub(" ", rawLine.strip())
        levels = report.split(" ")
        reports.append(levels)


# Check each of the reports
def count_safe_and_unsafe_reports(reports: List[List[str]]):
    unsafe_records = 0

    for report in reports:
        if not is_safe_report(report):
            unsafe_records += 1

    return {"unsafe": unsafe_records, "safe": len(reports) - unsafe_records}


def is_safe_report(report: List[str], tolerance: int = 0, removed: int = 0) -> bool:
    prev_delta = None

    for level_index in range(1, len(report)):
        level = int(report[level_index])
        prev_level = int(report[level_index - 1])

        delta = level - prev_level

        if (
            delta == 0  # Not increasing nor decreasing
            or (
                prev_delta is not None and prev_delta * delta < 0
            )  # From increasing to decreasing or vice versa
            or abs(delta) > DELTA_THRESHOLD  # Delta is greater than the threshold
        ):
            if removed >= tolerance:
                return False
            else:
                return is_safe_report(
                    report[: level_index - 1] + report[level_index:],
                    tolerance,
                    removed + 1,
                )

        prev_delta = delta

    return True


safe_and_unsafe_reports_count = count_safe_and_unsafe_reports(reports)

print(
    f"Safe reports: {safe_and_unsafe_reports_count['safe']}, Unsafe reports: {safe_and_unsafe_reports_count['unsafe']}"
)
