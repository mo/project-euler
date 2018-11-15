import R from 'ramda';

export const problem1 = (n: number) =>
    R.pipe<number, number[], number[], number>(
        R.range(0),
        R.filter((i: number) => i % 3 === 0 || i % 5 === 0),
        R.sum
    )(n);
