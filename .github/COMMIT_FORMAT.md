Commit Message Formatting
=========================

*Based on the [Git Commit Msg][karma-git-format] format described by Karma.*

## Format of a commit message:

First line cannot be longer than 70 characters, second line is always
blank and other lines should be wrapped at 80 characters.

```
<type>(<scope>): <subject>

<body>

<footer>
```

### Message subject

A message subject is required and **must not** be proceeded by a
newline. The contents of a message subject should not be longer than 70
characters and should not wrap onto the next line. If a message subject
is too long, then it should be made smaller and a more verbose message
should be in the [message body][#message-body].

**Allowed `<type>` values:**

* **feat** (new feature)
* **fix** (bug fix)
* **docs** (changes to documentation)
* **style** (formatting, missing semi colons, etc; no code change)
* **refactor** (refactoring production code)
* **test** (adding missing tests, refactoring tests; no production code change)
* **chore** (updating grunt tasks etc; no production code change)

**Example `<scope>` values:**
* init
* runner
* watcher
* config
* web-server
* proxy
* etc.

*The `<scope>` can be empty (eg. if the change is a global or difficult to
assign to a single component), in which case the parentheses are
omitted.*

### Message body

A message body is optional and must be proceeded by a new line after the
message subject. The contents of the message body should be wrapped at 80
characters.

A message body should:

* use the imperative, present tense: “change” not “changed” nor “changes”
* include motivation for the change and contrasts with previous behavior

***For more info about message body, see:***
* http://365git.tumblr.com/post/3308646748/writing-git-commit-messages
* http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html

### Message footer

A message footer is optional and must be proceeded by a new line after the
message body. The contents of the message footer should be wrapped at 80
characters.

A message footer could include the following:

**Referencing issues:**

Closed issues should be listed on a separate line in the footer prefixed
with "Closes" keyword like this:

```
Closes #234
```

or in case of multiple issues:

```
Closes #123, #245, #992
```

**Breaking changes:**

All breaking changes have to be mentioned in footer with the description
of the change, justification and migration notes.

```
BREAKING CHANGE:

`port-runner` command line option has changed to `runner-port`, so that
it is
consistent with the configuration file syntax.

To migrate your project, change all the commands, where you use
`--port-runner` to `--runner-port`.

```

[karma-git-format]: http://karma-runner.github.io/0.10/dev/git-commit-msg.html
