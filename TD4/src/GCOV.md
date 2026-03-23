# gcov

`gcov` est une exécutable qui permet de
quantifier la couverture des tests exécutés
par rapport à un fichier source.
Cet outil est très utile en combinaison
avec `klee`, car il permet de déterminer
si `klee` a exploré tout le programme
(et si ce n'est pas le cas, de quantifier à
quel point `klee` l'a exploré).

Pour l'utiliser, il faut compiler le fichier
source avec l'option `--coverage` :

```bash
gcc --coverage -o ex1 ex1.c
```

Il est important que l'exécutable ait le même
nom que le fichier source.
Une fois cela fait, vous pouvez alors rejouer les
tests générés par `klee` comme expliqué dans
l'exercice 1.
Après chaque test rejoué, utilisez la commande
`gcov ex1.c` pour voir la couverture actuelle
du code source.
Plus vous rejouez de cas de tests, plus la valeur
augmentera.
Vous pouvez utiliser cet outil afin de vérifier
que vos tests couvrent bien tout le code
des fichiers (notamment pour les
exercices 6 et 7).
