#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	printf("FileEditor made by ImKool-Gitch, reads one line at a time, doesnt support arroy keys\n");
	if (argc <= 1)
  {
      printf("Error ! Enter a file name !\n");
      printf("To find list of commands type -h\n");
      return -1;
  }
	else if (strcmp(argv[1], "-h") == 0)
  {
      printf("List of commands: \n");
      printf("-cf: creates file but doesnt open it\n-h: shows this\n");
      return 0;
  }
	else if (strcmp(argv[1], "-cf") == 0)
	{
			FILE* file_create = fopen(argv[2], "w");
			fclose(file_create);
			return 0;
	}
	char dir_path[500];
	strcpy(dir_path, argv[1]);
	FILE* file_point = fopen(dir_path, "w");
	if (file_point != NULL)
	{
		printf("File '%s' was created succesfully !\n", dir_path);
	}
	else
	{
		printf("There was an error when creating the file !\n");
		printf("Aborting program !\n");
		return -1;
	}
	char* FileWrite = malloc(1000);
	printf("Enter some text to start writing to the file. Enter 'ExitP' to exit the program\n");
	while(1)
	{
		FileWrite = realloc(FileWrite, 1000);
		scanf("%s", FileWrite);
		FileWrite = realloc(FileWrite, strlen(FileWrite));
		if (strcmp(FileWrite, "ExitP") == 0)
		{
			fclose(file_point);
			free(FileWrite);
			printf("Exiting program !\n");
			return 0;
		}
		fprintf(file_point, "%s\n", FileWrite);
	}
}
