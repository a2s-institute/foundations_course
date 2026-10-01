# Intuitive Linear Algebra

_Date: March 2026_

A series of interactive Jupyter notebooks covering core linear algebra topics with a visual, intuition-first approach. Designed as a refresher for robotics and engineering students.

## Notebooks

| #   | Notebook                        | Topics                                                                                   |
| --- | ------------------------------- | ---------------------------------------------------------------------------------------- |
| 1   | Vectors and Linear Combinations | Vectors as arrows, addition, scalar multiplication, span, basis, linear independence     |
| 2   | Matrices as Transformations     | 2D transformation visualization (grid + shapes), rotation, scaling, shearing, reflection |
| 3   | Solving Linear Systems          | Geometric interpretation, Gaussian elimination, condition number                         |
| 4   | Norms and Inner Products        | Lp norms, unit balls, inner product geometry, projections                                |
| 5   | Eigenvalues and Eigenvectors    | Intuitive eigendecomposition, 2D visualization, diagonalization                          |
| 6   | SVD Intuition and Applications  | SVD geometry, image compression, pseudo-inverse, PCA                                     |
| 7   | References and Resources        | Curated links to textbooks, videos, and interactive tools                                |

## Setup

```bash
# Install UV (if not already available)
curl -LsSf https://astral.sh/uv/install.sh | sh

# Install dependencies and create virtual environment
uv sync

# Open notebooks in your IDE/Jupyter and select the .venv kernel
```