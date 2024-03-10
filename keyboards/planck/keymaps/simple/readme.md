# Versione semplificata# della tastiera Planck

Miglioramento della versione storica  `keyboards/plank/keymaps/std`
Questa versione vuole essere uguale a quella del 2021 ma ricompilata con qmk attuale v4.0

## Layer

Ci sono tre layer
- raise: a cui si accede con il tasto a destra dello spazio
- lower: a cui si accede con il tasto a sinistra dello spazio
- vim: solo poche funzioni, si accede con il terzo tasto da sinistra (sotto la X)


## Comandi

| cmd             | layer  | desc                                                                           |
| ---             |        | ---                                                                            |
| MO(layer)       | qwerty | Momentarily turn on layer when pressed (requires KC_TRNS on destination layer) |
| LGUI_T(KC_RGHT) | querty | Left gui when held, right arrow when tapped                                    |

## Tasti

- `VIM_COPY`  associato a y -> "+y
- `VIM_PASTE` associato a p -> "+p
