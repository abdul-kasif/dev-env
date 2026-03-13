# Fedora Dev Setup

A simple script to quickly install common development tools on Fedora.

## Clone the Repository

```bash
git clone https://github.com/abdul-kasif/dev-env.git
cd dev-env/
chmod +x dev-run
```

## Usage

### List Available Applications

```bash
./dev-run --list
```

Displays all available applications that can be installed.

### Install an Application

```bash
./dev-run <application_name>
```

Example:

```bash
./dev-run docker
```

### Install All Applications

```bash
./dev-run
```

Runs all installation scripts inside the `run/` directory.

### Help

```bash
./dev-run --help
```

Shows the help menu with available commands.

## Notes

* Each application installer is stored inside the `run/` directory.
* Scripts inside `run/` are executed directly by `dev-run`.
* The system packages are updated automatically before installation.
