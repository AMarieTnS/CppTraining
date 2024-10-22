# Nom du compilateur
CXX = g++

# Options du compilateur
CXXFLAGS = -Wall -std=c++11

# Nom de l'exécutable
TARGET = PhoneBook

# Liste des fichiers source
SRCS = CPP_Module_00_Exo_1.cpp

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
