# Git Hooks

This directory contains custom git hooks for the repository.

## Setup

To enable these hooks, run:

```bash
git config core.hooksPath .githooks
```

## Available Hooks

### commit-msg

Validates that commit messages follow the
[Conventional Commits](https://www.conventionalcommits.org/) format.

**Format:**

```
<type>(<scope>): <subject>
```

**Valid types:** | Type | Description | Version Bump |
|------|-------------|--------------| | `feat` | A new feature | Minor | | `fix`
| A bug fix | Patch | | `perf` | Performance improvement | Patch | | `refactor`
| Code refactoring | Patch | | `docs` | Documentation only | None | | `style` |
Code style (formatting) | None | | `test` | Adding/updating tests | None | |
`chore` | Maintenance tasks | None | | `ci` | CI/CD changes | None | | `build` |
Build system changes | None | | `revert` | Reverting commits | None |

**Breaking changes:** Add `!` after type or scope:

```
feat!: redesign layer system
feat(oled)!: change display API
```

**Examples:**

```
feat(oled): add large ASCII art layer display
fix: correct debounce timing
docs: update README with flash instructions
```
