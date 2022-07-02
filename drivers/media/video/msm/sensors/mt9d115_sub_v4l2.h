/* Copyright (c) 2009, Code Aurora Forum. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/***********************************************************************/
/* Modified by                                                         */
/* (C) NEC CASIO Mobile Communications, Ltd. 2013                      */
/***********************************************************************/

#ifndef MT9D115_SUB_V4L2_H
#define MT9D115_SUB_V4L2_H

#include <linux/mfd/pm8xxx/pm8921.h>
#include <linux/clk.h>
#include <mach/irqs.h>

#include "msm.h"
#include "msm_sensor.h"
#include "msm_ispif.h"

#define SENSOR_NAME "mt9d115_sub"
#define PLATFORM_DRIVER_NAME "msm_camera_mt9d115_sub"
#define mt9d115_sub_obj mt9d115_sub_##obj

DEFINE_MUTEX(mt9d115_sub_mut);
static struct msm_sensor_ctrl_t mt9d115_sub_s_ctrl;

static int16_t mt9d115_sub_effect;
static enum mt9d115_Flicker mt9d115_sub_flicker_mode;
static enum mt9d115_brightness mt9d115_sub_bright_mode;
static enum mt9d115_White_Balance mt9d115_sub_wb_mode;
static enum mt9d115_Frame_Rate_setting mt9d115_sub_frame_rate_mode;
static enum mt9d115_Mode_setting mt9d115_sub_cap_mode_enable;
static enum mt9d115_Capture_Mode_setting mt9d115_sub_capture_mode;

static int32_t mt9d115_sub_sensor_reg_polling(void);
static void mt9d115_sub_sensor_start_stream(struct msm_sensor_ctrl_t *s_ctrl);
static void mt9d115_sub_sensor_stop_stream(struct msm_sensor_ctrl_t *s_ctrl);
static int32_t mt9d115_sub_sensor_write_output_settings(struct msm_sensor_ctrl_t *s_ctrl, uint16_t res);
static int32_t mt9d115_sub_sensor_write_res_settings(struct msm_sensor_ctrl_t *s_ctrl, uint16_t res);




static long mt9d115_sub_sensor_init_setting(struct msm_sensor_ctrl_t *s_ctrl);
static long mt9d115_sub_reg_setting(struct msm_sensor_ctrl_t *s_ctrl);
static int32_t mt9d115_sub_sensor_setting(struct msm_sensor_ctrl_t *s_ctrl, int update_type, int res);
static int32_t mt9d115_sub_set_pict_size( struct msm_sensor_ctrl_t *s_ctrl, int pict_size );
static int32_t mt9d115_sub_set_antibanding(struct msm_sensor_ctrl_t *s_ctrl, int antibanding);
static int32_t mt9d115_sub_set_wb(struct msm_sensor_ctrl_t *s_ctrl, int wb_val);
static int32_t mt9d115_sub_set_effect(struct msm_sensor_ctrl_t *s_ctrl, int effect);
static int32_t mt9d115_sub_set_exp_compensation(struct msm_sensor_ctrl_t *s_ctrl, int brightness);
static int32_t mt9d115_sub_set_scene(struct msm_sensor_ctrl_t *s_ctrl, int scene);


static int32_t mt9d115_sub_get_maker_note(struct msm_sensor_ctrl_t *s_ctrl, struct get_exif_maker_note_cfg *get_exif_maker_note);
static int32_t mt9d115_sub_get_exif_param(struct msm_sensor_ctrl_t *s_ctrl, struct get_exif_param_inf* get_exif_param);
static int32_t mt9d115_sub_set_frame_rate_mode(struct msm_sensor_ctrl_t *s_ctrl, int frame_rate_mode);
static int32_t mt9d115_sub_get_hdr_brightness(struct msm_sensor_ctrl_t *s_ctrl, struct hdr_brightness_t *hdr_brightness);
static int32_t mt9d115_sub_set_hdr_brightness(struct msm_sensor_ctrl_t *s_ctrl, struct hdr_brightness_t hdr_brightness);
static int32_t mt9d115_sub_set_cap_mode_enable(struct msm_sensor_ctrl_t *s_ctrl, int cap_mode_enable);
#if 1 
static int32_t mt9d115_sub_get_device_id(struct msm_sensor_ctrl_t *s_ctrl, uint16_t *device_id);
#endif 
static int32_t mt9d115_sub_sensor_power_up(struct msm_sensor_ctrl_t *s_ctrl);
static int mt9d115_sub_sensor_power_down(struct msm_sensor_ctrl_t *s_ctrl);
static int mt9d115_sub_i2c_probe(struct i2c_client *client, const struct i2c_device_id *id);
static int __init msm_sensor_init_module(void);




#define MT9D115_SUB_LOG_ERR_ON  1   
#define MT9D115_SUB_LOG_DBG_ON  0   

#if MT9D115_SUB_LOG_ERR_ON
#define MT9D115_SUB_LOG_ERR(fmt, args...) printk(KERN_ERR "mt9d115_sub:%s(%d) " fmt, __func__, __LINE__, ##args)
#else
#define MT9D115_SUB_LOG_ERR(fmt, args...) do{}while(0)
#endif

#if MT9D115_SUB_LOG_DBG_ON
#define MT9D115_SUB_LOG_DBG(fmt, args...) printk(KERN_INFO "mt9d115_sub:%s(%d) " fmt, __func__, __LINE__, ##args)
#else
#define MT9D115_SUB_LOG_DBG(fmt, args...) do{}while(0)
#endif

#define MT9D115_SUB_LOG_INF(fmt, args...) printk(KERN_INFO "mt9d115_sub:%s(%d) " fmt, __func__, __LINE__, ##args)



#define REG_MT9D115_SYSCTL			0x001A
#define REG_MT9D115_SYSCTL2			0x0018
#define REG_MT9D115_PGA_ENABLE		0x3210
#define MT9D115_PGA_ENABLE_MASK		0x0008

#define REG_MT9D115_COAINT_TIME		0x3012
#define REG_MT9D115_LINE_LENGTH_PCK	0x300C
#define REG_MT9D115_FI_INT_TIME		0x3014
#define REG_MT9D115_A_GAIN_CODE_GLOBAL	0x3028
#define REG_MT9D115_D_GAIN_GREENR	0x3032

#define REG_MT9D115_A_GAIN_CODE_GREENR	0x302A
#define REG_MT9D115_A_GAIN_CODE_GREENB	0x3030
#define REG_MT9D115_A_GAIN_CODE_RED		0x302C
#define REG_MT9D115_A_GAIN_CODE_BLUE	0x302E
#define REG_MT9D115_PARM_HOLD_MASK_FRM	0x3022

#define REG_MT9D115_MCUADD			0x098C
#define REG_MT9D115_MCUDAT			0x0990

#define REG_MT9D115_FD_FREQ			0xA404
#define REG_MT9D115_DEV_ID			0x0000
#define REG_MT9D115_AWB_TEMP		0xA353
#define REG_MT9D115_AWB_GAIN_R		0xA34E
#define REG_MT9D115_AWB_GAIN_G		0xA34F
#define REG_MT9D115_AWB_GAIN_B		0xA350
#define REG_MT9D115_SATURATION	    0xA354

#define MT9D115_SYSCTL_DP_MASK		0xFDFF
#define MT9D115_SYSCTL_MP_MASK		0x0008
#define MT9D115_SYSCTL_SM_MASK		0x0004
#define MT9D115_SYSCTL_SMINI_MASK	0x0001
#define MT9D115_MONPAT_ID_MASK		0x0000
#define MT9D115_SEQ_STATE_MASK		0x0003
#define MT9D115_SEQ_STATE_MASK2		0x0000

#define MT9D115_MONPAT_ADDRESS		0xA024
#define MT9D115_SEQRFM_ADDRESS		0xA103
#define MT9D115_SEQSAT_ADDRESS		0xA104

#define MT9D115_REFMOD_DAT			0x0006
#define MT9D115_REFSEQ_DAT			0x0005



#define MT9D115_GPIO_CAM2_MCLK		  4		 
#define MT9D115_GPIO_CAM2_V_EN2		  6		 
#define MT9D115_GPIO_CAM2_RST_N		 43		
#define MT9D115_GPIO_CAMIF_I2C_DATA	 20		
#define MT9D115_GPIO_CAMIF_I2C_CLK	 21		


#define PM8921_GPIO_BASE        NR_GPIO_IRQS
#define PM8921_GPIO_PM_TO_SYS(pm_gpio)  (pm_gpio - 1 + PM8921_GPIO_BASE)
#define MT9D115_PMGPIO_CAM2_V_EN1  PM8921_GPIO_PM_TO_SYS(42)   



enum mt9d115_reg_init {
	MT9D115_REG_INIT_00,	
	MT9D115_REG_INIT_01,	
	MT9D115_REG_INIT_02,	
	MT9D115_REG_INIT_03,	
	MT9D115_REG_INIT_04,	
	MT9D115_REG_INIT_05,	
	MT9D115_REG_INIT_06,	
	MT9D115_REG_INIT_07,	
	MT9D115_REG_INIT_MAX
};

enum mt9d115_White_Balance {
	MT9D115_WB_00,			
	MT9D115_WB_01,			
	MT9D115_WB_02,			
	MT9D115_WB_03,			
	MT9D115_WB_04,			
	MT9D115_WB_05,			
	MT9D115_WB_MAX
};

enum mt9d115_brightness {
	MT9D115_BN_00,			
	MT9D115_BN_01,			
	MT9D115_BN_02,			
	MT9D115_BN_03,			
	MT9D115_BN_04,			
	MT9D115_BN_05,			
	MT9D115_BN_06,			
	MT9D115_BN_07,			
	MT9D115_BN_08,			
	MT9D115_BN_09,			
	MT9D115_BN_10,			
	MT9D115_BN_11,			
	MT9D115_BN_12,			
	MT9D115_BN_MAX
};

enum mt9d115_Special_Effects {
	MT9D115_SE_00,			
	MT9D115_SE_01,			
	MT9D115_SE_02,			
	MT9D115_SE_03,			
	MT9D115_SE_MAX
};

enum mt9d115_AE_measurement_method {
	MT9D115_AE_00,			
	MT9D115_AE_01,			
	MT9D115_AE_MAX
};

enum mt9d115_Flicker {
	MT9D115_FL_00,			
	MT9D115_FL_01,			
	MT9D115_FL_02,			
	MT9D115_FL_MAX
};
#if 0
enum mt9d115_Position {
	MT9D115_PO_00,			
	MT9D115_PO_01,			
	MT9D115_PO_02,			
	MT9D115_PO_03,			
	MT9D115_PO_MAX
};
#endif
enum mt9d115_Noise_Reduction {
	MT9D115_NR_00,			
	MT9D115_NR_01,			
	MT9D115_NR_02,			
	MT9D115_NR_03,			
	MT9D115_NR_04,			
	MT9D115_NR_MAX
};

enum mt9d115_Sharpness_setting {
	MT9D115_SH_00,			
	MT9D115_SH_01,			
	MT9D115_SH_02,			
	MT9D115_SH_03,			
	MT9D115_SH_04,			
	MT9D115_SH_MAX
};

enum mt9d115_SIZE_setting {
	MT9D115_SIZE_00,		
	MT9D115_SIZE_01,		
	MT9D115_SIZE_02,		
	MT9D115_SIZE_03,		
	MT9D115_SIZE_04,		
	MT9D115_SIZE_05,		
	MT9D115_SIZE_06,		
	MT9D115_SIZE_07,		
	MT9D115_SIZE_08,		
	MT9D115_SIZE_09,		
	MT9D115_SIZE_10,		
	MT9D115_SIZE_11,		
	MT9D115_SIZE_MAX
};

enum mt9d115_ZOOM_setting {
	MT9D115_ZOOM_00,
	MT9D115_ZOOM_01,
	MT9D115_ZOOM_02,
	MT9D115_ZOOM_03,
	MT9D115_ZOOM_04,
	MT9D115_ZOOM_05,
	MT9D115_ZOOM_06,
	MT9D115_ZOOM_07,
	MT9D115_ZOOM_08,
	MT9D115_ZOOM_09,
	MT9D115_ZOOM_10,
	MT9D115_ZOOM_11,
	MT9D115_ZOOM_12,
	MT9D115_ZOOM_13,
	MT9D115_ZOOM_14,
	MT9D115_ZOOM_15,
	MT9D115_ZOOM_MAX
};

enum mt9d115_Mode_setting {
	MT9D115_MODE_PRE,		
	MT9D115_MODE_CAP,		
	MT9D115_MODE_MAX
};

enum mt9d115_Scene_setting {
	MT9D115_SN_00,	
	MT9D115_SN_01,	
	MT9D115_SN_02,	
	MT9D115_SN_03,	
	MT9D115_SN_MAX
};

#if 0
enum mt9d115_Anti_shaking_setting {
	MT9D115_AS_00,	
	MT9D115_AS_01,	
	MT9D115_AS_MAX
};
#endif

enum mt9d115_Frame_Rate_setting {
	MT9D115_FR_00,	
	MT9D115_FR_01,	
	MT9D115_FR_02,	
	MT9D115_FR_03,	
	MT9D115_FR_MAX
};

enum mt9d115_Capture_Mode_setting {
	MT9D115_CM_00,	
	MT9D115_CM_01,	
	MT9D115_CM_MAX
};


enum mt9d115_access_t{
    MT9D115_ACCESS_REGISTERS,
    MT9D115_ACCESS_VARIABLES,
};

struct reg_access_param_t{
    enum mt9d115_access_t reg_type;
    uint16_t  reg_addr;
    uint16_t* reg_data;
};

#if 0
struct mt9d115_zoom_value {
	int32_t step;
	int32_t size;
	int32_t mode;
};
#endif




struct pm_gpio mt9d115_cam2_v_en1_on = {
    .direction      = PM_GPIO_DIR_OUT,
    .output_buffer  = PM_GPIO_OUT_BUF_CMOS,
    .output_value   = 1,
    .pull           = PM_GPIO_PULL_NO,
    .vin_sel        = PM_GPIO_VIN_S4,
    .out_strength   = PM_GPIO_STRENGTH_LOW,
    .function       = PM_GPIO_FUNC_NORMAL,
    .inv_int_pol    = 0,
    .disable_pin    = 0,
};


struct pm_gpio mt9d115_cam2_v_en1_off = {
    .direction      = PM_GPIO_DIR_OUT,
    .output_buffer  = PM_GPIO_OUT_BUF_CMOS,
    .output_value   = 0,
    .pull           = PM_GPIO_PULL_NO,
    .vin_sel        = PM_GPIO_VIN_S4,
    .out_strength   = PM_GPIO_STRENGTH_LOW,
    .function       = PM_GPIO_FUNC_NORMAL,
    .inv_int_pol    = 0,
    .disable_pin    = 0,
};

static struct v4l2_subdev_info mt9d115_sub_subdev_info[] = {
    {
    .code   = V4L2_MBUS_FMT_YUYV8_2X8,
    .colorspace = V4L2_COLORSPACE_JPEG,
    .fmt    = 1,
    .order    = 0,
    },
    
};

static struct msm_sensor_output_info_t mt9d115_sub_dimensions[] = {

    {
        .x_output = 0x640,
        .y_output = 0x4B0,


        .line_length_pclk = 0x08B0,	
        .frame_length_lines = 0x50D,

        .vt_pixel_clk = 69120000,
        .op_pixel_clk = 128000000,
        .binning_factor = 1,
    },

    {
        .x_output = 0x640,
        .y_output = 0x4B0,


        .line_length_pclk = 0x08B0,	
        .frame_length_lines = 0x50D,

        .vt_pixel_clk = 69120000,
        .op_pixel_clk = 128000000,
        .binning_factor = 1,
    },
};

static struct msm_camera_csid_vc_cfg mt9d115_sub_cid_cfg[] = {
    {0, CSI_YUV422_8, CSI_DECODE_8BIT},
    {1, CSI_EMBED_DATA, CSI_DECODE_8BIT},
};

static struct msm_camera_csi2_params mt9d115_sub_csi_params = {
    .csid_params = {
        .lane_assign = 0xe4,
        .lane_cnt = 1,
        .lut_params = {
            .num_cid = 2,
            .vc_cfg = mt9d115_sub_cid_cfg,
        },
    },
    .csiphy_params = {
        .lane_cnt = 1,
        .settle_cnt = 7,
    },
};

static struct msm_camera_csi2_params *mt9d115_sub_csi_params_array[] = {
    &mt9d115_sub_csi_params,
    &mt9d115_sub_csi_params,
};

static struct msm_sensor_output_reg_addr_t mt9d115_sub_reg_addr = {
    .x_output = 0x2703,            
    .y_output = 0x2705,            
    .line_length_pclk = 0x2721,    
    .frame_length_lines = 0x271F,  
};

static struct msm_sensor_id_info_t mt9d115_sub_id_info = {
    .sensor_id_reg_addr = 0x0000,    
    .sensor_id = 0x2580,             
};

static struct msm_camera_i2c_client mt9d115_sub_sensor_i2c_client = {
	.addr_type = MSM_CAMERA_I2C_WORD_ADDR,
};

static const struct i2c_device_id mt9d115_sub_i2c_id[] = {
    {SENSOR_NAME, (kernel_ulong_t)&mt9d115_sub_s_ctrl},
	{ }
};

static struct i2c_driver mt9d115_sub_i2c_driver = {
	.id_table = mt9d115_sub_i2c_id,
	.probe  = mt9d115_sub_i2c_probe,
	.driver = {
		.name = SENSOR_NAME,
	},
};

static struct v4l2_subdev_core_ops mt9d115_sub_subdev_core_ops = {
    .s_ctrl = msm_sensor_v4l2_s_ctrl,
    .queryctrl = msm_sensor_v4l2_query_ctrl,
    .ioctl = msm_sensor_subdev_ioctl,
    .s_power = msm_sensor_power,
};

static struct v4l2_subdev_video_ops mt9d115_sub_subdev_video_ops = {
    .enum_mbus_fmt = msm_sensor_v4l2_enum_fmt,
};

static struct v4l2_subdev_ops mt9d115_sub_subdev_ops = {
    .core = &mt9d115_sub_subdev_core_ops,
    .video  = &mt9d115_sub_subdev_video_ops,
};
























static struct msm_camera_i2c_reg_conf
Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_1_array[] = {
						
	{0x0014, 0x2545},	
						
	{0x0010, 0x0769},	
	{0x0012, 0x00F7},	
	{0x0014, 0x2545},	
	{0x0014, 0x2547},	
	{0x0014, 0x2447}	
						
};

static struct msm_camera_i2c_reg_conf
Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_2_array[] = {
		
	{0x0014, 0x2047},	
	{0x0014, 0x2046},	
	{0x0018, 0x402D},	
	{0x0018, 0x402C}	
						
};





static struct msm_camera_i2c_reg_conf
Register_Wizard_Defaults_Sensor_Core_Timing_4_MIPI_setting_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0640},	
	{0x098C, 0x2705},	
	{0x0990, 0x04B0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0640},	
	{0x098C, 0x2709},	
	{0x0990, 0x04B0},	
	{0x098C, 0x270D},	
	{0x0990, 0x0004},	
	{0x098C, 0x270F},	
	{0x0990, 0x0004},	
	{0x098C, 0x2711},	
	{0x0990, 0x04BB},	
	{0x098C, 0x2713},	
	{0x0990, 0x064B},	
	{0x098C, 0x2715},	
	{0x0990, 0x0111},	
	{0x098C, 0x2717},	
	{0x0990, 0x0027},	
	{0x098C, 0x2719},	
	{0x0990, 0x003A},	
	{0x098C, 0x271B},	
	{0x0990, 0x00F6},	
	{0x098C, 0x271D},	
	{0x0990, 0x008B},	
	{0x098C, 0x271F},	
	{0x0990, 0x050D},	
	{0x098C, 0x2721},	
	{0x0990, 0x08B0},	
	{0x098C, 0x2723},	
	{0x0990, 0x0004},	
	{0x098C, 0x2725},	
	{0x0990, 0x0004},	
	{0x098C, 0x2727},	
	{0x0990, 0x04BB},	
	{0x098C, 0x2729},	
	{0x0990, 0x064B},	
	{0x098C, 0x272B},	
	{0x0990, 0x0111},	
	{0x098C, 0x272D},	
	{0x0990, 0x0027},	
	{0x098C, 0x272F},	
	{0x0990, 0x003A},	
	{0x098C, 0x2731},	
	{0x0990, 0x00F6},	
	{0x098C, 0x2733},	
	{0x0990, 0x008B},	
	{0x098C, 0x2735},	
	{0x0990, 0x050D},	
	{0x098C, 0x2737},	
	{0x0990, 0x08B0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0x222D},	
	{0x0990, 0x009D},	
	{0x098C, 0xA408},	
	{0x0990, 0x0026},	
	{0x098C, 0xA409},	
	{0x0990, 0x0028},	
	{0x098C, 0xA40A},	
	{0x0990, 0x002E},	
	{0x098C, 0xA40B},	
	{0x0990, 0x0030},	
	{0x098C, 0x2411},	
	{0x0990, 0x009D},	
	{0x098C, 0x2413},	
	{0x0990, 0x00BD},	
	{0x098C, 0x2415},	
	{0x0990, 0x009D},	
	{0x098C, 0x2417},	
	{0x0990, 0x00BD},	
	{0x098C, 0xA404},	
	{0x0990, 0x0010},	
	{0x098C, 0xA40D},	
	{0x0990, 0x0002},	
	{0x098C, 0xA40E},	
	{0x0990, 0x0003},	
	{0x098C, 0xA410},	
	{0x0990, 0x000A},	

						
	{0x3180, 0x8050},	

						
	{0x098C, 0x2306},	
	{0x0990, 0x01D6},	
	{0x098C, 0x2308},	
	{0x0990, 0xFF89},	
	{0x098C, 0x230A},	
	{0x0990, 0xFFA1},	
	{0x098C, 0x230C},	
	{0x0990, 0xFF73},	
	{0x098C, 0x230E},	
	{0x0990, 0x019C},	
	{0x098C, 0x2310},	
	{0x0990, 0xFFF1},	
	{0x098C, 0x2312},	
	{0x0990, 0xFFB0},	
	{0x098C, 0x2314},	
	{0x0990, 0xFF2D},	
	{0x098C, 0x2316},	
	{0x0990, 0x0223},	
	{0x098C, 0x2318},	
	{0x0990, 0x0022},	
	{0x098C, 0x231A},	
	{0x0990, 0x0047},	
	{0x098C, 0x231C},	
	{0x0990, 0xFF6B},	
	{0x098C, 0x231E},	
	{0x0990, 0xFFF0},	
	{0x098C, 0x2320},	
	{0x0990, 0x0053},	
	{0x098C, 0x2322},	
	{0x0990, 0x0033},	
	{0x098C, 0x2324},	
	{0x0990, 0x0067},	
	{0x098C, 0x2326},	
	{0x0990, 0xFF7C},	
	{0x098C, 0x2328},	
	{0x0990, 0x001B},	
	{0x098C, 0x232A},	
	{0x0990, 0x0064},	
	{0x098C, 0x232C},	
	{0x0990, 0x00ED},	
	{0x098C, 0x232E},	
	{0x0990, 0x000C},	
	{0x098C, 0x2330},	
	{0x0990, 0xFFD8},	

	{0x098C, 0xA366},	
	{0x0990, 0x0077},	
	{0x098C, 0xA367},	
	{0x0990, 0x0080},	
	{0x098C, 0xA368},	
	{0x0990, 0x0085},	
	{0x098C, 0xA369},	
	{0x0990, 0x0078},	
	{0x098C, 0xA36A},	
	{0x0990, 0x0080},	
	{0x098C, 0xA36B},	
	{0x0990, 0x0080},	

	{0x098C, 0xA348},	
	{0x0990, 0x0009},	
	{0x098C, 0xA349},	
	{0x0990, 0x0002},	
	{0x098C, 0xA351},	
	{0x0990, 0x0000},	
	{0x098C, 0xA352},	
	{0x0990, 0x007F},	
	{0x098C, 0xA354},	
	{0x0990, 0x0043},	
	{0x098C, 0xA355},	
	{0x0990, 0x0001},	

						
						
	{0x098C, 0xA36D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA363},	
	{0x0990, 0x00CE},	
	{0x098C, 0xA364},	
	{0x0990, 0x00e7},	
		
	{0x098C, 0xA34A},	
	{0x0990, 0x0069},	
	{0x098C, 0xA34B},	
	{0x0990, 0x00B6},	
	{0x098C, 0xA34C},	
	{0x0990, 0x0076},	
	{0x098C, 0xA34D},	
	{0x0990, 0x00A0},	

						
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
		
	{0x098C, 0xAB4F},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB50},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB51},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB52},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB53},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB54},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB55},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB56},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB57},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB58},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB59},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB5A},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB5B},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB5C},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB5D},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB5E},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB5F},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB60},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB61},	
	{0x0990, 0x00FF},	

						
	{0x3240, 0xc817},	
	{0x323E, 0x1A2F},	
		
						
	{0x098C, 0xAB04},	
	{0x0990, 0x0012},	
	{0x098C, 0xAB04},	
	{0x0990, 0x0012},	
	{0x098C, 0xAB06},	
	{0x0990, 0x0004},	
	{0x098C, 0xAB06},	
	{0x0990, 0x0004},	

	{0x098C, 0xA216},	
	{0x0990, 0x001D},	
	{0x098C, 0xA20D},	
	{0x0990, 0x0015},	
	{0x098C, 0xA20E},	
	{0x0990, 0x0020},	

						
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000D},	

						
	{0x098C, 0xA24F},	
	{0x0990, 0x003E},	

						
	{0x098C, 0xAB22},	
	{0x0990, 0x0005},	
	{0x326c, 0x1504},	

						
	{0x098C, 0xA209},	
	{0x0990, 0x0001},	
	{0x098C, 0xA20A},	
	{0x0990, 0x0020},	
	{0x098C, 0x2212},	
	{0x0990, 0x012C},	
	{0x098C, 0x2247},	
	{0x0990, 0x001E},	

						
	{0x098C, 0xA117},	
	{0x0990, 0x0002},	
	{0x098C, 0xA11D},	
	{0x0990, 0x0002},	
	{0x098C, 0xA129},	
	{0x0990, 0x0002},	

						
	{0x098C, 0x2B62},	
	{0x0990, 0xFFFF},	
	{0x098C, 0x2B64},	
	{0x0990, 0xFFFF},	

						
	{0x098C, 0xA355},	
	{0x0990, 0x0001},	

						
	{0x098C, 0x2B28},	
	{0x0990, 0x1000},	
	{0x098C, 0x2B2A},	
	{0x0990, 0x3000},	
	{0x098C, 0xAB20},	
	{0x0990, 0x0070},	
	{0x098C, 0xAB22},	
	{0x0990, 0x0005},	
	{0x098C, 0xAB24},	
	{0x0990, 0x0020},	
	{0x098C, 0xAB26},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB21},	
	{0x0990, 0x001A},	
	{0x098C, 0xAB23},	
	{0x0990, 0x0004},	
	{0x098C, 0xAB25},	
	{0x0990, 0x003A},	
	{0x098C, 0xAB27},	
	{0x0990, 0x0040},	

						
	{0x098C, 0x0415},	
	{0x0990, 0xF601},	
	{0x0992, 0x42C1},	
	{0x0994, 0x0326},	
	{0x0996, 0x11F6},	
	{0x0998, 0x0143},	
	{0x099A, 0xC104},	
	{0x099C, 0x260A},	
	{0x099E, 0xCC04},	
	{0x098C, 0x0425},	
	{0x0990, 0x33BD},	
	{0x0992, 0xA362},	
	{0x0994, 0xBD04},	
	{0x0996, 0x3339},	
	{0x0998, 0xC6FF},	
	{0x099A, 0xF701},	
	{0x099C, 0x6439},	
	{0x099E, 0xDE5D},	
	{0x098C, 0x0435},	
	{0x0990, 0x18CE},	
	{0x0992, 0x0325},	
	{0x0994, 0xCC00},	
	{0x0996, 0x27BD},	
	{0x0998, 0xC2B8},	
	{0x099A, 0xCC04},	
	{0x099C, 0xBDFD},	
	{0x099E, 0x033B},	
	{0x098C, 0x0445},	
	{0x0990, 0xCC06},	
	{0x0992, 0x6BFD},	
	{0x0994, 0x032F},	
	{0x0996, 0xCC03},	
	{0x0998, 0x25DD},	
	{0x099A, 0x5DC6},	
	{0x099C, 0x1ED7},	
	{0x099E, 0x6CD7},	
	{0x098C, 0x0455},	
	{0x0990, 0x6D5F},	
	{0x0992, 0xD76E},	
	{0x0994, 0xD78D},	
	{0x0996, 0x8620},	
	{0x0998, 0x977A},	
	{0x099A, 0xD77B},	
	{0x099C, 0x979A},	
	{0x099E, 0xC621},	
	{0x098C, 0x0465},	
	{0x0990, 0xD79B},	
	{0x0992, 0xFE01},	
	{0x0994, 0x6918},	
	{0x0996, 0xCE03},	
	{0x0998, 0x4DCC},	
	{0x099A, 0x0013},	
	{0x099C, 0xBDC2},	
	{0x099E, 0xB8CC},	
	{0x098C, 0x0475},	
	{0x0990, 0x05E9},	
	{0x0992, 0xFD03},	
	{0x0994, 0x4FCC},	
	{0x0996, 0x034D},	
	{0x0998, 0xFD01},	
	{0x099A, 0x69FE},	
	{0x099C, 0x02BD},	
	{0x099E, 0x18CE},	
	{0x098C, 0x0485},	
	{0x0990, 0x0361},	
	{0x0992, 0xCC00},	
	{0x0994, 0x11BD},	
	{0x0996, 0xC2B8},	
	{0x0998, 0xCC06},	
	{0x099A, 0x28FD},	
	{0x099C, 0x036F},	
	{0x099E, 0xCC03},	
	{0x098C, 0x0495},	
	{0x0990, 0x61FD},	
	{0x0992, 0x02BD},	
	{0x0994, 0xDE00},	
	{0x0996, 0x18CE},	
	{0x0998, 0x00C2},	
	{0x099A, 0xCC00},	
	{0x099C, 0x37BD},	
	{0x099E, 0xC2B8},	
	{0x098C, 0x04A5},	
	{0x0990, 0xCC06},	
	{0x0992, 0x4FDD},	
	{0x0994, 0xE6CC},	
	{0x0996, 0x00C2},	
	{0x0998, 0xDD00},	
	{0x099A, 0xC601},	
	{0x099C, 0xF701},	
	{0x099E, 0x64C6},	
	{0x098C, 0x04B5},	
	{0x0990, 0x05F7},	
	{0x0992, 0x0165},	
	{0x0994, 0x7F01},	
	{0x0996, 0x6639},	
	{0x0998, 0x373C},	
	{0x099A, 0x3C3C},	
	{0x099C, 0x3C3C},	
	{0x099E, 0x30EC},	
	{0x098C, 0x04C5},	
	{0x0990, 0x11ED},	
	{0x0992, 0x02EC},	
	{0x0994, 0x0FED},	
	{0x0996, 0x008F},	
	{0x0998, 0x30ED},	
	{0x099A, 0x04EC},	
	{0x099C, 0x0DEE},	
	{0x099E, 0x04BD},	
	{0x098C, 0x04D5},	
	{0x0990, 0xA406},	
	{0x0992, 0x30EC},	
	{0x0994, 0x02ED},	
	{0x0996, 0x06FC},	
	{0x0998, 0x10C0},	
	{0x099A, 0x2705},	
	{0x099C, 0xCCFF},	
	{0x099E, 0xFFED},	
	{0x098C, 0x04E5},	
	{0x0990, 0x06F6},	
	{0x0992, 0x0256},	
	{0x0994, 0x8616},	
	{0x0996, 0x3DC3},	
	{0x0998, 0x0261},	
	{0x099A, 0x8FE6},	
	{0x099C, 0x09C4},	
	{0x099E, 0x07C1},	
	{0x098C, 0x04F5},	
	{0x0990, 0x0226},	
	{0x0992, 0x1DFC},	
	{0x0994, 0x10C2},	
	{0x0996, 0x30ED},	
	{0x0998, 0x02FC},	
	{0x099A, 0x10C0},	
	{0x099C, 0xED00},	
	{0x099E, 0xC602},	
	{0x098C, 0x0505},	
	{0x0990, 0xBDC2},	
	{0x0992, 0x5330},	
	{0x0994, 0xEC00},	
	{0x0996, 0xFD10},	
	{0x0998, 0xC0EC},	
	{0x099A, 0x02FD},	
	{0x099C, 0x10C2},	
	{0x099E, 0x201B},	
	{0x098C, 0x0515},	
	{0x0990, 0xFC10},	
	{0x0992, 0xC230},	
	{0x0994, 0xED02},	
	{0x0996, 0xFC10},	
	{0x0998, 0xC0ED},	
	{0x099A, 0x00C6},	
	{0x099C, 0x01BD},	
	{0x099E, 0xC253},	
	{0x098C, 0x0525},	
	{0x0990, 0x30EC},	
	{0x0992, 0x00FD},	
	{0x0994, 0x10C0},	
	{0x0996, 0xEC02},	
	{0x0998, 0xFD10},	
	{0x099A, 0xC2C6},	
	{0x099C, 0x80D7},	
	{0x099E, 0x85C6},	
	{0x098C, 0x0535},	
	{0x0990, 0x40F7},	
	{0x0992, 0x10C4},	
	{0x0994, 0xF602},	
	{0x0996, 0x5686},	
	{0x0998, 0x163D},	
	{0x099A, 0xC302},	
	{0x099C, 0x618F},	
	{0x099E, 0xEC14},	
	{0x098C, 0x0545},	
	{0x0990, 0xFD10},	
	{0x0992, 0xC501},	
	{0x0994, 0x0101},	
	{0x0996, 0x0101},	
	{0x0998, 0xFC10},	
	{0x099A, 0xC2DD},	
	{0x099C, 0x7FFC},	
	{0x099E, 0x10C7},	
	{0x098C, 0x0555},	
	{0x0990, 0xDD76},	
	{0x0992, 0xF602},	
	{0x0994, 0x5686},	
	{0x0996, 0x163D},	
	{0x0998, 0xC302},	
	{0x099A, 0x618F},	
	{0x099C, 0xEC14},	
	{0x099E, 0x939F},	
	{0x098C, 0x0565},	
	{0x0990, 0x30ED},	
	{0x0992, 0x08DC},	
	{0x0994, 0x7693},	
	{0x0996, 0x9D25},	
	{0x0998, 0x08F6},	
	{0x099A, 0x02BC},	
	{0x099C, 0x4F93},	
	{0x099E, 0x7F23},	
	{0x098C, 0x0575},	
	{0x0990, 0x3DF6},	
	{0x0992, 0x02BC},	
	{0x0994, 0x4F93},	
	{0x0996, 0x7F23},	
	{0x0998, 0x06F6},	
	{0x099A, 0x02BC},	
	{0x099C, 0x4FDD},	
	{0x099E, 0x7FDC},	
	{0x098C, 0x0585},	
	{0x0990, 0x9DDD},	
	{0x0992, 0x76F6},	
	{0x0994, 0x02BC},	
	{0x0996, 0x4F93},	
	{0x0998, 0x7F26},	
	{0x099A, 0x0FE6},	
	{0x099C, 0x0AC1},	
	{0x099E, 0x0226},	
	{0x098C, 0x0595},	
	{0x0990, 0x09D6},	
	{0x0992, 0x85C1},	
	{0x0994, 0x8026},	
	{0x0996, 0x0314},	
	{0x0998, 0x7401},	
	{0x099A, 0xF602},	
	{0x099C, 0xBC4F},	
	{0x099E, 0x937F},	
	{0x098C, 0x05A5},	
	{0x0990, 0x2416},	
	{0x0992, 0xDE7F},	
	{0x0994, 0x09DF},	
	{0x0996, 0x7F30},	
	{0x0998, 0xEC08},	
	{0x099A, 0xDD76},	
	{0x099C, 0x200A},	
	{0x099E, 0xDC76},	
	{0x098C, 0x05B5},	
	{0x0990, 0xA308},	
	{0x0992, 0x2304},	
	{0x0994, 0xEC08},	
	{0x0996, 0xDD76},	
	{0x0998, 0x1274},	
	{0x099A, 0x0122},	
	{0x099C, 0xDE5D},	
	{0x099E, 0xEE14},	
	{0x098C, 0x05C5},	
	{0x0990, 0xAD00},	
	{0x0992, 0x30ED},	
	{0x0994, 0x11EC},	
	{0x0996, 0x06ED},	
	{0x0998, 0x02CC},	
	{0x099A, 0x0080},	
	{0x099C, 0xED00},	
	{0x099E, 0x8F30},	
	{0x098C, 0x05D5},	
	{0x0990, 0xED04},	
	{0x0992, 0xEC11},	
	{0x0994, 0xEE04},	
	{0x0996, 0xBDA4},	
	{0x0998, 0x0630},	
	{0x099A, 0xE603},	
	{0x099C, 0xD785},	
	{0x099E, 0x30C6},	
	{0x098C, 0x05E5},	
	{0x0990, 0x0B3A},	
	{0x0992, 0x3539},	
	{0x0994, 0x3C3C},	
	{0x0996, 0x3C34},	
	{0x0998, 0xCC32},	
	{0x099A, 0x3EBD},	
	{0x099C, 0xA558},	
	{0x099E, 0x30ED},	
	{0x098C, 0x05F5},	
	{0x0990, 0x04BD},	
	{0x0992, 0xB2D7},	
	{0x0994, 0x30E7},	
	{0x0996, 0x06CC},	
	{0x0998, 0x323E},	
	{0x099A, 0xED00},	
	{0x099C, 0xEC04},	
	{0x099E, 0xBDA5},	
	{0x098C, 0x0605},	
	{0x0990, 0x44CC},	
	{0x0992, 0x3244},	
	{0x0994, 0xBDA5},	
	{0x0996, 0x585F},	
	{0x0998, 0x30ED},	
	{0x099A, 0x02CC},	
	{0x099C, 0x3244},	
	{0x099E, 0xED00},	
	{0x098C, 0x0615},	
	{0x0990, 0xF601},	
	{0x0992, 0xD54F},	
	{0x0994, 0xEA03},	
	{0x0996, 0xAA02},	
	{0x0998, 0xBDA5},	
	{0x099A, 0x4430},	
	{0x099C, 0xE606},	
	{0x099E, 0x3838},	
	{0x098C, 0x0625},	
	{0x0990, 0x3831},	
	{0x0992, 0x39BD},	
	{0x0994, 0xD661},	
	{0x0996, 0xF602},	
	{0x0998, 0xF4C1},	
	{0x099A, 0x0126},	
	{0x099C, 0x0BFE},	
	{0x099E, 0x02BD},	
	{0x098C, 0x0635},	
	{0x0990, 0xEE10},	
	{0x0992, 0xFC02},	
	{0x0994, 0xF5AD},	
	{0x0996, 0x0039},	
	{0x0998, 0xF602},	
	{0x099A, 0xF4C1},	
	{0x099C, 0x0226},	
	{0x099E, 0x0AFE},	
	{0x098C, 0x0645},	
	{0x0990, 0x02BD},	
	{0x0992, 0xEE10},	
	{0x0994, 0xFC02},	
	{0x0996, 0xF7AD},	
	{0x0998, 0x0039},	
	{0x099A, 0x3CBD},	
	{0x099C, 0xB059},	
	{0x099E, 0xCC00},	
	{0x098C, 0x0655},	
	{0x0990, 0x28BD},	
	{0x0992, 0xA558},	
	{0x0994, 0x8300},	
	{0x0996, 0x0027},	
	{0x0998, 0x0BCC},	
	{0x099A, 0x0026},	
	{0x099C, 0x30ED},	
	{0x099E, 0x00C6},	
	{0x098C, 0x0665},	
	{0x0990, 0x03BD},	
	{0x0992, 0xA544},	
	{0x0994, 0x3839},	
	{0x0996, 0xBDD9},	
	{0x0998, 0x42D6},	
	{0x099A, 0x9ACB},	
	{0x099C, 0x01D7},	
	{0x099E, 0x9B39},	
	{0x098C, 0x2006},	
	{0x0990, 0x0415},	
	{0x098C, 0xA005},	
	{0x0990, 0x0001}	
						
						
};




static struct msm_camera_i2c_reg_conf
LSC_array[] = {
						
	{0x364E, 0x09F0},	
	{0x3650, 0xE84C},	
	{0x3652, 0x4F31},	
	{0x3654, 0x4E10},	
	{0x3656, 0x91D3},	
	{0x3658, 0x02B0},	
	{0x365A, 0xE3AC},	
	{0x365C, 0x6CF1},	
	{0x365E, 0x2C70},	
	{0x3660, 0xA232},	
	{0x3662, 0x02D0},	
	{0x3664, 0x882D},	
	{0x3666, 0x6330},	
	{0x3668, 0x3270},	
	{0x366A, 0x8CD2},	
	{0x366C, 0x0350},	
	{0x366E, 0xDE4C},	
	{0x3670, 0x58F1},	
	{0x3672, 0x49F0},	
	{0x3674, 0x9633},	
	{0x3676, 0x67ED},	
	{0x3678, 0xC9CE},	
	{0x367A, 0x88D0},	
	{0x367C, 0x926E},	
	{0x367E, 0x67D3},	
	{0x3680, 0x0DAE},	
	{0x3682, 0x564E},	
	{0x3684, 0x81AF},	
	{0x3686, 0x8ED2},	
	{0x3688, 0x3E53},	
	{0x368A, 0x9F8A},	
	{0x368C, 0xB6C9},	
	{0x368E, 0x802F},	
	{0x3690, 0xD490},	
	{0x3692, 0x1C93},	
	{0x3694, 0x70AB},	
	{0x3696, 0x47EF},	
	{0x3698, 0xBD4F},	
	{0x369A, 0x9F72},	
	{0x369C, 0x4213},	
	{0x369E, 0x3EF2},	
	{0x36A0, 0x3731},	
	{0x36A2, 0xBE34},	
	{0x36A4, 0x9234},	
	{0x36A6, 0x1677},	
	{0x36A8, 0x34B2},	
	{0x36AA, 0x1751},	
	{0x36AC, 0x9F13},	
	{0x36AE, 0x9174},	
	{0x36B0, 0x1896},	
	{0x36B2, 0x0072},	
	{0x36B4, 0x1B71},	
	{0x36B6, 0x8232},	
	{0x36B8, 0x9BF4},	
	{0x36BA, 0x5415},	
	{0x36BC, 0x2FF2},	
	{0x36BE, 0x3A91},	
	{0x36C0, 0x8634},	
	{0x36C2, 0xF633},	
	{0x36C4, 0x46B6},	
	{0x36C6, 0x9B10},	
	{0x36C8, 0x72D1},	
	{0x36CA, 0x3FB5},	
	{0x36CC, 0xFC13},	
	{0x36CE, 0xA218},	
	{0x36D0, 0x840F},	
	{0x36D2, 0x4271},	
	{0x36D4, 0x4115},	
	{0x36D6, 0x8114},	
	{0x36D8, 0xAF58},	
	{0x36DA, 0x7209},	
	{0x36DC, 0x3ED1},	
	{0x36DE, 0x7C34},	
	{0x36E0, 0xEEF2},	
	{0x36E2, 0xE9D7},	
	{0x36E4, 0x97AF},	
	{0x36E6, 0xA2AE},	
	{0x36E8, 0x1A95},	
	{0x36EA, 0xA972},	
	{0x36EC, 0x9218},	
	{0x36EE, 0xA614},	
	{0x36F0, 0xDCB3},	
	{0x36F2, 0x0EB7},	
	{0x36F4, 0x3D95},	
	{0x36F6, 0x8DB9},	
	{0x36F8, 0xAB13},	
	{0x36FA, 0x222B},	
	{0x36FC, 0x39F5},	
	{0x36FE, 0x9D51},	
	{0x3700, 0xAE58},	
	{0x3702, 0xC9B3},	
	{0x3704, 0xDD11},	
	{0x3706, 0x48F4},	
	{0x3708, 0x18F5},	
	{0x370A, 0x7E36},	
	{0x370C, 0x88B4},	
	{0x370E, 0xDAD3},	
	{0x3710, 0x0F35},	
	{0x3712, 0x1E34},	
	{0x3714, 0x6B96},	
	{0x3644, 0x0320},	
	{0x3642, 0x0258}	
						
};




static struct msm_camera_i2c_reg_conf
AE_Window_setting_array[] = {
						
	{0x098C, 0xA202},	
	{0x0990, 0x0034},	
	{0x098C, 0xA203},	
	{0x0990, 0x0097},	

						
	{0x098C, 0xA11E},	
	{0x0990, 0x0001},	
	{0x098C, 0xA404},	
	{0x0990, 0x0020}	

};




static struct msm_camera_i2c_reg_conf
Continue_setting_1_array[] = {
						
	{0x0018, 0x0028}	
						
};

static struct msm_camera_i2c_reg_conf
Continue_setting_2_array[] = {
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
};

static struct msm_camera_i2c_reg_conf
ref_array[] = {
						
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};


static struct msm_camera_i2c_conf_array mt9d115_sub_init_confs[MT9D115_REG_INIT_MAX] = {
    {&Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_1_array[0],ARRAY_SIZE(Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_1_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_2_array[0],ARRAY_SIZE(Register_Wizard_Defaults_Programming_PLL_4_MIPI_YUV422_setting_2_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Register_Wizard_Defaults_Sensor_Core_Timing_4_MIPI_setting_array[0],		ARRAY_SIZE(Register_Wizard_Defaults_Sensor_Core_Timing_4_MIPI_setting_array),		0,	MSM_CAMERA_I2C_WORD_DATA},
    {&LSC_array[0],																ARRAY_SIZE(LSC_array),																0,	MSM_CAMERA_I2C_WORD_DATA},
    {&AE_Window_setting_array[0],												ARRAY_SIZE(AE_Window_setting_array),												0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Continue_setting_1_array[0],												ARRAY_SIZE(Continue_setting_1_array),												0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Continue_setting_2_array[0],												ARRAY_SIZE(Continue_setting_2_array),												0,	MSM_CAMERA_I2C_WORD_DATA},
    {&ref_array[0],																ARRAY_SIZE(ref_array),																0,	MSM_CAMERA_I2C_WORD_DATA}
};





static struct msm_camera_i2c_reg_conf
White_Balance_setting_Auto_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x0069},	
	{0x098C, 0xA34B},	
	{0x0990, 0x00B6},	
	{0x098C, 0xA34C},	
	{0x0990, 0x0076},	
	{0x098C, 0xA34D},	
	{0x0990, 0x00A0},	
	{0x098C, 0xA351},	
	{0x0990, 0x0000},	
	{0x098C, 0xA352},	
	{0x0990, 0x007F}	
};

static struct msm_camera_i2c_reg_conf
White_Balance_setting_INCANDESCENT_2700_3500K_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x0070},	
	{0x098C, 0xA34B},	
	{0x0990, 0x009D},	
	{0x098C, 0xA34C},	
	{0x0990, 0x007C},	
	{0x098C, 0xA34D},	
	{0x0990, 0x008D},	
	{0x098C, 0xA351},	
	{0x0990, 0x0000},	
	{0x098C, 0xA352},	
	{0x0990, 0x0020},	
	{0x098C, 0xA353},	
	{0x0990, 0x000A}	
};

static struct msm_camera_i2c_reg_conf
White_Balance_setting_FLOURESCENT_3800_5500K_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x0088},	
	{0x098C, 0xA34B},	
	{0x0990, 0x00B0},	
	{0x098C, 0xA34C},	
	{0x0990, 0x006E},	
	{0x098C, 0xA34D},	
	{0x0990, 0x009D},	
	{0x098C, 0xA351},	
	{0x0990, 0x0030},	
	{0x098C, 0xA352},	
	{0x0990, 0x0055},	
	{0x098C, 0xA353},	
	{0x0990, 0x0049}	
};

static struct msm_camera_i2c_reg_conf
White_Balance_setting_FLOURESCENT_5000_6500K_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x008B},	
	{0x098C, 0xA34B},	
	{0x0990, 0x009B},	
	{0x098C, 0xA34C},	
	{0x0990, 0x006C},	
	{0x098C, 0xA34D},	
	{0x0990, 0x0090},	
	{0x098C, 0xA351},	
	{0x0990, 0x0050},	
	{0x098C, 0xA352},	
	{0x0990, 0x0070},	
	{0x098C, 0xA353},	
	{0x0990, 0x0061}	
};

static struct msm_camera_i2c_reg_conf
White_Balance_setting_DAYLIGHT_4500_6500K_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x0080},	
	{0x098C, 0xA34B},	
	{0x0990, 0x009F},	
	{0x098C, 0xA34C},	
	{0x0990, 0x0076},	
	{0x098C, 0xA34D},	
	{0x0990, 0x00C5},	
	{0x098C, 0xA351},	
	{0x0990, 0x0055},	
	{0x098C, 0xA352},	
	{0x0990, 0x007F},	
	{0x098C, 0xA353},	
	{0x0990, 0x006A}	
};

static struct msm_camera_i2c_reg_conf
White_Balance_setting_CLOUDY_5500_8000K_array[] = {
						
	{0x098C, 0xA34A},	
	{0x0990, 0x0087},	
	{0x098C, 0xA34B},	
	{0x0990, 0x00AF},	
	{0x098C, 0xA34C},	
	{0x0990, 0x0075},	
	{0x098C, 0xA34D},	
	{0x0990, 0x009B},	
	{0x098C, 0xA351},	
	{0x0990, 0x0060},	
	{0x098C, 0xA352},	
	{0x0990, 0x007F},	
	{0x098C, 0xA353},	
	{0x0990, 0x0070}	
};

static struct msm_camera_i2c_conf_array mt9d115_White_Balance_settings[MT9D115_WB_MAX] = {
	{&White_Balance_setting_Auto_array[0],						ARRAY_SIZE(White_Balance_setting_Auto_array),					0,MSM_CAMERA_I2C_WORD_DATA},
	{&White_Balance_setting_INCANDESCENT_2700_3500K_array[0],	ARRAY_SIZE(White_Balance_setting_INCANDESCENT_2700_3500K_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&White_Balance_setting_FLOURESCENT_3800_5500K_array[0],	ARRAY_SIZE(White_Balance_setting_FLOURESCENT_3800_5500K_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&White_Balance_setting_FLOURESCENT_5000_6500K_array[0],	ARRAY_SIZE(White_Balance_setting_FLOURESCENT_5000_6500K_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&White_Balance_setting_DAYLIGHT_4500_6500K_array[0],		ARRAY_SIZE(White_Balance_setting_DAYLIGHT_4500_6500K_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&White_Balance_setting_CLOUDY_5500_8000K_array[0],			ARRAY_SIZE(White_Balance_setting_CLOUDY_5500_8000K_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};





static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus6_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0001},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0003},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0009},	
	{0x098C, 0xAB40},	
	{0x0990, 0x001D},	
	{0x098C, 0xAB41},	
	{0x0990, 0x0032},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0048},	
	{0x098C, 0xAB43},	
	{0x0990, 0x0061},	
	{0x098C, 0xAB44},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB45},	
	{0x0990, 0x0096},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00AC},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00BD},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00CC},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00D7},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00E2},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00EA},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F2},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00F9},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus5_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0001},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0004},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x000C},	
	{0x098C, 0xAB40},	
	{0x0990, 0x0023},	
	{0x098C, 0xAB41},	
	{0x0990, 0x003B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0053},	
	{0x098C, 0xAB43},	
	{0x0990, 0x006D},	
	{0x098C, 0xAB44},	
	{0x0990, 0x0089},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00A1},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00B4},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00C4},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00D0},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00DB},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00E4},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F3},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00F9},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus4_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0002},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0005},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0010},	
	{0x098C, 0xAB40},	
	{0x0990, 0x002C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x0046},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0060},	
	{0x098C, 0xAB43},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB44},	
	{0x0990, 0x0096},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00AB},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00BB},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00D4},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00DE},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00ED},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FA},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus3_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0002},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0016},	
	{0x098C, 0xAB40},	
	{0x0990, 0x0037},	
	{0x098C, 0xAB41},	
	{0x0990, 0x0054},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0070},	
	{0x098C, 0xAB43},	
	{0x0990, 0x008B},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00A2},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00B3},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00C2},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00CD},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00D8},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00E0},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00E8},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00EE},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FA},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus2_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0003},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0009},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x001E},	
	{0x098C, 0xAB40},	
	{0x0990, 0x0044},	
	{0x098C, 0xAB41},	
	{0x0990, 0x0063},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0080},	
	{0x098C, 0xAB43},	
	{0x0990, 0x0099},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00AC},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00BB},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00C8},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00DB},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00E3},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00EA},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F5},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FA},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus1_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0004},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x000D},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0029},	
	{0x098C, 0xAB40},	
	{0x0990, 0x0054},	
	{0x098C, 0xAB41},	
	{0x0990, 0x0075},	
	{0x098C, 0xAB42},	
	{0x0990, 0x0091},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00A6},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00B6},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00C3},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00CE},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00D7},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00DF},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00E5},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F1},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F6},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FB},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_minus0_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0000},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus1_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0010},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0020},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus2_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0020},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0020},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus3_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0030},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0030},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus4_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0040},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0040},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus5_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0050},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0050},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
brightness_setting_brightness_plus6_array[] = {
						
	{0x098C, 0xAB37},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3C},	
	{0x0990, 0x0000},	
	{0x098C, 0xAB3D},	
	{0x0990, 0x0007},	
	{0x098C, 0xAB3E},	
	{0x0990, 0x0018},	
	{0x098C, 0xAB3F},	
	{0x0990, 0x0049},	
	{0x098C, 0xAB40},	
	{0x0990, 0x007C},	
	{0x098C, 0xAB41},	
	{0x0990, 0x009B},	
	{0x098C, 0xAB42},	
	{0x0990, 0x00AF},	
	{0x098C, 0xAB43},	
	{0x0990, 0x00BE},	
	{0x098C, 0xAB44},	
	{0x0990, 0x00C9},	
	{0x098C, 0xAB45},	
	{0x0990, 0x00D2},	
	{0x098C, 0xAB46},	
	{0x0990, 0x00DA},	
	{0x098C, 0xAB47},	
	{0x0990, 0x00E1},	
	{0x098C, 0xAB48},	
	{0x0990, 0x00E6},	
	{0x098C, 0xAB49},	
	{0x0990, 0x00EC},	
	{0x098C, 0xAB4A},	
	{0x0990, 0x00F0},	
	{0x098C, 0xAB4B},	
	{0x0990, 0x00F4},	
	{0x098C, 0xAB4C},	
	{0x0990, 0x00F8},	
	{0x098C, 0xAB4D},	
	{0x0990, 0x00FC},	
	{0x098C, 0xAB4E},	
	{0x0990, 0x00FF},	
	{0x098C, 0xAB37},	
	{0x0990, 0x0001},	
	{0x098C, 0xA75D},	
	{0x0990, 0x0060},	
	{0x098C, 0xA75E},	
	{0x0990, 0x0060},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_brightness_settings[MT9D115_BN_MAX] = {
	{&brightness_setting_brightness_minus6_array[0],ARRAY_SIZE(brightness_setting_brightness_minus6_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus5_array[0],ARRAY_SIZE(brightness_setting_brightness_minus5_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus4_array[0],ARRAY_SIZE(brightness_setting_brightness_minus4_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus3_array[0],ARRAY_SIZE(brightness_setting_brightness_minus3_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus2_array[0],ARRAY_SIZE(brightness_setting_brightness_minus2_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus1_array[0],ARRAY_SIZE(brightness_setting_brightness_minus1_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_minus0_array[0],ARRAY_SIZE(brightness_setting_brightness_minus0_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus1_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus1_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus2_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus2_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus3_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus3_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus4_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus4_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus5_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus5_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&brightness_setting_brightness_plus6_array[0],	ARRAY_SIZE(brightness_setting_brightness_plus6_array),	0,MSM_CAMERA_I2C_WORD_DATA}
};





static struct msm_camera_i2c_reg_conf
Special_Effects_setting_Effect_off_array[] = {
						
	{0x098C, 0x2759},	
	{0x0990, 0x6440},	
	{0x098C, 0x275B},	
	{0x0990, 0x6440},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Special_Effects_setting_mono_array[] = {
						
	{0x098C, 0x2759},	
	{0x0990, 0x6441},	
	{0x098C, 0x275B},	
	{0x0990, 0x6441},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Special_Effects_setting_Sepia_array[] = {
						
	{0x098C, 0x2763},	
	{0x0990, 0xE812},	
	{0x098C, 0x2759},	
	{0x0990, 0x6442},	
	{0x098C, 0x275B},	
	{0x0990, 0x6442},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Special_Effects_setting_Negative_array[] = {
						
	{0x098C, 0x2759},	
	{0x0990, 0x6443},	
	{0x098C, 0x275B},	
	{0x0990, 0x6443},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_Special_Effects_settings[MT9D115_SE_MAX] = {
	{&Special_Effects_setting_Effect_off_array[0],	ARRAY_SIZE(Special_Effects_setting_Effect_off_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&Special_Effects_setting_mono_array[0],		ARRAY_SIZE(Special_Effects_setting_mono_array),			0,MSM_CAMERA_I2C_WORD_DATA},
	{&Special_Effects_setting_Sepia_array[0],		ARRAY_SIZE(Special_Effects_setting_Sepia_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&Special_Effects_setting_Negative_array[0],	ARRAY_SIZE(Special_Effects_setting_Negative_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};


#if 0



static struct msm_camera_i2c_reg_conf
AE_measurement_method_setting_spot_array[] = {
						
	{0x098C, 0xA202},	
	{0x0990, 0x0066},	
	{0x098C, 0xA203},	
	{0x0990, 0x0033},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
AE_measurement_method_setting_average_array[] = {
						
	{0x098C, 0xA202},	
	{0x0990, 0x0000},	
	{0x098C, 0xA203},	
	{0x0990, 0x00FF},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_AE_measurement_method_settings[MT9D115_AE_MAX] = {
	{&AE_measurement_method_setting_spot_array[0],		ARRAY_SIZE(AE_measurement_method_setting_spot_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&AE_measurement_method_setting_average_array[0],	ARRAY_SIZE(AE_measurement_method_setting_average_array),10,MSM_CAMERA_I2C_WORD_DATA}
};
#endif




static struct msm_camera_i2c_reg_conf
Flicker_setting_flicker_60Hz_array[] = {
						
	{0x098C, 0xA11E},	
	{0x0990, 0x0002},	
	{0x098C, 0xA404},	
	{0x0990, 0x0090},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Flicker_setting_flicker_50Hz_array[] = {
						
	{0x098C, 0xA11E},	
	{0x0990, 0x0002},	
	{0x098C, 0xA404},	
	{0x0990, 0x00D0},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Flicker_setting_flicker_auto_array[] = {
						
	{0x098C, 0xA11E},	
	{0x0990, 0x0001},	
	{0x098C, 0xA404},	
	{0x0990, 0x0020},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_Flicker_settings[MT9D115_FL_MAX] = {
	{&Flicker_setting_flicker_60Hz_array[0],ARRAY_SIZE(Flicker_setting_flicker_60Hz_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&Flicker_setting_flicker_50Hz_array[0],ARRAY_SIZE(Flicker_setting_flicker_50Hz_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&Flicker_setting_flicker_auto_array[0],ARRAY_SIZE(Flicker_setting_flicker_auto_array),	0,MSM_CAMERA_I2C_WORD_DATA}
};

#if 0



static struct msm_camera_i2c_reg_conf
Position_setting_Normal_Position_array[] = {
						
	{0x098C, 0x2717},	
	{0x0990, 0x0024},	
	{0x098C, 0x272D},	
	{0x0990, 0x0024},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
};

static struct msm_camera_i2c_reg_conf
Position_setting_Horizontal_Mirror_array[] = {
						
	{0x098C, 0x2717},	
	{0x0990, 0x0025},	
	{0x098C, 0x272D},	
	{0x0990, 0x0025},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
};

static struct msm_camera_i2c_reg_conf
Position_setting_Vertical_Flip_array[] = {
						
	{0x098C, 0x2717},	
	{0x0990, 0x0026},	
	{0x098C, 0x272D},	
	{0x0990, 0x0026},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
};

static struct msm_camera_i2c_reg_conf
Position_setting_Rotate_180minus_array[] = {
						
	{0x098C, 0x2717},	
	{0x0990, 0x0027},	
	{0x098C, 0x272D},	
	{0x0990, 0x0027},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_Position_settings[MT9D115_PO_MAX] = {
	{&Position_setting_Normal_Position_array[0],	ARRAY_SIZE(Position_setting_Normal_Position_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&Position_setting_Horizontal_Mirror_array[0],	ARRAY_SIZE(Position_setting_Horizontal_Mirror_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Position_setting_Vertical_Flip_array[0],		ARRAY_SIZE(Position_setting_Vertical_Flip_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&Position_setting_Rotate_180minus_array[0],	ARRAY_SIZE(Position_setting_Rotate_180minus_array),		10,MSM_CAMERA_I2C_WORD_DATA}
};
#endif
#if 0



static struct msm_camera_i2c_reg_conf
Noise_Reduction_setting_plus2_array[] = {
						
	{0x098C, 0xAB23},	
	{0x0990, 0x0000},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Noise_Reduction_setting_plus1_array[] = {
						
	{0x098C, 0xAB23},	
	{0x0990, 0x0001},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Noise_Reduction_setting_Default_array[] = {
						
	{0x098C, 0xAB23},	
	{0x0990, 0x0004},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Noise_Reduction_setting_minus1_array[] = {
						
	{0x098C, 0xAB23},	
	{0x0990, 0x0005},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Noise_Reduction_setting_minus2_array[] = {
						
	{0x098C, 0xAB23},	
	{0x0990, 0x0009},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_Noise_Reduction_settings[MT9D115_NR_MAX] = {
	{&Noise_Reduction_setting_plus2_array[0],	ARRAY_SIZE(Noise_Reduction_setting_plus2_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Noise_Reduction_setting_plus1_array[0],	ARRAY_SIZE(Noise_Reduction_setting_plus1_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Noise_Reduction_setting_Default_array[0],	ARRAY_SIZE(Noise_Reduction_setting_Default_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Noise_Reduction_setting_minus1_array[0],	ARRAY_SIZE(Noise_Reduction_setting_minus1_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Noise_Reduction_setting_minus2_array[0],	ARRAY_SIZE(Noise_Reduction_setting_minus2_array),	10,MSM_CAMERA_I2C_WORD_DATA}
};





static struct msm_camera_i2c_reg_conf
Sharpness_setting_plus2_array[] = {
						
	{0x098C, 0xAB22},	
	{0x0990, 0x0007},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Sharpness_setting_plus1_array[] = {
						
	{0x098C, 0xAB22},	
	{0x0990, 0x0006},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Sharpness_setting_Defalut_array[] = {
						
	{0x098C, 0xAB22},	
	{0x0990, 0x0005},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Sharpness_setting_minus1_array[] = {
						
	{0x098C, 0xAB22},	
	{0x0990, 0x0004},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Sharpness_setting_minus2_array[] = {
						
	{0x098C, 0xAB22},	
	{0x0990, 0x0003},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_Sharpness_setting_settings[MT9D115_SH_MAX] = {
	{&Sharpness_setting_plus2_array[0],		ARRAY_SIZE(Sharpness_setting_plus2_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Sharpness_setting_plus1_array[0],		ARRAY_SIZE(Sharpness_setting_plus1_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Sharpness_setting_Defalut_array[0],	ARRAY_SIZE(Sharpness_setting_Defalut_array),10,MSM_CAMERA_I2C_WORD_DATA},
	{&Sharpness_setting_minus1_array[0],	ARRAY_SIZE(Sharpness_setting_minus1_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Sharpness_setting_minus2_array[0],	ARRAY_SIZE(Sharpness_setting_minus2_array),	10,MSM_CAMERA_I2C_WORD_DATA}
};
#endif
#if 0



static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_1600x1200_Cap_1600x1200_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0640},	
	{0x098C, 0x2705},	
	{0x0990, 0x04B0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0640},	
	{0x098C, 0x2709},	
	{0x0990, 0x04B0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0010}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_960x720_Cap_1600x1200_array[] = {
						
	{0x98C, 0x2703},	
	{0x990, 0x03C0},	
	{0x98C, 0x2705},	
	{0x990, 0x02D0},	
	{0x98C, 0x2707},	
	{0x990, 0x0640},	
	{0x98C, 0x2709},	
	{0x990, 0x04B0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000F}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_1152x720_Cap_1280x800_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0480},	
	{0x098C, 0x2705},	
	{0x0990, 0x02D0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0500},	
	{0x098C, 0x2709},	
	{0x0990, 0x0320},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0064},	
	{0x098C, 0x273F},	
	{0x0990, 0x044B},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0064},	
	{0x098C, 0x274D},	
	{0x0990, 0x044B},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000F}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_640x480_Cap_640x480_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0280},	
	{0x098C, 0x2705},	
	{0x0990, 0x01E0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0280},	
	{0x098C, 0x2709},	
	{0x0990, 0x01E0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000F}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_1280x720_Cap_1280x720_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0500},	
	{0x098C, 0x2705},	
	{0x0990, 0x02D0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0500},	
	{0x098C, 0x2709},	
	{0x0990, 0x02D0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0096},	
	{0x098C, 0x273F},	
	{0x0990, 0x0419},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0096},	
	{0x098C, 0x274D},	
	{0x0990, 0x0419},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_v_Pre_640x480_Cap_640x480_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0280},	
	{0x098C, 0x2705},	
	{0x0990, 0x01E0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0280},	
	{0x098C, 0x2709},	
	{0x0990, 0x01E0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_320x240_Cap_320x240_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0140},	
	{0x098C, 0x2705},	
	{0x0990, 0x00F0},	
	{0x098C, 0x2707},	
	{0x0990, 0x0140},	
	{0x098C, 0x2709},	
	{0x0990, 0x00F0},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_176x144_Cap_176x144_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x00B0},	
	{0x098C, 0x2705},	
	{0x0990, 0x0090},	
	{0x098C, 0x2707},	
	{0x0990, 0x00B0},	
	{0x098C, 0x2709},	
	{0x0990, 0x0090},	
	{0x098C, 0x2739},	
	{0x0990, 0x0043},	
	{0x098C, 0x273B},	
	{0x0990, 0x05FC},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0043},	
	{0x098C, 0x2749},	
	{0x0990, 0x05FC},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_1424x800_Cap_1424x800_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0590},	
	{0x098C, 0x2705},	
	{0x0990, 0x0320},	
	{0x098C, 0x2707},	
	{0x0990, 0x0590},	
	{0x098C, 0x2709},	
	{0x0990, 0x0320},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0096},	
	{0x098C, 0x273F},	
	{0x0990, 0x0419},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0096},	
	{0x098C, 0x274D},	
	{0x0990, 0x0419},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_800x600_Cap_800x600_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0320},	
	{0x098C, 0x2705},	
	{0x0990, 0x0258},	
	{0x098C, 0x2707},	
	{0x0990, 0x0320},	
	{0x098C, 0x2709},	
	{0x0990, 0x0258},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0010}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_400x300_Cap_400x300_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x0190},	
	{0x098C, 0x2705},	
	{0x0990, 0x012C},	
	{0x098C, 0x2707},	
	{0x0990, 0x0190},	
	{0x098C, 0x2709},	
	{0x0990, 0x012C},	
	{0x098C, 0x2739},	
	{0x0990, 0x0000},	
	{0x098C, 0x273B},	
	{0x0990, 0x063F},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0000},	
	{0x098C, 0x2749},	
	{0x0990, 0x063F},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Pre_224x180_Cap_224x180_array[] = {
						
	{0x098C, 0x2703},	
	{0x0990, 0x00E0},	
	{0x098C, 0x2705},	
	{0x0990, 0x00B4},	
	{0x098C, 0x2707},	
	{0x0990, 0x00E0},	
	{0x098C, 0x2709},	
	{0x0990, 0x00B4},	
	{0x098C, 0x2739},	
	{0x0990, 0x0032},	
	{0x098C, 0x273B},	
	{0x0990, 0x060D},	
	{0x098C, 0x273D},	
	{0x0990, 0x0000},	
	{0x098C, 0x273F},	
	{0x0990, 0x04AF},	
	{0x098C, 0x2747},	
	{0x0990, 0x0032},	
	{0x098C, 0x2749},	
	{0x0990, 0x060D},	
	{0x098C, 0x274B},	
	{0x0990, 0x0000},	
	{0x098C, 0x274D},	
	{0x0990, 0x04AF},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_SIZE_setting_settings[MT9D115_SIZE_MAX] = {
	{&SIZE_setting_Pre_1600x1200_Cap_1600x1200_array[0],ARRAY_SIZE(SIZE_setting_Pre_1600x1200_Cap_1600x1200_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_960x720_Cap_1600x1200_array[0],	ARRAY_SIZE(SIZE_setting_Pre_960x720_Cap_1600x1200_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_v_Pre_640x480_Cap_640x480_array[0],	ARRAY_SIZE(SIZE_setting_v_Pre_640x480_Cap_640x480_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_640x480_Cap_640x480_array[0],	ARRAY_SIZE(SIZE_setting_Pre_640x480_Cap_640x480_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_320x240_Cap_320x240_array[0],	ARRAY_SIZE(SIZE_setting_Pre_320x240_Cap_320x240_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_176x144_Cap_176x144_array[0],	ARRAY_SIZE(SIZE_setting_Pre_176x144_Cap_176x144_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_1280x720_Cap_1280x720_array[0],	ARRAY_SIZE(SIZE_setting_Pre_1280x720_Cap_1280x720_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_1152x720_Cap_1280x800_array[0],	ARRAY_SIZE(SIZE_setting_Pre_1152x720_Cap_1280x800_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_1424x800_Cap_1424x800_array[0],	ARRAY_SIZE(SIZE_setting_Pre_1424x800_Cap_1424x800_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_800x600_Cap_800x600_array[0],	ARRAY_SIZE(SIZE_setting_Pre_800x600_Cap_800x600_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_400x300_Cap_400x300_array[0],	ARRAY_SIZE(SIZE_setting_Pre_400x300_Cap_400x300_array),		10,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Pre_224x180_Cap_224x180_array[0],	ARRAY_SIZE(SIZE_setting_Pre_224x180_Cap_224x180_array),		10,MSM_CAMERA_I2C_WORD_DATA}
};
#endif
#if 0



static struct msm_camera_i2c_reg_conf
Anti_shaking_setting_Enable_array[] = {
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0040},	
	{0x098C, 0x2212},	
	{0x0990, 0x012C},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0007},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0007}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Anti_shaking_setting_Disable_array[] = {
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0020},	
	{0x098C, 0x2212},	
	{0x0990, 0x012C},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000F}	
						
						
						
						
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_Anti_shaking_settings[MT9D115_AS_MAX] = {
	{&Anti_shaking_setting_Enable_array[0],	ARRAY_SIZE(Anti_shaking_setting_Enable_array),	10,MSM_CAMERA_I2C_WORD_DATA},
	{&Anti_shaking_setting_Disable_array[0],ARRAY_SIZE(Anti_shaking_setting_Disable_array),	10,MSM_CAMERA_I2C_WORD_DATA}
};




static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0064},	
	{0x98C, 0x273F},	
	{0x990, 0x044B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_014_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x000B},	
	{0x98C, 0x273B},	
	{0x990, 0x0633},	
	{0x98C, 0x273D},	
	{0x990, 0x006B},	
	{0x98C, 0x273F},	
	{0x990, 0x0443},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_030_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0017},	
	{0x98C, 0x273B},	
	{0x990, 0x0627},	
	{0x98C, 0x273D},	
	{0x990, 0x0072},	
	{0x98C, 0x273F},	
	{0x990, 0x043C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_045_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0022},	
	{0x98C, 0x273B},	
	{0x990, 0x061C},	
	{0x98C, 0x273D},	
	{0x990, 0x0079},	
	{0x98C, 0x273F},	
	{0x990, 0x0435},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_061_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x002E},	
	{0x98C, 0x273B},	
	{0x990, 0x0610},	
	{0x98C, 0x273D},	
	{0x990, 0x0080},	
	{0x98C, 0x273F},	
	{0x990, 0x042E},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_077_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0039},	
	{0x98C, 0x273B},	
	{0x990, 0x0605},	
	{0x98C, 0x273D},	
	{0x990, 0x0087},	
	{0x98C, 0x273F},	
	{0x990, 0x0427},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_093_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0044},	
	{0x98C, 0x273B},	
	{0x990, 0x05FA},	
	{0x98C, 0x273D},	
	{0x990, 0x008E},	
	{0x98C, 0x273F},	
	{0x990, 0x0420},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_109_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x004F},	
	{0x98C, 0x273B},	
	{0x990, 0x05EF},	
	{0x98C, 0x273D},	
	{0x990, 0x0095},	
	{0x98C, 0x273F},	
	{0x990, 0x0419},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_126_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0059},	
	{0x98C, 0x273B},	
	{0x990, 0x05E5},	
	{0x98C, 0x273D},	
	{0x990, 0x009C},	
	{0x98C, 0x273F},	
	{0x990, 0x0412},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_143_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0064},	
	{0x98C, 0x273B},	
	{0x990, 0x05DA},	
	{0x98C, 0x273D},	
	{0x990, 0x00A2},	
	{0x98C, 0x273F},	
	{0x990, 0x040C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_160_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x006E},	
	{0x98C, 0x273B},	
	{0x990, 0x05D0},	
	{0x98C, 0x273D},	
	{0x990, 0x00A9},	
	{0x98C, 0x273F},	
	{0x990, 0x0405},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_177_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0078},	
	{0x98C, 0x273B},	
	{0x990, 0x05C6},	
	{0x98C, 0x273D},	
	{0x990, 0x00AF},	
	{0x98C, 0x273F},	
	{0x990, 0x03FF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_195_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0082},	
	{0x98C, 0x273B},	
	{0x990, 0x05BC},	
	{0x98C, 0x273D},	
	{0x990, 0x00B5},	
	{0x98C, 0x273F},	
	{0x990, 0x03F9},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_213_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x008C},	
	{0x98C, 0x273B},	
	{0x990, 0x05B2},	
	{0x98C, 0x273D},	
	{0x990, 0x00BB},	
	{0x98C, 0x273F},	
	{0x990, 0x03F3},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_231_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0096},	
	{0x98C, 0x273B},	
	{0x990, 0x05A8},	
	{0x98C, 0x273D},	
	{0x990, 0x00C2},	
	{0x98C, 0x273F},	
	{0x990, 0x03EC},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_WXGA_x1_25_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00A0},	
	{0x98C, 0x273B},	
	{0x990, 0x059F},	
	{0x98C, 0x273D},	
	{0x990, 0x00C8},	
	{0x98C, 0x273F},	
	{0x990, 0x03E7},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_wxga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_WXGA_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_014_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_014_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_030_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_030_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_045_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_045_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_061_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_061_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_077_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_077_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_093_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_093_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_109_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_109_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_126_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_126_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_143_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_143_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_160_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_160_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_177_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_177_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_195_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_195_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_213_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_213_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_231_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_231_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_WXGA_x1_25_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_WXGA_x1_25_array),	0,MSM_CAMERA_I2C_WORD_DATA}
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_062_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x002F},	
	{0x98C, 0x273B},	
	{0x990, 0x060F},	
	{0x98C, 0x273D},	
	{0x990, 0x0023},	
	{0x98C, 0x273F},	
	{0x990, 0x048B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_129_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x005C},	
	{0x98C, 0x273B},	
	{0x990, 0x05E2},	
	{0x98C, 0x273D},	
	{0x990, 0x0045},	
	{0x98C, 0x273F},	
	{0x990, 0x0469},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_201_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0085},	
	{0x98C, 0x273B},	
	{0x990, 0x05B9},	
	{0x98C, 0x273D},	
	{0x990, 0x0064},	
	{0x98C, 0x273F},	
	{0x990, 0x044A},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_276_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00AD},	
	{0x98C, 0x273B},	
	{0x990, 0x0591},	
	{0x98C, 0x273D},	
	{0x990, 0x0082},	
	{0x98C, 0x273F},	
	{0x990, 0x042C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_357_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00D2},	
	{0x98C, 0x273B},	
	{0x990, 0x056C},	
	{0x98C, 0x273D},	
	{0x990, 0x009D},	
	{0x98C, 0x273F},	
	{0x990, 0x0411},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_442_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00F5},	
	{0x98C, 0x273B},	
	{0x990, 0x0549},	
	{0x98C, 0x273D},	
	{0x990, 0x00B8},	
	{0x98C, 0x273F},	
	{0x990, 0x03F6},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_533_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0116},	
	{0x98C, 0x273B},	
	{0x990, 0x0528},	
	{0x98C, 0x273D},	
	{0x990, 0x00D0},	
	{0x98C, 0x273F},	
	{0x990, 0x03DE},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_630_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0135},	
	{0x98C, 0x273B},	
	{0x990, 0x0509},	
	{0x98C, 0x273D},	
	{0x990, 0x00E7},	
	{0x98C, 0x273F},	
	{0x990, 0x03C7},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_732_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0152},	
	{0x98C, 0x273B},	
	{0x990, 0x04EC},	
	{0x98C, 0x273D},	
	{0x990, 0x00FD},	
	{0x98C, 0x273F},	
	{0x990, 0x03B1},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_842_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x016D},	
	{0x98C, 0x273B},	
	{0x990, 0x04D1},	
	{0x98C, 0x273D},	
	{0x990, 0x0112},	
	{0x98C, 0x273F},	
	{0x990, 0x039C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x1_958_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0187},	
	{0x98C, 0x273B},	
	{0x990, 0x04B7},	
	{0x98C, 0x273D},	
	{0x990, 0x0125},	
	{0x98C, 0x273F},	
	{0x990, 0x0389},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x2_081_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x019F},	
	{0x98C, 0x273B},	
	{0x990, 0x049F},	
	{0x98C, 0x273D},	
	{0x990, 0x0137},	
	{0x98C, 0x273F},	
	{0x990, 0x0377},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x2_212_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01B6},	
	{0x98C, 0x273B},	
	{0x990, 0x0488},	
	{0x98C, 0x273D},	
	{0x990, 0x0148},	
	{0x98C, 0x273F},	
	{0x990, 0x0366},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x2_351_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01CB},	
	{0x98C, 0x273B},	
	{0x990, 0x0473},	
	{0x98C, 0x273D},	
	{0x990, 0x0158},	
	{0x98C, 0x273F},	
	{0x990, 0x0356},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_VGA_x2_5_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01E0},	
	{0x98C, 0x273B},	
	{0x990, 0x045F},	
	{0x98C, 0x273D},	
	{0x990, 0x0168},	
	{0x98C, 0x273F},	
	{0x990, 0x0347},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_vga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_VGA_x1_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_062_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_062_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_129_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_129_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_201_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_201_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_276_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_276_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_357_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_357_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_442_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_442_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_533_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_533_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_630_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_630_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_732_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_732_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_842_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_842_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x1_958_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x1_958_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x2_081_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x2_081_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x2_212_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x2_212_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x2_351_array[0],ARRAY_SIZE(SIZE_setting_Zoom_VGA_x2_351_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_VGA_x2_5_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_VGA_x2_5_array),	0,MSM_CAMERA_I2C_WORD_DATA}
};



static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_062_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x002F},	
	{0x98C, 0x273B},	
	{0x990, 0x060F},	
	{0x98C, 0x273D},	
	{0x990, 0x0023},	
	{0x98C, 0x273F},	
	{0x990, 0x048B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_129_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x005C},	
	{0x98C, 0x273B},	
	{0x990, 0x05E2},	
	{0x98C, 0x273D},	
	{0x990, 0x0045},	
	{0x98C, 0x273F},	
	{0x990, 0x0469},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_201_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0085},	
	{0x98C, 0x273B},	
	{0x990, 0x05B9},	
	{0x98C, 0x273D},	
	{0x990, 0x0064},	
	{0x98C, 0x273F},	
	{0x990, 0x044A},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_276_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00AD},	
	{0x98C, 0x273B},	
	{0x990, 0x0591},	
	{0x98C, 0x273D},	
	{0x990, 0x0082},	
	{0x98C, 0x273F},	
	{0x990, 0x042C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_357_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00D2},	
	{0x98C, 0x273B},	
	{0x990, 0x056C},	
	{0x98C, 0x273D},	
	{0x990, 0x009D},	
	{0x98C, 0x273F},	
	{0x990, 0x0411},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_442_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00F5},	
	{0x98C, 0x273B},	
	{0x990, 0x0549},	
	{0x98C, 0x273D},	
	{0x990, 0x00B8},	
	{0x98C, 0x273F},	
	{0x990, 0x03F6},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_533_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0116},	
	{0x98C, 0x273B},	
	{0x990, 0x0528},	
	{0x98C, 0x273D},	
	{0x990, 0x00D0},	
	{0x98C, 0x273F},	
	{0x990, 0x03DE},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_630_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0135},	
	{0x98C, 0x273B},	
	{0x990, 0x0509},	
	{0x98C, 0x273D},	
	{0x990, 0x00E7},	
	{0x98C, 0x273F},	
	{0x990, 0x03C7},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_732_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0152},	
	{0x98C, 0x273B},	
	{0x990, 0x04EC},	
	{0x98C, 0x273D},	
	{0x990, 0x00FD},	
	{0x98C, 0x273F},	
	{0x990, 0x03B1},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_842_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x016D},	
	{0x98C, 0x273B},	
	{0x990, 0x04D1},	
	{0x98C, 0x273D},	
	{0x990, 0x0112},	
	{0x98C, 0x273F},	
	{0x990, 0x039C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x1_958_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0187},	
	{0x98C, 0x273B},	
	{0x990, 0x04B7},	
	{0x98C, 0x273D},	
	{0x990, 0x0125},	
	{0x98C, 0x273F},	
	{0x990, 0x0389},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x2_081_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x019F},	
	{0x98C, 0x273B},	
	{0x990, 0x049F},	
	{0x98C, 0x273D},	
	{0x990, 0x0137},	
	{0x98C, 0x273F},	
	{0x990, 0x0377},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x2_212_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01B6},	
	{0x98C, 0x273B},	
	{0x990, 0x0488},	
	{0x98C, 0x273D},	
	{0x990, 0x0148},	
	{0x98C, 0x273F},	
	{0x990, 0x0366},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x2_351_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01CB},	
	{0x98C, 0x273B},	
	{0x990, 0x0473},	
	{0x98C, 0x273D},	
	{0x990, 0x0158},	
	{0x98C, 0x273F},	
	{0x990, 0x0356},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_VGA_x2_5_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01E0},	
	{0x98C, 0x273B},	
	{0x990, 0x045F},	
	{0x98C, 0x273D},	
	{0x990, 0x0168},	
	{0x98C, 0x273F},	
	{0x990, 0x0347},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_off_vga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_062_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_062_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_129_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_129_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_201_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_201_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_276_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_276_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_357_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_357_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_442_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_442_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_533_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_533_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_630_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_630_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_732_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_732_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_842_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_842_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x1_958_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x1_958_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x2_081_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x2_081_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x2_212_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x2_212_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x2_351_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x2_351_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_VGA_x2_5_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_VGA_x2_5_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};


static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_113_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0051},	
	{0x98C, 0x273B},	
	{0x990, 0x05ED},	
	{0x98C, 0x273D},	
	{0x990, 0x003D},	
	{0x98C, 0x273F},	
	{0x990, 0x0471},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_239_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x009A},	
	{0x98C, 0x273B},	
	{0x990, 0x05A4},	
	{0x98C, 0x273D},	
	{0x990, 0x0073},	
	{0x98C, 0x273F},	
	{0x990, 0x043B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_379_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00DC},	
	{0x98C, 0x273B},	
	{0x990, 0x0562},	
	{0x98C, 0x273D},	
	{0x990, 0x00A5},	
	{0x98C, 0x273F},	
	{0x990, 0x0409},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_536_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0117},	
	{0x98C, 0x273B},	
	{0x990, 0x0527},	
	{0x98C, 0x273D},	
	{0x990, 0x00D1},	
	{0x98C, 0x273F},	
	{0x990, 0x03DD},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_709_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x014C},	
	{0x98C, 0x273B},	
	{0x990, 0x04F2},	
	{0x98C, 0x273D},	
	{0x990, 0x00F9},	
	{0x98C, 0x273F},	
	{0x990, 0x03B5},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x1_903_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x017B},	
	{0x98C, 0x273B},	
	{0x990, 0x04C3},	
	{0x98C, 0x273D},	
	{0x990, 0x011C},	
	{0x98C, 0x273F},	
	{0x990, 0x0392},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x2_119_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01A6},	
	{0x98C, 0x273B},	
	{0x990, 0x0498},	
	{0x98C, 0x273D},	
	{0x990, 0x013C},	
	{0x98C, 0x273F},	
	{0x990, 0x0372},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x2_359_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01CC},	
	{0x98C, 0x273B},	
	{0x990, 0x0472},	
	{0x98C, 0x273D},	
	{0x990, 0x0159},	
	{0x98C, 0x273F},	
	{0x990, 0x0355},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x2_626_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01EF},	
	{0x98C, 0x273B},	
	{0x990, 0x044F},	
	{0x98C, 0x273D},	
	{0x990, 0x0173},	
	{0x98C, 0x273F},	
	{0x990, 0x033B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x2_924_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x020E},	
	{0x98C, 0x273B},	
	{0x990, 0x0430},	
	{0x98C, 0x273D},	
	{0x990, 0x018A},	
	{0x98C, 0x273F},	
	{0x990, 0x0324},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x3_255_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x022A},	
	{0x98C, 0x273B},	
	{0x990, 0x0414},	
	{0x98C, 0x273D},	
	{0x990, 0x019F},	
	{0x98C, 0x273F},	
	{0x990, 0x030F},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x3_623_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0243},	
	{0x98C, 0x273B},	
	{0x990, 0x03FB},	
	{0x98C, 0x273D},	
	{0x990, 0x01B2},	
	{0x98C, 0x273F},	
	{0x990, 0x02FC},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x4_034_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0259},	
	{0x98C, 0x273B},	
	{0x990, 0x03E5},	
	{0x98C, 0x273D},	
	{0x990, 0x01C3},	
	{0x98C, 0x273F},	
	{0x990, 0x02EB},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x4_491_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x026D},	
	{0x98C, 0x273B},	
	{0x990, 0x03D1},	
	{0x98C, 0x273D},	
	{0x990, 0x01D2},	
	{0x98C, 0x273F},	
	{0x990, 0x02DC},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QVGA_x5_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0280},	
	{0x98C, 0x273B},	
	{0x990, 0x03BF},	
	{0x98C, 0x273D},	
	{0x990, 0x01E0},	
	{0x98C, 0x273F},	
	{0x990, 0x02CF},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_off_qvga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_113_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_113_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_239_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_239_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_379_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_379_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_536_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_536_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_709_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_709_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x1_903_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x1_903_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x2_119_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x2_119_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x2_359_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x2_359_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x2_626_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x2_626_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x2_924_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x2_924_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x3_255_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x3_255_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x3_623_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x3_623_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x4_034_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x4_034_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x4_491_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x4_491_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QVGA_x5_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QVGA_x5_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};


static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0043},	
	{0x98C, 0x273B},	
	{0x990, 0x05FC},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_113_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x008D},	
	{0x98C, 0x273B},	
	{0x990, 0x05B1},	
	{0x98C, 0x273D},	
	{0x990, 0x003D},	
	{0x98C, 0x273F},	
	{0x990, 0x0471},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_239_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00D0},	
	{0x98C, 0x273B},	
	{0x990, 0x056E},	
	{0x98C, 0x273D},	
	{0x990, 0x0073},	
	{0x98C, 0x273F},	
	{0x990, 0x043B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_379_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x010C},	
	{0x98C, 0x273B},	
	{0x990, 0x0532},	
	{0x98C, 0x273D},	
	{0x990, 0x00A5},	
	{0x98C, 0x273F},	
	{0x990, 0x0409},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_536_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0142},	
	{0x98C, 0x273B},	
	{0x990, 0x04FC},	
	{0x98C, 0x273D},	
	{0x990, 0x00D1},	
	{0x98C, 0x273F},	
	{0x990, 0x03DD},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_709_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0173},	
	{0x98C, 0x273B},	
	{0x990, 0x04CB},	
	{0x98C, 0x273D},	
	{0x990, 0x00F9},	
	{0x98C, 0x273F},	
	{0x990, 0x03B5},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x1_903_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x019E},	
	{0x98C, 0x273B},	
	{0x990, 0x04A0},	
	{0x98C, 0x273D},	
	{0x990, 0x011C},	
	{0x98C, 0x273F},	
	{0x990, 0x0392},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x2_119_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01C6},	
	{0x98C, 0x273B},	
	{0x990, 0x0478},	
	{0x98C, 0x273D},	
	{0x990, 0x013C},	
	{0x98C, 0x273F},	
	{0x990, 0x0372},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x2_359_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01E9},	
	{0x98C, 0x273B},	
	{0x990, 0x0455},	
	{0x98C, 0x273D},	
	{0x990, 0x0159},	
	{0x98C, 0x273F},	
	{0x990, 0x0355},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x2_626_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0208},	
	{0x98C, 0x273B},	
	{0x990, 0x0436},	
	{0x98C, 0x273D},	
	{0x990, 0x0173},	
	{0x98C, 0x273F},	
	{0x990, 0x033B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x2_924_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0225},	
	{0x98C, 0x273B},	
	{0x990, 0x0419},	
	{0x98C, 0x273D},	
	{0x990, 0x018A},	
	{0x98C, 0x273F},	
	{0x990, 0x0324},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x3_255_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x023E},	
	{0x98C, 0x273B},	
	{0x990, 0x0400},	
	{0x98C, 0x273D},	
	{0x990, 0x019F},	
	{0x98C, 0x273F},	
	{0x990, 0x030F},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x3_623_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0255},	
	{0x98C, 0x273B},	
	{0x990, 0x03E9},	
	{0x98C, 0x273D},	
	{0x990, 0x01B2},	
	{0x98C, 0x273F},	
	{0x990, 0x02FC},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x4_034_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x026A},	
	{0x98C, 0x273B},	
	{0x990, 0x03D4},	
	{0x98C, 0x273D},	
	{0x990, 0x01C3},	
	{0x98C, 0x273F},	
	{0x990, 0x02EB},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x4_491_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x027C},	
	{0x98C, 0x273B},	
	{0x990, 0x03C2},	
	{0x98C, 0x273D},	
	{0x990, 0x01D2},	
	{0x98C, 0x273F},	
	{0x990, 0x02DC},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_off_QCIF_x5_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x028D},	
	{0x98C, 0x273B},	
	{0x990, 0x03B1},	
	{0x98C, 0x273D},	
	{0x990, 0x01E0},	
	{0x98C, 0x273F},	
	{0x990, 0x02CF},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_off_qcif_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_113_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_113_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_239_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_239_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_379_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_379_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_536_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_536_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_709_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_709_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x1_903_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x1_903_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x2_119_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x2_119_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x2_359_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x2_359_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x2_626_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x2_626_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x2_924_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x2_924_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x3_255_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x3_255_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x3_623_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x3_623_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x4_034_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x4_034_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x4_491_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x4_491_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_off_QCIF_x5_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_off_QCIF_x5_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};


static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_047_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0024},	
	{0x98C, 0x273B},	
	{0x990, 0x061A},	
	{0x98C, 0x273D},	
	{0x990, 0x001B},	
	{0x98C, 0x273F},	
	{0x990, 0x0493},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_096_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0046},	
	{0x98C, 0x273B},	
	{0x990, 0x05F8},	
	{0x98C, 0x273D},	
	{0x990, 0x0034},	
	{0x98C, 0x273F},	
	{0x990, 0x047A},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_148_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0067},	
	{0x98C, 0x273B},	
	{0x990, 0x05D7},	
	{0x98C, 0x273D},	
	{0x990, 0x004D},	
	{0x98C, 0x273F},	
	{0x990, 0x0461},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_203_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0087},	
	{0x98C, 0x273B},	
	{0x990, 0x05B7},	
	{0x98C, 0x273D},	
	{0x990, 0x0065},	
	{0x98C, 0x273F},	
	{0x990, 0x0449},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_259_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00A5},	
	{0x98C, 0x273B},	
	{0x990, 0x0599},	
	{0x98C, 0x273D},	
	{0x990, 0x007B},	
	{0x98C, 0x273F},	
	{0x990, 0x0433},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_319_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00C1},	
	{0x98C, 0x273B},	
	{0x990, 0x057D},	
	{0x98C, 0x273D},	
	{0x990, 0x0091},	
	{0x98C, 0x273F},	
	{0x990, 0x041D},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_381_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00DD},	
	{0x98C, 0x273B},	
	{0x990, 0x0561},	
	{0x98C, 0x273D},	
	{0x990, 0x00A5},	
	{0x98C, 0x273F},	
	{0x990, 0x0409},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_447_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00F7},	
	{0x98C, 0x273B},	
	{0x990, 0x0547},	
	{0x98C, 0x273D},	
	{0x990, 0x00B9},	
	{0x98C, 0x273F},	
	{0x990, 0x03F5},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_515_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0110},	
	{0x98C, 0x273B},	
	{0x990, 0x052E},	
	{0x98C, 0x273D},	
	{0x990, 0x00CC},	
	{0x98C, 0x273F},	
	{0x990, 0x03E2},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_587_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0128},	
	{0x98C, 0x273B},	
	{0x990, 0x0516},	
	{0x98C, 0x273D},	
	{0x990, 0x00DE},	
	{0x98C, 0x273F},	
	{0x990, 0x03D0},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_662_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x013E},	
	{0x98C, 0x273B},	
	{0x990, 0x0500},	
	{0x98C, 0x273D},	
	{0x990, 0x00EF},	
	{0x98C, 0x273F},	
	{0x990, 0x03BF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_741_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0154},	
	{0x98C, 0x273B},	
	{0x990, 0x04EA},	
	{0x98C, 0x273D},	
	{0x990, 0x00FF},	
	{0x98C, 0x273F},	
	{0x990, 0x03AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_823_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0169},	
	{0x98C, 0x273B},	
	{0x990, 0x04D5},	
	{0x98C, 0x273D},	
	{0x990, 0x010E},	
	{0x98C, 0x273F},	
	{0x990, 0x03A0},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x1_909_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x017D},	
	{0x98C, 0x273B},	
	{0x990, 0x04C1},	
	{0x98C, 0x273D},	
	{0x990, 0x011D},	
	{0x98C, 0x273F},	
	{0x990, 0x0391},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_VGA_x2_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0190},	
	{0x98C, 0x273B},	
	{0x990, 0x04AF},	
	{0x98C, 0x273D},	
	{0x990, 0x012C},	
	{0x98C, 0x273F},	
	{0x990, 0x0383},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_on_vga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_047_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_047_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_096_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_096_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_148_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_148_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_203_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_203_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_259_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_259_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_319_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_319_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_381_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_381_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_447_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_447_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_515_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_515_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_587_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_587_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_662_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_662_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_741_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_741_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_823_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_823_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x1_909_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x1_909_array),0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_VGA_x2_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_VGA_x2_array),	0,MSM_CAMERA_I2C_WORD_DATA}
};


static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0000},	
	{0x98C, 0x273B},	
	{0x990, 0x063F},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_096_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0046},	
	{0x98C, 0x273B},	
	{0x990, 0x05F8},	
	{0x98C, 0x273D},	
	{0x990, 0x0034},	
	{0x98C, 0x273F},	
	{0x990, 0x047A},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_203_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0087},	
	{0x98C, 0x273B},	
	{0x990, 0x05B7},	
	{0x98C, 0x273D},	
	{0x990, 0x0065},	
	{0x98C, 0x273F},	
	{0x990, 0x0449},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_319_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00C1},	
	{0x98C, 0x273B},	
	{0x990, 0x057D},	
	{0x98C, 0x273D},	
	{0x990, 0x0091},	
	{0x98C, 0x273F},	
	{0x990, 0x041D},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_447_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00F7},	
	{0x98C, 0x273B},	
	{0x990, 0x0547},	
	{0x98C, 0x273D},	
	{0x990, 0x00B9},	
	{0x98C, 0x273F},	
	{0x990, 0x03F5},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_587_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0128},	
	{0x98C, 0x273B},	
	{0x990, 0x0516},	
	{0x98C, 0x273D},	
	{0x990, 0x00DE},	
	{0x98C, 0x273F},	
	{0x990, 0x03D0},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_741_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0154},	
	{0x98C, 0x273B},	
	{0x990, 0x04EA},	
	{0x98C, 0x273D},	
	{0x990, 0x00FF},	
	{0x98C, 0x273F},	
	{0x990, 0x03AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x1_909_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x017D},	
	{0x98C, 0x273B},	
	{0x990, 0x04C1},	
	{0x98C, 0x273D},	
	{0x990, 0x011D},	
	{0x98C, 0x273F},	
	{0x990, 0x0391},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x2_094_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01A2},	
	{0x98C, 0x273B},	
	{0x990, 0x049C},	
	{0x98C, 0x273D},	
	{0x990, 0x0139},	
	{0x98C, 0x273F},	
	{0x990, 0x0375},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x2_297_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01C3},	
	{0x98C, 0x273B},	
	{0x990, 0x047B},	
	{0x98C, 0x273D},	
	{0x990, 0x0152},	
	{0x98C, 0x273F},	
	{0x990, 0x035C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x2_519_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01E2},	
	{0x98C, 0x273B},	
	{0x990, 0x045C},	
	{0x98C, 0x273D},	
	{0x990, 0x0169},	
	{0x98C, 0x273F},	
	{0x990, 0x0345},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x2_763_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01FE},	
	{0x98C, 0x273B},	
	{0x990, 0x0440},	
	{0x98C, 0x273D},	
	{0x990, 0x017E},	
	{0x98C, 0x273F},	
	{0x990, 0x0330},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x3_031_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0218},	
	{0x98C, 0x273B},	
	{0x990, 0x0426},	
	{0x98C, 0x273D},	
	{0x990, 0x0192},	
	{0x98C, 0x273F},	
	{0x990, 0x031C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x3_324_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x022F},	
	{0x98C, 0x273B},	
	{0x990, 0x040F},	
	{0x98C, 0x273D},	
	{0x990, 0x01A3},	
	{0x98C, 0x273F},	
	{0x990, 0x030B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x3_646_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0244},	
	{0x98C, 0x273B},	
	{0x990, 0x03FA},	
	{0x98C, 0x273D},	
	{0x990, 0x01B3},	
	{0x98C, 0x273F},	
	{0x990, 0x02FB},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QVGA_x4_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0258},	
	{0x98C, 0x273B},	
	{0x990, 0x03E7},	
	{0x98C, 0x273D},	
	{0x990, 0x01C2},	
	{0x98C, 0x273F},	
	{0x990, 0x02ED},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_on_qvga_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_096_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_096_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_203_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_203_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_319_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_319_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_447_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_447_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_587_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_587_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_741_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_741_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x1_909_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x1_909_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x2_094_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x2_094_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x2_297_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x2_297_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x2_519_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x2_519_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x2_763_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x2_763_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x3_031_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x3_031_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x3_324_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x3_324_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x3_646_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x3_646_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QVGA_x4_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QVGA_x4_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};


static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0032},	
	{0x98C, 0x273B},	
	{0x990, 0x060D},	
	{0x98C, 0x273D},	
	{0x990, 0x0000},	
	{0x98C, 0x273F},	
	{0x990, 0x04AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_096_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0074},	
	{0x98C, 0x273B},	
	{0x990, 0x05CA},	
	{0x98C, 0x273D},	
	{0x990, 0x0034},	
	{0x98C, 0x273F},	
	{0x990, 0x047A},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_203_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00B0},	
	{0x98C, 0x273B},	
	{0x990, 0x058E},	
	{0x98C, 0x273D},	
	{0x990, 0x0065},	
	{0x98C, 0x273F},	
	{0x990, 0x0449},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_319_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x00E7},	
	{0x98C, 0x273B},	
	{0x990, 0x0557},	
	{0x98C, 0x273D},	
	{0x990, 0x0091},	
	{0x98C, 0x273F},	
	{0x990, 0x041D},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_447_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0119},	
	{0x98C, 0x273B},	
	{0x990, 0x0525},	
	{0x98C, 0x273D},	
	{0x990, 0x00B9},	
	{0x98C, 0x273F},	
	{0x990, 0x03F5},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_587_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0147},	
	{0x98C, 0x273B},	
	{0x990, 0x04F7},	
	{0x98C, 0x273D},	
	{0x990, 0x00DE},	
	{0x98C, 0x273F},	
	{0x990, 0x03D0},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_741_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0171},	
	{0x98C, 0x273B},	
	{0x990, 0x04CD},	
	{0x98C, 0x273D},	
	{0x990, 0x00FF},	
	{0x98C, 0x273F},	
	{0x990, 0x03AF},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x1_909_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0197},	
	{0x98C, 0x273B},	
	{0x990, 0x04A7},	
	{0x98C, 0x273D},	
	{0x990, 0x011D},	
	{0x98C, 0x273F},	
	{0x990, 0x0391},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x2_094_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01B9},	
	{0x98C, 0x273B},	
	{0x990, 0x0485},	
	{0x98C, 0x273D},	
	{0x990, 0x0139},	
	{0x98C, 0x273F},	
	{0x990, 0x0375},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x2_297_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01D9},	
	{0x98C, 0x273B},	
	{0x990, 0x0465},	
	{0x98C, 0x273D},	
	{0x990, 0x0152},	
	{0x98C, 0x273F},	
	{0x990, 0x035C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x2_519_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x01F6},	
	{0x98C, 0x273B},	
	{0x990, 0x0448},	
	{0x98C, 0x273D},	
	{0x990, 0x0169},	
	{0x98C, 0x273F},	
	{0x990, 0x0345},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x2_763_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0210},	
	{0x98C, 0x273B},	
	{0x990, 0x042E},	
	{0x98C, 0x273D},	
	{0x990, 0x017E},	
	{0x98C, 0x273F},	
	{0x990, 0x0330},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x3_031_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0228},	
	{0x98C, 0x273B},	
	{0x990, 0x0416},	
	{0x98C, 0x273D},	
	{0x990, 0x0192},	
	{0x98C, 0x273F},	
	{0x990, 0x031C},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x3_324_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x023E},	
	{0x98C, 0x273B},	
	{0x990, 0x0400},	
	{0x98C, 0x273D},	
	{0x990, 0x01A3},	
	{0x98C, 0x273F},	
	{0x990, 0x030B},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x3_646_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0252},	
	{0x98C, 0x273B},	
	{0x990, 0x03EC},	
	{0x98C, 0x273D},	
	{0x990, 0x01B3},	
	{0x98C, 0x273F},	
	{0x990, 0x02FB},	
						
						
};

static struct msm_camera_i2c_reg_conf
SIZE_setting_Zoom_stabilize_on_QCIF_x4_array[] = {
	{0x98C, 0x2739},	
	{0x990, 0x0264},	
	{0x98C, 0x273B},	
	{0x990, 0x03DA},	
	{0x98C, 0x273D},	
	{0x990, 0x01C2},	
	{0x98C, 0x273F},	
	{0x990, 0x02ED},	
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_ZOOM_stabilize_on_qcif_setting_settings[MT9D115_ZOOM_MAX] = {
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_array),		0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_096_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_096_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_203_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_203_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_319_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_319_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_447_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_447_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_587_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_587_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_741_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_741_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x1_909_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x1_909_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x2_094_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x2_094_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x2_297_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x2_297_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x2_519_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x2_519_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x2_763_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x2_763_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x3_031_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x3_031_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x3_324_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x3_324_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x3_646_array[0],	ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x3_646_array),	0,MSM_CAMERA_I2C_WORD_DATA},
	{&SIZE_setting_Zoom_stabilize_on_QCIF_x4_array[0],		ARRAY_SIZE(SIZE_setting_Zoom_stabilize_on_QCIF_x4_array),		0,MSM_CAMERA_I2C_WORD_DATA}
};
#endif




static struct msm_camera_i2c_reg_conf
Mode_Preview_setting_array[] = {
						

	{0x098C, 0xA115},	
	{0x0990, 0x0000},	

	{0x098C, 0xA103},	
	{0x0990, 0x0001}	
};

static struct msm_camera_i2c_reg_conf
Mode_Capture_setting_array[] = {
						

	{0x098C, 0xA115},	
	{0x0990, 0x0002},	
	{0x098C, 0xA103},	
	{0x0990, 0x0002}	
};

static struct msm_camera_i2c_conf_array mt9d115_sub_confs[MT9D115_MODE_MAX] = {
    {&Mode_Preview_setting_array[0],ARRAY_SIZE(Mode_Preview_setting_array), 0, MSM_CAMERA_I2C_WORD_DATA},
    {&Mode_Capture_setting_array[0],ARRAY_SIZE(Mode_Capture_setting_array), 0, MSM_CAMERA_I2C_WORD_DATA}
};

#if 0



static struct msm_camera_i2c_reg_conf
Scene_Auto_setting_array[] = {
    {0x098C, 0xAB22},   
    {0x0990, 0x0005},   
    {0x098C, 0xAB23},   
    {0x0990, 0x0004},   
};

static struct msm_camera_i2c_reg_conf
Scene_Portrait_setting_array[] = {
    {0x098C, 0xAB22},   
    {0x0990, 0x0003},   
    {0x098C, 0xAB23},   
    {0x0990, 0x0009},   
};

static struct msm_camera_i2c_reg_conf
Scene_Illumination_setting_array[] = {
    {0x098C, 0xAB22},   
    {0x0990, 0x0005},   
    {0x098C, 0xAB23},   
    {0x0990, 0x0010},   
};

static struct msm_camera_i2c_reg_conf
Scene_Off_setting_array[] = {
    {0x098C, 0xAB22},   
    {0x0990, 0x0005},   
    {0x098C, 0xAB23},   
    {0x0990, 0x0003},   
};

static struct msm_camera_i2c_conf_array mt9d115_Scene_settings[MT9D115_SN_MAX] = {
    {&Scene_Auto_setting_array[0],			ARRAY_SIZE(Scene_Auto_setting_array),			0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Scene_Portrait_setting_array[0],		ARRAY_SIZE(Scene_Portrait_setting_array),		0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Scene_Illumination_setting_array[0],	ARRAY_SIZE(Scene_Illumination_setting_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Scene_Off_setting_array[0],			ARRAY_SIZE(Scene_Off_setting_array),			0,	MSM_CAMERA_I2C_WORD_DATA}
};
#endif



static struct msm_camera_i2c_reg_conf
Frame_Rate_setting_75_15fps_array[] = {
						
						
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0020},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000D},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Frame_Rate_setting_05_15fps_array[] = {
						
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0020},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0014},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Frame_Rate_setting_15fixed_array[] = {
						
						
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0040},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0006},	
	{0x098C, 0xA20C},	
	{0x0990, 0x0006},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_reg_conf
Frame_Rate_setting_10_15fps_array[] = {
						
						
	{0x098C, 0xA20E},	
	{0x0990, 0x0040},	
	{0x098C, 0xA20B},	
	{0x0990, 0x0004},	
	{0x098C, 0xA20C},	
	{0x0990, 0x000A},	
	{0x098C, 0xA103},	
	{0x0990, 0x0006}	
						
						
						
						
};

static struct msm_camera_i2c_conf_array mt9d115_Frame_Rate_settings[MT9D115_FR_MAX] = {
    {&Frame_Rate_setting_75_15fps_array[0],	ARRAY_SIZE(Frame_Rate_setting_75_15fps_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Frame_Rate_setting_05_15fps_array[0],	ARRAY_SIZE(Frame_Rate_setting_05_15fps_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Frame_Rate_setting_15fixed_array[0],	ARRAY_SIZE(Frame_Rate_setting_15fixed_array),	0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Frame_Rate_setting_10_15fps_array[0],	ARRAY_SIZE(Frame_Rate_setting_05_15fps_array),	0,	MSM_CAMERA_I2C_WORD_DATA}
};




static struct msm_camera_i2c_reg_conf
Capture_Mode_setting_Auto_array[] = {
	{0x098C, 0xAB22},	
	{0x0990, 0x0005},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_reg_conf
Capture_Mode_setting_Char_Illum_array[] = {
	{0x098C, 0xAB22},	
	{0x0990, 0x0004},	
	{0x098C, 0xA103},	
	{0x0990, 0x0005}	
						
};

static struct msm_camera_i2c_conf_array mt9d115_Capture_Mode_settings[MT9D115_CM_MAX] = {
    {&Capture_Mode_setting_Auto_array[0],		ARRAY_SIZE(Capture_Mode_setting_Auto_array),		0,	MSM_CAMERA_I2C_WORD_DATA},
    {&Capture_Mode_setting_Char_Illum_array[0],	ARRAY_SIZE(Capture_Mode_setting_Char_Illum_array),	0,	MSM_CAMERA_I2C_WORD_DATA}
};
















#endif 
