/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:42:17 by pcamaren          #+#    #+#             */
/*   Updated: 2021/09/29 20:00:54 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
Ok lets write the algorithm we have so far

1. Send the top three numbers to stack B
2. Then sort the three numbers on stack B decreasingly, this will max take 2 moves
	(we are going to call the top number x and the bottom number y, and the midpoint
	number m,
3. Now we are going to examine the top number on stack A and compare it to the top and bottom of stack B, we are going to call this top number a,
	3.1 if it is larger than x
		pb
	3.2 if a < y, then we
		pb
		rb
	3.3 Check if the end of the stack A(call this c) or if the number after a (call bb), fullfill the condition for 3.1 or 3.2
		if b fullfills the condition for 3.1 or 3.2
			sa
			then apply 3.1 or 3.2, the one that fits
		if c > a or c < a
			rra
			then apply either 3.1 or 3.2, the one that fits
	3.4 if y < a < x
			check if it bigger or smaller than middle point
				3.3.1 if a > middle point
					3.3.1.1check how many positions it would need to move to be
					sorted and keep track of this number, let call it (distance_a)
					3.3.1.2 check if b is  bigger than a and calculate the number
					of positions if would be to be sorted, and check if it is
					less than (distance_a - 1)
						if (distance_b < (distance_a - 1))
							sa,
					3.3.1.3 else check if c is bigger than a and calculate the
					number of positions it needs to move to be sorted, and call
					that distance_c
						if (distance_c < (distance_a - 1)
							rra
					3.3.1.4 then'
						rb * (distance_a/b/c);
						pb
						while (b > a && b < y)
							pb
						while (c > a && b < y)
							rra
							pb
						then rrb (distance_a/b/c);
							then repeat from number 3.
				3.3.2 if a < middle point
					3.3.2.1check how many positions it would need to move to be
					sorted and keep track of this number as distance_a
					3.3.2.2 now check if b is smaller than a, and then calculate
					the number of positions it would have to move and call this
					number distance_b
						if (distance_b < (distance_a - 1))
							sa
					3.3.2.3 else, check is c is smaller than a, and calculate
					distance_c
						if (distance_c < (distance_a -1))
							rra
					3.3.2.4 then'
						rrb * (distance_a/b/c)
						pb
						(update values of a, b, c, x, y)
						while (b < a && b > y)
							pb
						while (c > a && b < y)
							rra
							pb
						then rrb (distance_a/b/c/)
							then repeat from number 3

							**/
