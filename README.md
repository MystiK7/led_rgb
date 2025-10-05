# LED RGB

Test de la LED RGB **HW-479** SUR Arduino Uno.

Matériel utilisé :
- 1 module IR HW-201
- 1 module LED RGB HW-479
- 1 buzzer

Une photo du cablâge est disponible dans le dossier au besoin. 

## Fonctionnement du programme

Il existe 2 modes : 
- Auto : en tapant "auto" dans le moniteur série (9600 bauds), le module IR s'active et allume la LED RGB (rouge, vert, bleu, violet) lors de la détection d'un obstacle.
- Manuel : on tape la couleur RGB souhaitée et allume la LED avec cette couleur --> format : R G B

Il est aussi possible d'arrêter de switcher entre les deux modes en tapant "stop" dans le moniteur série.
