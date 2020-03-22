/*
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@taisei-project.org>.
 */

#include "taisei.h"

#include "manualtutorial.h"
#include "common.h"
#include "options.h"
#include "stage.h"
#include "stageselect.h"
#include "global.h"
#include "video.h"

static void draw_manualtutorial_menu(MenuData *m) {
	draw_options_menu_bg(m);
	draw_menu_title(m, "Manual / Tutorial");
	draw_menu_list(m, 100, 100, NULL, SCREEN_H);
}

MenuData* create_manualtutorial_menu(void) {
	MenuData *m = alloc_menu();

	m->draw = draw_manualtutorial_menu;
	m->logic = animate_menu_list;
m->flags = MF_Abortable;
	m->transition = TransFadeBlack;

	add_menu_entry(m, "Main Story", menu_action_close, NULL);
	add_menu_entry(m, "Extra Story", menu_action_close, NULL);
	add_menu_entry(m, "Tutorial", start_game, &(stages[146]));

	add_menu_separator(m);
	add_menu_entry(m, "Back", menu_action_close, NULL);

	while(!m->entries[m->cursor].action) {
		++m->cursor;
	}

	return m;
}
