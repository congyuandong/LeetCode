'use strict';
/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
const hammingDistance = (x, y) => {
	let counter = 0;

	while (x !== 0 || y !== 0) {
		if (x % 2 !== y % 2) {
        	counter += 1;
    	}
		x = parseInt(x/2, 10);
		y = parseInt(y/2, 10);
	}

	return counter;
};

console.log(hammingDistance(1, 4));