class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        seen = set()

        for r in range(9):
            for c in range(9):
                val = board[r][c]

                if val == ".":
                    continue

                row_tag = f"{val} in row {r}"
                col_tag = f"{val} in col {c}"
                box_tag = f"{val} in box {r // 3}-{c // 3}"

                if row_tag in seen or col_tag in seen or box_tag in seen:
                    return False

                seen.add(row_tag)
                seen.add(col_tag)
                seen.add(box_tag)

        return True