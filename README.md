# 💻 Data Structures and Algorithms (DSA) in C

A comprehensive collection of **Data Structure and Algorithm** implementations written in the **C programming language**. This repository is designed to be a learning resource for students and professionals looking to understand the low-level, memory-centric details of DSA.

---

## ✨ Key Features

* **Pure C Implementation:** All structures are built from scratch using pointers and dynamic memory allocation (`malloc`, `free`, etc.) to provide a deep understanding of memory management.
* **Modular Code:** Each data structure and major algorithm is contained in separate, clean **`.c` and `.h` files** for easy integration and reuse.
* **Test Drivers:** Includes a `main` function in each directory to demonstrate the usage and functionality of the implemented code.
* **Complexity Analysis:** Clear documentation (in the README or code comments) detailing the **Time and Space Complexity** for core operations.

---

## 📂 Repository Structure

| Concepts | Description | Key Topics |
| :--- | :--- | :--- |
| `01_Arrays` | Operations on basic and dynamic arrays. | Dynamic resizing, 1D/2D arrays. |
| `02_LinkedLists` | All variations of the fundamental list structure. | **Singly, Doubly, Circular** Linked Lists. |
| `03_Stacks_Queues`| Implementations of LIFO and FIFO principles. | Stack (Array/List), Queue (Circular/Linear). |
| `04_Trees` | Hierarchical data structures and their traversals. | **Binary Search Trees (BST)**, Traversals (Inorder, Preorder, Postorder, Level Order). |
| `05_Heaps` | Priority-based tree structure. | **Min-Heap, Max-Heap**, Heapify, Priority Queue. |
| `06_Hashing` | Key-value storage and collision handling. | Hash Tables using **Separate Chaining** and **Open Addressing**. |
| `07_Graphs` | Implementations and fundamental search algorithms. | **Adjacency List/Matrix**, **BFS, DFS**. |

---

## 🛠️ How to Compile and Run

### Prerequisites

* A C compiler (e.g., GCC)
* Make utility (optional, but recommended for simplicity)

### Compilation Steps

1.  **Clone the repository:**
    ```bash
    git clone [https://github.com/YourUsername/RepoName.git](https://github.com/YourUsername/RepoName.git)
    cd RepoName
    ```

2.  **Compile an individual file (e.g., the Singly Linked List):**
    You can compile the specific example file using GCC:
    ```bash
    gcc 02_LinkedLists/singly_linked_list.c -o sll_test
    ```

3.  **Run the executable:**
    ```bash
    ./sll_test
    ```

> 💡 **Tip:** We recommend compiling and running one folder's example at a time to keep your workspace clean.

---

## 🤝 Contributing

Contributions are welcome! If you find a bug, have a more optimized implementation, or want to add a new data structure (like AVL Trees or Disjoint Sets), feel free to:

1.  **Fork** the repository.
2.  Create your feature branch (`git checkout -b feature/AmazingFeature`).
3.  Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4.  Push to the branch (`git push origin feature/AmazingFeature`).
5.  Open a **Pull Request**.

---

## 📜 License

This Repo is licensed under the **MIT License** - see the [LICENSE.md](LICENSE.md) file for details.
