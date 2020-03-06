/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#ifndef IGUARD_stages_stage3_events_h
#define IGUARD_stages_stage3_events_h

#include "taisei.h"

#include "boss.h"

void scuttle_spellbg(Boss*, int t);
void wriggle_spellbg(Boss*, int t);

void wriggle_moonlight_rocket(Boss*, int t);
void wriggle_night_ignite(Boss*, int t);
void wriggle_firefly_storm(Boss*, int t);
void wriggle_light_singularity(Boss*, int t);

Boss* stage3_spawn_scuttle(cmplx pos);
Boss* stage3_spawn_wriggle_ex(cmplx pos);

DECLARE_EXTERN_TASK(stage3_main, NO_ARGS);

DECLARE_EXTERN_TASK_WITH_INTERFACE(stage1_spell_deadly_dance, BossAttack);


#define STAGE3_MIDBOSS_TIME 1765

#endif // IGUARD_stages_stage3_events_h
