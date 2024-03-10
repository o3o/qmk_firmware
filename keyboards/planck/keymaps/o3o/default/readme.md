# Planck Layout
Configurazioni per tastiera Planck rev6 acquistata il 16 maggio 2021.

La documentazione seguente è tratta da [qmk ufficiale](https://docs.qmk.fm/#/)

## Installazione
```
> paru -Sy qmk
```

## git
Creare un fork di [qmk]() e clonarlo:

```
> cd ~/cc
> g clone --recurse-submodules git@github.com:o3o/qmk_firmware.git
```

Non si lavora mai sul [master](https://docs.qmk.fm/#/newbs_git_using_your_master_branch).
Per aggiornare il fork con il master di qmk:
```
> git remote add upstream git@github.com:qmk/qmk_firmware
> git checkout master
> git pull upstream master
> git push origin master
```
a questo punto creare un nuovo branch
```
git checkout -b dev
git push --set-upstream origin dev
```
in questo modo `git push` esegue il push sempre su `dev`, altrimenti scrivere ogni volta:
```
git push origin dev
```

### Aggiornamenti successivi
```
> git checkout master
> git pull upstream master
> git push origin master
> git co dev
> git rebase upstream/master
```
## Creazione
Opzionalmente si può impostare la tastiera di default:
```
qmk config user.keyboard=planck/rev6_drop
```
a questo punto:
```
> qmk new-keymap o3o/default
```
crea la directory `./keyboards/planck/keymap/o3o/default`

Per compilare
```
> qmk -km o3o/default
```

## Flashing
Plug your keyboard into your computer and at press the RESET button on the bottom of they keyboard. Your computer should recognize the keyboard and should be ready for you to flash the new keymap onto it.

```
> qmk flash
```
## Keycodes
### Basic Keycodes

| key            | alias            | desc                                    |
| ---            | ---              | ---                                     |
| KC_TRANSPARENT | KC_TRNS, _______ | Use the next lowest non-transparent key |

### [Layer switching](https://docs.qmk.fm/#/keycodes?id=layer-switching)

| key           | desc                                    |
| ---           | ---                                     |
| LT(layer, kc) | Turn on layer when held, kc when tapped |
| MO(layer)	| Momentarily turn on layer when pressed (requires KC_TRNS on destination layer)|

## Layers
Sono definiti dall'enum `planck_layers`
- _QWERTY,
- _LOWER,
- _RAISE,
- _ADJUST,
- _CAT

## Codici usati
- MO(layer) - attiva momentaneamente il layer. Non appena si lascia il tasto, il layer viene disattivato.

- OSM(mod) one shot key: shift rimane premuto fino al successivo carattere

## Descrizione dei codici
- OSM(MOD_LSFT) one shot key: shift rimane premuto fino al successivo carattere
KC_LCTL
KC_LALT
KC_LGUI
CAT è MO(_CAT) con `CAT` layer 4
LOWER è `MO(_LOWER)`
LSFT_T(KC_SPC)
LSFT_T(KC_SPC)
RAISE

