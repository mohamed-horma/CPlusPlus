
````markdown
# Projet C++ – Validation de saisie et fonctions

## 1. Validation de saisie

### Compilation
Après compilation avec la commande :

```bash
make book
````

on obtient des erreurs d’ambiguïté :

* Appel de la fonction **par valeur** :

  ```
  src/main.cpp:18:19: error: call of overloaded ‘lit_au_clavier(int&)’ is ambiguous
  18 |     lit_au_clavier(page);
  ```

* Appel de la fonction **par référence** :

  ```
  src/main.cpp:22:19: error: call of overloaded ‘lit_au_clavier(int&)’ is ambiguous
  22 |     lit_au_clavier(page);
  ```

### Solution

L’ambiguïté vient du fait que deux fonctions portent le même nom, mais avec des paramètres différents.
Pour corriger cela, on place chaque fonction dans un **namespace** :

* `namespace LitParValeur` pour :

  ```cpp
  void lit_au_clavier(int page);
  ```

* `namespace LitParRef` pour :

  ```cpp
  void lit_au_clavier(int& ref);
  ```

Ainsi, chaque fonction est distinguée et les erreurs disparaissent.

---

## 2. Pour aller plus loin : la fonction `portelogique`

En C++, **retourner une référence vers une variable locale** est une erreur, car cette variable est détruite à la fin de la fonction.

Si on déclare la variable **`static`**, elle reste en mémoire entre les appels.
On peut donc l’utiliser pour mémoriser une **table de vérité** (valeurs des sorties pour chaque combinaison d’entrées d’une porte logique).

Exemple attendu :

```
logical_gate(true,false)  = false
logical_gate(false,true)  = false
logical_gate(true,true)   = true
logical_gate(false,false) = false
```

Ainsi, la fonction peut être utilisée comme une porte logique personnalisée.

---

## 3. Question Bonus

Lors de la compilation, une autre erreur peut apparaître :

> Une **référence à un `double`** ne peut pas être affectée comme un **pointeur**.

Cela signifie qu’il ne faut pas confondre les deux mécanismes :

* une **référence** est un alias vers une variable,
* un **pointeur** est une adresse mémoire qui peut être manipulée.

```

---


