from ortools.sat.python import cp_model


def main(board_size: int) -> None:
    model = cp_model.CpModel()

    # Variables: queen in each column, value is the row
    queens = [model.NewIntVar(0, board_size - 1, f"x_{i}") for i in range(board_size)]

    # Constraints
    model.AddAllDifferent(queens)  # row uniqueness
    model.AddAllDifferent([queens[i] + i for i in range(board_size)])  # "/" diagonal
    model.AddAllDifferent([queens[i] - i for i in range(board_size)])  # "\" diagonal

    # Solve
    solver = cp_model.CpSolver()
    status = solver.Solve(model)
    ans = ""
    if status == cp_model.OPTIMAL or status == cp_model.FEASIBLE:
        ans += "YES\n"
        for r in range(board_size):
            for c in range(board_size):
                if solver.Value(queens[c]) == r:
                    ans += f"{r + 1} {c + 1}\n"
    else:
        ans= "NO"
    return ans


if __name__ == "__main__":
    import sys
    import marshal
    size = 80
    final = {}
    for i in range(1, 81):
        final[i] = main(i)
    import base64
    import gzip
    print(base64.b64encode(gzip.compress(marshal.dumps(final))))