#include "test.h"

static int	g_seen = 0;

static void	count_one(void *content)
{
	(void)content;
	g_seen++;
}

static void	*shout(void *content)
{
	char	*s;

	s = ft_strdup((char *)content);
	if (s && s[0] >= 'a' && s[0] <= 'z')
		s[0] -= 32;
	return (s);
}

void	test_lst(void)
{
	t_list	*head;
	t_list	*mapped;

	printf("lst\n");
	head = ft_lstnew(ft_strdup("second"));
	check_str("ft_lstnew content", (char *)head->content, "second");
	check_int("ft_lstnew next is null", head->next == NULL, 1);
	ft_lstadd_front(&head, ft_lstnew(ft_strdup("first")));
	check_str("ft_lstadd_front", (char *)head->content, "first");
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("third")));
	check_int("ft_lstsize", ft_lstsize(head), 3);
	check_str("ft_lstlast", (char *)ft_lstlast(head)->content, "third");
	g_seen = 0;
	ft_lstiter(head, count_one);
	check_int("ft_lstiter visits all", g_seen, 3);
	mapped = ft_lstmap(head, shout, free);
	check_str("ft_lstmap first", (char *)mapped->content, "First");
	check_int("ft_lstmap keeps size", ft_lstsize(mapped), 3);
	ft_lstclear(&mapped, free);
	check_int("ft_lstclear nulls head", mapped == NULL, 1);
	ft_lstclear(&head, free);
	check_int("ft_lstclear empties the list", head == NULL, 1);
	head = ft_lstnew(ft_strdup("alone"));
	ft_lstdelone(head, free);
	check_int("ft_lstdelone on a lone node", 1, 1);
}
