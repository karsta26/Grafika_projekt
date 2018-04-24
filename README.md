# Obrazy 16-sto bitowe

Aplikacja ta umożliwia wczytanie obrazu 16-sto bitowego w formacie TIFF, jego konwersję z 16 bitów na 8 bitów oraz zapis w formacie jpg.

Aplikacja umożliwia następujące rodzaje konwersji:
- pełen zakres dynamiczny zdjęcia skompresowany liniowo z 16 bitów na 8 bitów,
- pełen zakres zdjęcia skompresowany z uwzględnieniem krzywej gamma z 16 na 8 bitów, przy czym istnieje możliwość regulacji parametru gamma,
- przeniesienie bez kompresji ośmiobitowej częsci informacji z obszaru szesnastobitowego.

W ostatnim przypadku istnieje możliwość wybrania, które bity mają zostać przeniesione, np. od 3 do 11.

Program rysuje również histogram jasności dla przetwarzanego obrazu.
