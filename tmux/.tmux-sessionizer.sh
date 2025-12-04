#!/bin/bash

# Enhanced tmux session manager with zsh support
# Features: auto-zsh, session listing, session deletion

SCRIPT_NAME="tmux-sessionizer"

# Function to display usage
usage() {
  echo "Usage: $SCRIPT_NAME [OPTIONS] [session_name]"
  echo "Options:"
  echo "  -l, --list     List all tmux sessions"
  echo "  -d, --delete   Delete a session"
  echo "  -h, --help     Show this help message"
  echo ""
  echo "Examples:"
  echo "  $SCRIPT_NAME                    # Prompt for session name"
  echo "  $SCRIPT_NAME mysession          # Create/attach to 'mysession'"
  echo "  $SCRIPT_NAME -l                 # List sessions"
  echo "  $SCRIPT_NAME -d oldsession      # Delete 'oldsession'"
  exit 1
}

# Function to check if tmux is installed
check_tmux_installed() {
  if ! command -v tmux &>/dev/null; then
    echo "Error: tmux is not installed!"
    echo "Install it with: sudo dnf install tmux"
    exit 1
  fi
}

# Function to check if zsh is installed
check_zsh_installed() {
  if ! command -v zsh &>/dev/null; then
    echo "Error: zsh is not installed!"
    echo "Install it with: sudo dnf install zsh"
    exit 1
  fi
}

# Function to list sessions
list_sessions() {
  echo "Available tmux sessions:"
  tmux list-sessions 2>/dev/null || echo "No sessions found"
  exit 0
}

# Function to delete session
delete_session() {
  local session_name="$1"
  if [ -z "$session_name" ]; then
    read -p "Enter session name to delete: " session_name
  fi

  if tmux has-session -t "$session_name" 2>/dev/null; then
    echo "Deleting session '$session_name'..."
    tmux kill-session -t "$session_name"
    echo "Session '$session_name' deleted."
  else
    echo "Session '$session_name' does not exist."
    exit 1
  fi
}

# Function to attach to existing session or create new one
manage_session() {
  local session_name="$1"

  # Check if session exists
  if tmux has-session -t "$session_name" 2>/dev/null; then
    echo "Session '$session_name' already exists. Attaching..."
    # Ensure zsh is used for existing sessions too
    tmux set-option -t "$session_name" default-shell /bin/zsh
    tmux attach-session -t "$session_name"
  else
    echo "Creating new session '$session_name' with zsh..."

    # Create new session with zsh as default shell
    tmux new-session -d -s "$session_name" -c "$HOME" -e SHELL=/bin/zsh

    # Set the default command to zsh for all windows in this session
    tmux set-option -t "$session_name" default-shell /bin/zsh

    # Attach to the new session
    tmux attach-session -t "$session_name"
  fi
}

# Parse command line arguments
case "${1:-}" in
-h | --help)
  usage
  ;;
-l | --list)
  list_sessions
  ;;
-d | --delete)
  check_tmux_installed
  check_zsh_installed
  delete_session "$2"
  ;;
"")
  # No arguments - prompt for session name
  check_tmux_installed
  check_zsh_installed
  echo "Available tmux sessions:"
  tmux list-sessions 2>/dev/null || echo "No sessions found"
  echo
  read -p "Enter session name: " session_name

  if [ -z "$session_name" ]; then
    echo "Error: Session name cannot be empty!"
    exit 1
  fi

  if [[ ! "$session_name" =~ ^[a-zA-Z0-9_-]+$ ]]; then
    echo "Error: Invalid session name!"
    exit 1
  fi

  manage_session "$session_name"
  ;;
*)
  # Session name provided as argument
  check_tmux_installed
  check_zsh_installed
  session_name="$1"

  if [[ ! "$session_name" =~ ^[a-zA-Z0-9_-]+$ ]]; then
    echo "Error: Invalid session name!"
    exit 1
  fi

  manage_session "$session_name"
  ;;
esac
