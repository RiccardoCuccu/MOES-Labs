//  Catapult System Level Synthesis 2010a.155 (Beta Release) Fri Sep 17 02:07:33 PDT 2010
//  
//  Copyright (c) Mentor Graphics Corporation, 1996-2010, All Rights Reserved.
//                       UNPUBLISHED, LICENSED SOFTWARE.
//            CONFIDENTIAL AND PROPRIETARY INFORMATION WHICH IS THE
//          PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS
//  
//  Running on Windows XP michaelf@ORW-DJAIN-620 Service Pack 3 5.01.2600 i686
//  
//  Package information: SIFLIBS v16.0_1.1, HLS_PKGS v16.0_1.1, 
//                       DesignPad v2.75_0.0
//  
options set Output OutputVerilog true
options save
project new
flow package require /SCVerify
flow run /SCVerify
solution file add {./mac.cpp} -type C++
solution file add ./mac_tb.cpp -exclude true
directive set -REGISTER_IDLE_SIGNAL false
directive set -IDLE_SIGNAL {}
directive set -TRANSACTION_DONE_SIGNAL true
directive set -DONE_FLAG {}
directive set -START_FLAG {}
directive set -FSM_ENCODING none
directive set -REG_MAX_FANOUT 0
directive set -NO_X_ASSIGNMENTS false
directive set -SAFE_FSM false
directive set -RESET_CLEARS_ALL_REGS true
directive set -ASSIGN_OVERHEAD 0
directive set -DESIGN_GOAL area
directive set -OLD_SCHED false
directive set -TIMING_CHECKS true
#directive set -MUXPATH true
#directive set -REALLOC true
directive set -PIPELINE_RAMP_UP true
directive set -COMPGRADE fast
directive set -SPECULATE true
directive set -MERGEABLE true
directive set -REGISTER_THRESHOLD 256
directive set -MEM_MAP_THRESHOLD 32
directive set -UNROLL no
directive set -CLOCK_OVERHEAD 20.000000
directive set -OPT_CONST_MULTS -1
go analyze
directive set -CLOCK_NAME clk
directive set -CLOCKS {clk {-CLOCK_PERIOD 3.00 -CLOCK_EDGE rising -CLOCK_HIGH_TIME 1.50 -CLOCK_OFFSET 0.000000 -RESET_KIND sync -RESET_SYNC_NAME rst -RESET_SYNC_ACTIVE high -RESET_ASYNC_NAME arst_n -RESET_ASYNC_ACTIVE low -ENABLE_NAME {} -ENABLE_ACTIVE high}}
directive set -TECHLIBS {{mgc_sample-065nm-dw_beh_dc.lib mgc_sample-065nm-dw_beh_dc}}
directive set -CSA 0
directive set -DESIGN_HIERARCHY mult_acc
go compile
directive set /mult_acc/core/main/MAC -PIPELINE_INIT_INTERVAL 1
go architect
go extract
