module.exports = {
    tabWidth: 2,
    printWidth: 300,
    trailingComma: "es5",
    bracketSpacing: false,
    overrides: [
        {
            files: ["*.ts", "*.js", "*.json"],
            options: {
                tabWidth: 4,
            },
        },
    ],
    endOfLine: "crlf",
};
