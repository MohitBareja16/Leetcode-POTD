# LeetCode POTD Repository Guidelines

This repository is dedicated to solving the daily **LeetCode Problem of the Day (POTD)**, documenting intuitive human-first explanations, visualizations, and clean implementations in **Python 3**, **Java**, and **C++**. Solutions are designed to be published directly to LeetCode Solutions and synced to GitHub to maintain a daily streak.

---

## 1. Directory & File Structure

### Daily POTD Naming Format
Each daily problem is housed in its own dedicated directory following the naming pattern:
```text
<Mon>-<Day>-<Question-Name>-<Type>/
```
- `<Mon>`: 3-letter month abbreviation (`Jan`, `Feb`, `Mar`, `Apr`, `May`, `Jun`, `Jul`, `Aug`, `Sep`, `Oct`, `Nov`, `Dec`)
- `<Day>`: 2-digit day of the month (`01` through `31`, or single/double digit e.g., `24`)
- `<Question-Name>`: Title-Cased or Kebab-Cased problem name (e.g., `Find-the-Length-of-the-Longest-Common-Prefix`)
- `<Type>`: Core algorithm / data structure tag (e.g., `Sliding-Window`, `Binary-Search`, `DP`, `Trie`, `Graph`, `Greedy`, `Two-Pointers`, `Monotonic-Stack`, `Tree`)

**Example:** `Sep-24-Find-the-Length-of-the-Longest-Common-Prefix-Trie/`

> **Note on Long-Term Organization**: 
> Initially, folders are created with the `<Mon>-<Day>-<Question-Name>-<Type>` naming convention for clear daily streak tracking. In the long run, the user plans to group or organize solutions strictly by **Question Type** (e.g., `Dynamic-Programming/`, `Sliding-Window/`, `Graphs/`) without year or month nesting. The root `README.md` should maintain both a Chronological Tracker and a Categorized by Topic index to facilitate this.

### Files Inside Each Problem Folder
```text
<Mon>-<Day>-<Question-Name>-<Type>/
├── README.md        # Comprehensive write-up (LeetCode post + GitHub explanation)
├── solution.py      # Idiomatic Python 3 solution
├── Solution.java    # Idiomatic Java solution
└── solution.cpp     # Idiomatic C++ solution
```

---

## 2. Daily Workflow & Interactive Collaboration

When working together on each daily POTD:

1. **User Shares Problem & Intuition**:
   - The user provides today's problem (title, link, or description) along with their human thought process or initial approach.
2. **Collaborative Refinement**:
   - We clarify edge cases, evaluate time/space tradeoffs, and refine the core intuition.
3. **Interactive Scaffolding & Generation**:
   - The agent creates the dedicated folder `<Mon>-<Day>-<Question-Name>-<Type>/` directly.
   - Generates the visual explanation (ASCII walkthrough/diagram).
   - Generates clean, idiomatic solutions with comments in `solution.py`, `Solution.java`, and `solution.cpp`.
   - Generates the polished `README.md` formatted for instant copy-pasting to LeetCode Solutions.
4. **Tracker & Git Commit**:
   - Updates the root `README.md` tracker table (and Topic index).
   - Provides the one-line `git add`, `git commit`, and `git push` commands.

---

## 3. LeetCode Solution Post Template (`README.md`)

Every `README.md` inside a problem folder should follow this standardized template:

```markdown
# [Problem Name] - [Topic / Category]

**Problem Link:** [LeetCode Problem](https://leetcode.com/problems/...)  
**Difficulty:** Easy | Medium | Hard  
**Date:** <Month> <Day>, <Year>  
**Topics:** `<Tag1>`, `<Tag2>`

---

## 💡 Intuition & Thought Process
> *Explain the problem in plain English. How do you naturally think about it before writing code? What is the core breakthrough or realization?*

---

## 📊 Visual Explanation & Walkthrough
*Include ASCII diagrams, array state traces, pointer visualizations, or recursion steps.*

Example Trace:
\`\`\`text
Input: nums = [1, 2, 3], target = ...
Step 1: [visual state]
Step 2: [visual state]
\`\`\`

---

## ⚙️ Approach
1. **Step 1**: ...
2. **Step 2**: ...
3. **Step 3**: ...

---

## ⏱️ Complexity Analysis
- **Time Complexity:** $O(...)$ — *Detailed justification (e.g., iterating through array of length $N$ with $O(1)$ operations).*
- **Space Complexity:** $O(...)$ — *Detailed justification (e.g., auxiliary hash set storing up to $N$ elements).*

---

## 💻 Code Implementations

### Python 3
\`\`\`python
class Solution:
    def solve(self, ...):
        # Implementation with concise comments
        pass
\`\`\`

### Java
\`\`\`java
class Solution {
    public ... solve(...) {
        // Implementation with concise comments
    }
}
\`\`\`

### C++
\`\`\`cpp
class Solution {
public:
    ... solve(...) {
        // Implementation with concise comments
    }
};
\`\`\`
```

---

## 4. Code Standards Across Languages

- **Python 3**:
  - Use type hints (`def method(self, nums: List[int]) -> int:`).
  - Idiomatic Python constructs (list comprehensions, `defaultdict`, `Counter` where appropriate).
  - PEP 8 naming and formatting.

- **Java**:
  - Class name `Solution`.
  - Import necessary collections (`java.util.*`).
  - Clear variable names, avoid raw types, handle potential overflows (`long` vs `int` if needed).

- **C++**:
  - Modern C++ style (C++17/20).
  - Include fast I/O setup when beneficial:
    ```cpp
    static const auto fast = []() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        return 0;
    }();
    ```
  - Use standard STL containers efficiently (`vector`, `unordered_map`, `string_view` where appropriate).

---

## 5. Git Commit Convention

For consistent daily streak commits:
- Commit message format:
  ```bash
  git commit -m "feat(potd): solve <Mon>-<Day> - <Question-Name> (<Type>)"
  ```
- Example:
  ```bash
  git commit -m "feat(potd): solve Sep-24 - Find the Length of the Longest Common Prefix (Trie)"
  ```
