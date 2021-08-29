function reverseOnlyLetters(s: string): string {
    const myString = s.split("");
    const letters: string[] = [];
    const positions: number[] = [];
    for (let i = 0; i < myString.length; i++) {
        const curr = myString[i];
        if (/[a-zA-Z]/.test(curr)) {
            letters.push(curr);
            positions.push(i);
        }
    }
    positions.reverse().forEach((pos, index) => {
        myString[pos] = letters[index];
    });
    return myString.join("");
}
