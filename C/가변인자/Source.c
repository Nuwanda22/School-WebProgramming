#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

typedef struct _string
{
	char ch;
	struct _string *next;
}String;

String *alloc(char ch)
{
	String *str = (String *)malloc(sizeof(String));
	str->ch = ch;
	str->next = NULL;

	return str;
}

void addChar(String **head, char character)
{
	String *temp = *head;
	String *str = alloc(character);
	
	if (temp == NULL){
		*head = str;
	}
	else{
		while (temp->next != NULL){
			temp = temp->next;
		}
		temp->next = str;
	}
}

void addString(String **head, char *string)
{
	String *temp = *head;

	for (int i = 0; string[i] != 0; i++){
		addChar(head, string[i]);
	}
}

void addDecimal(String **head, int decimal)
{
	char str[12]; //-2147483648 ~ 2147483647
	addString(head, itoa(decimal, str, 10));
}

void freeAll(String **head)
{
	String *prev;
	String *temp = *head;
	while (temp != NULL){
		prev = temp;
		temp = temp->next;
		free(prev);
	}
	*head = NULL;
}

char *listToString(String *head)
{
	char *string;
	int i = 0;
	int count = 0;
	
	String *temp = head;
	while (temp != NULL){
		count++;
		temp = temp->next;
	} // for (String *temp = head; temp != NULL; temp = temp->next) count++;
	
	string = (char *)calloc(count + 1, sizeof(char));
	
	temp = head;
	while (temp != NULL){
		string[i++] = temp->ch;
		temp = temp->next;
	} // for (String *temp = head, int i = 0; temp != NULL; temp = temp->next, i++) string[i] = temp->ch;
	string[i] = '\0';

	return string;
}

char *formatToString(char *format, ...)
{
	char *string;
	String *head = NULL;
	va_list ap;
	va_start(ap, format);
	for (int i = 0; format[i] != 0; i++){
		if (format[i] == '%'){
			i++;
			if (format[i] == 's'){
				char *temp = va_arg(ap, char*);
				if (temp == NULL){
					temp = "<null>";
				}
				addString(&head, temp);
			}
			else if (format[i] == 'd'){
				addDecimal(&head, va_arg(ap, int));
			}
			else if (format[i] == 'c'){
				addChar(&head, va_arg(ap, char));
			}
			else{
				addChar(&head, format[i]);
			}
		}
		else{
			addChar(&head, format[i]);
		}
	}
	va_end(ap);
	string = listToString(head);
	freeAll(&head);
	return string;
}

//void test(char *format, ...)
//{
//	va_list ap;
//	va_start(ap, format);
//	for (int i = 0; format[i] != 0; i++){
//		if (format[i] == '%'){
//			if (format[i + 1] == 's'){
//				char* ch = va_arg(ap, char*);
//				fputs(ch, stdout);
//				i++;
//			}
//		}
//		else{
//			fputc(format[i], stdout);
//		}
//	}
//	va_end(ap);
//}

#define ftos formatToString

int main()
{
	fputs(ftos("%s %c %d %% %m", NULL, 49, 100), stdout);
	return 0;
}