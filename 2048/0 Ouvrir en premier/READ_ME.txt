									# Jeu 2048 #

Bienvenue dans ce tutoriel qui vous expliquera comment compiler notre programme et profiter du jeu 2048

/!\ Programme uniquement compatible sur l'OS Windows /!\

		Etape 1: Consultation du programme en condition de jeu normal

1) Une fois avoir téléchargé notre fichier, placé le sur votre Bureau

2) Clic droit sur l'archive -> Extraire les fichiers.. -> Cliquez Ok

3) Ouvrez le terminal de votre ordinateur, puis rendez vous dans la racine de ce dossier via la commande cd : C:\VOTRE PATH\Bureau\FINAL_VERSION>

4) Dès lors, entrez la commande suivante dans votre terminal :


		gcc *.c -o (Appelation au choix)


5) Pour lancer le programme, entrez simplement (Appelation de votre choix) dans le terminal


		

3) Pour lancer le programme, entrez simplement (Appelation de votre choix) dans le terminal

Indications importantes :

Lorsque vous êtes invités à réaliser un déplacement, veuillez saisir dans le terminal la lettre correspondant au déplacement suivant :

z = HAUT
s = BAS
q = GAUCHE
d = DROITE
	

	RAPPEL DES REGLES / REGLES OPTIONNELLES 

/ SAUVEGARDE \

Pour sauvegarder votre partie, il vous suffira de saisir le caractère 'c' dans le terminal, avant de cliquer sur la touche entrée.


/ LES VALEURS \

Ensemble des valeurs que vous pouvez rencontrer sur votre plateau :

2
4
8
16
32
64
128
256
512
1024
2048


/ BUT DU JEU \
 
L'objectif est de deplacer les cases de votre plateau de jeu de façon à obtenir une case portant la valeur 2048.


/ Version test \

Afin de tester les fins possibles, il suffira de sélectionner un des deux fichiers test (1-2).txt présent dans le dossier évaluation ;

Puis, de le renommer en test.txt, avant de remplacer celui présent dans l'arborescence :

	 C:\VOTRE PATH\Bureau\FINAL_VERSION>
