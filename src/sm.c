#include <stdio.h>
#include <unistd.h>

static char state_str[4][10] = {"IDLE", "CONFIGURE", "START", "STOP"};

typedef enum
{
    IDLE,
    CONFIGURE,
    START,
    STOP
} machine_state;

typedef enum
{
    CELL_SETUP_REQ,
    CELL_ACTIVATE_REQ,
    CELL_DEACTIVATE_REQ,
    CELL_RELEASE_REQ
} machine_req;

machine_state cell_setup_req()
{
    machine_state next_state = CONFIGURE;
    sleep(3);
    printf("%s: change state to %s\n", __func__, state_str[next_state]);
    return next_state;
}

machine_state cell_activate_req()
{
    machine_state next_state = START;
    sleep(3);
    printf("%s: change state to %s\n", __func__, state_str[next_state]);
    return next_state;
}

machine_state cell_deactivate_req()
{
    machine_state next_state = STOP;
    sleep(3);
    printf("%s: change state to %s\n", __func__, state_str[next_state]);
    return next_state;
}

machine_state cell_release_req()
{
    machine_state next_state = IDLE;
    sleep(3);
    printf("%s: change state to %s\n", __func__, state_str[next_state]);
    return next_state;
}

typedef machine_state (*fp)();

typedef struct
{
    machine_req req;
    fp handler;
} req_handler;

typedef struct
{
    machine_state state;
    req_handler *req_h;
} state_handler;

req_handler idle_handle[] = {{CELL_SETUP_REQ, cell_setup_req}};
req_handler configure_handle[] = {{CELL_ACTIVATE_REQ, cell_activate_req}};
req_handler start_handle[] = {{CELL_DEACTIVATE_REQ, cell_deactivate_req}};
req_handler stop_handle[] = {{CELL_RELEASE_REQ, cell_release_req}};

static state_handler statHandler[] = {{IDLE, idle_handle}, {START, configure_handle}, {START, start_handle}, {STOP, stop_handle}};

int main()
{
    machine_state init_state = IDLE;
    machine_state now_state = init_state;
    while (1)
    {
        req_handler *init_handler = statHandler[now_state].req_h;
        now_state = init_handler[0].handler();
    }
    return 0;
}