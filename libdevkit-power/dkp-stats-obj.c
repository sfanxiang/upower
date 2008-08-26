/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2008 Richard Hughes <richard@hughsie.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <string.h>
#include <stdlib.h>

#include "dkp-debug.h"
#include "dkp-stats-obj.h"

/**
 * dkp_stats_obj_copy:
 **/
DkpStatsObj *
dkp_stats_obj_copy (const DkpStatsObj *cobj)
{
	DkpStatsObj *obj;
	obj = g_new0 (DkpStatsObj, 1);
	obj->value = cobj->value;
	obj->accuracy = cobj->accuracy;
	return obj;
}

/**
 * dkp_stats_obj_new:
 **/
DkpStatsObj *
dkp_stats_obj_new (void)
{
	DkpStatsObj *obj;
	obj = g_new0 (DkpStatsObj, 1);
	obj->value = 0.0f;
	obj->accuracy = 0;
	return obj;
}

/**
 * dkp_stats_obj_free:
 **/
gboolean
dkp_stats_obj_free (DkpStatsObj *obj)
{
	if (obj == NULL)
		return FALSE;
	g_free (obj);
	return TRUE;
}

/**
 * dkp_stats_obj_create:
 **/
DkpStatsObj *
dkp_stats_obj_create (gdouble value, gdouble state)
{
	DkpStatsObj *obj;
	obj = dkp_stats_obj_new ();
	obj->value = value;
	obj->accuracy = state;
	return obj;
}
