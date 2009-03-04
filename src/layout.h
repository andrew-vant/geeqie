/*
 * Geeqie
 * (C) 2004 John Ellis
 * Copyright (C) 2008 - 2009 The Geeqie Team
 *
 * Author: John Ellis
 *
 * This software is released under the GNU General Public License (GNU GPL).
 * Please read the included file COPYING for more information.
 * This software comes with no warranty of any kind, use at your own risk!
 */

#ifndef LAYOUT_H
#define LAYOUT_H


extern GList *layout_window_list;


LayoutWindow *layout_new(FileData *dir_fd, LayoutOptions *lop);
LayoutWindow *layout_new_with_geometry(FileData *dir_fd, LayoutOptions *lop,
				       const gchar *geometry);
LayoutWindow *layout_new_from_config(const gchar **attribute_names, const gchar **attribute_values, gboolean use_commandline);

void layout_close(LayoutWindow *lw);
void layout_free(LayoutWindow *lw);

gint layout_valid(LayoutWindow **lw);

void layout_sync_options_with_current_state(LayoutWindow *lw);
void layout_load_attributes(LayoutOptions *layout, const gchar **attribute_names, const gchar **attribute_values);
void layout_write_attributes(LayoutOptions *layout, GString *outstr, gint indent);
void layout_write_config(LayoutWindow *lw, GString *outstr, gint indent);


LayoutWindow *layout_find_by_image(ImageWindow *imd);
LayoutWindow *layout_find_by_image_fd(ImageWindow *imd);

const gchar *layout_get_path(LayoutWindow *lw);
gint layout_set_path(LayoutWindow *lw, const gchar *path);
gint layout_set_fd(LayoutWindow *lw, FileData *fd);

void layout_status_update_progress(LayoutWindow *lw, gdouble val, const gchar *text);
void layout_status_update_info(LayoutWindow *lw, const gchar *text);
void layout_status_update_image(LayoutWindow *lw);
void layout_status_update_write(LayoutWindow *lw);
void layout_status_update_all(LayoutWindow *lw);

void layout_status_update_write_all(void);

GList *layout_list(LayoutWindow *lw);
guint layout_list_count(LayoutWindow *lw, gint64 *bytes);
FileData *layout_list_get_fd(LayoutWindow *lw, gint index);
gint layout_list_get_index(LayoutWindow *lw, FileData *fd);
void layout_list_sync_fd(LayoutWindow *lw, FileData *fd);

GList *layout_selection_list(LayoutWindow *lw);
/* return list of pointers to int for selection */
GList *layout_selection_list_by_index(LayoutWindow *lw);
guint layout_selection_count(LayoutWindow *lw, gint64 *bytes);
void layout_select_all(LayoutWindow *lw);
void layout_select_none(LayoutWindow *lw);
void layout_select_invert(LayoutWindow *lw);

void layout_mark_to_selection(LayoutWindow *lw, gint mark, MarkToSelectionMode mode);
void layout_selection_to_mark(LayoutWindow *lw, gint mark, SelectionToMarkMode mode);

void layout_refresh(LayoutWindow *lw);

void layout_thumb_set(LayoutWindow *lw, gint enable);
gint layout_thumb_get(LayoutWindow *lw);

void layout_marks_set(LayoutWindow *lw, gint enable);
gint layout_marks_get(LayoutWindow *lw);

void layout_sort_set(LayoutWindow *lw, SortType type, gint ascend);
gint layout_sort_get(LayoutWindow *lw, SortType *type, gint *ascend);

gint layout_geometry_get(LayoutWindow *lw, gint *x, gint *y, gint *w, gint *h);
gint layout_geometry_get_dividers(LayoutWindow *lw, gint *h, gint *v);

void layout_views_set(LayoutWindow *lw, DirViewType dir_view_type, FileViewType file_view_type);
gint layout_views_get(LayoutWindow *lw, DirViewType *dir_view_type, FileViewType *file_view_type);

void layout_status_update(LayoutWindow *lw, const gchar *text);

void layout_style_set(LayoutWindow *lw, gint style, const gchar *order);

void layout_menu_update_edit(void);
void layout_styles_update(void);
void layout_colors_update(void);


gint layout_geometry_get_tools(LayoutWindow *lw, gint *x, gint *y, gint *w, gint *h, gint *divider_pos);
void layout_tools_float_set(LayoutWindow *lw, gint popped, gint hidden);
gint layout_tools_float_get(LayoutWindow *lw, gint *popped, gint *hidden);

void layout_tools_float_toggle(LayoutWindow *lw);
void layout_tools_hide_toggle(LayoutWindow *lw);


void layout_toolbar_toggle(LayoutWindow *lw);
gint layout_toolbar_hidden(LayoutWindow *lw);
void layout_info_pixel_toggle(LayoutWindow *lw);
gint layout_info_pixel_hidden(LayoutWindow *lw);

void layout_split_change(LayoutWindow *lw, ImageSplitMode mode);

#endif
/* vim: set shiftwidth=8 softtabstop=0 cindent cinoptions={1s: */
