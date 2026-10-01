#!/bin/bash
BASE="$(cd "$(dirname "$0")" && pwd)"

run_c() {
    local dir="$1"; local src="$2"; local exe="$3"; shift 3
    cd "$BASE/$dir" || return
    if [ ! -x "$exe" ]; then
        gcc "$src" -o "$exe" || { read -p "Press Enter..."; return; }
    fi
    ./$exe "$@"
    echo
    read -p "Press Enter to return to menu..."
}

co1_menu() {
    while true; do
        clear
        echo "=============================================="
        echo "       CO1 - SYSTEM CALLS & SHELL"
        echo "=============================================="
        echo "1. System Calls Demo"
        echo "2. System Information Shell"
        echo "3. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO1_System_Calls_Shell" system_calls.c system_calls ;;
            2) cd "$BASE/CO1_System_Calls_Shell" && bash system_info.sh; echo; read -p "Press Enter..." ;;
            3) return;; *) echo "Invalid choice"; sleep 1;;
        esac
    done
}
co2_menu() {
    while true; do
        clear; echo "=============================================="; echo "          CO2 - PROCESS MANAGEMENT"; echo "=============================================="
        echo "1. Process Creation"; echo "2. Process Execution"; echo "3. Process Termination"; echo "4. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO2_Process_Management" process_creation.c process_creation;;
            2) run_c "CO2_Process_Management" process_exec.c process_exec;;
            3) run_c "CO2_Process_Management" process_termination.c process_termination;;
            4) return;; *) echo "Invalid choice"; sleep 1;; esac
    done
}
co3_menu() {
    while true; do
        clear; echo "=============================================="; echo "          CO3 - COMMUNICATION / IPC"; echo "=============================================="
        echo "1. Pipe - Enter your own message"; echo "2. FIFO - Enter your own message"; echo "3. Signal - Press Ctrl+C"; echo "4. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO3_Communication" pipe_demo.c pipe_demo;;
            2)
                clear
                echo "=============================================="
                echo "          FIFO TWO-TERMINAL DEMO"
                echo "=============================================="
                echo ""
                echo "Open a SECOND terminal and go to this folder:"
                echo "  cd "$ROOT/CO3_Communication""
                echo ""
                echo "TERMINAL 1 (Reader):"
                echo "  ./fifo_demo reader"
                echo ""
                echo "TERMINAL 2 (Writer):"
                echo "  ./fifo_demo writer"
                echo ""
                echo "Type your message in Terminal 2."
                echo "The received message will appear in Terminal 1."
                echo ""
                echo "Press Enter here when you are finished..."
                read
                ;;
            3) run_c "CO3_Communication" signal_demo.c signal_demo;;
            4) return;; *) echo "Invalid choice"; sleep 1;; esac
    done
}
co4_menu() {
    while true; do
        clear; echo "=============================================="; echo "          CO4 - MEMORY MANAGEMENT"; echo "=============================================="
        echo "1. Copy-on-Write"; echo "2. Memory Maps"; echo "3. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO4_Memory_Management" copy_on_write.c copy_on_write;;
            2) run_c "CO4_Memory_Management" memory_maps.c memory_maps;;
            3) return;; *) echo "Invalid choice"; sleep 1;; esac
    done
}
co5_menu() {
    while true; do
        clear; echo "=============================================="; echo "          CO5 - FILE MANAGEMENT"; echo "=============================================="
        echo "1. File I/O"; echo "2. Directory Demo"; echo "3. Memory-Mapped File"; echo "4. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO5_File_Management" file_io.c file_io;;
            2) run_c "CO5_File_Management" directory_demo.c directory_demo;;
            3) run_c "CO5_File_Management" mmap_demo.c mmap_demo;;
            4) return;; *) echo "Invalid choice"; sleep 1;; esac
    done
}
co6_menu() {
    while true; do
        clear; echo "=============================================="; echo "          CO6 - SYNCHRONIZATION"; echo "=============================================="
        echo "1. Pthread Demo"; echo "2. Mutex Demo"; echo "3. Semaphore Demo"; echo "4. Condition Variable Demo"; echo "5. Race Condition"; echo "6. Back"
        read -p "Enter your choice: " c
        case $c in
            1) run_c "CO6_Synchronization" pthread_demo.c pthread_demo -lpthread;;
            2) run_c "CO6_Synchronization" mutex_demo.c mutex_demo -lpthread;;
            3) run_c "CO6_Synchronization" semaphore_demo.c semaphore_demo -lpthread;;
            4) run_c "CO6_Synchronization" condition_demo.c condition_demo -lpthread;;
            5) run_c "CO6_Synchronization" race_condition.c race_condition -lpthread;;
            6) return;; *) echo "Invalid choice"; sleep 1;; esac
    done
}
while true; do
    clear
    echo "=============================================="
    echo "        LINUX OS MANAGEMENT SYSTEM"
    echo "=============================================="
    echo "1. CO1 - System Calls & Shell"
    echo "2. CO2 - Process Management"
    echo "3. CO3 - Communication / IPC"
    echo "4. CO4 - Memory Management"
    echo "5. CO5 - File Management"
    echo "6. CO6 - Synchronization"
    echo "7. Exit"
    echo "=============================================="
    read -p "Enter your choice: " choice
    case $choice in
        1) co1_menu;; 2) co2_menu;; 3) co3_menu;; 4) co4_menu;; 5) co5_menu;; 6) co6_menu;;
        7) echo "Thank you!"; exit 0;; *) echo "Invalid choice"; sleep 1;;
    esac
done
