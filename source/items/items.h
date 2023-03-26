enum states {
    unknown,
    failed,
    staged,
    skipped,
    processing,
    successful
};

enum shifts {
    begin,
    stage,
    resume,
    exit,
    stop,
}