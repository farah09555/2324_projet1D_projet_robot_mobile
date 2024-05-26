# Conception de robot mobile

Ce projet se fait dans le cadre de la fin de notre première année du cycle d'ingénieur en Electronique et Informatique Industrielle via la voie d'apprentissage. Nous vous présenterons plus de détails ci-dessous.

A) Nom et contexte du projet :
L’objectif est de concevoir un robot mobile autonome qui suivra une trajectoire donnée en évitant les obstacles grâce à un capteur de détection d’obstacles. 

B) Matériels utilisés

1. Plateforme avec 3 Roues Mobiles

Rôle : Structure physique et mobilité
Fonctionnalité : La plateforme sert de base pour tous les autres composants et permet au robot de se déplacer. Les trois roues mobiles, configurées dans une formation triangulaire, assurent une stabilité et une manœuvrabilité optimale du robot.

2. Carte STM32 (Microcontrôleur) NUCLEO-L476RG

Rôle : Unité centrale de contrôle
Fonctionnalité : Le microcontrôleur STM32 est le cerveau du robot. Il traite les informations provenant des capteurs et des périphériques, prend des décisions basées sur les algorithmes de contrôle, et envoie des commandes aux moteurs et autres composants.

3. Prototypage (ou circuit imprimé)

Rôle : Support de connexion et intégration des composants
Fonctionnalité : Le prototypage ou le circuit imprimé permet de monter et de connecter facilement les différents composants électroniques. Il facilite les connexions électriques propres et fiables, permettant de tester et de modifier les circuits selon les besoins du projet.

4. Piles de 1,5 volts (x4)

Rôle : Source d'alimentation
Fonctionnalité : Les quatre piles de 1,5 volts fournissent l'énergie électrique nécessaire pour faire fonctionner tous les composants du robot. En série, elles offrent une tension combinée de 6 volts, suffisante pour alimenter le microcontrôleur, les moteurs, et les capteurs.

5. Moteurs CC (Courant Continu)

Rôle : Actuateurs pour le mouvement
Fonctionnalité : Les moteurs à courant continu convertissent l'énergie électrique en énergie mécanique, permettant ainsi au robot de se déplacer. En ajustant la tension et la polarité appliquées aux moteurs, on peut contrôler la vitesse et la direction de chaque roue.

6. Capteur TOF (Time of Flight)

Rôle : Détection de distance
Fonctionnalité : Le capteur TOF mesure la distance entre le robot et un objet en émettant un faisceau lumineux et en mesurant le temps que prend la lumière pour revenir après avoir été réfléchie par l'objet. Cela permet au robot de détecter des obstacles, de naviguer dans l'environnement et de réaliser des tâches d'évitement d'obstacles.

7. Driver L298N

Rôle : Interface de contrôle pour les moteurs
Fonctionnalité : Le driver L298N est un pont en H utilisé pour contrôler la puissance fournie aux moteurs CC. Il permet de contrôler la vitesse et la direction des moteurs à partir des signaux de commande fournis par le microcontrôleur. Il peut gérer des courants plus élevés nécessaires pour faire fonctionner les moteurs sans endommager le microcontrôleur

8. MPU-6050 (Gyroscope à 3 axes)

Rôle : Détection de mouvement et orientation
Fonctionnalité : Le MPU-6050 est un capteur inertiel qui combine un gyroscope à 3 axes et un accéléromètre à 3 axes. Il mesure les rotations et les accélérations du robot, permettant de déterminer son orientation et ses mouvements dans l'espace. Ces données sont essentielles pour la stabilisation, la navigation et le contrôle précis du mouvement du robot

C) Fonctionnalités du robot :
Un microcontrôleur STM32 offre une gamme étendue de fonctionnalités techniques cruciales pour le fonctionnement efficace et sécurisé d'un robot mobile. Grâce à ses capacités avancées et sa flexibilité, il constitue le cœur du système, permettant de gérer et de coordonner les différentes opérations du robot de manière optimale.

Voici ci-dessous les fonctionnalités détaillées de ce robot mobile, qui vont être programmées en C par la suite sur STM32Microcontrollers, le logiciel compilation et génération du code source.

1. Pilotage du moteur
Le STM32 peut contrôler les moteurs du robot via des interfaces telles que les PWM (Pulse Width Modulation) pour réguler la vitesse et la direction. En générant des signaux PWM, le microcontrôleur peut ajuster la puissance fournie aux moteurs, permettant des mouvements précis.

2. Réglages automatiques de timers
Les timers intégrés du STM32 permettent de gérer des tâches périodiques ou temporisées sans intervention du CPU principal. Par exemple, ils peuvent être utilisés pour la gestion du temps de fonctionnement des moteurs, les intervalles de capteurs, ou la synchronisation de diverses actions du robot.

3. Horodatage : génération du temps courant
Le microcontrôleur peut utiliser un timer en mode compteur pour garder une trace du temps écoulé depuis le démarrage du robot. Ceci est crucial pour des tâches comme le suivi des délais, la planification des actions futures, ou la journalisation des événements.

4. Programmer les arrêts d’urgence
Le STM32 peut surveiller des capteurs spécifiques pour déclencher un arrêt d’urgence en cas de danger. Ce mécanisme assure la sécurité en coupant immédiatement l'alimentation des moteurs et en mettant le système dans un état sûr.

5. Mise en œuvre du hacheur
Un hacheur est utilisé pour contrôler la tension et le courant fournis aux moteurs. Le STM32 peut contrôler les transistors de puissance du hacheur via des signaux PWM, permettant une régulation fine de l'énergie et donc des performances optimisées du moteur.

6. Les conversions analogiques-numériques
l'ADC du microcontrôleur STM32 est utilisé pour lire les données du capteur de distance. Cela permet de convertir les signaux analogiques en valeurs numériques que le microcontrôleur peut utiliser pour prendre des décisions pour éviter les obstacles.

Conclusion : En intégrant tous ces composants, on obtient un robot mobile capable de percevoir son environnement, de prendre des décisions intelligentes et de se déplacer de manière autonome. Le microcontrôleur coordonne l'ensemble du système, utilisant les données des capteurs pour ajuster les commandes des moteurs via le driver, permettant ainsi au robot d'interagir efficacement avec son environnement.


