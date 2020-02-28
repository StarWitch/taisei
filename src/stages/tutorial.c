/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#include "taisei.h"

#include "tutorial.h"
#include "tutorial_events.h"

#include "global.h"
#include "stage.h"
#include "stageutils.h"
#include "stagedraw.h"
#include "resource/model.h"
#include "util/glm.h"
#include "common_tasks.h"

static void tut_start(void) {
	tut_events();
}

static void tut_end(void) {

}

StageProcs tutorial_procs = {
	.begin = tut_start,
//	.preload = tut_preload,
	.end = tut_end,
	//.draw = tut_draw,
	//.update = tut_update,
	//.shader_rules = tut_shaders,
};
