# Nom du compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g

# Nom de l'exécutable
TARGET =  Whatever 

# Dossiers contenant les fichiers source et d'en-tête
SRC_DIR = Sources
INC_DIR = Includes

# Liste des fichiers source
SRCS = main.cpp $(wildcard $(SRC_DIR)/*.cpp)

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -I$(INC_DIR) -o $(TARGET) $(SRCS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
