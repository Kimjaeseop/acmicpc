#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define STR_MAX 1024
#define F_MAX 128

typedef struct tree {
	char cur_dir[STR_MAX]; // current directory
	char f_list[F_MAX][F_MAX]; // file list
	char d_list[F_MAX][F_MAX]; // directory list
	int f_cnt;
	int d_cnt;
	time_t m_time;
	int depth;

	struct tree *ch_node[500];
} tree; 

tree *node;
char operation[8];
char root_dir[STR_MAX]; // root dir
char input[STR_MAX];
char *tok; // 쉘 인풋 문자열 토크나이징을 위한 문자열

void read_dir(int depth, char dir_name[STR_MAX], tree *node) {
	int C = 0;
	struct stat statbuf;
	char r_path[STR_MAX]; // real_path
	struct dirent **n_list;

	node->depth = depth;
	strcpy(node->cur_dir, dir_name);

	printf("cur_dir : %s\n", node->cur_dir);
	
	if ((C = scandir(dir_name, &n_list, NULL, alphasort)) == -1) {
		fprintf(stderr, "scandir error for %s\n", dir_name);
		exit(0);
	}

	for(int i = 0; i < C; i++) {
		if (*(n_list[i]->d_name) == '.') {
			continue ;
		}

		sprintf(r_path, "%s/%s", node->cur_dir, n_list[i]->d_name); // 이 부분에서 해주는 이유는 여기서 안해주면 lstat에서 서브디렉토리 파일 읽을 때 에러남

		if (lstat(r_path, &statbuf) == -1) {
			fprintf(stderr, "lstat error for %s\n", n_list[i]->d_name);
			exit(0);
		}

		if (S_ISDIR(statbuf.st_mode)) { // 디렉터리
			// 노드의 디렉터리 리스트에 추가
			strcpy(node->d_list[(node->d_cnt)], n_list[i]->d_name);

			if (node->ch_node[(node->d_cnt)] == NULL) {
				node->ch_node[(node->d_cnt)] = (tree *) malloc (sizeof(tree));
			}

			read_dir(depth + 1, r_path, node->ch_node[(node->d_cnt++)]); // 하위디렉터리를 읽기 위해 재귀호출
		}
		else if (S_ISREG(statbuf.st_mode)) {
			printf("file : %s\n", n_list[i]->d_name);
		}
	}
}

int main(void)
{
	node = (tree *) malloc (sizeof(tree));
	getcwd(root_dir, STR_MAX);

	read_dir(0, root_dir, node);

	while (1) {
		printf("20152365>");

		int i = 0;

		char FILENAME[STR_MAX] = { 0, };
		char *TIME = (char *) malloc (sizeof(STR_MAX));

		fgets(input, STR_MAX, stdin);

		tok = strtok(input, " ");
		strcpy(operation, tok);

		if (!strcmp(operation, "delete")) {
			for (i = 1; ; i++) {
				tok = strtok(NULL, " ");

				if (tok == NULL) {
					break;
				}

				if (i == 1) {
					strcpy(FILENAME, tok);
				}
				else {
					sprintf(TIME, "%s %s", TIME, tok);
				}
			}

			while ((*TIME) == ' ') {
				TIME++;
			}

			printf("FILENAME : %s\n", FILENAME);
			printf("TIME : %s\n", TIME);
		}
		else if (!strcmp(operation, "size")) {
		}
		else if (!strcmp(operation, "recover")) {
		}
		else if (!strcmp(operation, "tree")) {
		}
		else if (!strcmp(operation, "exit")) {
			return 0;
		}
		else if (!strcmp(operation, "help")) {
		}
	}


	return 0;
}
