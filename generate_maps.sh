#!/bin/bash

# Tworzenie katalogu na mapy
mkdir -p maps

echo "Generowanie map testowych..."

# --- MAPY POPRAWNE (VALID) ---

# 1. Klasyczna mała mapa
cat > maps/valid_small.ber << EOF
11111
1C0E1
10P01
11111
EOF

# 2. Mapa podłużna (test prostokąta)
cat > maps/valid_long.ber << EOF
11111111111111
100000000000C1
1P0000E0000001
11111111111111
EOF

# 3. Mapa bardziej skomplikowana (labirynt)
cat > maps/valid_maze.ber << EOF
111111111111
1P00000100C1
101111010101
101000000101
1010111111E1
1000000000C1
111111111111
EOF

# --- MAPY BŁĘDNE (INVALID) - Twój program musi zwrócić "Error" ---

# [cite_start]4. Brak otoczenia murami (dziura w ścianie) [cite: 153]
cat > maps/error_no_walls.ber << EOF
11111
1P0C1
100E1
11011
EOF

# [cite_start]5. Mapa nie jest prostokątem (różna długość linii) [cite: 152]
cat > maps/error_rectangle.ber << EOF
11111
1P0C1
100E11
11111
EOF

# [cite_start]6. Brak ścieżki do wyjścia (Flood Fill test) [cite: 154]
# Gracz (P) jest odcięty od Kolekcjonerek (C) i Wyjścia (E)
cat > maps/error_no_path.ber << EOF
1111111
1P010C1
10010E1
1111111
EOF

# [cite_start]7. Zły znak w mapie (np. 'X') [cite: 137]
cat > maps/error_chars.ber << EOF
11111
1P0X1
100E1
11111
EOF

# [cite_start]8. Brak wyjścia (E) [cite: 149]
cat > maps/error_no_exit.ber << EOF
11111
1P0C1
10001
11111
EOF

# [cite_start]9. Zduplikowany gracz (Dwa 'P') [cite: 149, 151]
cat > maps/error_double_player.ber << EOF
11111
1P0C1
100E1
1P111
EOF

echo "Gotowe! Mapy znajdują się w folderze 'maps/'."
