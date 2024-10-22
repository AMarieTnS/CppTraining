# Nom du compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -Werror

# Nom de l'exécutable
TARGET = pointer

# Liste des fichiers source
SRCS = ex04.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
