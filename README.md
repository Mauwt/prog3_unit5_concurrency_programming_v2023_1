# Task #0: Concurrency Programming  
**course:** Programación III  
**unit:** 5  
**cmake project:** prog3_unit5_concurrency_programming_v2023_1
## Instructions
Subir a gradescope el siguiente archivo:
- `generate_random_vector.h`
- `factorial.h`
- `merge_sort.h`

## Question #1 - generar vector aleatorio (4 points)

Desarrollar un template que permita generar un vector de números aleatorios en un rango dado de valores.

**Use Case #1:**
```cpp
auto v = generate_random_vector<int, 10000>(-20, 20);
cout << size(v) << endl;
cout << max_element(begin(v), end(v)) << " " min_element(begin(v), end(v)) << endl;
```

**Use Case #2:**
```cpp
auto v = generate_random_vector<unsigned int, 10000>(1, 30);
cout << size(v) << endl;
cout << max_element(begin(v), end(v)) << " " min_element(begin(v), end(v)) << endl;
```

## Question #2 - factorial paralelo (6 points)

Desarrollar un template que permita realizar calcular de forma paralela el factorial de un número.

**Use Case #1:**
```cpp
auto f = calculate_factorial<unsigned long long>(20);
cout << f << endl;
```

## Question #3 - ordenamiento merge paralelo (6 points)

Desarrollar un template que permita ordenar un vector en un rango dado de valores.

**Use Case #1:**
```cpp
auto v = generate_random_vector<unsigned int, 10000>(100, 10000);
merge_sort(begin(v), end(v));
cout << v << endl;
```

**Use Case #2:**
```cpp
auto v = generate_random_vector<10000>(-5000, 5000);
merge_sort(begin(v), end(v));
cout << v << endl;
```

