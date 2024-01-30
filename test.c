#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *str) {
  size_t i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

size_t ft_strlcpy(char *dest, const char *src, size_t sizedest) {
  size_t i;

  i = 0;
  if (sizedest > 0) {
    while (src[i] && i + 1 < sizedest) {
      dest[i] = src[i];
      i++;
    }
    dest[i] = '\0';
  }
  return (ft_strlen(src));
}

int ft_atoi(const char *str) {
  int i;
  int sig;
  int result;
  char *str1;

  str1 = (char *)str;
  i = 0;
  sig = 1;
  result = 0;
  while ((str1[i] >= 9 && str1[i] <= 13) || (str1[i] == ' '))
    i++;
  if (str1[i] == '-' || str1[i] == '+') {
    if (str1[i] == '-')
      sig = -1;
    i++;
  }
  while (str1[i] >= '0' && str1[i] <= '9') {
    result = result * 10 + str1[i] - '0';
    i++;
  }
  return (result * sig);
}

static size_t ft_countword(char const *s, char c) {
  size_t count;

  count = 0;
  while (*s) {
    while (*s == c)
      s++;
    if (*s != '\0')
      count++;
    while (*s && *s != c)
      s++;
  }
  return (count);
}

void cleanup(char **lst) {
  int i;

  i = 0;
  while (lst[i])
    free(lst[i++]);
  free(lst);
}

char **filler(const char *s, char **lst, char c) {
  size_t word_len;
  int i;

  i = 0;
  while (*s) {
    while (*s == c)
      s++;
    if (*s != '\0') {
      word_len = 0;
      while (s[word_len] != '\0' && s[word_len] != c)
        word_len++;
      lst[i] = (char *)malloc(sizeof(char) * (word_len + 1));
      if (!lst[i]) {
        return (cleanup(lst), NULL);
      }
      ft_strlcpy(lst[i], s, word_len + 1);
      i++;
      s += word_len;
    }
  }
  lst[i] = NULL;
  return (lst);
}

char **ft_split(char const *s, char c) {
  char **lst;
  int wordcount;

  if (!s)
    return (NULL);
  wordcount = ft_countword(s, c);
  lst = (char **)malloc((wordcount + 1) * sizeof(char *));
  if (!lst)
    return (NULL);
  if (!filler(s, lst, c))
    return (NULL);
  return (lst);
}

int main(int argc, char **argv) {
  int k = argc;
  k++;
  char **str = ft_split(argv[1], ',');
  int i = 0;
  int j = 1;
  char *ptr;
  while (*str[i] != '\0') {
    i = ft_atoi(str[i]);
    ptr = str[i];
    printf("el digito %d, es: %d", j, i);
    i++;
    j++;
    free(ptr);
  }
  return (0);
}
