function isMatch(s: string, p: string): boolean {
    if (p[1] === "*" && isMatch(s, p.slice(2))) {
        return true;
    } else {
        // exhaust all testing string
        if (s.length === 0) {
            return p.length === 0 || (p[1] === "*" && isMatch(s, p.slice(2)));
        }

        // special case
        if (p === ".*") {
            return true;
        }

        if (p.slice(0, 2) === ".*") {
            return isMatch(s.slice(1), p);
        }

        // exhaust all regex conditions
        if (p.length === 0) {
            return s.length === 0;
        }

        // base case
        if (p.length === 1) {
            return s.length === 1 && (s === p || p === ".");
        }

        // p is guaranteed to have more than 1 items since it passed base case
        // p[0] must be either a letter or a "."
        if (p[0] === s[0] || p[0] === ".") {
            if (p[1] === "*") {
                /**
                 * Two cases:
                 * 1. Matching the same character with "*"
                 * 2. First time matching a character
                 */
                if (s[0] === s[1]) {
                    // do not slice p since it is any match with "*"
                    if (!isMatch(s.slice(1), p)) {
                        return isMatch(s.slice(1), p.slice(2));
                    } else {
                        return true;
                    }
                } else {
                    return isMatch(s.slice(1), p.slice(2));
                }
            } else {
                return isMatch(s.slice(1), p.slice(1));
            }
        } else {
            return p[1] === "*" && isMatch(s, p.slice(2));
        }
    }
}
