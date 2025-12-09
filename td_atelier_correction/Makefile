# Makefile pour TD Pointeurs & Couture
# Compilation des exercices et de la bibliothèque atelier_couture

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Tous les exécutables
EXOS = exo1 exo2 exo3 exo4 exo5 exo6
EXEMPLE = exemple

# Cible par défaut : compile tous les exercices
all: $(EXOS) $(EXEMPLE)

# Règles pour chaque exercice (fichiers autonomes)
exo1: exo1_etalonner_ruban.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

exo2: exo2_mesures_clients.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

exo3: exo3_surface_rouleaux.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

exo4: exo4_decoupe_bandes.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

exo5: exo5_carnet_commandes.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

exo6: exo6_plan_coupe.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Exemple utilisant la bibliothèque
exemple: exemple_utilisation.cpp atelier_couture.cpp atelier_couture.hpp
	$(CXX) $(CXXFLAGS) exemple_utilisation.cpp atelier_couture.cpp -o $@

# Exécuter tous les exercices
run-all: all
	@echo "=== Exécution de l'exercice 1 ==="
	@./exo1
	@echo ""
	@echo "=== Exécution de l'exercice 2 ==="
	@./exo2
	@echo ""
	@echo "=== Exécution de l'exercice 3 ==="
	@./exo3
	@echo ""
	@echo "=== Exécution de l'exercice 4 ==="
	@./exo4
	@echo ""
	@echo "=== Exécution de l'exercice 5 ==="
	@./exo5
	@echo ""
	@echo "=== Exécution de l'exercice 6 ==="
	@./exo6
	@echo ""
	@echo "=== Exécution de l'exemple ==="
	@./exemple

# Exécuter un exercice spécifique
run-%: %
	@echo "=== Exécution de $< ==="
	@./$<

# Nettoyage
clean:
	rm -f $(EXOS) $(EXEMPLE)

# Nettoyage complet (y compris fichiers temporaires)
distclean: clean
	rm -f *.o *~ core

# Afficher l'aide
help:
	@echo "Makefile pour TD Pointeurs & Couture"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  make           : Compile tous les exercices et l'exemple"
	@echo "  make all       : Idem"
	@echo "  make exo1      : Compile uniquement l'exercice 1"
	@echo "  make exo2      : Compile uniquement l'exercice 2"
	@echo "  make exo3      : Compile uniquement l'exercice 3"
	@echo "  make exo4      : Compile uniquement l'exercice 4"
	@echo "  make exo5      : Compile uniquement l'exercice 5"
	@echo "  make exo6      : Compile uniquement l'exercice 6"
	@echo "  make exemple   : Compile l'exemple utilisant la bibliothèque"
	@echo "  make run-all   : Compile et exécute tous les exercices"
	@echo "  make run-exo1  : Compile et exécute l'exercice 1"
	@echo "  make run-exo2  : Compile et exécute l'exercice 2"
	@echo "  make run-exo3  : Compile et exécute l'exercice 3"
	@echo "  make run-exo4  : Compile et exécute l'exercice 4"
	@echo "  make run-exo5  : Compile et exécute l'exercice 5"
	@echo "  make run-exo6  : Compile et exécute l'exercice 6"
	@echo "  make clean     : Supprime tous les exécutables"
	@echo "  make distclean : Supprime tous les fichiers générés"
	@echo "  make help      : Affiche cette aide"

.PHONY: all clean distclean help run-all
