/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#include "taisei.h"

#include "tutorial_events.h"
#include "global.h"
#include "stagetext.h"
#include "common_tasks.h"

TASK(burst_fairy, { cmplx pos; cmplx dir; }) {
	Enemy *e = TASK_BIND_UNBOXED(create_enemy1c(ARGS.pos, 700, Fairy, NULL, 0));

	INVOKE_TASK_WHEN(&e->events.killed, common_drop_items, &e->pos, {
		.points = 1,
		.power = 1,
	});

	e->move.attraction_point = ARGS.pos + 120*I;
	e->move.attraction = 0.03;

	WAIT(60);

	play_sound("shot1");
	int n = 1.5 * global.diff - 1;

	for(int i = -n; i <= n; i++) {
		cmplx aim = cdir(carg(global.plr.pos - e->pos) + 0.2 * i);

		PROJECTILE(
			.proto = pp_crystal,
			.pos = e->pos,
			.color = RGB(0.2, 0.3, 0.5),
			.move = move_asymptotic_simple(aim * (2 + 0.5 * global.diff), 5),
		);
	}

	WAIT(1);

	e->move.attraction = 0;
	e->move.acceleration = 0.04 * ARGS.dir;
	e->move.retention = 1;

}

// opening. projectile bursts
TASK(burst_fairies_1, NO_ARGS) {
	for(int i = 3; i--;) {
		INVOKE_TASK(burst_fairy, VIEWPORT_W/2 + 70,  1 + 0.6*I);
		INVOKE_TASK(burst_fairy, VIEWPORT_W/2 - 70, -1 + 0.6*I);
		WAIT(25);
	}
}

DEFINE_EXTERN_TASK(tutorial_main) {
	INVOKE_TASK_DELAYED(100, burst_fairies_1);

	WAIT(1000);

	//WAIT_EVENT(&global.dialog->events.fadeout_began);
	WAIT(5);
	stage_finish(GAMEOVER_SCORESCREEN);
}

