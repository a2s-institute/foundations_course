# Linear Algebra in Robotics — Examples and Use Cases

This document maps each topic and subtopic from the
[Intro to Linear Algebra notebooks](notebooks/) to concrete examples drawn
from modern robotics: manipulators, mobile robots, drones, humanoids, surgical
systems, autonomous vehicles, and more.

---

## 1 — Vectors and Linear Combinations

### 1.1 What Is a Vector?

| Concept | Robotics example |
|---|---|
| Position vector | A 6-DOF manipulator's **end-effector pose** is stored as a vector `(x, y, z, φ, θ, ψ)`. Every motion-planning query starts by encoding "where is the robot?" as a vector in configuration space. |
| Velocity vector | Drone flight controllers represent the quadrotor's velocity as `v = (vx, vy, vz)` in the body or world frame. PX4 and ArduPilot both propagate this vector through their EKF pipelines. |
| Force / torque vector | In collaborative robots (cobots) like the KUKA iiwa, a 6-axis force-torque sensor at the wrist reports `w = (fx, fy, fz, τx, τy, τz)`, a wrench vector used for impedance control. |

### 1.2 Vector Addition — Parallelogram Rule

| Concept | Robotics example |
|---|---|
| Superposition of forces | When a Boston Dynamics Spot robot pushes a door, the net force on the foot is the vector sum of the actuator force, gravity, and ground-reaction force. Controllers add these vectors (parallelogram rule) to compute the resultant. |
| Velocity composition | An AGV (Automated Guided Vehicle) driving on a moving conveyor belt has a world-frame velocity `v_world = v_robot + v_belt`. Warehouse logistics systems (Amazon Kiva/Proteus) perform this addition in real time. |
| Sensor fusion of displacements | Visual-inertial odometry (VIO) in AR headsets and drones adds the displacement estimated by the camera to the displacement from the IMU, correcting drift through vector addition in a filter. |

### 1.3 Scalar Multiplication

| Concept | Robotics example |
|---|---|
| Speed scaling | Industrial robots (e.g., ABB IRB series) expose a *speed override* slider (0–100 %). Internally this multiplies the planned joint-velocity vector by a scalar `α ∈ [0, 1]`, slowing the entire trajectory uniformly. |
| Thrust scaling | A quadrotor's thrust command is a scalar multiple of the unit body-z vector: `f = T · ẑ_B`. Increasing `T` scales the vector, making the drone ascend faster. |
| Gain tuning | PID controllers multiply the error vector by scalar gains `Kp, Ki, Kd`. Tuning these scalars stretches or shrinks the corrective action applied to each joint. |

### 1.4 Linear Combinations

| Concept | Robotics example |
|---|---|
| Trajectory blending | In motion planning, a smooth path between waypoints can be expressed as a linear combination of basis trajectories (e.g., Dynamic Movement Primitives — DMPs). A humanoid robot learns to pour water by blending demonstrated trajectories: `ξ = w₁·ξ₁ + w₂·ξ₂`. |
| Weighted sensor fusion | A self-driving car's Kalman filter produces an estimated state that is a weighted linear combination of the GPS measurement and the IMU prediction: `x̂ = K·z_GPS + (I − K)·x̂_pred`. |
| Robot swarm formation | In multi-robot formation control, a follower robot's desired position is a linear combination of leader positions: `p_follower = α₁·p₁ + α₂·p₂` with `α₁ + α₂ = 1`, placing it on the line segment between two leaders. |

### 1.5 Span

| Concept | Robotics example |
|---|---|
| Reachable workspace | The span of joint-velocity vectors (columns of the Jacobian) defines the set of end-effector velocities the robot can achieve at a given configuration. If the span loses a dimension, the robot is at a **kinematic singularity**. |
| Controllability of a mobile robot | A differential-drive robot (e.g., TurtleBot) has two control inputs (left/right wheel speeds). The span of the resulting velocity vectors is a 2D subspace of the 3D pose space `(x, y, θ)`. Through Lie brackets, the span extends to the full space — the robot is controllable but nonholonomic. |

### 1.6 Basis and Linear Independence

| Concept | Robotics example |
|---|---|
| Coordinate frames | Every link of a robot arm is assigned a local coordinate frame with a standard basis `(x̂, ŷ, ẑ)`. The Denavit-Hartenberg (DH) convention prescribes how to attach these bases so each frame is linearly independent from the others. |
| Redundancy detection | A 7-DOF robot arm (e.g., Franka Emika Panda) is kinematically **redundant** for a 6-DOF task. The extra column in the Jacobian is linearly dependent on the task-space directions, yielding a 1D **null space** used for secondary objectives like joint-limit avoidance. |
| IMU axis alignment | A MEMS IMU measures acceleration along three orthogonal (linearly independent) axes. If two axes were parallel (dependent), no rotation could separate their readings, and the sensor would lose a degree of information. |

### 1.7 Extension to 3D

| Concept | Robotics example |
|---|---|
| Spatial manipulators | All industrial 6-DOF arms (Fanuc, KUKA, UR) operate in ℝ³. Position, orientation, and their time derivatives are all 3D vectors or members of SO(3). |
| 3D LiDAR point clouds | A Velodyne or Ouster LiDAR on a self-driving car returns millions of 3D points `(x, y, z)`. Algorithms like ICP (Iterative Closest Point) align two point clouds by finding the best rigid transformation in ℝ³. |
| Drone navigation | A drone planning a delivery path (e.g., Wing, Amazon Prime Air) works in full 3D airspace. Waypoints, obstacles, and no-fly zones are all described by 3D vectors and their spans. |

---

## 2 — Matrices as Linear Transformations

### 2.1 / 2.2 Matrix–Vector Product and Scene Geometry

| Concept | Robotics example |
|---|---|
| Homogeneous transformation | Forward kinematics multiplies a sequence of 4×4 matrices `T₀¹ · T₁² · … · Tₙ₋₁ⁿ` by the tool-tip position vector to get the end-effector pose in the base frame. This is the core calculation every robot controller performs at kHz rates. |
| Camera projection | A pinhole camera model projects a 3D world point to a 2D pixel via `p_2D = K · [R | t] · P_3D`, a matrix–vector product. Vision-guided bin-picking systems (e.g., Photoneo, Zivid) rely on this at every frame. |

### 2.4.1 Rotation

| Concept | Robotics example |
|---|---|
| SO(3) rotation matrices | Every joint of a robotic arm contributes a rotation. The orientation of the end-effector is represented as `R ∈ SO(3)`, a 3×3 orthogonal matrix with `det(R) = 1`. The Modern Robotics textbook (Lynch & Park) builds all kinematics on this. |
| Drone attitude control | Quadrotor autopilots (PX4, Betaflight) represent the vehicle's attitude as a rotation matrix (or its quaternion equivalent). The attitude controller computes the error rotation `Rₑ = Rᵈᵀ · R` and extracts angular-velocity corrections. |
| SLAM map alignment | When a robot revisits an area (loop closure), the ICP algorithm finds the rotation matrix that best aligns the old and new LiDAR scans, minimising point-to-point distance. |

### 2.4.2 Scaling

| Concept | Robotics example |
|---|---|
| Sensor calibration | A depth camera's raw disparity map is converted to metric depth by multiplying each pixel value by a scalar (or diagonal scaling matrix). Intel RealSense and Stereolabs ZED cameras apply this during their calibration pipeline. |
| Joint-space scaling | Non-uniform scaling matrices map between joint-space and task-space units. A robot with one prismatic joint (metres) and one revolute joint (radians) uses a diagonal weighting matrix so that optimisation treats both consistently. |

### 2.4.3 Shearing

| Concept | Robotics example |
|---|---|
| Soft-robot deformation modelling | Continuum robots (e.g., surgical snake-arm endoscopes) undergo shear deformations. Finite-element models approximate local deformation with shear matrices to predict the tip pose from actuator inputs. |
| Terrain-induced skid | A tracked robot on loose soil experiences lateral skid modelled as a shear: the actual displacement matrix has off-diagonal terms relative to the commanded motion. Skid-steer models explicitly include these terms. |

### 2.4.4 Reflection

| Concept | Robotics example |
|---|---|
| Mirror-image tool paths | In dual-arm manipulation (e.g., Baxter, YuMi), one arm's trajectory can be mirrored for the other by applying a reflection matrix across the sagittal plane, enabling symmetric tasks like folding laundry. |
| Chirality handling in assembly | Some parts are left-handed or right-handed. A vision system detects chirality by checking whether the transformation from a template includes a reflection (`det = −1`) and signals the robot to pick the correct variant. |

### 2.4.5 Projection

| Concept | Robotics example |
|---|---|
| Perspective projection | A robot vision system projects 3D objects onto a 2D image plane using a projection matrix. This is how pick-and-place systems localise objects from camera images. |
| Null-space projection | Redundant manipulators project secondary tasks (e.g., joint-limit avoidance, obstacle avoidance) into the **null space** of the primary task Jacobian using the projector `N = I − J⁺J`. This is standard practice on 7-DOF arms like the KUKA iiwa and Franka Panda. |
| Ground-plane projection | Autonomous vehicles project 3D LiDAR points onto a 2D bird's-eye-view (BEV) grid via an orthographic projection matrix. BEV maps are a popular representation in modern self-driving perception stacks (e.g., BEVFormer). |

### 2.5 Composition of Transformations

| Concept | Robotics example |
|---|---|
| Kinematic chain | A 6-DOF arm's forward kinematics is the composition `T = T₁·T₂·T₃·T₄·T₅·T₆`. Changing the order changes the result — this non-commutativity is why DH parameter conventions exist. |
| Hand-eye calibration | The classic `AX = XB` problem composes the robot base-to-hand transform with the camera-to-target transform. Solving for the unknown hand-eye transform `X` is a matrix equation arising from composing four rigid transformations. |
| Multi-sensor extrinsics | Self-driving cars (Waymo, Cruise) chain transforms: LiDAR → vehicle body → world. Each link is a 4×4 matrix; the composition gives every LiDAR point in global coordinates. |

### 2.6 Determinant as Area / Volume Factor

| Concept | Robotics example |
|---|---|
| Singularity detection | When `det(J) = 0` (or near zero), the manipulator Jacobian is singular — the robot loses a degree of freedom in task space. Industrial controllers monitor `|det(J)|` and slow down or halt the robot near singularities. |
| Grasp quality metric | The **grasp wrench space** volume, related to a determinant, quantifies how well a multi-fingered hand can resist external disturbances. A larger determinant means the grasp is more robust. |

### 2.7 Matrix Columns = Where the Basis Goes

| Concept | Robotics example |
|---|---|
| Jacobian column interpretation | Each column of the manipulator Jacobian is the end-effector velocity produced by a unit velocity at the corresponding joint (with all others at zero). This column-by-column view is how engineers diagnose which joints contribute to which task-space directions. |
| Rotation matrix columns | The columns of a rotation matrix are the unit vectors of the rotated frame expressed in the original frame. When a UR5 arm reports its tool orientation as a 3×3 matrix, each column tells you where the tool's x, y, z axes point in the world. |

---

## 3 — Solving Linear Systems

### 3.1 Geometric Interpretation

| Concept | Robotics example |
|---|---|
| Intersection of constraint planes | Inverse kinematics for a 3-DOF planar arm requires solving three nonlinear equations. After linearisation (Newton-Raphson), each iteration solves a linear system whose geometric interpretation is the intersection of planes in joint space. |
| No-solution case (parallel lines / planes) | A 2-DOF arm asked to reach a point beyond its workspace leads to an inconsistent linear system — the constraint lines do not intersect. Trajectory planners detect this and report "target unreachable." |

### 3.2 Gaussian Elimination

| Concept | Robotics example |
|---|---|
| Real-time inverse dynamics | The **Articulated Body Algorithm** (Featherstone) solves a linear system `H·q̈ = τ − C` at every control cycle. Internally it performs forward/backward sweeps analogous to Gaussian elimination on the mass matrix `H`. |
| Sparse linear solvers in SLAM | Graph-based SLAM (g2o, GTSAM) solves large sparse linear systems at each optimisation step. The sparsity pattern reflects which landmarks are visible from which poses; Cholesky factorisation (a structured form of Gaussian elimination) exploits this sparsity. |

### 3.3 Condition Number — Sensitivity to Perturbations

| Concept | Robotics example |
|---|---|
| Manipulability index | The condition number of the Jacobian `κ(J) = σ_max / σ_min` measures how uniformly the robot can move in all task-space directions. A high `κ` means the robot is near a singularity — small joint motions produce wildly different end-effector motions. Yoshikawa's **manipulability ellipsoid** visualises this. |
| Ill-conditioned calibration | Hand-eye calibration or camera intrinsic calibration can be ill-conditioned if the calibration poses lack diversity. A high condition number of the measurement matrix warns the engineer to add more varied poses. |
| Sensitivity of localisation | In GPS-denied environments, a robot triangulates its position from beacon ranges. If the beacons are nearly collinear, the system matrix is ill-conditioned and the position estimate swings wildly with small range errors — the geometric equivalent of nearly-parallel lines. |

### 3.4 Extension to 3D — Planes and Intersections

| Concept | Robotics example |
|---|---|
| Multi-plane intersection for object pose | A bin-picking system detects three dominant planes (e.g., faces of a box) in a point cloud. The object's corner is the unique intersection of three planes — a 3×3 linear system. |
| Force balance in multi-contact | A humanoid robot standing on two feet has contact forces at each foot; the Newton-Euler equations for the whole body form a 3D linear system whose solution gives the ground-reaction forces. |

---

## 4 — Norms and Inner Products

### 4.1 Vector Norms

| Norm | Robotics example |
|---|---|
| L² (Euclidean) | Path length in Cartesian space: the most common distance metric in motion planning (RRT, PRM). "How far is the end-effector from the target?" is answered by `‖p_ee − p_target‖₂`. |
| L¹ (Manhattan) | Joint-space cost for a robot that moves one joint at a time (decoupled control). Grid-based planners on warehouse robots sometimes use L¹ distance because the robot travels along aisles (axis-aligned). |
| L∞ (Chebyshev) | **Synchronised multi-axis motion**: the time to complete a multi-joint move is determined by the slowest joint, i.e., `‖Δq / q̇_max‖∞`. Industrial robots use this to plan time-optimal point-to-point motions. |

### 4.2 Unit Balls — Geometry of Norms

| Concept | Robotics example |
|---|---|
| L² unit ball → sphere | Collision checking inflates a robot link to a bounding sphere (radius = 1 in normalised coordinates). The L² ball is the natural "safety bubble" shape. |
| L∞ unit ball → cube | Occupancy grids in SLAM (e.g., OctoMap) use axis-aligned voxels — essentially L∞ balls. Checking if a point lies inside a voxel is a max-norm test. |
| L¹ unit ball → diamond | Some trajectory-optimisation formulations penalise control effort with L¹ norm (promoting sparsity / bang-bang control). The diamond-shaped feasible set encourages solutions that activate only one actuator at a time. |

### 4.3 Inner Product — Angles Between Vectors

| Concept | Robotics example |
|---|---|
| Alignment for obstacle avoidance | A robot's velocity vector **v** is compared to the direction toward an obstacle **d** via `cos θ = v·d / (‖v‖·‖d‖)`. If `cos θ ≈ 1`, the robot is heading straight toward the obstacle and must steer away. Potential-field methods use this angle check. |
| Surface-normal estimation | From a point cloud, a robot estimates the surface normal at each point (via PCA on neighbours). The dot product between the normal and the approach direction tells a grasping system whether the surface is facing the gripper. |
| Feature matching in visual SLAM | ORB-SLAM computes the angle (via dot product of normalised descriptors) between feature vectors to decide whether two keypoints match across frames. |

### 4.4 Projection

| Concept | Robotics example |
|---|---|
| Force projection onto a surface | When a robot polishing a surface applies a force **f**, the useful component is the projection onto the surface normal: `proj_n̂(f)`. Hybrid force-position controllers (Raibert & Craig) decompose forces this way. |
| Least-squares fitting | A mobile robot fits a line to 2D LiDAR hits on a wall. Each point is projected onto the best-fit line; the orthogonal residuals are minimised. This is how Hector SLAM detects and tracks walls. |
| Null-space velocity projection | In redundant-arm control, the desired joint velocity is decomposed into the task-space component `J⁺·ẋ` and the null-space component (projection onto the null space of `J`). Secondary objectives are projected through `(I − J⁺J)`. |

### 4.5 Matrix Norms (Preview)

| Concept | Robotics example |
|---|---|
| Spectral norm = σ_max | The spectral norm of the Jacobian gives the maximum end-effector speed per unit joint speed. It is the longest axis of the manipulability ellipsoid. |
| Frobenius norm | In visual odometry, the Frobenius norm of the reprojection-error Jacobian is used to weight residuals in a Levenberg-Marquardt solver (ceres-solver, g2o). |
| Gain bound for controllers | For a linear state-feedback controller `u = −Kx`, the spectral norm `‖K‖₂` bounds the maximum control effort. This is checked to avoid actuator saturation in real hardware (e.g., torque limits on a Franka arm). |

---

## 5 — Eigenvalues and Eigenvectors

### 5.1 Visualising the Eigenvector Property

| Concept | Robotics example |
|---|---|
| Principal axes of the inertia tensor | The eigenvectors of a rigid body's inertia matrix `I` are the **principal axes** around which the body can rotate without wobble. Satellite attitude controllers (reaction wheels) align torques with these axes for efficient de-tumbling. |
| Dominant vibration mode | A flexible-link robot arm vibrates after a sudden stop. The eigenvector of the stiffness matrix associated with the lowest eigenvalue gives the dominant vibration mode shape — the direction in which the tip oscillates most. |

### 5.2 Interactive Eigenvector Explorer (applied)

| Concept | Robotics example |
|---|---|
| Stiffness ellipsoid | A compliant robot end-effector (e.g., in a surgical robot) has a stiffness matrix `K`. Its eigenvectors and eigenvalues define a **stiffness ellipsoid**: directions where the arm is stiff vs. compliant. Surgeons configure this so the arm is stiff along the cutting axis and compliant laterally (for safety). |

### 5.3 Eigenvalues and Transformation Types

| Eigenvalue pattern | Robotics example |
|---|---|
| All eigenvalues with `|λ| < 1` (stable) | A discrete-time LQR controller for a balancing robot (Segway, Unitree Go2 standing) places all closed-loop eigenvalues inside the unit circle, guaranteeing stability. |
| Complex eigenvalues | A PD-controlled joint exhibits oscillatory behaviour (underdamped) when the closed-loop eigenvalues have nonzero imaginary parts. Increasing derivative gain moves them toward the real axis, reducing oscillation. |
| Zero eigenvalue | In formation control, the graph Laplacian's zero eigenvalue (and its eigenvector **1**) corresponds to a rigid translation of the entire swarm — a motion that preserves formation shape. |
| Eigenvalue = 1 (projection) | A projection onto the task-space of a redundant arm has eigenvalue 1 for task-space directions and 0 for null-space directions, cleanly separating primary and secondary objectives. |

### 5.4 Diagonalisation and Matrix Powers

| Concept | Robotics example |
|---|---|
| Decoupled modal dynamics | A multi-DOF vibrating system `M·q̈ + K·q = 0` diagonalises into independent oscillators via eigenvectors of `M⁻¹K`. Each mode can be damped independently — this is how active vibration suppression works on long-reach space manipulators (Canadarm2). |
| Discrete-time state propagation | A linear state-space model `x_{k+1} = A·x_k` is efficiently computed via `Aᵏ = V·Λᵏ·V⁻¹`. Kalman filters for inertial navigation (e.g., on Mars rovers) exploit diagonalisation to propagate uncertainty covariance efficiently. |
| PageRank-style consensus | In a multi-robot network, the consensus protocol converges at a rate determined by the second-largest eigenvalue of the adjacency matrix. The power-iteration view (`Aᵏ`) explains how information diffuses through the swarm over time. |

### 5.5 Characteristic Polynomial / Trace / Determinant

| Concept | Robotics example |
|---|---|
| Stability via characteristic polynomial | The characteristic polynomial of the system matrix `det(A − λI) = 0` determines the poles of a robot's closed-loop transfer function. Control engineers (e.g., designing a PID for a UR5 joint) use Routh-Hurwitz criteria on this polynomial to verify stability without computing eigenvalues explicitly. |
| Trace as sum of eigenvalues | In covariance-based localisation (EKF-SLAM), the trace of the position covariance matrix equals the sum of its eigenvalues and measures overall uncertainty. Exploration planners drive the robot to configurations that minimise this trace ("A-optimal" design). |

---

## 6 — SVD: Intuition and Applications

### 6.1 SVD Geometry — Rotate, Scale, Rotate

| Concept | Robotics example |
|---|---|
| Manipulability ellipsoid | The SVD of the Jacobian `J = UΣVᵀ` maps the unit ball of joint velocities to an ellipsoid of end-effector velocities. The columns of `U` give the ellipsoid axes in task space; the singular values `σᵢ` give the semi-axis lengths. A **sphere-like** ellipsoid (all `σᵢ` similar) means the robot can move equally well in all directions — a desirable property for surgical and collaborative robots. |
| Image of the unit circle under a transform | In drone dynamics, applying an aerodynamic coupling matrix to all unit rotor-speed combinations traces an ellipsoid of achievable force/torque — the SVD reveals which combinations are most and least effective. |

### 6.2 Singular Values, Eigenvalues, and the Connection

| Concept | Robotics example |
|---|---|
| σ_min as distance to singularity | Robot controllers monitor the minimum singular value of the Jacobian. When `σ_min → 0`, the robot approaches a kinematic singularity. Damped least-squares (Levenberg-Marquardt IK) adds `λ²` to `σᵢ²` to prevent blow-up near singularities — this is standard on arms like the Franka Panda. |
| σᵢ² as eigenvalues of JᵀJ | In optimal experiment design for robot calibration, the eigenvalues of the Fisher Information Matrix (`∝ JᵀJ`) indicate which calibration parameters are well-determined. This guides where to place calibration targets. |

### 6.3 Low-Rank Approximation

| Concept | Robotics example |
|---|---|
| Map compression | A robot building an occupancy grid in a large warehouse may store a 10,000 × 10,000 map. A low-rank SVD approximation (rank 50–100) compresses this dramatically while preserving corridor structure, enabling faster path planning on memory-limited embedded systems. |
| Point-cloud denoising | Taking the top-k singular values of a matrix of stacked point-cloud patches removes sensor noise while preserving geometric features — used as a pre-processing step for 3D object recognition in warehouse robots. |
| Gait library compression | A humanoid robot stores hundreds of walking gaits as columns of a matrix. The rank-k approximation captures the k most important motion synergies; new gaits are generated as linear combinations of these, reducing storage and computation (used in Atlas locomotion research). |

### 6.4 Pseudo-Inverse and Least Squares

| Concept | Robotics example |
|---|---|
| Redundant manipulator IK | A 7-DOF arm solving for a 6-DOF task uses the Moore-Penrose pseudo-inverse `J⁺` to find the minimum-norm joint velocity: `q̇ = J⁺·ẋ`. This is the default resolved-rate controller in ROS MoveIt for redundant arms. |
| Overdetermined calibration | Robot-world/hand-eye calibration collects many pose pairs (overdetermined system). The pseudo-inverse gives the least-squares estimate of the unknown transform, minimising overall calibration error. Implemented in OpenCV's `calibrateHandEye`. |
| Line/plane fitting for navigation | A mobile robot fits a line to LiDAR points on a wall using least squares (`A⁺·b`). The result is the wall's position and orientation, used for wall-following behaviour. |

### 6.5 PCA — Principal Component Analysis

| Concept | Robotics example |
|---|---|
| Gait analysis | Researchers record joint-angle trajectories of a bipedal robot (e.g., Cassie, Digit) during walking. PCA on the trajectory matrix reveals that 2–3 principal components capture >95 % of the variance — these are the dominant locomotion synergies. Controllers can operate in this low-dimensional space for faster optimisation. |
| Dimensionality reduction for grasping | A robot hand with 16 joints (e.g., Shadow Dexterous Hand) has a 16-dimensional configuration space. PCA on a database of human grasps shows that most grasps lie in a 2–3D subspace (the "eigengrasp" space). Planning in eigengrasp space is orders of magnitude faster. |
| Anomaly detection | A manufacturing robot's motor-current signals are projected onto principal components learned during normal operation. A large residual (projection error) signals an anomaly — bearing wear, collision, or payload change. This is a common predictive-maintenance technique in Industry 4.0. |

### 6.6 Non-Square Matrices

| Concept | Robotics example |
|---|---|
| Tall matrix (more equations than unknowns) | An over-constrained sensor system: 10 range sensors estimate a 3D position → a 10 × 3 matrix. The SVD-based pseudo-inverse gives the least-squares solution. This arises in ultra-wideband (UWB) indoor localisation for drones. |
| Wide matrix (more unknowns than equations) | A 7-DOF arm tracking a 3-DOF position target → a 3 × 7 Jacobian (wide). The SVD reveals a 4D null space of joint velocities that don't move the end-effector. The robot exploits this freedom for self-motion (elbow repositioning, cable management). |
| Rank deficiency | If a 6×6 Jacobian has rank 5, the SVD isolates the lost direction (the singular vector with `σ₆ ≈ 0`). The robot cannot move in that task-space direction — e.g., a SCARA arm at full extension cannot move radially outward. |

---

## Quick Reference — Topic-to-Robot Mapping

| Notebook | Key linear algebra concept | Flagship robotics application |
|---|---|---|
| 01 Vectors | Linear combination, span, basis | Trajectory blending (DMPs), workspace reachability, sensor fusion |
| 02 Matrices | Rotation, composition, determinant | Forward kinematics (DH), singularity detection, camera projection |
| 03 Systems | Gaussian elimination, condition number | Inverse dynamics (Featherstone), SLAM solvers, manipulability index |
| 04 Norms | Lᵖ norms, projection, inner product | Path cost metrics, force decomposition, obstacle-avoidance angles |
| 05 Eigen | Diagonalisation, stability, modal analysis | LQR stability, principal axes of inertia, vibration suppression |
| 06 SVD | Pseudo-inverse, PCA, low-rank approx. | Redundant-arm IK, eigengrasp planning, map compression |

---

*Generated as a companion to the [Intro to Linear Algebra](notebooks/) notebook series.*
