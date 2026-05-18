#include "servers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const struct server *get_busiest_server(const struct server *servers, unsigned int count) {
    if (servers == NULL)
        return 0;

    const struct server *busiest = &servers[0];

    for (int i = 1; i < count; i++) {
        if (servers[i].req_per_sec > busiest->req_per_sec) {
            busiest = &servers[i];
        }
    }
    return busiest;
}

struct server *get_servers_in_location(const struct server *servers, unsigned int count, const char *location) {
    unsigned int match = 0;

    for (unsigned int i = 0; i < count; i++) {
        if (strcmp(servers[i].location, location))
            match++;
    }

    struct server *subset = malloc(match * sizeof(struct server));
    unsigned int   index  = 0;
    for (unsigned int i = 0; i < count; i++) {
        if (strcmp(servers[i].location, location) == 0) {
            subset[index] = servers[i];
            index++;
        }
    }
    return subset;
}

unsigned int filter_servers_by_utilization(struct server *servers, unsigned int count, unsigned int max_utilization) {
    unsigned int counter = 0;
    for (unsigned int i = 0; i < count; i++) {
        if (servers[i].utilization <= max_utilization) {
            servers[counter++] = servers[i];
        }
    }
    return counter;
}

// helpers provided by us

void print_server(const char *description, struct server s) {
    printf("%s{ .req_per_sec = %3u, .utilization = %3u, .location = \"%s\" }\n",
           description,
           s.req_per_sec,
           s.utilization,
           s.location);
}

void print_servers(const char *description, const struct server *servers, unsigned int count) {
    for (unsigned int i = 0; i < count; ++i) {
        print_server(description, servers[i]);
    }
}
