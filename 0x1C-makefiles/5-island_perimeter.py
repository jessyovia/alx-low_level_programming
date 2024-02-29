# 5-island_perimeter.py
#!/usr/bin/python3
"""
Calculates the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculates the perimeter of an island in a grid.

    Args:
        grid (list): A list of lists of integers representing the grid.

    Returns:
        int: The perimeter of the island.

    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2
    return perimeter
