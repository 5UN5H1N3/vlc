/*****************************************************************************
 * libvlc_events.h:  libvlc_events external API structure
 *****************************************************************************
 * Copyright (C) 1998-2007 the VideoLAN team
 * $Id $
 *
 * Authors: Filippo Carone <littlejohn@videolan.org>
 *          Pierre d'Herbemont <pdherbemont@videolan.org>
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef _LIBVLC_EVENTS_H
#define _LIBVLC_EVENTS_H 1

# ifdef __cplusplus
extern "C" {
# endif

/*****************************************************************************
 * Events handling
 *****************************************************************************/

/** \defgroup libvlc_events Events
 * \ingroup libvlc
 * LibVLC Available Events
 * @{
 */

typedef enum libvlc_event_type_t {
    libvlc_MediaDescriptorMetaChanged,
    libvlc_MediaDescriptorSubItemAdded,
    libvlc_MediaDescriptorDurationChanged,
    libvlc_MediaDescriptorPreparsedChanged,
    libvlc_MediaDescriptorFreed,
    libvlc_MediaDescriptorStateChanged,

    libvlc_MediaInstancePlayed,
    libvlc_MediaInstancePaused,
    libvlc_MediaInstanceReachedEnd,
    libvlc_MediaInstanceEncounteredError,
    libvlc_MediaInstanceTimeChanged,
    libvlc_MediaInstancePositionChanged,
    libvlc_MediaInstanceSeekableChanged,
    libvlc_MediaInstancePausableChanged,

    libvlc_MediaListItemAdded,
    libvlc_MediaListWillAddItem,
    libvlc_MediaListItemDeleted,
    libvlc_MediaListWillDeleteItem,

    libvlc_MediaListViewItemAdded,
    libvlc_MediaListViewWillAddItem,
    libvlc_MediaListViewItemDeleted,
    libvlc_MediaListViewWillDeleteItem,

    libvlc_MediaListPlayerPlayed,
    libvlc_MediaListPlayerNextItemSet,
    libvlc_MediaListPlayerStopped,

    libvlc_MediaDiscovererStarted,
    libvlc_MediaDiscovererEnded

} libvlc_event_type_t;

/**
 * An Event
 * \param type the even type
 * \param p_obj the sender object
 * \param u Event dependent content
 */

typedef struct libvlc_event_t
{
    libvlc_event_type_t type;
    void * p_obj;
    union event_type_specific
    {
        /* media descriptor */
        struct
        {
            libvlc_meta_t meta_type;
        } media_descriptor_meta_changed;
        struct
        {
            libvlc_media_descriptor_t * new_child;
        } media_descriptor_subitem_added;
        struct
        {
            vlc_int64_t new_duration;
        } media_descriptor_duration_changed;
        struct
        {
            int new_status;
        } media_descriptor_preparsed_changed;
        struct
        {
            libvlc_media_descriptor_t * md;
        } media_descriptor_freed;
        struct
        {
            libvlc_state_t new_state;
        } media_descriptor_state_changed;

        /* media instance */
        struct
        {
            float new_position;
        } media_instance_position_changed;
        struct
        {
            libvlc_time_t new_time;
        } media_instance_time_changed;
        struct
        {
            libvlc_time_t new_seekable;
        } media_instance_seekable_changed;
        struct
        {
            libvlc_time_t new_pausable;
        } media_instance_pausable_changed;

        /* media list */
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_item_added;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_will_add_item;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_item_deleted;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_will_delete_item;

        /* media list view */
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_view_item_added;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_view_will_add_item;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_view_item_deleted;
        struct
        {
            libvlc_media_descriptor_t * item;
            int index;
        } media_list_view_will_delete_item;

        /* media discoverer */
        struct
        {
            void * unused;
        } media_media_discoverer_started;
        struct
        {
            void * unused;
        } media_media_discoverer_ended;

    } u;
} libvlc_event_t;

/**
 * Event manager that belongs to a libvlc object, and from whom events can
 * be received.
 */

typedef struct libvlc_event_manager_t libvlc_event_manager_t;

/**
 * Callback function notification
 * \param p_event the event triggering the callback
 */

typedef void ( *libvlc_callback_t )( const libvlc_event_t *, void * );

/**@} */

# ifdef __cplusplus
}
# endif

#endif /* _LIBVLC_EVENTS_H */
