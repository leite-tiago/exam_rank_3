# 📘 42 Exam Rank 3

This repository contains preparation material and solutions related to the 42 School Exam Rank 3. The exam typically includes one of two main exercises:

* `get_next_line` (GNL)
* `ft_printf`

---

## 🧪 Exam Format

During the exam, you will be assigned one of the two projects at random. You must implement the project from scratch within the time limit. No external libraries are allowed (except `unistd.h`, `stdlib.h`, etc., as permitted by the project specifications).

---

## 📂 Repository Structure

```
exam_rank_3/
├── get_next_line/         # Source code and headers for get_next_line
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
│
├── ft_printf/             # Source code and headers for ft_printf
│   ├── ft_printf.c
│   ├── ft_utils.c
│   └── ft_printf.h
│
└── README.md              # Project documentation
```

---

## 📌 Key Concepts Practiced

### get\_next\_line

* File descriptor management
* Static variables for persistent state
* Efficient string handling and buffer management

### ft\_printf

* Variadic functions (`va_list`)
* Parsing format strings
* Type-specific formatting (integers, strings, hex, pointers, etc.)

---

## 🛠️ Compilation

You can compile each project separately:

```bash
# For get_next_line
gcc -Wall -Wextra -Werror get_next_line/get_next_line.c get_next_line/get_next_line_utils.c -D BUFFER_SIZE=42 -o gnl

# For ft_printf
gcc -Wall -Wextra -Werror ft_printf/ft_printf.c ft_printf/ft_utils.c -o printf_test
```

---

## 💡 Tips for the Exam

* Don’t forget to handle edge cases (e.g., empty lines, null strings, buffer boundaries).
* Make sure your code doesn’t leak memory or file descriptors.
* Stick strictly to the allowed functions.
* Write modular and well-separated code to stay organized under pressure.

---

## 📜 License

This project is part of the 42 Network curriculum.
