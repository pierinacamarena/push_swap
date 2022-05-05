/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirty_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	merge_complement(t_dirtysort *dirty, int *arr)
{
	while (dirty->i < dirty->n1)
	{
		arr[dirty->k] = dirty->larr[dirty->i];
		dirty->i++;
		dirty->k++;
	}
	while (dirty->j < dirty->n2)
	{
		arr[dirty->k] = dirty->rarr[dirty->j];
		dirty->j++;
		dirty->k++;
	}
}

void	merge_helper(t_dirtysort *dirty, int *arr, int l)
{
	dirty->i = 0;
	dirty->j = 0;
	dirty->k = l;
	while (dirty->i < dirty->n1 && dirty->j < dirty->n2)
	{
		if (dirty->larr[dirty->i] <= dirty->rarr[dirty->j])
		{
			arr[dirty->k] = dirty->larr[dirty->i];
			dirty->i++;
		}
		else
		{
			arr[dirty->k] = dirty->rarr[dirty->j];
			dirty->j++;
		}
		dirty->k++;
	}
	merge_complement(dirty, arr);
}

void	merge(int *arr, int l, int m, int r)
{
	t_dirtysort	dirty;

	dirty.i = 0;
	dirty.n1 = m - l + 1;
	dirty.n2 = r - m;
	dirty.larr = (int *)malloc(sizeof(int) * dirty.n1);
	dirty.rarr = (int *)malloc(sizeof(int) * dirty.n2);
	while (dirty.i < dirty.n1)
	{
		dirty.larr[dirty.i] = arr[l + dirty.i];
		dirty.i++;
	}
	dirty.j = 0;
	while (dirty.j < dirty.n2)
	{
		dirty.rarr[dirty.j] = arr[m + 1 + dirty.j];
		dirty.j++;
	}
	merge_helper(&dirty, arr, l);
	free(dirty.larr);
	free(dirty.rarr);
}

void	merge_sort(int *arr, int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int	*dirty_sorting(t_stack stacka)
{
	int	arr_size;
	int	i;
	int	*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * stacka.size);
	arr_size = stacka.size;
	while (i < arr_size)
	{
		arr[i] = stacka.array[i];
		i++;
	}
	merge_sort(arr, 0, arr_size - 1);
	return (arr);
}
