Repository : https://github.com/diiad/TP-Git-2025-2A3-G7.git
Élève 1 = Diadieu DOUCOURE
Élève 2 = Oumar BARRY
Élève 3
 
# TP Final - Versioning avec Git et GitHub

*Édition 2025*

Enseignante et correctrice : Sarah Schlegel ([@SarahSch19](https://github.com/esgi-na-sa/TP-Git-2025))

## Modalités

Durée : 1h30

Ce TP est à faire par groupes de 3. Dans les rares cas où vous ne seriez que 2, l'intégralité du TP est à réaliser, mais vous pouvez vous répartir les tâches de l'élève n°3.

## Livrables

Le seul livrable attendu est **le dossier de travail complet (repository), à rendre sur MyGes** uniquement au format .zip. Il doit absolument contenir :

- le dossier .git
- le dossier `screenshots`
- les différents fichiers à créer durant le tp (`tp.md`, `reflexion.md`)

## Ressources autorisées

Vous avez accès à toutes les ressources fournies en cours (supports PDF, cheat sheet, etc.). Vous n'avez **pas** l'autorisation d'utiliser des LLMS et IAs génératives (ChatGPT, Copilot, etc.) pour trouver les commandes à utiliser. Vous n'avez également pas le droit de communiquer avec les étudiants des autres groupes.

# Instructions

## Règles de nomenclature

### Branches

Afin d'identifier votre travail, vos **branches** doivent respecter la nomenclature suivante : `branch/<nom-de-l'élève>`. 

Exemples :

- `branch/Jane-Doe`
- `branch/Louis-Petit`

### Commits

Afin de structurer vos commits, vous devez respecter la nomenclature de commits suivante :

- `feat/<nom-de-l'élève>: <description de la modification>` pour les modifications principales avec nom-de-l'élève étant l'élève qui a fait la modification
- `merge/<nom-de-l'élève>: merge de <source> vers <destination>` pour les merge, avec `<source>` étant le nom de la branche source, et `<destination>` celui de la branche vers laquelle le merge est effectué

Si vous ne souhaitez pas mettre vos noms complets dans les commits et les noms de branches, vous pouvez utiliser seulement votre prénom (s'il n'y a pas de doppelganger dans votre groupe) ou votre pseudo GitHub. Vous devrez alors rajouter dans le livrable de rendu les associations entre vos pseudos GitHub et vos noms réels.

## **Phase 1 – Démarrage du projet**

1. Un élève du groupe fait un fork du repository https://github.com/esgi-na-sa/TP-Git-2025. Le nom du repo doit contenir votre classe et le numéro de votre groupe, par exemple `TP-Git-2025-2a1-G1`.
2. Il ajoute les deux autres ainsi que l'enseignante (`SarahSch19`) en tant que collaborateurs
3. Chaque étudiant **clone** le repository sur sa machine.
4. Chacun crée sa **branche personnelle** à partir du commit initial (`main` ou `master`).

À partir de cette étape, le travail de chaque élève diverge.

## Phase 2 – Modifications initiales

Toutes les modifications doivent être commitées et pushées sur leurs branches respectives.

### Élève 1 :

- Crée un fichier [`tp.md`](http://tp.md) avec un bref contenu texte (3-4 lignes, peuvent être copiées depuis le `README.md`.

### Élève 2 :

- Crée également un fichier [`tp.md`](http://tp.md) avec un contenu **différent** (idem, quelques lignes de texte).

### Élève 3 :

- Modifie le `README.md` pour :
    - Supprimer son contenu initial
    - Lister les noms des trois contributeurs (et leurs pseudos github si nécessaire).
    - Ajouter l’URL en remote du repository forké.
    
    ```jsx
    Repository : https://github.com/jean-durand/TP-Git-2025-2a1-G1
    Élève 1 = Jane Doe
    Élève 2 = Louis Petit
    Élève 3 = Jean Durand
    ```
    

> S'il n'y a pas de troisième élève, ces tâches sont à répartir entre les deux élèves présents.
> 

## Phase 3 – Collaboration et gestion des conflits

### Étape 1 : Fusions croisées

- **Élève 1** : merge la branche de l’Élève 2 **sans** fast-forward
- **Élève 2** : merge la branche de l’Élève 3 **avec** fast-forward
- **Élève 3** : rebase sa branche sur celles de l’Élève 1 puis de l’Élève 2.

> Si un conflit apparaît, il doit être résolu et mentionné dans la description du commit.

## Phase 4 – Manipulations avancées sur l’historique

1. **Élève 1 : Créer un HEAD détaché :**
    - Créer un **head détaché** à partir du commit `36daa99 19/10/2021 grid and cells setup`
    - Ajouter du contenu dans un fichier `detached.md`et commit.
    - Faire une capture d’écran du terminal en mode head détaché et la placer dans un dossier `/screenshots/`.
    - Appeler la branche `detached` et la pousser en remote.
2. **Élève 2 : Faire un revert :**
    - Revenir sur le commit de création du fichier `tp.md` de l’Élève 1.
    - Faire un commit de revert appelé `revert/<nom>` et décrire ce qui a été annulé.
3. **Élève 3 : Faire un reset**
    - Faire une capture d’écran de `git log --oneline --graph` **avant** le reset.
    - Effectuer un **reset hard** au commit **précédant** le merge de l'élève3 sur la branche de l'élève 2.
    - Commiter la capture dans le dossier `/screenshots/`.

## Phase 5 – Pull Requests et revue de code

- **Élève 3** : crée une Pull Request de sa branche vers `main`.
- **Élève 2** : approuve la PR.
- **Élève 1** : demande des changements.
- **Élève 2** : répond au commentaire.
- **Élève 1** : marque le commentaire comme résolu.
- **Élève 3** : fusionne via **Squash & Merge**.

> /!\ Les pull requests doivent être faites sur le repository forké, pas vers le repository principal.

## Phase 6 – Réflexion et questions techniques (écrites)

Chaque étudiant doit répondre dans un fichier `reflexion.md` :

1. **Expliquez, en quelques phrases, la structure actuelle du projet Git après toutes les opérations (branches, merges, commits).**
    - Vous pouvez illustrer avec `git log --graph`.
2. **Quelle est la différence entre `git fetch` et `git pull` ?**
    - Donnez un exemple concret où l’un est préférable à l’autre.
3. **Expliquez la différence entre `git reset` et `git revert`.**
    - Décrivez une situation où utiliser l’un serait risqué.

## Bonus (optionnel, +1 point)

Configurez une **règle de protection** sur la branche principale :

- Interdire le push direct
- Obliger au moins une approbation avant merge

Ajoutez une capture d’écran de la configuration GitHub dans le dossier `/screenshots/`.

# *À vos terminaux !*
