/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:55:04 by pcamaren          #+#    #+#             */
/*   Updated: 2021/10/06 15:40:05 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Merge Function
void merge(t_stack *arr, int l, int m, int r) 
{ 
    int i; 
    int j; 
    int k; 
    int n1;
    int n2; 
    n1 = m - l + 1;
    n2 = r - m;
    int L[n1];
    int R[n2]; 

    
    i = 0;
    while (i < n1)
    {
        L[i] = arr->array[l + i];
        i++;
    }
    j = 0;
    while (j < n2)
    {
        R[j] = arr->array[m + 1 + j];
        j++;
    }
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr->array[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr->array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr->array[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr->array[k] = R[j]; 
        j++; 
        k++;   
    } 
}

// Merge Sort Function in C 
void mergeSort(t_stack *arr, int l, int r) 
{ 
    int m;

    if (l < r) 
    { 
        m = l + (r - l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
        merge(arr, l, m, r); 
    } 
} 

t_stack dirty_sorting(t_stack stacka) 
{
    int arr_size; 
    int i;
    t_stack arr;

    i = 0;
    arr_size = stacka.size;
    arr = init_stack(arr_size);
    while(i < arr_size)
    {
        arr.array[i] = stacka.array[i];
        i++;
    }
    mergeSort(&arr, 0, arr_size - 1); 
    return (arr); 
}