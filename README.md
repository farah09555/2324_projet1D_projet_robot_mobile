# 2324_projet1D_projet_robot_mobile
Projet electronique STM32, projet de conception de robot mobile

A) Nom et contexte du projet :
Ce projet se fait dans le cadre de la fin de notre première année du cycle d'ingénieur en Electronique et Informatique Industrielle via la voie d'apprentissage.
L’objectif est de concevoir un robot mobile autonome qui suivra une trajectoire donnée en évitant les obstacles grâce à un capteur de détection d’obstacles. Nous vous présenterons plus de détails ci-dessous.

B) Matériels utilisés dans ce projet : 
STM32 = Microcontrôleur qui utilise des cœurs ARM Cortex pour offrir des performances élevées, une faible consommation d'énergie et une large gamme de fonctionnalités intégrées, ce qui le rend idéal pour une variété d'applications électroniques.

C) Fonctionnalités du robot :
Un microcontrôleur STM32 offre une gamme étendue de fonctionnalités techniques cruciales pour le fonctionnement efficace et sécurisé d'un robot mobile. Grâce à ses capacités avancées et sa flexibilité, il constitue le cœur du système, permettant de gérer et de coordonner les différentes opérations du robot de manière optimale.

1. Pilotage du moteur
Le STM32 peut contrôler les moteurs du robot via des interfaces telles que les PWM (Pulse Width Modulation) pour réguler la vitesse et la direction. En générant des signaux PWM, le microcontrôleur peut ajuster la puissance fournie aux moteurs, permettant des mouvements précis.

2. Réglages automatiques de timers
Les timers intégrés du STM32 permettent de gérer des tâches périodiques ou temporisées sans intervention du CPU principal. Par exemple, ils peuvent être utilisés pour la gestion du temps de fonctionnement des moteurs, les intervalles de capteurs, ou la synchronisation de diverses actions du robot.

3. Horodatage : génération du temps courant
Le microcontrôleur peut utiliser un timer en mode compteur pour garder une trace du temps écoulé depuis le démarrage du robot. Ceci est crucial pour des tâches comme le suivi des délais, la planification des actions futures, ou la journalisation des événements.

4. Commande manuelle à distance
Le STM32 peut recevoir des commandes via divers modules de communication (Bluetooth, Wi-Fi, RF). Ces commandes peuvent être utilisées pour contrôler manuellement le robot à distance, par exemple à l'aide d'une application mobile ou d'une télécommande.

5. Programmer les arrêts d’urgence
Le STM32 peut surveiller des capteurs spécifiques (comme des interrupteurs de sécurité ou des capteurs de collision) pour déclencher un arrêt d’urgence en cas de danger. Ce mécanisme assure la sécurité en coupant immédiatement l'alimentation des moteurs et en mettant le système dans un état sûr.

6. Mise en œuvre du hacheur
Un hacheur est utilisé pour contrôler la tension et le courant fournis aux moteurs. Le STM32 peut contrôler les transistors de puissance (MOSFETs ou IGBTs) du hacheur via des signaux PWM, permettant une régulation fine de l'énergie et donc des performances optimisées du moteur.

7. Les conversions analogiques-numériques
Le STM32 possède des convertisseurs analogiques-numériques (ADC) intégrés, permettant de lire les valeurs de capteurs analogiques (comme les capteurs de température, de lumière, ou de distance) et de les convertir en données numériques que le microcontrôleur peut traiter pour prendre des décisions en temps réel.

En résumé, 
