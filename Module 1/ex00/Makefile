# Nom du compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -Werror

# Nom de l'exécutable
TARGET = Heap_Quadrupeds

# Liste des fichiers source
SRCS = main.cpp Pony.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
