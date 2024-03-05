# Push-Swap

A program that sort elements of a stack in ascending order. This project is part of the 42 Quebec curriculum. The program
takes as arguments the elements of the stack, which must be integers, in any given order, and return the operations it will do
to arrange the stack. The program is build assuming you have access to 2 stacks and all the given element
are placed inside the first stack at start.

For the operations: The first letter stands for the type of operation. "s" stands for swap, which means taking the first 
element of a stack and swap it with the second. "r" stands for rotate, it puts the first element of a stack to the end of
the stack. "p" stands for push, it take the element of the top of a stack to the top of the other stack.
The second letter stands for the stack on which the operation is being made. "a" stands for the first stack and "b" stand 
for the second one. It can also be the repetition of the operation (example: "rr"), in this case, in means that the operation
is happening simultaneously on both stacks. In the case of the operation "p", the given letter is the stack on which the 
number is being push on.

## Installation

- Clone the repository in a folder of your choice.

```bash
git@github.com:ShroomySquid/push_swap.git
```

- Run the command make in the folder to compile the program.

# Push-Swap -- Français

Un programme qui arrange les éléments d'une pile en ordre croissant. Ce projet fait partie du cursus de 42 québec.
Le programme prend en argument les éléments du stack, qui doivent être des entiers. Le programme retourne les opérations
qu'il doit faire afin de réarranger les éléments en ordre croissant. Le programme assume qu'il a accès à 2 piles et que
tout les éléments sont initialement placés dans la première pile.

Pour les opérations: la première lettre indique le type d'opération faite par le programme. "s" pour swap, on intervertit 
les deux premiers éléments de la pile. "r" pour rotate, on place le premier élément de la pile à la fin de la pile.
"p" pour push, on place le premier élément d'un pile au dessus d'une autre pile. 
La deuxième lettre indique la pile sur laquelle l'action s'opère. "a" pour la première, "b" pour la seconde. Si on répète
la lettre de l'opération (example: ss), cela indique que l'opération se fait sur les deux piles simultanéments. Dans le
cas de "p", la pile indique est celle qui reçoit l'élément de l'autre pile.

## Installation

- Cloner le répertoire dans un dossier de votre choix.

```bash
git@github.com:ShroomySquid/push_swap.git
```

- Faites la commande "make" dans le doisser afin de compiler le program.
