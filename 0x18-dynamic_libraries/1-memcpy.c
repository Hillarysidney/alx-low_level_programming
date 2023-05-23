#include "main.h"
/**
 *_memcpy -   copy number bytes form adress "from" to the adress "to"
 *@dest: content is to be copied
 *@src: Source of the data to be copied
 *@n: bytes of the memory
 *Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)

{
	unsigned int o;

	o = 0;
	while (o < n)  /*Delacring the WHILE*/
	{
		*(dest + o) = *(src + o); /*add 1 position dest and the src*/
		o++;

	} /*END WHILE*/


	return (dest);
}
