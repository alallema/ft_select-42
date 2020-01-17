# ft_select

## Description
Ce projet est une initiation à la manipulation du terminal avec les termcaps. Le but est de créer une interface utilisateur pour un programme lancé dans le terminal.

## Usage

```$> ./ft_select [arg] [args ...]```

- ⬅︎➡︎⬆︎⬇︎ mouvement
- `Tab` change la couleur du texte
- `ALT+C` passe le texte en gras
- `Space` selectionne un élément

## Fonctions autorisees

- isatty, ttyname, ttyslot
- ioctl
- getenv
- tcsetattr, tcgetattr
- tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
- open, close, write
- malloc, free
- read, exit
- signal