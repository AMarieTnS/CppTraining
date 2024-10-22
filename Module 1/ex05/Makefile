# Nom du compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -Werror

# Nom de l'exécutable
TARGET = Violence

# Liste des fichiers source
SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)