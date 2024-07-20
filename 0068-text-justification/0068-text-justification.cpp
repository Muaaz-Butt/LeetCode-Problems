class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> currentLine;
        int currentLineLength = 0;

        for (const string& word : words) {
            if (currentLineLength + word.length() + currentLine.size() > maxWidth) {
                int totalSpaces = maxWidth - currentLineLength;
                int spacesBetweenWords = currentLine.size() - 1;

                if (spacesBetweenWords == 0) {
                    result.push_back(currentLine[0] + string(totalSpaces, ' '));
                } else {
                    int spacesPerSlot = totalSpaces / spacesBetweenWords;
                    int extraSpaces = totalSpaces % spacesBetweenWords;

                    string line;
                    for (int i = 0; i < currentLine.size(); ++i) {
                        line += currentLine[i];
                        if (i < spacesBetweenWords) {
                            line += string(spacesPerSlot + (i < extraSpaces ? 1 : 0), ' ');
                        }
                    }
                    result.push_back(line);
                }

                currentLine.clear();
                currentLineLength = 0;
            }

            currentLine.push_back(word);
            currentLineLength += word.length();
        }

        string lastLine;
        for (int i = 0; i < currentLine.size(); ++i) {
            lastLine += currentLine[i];
            if (i < currentLine.size() - 1) {
                lastLine += " ";
            }
        }
        lastLine += string(maxWidth - lastLine.length(), ' ');
        result.push_back(lastLine);

        return result;
    }
};