# Juego de Cifras y Letras
Hecho por Carlos Vera Lahoz e Iker Resino Sánchez

## Descripción del Proyecto

Este proyecto consiste en el desarrollo del juego de "Cifras y Letras", implementado en C++. El programa tiene dos modos de juego principales:

1. **Cifras**: Los jugadores deben realizar operaciones matemáticas con una selección de números para alcanzar un objetivo específico.
2. **Letras**: Los jugadores deben formar palabras utilizando letras seleccionadas al azar, siguiendo las reglas de puntuación definidas.

El desarrollo del proyecto ha seguido un enfoque modular, organizando el código en diferentes clases y archivos que permiten manejar tanto la lógica como la interacción con el usuario de forma clara y eficiente.

---

## Contenido del Proyecto

### Archivos Principales

Los archivos del proyecto están organizados en dos carpetas:
- **`src`**: Contiene las implementaciones de la lógica del juego.
- **`include`**: Contiene las declaraciones de clases e interfaces necesarias.

#### 1. Archivos Relacionados con Cifras
- **`src/cifras.cpp`**:
  Este archivo contiene la clase `Cifras`, que implementa toda la lógica del juego de cifras. Genera números aleatorios, calcula operaciones y determina las mejores soluciones mediante recursión y exploración de operaciones matemáticas.

#### 2. Archivos Relacionados con Letras
- **`src/letras.cpp`**:
  Implementa la lógica del juego de letras, utilizando las clases `Dictionary`, `LettersSet`, `LettersBag` y `Solver` para cargar palabras, manejar letras y determinar las mejores soluciones.

#### 3. Archivos Auxiliares y Clases
- **`Dictionary`**:
  Maneja un conjunto de palabras y permite realizar operaciones como buscar, insertar, eliminar, y explorar palabras por longitud o prefijo.
- **`LettersBag`**:
  Gestiona una bolsa aleatoria de letras que los jugadores pueden extraer.
- **`LettersSet`**:
  Define la puntuación asociada a cada letra y proporciona funcionalidades para calcularla.
- **`Solver`**:
  Determina las mejores soluciones posibles a partir de un conjunto de letras, ya sea por longitud o puntuación.

#### 4. Archivos de Pruebas
Varios archivos de pruebas (`proof_*.cpp`) verifican la funcionalidad de cada componente, asegurándose de que las clases y métodos implementados funcionen correctamente.

---

## Cómo Ejecutar y Probar el Proyecto

1. **Clonar el Repositorio**
   ```bash
   git clone https://github.com/carloss433/cifrasyletras.git
   cd cifrasyletras
   ```

2. **Compilación**
   Asegúrate de disponer de un compilador compatible con C++11 o superior. Usa los siguientes comandos para compilar:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. **Ejecución**
   Por ejemplo, para jugar al modo "letras":
   ```bash
   ./letras diccionario.txt letras.txt 10 P
   ```

4. **Ejecutar las Pruebas**
   Cada archivo `proof_*.cpp` contiene pruebas específicas que se pueden ejecutar de la siguiente manera:
   ```bash
   ./proof_letters_set
   ./proof_letters_bag
   ./proof_letras
   ```

---

¡Esperamos que disfrutes jugando "Cifras y Letras"!
