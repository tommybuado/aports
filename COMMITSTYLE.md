Policy for commits in aports
============================

This document defines policy for organizing and titling commits for
inclusion in aports.

Glossary
---------

Definition used for the following terms.

##### Repository

Where the aport resides, it is the penultimate repository in the path of
the aport.

Example: `main/foo/APKBUILD`, `main` is the repository

##### Aport

Directory inside the repository that contains a build recipe with metadata
(APKBUILD) and auxiliary files.

The name of the directory and the value of the variable `pkgname` in the
build recipe **must** match.

Example: `main/foo/APKBUILD`, `foo` is the aport

##### Commits

Set of changes to files as recorded by git with other metadata like title,
message and an autogenerated ID.

##### Merge Request

Proposal of a set of commits to be merged into a branch of a repository.

This is what maintainers review, and what Continous Integration checks to
guarantee it won't break anything.

In Alpine Linux' aports terms this is commonly the `master` branch of the
repo. Other branches like `3.X-stable` are used to push to released versions.

Organizing
----------

Commits should be split by function and what aport they change, one commit
per aport changed, and one commit per type of change.

Commits that are related to the same aport or are closely related must be
under the same Merge Request.

Exceptions to these organization rules may apply depending on the situation,
as noted below.

Commit types
------------

Different sets of changes in a commit award a different type that has a
distinct template, rules and exceptions to follow when organizing and titling.

---

### Upgrade

Increases the value of `pkgver`, and sets the value of `pkgrel` to 0.

###### Template

- `$repository/$pkgname: upgrade to $pkgver`
  
Example: `main/foo: upgrade to 2.0.0`

###### Rules

One commit per upgraded aport.

###### Exceptions

Upgrading lots of aports that are maintained upstream in lockstep (same version
and released at the same time) can be all in the same commit

Example: KDE Plasma Framework

---

### Downgrade

Decreases the value of `pkgver`, and increases the value of `pkgrel` by 1 in 
relation to the value of `pkgrel` before the last upgrade.

###### Template

- `$repository/$pkgname: downgrade to $pkgver`

Example: `main/foo: downgrade to 1.9.8`

###### Rules

One commit per downgraded aport.

---

### Move

Moves an aport from one repository to another.

###### Template

- `$newrepository/$pkgname: move from $oldrepository`

Example: `community/foo: move from main`

###### Rules

One commit per moved aport.

---

### Rename

Renames an aport.

###### Template

- `$repository/$newpkgname: rename from $oldpkgname`

Example: `community/bar: rename from foo`

###### Rules

One commit per renamed aport.

---

### Add

Introduces a new aport.

###### Template

- `$repository/$pkgname: new aport`

Example: `testing/bar: new aport`

###### Rules

One commit per aport introduced.

---

### Remove

Removes an aport from aports altogether.

#### Template

- `$repository/$pkgname: remove`

Example: `community/baz: remove`

#### Rules

One commit per removed aport.

---

### Rebuilds

Only increasing the value of `pkgrel` by 1.

#### Template

- `$repository/$pkgname: rebuild <reason-if-exists>`

Example: `community/foo: rebuild`

#### Rules

One commit per rebuilt aport.

#### Exceptions

When various aports need to be rebuilt for the same reason the commit can
hold all `Rebuilds` but split instead by repository.

Example: `community/*: rebuild for so:libfoo.so.2`

---

### Addition of maintainership

Adding yourself as maintainer.

#### Template

- `$repository/$pkgname: take over maintainership`

Example: `community/foo: take over maintainership`

#### Rules

One commit per aport assumed maintainership of.

---

### Removal of maintainership

Removing yourself as maintainer.

#### Template

- `$repository/$pkgname: drop maintainership`

Example: `community/foo: drop maintainership`

#### Rules

One commit per aport maintainership is removed from.

#### Exceptions

When removing maintainership from all aports you maintain, the commit can
hold all maintainership removals but instead be split by repository.

Example: `community/*: drop maintainership`

<!--
Missing improvements
Also missing tree-wide changes like usage of abuild-meson instead of meson
-->

---

### Other

Any set of changes not specified above falls under this type.

#### Template

If the commit changes an aport:

- `$repository/$pkgname: <action>`

If the commit changes anything else in the repository:

- `$directory_or_file: <action>`
    - If the file is inside a directory use the directory, if inside a file use the name of the file

`<action>` is what is the commit is doing. Be **short** and **direct**.

Examples:

- `main/foo: fix policy violations`
- `scripts/: enable compilation under mips64el`

#### Rules

It is **essential** to include reasoning for the changes in the body of the
commit.

Universal Title writing rules
-----------------------------

Applies to all commits, regardless of type.

### Imperative, Present Tense

Use the Present Tense and the Imperative mood

Examples:

- `main/foo: remove stale patches`
- `community/bar: patch CVE-YYYY-XXXXX`
- `testing/baz: fix policy violations`

### Lowercase, No dot

Text after the colon must start in lowercase and have no dot at the end.

### Direct, Short

Focus on **what** the commit does and use as few words as possible.

If possible also tell **why**.

Good examples:

- `main/foo: fix build under gcc-10`
    - `fix build` is **what**
    - `under gcc-10` is **why**
- `main/foo: disable support for X`
    - `disable support for X` is **what**
- `main/foo: add fish completion`
    - `add fish completion` is **what**
- `main/foo: enable on x86`
    - `enable on x86` is **what**
- `main/foo: rebuild for so:foo.so.2`
    - `rebuild` is **what**
    - `for so:foo.so.2` is **why**

They are short and concise, they tell **what** the commit did. If given
the opportunity also tell **why**.

The **how** and a clear **why** is handled by the commit body and changes.

### Assume basic knowledge, Avoid unnecessary explanations

The reader does not need to be told how the complex details of something work,
just that it was the reason the change was done.

Example:  

Don't tell the user how sonames work and how an ELF binary finds libraries
to load via the soname, just tell the soname has changed and thus a rebuild was
required.
