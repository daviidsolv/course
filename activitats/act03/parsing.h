#ifndef PARSING_H_   /* Include guard */
#define PARSING_H_

int parseCommand(char *command, int debugMode);
int parseLine(char *line, int debugMode);
int parseErrors(char *command, int debugMode);

#endif // PARSING_H_