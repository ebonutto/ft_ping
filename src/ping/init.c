#include "ping.h"

#include <stddef.h> // NULL
#include <string.h> // memset()

static void ping_init_args(t_ping_ctx *ctx)
{
	ctx->progname = NULL;
	ctx->hostname = NULL;
	ctx->flags = 0;
	ctx->count = 0;
	ctx->interval = 1.0;
	ctx->ttl = 64;
	ctx->pattern = 0;
}

static void ping_init_socket(t_ping_ctx *ctx)
{
	ctx->sockfd = -1;
	memset(&ctx->addr, 0, sizeof(ctx->addr));
}

static void ping_init_stats(t_ping_ctx *ctx)
{
	ctx->send = 0;
	ctx->received = 0;
	ctx->rtt_min = -1.0;
	ctx->rtt_max = -1.0;
	ctx->rtt_sum = 0.0;
	ctx->rtt_sum_sq = 0.0;
}

void ping_init(t_ping_ctx *ctx)
{
	ping_init_args(ctx);
	ping_init_socket(ctx);
	ping_init_stats(ctx);
}
