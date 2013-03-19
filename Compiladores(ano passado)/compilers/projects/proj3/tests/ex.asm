; tabela de mapeamento:
 a:4
 b:8
 c:12
 d:16
 e:20
; ---------------------

; para 4 registos (e algumas optimizacoes)

// b = b + 1
	r0 = ARP + 8	// 			» b
	r0 = *r0	// access 'b'		[ r0=b ]
	r0 = r0 + 1	//
// a = b + c
	r1 = ARP + 12	// 			» c
	r1 = *r1	// access 'c'		[ r0=b, r1=c ]
	r2 = r0 + r1	// got 'b' and 'c'
	r3 = ARP + 4	// 			» a
	*r3 = r2	// store on 'a'		[ r0=b, r1=c, r2, r3=&a ]
// d = c
	r2 = ARP + 16	// 			» d
	*r2 = r1	// store on 'd'		[ r0=b, r1=c, r2=&d, r3=&a ]
// e = a + b
	r3 = *r3	// access 'a' 		[ r0=b, r1=c, r2=&d, r3=a ]
	r1 = r3 + r0	// got 'a' and 'b'
	r2 = ARP + 20	// 			» e
	*r2 = r1	// store on 'e'		[ r0=b, r1, r2=&e, r3=a ]





check the stack:
 -> 1st for the rhs variables
 -> 2nd the lhs variables



; Number of Registers: 4 	// dado como input
; Number Load Operations: 2 	// contado no C3E (right handed side)
; Number Store Operations: 4 	// contado no C3E (left handed side)
