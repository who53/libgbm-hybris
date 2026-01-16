#ifndef __UAPI_EVDI_DRM_H__
#define __UAPI_EVDI_DRM_H__

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#endif

#define DRM_EVDI_CONNECT 0x00
#define DRM_EVDI_POLL 0x04
#define DRM_EVDI_GBM_GET_BUFF 0x06
#define DRM_EVDI_GET_BUFF_CALLBACK 0x08
#define DRM_EVDI_DESTROY_BUFF_CALLBACK 0x09
#define DRM_EVDI_SWAP_CALLBACK 0x0A
#define DRM_EVDI_GBM_DEL_BUFF 0x0B
#define DRM_EVDI_GBM_CREATE_BUFF 0x0C
#define DRM_EVDI_GBM_CREATE_BUFF_CALLBACK 0x0D

struct drm_evdi_connect {
	int32_t connected;
	int32_t dev_index;
	uint32_t width;
	uint32_t height;
	uint32_t refresh_rate;
	uint32_t display_id;
};

enum poll_event_type {
	none,
	get_buf,
	destroy_buf,
	swap_to,
	create_buf,
	crtc_state
};

struct drm_evdi_poll {
	enum poll_event_type event;
	int poll_id;
	void *data;
};

struct drm_evdi_gbm_get_buff {
	int id;
	void *native_handle;
};

struct drm_evdi_get_buff_callabck {
	int poll_id;
	int version;
	int numFds;
	int numInts;
	int *fd_ints;
	int *data_ints;
};

struct drm_evdi_destroy_buff_callback {
	int poll_id;
};

struct drm_evdi_swap_callback {
	int poll_id;
};

struct drm_evdi_gbm_create_buff {
	int *id;
	uint32_t *stride;
	uint32_t format;
	uint32_t width;
	uint32_t height;
};

struct drm_evdi_create_buff_callabck {
	int poll_id;
	int id;
	uint32_t stride;
};

struct drm_evdi_gbm_del_buff {
	int id;
};

struct drm_evdi_crtc_state {
	int display_id;
	int mode;
};

#define DRM_IOCTL_EVDI_CONNECT \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_CONNECT, struct drm_evdi_connect)
#define DRM_IOCTL_EVDI_POLL \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_POLL, struct drm_evdi_poll)
#define DRM_IOCTL_EVDI_GBM_GET_BUFF                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_GBM_GET_BUFF, \
		 struct drm_evdi_gbm_get_buff)
#define DRM_IOCTL_EVDI_GET_BUFF_CALLBACK                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_GET_BUFF_CALLBACK, \
		 struct drm_evdi_get_buff_callabck)
#define DRM_IOCTL_EVDI_DESTROY_BUFF_CALLBACK                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_DESTROY_BUFF_CALLBACK, \
		 struct drm_evdi_destroy_buff_callback)
#define DRM_IOCTL_EVDI_SWAP_CALLBACK                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_SWAP_CALLBACK, \
		 struct drm_evdi_swap_callback)
#define DRM_IOCTL_EVDI_GBM_CREATE_BUFF                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_GBM_CREATE_BUFF, \
		 struct drm_evdi_gbm_create_buff)
#define DRM_IOCTL_EVDI_GBM_CREATE_BUFF_CALLBACK                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_GBM_CREATE_BUFF_CALLBACK, \
		 struct drm_evdi_create_buff_callabck)
#define DRM_IOCTL_EVDI_GBM_DEL_BUFF                        \
	DRM_IOWR(DRM_COMMAND_BASE + DRM_EVDI_GBM_DEL_BUFF, \
		 struct drm_evdi_gbm_del_buff)

#endif /* __UAPI_EVDI_DRM_H__ */
